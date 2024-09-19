#pragma once

struct CentroidDecomp {
    vector<int> par;

    CentroidDecomp(const vector<vector<int>> &g_) : g(g_) {
        par.resize(sz(g));
        blocked.resize(sz(g));
        st_size.resize(sz(g));
        for (int i = 0; i < sz(g); i++) {
            if (st_size[i] == 0) {
                build(i, -1);
            }
        }
        blocked.clear();
        st_size.clear();
    }

private:
    const vector<vector<int>> &g;
    vector<bool> blocked;
    vector<int> st_size;

    void get_sizes(int u, int u_par) {
        st_size[u] = 1;
        for (int v : g[u]) {
            if (v != u_par && !blocked[v]) {
                get_sizes(v, u);
                st_size[u] += st_size[v];
            }
        }
    }

    int find_centroid(int u, int u_par, int tree_sz) {
        int nxt = -1;
        for (int v : g[u]) {
            if (v != u_par && !blocked[v] && st_size[v] * 2 > tree_sz) {
                nxt = v;
                break;
            }
        }
        return nxt == -1 ? u : find_centroid(nxt, u, tree_sz);
    }

    void build(int u, int u_par) {
        get_sizes(u, -1);
        const int root = find_centroid(u, -1, st_size[u]);
        par[root] = u_par;
        blocked[root] = true;
        for (int v : g[root]) {
            if (!blocked[v]) {
                build(v, root);
            }
        }
    }
};
