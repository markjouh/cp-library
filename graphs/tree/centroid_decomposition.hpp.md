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
  bundledCode: "#line 2 \"graphs/tree/centroid_decomposition.hpp\"\n\nstruct CentroidDecomposition\
    \ {\n  vector<int> cdPar;\n\n  CentroidDecomposition(const vector<vector<int>>\
    \ &g) : adj(g) {\n    cdPar.resize(sz(g));\n    blocked.resize(sz(g));\n    stSize.resize(sz(g));\n\
    \    for (int i = 0; i < sz(g); i++) {\n      if (stSize[i] == 0) {\n        build(i,\
    \ -1);\n      }\n    }\n    blocked.clear();\n    stSize.clear();\n  }\n\nprivate:\n\
    \  const vector<vector<int>> &adj;\n  vector<bool> blocked;\n  vector<int> stSize;\n\
    \n  void getSizes(int u, int par) {\n    stSize[u] = 1;\n    for (int v : adj[u])\
    \ {\n      if (v != par && !blocked[v]) {\n        getSizes(v, u);\n        stSize[u]\
    \ += stSize[v];\n      }\n    }\n  }\n\n  int findCentroid(int u, int par, int\
    \ treeSize) {\n    int nxt = -1;\n    for (int v : adj[u]) {\n      if (v != par\
    \ && !blocked[v] && stSize[v] * 2 > treeSize) {\n        nxt = v;\n        break;\n\
    \      }\n    }\n    return nxt == -1 ? u : findCentroid(nxt, u, treeSize);\n\
    \  }\n\n  void build(int u, int par) {\n    getSizes(u, -1);\n    const int root\
    \ = findCentroid(u, -1, stSize[u]);\n    cdPar[root] = par;\n    blocked[root]\
    \ = true;\n    for (int v : adj[root]) {\n      if (!blocked[v]) {\n        build(v,\
    \ root);\n      }\n    }\n  }\n};\n"
  code: "#pragma once\n\nstruct CentroidDecomposition {\n  vector<int> cdPar;\n\n\
    \  CentroidDecomposition(const vector<vector<int>> &g) : adj(g) {\n    cdPar.resize(sz(g));\n\
    \    blocked.resize(sz(g));\n    stSize.resize(sz(g));\n    for (int i = 0; i\
    \ < sz(g); i++) {\n      if (stSize[i] == 0) {\n        build(i, -1);\n      }\n\
    \    }\n    blocked.clear();\n    stSize.clear();\n  }\n\nprivate:\n  const vector<vector<int>>\
    \ &adj;\n  vector<bool> blocked;\n  vector<int> stSize;\n\n  void getSizes(int\
    \ u, int par) {\n    stSize[u] = 1;\n    for (int v : adj[u]) {\n      if (v !=\
    \ par && !blocked[v]) {\n        getSizes(v, u);\n        stSize[u] += stSize[v];\n\
    \      }\n    }\n  }\n\n  int findCentroid(int u, int par, int treeSize) {\n \
    \   int nxt = -1;\n    for (int v : adj[u]) {\n      if (v != par && !blocked[v]\
    \ && stSize[v] * 2 > treeSize) {\n        nxt = v;\n        break;\n      }\n\
    \    }\n    return nxt == -1 ? u : findCentroid(nxt, u, treeSize);\n  }\n\n  void\
    \ build(int u, int par) {\n    getSizes(u, -1);\n    const int root = findCentroid(u,\
    \ -1, stSize[u]);\n    cdPar[root] = par;\n    blocked[root] = true;\n    for\
    \ (int v : adj[root]) {\n      if (!blocked[v]) {\n        build(v, root);\n \
    \     }\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/tree/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-09-11 14:56:51-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/tree/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graphs/tree/centroid_decomposition.hpp
- /library/graphs/tree/centroid_decomposition.hpp.html
title: graphs/tree/centroid_decomposition.hpp
---
