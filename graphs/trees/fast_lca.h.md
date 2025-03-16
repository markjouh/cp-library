---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/static/sparse_table.h
    title: datastructures/static/sparse_table.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/fast_lca.test.cpp
    title: verify/library_checker/tree/fast_lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/static/sparse_table.h\"\ntemplate <class\
    \ T, auto op>\nstruct SparseTable {\n  int n, log;\n  vector<vector<T>> st;\n\n\
    \  SparseTable() {}\n  SparseTable(const vector<T> &a) : n(sz(a)), log(__lg(n)\
    \ + 1) {\n    st.resize(log);\n    st[0] = a;\n    for (int i = 1; i < log; i++)\
    \ {\n      st[i].resize(n - (1 << i) + 1);\n      for (int j = 0; j < sz(st[i]);\
    \ j++) {\n        st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n\
    \      }\n    }\n  }\n\n  T query(int l, int r) {\n    assert(l <= r);\n    int\
    \ i = __lg(++r - l);\n    return op(st[i][l], st[i][r - (1 << i)]);\n  }\n};\n\
    \ntemplate <class T>\nT min_op(T x, T y) {\n  return x < y ? x : y;\n}\ntemplate\
    \ <class T>\nT max_op(T x, T y) {\n  return x > y ? x : y;\n}\n#line 2 \"graphs/trees/fast_lca.h\"\
    \n\nstruct FastLCA {\n  vector<int> tin, dep;\n  SparseTable<pair<int, int>, min_op<pair<int,\
    \ int>>> rmq;\n\n  FastLCA() {}\n  FastLCA(const vector<vector<int>> &g) {\n \
    \   tin.resize(sz(g));\n    dep.resize(sz(g));\n    vector<pair<int, int>> d;\n\
    \n    auto dfs = [&](auto &&self, int u, int par) -> void {\n      tin[u] = sz(d);\n\
    \      d.emplace_back(dep[u], u);\n      for (int v : g[u]) {\n        if (v !=\
    \ par) {\n          dep[v] = dep[u] + 1;\n          self(self, v, u);\n      \
    \    d.emplace_back(dep[u], u);\n        }\n      }\n    };\n\n    dfs(dfs, 0,\
    \ -1);\n    rmq = SparseTable<pair<int, int>, min_op<pair<int, int>>>(d);\n  }\n\
    \n  int lca(int u, int v) {\n    if (tin[u] > tin[v]) {\n      swap(u, v);\n \
    \   }\n    return rmq.query(tin[u], tin[v]).second;\n  }\n\n  int dist(int u,\
    \ int v) {\n    if (tin[u] > tin[v]) {\n      swap(u, v);\n    }\n    return dep[u]\
    \ + dep[v] - 2 * rmq.query(tin[u], tin[v]).first;\n  }\n};\n"
  code: "#include \"../../datastructures/static/sparse_table.h\"\n\nstruct FastLCA\
    \ {\n  vector<int> tin, dep;\n  SparseTable<pair<int, int>, min_op<pair<int, int>>>\
    \ rmq;\n\n  FastLCA() {}\n  FastLCA(const vector<vector<int>> &g) {\n    tin.resize(sz(g));\n\
    \    dep.resize(sz(g));\n    vector<pair<int, int>> d;\n\n    auto dfs = [&](auto\
    \ &&self, int u, int par) -> void {\n      tin[u] = sz(d);\n      d.emplace_back(dep[u],\
    \ u);\n      for (int v : g[u]) {\n        if (v != par) {\n          dep[v] =\
    \ dep[u] + 1;\n          self(self, v, u);\n          d.emplace_back(dep[u], u);\n\
    \        }\n      }\n    };\n\n    dfs(dfs, 0, -1);\n    rmq = SparseTable<pair<int,\
    \ int>, min_op<pair<int, int>>>(d);\n  }\n\n  int lca(int u, int v) {\n    if\
    \ (tin[u] > tin[v]) {\n      swap(u, v);\n    }\n    return rmq.query(tin[u],\
    \ tin[v]).second;\n  }\n\n  int dist(int u, int v) {\n    if (tin[u] > tin[v])\
    \ {\n      swap(u, v);\n    }\n    return dep[u] + dep[v] - 2 * rmq.query(tin[u],\
    \ tin[v]).first;\n  }\n};"
  dependsOn:
  - datastructures/static/sparse_table.h
  isVerificationFile: false
  path: graphs/trees/fast_lca.h
  requiredBy: []
  timestamp: '2025-03-16 14:57:47-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/fast_lca.test.cpp
documentation_of: graphs/trees/fast_lca.h
layout: document
redirect_from:
- /library/graphs/trees/fast_lca.h
- /library/graphs/trees/fast_lca.h.html
title: graphs/trees/fast_lca.h
---
