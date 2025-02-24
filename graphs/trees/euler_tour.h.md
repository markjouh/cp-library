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
  bundledCode: "#line 1 \"graphs/trees/euler_tour.h\"\npair<vector<int>, vector<int>>\
    \ euler_tour(const vector<vector<int>> &g) {\n  const int n = g.size();\n  vector<int>\
    \ tin(n), tout(n);\n\n  int time = 0;\n\n  auto dfs = [&](auto &&self, int u,\
    \ int par) -> void {\n    tin[u] = time++;\n    for (int v : g[u]) {\n      if\
    \ (v != par) {\n        self(self, v, u);\n      }\n    }\n    tout[u] = time;\n\
    \  };\n\n  dfs(dfs, 0, -1);\n\n  return make_pair(tin, tout);\n}\n"
  code: "pair<vector<int>, vector<int>> euler_tour(const vector<vector<int>> &g) {\n\
    \  const int n = g.size();\n  vector<int> tin(n), tout(n);\n\n  int time = 0;\n\
    \n  auto dfs = [&](auto &&self, int u, int par) -> void {\n    tin[u] = time++;\n\
    \    for (int v : g[u]) {\n      if (v != par) {\n        self(self, v, u);\n\
    \      }\n    }\n    tout[u] = time;\n  };\n\n  dfs(dfs, 0, -1);\n\n  return make_pair(tin,\
    \ tout);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/trees/euler_tour.h
  requiredBy: []
  timestamp: '2025-02-24 14:32:43-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/trees/euler_tour.h
layout: document
redirect_from:
- /library/graphs/trees/euler_tour.h
- /library/graphs/trees/euler_tour.h.html
title: graphs/trees/euler_tour.h
---
