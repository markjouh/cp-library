/* Given a rooted tree, computes binary lifts, which enable O(log(N)) LCA.
 * TODO: arbitrary path aggregates?
 */

struct binary_lifts {
    int n, lg;
    vector<int> dep;
    vector<vector<int>> up;

    binary_lifts(const vector<vector<int>> &g, int root = 0) : n(sz(g)), lg(__lg(n) + 1), dep(n, -1), up(n, vector<int>(lg, -1)) {
        queue<int> q;
        dep[root] = 0;
        q.push(root);
        while (sz(q)) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    up[v][0] = u;
                    for (int i = 1; i < lg; i++) {
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

    int par(int x) {
        return up[x][0];
    }

    int anc(int x, int k) {
        for (int i = 0; i < lg; i++) {
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
        for (int i = lg - 1; i >= 0; i--) {
            if (up[x][i] != up[y][i]) {
                x = up[x][i];
                y = up[y][i];
            }
        }
        return up[x][0];
    }

    int dist(int x, int y) {
        return dep[x] + dep[y] - 2 * dep[lca(x, y)];
    }
};
