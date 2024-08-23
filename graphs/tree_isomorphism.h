/* Takes in rooted trees and computes perfect hashes of all subtrees in O(N * log(N)).
 * Two trees are isomorphic if and only if their hashes match.
 */

struct tree_isomorphism {
    map<vector<int>, int> hashes;

    vector<int> compute(const vector<vector<int>> &g, int root = 0) {
        vector<int> res(sz(g));

        auto dfs = [&](int u, int par, auto &&self) -> void {
            vector<int> children;
            for (int v : g[u]) {
                if (v != par) {
                    self(v, u, self);
                    children.push_back(res[v]);
                }
            }
            sort(all(children));
            if (!hashes.count(children)) {
                hashes[children] = sz(hashes);
            }
            res[u] = hashes[children];
        };

        dfs(root, -1, dfs);
        return res;
    }
};
