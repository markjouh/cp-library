#pragma once

struct BinaryLifting {
    int log;
    vector<int> dep;
    vector<vector<int>> up;

    BinaryLifting(const vector<vector<int>> &g, int root = 0) {
        log = __lg(sz(g) - 1) + 1;
        dep.resize(sz(g), -1);
        up = vector(sz(g), vector<int>(log, -1));

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
                    for (int i = 1; i < log; i++) {
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
        for (int i = 0; i < log; i++) {
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
        for (int i = log - 1; i >= 0; i--) {
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
