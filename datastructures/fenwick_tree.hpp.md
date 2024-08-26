---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree_extended.hpp
    title: Range Add Range Query Fenwick Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/fenwick_tree.hpp\"\n\ntemplate<class T> struct\
    \ fenwick_tree {\n    int n;\n    vector<T> tree;\n\n    fenwick_tree(int x) :\
    \ n(x), tree(n + 1) {}\n\n    fenwick_tree(const vector<T> &a) : n(sz(a)), tree(n\
    \ + 1) {\n        for (int i = 1; i <= n; i++) {\n            tree[i] += a[i -\
    \ 1];\n            if (i + (i & -i) <= n) {\n                tree[i + (i & -i)]\
    \ += tree[i];\n            }\n        }\n    }\n\n    void add(int p, T v) {\n\
    \        assert(p >= 0);\n        for (p++; p <= n; p += p & -p) {\n         \
    \   tree[p] += v;\n        }\n    }\n\n    T sum(int r) {\n        assert(r <\
    \ n);\n        T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n         \
    \   res += tree[r];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l - 1);\n    }\n};\n"
  code: "#pragma once\n\ntemplate<class T> struct fenwick_tree {\n    int n;\n   \
    \ vector<T> tree;\n\n    fenwick_tree(int x) : n(x), tree(n + 1) {}\n\n    fenwick_tree(const\
    \ vector<T> &a) : n(sz(a)), tree(n + 1) {\n        for (int i = 1; i <= n; i++)\
    \ {\n            tree[i] += a[i - 1];\n            if (i + (i & -i) <= n) {\n\
    \                tree[i + (i & -i)] += tree[i];\n            }\n        }\n  \
    \  }\n\n    void add(int p, T v) {\n        assert(p >= 0);\n        for (p++;\
    \ p <= n; p += p & -p) {\n            tree[p] += v;\n        }\n    }\n\n    T\
    \ sum(int r) {\n        assert(r < n);\n        T res = 0;\n        for (r++;\
    \ r > 0; r -= r & -r) {\n            res += tree[r];\n        }\n        return\
    \ res;\n    }\n\n    T sum(int l, int r) {\n        return sum(r) - sum(l - 1);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/fenwick_tree.hpp
  requiredBy:
  - datastructures/fenwick_tree_extended.hpp
  timestamp: '2024-08-26 18:36:05-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
documentation_of: datastructures/fenwick_tree.hpp
layout: document
title: Fenwick Tree
---

### Overview

The fenwick tree is a data structure that stores an array and supports $O(\log{n})$ point updates and range queries. It's generally used for adds/sums.

### Operations

* `fenwick_tree<T>(x)`: Builds a fenwick tree of length x, or from the vector x. The complexity is $O(n)$ in both cases.
* `add(k, x)`: Adds x to index k. $O(\log{n})$
* `sum(l, r)`: Returns the sum of the interval $[l, r]$. $O(\log{n})$.

### More Details

The reason fenwick trees are seldom used outside of sum queries is because their functionality is just a small subset of that of segment trees, with their only advantage being a noticable but rarely crucial edge in terms of constant factor. It's not possible to compute range queries if the operation being applied doesn't have an inverse, and AFAIK the same goes for any sort of updates (even if it can be done, it'd probably come at the cost of the simplicity that make FTs desirable in the first place).

We can modify the datastructure to support range updates and point queries instead by swapping the contents of the inner loops of the update and query functions, but it's not covered in this library out of simplicity, and because we can get both range updates and range queries using two point update fenwick trees in tandem anyway.