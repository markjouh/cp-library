struct kosaraju_scc {
    int sccs = 0;
    vector<int> comp;
    vector<vector<int>> members, c_adj;

    kosaraju_scc(const vector<vector<int>> &g) : comp(sz(g), -1), adj(g), t_adj(sz(g)), vis(sz(g)) {
        ord.reserve(sz(g));
        for (int i = 0; i < sz(g); i++) {
            if (!vis[i]) {
                dfs_setup(i);
            }
        }
        for (int i = sz(ord) - 1; i >= 0; i--) {
            if (comp[ord[i]] == -1) {
                members.emplace_back();
                dfs_build(ord[i]);
                sccs++;
            }
        }
        t_adj.clear();
        vis.clear();
        ord.clear();

        c_adj.resize(sccs);
        vector<int> prev(sccs, -1);
        for (int i = 0; i < sccs; i++) {
            for (int u : members[i]) {
                for (int v : adj[u]) {
                    if (comp[v] != i && prev[comp[v]] < i) {
                        c_adj[i].push_back(comp[v]);
                        prev[comp[v]] = i;
                    }
                }
            }
        }
    }

private:
    const vector<vector<int>> &adj;
    vector<vector<int>> t_adj;
    vector<bool> vis;
    vector<int> ord;

    void dfs_setup(int u) {
        vis[u] = true;
        for (int v : adj[u]) {
            t_adj[v].push_back(u);
            if (!vis[v]) {
                dfs_setup(v);
            }
        }
        ord.push_back(u);
    }

    void dfs_build(int u) {
        comp[u] = sccs;
        members[sccs].push_back(u);
        for (int v : t_adj[u]) {
            if (comp[v] == -1) {
                dfs_build(v);
            }
        }
    }
};
