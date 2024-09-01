---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/tree/euler_tour.hpp\"\n\nstruct EulerTour {\n  vector<int>\
    \ tin, tout;\n\n  EulerTour(const vector<vector<int>> &g, int root = 0) : adj(g)\
    \ {\n    tin.resize(sz(g));\n    tout.resize(sz(g));\n    dfs(root, -1);\n  }\n\
    \nprivate:\n  int time = 0;\n  const vector<vector<int>> &adj;\n\n  void dfs(int\
    \ u, int par) {\n    tin[u] = time++;\n    for (int v : adj[u]) {\n      if (v\
    \ != par) {\n        dfs(v, u);\n      }\n    }\n    tout[u] = time;\n  }\n};\n"
  code: "#pragma once\n\nstruct EulerTour {\n  vector<int> tin, tout;\n\n  EulerTour(const\
    \ vector<vector<int>> &g, int root = 0) : adj(g) {\n    tin.resize(sz(g));\n \
    \   tout.resize(sz(g));\n    dfs(root, -1);\n  }\n\nprivate:\n  int time = 0;\n\
    \  const vector<vector<int>> &adj;\n\n  void dfs(int u, int par) {\n    tin[u]\
    \ = time++;\n    for (int v : adj[u]) {\n      if (v != par) {\n        dfs(v,\
    \ u);\n      }\n    }\n    tout[u] = time;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/tree/euler_tour.hpp
  requiredBy: []
  timestamp: '2024-08-31 22:39:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/tree/euler_tour.hpp
layout: document
redirect_from:
- /library/graphs/tree/euler_tour.hpp
- /library/graphs/tree/euler_tour.hpp.html
title: graphs/tree/euler_tour.hpp
---
