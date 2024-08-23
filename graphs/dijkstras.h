/* Given a weighted graph, computes and constructs the shortest paths from the
 * starting vertex in O((V + E) * log(V)).
 */

template<class T> pair<vector<T>, vector<int>> dijkstras(const vector<vector<pair<int, int>>> &g, int start = 0) {
    vector<T> dist(sz(g), numeric_limits<T>::max());
    vector<int> from(sz(g), -1);
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
    dist[start] = 0;
    pq.emplace(0, start);
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
