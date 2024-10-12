#pragma once

#include "../../datastructures/static/rmq.h"

struct LCA {
    vector<int> tin, dep;
    RMQ<pair<int, int>> rmq;

    LCA(const vector<vector<int>> &g) {
        const int n = sz(g);
        tin.resize(n), dep.resize(n);

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
        rmq = RMQ(d);
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