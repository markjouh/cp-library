---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/fentree/fenwick_tree_range_add.hpp\"\n\n\
    template <class T>\nstruct RangeAddFT {\n  int n;\n  vector<T> ft;\n\n  RangeAddFT(int\
    \ x) : n(x), ft(n + 1) {}\n\n  RangeAddFT(const vector<T> &a) : n(sz(a)), ft(n\
    \ + 1) {\n    for (int i = 0; i < n; i++) {\n      ft[i + 1] += a[i];\n      ft[i]\
    \ -= a[i];\n    }\n    for (int i = n; i >= 1; i--) {\n      ft[i - (i & -i)]\
    \ += ft[i];\n    }\n  }\n\n  void add(int r, T v) {\n    // assert(r < n);\n \
    \   for (r++; r > 0; r -= r & -r) {\n      ft[r] += v;\n    }\n  }\n\n  void add(int\
    \ l, int r, T v) {\n    add(r, v);\n    add(l - 1, T(0) - v);\n  }\n\n  T get(int\
    \ p) {\n    // assert(p >= 0);\n    T res = 0;\n    for (p++; p <= n; p += p &\
    \ -p) {\n      res += ft[p];\n    }\n    return res;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct RangeAddFT {\n  int n;\n  vector<T>\
    \ ft;\n\n  RangeAddFT(int x) : n(x), ft(n + 1) {}\n\n  RangeAddFT(const vector<T>\
    \ &a) : n(sz(a)), ft(n + 1) {\n    for (int i = 0; i < n; i++) {\n      ft[i +\
    \ 1] += a[i];\n      ft[i] -= a[i];\n    }\n    for (int i = n; i >= 1; i--) {\n\
    \      ft[i - (i & -i)] += ft[i];\n    }\n  }\n\n  void add(int r, T v) {\n  \
    \  // assert(r < n);\n    for (r++; r > 0; r -= r & -r) {\n      ft[r] += v;\n\
    \    }\n  }\n\n  void add(int l, int r, T v) {\n    add(r, v);\n    add(l - 1,\
    \ T(0) - v);\n  }\n\n  T get(int p) {\n    // assert(p >= 0);\n    T res = 0;\n\
    \    for (p++; p <= n; p += p & -p) {\n      res += ft[p];\n    }\n    return\
    \ res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/fentree/fenwick_tree_range_add.hpp
  requiredBy: []
  timestamp: '2024-09-02 21:02:51-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/fentree/fenwick_tree_range_add.hpp
layout: document
redirect_from:
- /library/datastructures/fentree/fenwick_tree_range_add.hpp
- /library/datastructures/fentree/fenwick_tree_range_add.hpp.html
title: datastructures/fentree/fenwick_tree_range_add.hpp
---
