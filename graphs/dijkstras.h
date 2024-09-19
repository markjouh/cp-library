#pragma once

template <class T>
auto dijkstras(const vector<vector<pair<int, int>>> &g, int start = 0) {
    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;

    vector<T> dist(sz(g), numeric_limits<T>::max());
    vector<int> from(sz(g), -1);
    
    dist[start] = 0;
    pq.emplace(0, start);

    while (sz(pq)) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d != dist[u]) {
            continue;
        }
        for (auto [v, w] : g[u]) {
            if (ckmin(dist[v], d + w)) {
                from[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }
    return make_pair(dist, from);
}
