#pragma once

struct CentroidDecomp {
    vector<int> par;

    CentroidDecomp(const vector<vector<int>> &g_) : g(g_) {
        par.resize(sz(g));
        blocked.resize(sz(g));
        size_st.resize(sz(g));
        for (int i = 0; i < sz(g); i++) {
            if (size_st[i] == 0) {
                build(i, -1);
            }
        }
        blocked.clear();
        size_st.clear();
    }

private:
    const vector<vector<int>> &g;
    vector<bool> blocked;
    vector<int> size_st;

    void get_sizes(int u, int u_par) {
        size_st[u] = 1;
        for (int v : g[u]) {
            if (v != u_par && !blocked[v]) {
                get_sizes(v, u);
                size_st[u] += size_st[v];
            }
        }
    }

    int find_centroid(int u, int u_par, int tree_sz) {
        int nxt = -1;
        for (int v : g[u]) {
            if (v != u_par && !blocked[v] && size_st[v] * 2 > tree_sz) {
                nxt = v;
                break;
            }
        }
        return nxt == -1 ? u : find_centroid(nxt, u, tree_sz);
    }

    void build(int u, int u_par) {
        get_sizes(u, -1);
        const int root = find_centroid(u, -1, size_st[u]);
        par[root] = u_par;
        blocked[root] = true;
        for (int v : g[root]) {
            if (!blocked[v]) {
                build(v, root);
            }
        }
    }
};
