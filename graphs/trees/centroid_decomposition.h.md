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
  bundledCode: "#line 2 \"graphs/trees/centroid_decomposition.h\"\n\nstruct CentroidDecomp\
    \ {\n    int root;\n    vector<int> par;\n    vector<vector<int>> h;\n\n    const\
    \ vector<int> &operator[](int u) {\n        return h[u];\n    }\n\n    CentroidDecomp(const\
    \ vector<vector<int>> &g_) : g(g_) {\n        const int n = sz(g);\n        par.resize(n);\n\
    \        blocked.resize(n);\n        size_st.resize(n);\n        for (int i =\
    \ 0; i < n; i++) {\n            if (size_st[i] == 0) {\n                build(i,\
    \ -1);\n            }\n        }\n        blocked.clear();\n        size_st.clear();\n\
    \n        h.resize(n);\n        for (int i = 0; i < n; i++) {\n            if\
    \ (par[i] == -1) {\n                root = i;\n            } else {\n        \
    \        h[par[i]].push_back(i);\n            }\n        }\n    }\n\nprivate:\n\
    \    const vector<vector<int>> &g;\n    vector<bool> blocked;\n    vector<int>\
    \ size_st;\n\n    void get_sizes(int u, int u_par) {\n        size_st[u] = 1;\n\
    \        for (int v : g[u]) {\n            if (v != u_par && !blocked[v]) {\n\
    \                get_sizes(v, u);\n                size_st[u] += size_st[v];\n\
    \            }\n        }\n    }\n    int find_centroid(int u, int u_par, int\
    \ tree_sz) {\n        int nxt = -1;\n        for (int v : g[u]) {\n          \
    \  if (v != u_par && !blocked[v] && size_st[v] * 2 > tree_sz) {\n            \
    \    nxt = v;\n                break;\n            }\n        }\n        return\
    \ nxt == -1 ? u : find_centroid(nxt, u, tree_sz);\n    }\n    void build(int u,\
    \ int u_par) {\n        get_sizes(u, -1);\n        const int cent = find_centroid(u,\
    \ -1, size_st[u]);\n        par[cent] = u_par;\n        blocked[cent] = true;\n\
    \        for (int v : g[cent]) {\n            if (!blocked[v]) {\n           \
    \     build(v, cent);\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n\nstruct CentroidDecomp {\n    int root;\n    vector<int> par;\n\
    \    vector<vector<int>> h;\n\n    const vector<int> &operator[](int u) {\n  \
    \      return h[u];\n    }\n\n    CentroidDecomp(const vector<vector<int>> &g_)\
    \ : g(g_) {\n        const int n = sz(g);\n        par.resize(n);\n        blocked.resize(n);\n\
    \        size_st.resize(n);\n        for (int i = 0; i < n; i++) {\n         \
    \   if (size_st[i] == 0) {\n                build(i, -1);\n            }\n   \
    \     }\n        blocked.clear();\n        size_st.clear();\n\n        h.resize(n);\n\
    \        for (int i = 0; i < n; i++) {\n            if (par[i] == -1) {\n    \
    \            root = i;\n            } else {\n                h[par[i]].push_back(i);\n\
    \            }\n        }\n    }\n\nprivate:\n    const vector<vector<int>> &g;\n\
    \    vector<bool> blocked;\n    vector<int> size_st;\n\n    void get_sizes(int\
    \ u, int u_par) {\n        size_st[u] = 1;\n        for (int v : g[u]) {\n   \
    \         if (v != u_par && !blocked[v]) {\n                get_sizes(v, u);\n\
    \                size_st[u] += size_st[v];\n            }\n        }\n    }\n\
    \    int find_centroid(int u, int u_par, int tree_sz) {\n        int nxt = -1;\n\
    \        for (int v : g[u]) {\n            if (v != u_par && !blocked[v] && size_st[v]\
    \ * 2 > tree_sz) {\n                nxt = v;\n                break;\n       \
    \     }\n        }\n        return nxt == -1 ? u : find_centroid(nxt, u, tree_sz);\n\
    \    }\n    void build(int u, int u_par) {\n        get_sizes(u, -1);\n      \
    \  const int cent = find_centroid(u, -1, size_st[u]);\n        par[cent] = u_par;\n\
    \        blocked[cent] = true;\n        for (int v : g[cent]) {\n            if\
    \ (!blocked[v]) {\n                build(v, cent);\n            }\n        }\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graphs/trees/centroid_decomposition.h
  requiredBy: []
  timestamp: '2024-10-12 02:07:15-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/trees/centroid_decomposition.h
layout: document
redirect_from:
- /library/graphs/trees/centroid_decomposition.h
- /library/graphs/trees/centroid_decomposition.h.html
title: graphs/trees/centroid_decomposition.h
---
