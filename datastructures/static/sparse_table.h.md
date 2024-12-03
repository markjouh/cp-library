---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graphs/trees/rmq_lca.h
    title: graphs/trees/rmq_lca.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/static/sparse_table.h\"\ntemplate <class\
    \ T, auto op>\nstruct sparse_table {\n    int n, log;\n    vector<vector<T>> st;\n\
    \n    sparse_table() {}\n    sparse_table(const vector<T> &a) : n(sz(a)), log(__lg(n)\
    \ + 1) {\n        st.resize(log);\n        st[0] = a;\n        for (int i = 1;\
    \ i < log; i++) {\n            st[i].resize(n - (1 << i) + 1);\n            for\
    \ (int j = 0; j < sz(st[i]); j++) {\n                st[i][j] = op(st[i - 1][j],\
    \ st[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int\
    \ l, int r) {\n        assert(l <= r);\n        int i = __lg(++r - l);\n     \
    \   return op(st[i][l], st[i][r - (1 << i)]);\n    }\n};\n\ntemplate <class T>\n\
    T min_op(T x, T y) {\n    return x < y ? x : y;\n}\ntemplate <class T>\nT max_op(T\
    \ x, T y) {\n    return x > y ? x : y;\n}\n"
  code: "template <class T, auto op>\nstruct sparse_table {\n    int n, log;\n   \
    \ vector<vector<T>> st;\n\n    sparse_table() {}\n    sparse_table(const vector<T>\
    \ &a) : n(sz(a)), log(__lg(n) + 1) {\n        st.resize(log);\n        st[0] =\
    \ a;\n        for (int i = 1; i < log; i++) {\n            st[i].resize(n - (1\
    \ << i) + 1);\n            for (int j = 0; j < sz(st[i]); j++) {\n           \
    \     st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n          \
    \  }\n        }\n    }\n\n    T query(int l, int r) {\n        assert(l <= r);\n\
    \        int i = __lg(++r - l);\n        return op(st[i][l], st[i][r - (1 << i)]);\n\
    \    }\n};\n\ntemplate <class T>\nT min_op(T x, T y) {\n    return x < y ? x :\
    \ y;\n}\ntemplate <class T>\nT max_op(T x, T y) {\n    return x > y ? x : y;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/sparse_table.h
  requiredBy:
  - graphs/trees/rmq_lca.h
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_rmq.test.cpp
documentation_of: datastructures/static/sparse_table.h
layout: document
redirect_from:
- /library/datastructures/static/sparse_table.h
- /library/datastructures/static/sparse_table.h.html
title: datastructures/static/sparse_table.h
---
