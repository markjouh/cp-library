pair<vi, vi> euler_tour(vec<vi> &g, int r = 0) {
    pair<vi, vi> res;
    res.fi = res.se = vi(sz(g));
    int time = 0;

    auto dfs = [&](auto &&self, int u, int par) -> void {
        res.fi[u] = time++;
        for (int v : g[u]) {
            if (v != par) {
                self(self, v, u);
            }
        }
        res.se[u] = time;
    };

    dfs(dfs, r, -1);
    return res;
}
