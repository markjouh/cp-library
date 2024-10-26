---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/segment_tree/segtree_range_update.h\"\ntemplate\
    \ <class T, auto op, auto id>\nstruct SegtreeRU {\n    int n;\n    vector<T> st;\n\
    \n    SegtreeRU(int n_) : n(n_), st(2 * n, id()) {}\n\n    void update(int l,\
    \ int r, T v) {\n        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) {\n                st[l] = op(st[l], v);\n           \
    \     l++;\n            }\n            if (r & 1) {\n                r--;\n  \
    \              st[r] = op(st[r], v);\n            }\n        }\n    }\n\n    int\
    \ get(int p) {\n        T res = id();\n        for (p += n; p > 0; p >>= 1) {\n\
    \            res = op(res, st[p]);\n        }\n        return res;\n    }\n};\n"
  code: "template <class T, auto op, auto id>\nstruct SegtreeRU {\n    int n;\n  \
    \  vector<T> st;\n\n    SegtreeRU(int n_) : n(n_), st(2 * n, id()) {}\n\n    void\
    \ update(int l, int r, T v) {\n        for (l += n, r += n + 1; l < r; l >>= 1,\
    \ r >>= 1) {\n            if (l & 1) {\n                st[l] = op(st[l], v);\n\
    \                l++;\n            }\n            if (r & 1) {\n             \
    \   r--;\n                st[r] = op(st[r], v);\n            }\n        }\n  \
    \  }\n\n    int get(int p) {\n        T res = id();\n        for (p += n; p >\
    \ 0; p >>= 1) {\n            res = op(res, st[p]);\n        }\n        return\
    \ res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segment_tree/segtree_range_update.h
  requiredBy: []
  timestamp: '2024-10-25 20:41:56-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segment_tree/segtree_range_update.h
layout: document
redirect_from:
- /library/datastructures/segment_tree/segtree_range_update.h
- /library/datastructures/segment_tree/segtree_range_update.h.html
title: datastructures/segment_tree/segtree_range_update.h
---
