---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructures/segment_tree/segtree_set.h
    title: datastructures/segment_tree/segtree_set.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/segment_tree/segtree.h\"\ntemplate <class\
    \ T, auto op, auto id>\nstruct segtree {\n    int n;\n    vector<T> st;\n\n  \
    \  segtree(int n_) : n(n_), st(2 * n, id()) {}\n\n    segtree(const vector<T>\
    \ &a) : n(sz(a)), st(2 * n) {\n        copy(all(a), begin(st) + n);\n        for\
    \ (int i = n - 1; i > 0; i--) {\n            st[i] = op(st[i << 1], st[i << 1\
    \ | 1]);\n        }\n    }\n\n    void set(int p, T val) {\n        for (st[p\
    \ += n] = val, p >>= 1; p > 0; p >>= 1) {\n            st[p] = op(st[p << 1],\
    \ st[p << 1 | 1]);\n        }\n    }\n\n    T get(int p) {\n        return st[p\
    \ + n];\n    }\n\n    T query(int l, int r) {\n        T ls = id(), rs = id();\n\
    \        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l\
    \ & 1) {\n                ls = op(ls, st[l++]);\n            }\n            if\
    \ (r & 1) {\n                rs = op(st[--r], rs);\n            }\n        }\n\
    \        return op(ls, rs);\n    }\n};\n"
  code: "template <class T, auto op, auto id>\nstruct segtree {\n    int n;\n    vector<T>\
    \ st;\n\n    segtree(int n_) : n(n_), st(2 * n, id()) {}\n\n    segtree(const\
    \ vector<T> &a) : n(sz(a)), st(2 * n) {\n        copy(all(a), begin(st) + n);\n\
    \        for (int i = n - 1; i > 0; i--) {\n            st[i] = op(st[i << 1],\
    \ st[i << 1 | 1]);\n        }\n    }\n\n    void set(int p, T val) {\n       \
    \ for (st[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n            st[p] = op(st[p\
    \ << 1], st[p << 1 | 1]);\n        }\n    }\n\n    T get(int p) {\n        return\
    \ st[p + n];\n    }\n\n    T query(int l, int r) {\n        T ls = id(), rs =\
    \ id();\n        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n       \
    \     if (l & 1) {\n                ls = op(ls, st[l++]);\n            }\n   \
    \         if (r & 1) {\n                rs = op(st[--r], rs);\n            }\n\
    \        }\n        return op(ls, rs);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segment_tree/segtree.h
  requiredBy:
  - datastructures/segment_tree/segtree_set.h
  timestamp: '2025-02-28 17:36:32-08:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rmq.test.cpp
documentation_of: datastructures/segment_tree/segtree.h
layout: document
redirect_from:
- /library/datastructures/segment_tree/segtree.h
- /library/datastructures/segment_tree/segtree.h.html
title: datastructures/segment_tree/segtree.h
---
