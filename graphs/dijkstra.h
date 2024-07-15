vi dijk(vec<vpi> &g, int r = 0) {
    vi dist(sz(g), inf); dist[r] = 0;
    queue<pi> q; q.emplace(0, 0);
    while (sz(q)) {
        auto [d, u] = q.front(); q.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : g[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                q.emplace(dist[v], v);
            }
        }
    }
    return dist;
}
