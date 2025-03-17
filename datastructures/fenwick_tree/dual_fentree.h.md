---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/fenwick_tree/dual_fentree.h\"\ntemplate <class\
    \ T>\nstruct DualFentree {\n  int n;\n  Fentree<T> pref, suff;\n\n  DualFentree(int\
    \ n_) : n(n_), pref(n), suff(n) {}\n\n  T sum(int r) {\n    return pref.sum(r\
    \ - 1) + suff.sum(n - r - 1) * (r + 1);\n  }\n\n  T sum(int l, int r) {\n    return\
    \ sum(r) - (l > 0 ? sum(l - 1) : 0);\n  }\n\n  void add(int r, T v) {\n    pref.add(r,\
    \ v * (r + 1));\n    suff.add(n - r - 1, v);\n  }\n\n  void add(int l, int r,\
    \ T v) {\n    add(r, v);\n    if (l > 0) {\n      add(l - 1, T(0) - T(v));\n \
    \   }\n  }\n};\n"
  code: "template <class T>\nstruct DualFentree {\n  int n;\n  Fentree<T> pref, suff;\n\
    \n  DualFentree(int n_) : n(n_), pref(n), suff(n) {}\n\n  T sum(int r) {\n   \
    \ return pref.sum(r - 1) + suff.sum(n - r - 1) * (r + 1);\n  }\n\n  T sum(int\
    \ l, int r) {\n    return sum(r) - (l > 0 ? sum(l - 1) : 0);\n  }\n\n  void add(int\
    \ r, T v) {\n    pref.add(r, v * (r + 1));\n    suff.add(n - r - 1, v);\n  }\n\
    \n  void add(int l, int r, T v) {\n    add(r, v);\n    if (l > 0) {\n      add(l\
    \ - 1, T(0) - T(v));\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/fenwick_tree/dual_fentree.h
  requiredBy: []
  timestamp: '2025-03-17 19:49:59-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
documentation_of: datastructures/fenwick_tree/dual_fentree.h
layout: document
redirect_from:
- /library/datastructures/fenwick_tree/dual_fentree.h
- /library/datastructures/fenwick_tree/dual_fentree.h.html
title: datastructures/fenwick_tree/dual_fentree.h
---
