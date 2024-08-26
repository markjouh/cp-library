---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree_extended.hpp
    title: datastructures/fenwick_tree_extended.hpp
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
    _deprecated_at_docs: docs/datastructures/fenwick_tree.md
    document_title: Fenwick Tree (Binary Indexed Tree)
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
    \ int r) {\n        return sum(r) - sum(l - 1);\n    }\n};\n\n/**\n * @brief Fenwick\
    \ Tree (Binary Indexed Tree)\n * @docs docs/datastructures/fenwick_tree.md\n */\n"
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
    \    }\n};\n\n/**\n * @brief Fenwick Tree (Binary Indexed Tree)\n * @docs docs/datastructures/fenwick_tree.md\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/fenwick_tree.hpp
  requiredBy:
  - datastructures/fenwick_tree_extended.hpp
  timestamp: '2024-08-26 17:42:39-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
documentation_of: datastructures/fenwick_tree.hpp
layout: document
redirect_from:
- /library/datastructures/fenwick_tree.hpp
- /library/datastructures/fenwick_tree.hpp.html
title: Fenwick Tree (Binary Indexed Tree)
---
A fenwick tree is a data structure that's generally used for $O(log(N))$ point updates and range sum queries.