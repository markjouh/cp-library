---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: datastructures/segtree/segtree_set.h
    title: datastructures/segtree/segtree_set.h
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/segtree/segtree.h\"\n\ntemplate <class T,\
    \ T(*op)(T, T), T(*id)()>\nstruct Segtree {\n    int n;\n    vector<T> st;\n\n\
    \    Segtree(int n_) : n(n_), st(2 * n, id()) {}\n\n    Segtree(const vector<T>\
    \ &a) : n(sz(a)), st(2 * n) {\n        copy(begin(a), end(a), begin(st) + n);\n\
    \        for (int i = n - 1; i > 0; i--) {\n            st[i] = op(st[i << 1],\
    \ st[i << 1 | 1]);\n        }\n    }\n\n    T get(int p) {\n        return st[p\
    \ + n];\n    }\n\n    T query(int l, int r) {\n        T ls = id(), rs = id();\n\
    \        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l\
    \ & 1) {\n                ls = op(ls, st[l++]);\n            }\n            if\
    \ (r & 1) {\n                rs = op(st[--r], rs);\n            }\n        }\n\
    \        return op(ls, rs);\n    }\n\n    void set(int p, T val) {\n        for\
    \ (st[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n            st[p] = op(st[p <<\
    \ 1], st[p << 1 | 1]);\n        }\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T, T(*op)(T, T), T(*id)()>\nstruct Segtree\
    \ {\n    int n;\n    vector<T> st;\n\n    Segtree(int n_) : n(n_), st(2 * n, id())\
    \ {}\n\n    Segtree(const vector<T> &a) : n(sz(a)), st(2 * n) {\n        copy(begin(a),\
    \ end(a), begin(st) + n);\n        for (int i = n - 1; i > 0; i--) {\n       \
    \     st[i] = op(st[i << 1], st[i << 1 | 1]);\n        }\n    }\n\n    T get(int\
    \ p) {\n        return st[p + n];\n    }\n\n    T query(int l, int r) {\n    \
    \    T ls = id(), rs = id();\n        for (l += n, r += n + 1; l < r; l >>= 1,\
    \ r >>= 1) {\n            if (l & 1) {\n                ls = op(ls, st[l++]);\n\
    \            }\n            if (r & 1) {\n                rs = op(st[--r], rs);\n\
    \            }\n        }\n        return op(ls, rs);\n    }\n\n    void set(int\
    \ p, T val) {\n        for (st[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n   \
    \         st[p] = op(st[p << 1], st[p << 1 | 1]);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segtree/segtree.h
  requiredBy:
  - datastructures/segtree/segtree_set.h
  timestamp: '2024-09-19 17:47:28-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segtree/segtree.h
layout: document
redirect_from:
- /library/datastructures/segtree/segtree.h
- /library/datastructures/segtree/segtree.h.html
title: datastructures/segtree/segtree.h
---
