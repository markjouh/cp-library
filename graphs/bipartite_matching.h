// Left and right parts should have separate numbering
// ls_adj should contain the neighbors of the left part
// rs_match should be the size of the right part, and be initialized with -1s

bool find(int j, vector<vector<int>> &ls_adj, vector<int> &rs_match, vector<int> &vis) {
    if (rs_match[j] == -1) {
        return 1;
    }
    vis[j] = 1;
    int di = rs_match[j];
    for (int e : ls_adj[di]) {
        if (!vis[e] && find(e, ls_adj, rs_match, vis)) {
            rs_match[e] = di;
            return 1;
        }
    }
    return 0;
}

int bipartite_matching(vector<vector<int>> &ls_adj, vector<int> &rs_match) {
    vector<int> vis;
    for (int i = 0; i < sz(ls_adj); i++) {
        vis.assign(sz(rs_match), 0);
        for (int j : ls_adj[i]) {
            if (find(j, ls_adj, rs_match, vis)) {
                rs_match[j] = i;
                break;
            }
        }
    }
    return sz(rs_match) - count(all(rs_match), -1);
}
