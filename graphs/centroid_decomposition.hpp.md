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
  bundledCode: "#line 2 \"graphs/centroid_decomposition.hpp\"\n\nstruct CentroidDecomposition\
    \ {\n  vector<int> cd_par;\n\n  CentroidDecomposition(const vector<vector<int>>\
    \ &g) : adj(g) {\n    cd_par.resize(sz(g));\n    blocked.resize(sz(g));\n    st_size.resize(sz(g));\n\
    \    for (int i = 0; i < sz(g); i++) {\n      if (st_size[i] == 0) {\n       \
    \ build(i, -1);\n      }\n    }\n    blocked.clear();\n    st_size.clear();\n\
    \  }\n\nprivate:\n  const vector<vector<int>> &adj;\n  vector<bool> blocked;\n\
    \  vector<int> st_size;\n\n  void get_sizes(int u, int par) {\n    st_size[u]\
    \ = 1;\n    for (int v : adj[u]) {\n      if (v != par && !blocked[v]) {\n   \
    \     get_sizes(v, u);\n        st_size[u] += st_size[v];\n      }\n    }\n  }\n\
    \n  int find_centroid(int u, int par, int tree_sz) {\n    int nxt = -1;\n    for\
    \ (int v : adj[u]) {\n      if (v != par && !blocked[v] && st_size[v] * 2 > tree_sz)\
    \ {\n        nxt = v;\n        break;\n      }\n    }\n    return nxt == -1 ?\
    \ u : find_centroid(nxt, u, tree_sz);\n  }\n\n  void build(int u, int par) {\n\
    \    get_sizes(u, -1);\n    const int root = find_centroid(u, -1, st_size[u]);\n\
    \    cd_par[root] = par;\n    blocked[root] = true;\n    for (int v : adj[root])\
    \ {\n      if (!blocked[v]) {\n        build(v, root);\n      }\n    }\n  }\n\
    };\n"
  code: "#pragma once\n\nstruct CentroidDecomposition {\n  vector<int> cd_par;\n\n\
    \  CentroidDecomposition(const vector<vector<int>> &g) : adj(g) {\n    cd_par.resize(sz(g));\n\
    \    blocked.resize(sz(g));\n    st_size.resize(sz(g));\n    for (int i = 0; i\
    \ < sz(g); i++) {\n      if (st_size[i] == 0) {\n        build(i, -1);\n     \
    \ }\n    }\n    blocked.clear();\n    st_size.clear();\n  }\n\nprivate:\n  const\
    \ vector<vector<int>> &adj;\n  vector<bool> blocked;\n  vector<int> st_size;\n\
    \n  void get_sizes(int u, int par) {\n    st_size[u] = 1;\n    for (int v : adj[u])\
    \ {\n      if (v != par && !blocked[v]) {\n        get_sizes(v, u);\n        st_size[u]\
    \ += st_size[v];\n      }\n    }\n  }\n\n  int find_centroid(int u, int par, int\
    \ tree_sz) {\n    int nxt = -1;\n    for (int v : adj[u]) {\n      if (v != par\
    \ && !blocked[v] && st_size[v] * 2 > tree_sz) {\n        nxt = v;\n        break;\n\
    \      }\n    }\n    return nxt == -1 ? u : find_centroid(nxt, u, tree_sz);\n\
    \  }\n\n  void build(int u, int par) {\n    get_sizes(u, -1);\n    const int root\
    \ = find_centroid(u, -1, st_size[u]);\n    cd_par[root] = par;\n    blocked[root]\
    \ = true;\n    for (int v : adj[root]) {\n      if (!blocked[v]) {\n        build(v,\
    \ root);\n      }\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-08-28 03:16:10-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graphs/centroid_decomposition.hpp
- /library/graphs/centroid_decomposition.hpp.html
title: graphs/centroid_decomposition.hpp
---
