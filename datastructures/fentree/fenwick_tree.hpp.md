---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructures/fentree/fenwick_tree_dual.hpp
    title: datastructures/fentree/fenwick_tree_dual.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/fentree/fenwick_tree.hpp\"\n\ntemplate <class\
    \ T>\nstruct FenwickTree {\n  int n;\n  vector<T> ft;\n\n  FenwickTree(int x)\
    \ : n(x), ft(n + 1) {}\n\n  FenwickTree(const vector<T> &a) : n(sz(a)), ft(n +\
    \ 1) {\n    for (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n      if\
    \ (i + (i & -i) <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n\
    \  }\n\n  void add(int p, T v) {\n    // assert(p >= 0);\n    for (p++; p <= n;\
    \ p += p & -p) {\n      ft[p] += v;\n    }\n  }\n\n  T sum(int r) {\n    // assert(r\
    \ < n);\n    T res = 0;\n    for (r++; r > 0; r -= r & -r) {\n      res += ft[r];\n\
    \    }\n    return res;\n  }\n\n  T sum(int l, int r) {\n    return sum(r) - sum(l\
    \ - 1);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct FenwickTree {\n  int n;\n  vector<T>\
    \ ft;\n\n  FenwickTree(int x) : n(x), ft(n + 1) {}\n\n  FenwickTree(const vector<T>\
    \ &a) : n(sz(a)), ft(n + 1) {\n    for (int i = 1; i <= n; i++) {\n      ft[i]\
    \ += a[i - 1];\n      if (i + (i & -i) <= n) {\n        ft[i + (i & -i)] += ft[i];\n\
    \      }\n    }\n  }\n\n  void add(int p, T v) {\n    // assert(p >= 0);\n   \
    \ for (p++; p <= n; p += p & -p) {\n      ft[p] += v;\n    }\n  }\n\n  T sum(int\
    \ r) {\n    // assert(r < n);\n    T res = 0;\n    for (r++; r > 0; r -= r & -r)\
    \ {\n      res += ft[r];\n    }\n    return res;\n  }\n\n  T sum(int l, int r)\
    \ {\n    return sum(r) - sum(l - 1);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/fentree/fenwick_tree.hpp
  requiredBy:
  - datastructures/fentree/fenwick_tree_dual.hpp
  timestamp: '2024-08-31 22:47:38-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
documentation_of: datastructures/fentree/fenwick_tree.hpp
layout: document
redirect_from:
- /library/datastructures/fentree/fenwick_tree.hpp
- /library/datastructures/fentree/fenwick_tree.hpp.html
title: datastructures/fentree/fenwick_tree.hpp
---
