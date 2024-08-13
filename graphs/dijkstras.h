template<class T> pair<vec<T>, vi> dijkstras(vec<vpi> &g, int r = 0) {
    vec<T> dist(sz(g), numeric_limits<T>::max());
    vi from(sz(g), -1);
    priority_queue<pair<T, int>, vec<pair<T, int>>, greater<pair<T, int>>> pq;
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
