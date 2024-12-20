#include "../../datastructures/static/sparse_table.h"

struct rmq_lca {
    vector<int> tin, dep;
    sparse_table<pair<int, int>, min_op<pair<int, int>>> rmq;

    rmq_lca() {}
    rmq_lca(const vector<vector<int>> &g) {
        tin.resize(sz(g));
        dep.resize(sz(g));
        vector<pair<int, int>> d;

        auto dfs = [&](auto &&self, int u, int par) -> void {
            tin[u] = sz(d);
            d.emplace_back(dep[u], u);
            for (int v : g[u]) {
                if (v != par) {
                    dep[v] = dep[u] + 1;
                    self(self, v, u);
                    d.emplace_back(dep[u], u);
                }
            }
        };

        dfs(dfs, 0, -1);
        rmq = sparse_table<pair<int, int>, min_op<pair<int, int>>>(d);
    }

    int lca(int u, int v) {
        if (tin[u] > tin[v]) {
            swap(u, v);
        }
        return rmq.query(tin[u], tin[v]).second;
    }
    int dist(int u, int v) {
        if (tin[u] > tin[v]) {
            swap(u, v);
        }
        return dep[u] + dep[v] - 2 * rmq.query(tin[u], tin[v]).first;
    }
};