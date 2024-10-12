#pragma once

struct TreeIsomorphism {
    map<vector<int>, int> hashes;

    vector<int> gen(const vector<vector<int>> &g, int r = 0) {
        vector<int> res(sz(g));
        dfs(r, -1, g, res);
        return res;
    }

private:
    void dfs(int u, int par, auto &g, auto &res) {
        vector<int> children;
        for (int v : g[u]) {
            if (v != par) {
                dfs(v, u, g, res);
                children.push_back(res[v]);
            }
        }
        sort(all(children));
        if (!hashes.count(children)) {
            hashes[children] = sz(hashes);
        }
        res[u] = hashes[children];
    }
};
