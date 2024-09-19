#pragma once

struct KosarajuSCC {
    int sccs = 0;
    vector<int> comp;
    vector<vector<int>> members, cond_g;

    KosarajuSCC(const vector<vector<int>> &g_) : g(g_) {
        comp.resize(sz(g), -1);
        rev_g.resize(sz(g));
        vis.resize(sz(g));
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
        rev_g.clear();
        vis.clear();
        ord.clear();

        cond_g.resize(sccs);
        vector<int> prev(sccs, -1);
        for (int i = 0; i < sccs; i++) {
            for (int u : members[i]) {
                for (int v : g[u]) {
                    if (comp[v] != i && prev[comp[v]] < i) {
                        cond_g[i].push_back(comp[v]);
                        prev[comp[v]] = i;
                    }
                }
            }
        }
    }

private:
    const vector<vector<int>> &g;
    vector<vector<int>> rev_g;
    vector<bool> vis;
    vector<int> ord;

    void dfs_setup(int u) {
        vis[u] = true;
        for (int v : g[u]) {
            rev_g[v].push_back(u);
            if (!vis[v]) {
                dfs_setup(v);
            }
        }
        ord.push_back(u);
    }

    void dfs_build(int u) {
        comp[u] = sccs;
        members[sccs].push_back(u);
        for (int v : rev_g[u]) {
            if (comp[v] == -1) {
                dfs_build(v);
            }
        }
    }
};
