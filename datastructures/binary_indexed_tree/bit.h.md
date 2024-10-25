---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructures/binary_indexed_tree/bit_2d.h
    title: datastructures/binary_indexed_tree/bit_2d.h
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_indexed_tree/bit_dual.h
    title: datastructures/binary_indexed_tree/bit_dual.h
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
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/binary_indexed_tree/bit.h\"\n\ntemplate <class\
    \ T>\nstruct BIT {\n    int n;\n    vector<T> ft;\n\n    BIT(int n_) : n(n_),\
    \ ft(n + 1) {}\n\n    BIT(const vector<T> &a) : n(sz(a)), ft(n + 1) {\n      \
    \  for (int i = 1; i <= n; i++) {\n            ft[i] += a[i - 1];\n          \
    \  if (i + (i & -i) <= n) {\n                ft[i + (i & -i)] += ft[i];\n    \
    \        }\n        }\n    }\n\n    void add(int p, T v) {\n        for (p++;\
    \ p <= n; p += p & -p) {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int\
    \ r) {\n        T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n        \
    \    res += ft[r];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l - 1);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct BIT {\n    int n;\n    vector<T>\
    \ ft;\n\n    BIT(int n_) : n(n_), ft(n + 1) {}\n\n    BIT(const vector<T> &a)\
    \ : n(sz(a)), ft(n + 1) {\n        for (int i = 1; i <= n; i++) {\n          \
    \  ft[i] += a[i - 1];\n            if (i + (i & -i) <= n) {\n                ft[i\
    \ + (i & -i)] += ft[i];\n            }\n        }\n    }\n\n    void add(int p,\
    \ T v) {\n        for (p++; p <= n; p += p & -p) {\n            ft[p] += v;\n\
    \        }\n    }\n\n    T sum(int r) {\n        T res = 0;\n        for (r++;\
    \ r > 0; r -= r & -r) {\n            res += ft[r];\n        }\n        return\
    \ res;\n    }\n\n    T sum(int l, int r) {\n        return sum(r) - sum(l - 1);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/binary_indexed_tree/bit.h
  requiredBy:
  - datastructures/binary_indexed_tree/bit_2d.h
  - datastructures/binary_indexed_tree/bit_dual.h
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
documentation_of: datastructures/binary_indexed_tree/bit.h
layout: document
redirect_from:
- /library/datastructures/binary_indexed_tree/bit.h
- /library/datastructures/binary_indexed_tree/bit.h.html
title: datastructures/binary_indexed_tree/bit.h
---
