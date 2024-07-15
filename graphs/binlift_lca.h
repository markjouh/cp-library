struct LCA {
    int n, lg;
    vi dep;
    vec<vi> up;

    LCA(vec<vi> &g) : n(sz(g)), lg(__lg(n) + 1), dep(n, INF), up(n, vi(lg, -1)) {
        queue<int> q;
        dep[0] = 0;
        q.push(0);
        while (sz(q)) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dep[v] == INF) {
                    dep[v] = dep[u] + 1;
                    up[v][0] = u;
                    rep(i, 1, lg) {
                        if (up[v][i - 1] == -1) {
                            break;
                        }
                        up[v][i] = up[up[v][i - 1]][i - 1];
                    }
                    q.push(v);
                }
            }
        }
    }

    int anc(int x, int k) {
        rep(i, lg) {
            if (x != -1 && ((k >> i) & 1)) {
                x = up[x][i];
            }
        }
        return x;
    }

    int lca(int x, int y) {
        if (dep[x] < dep[y]) {
            swap(x, y);
        }
        x = anc(x, dep[x] - dep[y]);
        if (x == y) {
            return x;
        }
        per(i, lg) {
            if (up[x][i] != up[y][i]) {
                x = up[x][i];
                y = up[y][i];
            }
        }
        return up[x][0];
    }

    int dist(int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)] + 1;
    }
};
