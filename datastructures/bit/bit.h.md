---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructures/bit/bit_2d.h
    title: datastructures/bit/bit_2d.h
  - icon: ':heavy_check_mark:'
    path: datastructures/bit/bit_dual.h
    title: datastructures/bit/bit_dual.h
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
  bundledCode: "#line 2 \"datastructures/bit/bit.h\"\n\ntemplate <class T>\nstruct\
    \ BIT {\n    int n;\n    vector<T> ft;\n\n    BIT(int n_) : n(n_), ft(n + 1) {}\n\
    \n    BIT(const vector<T> &a) : n(sz(a)), ft(n + 1) {\n        for (int i = 1;\
    \ i <= n; i++) {\n            ft[i] += a[i - 1];\n            if (i + (i & -i)\
    \ <= n) {\n                ft[i + (i & -i)] += ft[i];\n            }\n       \
    \ }\n    }\n\n    void add(int p, T v) {\n        for (p++; p <= n; p += p & -p)\
    \ {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int r) {\n       \
    \ T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n            res += ft[r];\n\
    \        }\n        return res;\n    }\n\n    T sum(int l, int r) {\n        return\
    \ sum(r) - sum(l - 1);\n    }\n};\n"
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
  path: datastructures/bit/bit.h
  requiredBy:
  - datastructures/bit/bit_dual.h
  - datastructures/bit/bit_2d.h
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
documentation_of: datastructures/bit/bit.h
layout: document
redirect_from:
- /library/datastructures/bit/bit.h
- /library/datastructures/bit/bit.h.html
title: datastructures/bit/bit.h
---
