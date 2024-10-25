---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_indexed_tree/bit.h
    title: datastructures/binary_indexed_tree/bit.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/binary_indexed_tree/bit_2d.h\"\n\n#line 2\
    \ \"datastructures/binary_indexed_tree/bit.h\"\n\ntemplate <class T>\nstruct BIT\
    \ {\n    int n;\n    vector<T> ft;\n\n    BIT(int n_) : n(n_), ft(n + 1) {}\n\n\
    \    BIT(const vector<T> &a) : n(sz(a)), ft(n + 1) {\n        for (int i = 1;\
    \ i <= n; i++) {\n            ft[i] += a[i - 1];\n            if (i + (i & -i)\
    \ <= n) {\n                ft[i + (i & -i)] += ft[i];\n            }\n       \
    \ }\n    }\n\n    void add(int p, T v) {\n        for (p++; p <= n; p += p & -p)\
    \ {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int r) {\n       \
    \ T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n            res += ft[r];\n\
    \        }\n        return res;\n    }\n\n    T sum(int l, int r) {\n        return\
    \ sum(r) - sum(l - 1);\n    }\n};\n#line 4 \"datastructures/binary_indexed_tree/bit_2d.h\"\
    \n\ntemplate <class T>\nstruct BIT2D {\n    int n;\n    vector<BIT<T>> ft;\n\n\
    \    BIT2D(int n_, int m) : n(n_), ft(n + 1, BIT<T>(m)) {}\n\n    void add(int\
    \ r, int c, T v) {\n        for (r++; r <= n; r += r & -r) {\n            ft[r].add(c,\
    \ v);\n        }\n    }\n\n    T sum(int r, int c) {\n        if (r < 0 || c <\
    \ 0) {\n            return 0;\n        }\n        T res = 0;\n        for (r++;\
    \ r > 0; r -= r & -r) {\n            res += ft[r].sum(c);\n        }\n       \
    \ return res;\n    }\n\n    T sum(int r1, int c1, int r2, int c2) {\n        return\
    \ sum(r2, c2) - sum(r2, c1 - 1) - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1);\n   \
    \ }\n};\n"
  code: "#pragma once\n\n#include \"bit.h\"\n\ntemplate <class T>\nstruct BIT2D {\n\
    \    int n;\n    vector<BIT<T>> ft;\n\n    BIT2D(int n_, int m) : n(n_), ft(n\
    \ + 1, BIT<T>(m)) {}\n\n    void add(int r, int c, T v) {\n        for (r++; r\
    \ <= n; r += r & -r) {\n            ft[r].add(c, v);\n        }\n    }\n\n   \
    \ T sum(int r, int c) {\n        if (r < 0 || c < 0) {\n            return 0;\n\
    \        }\n        T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n    \
    \        res += ft[r].sum(c);\n        }\n        return res;\n    }\n\n    T\
    \ sum(int r1, int c1, int r2, int c2) {\n        return sum(r2, c2) - sum(r2,\
    \ c1 - 1) - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1);\n    }\n};"
  dependsOn:
  - datastructures/binary_indexed_tree/bit.h
  isVerificationFile: false
  path: datastructures/binary_indexed_tree/bit_2d.h
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/binary_indexed_tree/bit_2d.h
layout: document
redirect_from:
- /library/datastructures/binary_indexed_tree/bit_2d.h
- /library/datastructures/binary_indexed_tree/bit_2d.h.html
title: datastructures/binary_indexed_tree/bit_2d.h
---
