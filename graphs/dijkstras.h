pair<vl, vi> dijkstras(vec<vpi> &g, int r = 0) {
    vl dist(sz(g), infl);
    vi from(sz(g), -1);
    priority_queue<pl, vec<pl>, greater<pl>> pq;
    dist[r] = 0;
    pq.emplace(0, r);
    while (sz(pq)) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) {
            continue;
        }
        for (auto [v, w] : g[u]) {
            if (d + w < dist[v]) {
                dist[v] = d + w;
                from[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
    return {dist, from};
}
