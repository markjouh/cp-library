struct TreeHashing {
    map<vector<int>, int> hash;

    auto add(const vector<vector<int>> &g, int r = 0) {
        vector<int> res(sz(g));
        
        auto dfs = [&](auto &&self, int u, int par) -> void {
            vector<int> ch;
            for (int v : g[u]) {
                if (v != par) {
                    self(self, v, u);
                    ch.push_back(res[v]);
                }
            }
            sort(all(ch));
            if (!hash.count(ch)) {
                hash[ch] = sz(hash);
            }
            res[u] = hash[ch];
        };

        dfs(dfs, r, -1);

        return res;
    }
};
