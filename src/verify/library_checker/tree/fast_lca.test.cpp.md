---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/static/sparse_table.h
    title: Sparse Table
  - icon: ':heavy_check_mark:'
    path: src/graphs/trees/fast_lca.h
    title: Fast LCA (Lowest Common Ancestor)
  - icon: ':heavy_check_mark:'
    path: src/template/template.h
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"src/verify/library_checker/tree/fast_lca.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"src/template/template.h\"\
    \n/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define all(x) begin(x), end(x)\n#line 1 \"src/datastructures/static/sparse_table.h\"\
    \ntemplate <class T, auto op>\nstruct SparseTable {\n  int n, log;\n  vector<vector<T>>\
    \ st;\n\n  SparseTable() {}\n  SparseTable(const vector<T> &a) : n(ssize(a)),\
    \ log(__lg(n) + 1) {\n    st.resize(log);\n    st[0] = a;\n    for (int i = 1;\
    \ i < log; i++) {\n      st[i].resize(n - (1 << i) + 1);\n      for (int j = 0;\
    \ j < ssize(st[i]); j++) {\n        st[i][j] = op(st[i - 1][j], st[i - 1][j +\
    \ (1 << (i - 1))]);\n      }\n    }\n  }\n\n  T query(int l, int r) {\n    assert(l\
    \ <= r);\n    int i = __lg(++r - l);\n    return op(st[i][l], st[i][r - (1 <<\
    \ i)]);\n  }\n};\n\ntemplate <class T>\nT min_op(T x, T y) {\n  return x < y ?\
    \ x : y;\n}\ntemplate <class T>\nT max_op(T x, T y) {\n  return x > y ? x : y;\n\
    }\n#line 2 \"src/graphs/trees/fast_lca.h\"\n\nstruct FastLCA {\n  vector<int>\
    \ tin, dep;\n  SparseTable<pair<int, int>, min_op<pair<int, int>>> rmq;\n\n  FastLCA()\
    \ {}\n  FastLCA(const vector<vector<int>> &g) {\n    tin.resize(ssize(g));\n \
    \   dep.resize(ssize(g));\n    vector<pair<int, int>> d;\n\n    auto dfs = [&](auto\
    \ &&self, int u, int par) -> void {\n      tin[u] = ssize(d);\n      d.emplace_back(dep[u],\
    \ u);\n      for (int v : g[u]) {\n        if (v != par) {\n          dep[v] =\
    \ dep[u] + 1;\n          self(self, v, u);\n          d.emplace_back(dep[u], u);\n\
    \        }\n      }\n    };\n\n    dfs(dfs, 0, -1);\n    rmq = SparseTable<pair<int,\
    \ int>, min_op<pair<int, int>>>(d);\n  }\n\n  int lca(int u, int v) {\n    if\
    \ (tin[u] > tin[v]) {\n      swap(u, v);\n    }\n    return rmq.query(tin[u],\
    \ tin[v]).second;\n  }\n\n  int dist(int u, int v) {\n    if (tin[u] > tin[v])\
    \ {\n      swap(u, v);\n    }\n    return dep[u] + dep[v] - 2 * rmq.query(tin[u],\
    \ tin[v]).first;\n  }\n};\n#line 5 \"src/verify/library_checker/tree/fast_lca.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<vector<int>> g(n);\n\
    \  for (int i = 1; i < n; i++) {\n    int p;\n    cin >> p;\n    g[p].push_back(i);\n\
    \  }\n  FastLCA ds(g);\n  while (q--) {\n    int u, v;\n    cin >> u >> v;\n \
    \   cout << ds.lca(u, v) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../../template/template.h\"\
    \n#include \"../../../graphs/trees/fast_lca.h\"\n\nint main() {\n  int n, q;\n\
    \  cin >> n >> q;\n  vector<vector<int>> g(n);\n  for (int i = 1; i < n; i++)\
    \ {\n    int p;\n    cin >> p;\n    g[p].push_back(i);\n  }\n  FastLCA ds(g);\n\
    \  while (q--) {\n    int u, v;\n    cin >> u >> v;\n    cout << ds.lca(u, v)\
    \ << '\\n';\n  }\n}"
  dependsOn:
  - src/template/template.h
  - src/graphs/trees/fast_lca.h
  - src/datastructures/static/sparse_table.h
  isVerificationFile: true
  path: src/verify/library_checker/tree/fast_lca.test.cpp
  requiredBy: []
  timestamp: '2026-01-15 15:27:11+00:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/tree/fast_lca.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/tree/fast_lca.test.cpp
- /verify/src/verify/library_checker/tree/fast_lca.test.cpp.html
title: src/verify/library_checker/tree/fast_lca.test.cpp
---
