#pragma once

auto topsort(const vector<vector<int>> &g) {
  vector<int> deg(sz(g));
  for (int u = 0; u < sz(g); u++) {
    for (int v : g[u]) {
      deg[v]++;
    }
  }
  queue<int> q;
  for (int i = 0; i < sz(g); i++) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }
  vector<int> res;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    res.push_back(u);
    for (int v : g[u]) {
      if (--deg[v] == 0) {
        q.push(v);
      }
    }
  }
  return res;
}