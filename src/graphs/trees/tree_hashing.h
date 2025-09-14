map<vector<int>, int> tree_hashes;

auto hash_tree(const vector<vector<int>> &g, int root = 0) {
  vector<int> res(ssize(g));
  
  auto dfs = [&](auto &&self, int u, int par) -> void {
    vector<int> ch;
    for (int v : g[u]) {
      if (v != par) {
        self(self, v, u);
        ch.push_back(res[v]);
      }
    }
    sort(all(ch));
    if (!tree_hashes.count(ch)) {
      tree_hashes[ch] = ssize(tree_hashes);
    }
    res[u] = tree_hashes[ch];
  };

  dfs(dfs, root, -1);

  return res;
}
