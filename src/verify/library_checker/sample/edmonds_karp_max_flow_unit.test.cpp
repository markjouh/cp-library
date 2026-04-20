#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../flow/edmonds_karp_max_flow.h"

// Reference: Dinic's algorithm on a dense-matrix capacity representation.
struct DinicRef {
  int n, s, t;
  vector<vector<pair<int, int>>> g;  // (v, edge_idx)
  vector<int> from, to, cap, flow;
  vector<int> level, it;

  DinicRef(int n, int s, int t) : n(n), s(s), t(t), g(n) {}

  void add(int u, int v, int c) {
    g[u].push_back({v, (int)from.size()});
    from.push_back(u); to.push_back(v); cap.push_back(c); flow.push_back(0);
    g[v].push_back({u, (int)from.size()});
    from.push_back(v); to.push_back(u); cap.push_back(0); flow.push_back(0);
  }

  bool bfs() {
    level.assign(n, -1);
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto [v, e] : g[u]) {
        if (level[v] == -1 && cap[e] - flow[e] > 0) {
          level[v] = level[u] + 1;
          q.push(v);
        }
      }
    }
    return level[t] != -1;
  }

  int dfs(int u, int pushed) {
    if (u == t || pushed == 0) return pushed;
    for (int &i = it[u]; i < (int)g[u].size(); i++) {
      auto [v, e] = g[u][i];
      if (level[v] != level[u] + 1 || cap[e] - flow[e] <= 0) continue;
      int d = dfs(v, min(pushed, cap[e] - flow[e]));
      if (d > 0) {
        flow[e] += d;
        flow[e ^ 1] -= d;
        return d;
      }
    }
    return 0;
  }

  int max_flow() {
    int f = 0;
    while (bfs()) {
      it.assign(n, 0);
      while (int d = dfs(s, INT_MAX)) f += d;
    }
    return f;
  }
};

void check(int n, int s, int t, const vector<tuple<int, int, int>> &edges) {
  EdmondsKarpMaxFlow ek(n, s, t);
  DinicRef dn(n, s, t);
  for (auto [u, v, c] : edges) {
    ek.add(u, v, c);
    dn.add(u, v, c);
  }
  int got = ek.max_flow();
  int want = dn.max_flow();
  assert(got == want);
}

int main() {
  mt19937_64 rng(0xDEADBEEF);

  // s == t
  check(1, 0, 0, {});
  check(2, 0, 0, {{0, 1, 5}});

  // Disconnected s-t
  check(2, 0, 1, {});
  check(3, 0, 2, {{0, 1, 5}});

  // Single direct edge
  check(2, 0, 1, {{0, 1, 1}});
  check(2, 0, 1, {{0, 1, 100}});
  check(2, 0, 1, {{0, 1, INT_MAX}});

  // Parallel edges
  check(2, 0, 1, {{0, 1, 3}, {0, 1, 5}});
  check(2, 0, 1, {{0, 1, 3}, {0, 1, 3}, {0, 1, 3}});

  // Antiparallel (back edge doesn't help)
  check(2, 0, 1, {{0, 1, 10}, {1, 0, 5}});

  // Textbook graph with min-cut
  check(4, 0, 3, {{0, 1, 10}, {0, 2, 5}, {1, 3, 8}, {2, 3, 10}, {1, 2, 2}});

  // Chain s -> ... -> t — bottleneck is min edge
  {
    int n = 20;
    vector<tuple<int, int, int>> es;
    for (int i = 0; i + 1 < n; i++) {
      es.emplace_back(i, i + 1, 10 + i);  // capacities 10, 11, ..., 28
    }
    check(n, 0, n - 1, es);  // bottleneck = 10
  }

  // Complete DAG (tournament)
  {
    int n = 6;
    vector<tuple<int, int, int>> es;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        es.emplace_back(i, j, int(rng() % 20));
    check(n, 0, n - 1, es);
  }

  // Bipartite matching reduction
  {
    int L = 6, R = 6, n = L + R + 2;
    int s = 0, t = n - 1;
    vector<tuple<int, int, int>> es;
    for (int i = 0; i < L; i++) es.emplace_back(s, 1 + i, 1);
    for (int j = 0; j < R; j++) es.emplace_back(1 + L + j, t, 1);
    // Random bipartite edges
    for (int i = 0; i < L; i++)
      for (int j = 0; j < R; j++)
        if (rng() % 2) es.emplace_back(1 + i, 1 + L + j, 1);
    check(n, s, t, es);
  }

  // Small random networks
  for (int iter = 0; iter < 300; iter++) {
    int n = 2 + int(rng() % 8);
    int s = 0, t = n - 1;
    int m = int(rng() % (n * n + 1));
    vector<tuple<int, int, int>> es;
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n), v = int(rng() % n);
      int c = 1 + int(rng() % 20);
      es.emplace_back(u, v, c);
    }
    check(n, s, t, es);
  }

  // Medium random networks with unit capacities
  for (int iter = 0; iter < 100; iter++) {
    int n = 5 + int(rng() % 15);
    int s = int(rng() % n);
    int t;
    do { t = int(rng() % n); } while (t == s);
    int m = int(rng() % (3 * n + 1));
    vector<tuple<int, int, int>> es;
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n), v = int(rng() % n);
      es.emplace_back(u, v, 1);
    }
    check(n, s, t, es);
  }

  // Larger sparse networks
  for (int iter = 0; iter < 30; iter++) {
    int n = 30 + int(rng() % 70);
    int s = 0, t = n - 1;
    int m = int(rng() % (2 * n + 1));
    vector<tuple<int, int, int>> es;
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n), v = int(rng() % n);
      int c = 1 + int(rng() % 100);
      es.emplace_back(u, v, c);
    }
    check(n, s, t, es);
  }

  // Grid: 4x4 grid, flow from (0,0) to (3,3)
  {
    int h = 4, w = 4, n = h * w;
    vector<tuple<int, int, int>> es;
    for (int r = 0; r < h; r++)
      for (int c = 0; c < w; c++) {
        int u = r * w + c;
        if (r + 1 < h) es.emplace_back(u, u + w, 5);
        if (c + 1 < w) es.emplace_back(u, u + 1, 5);
      }
    check(n, 0, n - 1, es);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
