#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../graphs/shortest_paths/bfs01.h"

// Reference Dijkstra for 0/1 weighted graph
vector<int> dijkstra_ref(const vector<vector<pair<int, bool>>> &g, int start) {
  int n = ssize(g);
  vector<int> dist(n, INT_MAX / 2);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  dist[start] = 0;
  pq.emplace(0, start);
  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();
    if (d != dist[u]) continue;
    for (auto [v, w] : g[u]) {
      int nd = d + int(w);
      if (nd < dist[v]) {
        dist[v] = nd;
        pq.emplace(nd, v);
      }
    }
  }
  return dist;
}

void check(const vector<vector<pair<int, bool>>> &g, int start) {
  vector<int> got = bfs01(g, start);
  vector<int> want = dijkstra_ref(g, start);
  assert(got.size() == want.size());
  for (int i = 0; i < ssize(g); i++) {
    assert(got[i] == want[i]);
  }
}

int main() {
  mt19937_64 rng(1729);

  // Tiny cases
  check({{}}, 0);                                      // single isolated
  check({{{1, 0}}, {}}, 0);                            // one 0-edge
  check({{{1, 1}}, {}}, 0);                            // one 1-edge
  check({{{1, 0}, {2, 1}}, {{2, 0}}, {}}, 0);          // mixed
  check({{{0, 0}}, {}}, 0);                            // self 0-loop
  check({{{0, 1}}, {}}, 0);                            // self 1-loop
  check({{}, {}, {}}, 0);                              // disconnected
  check({{{1, 1}, {2, 1}}, {{2, 1}}, {}}, 0);          // all-1 triangle path

  // Chain with alternating weights
  {
    int n = 100;
    vector<vector<pair<int, bool>>> g(n);
    for (int i = 0; i + 1 < n; i++) {
      g[i].emplace_back(i + 1, i & 1);
    }
    check(g, 0);
  }

  // Directed cycle with all zeros — should all be 0
  {
    int n = 50;
    vector<vector<pair<int, bool>>> g(n);
    for (int i = 0; i < n; i++) g[i].emplace_back((i + 1) % n, false);
    check(g, 0);
    auto d = bfs01(g, 0);
    for (int i = 0; i < n; i++) assert(d[i] == 0);
  }

  // Directed cycle with all ones
  {
    int n = 50;
    vector<vector<pair<int, bool>>> g(n);
    for (int i = 0; i < n; i++) g[i].emplace_back((i + 1) % n, true);
    check(g, 0);
    auto d = bfs01(g, 0);
    for (int i = 0; i < n; i++) assert(d[i] == i);
  }

  // Parallel edges (0 vs 1)
  {
    vector<vector<pair<int, bool>>> g(3);
    g[0].emplace_back(1, true);
    g[0].emplace_back(1, false);   // 0-edge is better
    g[1].emplace_back(2, true);
    auto d = bfs01(g, 0);
    assert(d[0] == 0 && d[1] == 0 && d[2] == 1);
  }

  // Shortest path requires interleaving 0s and 1s carefully (deque ordering)
  {
    //   0 --1-> 1 --0-> 2
    //   0 --0-> 3 --1-> 2
    // best is via 3 -> 2: total 1 (=0+1). Alternative via 1: 1+0=1. Tie.
    // Now: 0->1 (w=1), 1->3 (w=1), 3->2 (w=0). Via 0->3: cheaper path to 2? d[3]=0, then 0.
    vector<vector<pair<int, bool>>> g(4);
    g[0].emplace_back(1, true);
    g[0].emplace_back(3, false);
    g[1].emplace_back(2, false);
    g[3].emplace_back(2, true);
    auto d = bfs01(g, 0);
    assert(d[0] == 0 && d[1] == 1 && d[3] == 0 && d[2] == 1);
  }

  // Grid graphs with 0/1 weights
  for (int h = 1; h <= 6; h++) {
    for (int w = 1; w <= 6; w++) {
      int n = h * w;
      vector<vector<pair<int, bool>>> g(n);
      for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
          int u = r * w + c;
          if (r + 1 < h) {
            bool wt = (rng() & 1);
            g[u].emplace_back(u + w, wt);
            g[u + w].emplace_back(u, wt);
          }
          if (c + 1 < w) {
            bool wt = (rng() & 1);
            g[u].emplace_back(u + 1, wt);
            g[u + 1].emplace_back(u, wt);
          }
        }
      }
      check(g, 0);
    }
  }

  // Random sparse graphs
  for (int iter = 0; iter < 500; iter++) {
    int n = 1 + int(rng() % 30);
    int m = int(rng() % (3 * n + 1));
    vector<vector<pair<int, bool>>> g(n);
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n), v = int(rng() % n);
      bool w = rng() & 1;
      g[u].emplace_back(v, w);
    }
    check(g, int(rng() % n));
  }

  // Random dense graphs
  for (int iter = 0; iter < 100; iter++) {
    int n = 1 + int(rng() % 20);
    vector<vector<pair<int, bool>>> g(n);
    for (int u = 0; u < n; u++) {
      for (int v = 0; v < n; v++) {
        if (rng() % 3 != 0) {
          g[u].emplace_back(v, rng() & 1);
        }
      }
    }
    check(g, 0);
  }

  // All-zero graph (effectively reachability)
  for (int iter = 0; iter < 100; iter++) {
    int n = 1 + int(rng() % 30);
    int m = int(rng() % (2 * n + 1));
    vector<vector<pair<int, bool>>> g(n);
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n), v = int(rng() % n);
      g[u].emplace_back(v, false);
    }
    check(g, 0);
  }

  // All-one graph (standard BFS)
  for (int iter = 0; iter < 100; iter++) {
    int n = 1 + int(rng() % 30);
    int m = int(rng() % (2 * n + 1));
    vector<vector<pair<int, bool>>> g(n);
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n), v = int(rng() % n);
      g[u].emplace_back(v, true);
    }
    check(g, 0);
  }

  // Larger random
  for (int iter = 0; iter < 30; iter++) {
    int n = 200 + int(rng() % 800);
    int m = int(rng() % (5 * n));
    vector<vector<pair<int, bool>>> g(n);
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n), v = int(rng() % n);
      g[u].emplace_back(v, rng() & 1);
    }
    check(g, 0);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
