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
  bundledCode: "#line 2 \"datastructures/static/sparse_table.hpp\"\n\ntemplate <class\
    \ T, T(*op)(T, T)>\nstruct SparseTable {\n  int n, log;\n  vector<vector<T>> table;\n\
    \n  SparseTable(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1) {\n    table.resize(log);\n\
    \    table[0] = a;\n    for (int i = 1; i < log; i++) {\n      table[i].resize(n\
    \ - (1 << i) + 1);\n      for (int j = 0; j < sz(table[i]); j++) {\n        table[i][j]\
    \ = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n \
    \ }\n\n  T query(int l, int r) {\n    assert(l <= r);\n    int i = __lg(++r -\
    \ l);\n    return op(table[i][l], table[i][r - (1 << i)]);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T, T(*op)(T, T)>\nstruct SparseTable {\n\
    \  int n, log;\n  vector<vector<T>> table;\n\n  SparseTable(const vector<T> &a)\
    \ : n(sz(a)), log(__lg(n) + 1) {\n    table.resize(log);\n    table[0] = a;\n\
    \    for (int i = 1; i < log; i++) {\n      table[i].resize(n - (1 << i) + 1);\n\
    \      for (int j = 0; j < sz(table[i]); j++) {\n        table[i][j] = op(table[i\
    \ - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n  }\n\n  T query(int\
    \ l, int r) {\n    assert(l <= r);\n    int i = __lg(++r - l);\n    return op(table[i][l],\
    \ table[i][r - (1 << i)]);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-09-05 17:05:59-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_rmq.test.cpp
documentation_of: datastructures/static/sparse_table.hpp
layout: document
redirect_from:
- /library/datastructures/static/sparse_table.hpp
- /library/datastructures/static/sparse_table.hpp.html
title: datastructures/static/sparse_table.hpp
---
