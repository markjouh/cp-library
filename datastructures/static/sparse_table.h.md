---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/static/sparse_table.h\"\n\ntemplate <class\
    \ T, auto op>\nstruct RMQ {\n    int n, log;\n    vector<vector<T>> st;\n\n  \
    \  RMQ() {}\n    RMQ(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1) {\n    \
    \    st.resize(log);\n        st[0] = a;\n        rep(i, 1, log) {\n         \
    \   st[i].resize(n - (1 << i) + 1);\n            rep(j, sz(st[i])) {\n       \
    \         st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n      \
    \      }\n        }\n    }\n\n    T query(int l, int r) {\n        assert(l <=\
    \ r);\n        int i = __lg(++r - l);\n        return op(st[i][l], st[i][r - (1\
    \ << i)]);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T, auto op>\nstruct RMQ {\n    int n, log;\n\
    \    vector<vector<T>> st;\n\n    RMQ() {}\n    RMQ(const vector<T> &a) : n(sz(a)),\
    \ log(__lg(n) + 1) {\n        st.resize(log);\n        st[0] = a;\n        rep(i,\
    \ 1, log) {\n            st[i].resize(n - (1 << i) + 1);\n            rep(j, sz(st[i]))\
    \ {\n                st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n\
    \            }\n        }\n    }\n\n    T query(int l, int r) {\n        assert(l\
    \ <= r);\n        int i = __lg(++r - l);\n        return op(st[i][l], st[i][r\
    \ - (1 << i)]);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/sparse_table.h
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/data_structure/static_rmq.test.cpp
documentation_of: datastructures/static/sparse_table.h
layout: document
redirect_from:
- /library/datastructures/static/sparse_table.h
- /library/datastructures/static/sparse_table.h.html
title: datastructures/static/sparse_table.h
---
