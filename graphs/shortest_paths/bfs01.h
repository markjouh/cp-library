int dq[1 << 17];
 
auto bfs01(const vector<vector<pair<int, bool>>> &g, int start = 0) {
    vector<int> dist(sz(g), INT_MAX / 2);
    int l = 1 << 16, r = l;
    
    dist[start] = 0;
    dq[l] = start;
 
    while (l <= r) {
        int u = dq[l++];
        for (auto [v, w] : g[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                dq[w ? ++r : --l] = v;
            }
        }
    }
    return dist;
}