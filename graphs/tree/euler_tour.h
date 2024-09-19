#pragma once

struct EulerTour {
    vector<int> tin, tout;

    EulerTour(const vector<vector<int>> &g, int root = 0) : adj(g) {
        tin.resize(sz(g));
        tout.resize(sz(g));
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
