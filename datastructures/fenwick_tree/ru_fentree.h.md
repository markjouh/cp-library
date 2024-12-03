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
  bundledCode: "#line 1 \"datastructures/fenwick_tree/ru_fentree.h\"\ntemplate <class\
    \ T>\nstruct ru_fentree {\n    int n;\n    vector<T> ft;\n\n    ru_fentree(int\
    \ n_) : n(n_), ft(n + 1) {}\n\n    ru_fentree(const vector<T> &a) : n(sz(a)),\
    \ ft(n + 1) {\n        for (int i = 0; i < n; i++) {\n            ft[i + 1] +=\
    \ a[i];\n            ft[i] -= a[i];\n        }\n        for (int i = n; i >= 1;\
    \ i--) {\n            ft[i - (i & -i)] += ft[i];\n        }\n    }\n\n    void\
    \ add(int r, T v) {\n        for (r++; r > 0; r -= r & -r) {\n            ft[r]\
    \ += v;\n        }\n    }\n\n    void add(int l, int r, T v) {\n        add(r,\
    \ v);\n        add(l - 1, T(0) - v);\n    }\n\n    T get(int p) {\n        T res\
    \ = 0;\n        for (p++; p <= n; p += p & -p) {\n            res += ft[p];\n\
    \        }\n        return res;\n    }\n};\n"
  code: "template <class T>\nstruct ru_fentree {\n    int n;\n    vector<T> ft;\n\n\
    \    ru_fentree(int n_) : n(n_), ft(n + 1) {}\n\n    ru_fentree(const vector<T>\
    \ &a) : n(sz(a)), ft(n + 1) {\n        for (int i = 0; i < n; i++) {\n       \
    \     ft[i + 1] += a[i];\n            ft[i] -= a[i];\n        }\n        for (int\
    \ i = n; i >= 1; i--) {\n            ft[i - (i & -i)] += ft[i];\n        }\n \
    \   }\n\n    void add(int r, T v) {\n        for (r++; r > 0; r -= r & -r) {\n\
    \            ft[r] += v;\n        }\n    }\n\n    void add(int l, int r, T v)\
    \ {\n        add(r, v);\n        add(l - 1, T(0) - v);\n    }\n\n    T get(int\
    \ p) {\n        T res = 0;\n        for (p++; p <= n; p += p & -p) {\n       \
    \     res += ft[p];\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/fenwick_tree/ru_fentree.h
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/fenwick_tree/ru_fentree.h
layout: document
redirect_from:
- /library/datastructures/fenwick_tree/ru_fentree.h
- /library/datastructures/fenwick_tree/ru_fentree.h.html
title: datastructures/fenwick_tree/ru_fentree.h
---
