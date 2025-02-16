template <class T, auto op, auto id>
struct tree_paths {
    int log;
    vector<int> dep;
    vector<vector<int>> up;
    vector<vector<T>> val;

    tree_paths(const vector<vector<pair<int, int>>> &g, int root = 0) {
        log = __lg(sz(g)) + 1;
        dep.resize(sz(g), -1);
        up = vector(sz(g), vector<int>(log, -1));
        val = vector(sz(g), vector<T>(log, id()));

        queue<int> q;
        dep[root] = 0;
        q.push(root);
        while (sz(q)) {
            int u = q.front();
            q.pop();
            for (auto [v, w] : g[u]) {
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    up[v][0] = u;
                    val[v][0] = w;
                    for (int i = 1; i < log; i++) {
                        if (up[v][i - 1] == -1) {
                            break;
                        }
                        up[v][i] = up[up[v][i - 1]][i - 1];
                        val[v][i] = op(val[v][i - 1], val[up[v][i - 1]][i - 1]);
                    }
                    q.push(v);
                }
            }
        }
    }

    T query(int x, int y) {
        if (dep[x] < dep[y]) {
            swap(x, y);
        }
        T res = id();
        const int diff = dep[x] - dep[y];
        for (int i = 0; i < log; i++) {
            if (x != -1 && ((diff >> i) & 1)) {
                res = op(res, val[x][i]);
                x = up[x][i];
            }
        }
        if (x == y) {
            return res;
        }
        for (int i = log - 1; i >= 0; i--) {
            if (up[x][i] != up[y][i]) {
                res = op(res, val[x][i]);
                res = op(res, val[y][i]);
                x = up[x][i];
                y = up[y][i];
            }
        }
        res = op(res, val[x][0]);
        res = op(res, val[y][0]);
        return res;
    }
};
