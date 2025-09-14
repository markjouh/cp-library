template <class T>
auto dijkstras_k_shortest(const vector<vector<pair<int, int>>> &g, int k, int start = 0) {
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;

  vector<vector<T>> dist(ssize(g));
  for (int i = 0; i < ssize(g); i++) {
    dist[i].reserve(k);
  }

  pq.emplace(0, start);

  while (ssize(pq)) {
    auto [d, u] = pq.top();
    pq.pop();
    if (ssize(dist[u]) == k) {
      continue;
    }
    dist[u].push_back(d);
    for (auto [v, w] : g[u]) {
      pq.emplace(d + w, v);
    }
  }
  return dist;
}
