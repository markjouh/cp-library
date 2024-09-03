---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1994/submission/279728160
    - https://cp-algorithms.com/graph/euler_path.html
  bundledCode: "#line 2 \"graphs/euler_cycle.hpp\"\n\n// https://cp-algorithms.com/graph/euler_path.html\n\
    // https://codeforces.com/contest/1994/submission/279728160\n\nvec<int> euler_cycle(const\
    \ vec<vec<int>> &g) {\n  vec<vec<pii>> h(sz(g));\n  vector<int> deg(sz(g));\n\
    \  int cnt = 0;\n  rep(u, sz(g)) {\n    int self = 0;\n    for (int v : g[u])\
    \ {\n      if ((u == v && self % 2) || u < v) {\n        h[u].eb(v, cnt);\n  \
    \      h[v].eb(u, cnt);\n        deg[u]++, deg[v]++;\n        cnt++;\n      }\n\
    \      self += u == v;\n    }\n  }\n\n  vec<bool> removed(cnt);\n  vec<int> stk,\
    \ res;\n  stk.pb(0);\n  while (sz(stk)) {\n    int u = stk.back();\n    if (deg[u]\
    \ == 0) {\n      res.pb(u);\n      stk.pop_back();\n    } else {\n      while\
    \ (removed[h[u].back().se]) {\n        h[u].pop_back();\n      }\n      auto [v,\
    \ idx] = h[u].back();\n      h[u].pop_back();\n\n      deg[u]--, deg[v]--;\n \
    \     removed[idx] = true;\n\n      stk.pb(v);\n    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n\n// https://cp-algorithms.com/graph/euler_path.html\n// https://codeforces.com/contest/1994/submission/279728160\n\
    \nvec<int> euler_cycle(const vec<vec<int>> &g) {\n  vec<vec<pii>> h(sz(g));\n\
    \  vector<int> deg(sz(g));\n  int cnt = 0;\n  rep(u, sz(g)) {\n    int self =\
    \ 0;\n    for (int v : g[u]) {\n      if ((u == v && self % 2) || u < v) {\n \
    \       h[u].eb(v, cnt);\n        h[v].eb(u, cnt);\n        deg[u]++, deg[v]++;\n\
    \        cnt++;\n      }\n      self += u == v;\n    }\n  }\n\n  vec<bool> removed(cnt);\n\
    \  vec<int> stk, res;\n  stk.pb(0);\n  while (sz(stk)) {\n    int u = stk.back();\n\
    \    if (deg[u] == 0) {\n      res.pb(u);\n      stk.pop_back();\n    } else {\n\
    \      while (removed[h[u].back().se]) {\n        h[u].pop_back();\n      }\n\
    \      auto [v, idx] = h[u].back();\n      h[u].pop_back();\n\n      deg[u]--,\
    \ deg[v]--;\n      removed[idx] = true;\n\n      stk.pb(v);\n    }\n  }\n  return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graphs/euler_cycle.hpp
  requiredBy: []
  timestamp: '2024-09-03 18:33:43-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/euler_cycle.hpp
layout: document
redirect_from:
- /library/graphs/euler_cycle.hpp
- /library/graphs/euler_cycle.hpp.html
title: graphs/euler_cycle.hpp
---
