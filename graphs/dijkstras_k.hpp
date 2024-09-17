#pragma once

template <class T>
auto dijkstrasK(const vector<vector<pair<int, int>>> &g, int k, int start = 0) {
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;

  vector<vector<T>> dist(sz(g));
  for (int i = 0; i < sz(g); i++) {
    dist[i].reserve(k);
  }
  
  pq.emplace(0, start);

  while (sz(pq)) {
    auto [d, u] = pq.top();
    pq.pop();
    if (sz(dist[u]) == k) {
      continue;
    }
    dist[u].push_back(d);
    for (auto [v, w] : g[u]) {
      pq.emplace(d + w, v);
    }
  }
  return dist;
}