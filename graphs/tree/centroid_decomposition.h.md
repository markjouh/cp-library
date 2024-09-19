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
  bundledCode: "#line 2 \"graphs/tree/centroid_decomposition.h\"\n\nstruct CentroidDecomp\
    \ {\n    vector<int> par;\n\n    CentroidDecomp(const vector<vector<int>> &g_)\
    \ : g(g_) {\n        par.resize(sz(g));\n        blocked.resize(sz(g));\n    \
    \    st_size.resize(sz(g));\n        for (int i = 0; i < sz(g); i++) {\n     \
    \       if (st_size[i] == 0) {\n                build(i, -1);\n            }\n\
    \        }\n        blocked.clear();\n        st_size.clear();\n    }\n\nprivate:\n\
    \    const vector<vector<int>> &g;\n    vector<bool> blocked;\n    vector<int>\
    \ st_size;\n\n    void get_sizes(int u, int u_par) {\n        st_size[u] = 1;\n\
    \        for (int v : g[u]) {\n            if (v != u_par && !blocked[v]) {\n\
    \                get_sizes(v, u);\n                st_size[u] += st_size[v];\n\
    \            }\n        }\n    }\n\n    int find_centroid(int u, int u_par, int\
    \ tree_sz) {\n        int nxt = -1;\n        for (int v : g[u]) {\n          \
    \  if (v != u_par && !blocked[v] && st_size[v] * 2 > tree_sz) {\n            \
    \    nxt = v;\n                break;\n            }\n        }\n        return\
    \ nxt == -1 ? u : find_centroid(nxt, u, tree_sz);\n    }\n\n    void build(int\
    \ u, int u_par) {\n        get_sizes(u, -1);\n        const int root = find_centroid(u,\
    \ -1, st_size[u]);\n        par[root] = u_par;\n        blocked[root] = true;\n\
    \        for (int v : g[root]) {\n            if (!blocked[v]) {\n           \
    \     build(v, root);\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n\nstruct CentroidDecomp {\n    vector<int> par;\n\n    CentroidDecomp(const\
    \ vector<vector<int>> &g_) : g(g_) {\n        par.resize(sz(g));\n        blocked.resize(sz(g));\n\
    \        st_size.resize(sz(g));\n        for (int i = 0; i < sz(g); i++) {\n \
    \           if (st_size[i] == 0) {\n                build(i, -1);\n          \
    \  }\n        }\n        blocked.clear();\n        st_size.clear();\n    }\n\n\
    private:\n    const vector<vector<int>> &g;\n    vector<bool> blocked;\n    vector<int>\
    \ st_size;\n\n    void get_sizes(int u, int u_par) {\n        st_size[u] = 1;\n\
    \        for (int v : g[u]) {\n            if (v != u_par && !blocked[v]) {\n\
    \                get_sizes(v, u);\n                st_size[u] += st_size[v];\n\
    \            }\n        }\n    }\n\n    int find_centroid(int u, int u_par, int\
    \ tree_sz) {\n        int nxt = -1;\n        for (int v : g[u]) {\n          \
    \  if (v != u_par && !blocked[v] && st_size[v] * 2 > tree_sz) {\n            \
    \    nxt = v;\n                break;\n            }\n        }\n        return\
    \ nxt == -1 ? u : find_centroid(nxt, u, tree_sz);\n    }\n\n    void build(int\
    \ u, int u_par) {\n        get_sizes(u, -1);\n        const int root = find_centroid(u,\
    \ -1, st_size[u]);\n        par[root] = u_par;\n        blocked[root] = true;\n\
    \        for (int v : g[root]) {\n            if (!blocked[v]) {\n           \
    \     build(v, root);\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/tree/centroid_decomposition.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/tree/centroid_decomposition.h
layout: document
redirect_from:
- /library/graphs/tree/centroid_decomposition.h
- /library/graphs/tree/centroid_decomposition.h.html
title: graphs/tree/centroid_decomposition.h
---
