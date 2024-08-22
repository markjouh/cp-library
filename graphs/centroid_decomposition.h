vi centroid_decomp(vec<vi> &g) {
    const int n = sz(g);
    vb blocked(n);
    vi st_size(n), par(n, -1);

    auto get_sizes = [&](auto &&self, int u, int p) -> void {
        st_size[u] = 1;
        for (int v : g[u]) {
            if (v != p && !blocked[v]) {
                self(self, v, u);
                st_size[u] += st_size[v];
            }
        }
    };

    auto find_centroid = [&](auto &&self, int u, int p, int sz) -> int {
        int to = -1;
        for (int v : g[u]) {
            if (v != p && !blocked[v] && st_size[v] > sz / 2) {
                to = v;
            }
        }
        return to == -1 ? u : self(self, to, u, sz);
    };

    auto gen_tree = [&](auto &&self, int u, int p) -> void {
        get_sizes(get_sizes, u, -1);
        int cent = find_centroid(find_centroid, u, -1, st_size[u]);
        par[cent] = p;
        blocked[cent] = true;
        if (st_size[u] > 1) {
            for (int v : g[cent]) {
                if (!blocked[v]) {
                    self(self, v, cent);
                }
            }
        }
    };

    rep(i, n) {
        if (st_size[i] == 0) {
            gen_tree(gen_tree, i, -1);
        }
    }
    return par;
}
