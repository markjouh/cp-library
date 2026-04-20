#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../graphs/topsort.h"

// A valid Kahn-style topo output on g satisfies:
//   - distinct vertices
//   - processing in order leaves indegrees in tact: each vertex has 0 indegree
//     from the remaining unprocessed set when its turn comes
//   - remaining unprocessed vertices all have positive indegree (cycle residue)
bool is_valid_kahn(const vector<vector<int>> &g, const vector<int> &order) {
  int n = ssize(g);
  vector<int> indeg(n, 0);
  for (int u = 0; u < n; u++) {
    for (int v : g[u]) indeg[v]++;
  }
  vector<char> seen(n, 0);
  for (int u : order) {
    if (u < 0 || u >= n || seen[u]) return false;
    if (indeg[u] != 0) return false;
    seen[u] = 1;
    for (int v : g[u]) indeg[v]--;
  }
  for (int u = 0; u < n; u++) {
    if (!seen[u] && indeg[u] == 0) return false;
  }
  return true;
}

bool has_cycle_dfs(const vector<vector<int>> &g) {
  int n = ssize(g);
  vector<int> color(n, 0);  // 0 white, 1 gray, 2 black
  function<bool(int)> dfs = [&](int u) -> bool {
    color[u] = 1;
    for (int v : g[u]) {
      if (color[v] == 1) return true;
      if (color[v] == 0 && dfs(v)) return true;
    }
    color[u] = 2;
    return false;
  };
  for (int i = 0; i < n; i++) {
    if (color[i] == 0 && dfs(i)) return true;
  }
  return false;
}

void check(const vector<vector<int>> &g) {
  auto order = topsort(g);
  assert(is_valid_kahn(g, order));
  bool cycle = has_cycle_dfs(g);
  assert((ssize(order) == ssize(g)) == !cycle);
}

int main() {
  mt19937_64 rng(42);

  // Edge cases
  check({});                                         // empty
  check(vector<vector<int>>(1));                     // single isolated
  check({{0}});                                      // self-loop
  check({{1}, {}});                                  // simple edge
  check({{1}, {0}});                                 // 2-cycle
  check({{}, {}, {}});                               // no edges
  check({{1}, {2}, {0}});                            // 3-cycle
  check({{1}, {2}, {}});                             // chain
  check({{1, 2, 3}, {}, {}, {}});                    // star out
  check({{}, {0}, {0}, {0}});                        // star in
  check({{1, 2}, {3}, {3}, {4}, {}});                // small DAG
  check({{1, 2}, {2, 3}, {3}, {4}, {2}});            // DAG with back-leaning cycle via 4->2
  // Self-loop among other edges
  check({{1, 1}, {2}, {}});
  // Multiple disconnected components, some with cycles
  check({{1}, {}, {3}, {2}});                        // {0->1}, {2<->3}

  // Chain (long path): always a DAG
  for (int n : {5, 10, 100, 500}) {
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; i++) g[i].push_back(i + 1);
    check(g);
  }

  // Reverse chain
  for (int n : {5, 10, 100}) {
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; i++) g[i + 1].push_back(i);
    check(g);
  }

  // Star (DAG)
  for (int n : {3, 10, 100}) {
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) g[0].push_back(i);
    check(g);
  }

  // Complete DAG (fully ordered tournament)
  for (int n : {3, 5, 10, 30}) {
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        g[i].push_back(j);
    check(g);
  }

  // Random DAGs (force u < v so no cycles)
  for (int iter = 0; iter < 1000; iter++) {
    int n = 1 + int(rng() % 30);
    int m = int(rng() % (n * n + 1));
    vector<vector<int>> g(n);
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n);
      int v = int(rng() % n);
      if (u == v) continue;
      if (u > v) swap(u, v);
      if (edges.insert({u, v}).second) g[u].push_back(v);
    }
    check(g);
  }

  // Random graphs that may contain cycles
  for (int iter = 0; iter < 1000; iter++) {
    int n = 1 + int(rng() % 20);
    int m = int(rng() % (n * n + 1));
    vector<vector<int>> g(n);
    set<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n);
      int v = int(rng() % n);
      if (edges.insert({u, v}).second) g[u].push_back(v);
    }
    check(g);
  }

  // Dense random graphs (~80% density)
  for (int iter = 0; iter < 200; iter++) {
    int n = 1 + int(rng() % 15);
    vector<vector<int>> g(n);
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        if (rng() % 10 < 8) g[u].push_back(v);
      }
    }
    check(g);
  }

  // Multi-edges (duplicates)
  for (int iter = 0; iter < 200; iter++) {
    int n = 1 + int(rng() % 15);
    int m = int(rng() % (n * n + 1));
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n);
      int v = int(rng() % n);
      g[u].push_back(v);  // allow duplicates
    }
    check(g);
  }

  // Larger DAGs
  for (int iter = 0; iter < 50; iter++) {
    int n = 100 + int(rng() % 900);
    int m = int(rng() % (3 * n));
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n), v = int(rng() % n);
      if (u == v) continue;
      if (u > v) swap(u, v);
      g[u].push_back(v);
    }
    check(g);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
