---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/sparse_table.hpp\"\n\ntemplate <class T,\
    \ T(*op)(T, T)>\nstruct SparseTable {\n  int n, lg;\n  vector<vector<T>> table;\n\
    \n  SparseTable(const vector<T> &a) : n(sz(a)), lg(__lg(n) + 1) {\n    table.resize(lg);\n\
    \    table[0] = a;\n    for (int i = 1; i < lg; i++) {\n      table[i].resize(n\
    \ - (1 << i) + 1);\n      for (int j = 0; j < sz(table[i]); j++) {\n        table[i][j]\
    \ = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n \
    \ }\n\n  T query(int l, int r) {\n    assert(l <= r);\n    int i = __lg(++r -\
    \ l);\n    return op(table[i][l], table[i][r - (1 << i)]);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T, T(*op)(T, T)>\nstruct SparseTable {\n\
    \  int n, lg;\n  vector<vector<T>> table;\n\n  SparseTable(const vector<T> &a)\
    \ : n(sz(a)), lg(__lg(n) + 1) {\n    table.resize(lg);\n    table[0] = a;\n  \
    \  for (int i = 1; i < lg; i++) {\n      table[i].resize(n - (1 << i) + 1);\n\
    \      for (int j = 0; j < sz(table[i]); j++) {\n        table[i][j] = op(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n\n  T query(int\
    \ l, int r) {\n    assert(l <= r);\n    int i = __lg(++r - l);\n    return op(table[i][l],\
    \ table[i][r - (1 << i)]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-08-28 03:11:34-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_rmq.test.cpp
documentation_of: datastructures/sparse_table.hpp
layout: document
title: Sparse Table
---

### Overview

The sparse table is a data structure that's useful for answering static range queries in constant time given an idempotent merge operation (that is, applying it more than once won't change the result). Generally used for RMQ.

Sparse tables precompute the result for all subarrays with lengths of powers of 2 using range dp. This guaranteees there will always exist a pair of (not neccessarily distinct) intervals in our table which have a union equal to any valid query interval, allowing us to compute the answer in $O(1)$.

### Usage

* `sparse_table<T>(a)`: Builds a sparse table from the vector `a`. $O(n \log{n})$ time and memory.
* `query(l, r)`: Returns the range aggregate over the interval $[l, r]$. $O(1)$