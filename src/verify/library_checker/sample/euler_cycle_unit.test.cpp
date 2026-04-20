#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../graphs/euler_cycle.h"

// Verify that `cycle` is a valid Eulerian cycle of `g`:
//   - each consecutive pair in `cycle` is an edge
//   - every edge is used exactly once (both directions of the undirected
//     representation count as the same edge — we match by decrementing counts)
//   - cycle starts and ends at vertex 0 (our impl's convention)
// Precondition: g has all-even degrees in the connected component of 0.
bool is_valid_euler(const vector<vector<int>> &g, const vector<int> &cycle) {
  int n = ssize(g);

  // Count edges and collect total edge count
  int total_edges = 0;
  for (int u = 0; u < n; u++) {
    int self = 0;
    for (int v : g[u]) {
      if (u == v) self++;
      else if (u < v) total_edges++;
    }
    total_edges += self / 2;  // self-loops counted per vertex pair
  }

  if (cycle.empty()) return false;
  if (cycle.front() != 0 || cycle.back() != 0) return false;
  if (ssize(cycle) != total_edges + 1) return false;

  // Multiset of remaining edges (multi-edge safe): map unordered pair -> count.
  map<pair<int, int>, int> edge_count;
  auto key = [](int u, int v) {
    if (u > v) swap(u, v);
    return make_pair(u, v);
  };
  for (int u = 0; u < n; u++) {
    int self = 0;
    for (int v : g[u]) {
      if (u == v) self++;
      else if (u < v) edge_count[key(u, v)]++;
    }
    if (self) edge_count[key(u, u)] += self / 2;
  }
  for (int i = 0; i + 1 < ssize(cycle); i++) {
    auto k = key(cycle[i], cycle[i + 1]);
    auto it = edge_count.find(k);
    if (it == edge_count.end() || it->second == 0) return false;
    it->second--;
    if (it->second == 0) edge_count.erase(it);
  }
  return edge_count.empty();
}

// Check whether component of vertex 0 has all-even degrees. Our impl
// requires this.
bool component0_all_even(const vector<vector<int>> &g) {
  int n = ssize(g);
  vector<int> comp_mark(n, 0);
  queue<int> q;
  q.push(0);
  comp_mark[0] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) {
      if (!comp_mark[v]) {
        comp_mark[v] = 1;
        q.push(v);
      }
    }
  }
  for (int u = 0; u < n; u++) {
    if (!comp_mark[u]) continue;
    // self-loops count 2 toward degree
    if (int(g[u].size()) % 2 != 0) return false;
  }
  return true;
}

// Build undirected graph from an unordered edge list (with multiplicities).
vector<vector<int>> build_graph(int n, const vector<pair<int, int>> &edges) {
  vector<vector<int>> g(n);
  for (auto [u, v] : edges) {
    g[u].push_back(v);
    if (u != v) g[v].push_back(u);
    else g[v].push_back(u);  // self-loop adds two adjacency entries (one per endpoint)
  }
  return g;
}

void check(int n, const vector<pair<int, int>> &edges) {
  auto g = build_graph(n, edges);
  if (!component0_all_even(g)) return;  // skip — not Eulerian per this impl's contract
  // Skip cases where some edges live outside component(0)
  vector<int> comp(n, 0);
  queue<int> q;
  q.push(0);
  comp[0] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) if (!comp[v]) { comp[v] = 1; q.push(v); }
  }
  for (int u = 0; u < n; u++) if (!comp[u] && !g[u].empty()) return;
  auto cycle = euler_cycle(g);
  assert(is_valid_euler(g, cycle));
}

int main() {
  mt19937_64 rng(0xEE71EC);

  // Single isolated vertex — trivially Eulerian
  check(1, {});

  // Single self-loop
  check(1, {{0, 0}});

  // Several self-loops
  check(1, {{0, 0}, {0, 0}, {0, 0}});

  // Triangle
  check(3, {{0, 1}, {1, 2}, {2, 0}});

  // Figure-eight (two triangles sharing vertex 0)
  check(5, {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}, {4, 0}});

  // Square
  check(4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}});

  // Bowtie: two triangles sharing a vertex
  check(5, {{0, 1}, {1, 2}, {2, 0}, {0, 3}, {3, 4}, {4, 0}});

  // Multigraph: two parallel edges between 0 and 1
  check(2, {{0, 1}, {0, 1}});

  // Self-loop + cycle
  check(3, {{0, 0}, {0, 1}, {1, 2}, {2, 0}});

  // Random Eulerian graphs: generate a cycle passing through vertices, which
  // guarantees all degrees are even.
  for (int iter = 0; iter < 500; iter++) {
    int n = 2 + int(rng() % 20);
    int steps = 1 + int(rng() % 50);
    vector<pair<int, int>> edges;
    int u = 0;
    vector<int> visited = {0};
    for (int i = 0; i < steps; i++) {
      int v = int(rng() % n);
      edges.emplace_back(u, v);
      u = v;
    }
    edges.emplace_back(u, 0);  // close cycle back to 0
    check(n, edges);
  }

  // Union of multiple disjoint cycles through vertex 0
  for (int iter = 0; iter < 100; iter++) {
    int cycles = 1 + int(rng() % 5);
    int n = 1;
    vector<pair<int, int>> edges;
    for (int c = 0; c < cycles; c++) {
      int len = 3 + int(rng() % 5);
      int prev = 0;
      for (int i = 1; i < len; i++) {
        edges.emplace_back(prev, n);
        prev = n;
        n++;
      }
      edges.emplace_back(prev, 0);
    }
    check(n, edges);
  }

  // Dense Eulerian graphs: take random graph, add edges to fix odd degrees
  for (int iter = 0; iter < 200; iter++) {
    int n = 3 + int(rng() % 8);
    vector<vector<int>> adj(n);
    vector<pair<int, int>> edges;
    int m = 1 + int(rng() % (n * n));
    for (int i = 0; i < m; i++) {
      int u = int(rng() % n), v = int(rng() % n);
      edges.emplace_back(u, v);
      adj[u].push_back(v);
      if (u != v) adj[v].push_back(u);
      else adj[u].push_back(v);
    }
    // Pair up odd-degree vertices with additional edges
    vector<int> odds;
    for (int i = 0; i < n; i++) if (adj[i].size() % 2) odds.push_back(i);
    for (int i = 0; i + 1 < ssize(odds); i += 2) {
      edges.emplace_back(odds[i], odds[i + 1]);
    }
    check(n, edges);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
