#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../graphs/trees/tree_paths.h"

// Brute: BFS from each query endpoint, aggregate edge weights along the path.

template <class T, auto op, auto id>
T brute_path(const vector<vector<pair<int, int>>> &g, int x, int y) {
  int n = ssize(g);
  vector<int> par(n, -2), parw(n, 0);
  queue<int> q;
  q.push(x);
  par[x] = -1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto [v, w] : g[u]) {
      if (par[v] == -2) {
        par[v] = u;
        parw[v] = w;
        q.push(v);
      }
    }
  }
  T res = id();
  int u = y;
  while (u != x) {
    res = op(res, T(parw[u]));
    u = par[u];
  }
  return res;
}

auto sum_op = [](int a, int b) { return a + b; };
auto sum_id = []() { return 0; };
auto xor_op = [](int a, int b) { return a ^ b; };
auto xor_id = []() { return 0; };
auto max_op_fn = [](int a, int b) { return max(a, b); };
auto max_id_fn = []() { return INT_MIN; };
auto min_op_fn = [](int a, int b) { return min(a, b); };
auto min_id_fn = []() { return INT_MAX; };

template <auto op, auto id>
void check_tree(const vector<vector<pair<int, int>>> &g, int root, int queries, mt19937_64 &rng) {
  int n = ssize(g);
  TreePaths<int, op, id> tp(g, root);
  for (int q = 0; q < queries; q++) {
    int x = int(rng() % n), y = int(rng() % n);
    int got = tp.query(x, y);
    int want = brute_path<int, op, id>(g, x, y);
    assert(got == want);
  }
}

vector<vector<pair<int, int>>> random_tree(int n, mt19937_64 &rng, int wlo, int whi) {
  vector<vector<pair<int, int>>> g(n);
  for (int i = 1; i < n; i++) {
    int p = int(rng() % i);
    int w = wlo + int(rng() % (whi - wlo + 1));
    g[p].emplace_back(i, w);
    g[i].emplace_back(p, w);
  }
  return g;
}

int main() {
  mt19937_64 rng(31337);

  // Single node
  {
    vector<vector<pair<int, int>>> g(1);
    TreePaths<int, sum_op, sum_id> tp(g, 0);
    assert(tp.query(0, 0) == 0);
  }

  // Two nodes
  {
    vector<vector<pair<int, int>>> g(2);
    g[0].emplace_back(1, 7);
    g[1].emplace_back(0, 7);
    TreePaths<int, sum_op, sum_id> tp(g, 0);
    assert(tp.query(0, 0) == 0);
    assert(tp.query(0, 1) == 7);
    assert(tp.query(1, 0) == 7);
    assert(tp.query(1, 1) == 0);
  }

  // Chain
  {
    int n = 20;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i + 1 < n; i++) {
      g[i].emplace_back(i + 1, i + 1);
      g[i + 1].emplace_back(i, i + 1);
    }
    TreePaths<int, sum_op, sum_id> tp(g, 0);
    // path 0..k has sum = 1+2+...+k = k*(k+1)/2
    for (int k = 0; k < n; k++) {
      assert(tp.query(0, k) == k * (k + 1) / 2);
    }
  }

  // Star: one center, many leaves
  {
    int n = 30;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; i++) {
      g[0].emplace_back(i, i * 2);
      g[i].emplace_back(0, i * 2);
    }
    TreePaths<int, sum_op, sum_id> tp(g, 0);
    for (int i = 1; i < n; i++) {
      assert(tp.query(0, i) == i * 2);
      for (int j = 1; j < n; j++) {
        int expect = (i == j ? 0 : i * 2 + j * 2);
        assert(tp.query(i, j) == expect);
      }
    }
  }

  // Random small trees, sum
  for (int iter = 0; iter < 200; iter++) {
    int n = 1 + int(rng() % 30);
    auto g = random_tree(n, rng, 0, 100);
    int root = int(rng() % n);
    check_tree<sum_op, sum_id>(g, root, 100, rng);
  }

  // Random small trees, xor
  for (int iter = 0; iter < 200; iter++) {
    int n = 1 + int(rng() % 30);
    auto g = random_tree(n, rng, 0, 1000);
    int root = int(rng() % n);
    check_tree<xor_op, xor_id>(g, root, 100, rng);
  }

  // Random small trees, max
  for (int iter = 0; iter < 200; iter++) {
    int n = 1 + int(rng() % 30);
    auto g = random_tree(n, rng, 0, 1000);
    int root = int(rng() % n);
    TreePaths<int, max_op_fn, max_id_fn> tp(g, root);
    for (int q = 0; q < 50; q++) {
      int x = int(rng() % n), y = int(rng() % n);
      int got = tp.query(x, y);
      int want = x == y ? INT_MIN : brute_path<int, max_op_fn, max_id_fn>(g, x, y);
      assert(got == want);
    }
  }

  // Random small trees, min
  for (int iter = 0; iter < 200; iter++) {
    int n = 1 + int(rng() % 30);
    auto g = random_tree(n, rng, 0, 1000);
    int root = int(rng() % n);
    TreePaths<int, min_op_fn, min_id_fn> tp(g, root);
    for (int q = 0; q < 50; q++) {
      int x = int(rng() % n), y = int(rng() % n);
      int got = tp.query(x, y);
      int want = x == y ? INT_MAX : brute_path<int, min_op_fn, min_id_fn>(g, x, y);
      assert(got == want);
    }
  }

  // Negative edge weights (sum)
  for (int iter = 0; iter < 50; iter++) {
    int n = 1 + int(rng() % 20);
    auto g = random_tree(n, rng, -100, 100);
    int root = int(rng() % n);
    check_tree<sum_op, sum_id>(g, root, 50, rng);
  }

  // Larger random
  for (int iter = 0; iter < 20; iter++) {
    int n = 100 + int(rng() % 900);
    auto g = random_tree(n, rng, 0, 1000);
    check_tree<sum_op, sum_id>(g, 0, 100, rng);
  }

  // Deep chain (worst-case depth for binary lifting)
  {
    int n = 2000;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i + 1 < n; i++) {
      g[i].emplace_back(i + 1, 1);
      g[i + 1].emplace_back(i, 1);
    }
    TreePaths<int, sum_op, sum_id> tp(g, 0);
    for (int q = 0; q < 200; q++) {
      int x = int(rng() % n), y = int(rng() % n);
      int got = tp.query(x, y);
      int want = abs(x - y);
      assert(got == want);
    }
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
