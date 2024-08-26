/* Takes in rooted trees and generates perfect hashes of all subtrees in O(N * log(N)).
 * Two trees are isomorphic if and only if their hashes match.
 */

struct tree_isomorphism {
    map<vector<int>, int> hashes;

    vector<int> gen(const vector<vector<int>> &g, int root = 0) {
        vector<int> res(sz(g));
        dfs(root, -1, g, res);
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
