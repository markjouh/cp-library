---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree.hpp
    title: datastructures/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/dual_fenwick_tree.hpp\"\n\n#line 2 \"datastructures/fenwick_tree.hpp\"\
    \n\ntemplate <class T>\nstruct FenwickTree {\n  int n;\n  vector<T> ft;\n\n  FenwickTree(int\
    \ x) : n(x), ft(n + 1) {}\n\n  FenwickTree(const vector<T> &a) : n(sz(a)), ft(n\
    \ + 1) {\n    for (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n     \
    \ if (i + (i & -i) <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n\
    \  }\n\n  void add(int p, T v) {\n    // assert(p >= 0);\n    for (p++; p <= n;\
    \ p += p & -p) {\n      ft[p] += v;\n    }\n  }\n\n  T sum(int r) {\n    // assert(r\
    \ < n);\n    T res = 0;\n    for (r++; r > 0; r -= r & -r) {\n      res += ft[r];\n\
    \    }\n    return res;\n  }\n\n  T sum(int l, int r) {\n    return sum(r) - sum(l\
    \ - 1);\n  }\n};\n#line 4 \"datastructures/dual_fenwick_tree.hpp\"\n\ntemplate\
    \ <class T>\nstruct DualFenwickTree {\n  int n;\n  FenwickTree<T> in_pref, os_pref;\n\
    \n  DualFenwickTree(int x) : n(x), in_pref(n), os_pref(n) {}\n\n  T sum(int r)\
    \ {\n    return in_pref.sum(r - 1) + os_pref.sum(n - r - 1) * (r + 1);\n  }\n\n\
    \  T sum(int l, int r) {\n    return sum(r) - (l > 0 ? sum(l - 1) : 0);\n  }\n\
    \n  void add(int r, T v) {\n    in_pref.add(r, v * (r + 1));\n    os_pref.add(n\
    \ - r - 1, v);\n  }\n\n  void add(int l, int r, T v) {\n    add(r, v);\n    if\
    \ (l > 0) {\n      add(l - 1, T(0) - T(v));\n    }\n  }\n};\n"
  code: "#pragma once\n\n#include \"fenwick_tree.hpp\"\n\ntemplate <class T>\nstruct\
    \ DualFenwickTree {\n  int n;\n  FenwickTree<T> in_pref, os_pref;\n\n  DualFenwickTree(int\
    \ x) : n(x), in_pref(n), os_pref(n) {}\n\n  T sum(int r) {\n    return in_pref.sum(r\
    \ - 1) + os_pref.sum(n - r - 1) * (r + 1);\n  }\n\n  T sum(int l, int r) {\n \
    \   return sum(r) - (l > 0 ? sum(l - 1) : 0);\n  }\n\n  void add(int r, T v) {\n\
    \    in_pref.add(r, v * (r + 1));\n    os_pref.add(n - r - 1, v);\n  }\n\n  void\
    \ add(int l, int r, T v) {\n    add(r, v);\n    if (l > 0) {\n      add(l - 1,\
    \ T(0) - T(v));\n    }\n  }\n};"
  dependsOn:
  - datastructures/fenwick_tree.hpp
  isVerificationFile: false
  path: datastructures/dual_fenwick_tree.hpp
  requiredBy: []
  timestamp: '2024-08-31 21:03:37-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
documentation_of: datastructures/dual_fenwick_tree.hpp
layout: document
redirect_from:
- /library/datastructures/dual_fenwick_tree.hpp
- /library/datastructures/dual_fenwick_tree.hpp.html
title: datastructures/dual_fenwick_tree.hpp
---
