#pragma once

// https://cp-algorithms.com/graph/euler_path.html
// https://codeforces.com/contest/1994/submission/279728160

vector<int> findEulerCycle(const vector<vector<int>> &g) {
  vector<vector<pair<int, int>>> h(sz(g));
  vector<int> deg(sz(g));
  int cnt = 0;
  for (int u = 0; u < sz(g); u++) {
    int self = 0;
    for (int v : g[u]) {
      if ((u == v && self % 2) || u < v) {
        h[u].emplace_back(v, cnt);
        h[v].emplace_back(u, cnt);
        deg[u]++, deg[v]++;
        cnt++;
      }
      self += u == v;
    }
  }

  vector<bool> removed(cnt);
  vector<int> stk, res;
  stk.push_back(0);
  while (sz(stk)) {
    int u = stk.back();
    if (deg[u] == 0) {
      res.push_back(u);
      stk.pop_back();
    } else {
      while (removed[h[u].back().se]) {
        h[u].pop_back();
      }
      auto [v, idx] = h[u].back();
      h[u].pop_back();

      deg[u]--, deg[v]--;
      removed[idx] = true;

      stk.push_back(v);
    }
  }
  return res;
}