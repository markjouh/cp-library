/* Given a rooted undirected tree, computes (tin, tout) such that if vertex v
 * were assigned to position tin[v] for all v, the interval [tin[v], tout[v])
 * would contain exactly the subtree rooted at v for all v.
 */

pair<vector<int>, vector<int>> euler_tour(const vector<vector<int>> &g, int root = 0) {
    pair<vector<int>, vector<int>> res;
    res.first = res.second = vector<int>(sz(g));
    int time = 0;

    auto dfs = [&](auto &&self, int u, int par) -> void {
        res.first[u] = time++;
        for (int v : g[u]) {
            if (v != par) {
                self(self, v, u);
            }
        }
        res.second[u] = time;
    };

    dfs(dfs, root, -1);
    return res;
}
