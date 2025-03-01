---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree/fentree.h
    title: datastructures/fenwick_tree/fentree.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/fenwick_tree/fentree.h\"\ntemplate <class\
    \ T>\nstruct fentree {\n    int n;\n    vector<T> ft;\n\n    fentree(int n_) :\
    \ n(n_), ft(n + 1) {}\n\n    fentree(const vector<T> &a) : n(sz(a)), ft(n + 1)\
    \ {\n        for (int i = 1; i <= n; i++) {\n            ft[i] += a[i - 1];\n\
    \            if (i + (i & -i) <= n) {\n                ft[i + (i & -i)] += ft[i];\n\
    \            }\n        }\n    }\n\n    void add(int p, T v) {\n        for (p++;\
    \ p <= n; p += p & -p) {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int\
    \ r) {\n        T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n        \
    \    res += ft[r];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l - 1);\n    }\n};\n#line 2 \"datastructures/fenwick_tree/dual_fentree.h\"\
    \n\ntemplate <class T>\nstruct dual_fentree {\n    int n;\n    fentree<T> pref,\
    \ suff;\n\n    dual_fentree(int n_) : n(n_), pref(n), suff(n) {}\n\n    T sum(int\
    \ r) {\n        return pref.sum(r - 1) + suff.sum(n - r - 1) * (r + 1);\n    }\n\
    \n    T sum(int l, int r) {\n        return sum(r) - (l > 0 ? sum(l - 1) : 0);\n\
    \    }\n\n    void add(int r, T v) {\n        pref.add(r, v * (r + 1));\n    \
    \    suff.add(n - r - 1, v);\n    }\n\n    void add(int l, int r, T v) {\n   \
    \     add(r, v);\n        if (l > 0) {\n            add(l - 1, T(0) - T(v));\n\
    \        }\n    }\n};\n"
  code: "#include \"fentree.h\"\n\ntemplate <class T>\nstruct dual_fentree {\n   \
    \ int n;\n    fentree<T> pref, suff;\n\n    dual_fentree(int n_) : n(n_), pref(n),\
    \ suff(n) {}\n\n    T sum(int r) {\n        return pref.sum(r - 1) + suff.sum(n\
    \ - r - 1) * (r + 1);\n    }\n\n    T sum(int l, int r) {\n        return sum(r)\
    \ - (l > 0 ? sum(l - 1) : 0);\n    }\n\n    void add(int r, T v) {\n        pref.add(r,\
    \ v * (r + 1));\n        suff.add(n - r - 1, v);\n    }\n\n    void add(int l,\
    \ int r, T v) {\n        add(r, v);\n        if (l > 0) {\n            add(l -\
    \ 1, T(0) - T(v));\n        }\n    }\n};"
  dependsOn:
  - datastructures/fenwick_tree/fentree.h
  isVerificationFile: false
  path: datastructures/fenwick_tree/dual_fentree.h
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
documentation_of: datastructures/fenwick_tree/dual_fentree.h
layout: document
redirect_from:
- /library/datastructures/fenwick_tree/dual_fentree.h
- /library/datastructures/fenwick_tree/dual_fentree.h.html
title: datastructures/fenwick_tree/dual_fentree.h
---
