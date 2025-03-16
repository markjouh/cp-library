---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/edmonds_karp_max_flow.h\"\nstruct EdmondsKarpMaxFlow\
    \ {\n  struct Edge {\n    int from, to;\n    int c, f;\n  };\n\n  int n, s, t;\n\
    \  vector<vector<int>> g;\n  vector<Edge> edges;\n\n  EdmondsKarpMaxFlow(int n_,\
    \ int s_, int t_) : n(n_), s(s_), t(t_), g(n) {}\n\n  void add(int u, int v, int\
    \ cap = INT_MAX) {\n    g[u].push_back(edges.size());\n    edges.push_back({u,\
    \ v, cap, 0});\n    g[v].push_back(edges.size());\n    edges.push_back({v, u,\
    \ 0, 0});\n  }\n\n  int max_flow() {\n    int res = 0;\n\n    while (true) {\n\
    \      bool found_path = false;\n\n      vector<int> par(n, -1);\n      queue<pair<int,\
    \ int>> q;\n      par[s] = -2;\n      q.push({s, INT_MAX});\n\n      while (!q.empty())\
    \ {\n        auto [u, mn] = q.front();\n        q.pop();\n\n        if (u == t)\
    \ {\n          res += mn;\n          found_path = true;\n          while (u !=\
    \ s) {\n            edges[par[u]].f += mn;\n            edges[par[u] ^ 1].f -=\
    \ mn;\n            u = edges[par[u]].from;\n          }\n          break;\n  \
    \      }\n\n        for (int id : g[u]) {\n          int v = edges[id].to;\n \
    \         int r = edges[id].c - edges[id].f;\n          if (par[v] == -1 && r\
    \ > 0) {\n            par[v] = id;\n            q.push({v, min(mn, r)});\n   \
    \       }\n        }\n      }\n\n      if (!found_path) {\n        break;\n  \
    \    }\n    }\n\n    return res;\n  }\n};\n"
  code: "struct EdmondsKarpMaxFlow {\n  struct Edge {\n    int from, to;\n    int\
    \ c, f;\n  };\n\n  int n, s, t;\n  vector<vector<int>> g;\n  vector<Edge> edges;\n\
    \n  EdmondsKarpMaxFlow(int n_, int s_, int t_) : n(n_), s(s_), t(t_), g(n) {}\n\
    \n  void add(int u, int v, int cap = INT_MAX) {\n    g[u].push_back(edges.size());\n\
    \    edges.push_back({u, v, cap, 0});\n    g[v].push_back(edges.size());\n   \
    \ edges.push_back({v, u, 0, 0});\n  }\n\n  int max_flow() {\n    int res = 0;\n\
    \n    while (true) {\n      bool found_path = false;\n\n      vector<int> par(n,\
    \ -1);\n      queue<pair<int, int>> q;\n      par[s] = -2;\n      q.push({s, INT_MAX});\n\
    \n      while (!q.empty()) {\n        auto [u, mn] = q.front();\n        q.pop();\n\
    \n        if (u == t) {\n          res += mn;\n          found_path = true;\n\
    \          while (u != s) {\n            edges[par[u]].f += mn;\n            edges[par[u]\
    \ ^ 1].f -= mn;\n            u = edges[par[u]].from;\n          }\n          break;\n\
    \        }\n\n        for (int id : g[u]) {\n          int v = edges[id].to;\n\
    \          int r = edges[id].c - edges[id].f;\n          if (par[v] == -1 && r\
    \ > 0) {\n            par[v] = id;\n            q.push({v, min(mn, r)});\n   \
    \       }\n        }\n      }\n\n      if (!found_path) {\n        break;\n  \
    \    }\n    }\n\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/edmonds_karp_max_flow.h
  requiredBy: []
  timestamp: '2025-03-16 14:57:47-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/edmonds_karp_max_flow.h
layout: document
redirect_from:
- /library/flow/edmonds_karp_max_flow.h
- /library/flow/edmonds_karp_max_flow.h.html
title: flow/edmonds_karp_max_flow.h
---
