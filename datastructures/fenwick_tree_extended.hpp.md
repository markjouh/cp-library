---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree.hpp
    title: Fenwick Tree
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
  bundledCode: "#line 2 \"datastructures/fenwick_tree_extended.hpp\"\n\n#line 2 \"\
    datastructures/fenwick_tree.hpp\"\n\ntemplate <class T>\nstruct FenwickTree {\n\
    \  int n;\n  vector<T> ft;\n\n  FenwickTree(int x) : n(x), ft(n + 1) {}\n\n  FenwickTree(const\
    \ vector<T> &a) : n(sz(a)), ft(n + 1) {\n    for (int i = 1; i <= n; i++) {\n\
    \      ft[i] += a[i - 1];\n      if (i + (i & -i) <= n) {\n        ft[i + (i &\
    \ -i)] += ft[i];\n      }\n    }\n  }\n\n  void add(int p, T v) {\n    // assert(p\
    \ >= 0);\n    for (p++; p <= n; p += p & -p) {\n      ft[p] += v;\n    }\n  }\n\
    \n  T sum(int r) {\n    // assert(r < n);\n    T res = 0;\n    for (r++; r > 0;\
    \ r -= r & -r) {\n      res += ft[r];\n    }\n    return res;\n  }\n\n  T sum(int\
    \ l, int r) {\n    return sum(r) - sum(l - 1);\n  }\n};\n#line 4 \"datastructures/fenwick_tree_extended.hpp\"\
    \n\ntemplate <class T>\nstruct DualFenwickTree {\n  int n;\n  FenwickTree<T> in_pref,\
    \ os_pref;\n\n  DualFenwickTree(int x) : n(x), in_pref(n), os_pref(n) {}\n\n \
    \ T sum(int r) {\n    return in_pref.sum(r - 1) + os_pref.sum(n - r - 1) * (r\
    \ + 1);\n  }\n\n  T sum(int l, int r) {\n    return sum(r) - (l > 0 ? sum(l -\
    \ 1) : 0);\n  }\n\n  void add(int r, T v) {\n    in_pref.add(r, v * (r + 1));\n\
    \    os_pref.add(n - r - 1, v);\n  }\n\n  void add(int l, int r, T v) {\n    add(r,\
    \ v);\n    if (l > 0) {\n      add(l - 1, T(0) - T(v));\n    }\n  }\n};\n"
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
  path: datastructures/fenwick_tree_extended.hpp
  requiredBy: []
  timestamp: '2024-08-30 00:07:29-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
documentation_of: datastructures/fenwick_tree_extended.hpp
layout: document
title: Range Add Range Sum Fenwick Tree
---

### Overview

A data structure that uses two point update fenwick trees to achieve both range adds and range sums in $O(\log(n))$.

For a reversible operation like addition, supporting prefix operations naturally extends to range operations, so let's focus on that for now. When we query a prefix $r$, completed prefix updates at some $p \leq r$ have contribution capped by their position, while for updates with $p \gt r$, it's capped by our position. We can reflect both of these possible "pulls" using two fenwick trees `inside` and `outside`, with `inside` storing a capped, fixed contribution, and `outside` storing a coefficient to apply to future query positions.

### Usage

* `DualFenwickTree<T>(x)`: Builds a fenwick tree of length x, or from the vector x. The complexity is $O(n)$ in both cases.
* `add(l, r, x)`: Adds x to the interval $[l, r]$.
* `sum(l, r)`: Returns the sum of the interval $[l, r]$.