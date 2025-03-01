---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree/dual_fentree.h
    title: datastructures/fenwick_tree/dual_fentree.h
  - icon: ':warning:'
    path: datastructures/fenwick_tree/fentree_2d.h
    title: datastructures/fenwick_tree/fentree_2d.h
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
  bundledCode: "#line 1 \"datastructures/fenwick_tree/fentree.h\"\ntemplate <class\
    \ T>\nstruct fentree {\n    int n;\n    vector<T> ft;\n\n    fentree(int n_) :\
    \ n(n_), ft(n + 1) {}\n\n    fentree(const vector<T> &a) : n(sz(a)), ft(n + 1)\
    \ {\n        for (int i = 1; i <= n; i++) {\n            ft[i] += a[i - 1];\n\
    \            if (i + (i & -i) <= n) {\n                ft[i + (i & -i)] += ft[i];\n\
    \            }\n        }\n    }\n\n    void add(int p, T v) {\n        for (p++;\
    \ p <= n; p += p & -p) {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int\
    \ r) {\n        T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n        \
    \    res += ft[r];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l - 1);\n    }\n};\n"
  code: "template <class T>\nstruct fentree {\n    int n;\n    vector<T> ft;\n\n \
    \   fentree(int n_) : n(n_), ft(n + 1) {}\n\n    fentree(const vector<T> &a) :\
    \ n(sz(a)), ft(n + 1) {\n        for (int i = 1; i <= n; i++) {\n            ft[i]\
    \ += a[i - 1];\n            if (i + (i & -i) <= n) {\n                ft[i + (i\
    \ & -i)] += ft[i];\n            }\n        }\n    }\n\n    void add(int p, T v)\
    \ {\n        for (p++; p <= n; p += p & -p) {\n            ft[p] += v;\n     \
    \   }\n    }\n\n    T sum(int r) {\n        T res = 0;\n        for (r++; r >\
    \ 0; r -= r & -r) {\n            res += ft[r];\n        }\n        return res;\n\
    \    }\n\n    T sum(int l, int r) {\n        return sum(r) - sum(l - 1);\n   \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/fenwick_tree/fentree.h
  requiredBy:
  - datastructures/fenwick_tree/dual_fentree.h
  - datastructures/fenwick_tree/fentree_2d.h
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
documentation_of: datastructures/fenwick_tree/fentree.h
layout: document
redirect_from:
- /library/datastructures/fenwick_tree/fentree.h
- /library/datastructures/fenwick_tree/fentree.h.html
title: datastructures/fenwick_tree/fentree.h
---
