#pragma once

int myDeque[1 << 17];
 
auto bfs01(const vector<vector<pair<int, bool>>> &g, int start = 0) {
  vector<int> dist(sz(g), INT_MAX / 2);
  int dL = 1 << 16, dR = dL;
  
  dist[start] = 0;
  myDeque[dL] = start;
 
  while (dL <= dR) {
    int u = myDeque[dL++];
    for (auto [v, w] : g[u]) {
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        if (w) {
          myDeque[++dR] = v;
        } else {
          myDeque[--dL] = v;
        }
      }
    }
  }
  return dist;
}