#pragma once

struct centroid_decomp {
    vector<int> cd_par;

    centroid_decomp(const vector<vector<int>> &g) : cd_par(sz(g)), adj(g), blocked(sz(g)), st_size(sz(g)) {
        for (int i = 0; i < sz(g); i++) {
            if (st_size[i] == 0) {
                build(i, -1);
            }
        }
        blocked.clear();
        st_size.clear();
    }
private:
    const vector<vector<int>> &adj;
    vector<bool> blocked;
    vector<int> st_size;

    void get_sizes(int u, int par) {
        st_size[u] = 1;
        for (int v : adj[u]) {
            if (v != par && !blocked[v]) {
                get_sizes(v, u);
                st_size[u] += st_size[v];
            }
        }
    }

    int find_centroid(int u, int par, int tree_sz) {
        int nxt = -1;
        for (int v : adj[u]) {
            if (v != par && !blocked[v] && st_size[v] * 2 > tree_sz) {
                nxt = v;
                break;
            }
        }
        return nxt == -1 ? u : find_centroid(nxt, u, tree_sz);
    }

    void build(int u, int par) {
        get_sizes(u, -1);
        const int root = find_centroid(u, -1, st_size[u]);
        cd_par[root] = par;
        blocked[root] = true;
        for (int v : adj[root]) {
            if (!blocked[v]) {
                build(v, root);
            }
        }
    }
};
