---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructures/fentree/fenwick_tree.hpp
    title: datastructures/fentree/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/fentree/fenwick_tree_2d.hpp\"\n\n#line 2\
    \ \"datastructures/fentree/fenwick_tree.hpp\"\n\ntemplate <class T>\nstruct FenwickTree\
    \ {\n  int n;\n  vector<T> ft;\n\n  FenwickTree(int n_) : n(n_), ft(n + 1) {}\n\
    \n  FenwickTree(const vector<T> &a) : n(sz(a)), ft(n + 1) {\n    for (int i =\
    \ 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n      if (i + (i & -i) <= n) {\n\
    \        ft[i + (i & -i)] += ft[i];\n      }\n    }\n  }\n\n  void add(int p,\
    \ T v) {\n    for (p++; p <= n; p += p & -p) {\n      ft[p] += v;\n    }\n  }\n\
    \n  T sum(int r) {\n    T res = 0;\n    for (r++; r > 0; r -= r & -r) {\n    \
    \  res += ft[r];\n    }\n    return res;\n  }\n\n  T sum(int l, int r) {\n   \
    \ return sum(r) - sum(l - 1);\n  }\n};\n#line 4 \"datastructures/fentree/fenwick_tree_2d.hpp\"\
    \n\ntemplate <class T>\nstruct FenwickTree2d {\n  int n;\n  vector<FenwickTree<T>>\
    \ ft;\n\n  FenwickTree2d(int n_, int m) : n(n_), ft(n + 1, FenwickTree<T>(m))\
    \ {}\n\n  void add(int r, int c, T v) {\n    for (r++; r <= n; r += r & -r) {\n\
    \      ft[r].add(c, v);\n    }\n  }\n\n  T sum(int r, int c) {\n    if (r < 0\
    \ || c < 0) {\n      return 0;\n    }\n    T res = 0;\n    for (r++; r > 0; r\
    \ -= r & -r) {\n      res += ft[r].sum(c);\n    }\n    return res;\n  }\n\n  T\
    \ sum(int r1, int c1, int r2, int c2) {\n    return sum(r2, c2) - sum(r2, c1 -\
    \ 1) - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1);\n  }\n};\n"
  code: "#pragma once\n\n#include \"fenwick_tree.hpp\"\n\ntemplate <class T>\nstruct\
    \ FenwickTree2d {\n  int n;\n  vector<FenwickTree<T>> ft;\n\n  FenwickTree2d(int\
    \ n_, int m) : n(n_), ft(n + 1, FenwickTree<T>(m)) {}\n\n  void add(int r, int\
    \ c, T v) {\n    for (r++; r <= n; r += r & -r) {\n      ft[r].add(c, v);\n  \
    \  }\n  }\n\n  T sum(int r, int c) {\n    if (r < 0 || c < 0) {\n      return\
    \ 0;\n    }\n    T res = 0;\n    for (r++; r > 0; r -= r & -r) {\n      res +=\
    \ ft[r].sum(c);\n    }\n    return res;\n  }\n\n  T sum(int r1, int c1, int r2,\
    \ int c2) {\n    return sum(r2, c2) - sum(r2, c1 - 1) - sum(r1 - 1, c2) + sum(r1\
    \ - 1, c1 - 1);\n  }\n};"
  dependsOn:
  - datastructures/fentree/fenwick_tree.hpp
  isVerificationFile: false
  path: datastructures/fentree/fenwick_tree_2d.hpp
  requiredBy: []
  timestamp: '2024-09-05 15:13:46-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
documentation_of: datastructures/fentree/fenwick_tree_2d.hpp
layout: document
redirect_from:
- /library/datastructures/fentree/fenwick_tree_2d.hpp
- /library/datastructures/fentree/fenwick_tree_2d.hpp.html
title: datastructures/fentree/fenwick_tree_2d.hpp
---
