struct centroid_decomp {
    int root;
    vector<int> par;
    vector<vector<int>> h;

    const vector<int> &operator[](int u) {
        return h[u];
    }

    centroid_decomp(const vector<vector<int>> &g_) : g(g_) {
        const int n = sz(g);
        par.resize(n);
        blocked.resize(n);
        size_st.resize(n);
        for (int i = 0; i < n; i++) {
            if (size_st[i] == 0) {
                build(i, -1);
            }
        }
        blocked.clear();
        size_st.clear();

        h.resize(n);
        for (int i = 0; i < n; i++) {
            if (par[i] == -1) {
                root = i;
            } else {
                h[par[i]].push_back(i);
            }
        }
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
        const int cent = find_centroid(u, -1, size_st[u]);
        par[cent] = u_par;
        blocked[cent] = true;
        for (int v : g[cent]) {
            if (!blocked[v]) {
                build(v, cent);
            }
        }
    }
};