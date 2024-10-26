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
  bundledCode: "#line 1 \"datastructures/binary_indexed_tree/bit_range_add.h\"\ntemplate\
    \ <class T>\nstruct BITRU {\n    int n;\n    vector<T> ft;\n\n    BITRU(int n_)\
    \ : n(n_), ft(n + 1) {}\n\n    BITRU(const vector<T> &a) : n(sz(a)), ft(n + 1)\
    \ {\n        for (int i = 0; i < n; i++) {\n            ft[i + 1] += a[i];\n \
    \           ft[i] -= a[i];\n        }\n        for (int i = n; i >= 1; i--) {\n\
    \            ft[i - (i & -i)] += ft[i];\n        }\n    }\n\n    void add(int\
    \ r, T v) {\n        for (r++; r > 0; r -= r & -r) {\n            ft[r] += v;\n\
    \        }\n    }\n\n    void add(int l, int r, T v) {\n        add(r, v);\n \
    \       add(l - 1, T(0) - v);\n    }\n\n    T get(int p) {\n        T res = 0;\n\
    \        for (p++; p <= n; p += p & -p) {\n            res += ft[p];\n       \
    \ }\n        return res;\n    }\n};\n"
  code: "template <class T>\nstruct BITRU {\n    int n;\n    vector<T> ft;\n\n   \
    \ BITRU(int n_) : n(n_), ft(n + 1) {}\n\n    BITRU(const vector<T> &a) : n(sz(a)),\
    \ ft(n + 1) {\n        for (int i = 0; i < n; i++) {\n            ft[i + 1] +=\
    \ a[i];\n            ft[i] -= a[i];\n        }\n        for (int i = n; i >= 1;\
    \ i--) {\n            ft[i - (i & -i)] += ft[i];\n        }\n    }\n\n    void\
    \ add(int r, T v) {\n        for (r++; r > 0; r -= r & -r) {\n            ft[r]\
    \ += v;\n        }\n    }\n\n    void add(int l, int r, T v) {\n        add(r,\
    \ v);\n        add(l - 1, T(0) - v);\n    }\n\n    T get(int p) {\n        T res\
    \ = 0;\n        for (p++; p <= n; p += p & -p) {\n            res += ft[p];\n\
    \        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/binary_indexed_tree/bit_range_add.h
  requiredBy: []
  timestamp: '2024-10-25 20:08:44-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/binary_indexed_tree/bit_range_add.h
layout: document
redirect_from:
- /library/datastructures/binary_indexed_tree/bit_range_add.h
- /library/datastructures/binary_indexed_tree/bit_range_add.h.html
title: datastructures/binary_indexed_tree/bit_range_add.h
---
