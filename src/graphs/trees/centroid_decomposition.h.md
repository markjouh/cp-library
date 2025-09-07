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
  bundledCode: "#line 1 \"src/graphs/trees/centroid_decomposition.h\"\nstruct CentroidDecomp\
    \ {\n  int root;\n  vector<int> par;\n  vector<vector<int>> tree;\n \n  CentroidDecomp(const\
    \ vector<vector<int>> &g_) : g(g_) {\n    const int n = g.size();\n    par.resize(n);\n\
    \    blocked.resize(n);\n    st_size.resize(n);\n    for (int i = 0; i < n; i++)\
    \ {\n      if (st_size[i] == 0) {\n        build(i, -1);\n      }\n    }\n   \
    \ blocked.clear();\n    st_size.clear();\n \n    tree.resize(n);\n    for (int\
    \ i = 0; i < n; i++) {\n      if (par[i] == -1) {\n        root = i;\n      }\
    \ else {\n        tree[par[i]].push_back(i);\n      }\n    }\n  }\n \nprivate:\n\
    \  const vector<vector<int>> &g;\n  vector<bool> blocked;\n  vector<int> st_size;\n\
    \ \n  void get_sizes(int u, int u_par) {\n    st_size[u] = 1;\n    for (int v\
    \ : g[u]) {\n      if (v != u_par && !blocked[v]) {\n        get_sizes(v, u);\n\
    \        st_size[u] += st_size[v];\n      }\n    }\n  }\n \n  int get_centroid(int\
    \ u, int u_par, int tree_sz) {\n    int nxt = -1;\n    for (int v : g[u]) {\n\
    \      if (v != u_par && !blocked[v] && st_size[v] * 2 > tree_sz) {\n        nxt\
    \ = v;\n        break;\n      }\n    }\n    return nxt == -1 ? u : get_centroid(nxt,\
    \ u, tree_sz);\n  }\n  \n  void build(int u, int u_par) {\n    get_sizes(u, -1);\n\
    \    const int cent = get_centroid(u, -1, st_size[u]);\n    par[cent] = u_par;\n\
    \    blocked[cent] = true;\n    for (int v : g[cent]) {\n      if (!blocked[v])\
    \ {\n        build(v, cent);\n      }\n    }\n  }\n};\n"
  code: "struct CentroidDecomp {\n  int root;\n  vector<int> par;\n  vector<vector<int>>\
    \ tree;\n \n  CentroidDecomp(const vector<vector<int>> &g_) : g(g_) {\n    const\
    \ int n = g.size();\n    par.resize(n);\n    blocked.resize(n);\n    st_size.resize(n);\n\
    \    for (int i = 0; i < n; i++) {\n      if (st_size[i] == 0) {\n        build(i,\
    \ -1);\n      }\n    }\n    blocked.clear();\n    st_size.clear();\n \n    tree.resize(n);\n\
    \    for (int i = 0; i < n; i++) {\n      if (par[i] == -1) {\n        root =\
    \ i;\n      } else {\n        tree[par[i]].push_back(i);\n      }\n    }\n  }\n\
    \ \nprivate:\n  const vector<vector<int>> &g;\n  vector<bool> blocked;\n  vector<int>\
    \ st_size;\n \n  void get_sizes(int u, int u_par) {\n    st_size[u] = 1;\n   \
    \ for (int v : g[u]) {\n      if (v != u_par && !blocked[v]) {\n        get_sizes(v,\
    \ u);\n        st_size[u] += st_size[v];\n      }\n    }\n  }\n \n  int get_centroid(int\
    \ u, int u_par, int tree_sz) {\n    int nxt = -1;\n    for (int v : g[u]) {\n\
    \      if (v != u_par && !blocked[v] && st_size[v] * 2 > tree_sz) {\n        nxt\
    \ = v;\n        break;\n      }\n    }\n    return nxt == -1 ? u : get_centroid(nxt,\
    \ u, tree_sz);\n  }\n  \n  void build(int u, int u_par) {\n    get_sizes(u, -1);\n\
    \    const int cent = get_centroid(u, -1, st_size[u]);\n    par[cent] = u_par;\n\
    \    blocked[cent] = true;\n    for (int v : g[cent]) {\n      if (!blocked[v])\
    \ {\n        build(v, cent);\n      }\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/trees/centroid_decomposition.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/trees/centroid_decomposition.h
layout: document
title: Centroid Decomposition
---

Decomposes tree into centroid hierarchy for efficient path queries and updates.

## Operations

- `CentroidDecomposition(g)`: Build centroid decomposition of tree `g`
- Access decomposition tree structure through public members

## Complexity

- Construction: $O(n \log n)$
- Space: $O(n)$

## Usage

{% raw %}
```cpp
vector<vector<int>> tree = {{1, 2}, {0, 3}, {0}, {1}};
CentroidDecomposition cd(tree);

// Use centroid tree for path queries
// Implementation depends on specific problem requirements
```
{% endraw %}

## Notes

Creates auxiliary tree where each node's centroid subtrees have size at most n/2. Useful for path queries in trees.
