#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../template/template.h"
#include "../../../graphs/trees/centroid_decomposition.h"

// Invariants we verify:
//   (a) exactly one root (par == -1)
//   (b) par and tree are consistent: for every u with par[u] != -1,
//       tree[par[u]] contains u
//   (c) centroid tree has n vertices and no cycles (subtree of root == [0,n))
//   (d) centroid tree depth is O(log n): each vertex's subtree size in the
//       centroid tree is at most twice that of any of its children (since every
//       centroid splits its subtree into pieces of size <= half, children's
//       subtree counts are <= half of parent's by construction — we verify
//       the weaker "subtree halving" invariant directly)

void check_tree(const vector<vector<int>> &tree_g, const CentroidDecomp &cd, int n) {
  // (a) exactly one root
  int root_count = 0;
  for (int i = 0; i < n; i++) if (cd.par[i] == -1) root_count++;
  assert(root_count == 1);
  assert(cd.par[cd.root] == -1);

  // (b) par <-> tree consistency
  for (int u = 0; u < n; u++) {
    if (cd.par[u] == -1) continue;
    const auto &siblings = cd.tree[cd.par[u]];
    assert(count(siblings.begin(), siblings.end(), u) == 1);
  }
  int edge_count = 0;
  for (int u = 0; u < n; u++) edge_count += int(cd.tree[u].size());
  assert(edge_count == n - 1);

  // (c) reachability from root covers all vertices
  vector<int> vis(n, 0);
  function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    for (int v : cd.tree[u]) {
      assert(!vis[v]);  // acyclic
      dfs(v);
    }
  };
  dfs(cd.root);
  for (int i = 0; i < n; i++) assert(vis[i] == 1);

  // (d) subtree halving: each centroid subtree has size <= half of parent's
  vector<int> sz(n);
  function<int(int)> size_of = [&](int u) {
    int s = 1;
    for (int v : cd.tree[u]) s += size_of(v);
    sz[u] = s;
    return s;
  };
  size_of(cd.root);
  for (int u = 0; u < n; u++) {
    for (int v : cd.tree[u]) {
      assert(sz[v] * 2 <= sz[u]);
    }
  }

  // Depth of centroid tree should be O(log n)
  function<int(int)> depth = [&](int u) {
    int d = 0;
    for (int v : cd.tree[u]) d = max(d, depth(v) + 1);
    return d;
  };
  int d = depth(cd.root);
  assert(d <= 2 * (__lg(max(1, n)) + 2));  // loose but always holds
}

vector<vector<int>> random_tree(int n, mt19937_64 &rng) {
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int p = int(rng() % i);
    g[p].push_back(i);
    g[i].push_back(p);
  }
  return g;
}

int main() {
  mt19937_64 rng(20250420);

  // Single node
  {
    vector<vector<int>> g(1);
    CentroidDecomp cd(g);
    assert(cd.root == 0 && cd.par[0] == -1 && cd.tree[0].empty());
  }

  // Two nodes
  {
    vector<vector<int>> g(2);
    g[0].push_back(1);
    g[1].push_back(0);
    CentroidDecomp cd(g);
    check_tree(g, cd, 2);
  }

  // Chain (bamboo): worst case for depth
  for (int n : {3, 5, 10, 50, 200, 1000}) {
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; i++) {
      g[i].push_back(i + 1);
      g[i + 1].push_back(i);
    }
    CentroidDecomp cd(g);
    check_tree(g, cd, n);
  }

  // Star: centroid should be the hub
  for (int n : {3, 10, 100, 1000}) {
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      g[0].push_back(i);
      g[i].push_back(0);
    }
    CentroidDecomp cd(g);
    assert(cd.root == 0);
    check_tree(g, cd, n);
  }

  // Perfect binary tree
  {
    int n = (1 << 10) - 1;
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int p = (i - 1) / 2;
      g[p].push_back(i);
      g[i].push_back(p);
    }
    CentroidDecomp cd(g);
    check_tree(g, cd, n);
  }

  // Caterpillar: backbone with pending leaves
  {
    int backbone = 50, total = 150;
    vector<vector<int>> g(total);
    for (int i = 0; i + 1 < backbone; i++) {
      g[i].push_back(i + 1);
      g[i + 1].push_back(i);
    }
    int next_leaf = backbone;
    for (int i = 0; i < backbone && next_leaf < total; i++) {
      int leaves = int((next_leaf + i) % 3);
      for (int k = 0; k < leaves && next_leaf < total; k++) {
        g[i].push_back(next_leaf);
        g[next_leaf].push_back(i);
        next_leaf++;
      }
    }
    // Fill remaining as leaves of vertex 0
    while (next_leaf < total) {
      g[0].push_back(next_leaf);
      g[next_leaf].push_back(0);
      next_leaf++;
    }
    CentroidDecomp cd(g);
    check_tree(g, cd, total);
  }

  // Random trees of many sizes
  for (int iter = 0; iter < 500; iter++) {
    int n = 1 + int(rng() % 200);
    auto g = random_tree(n, rng);
    CentroidDecomp cd(g);
    check_tree(g, cd, n);
  }

  // Larger random trees
  for (int iter = 0; iter < 20; iter++) {
    int n = 500 + int(rng() % 2000);
    auto g = random_tree(n, rng);
    CentroidDecomp cd(g);
    check_tree(g, cd, n);
  }

  int a, b;
  cin >> a >> b;
  cout << a + b << '\n';
}
