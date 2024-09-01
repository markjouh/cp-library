---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/segtreecore/segment_tree.hpp\"\n\ntemplate\
    \ <class T, T(*op)(T, T), T(*id)()>\nstruct SegmentTree {\n  int n;\n  vector<T>\
    \ st;\n\n  SegmentTree(int sz) : n(sz), st(2 * n, id()) {}\n\n  SegmentTree(const\
    \ vector<T> &a) : n(sz(a)), st(2 * n) {\n    copy(begin(a), end(a), begin(st)\
    \ + n);\n    for (int i = n - 1; i > 0; i--) {\n      st[i] = op(st[i << 1], st[i\
    \ << 1 | 1]);\n    }\n  }\n\n  T query(int l, int r) {\n    T ls = id(), rs =\
    \ id();\n    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n      if (l\
    \ & 1) {\n        ls = op(ls, st[l++]);\n      }\n      if (r & 1) {\n       \
    \ rs = op(st[--r], rs);\n      }\n    }\n    return op(ls, rs);\n  }\n\n  void\
    \ set(int p, T val) {\n    for (st[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n\
    \      st[p] = op(st[p << 1], st[p << 1 | 1]);\n    }\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T, T(*op)(T, T), T(*id)()>\nstruct SegmentTree\
    \ {\n  int n;\n  vector<T> st;\n\n  SegmentTree(int sz) : n(sz), st(2 * n, id())\
    \ {}\n\n  SegmentTree(const vector<T> &a) : n(sz(a)), st(2 * n) {\n    copy(begin(a),\
    \ end(a), begin(st) + n);\n    for (int i = n - 1; i > 0; i--) {\n      st[i]\
    \ = op(st[i << 1], st[i << 1 | 1]);\n    }\n  }\n\n  T query(int l, int r) {\n\
    \    T ls = id(), rs = id();\n    for (l += n, r += n + 1; l < r; l >>= 1, r >>=\
    \ 1) {\n      if (l & 1) {\n        ls = op(ls, st[l++]);\n      }\n      if (r\
    \ & 1) {\n        rs = op(st[--r], rs);\n      }\n    }\n    return op(ls, rs);\n\
    \  }\n\n  void set(int p, T val) {\n    for (st[p += n] = val, p >>= 1; p > 0;\
    \ p >>= 1) {\n      st[p] = op(st[p << 1], st[p << 1 | 1]);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segtreecore/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-08-31 22:39:57-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rmq.test.cpp
documentation_of: datastructures/segtreecore/segment_tree.hpp
layout: document
redirect_from:
- /library/datastructures/segtreecore/segment_tree.hpp
- /library/datastructures/segtreecore/segment_tree.hpp.html
title: datastructures/segtreecore/segment_tree.hpp
---
