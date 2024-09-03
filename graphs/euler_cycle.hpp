#pragma once

// https://cp-algorithms.com/graph/euler_path.html
// https://codeforces.com/contest/1994/submission/279728160

vec<int> euler_cycle(const vec<vec<int>> &g) {
  vec<vec<pii>> h(sz(g));
  vector<int> deg(sz(g));
  int cnt = 0;
  rep(u, sz(g)) {
    int self = 0;
    for (int v : g[u]) {
      if ((u == v && self % 2) || u < v) {
        h[u].eb(v, cnt);
        h[v].eb(u, cnt);
        deg[u]++, deg[v]++;
        cnt++;
      }
      self += u == v;
    }
  }

  vec<bool> removed(cnt);
  vec<int> stk, res;
  stk.pb(0);
  while (sz(stk)) {
    int u = stk.back();
    if (deg[u] == 0) {
      res.pb(u);
      stk.pop_back();
    } else {
      while (removed[h[u].back().se]) {
        h[u].pop_back();
      }
      auto [v, idx] = h[u].back();
      h[u].pop_back();

      deg[u]--, deg[v]--;
      removed[idx] = true;

      stk.pb(v);
    }
  }
  return res;
}