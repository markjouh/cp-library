#pragma once

struct euler_tour {
    vector<int> tin, tout;

    euler_tour(const vector<vector<int>> &g, int root = 0) : adj(g) {
        dfs(root, -1);
    }

private:
    int time = 0;
    const vector<vector<int>> &adj;

    void dfs(int u, int par) {
        tin[u] = time++;
        for (int v : adj[u]) {
            if (v != par) {
                dfs(v, u);
            }
        }
        tout[u] = time;
    }
};
