pair<vector<int>, vector<int>> euler_tour(const vector<vector<int>> &g) {
  const int n = g.size();
  vector<int> tin(n), tout(n);

  int time = 0;

  auto dfs = [&](auto &&self, int u, int par) -> void {
    tin[u] = time++;
    for (int v : g[u]) {
      if (v != par) {
        self(self, v, u);
      }
    }
    tout[u] = time;
  };

  dfs(dfs, 0, -1);

  return make_pair(tin, tout);
}
