struct tree_iso {
    map<vi, int> mp;

    vi gen(vector<vi> &g, int r = 0) {
        vi res(sz(g));

        auto dfs = [&](int u, int par, auto &&self) -> void {
            vi ch;
            for (int v : g[u]) {
                if (v != par) {
                    self(v, u, self);
                    ch.pb(res[v]);
                }
            }
            sort(all(ch));
            if (!mp.count(ch)) {
                mp[ch] = sz(mp);
            }
            res[u] = mp[ch];
        };

        dfs(r, -1, dfs);
        return res;
    }
};
