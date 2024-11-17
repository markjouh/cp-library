---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/static/mergesort_tree.h\"\ntemplate <class\
    \ T>\nstruct MergesortTree {\n    int n;\n    vector<vector<T>> st;\n\n    MergesortTree(const\
    \ vector<T> &a) : n(sz(a)), st(2 * n) {\n        for (int i = 0; i < n; i++) {\n\
    \            st[i + n] = {a[i]};\n        }\n        for (int i = n - 1; i > 0;\
    \ i--) {\n            merge(begin(st[i << 1]), end(st[i << 1]), begin(st[i <<\
    \ 1 | 1]),\n                end(st[i << 1 | 1]), back_inserter(st[i]));\n    \
    \    }\n    }\n\n    T query(int l, int r, T v) {\n        T ls = 0, rs = 0;\n\
    \        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l\
    \ & 1) {\n                ls += lower_bound(all(st[l]), v) - begin(st[l]);\n \
    \               l++;\n            }\n            if (r & 1) {\n              \
    \  r--;\n                rs += lower_bound(all(st[r]), v) - begin(st[r]);\n  \
    \          }\n        }\n        return ls + rs;\n    }\n};\n"
  code: "template <class T>\nstruct MergesortTree {\n    int n;\n    vector<vector<T>>\
    \ st;\n\n    MergesortTree(const vector<T> &a) : n(sz(a)), st(2 * n) {\n     \
    \   for (int i = 0; i < n; i++) {\n            st[i + n] = {a[i]};\n        }\n\
    \        for (int i = n - 1; i > 0; i--) {\n            merge(begin(st[i << 1]),\
    \ end(st[i << 1]), begin(st[i << 1 | 1]),\n                end(st[i << 1 | 1]),\
    \ back_inserter(st[i]));\n        }\n    }\n\n    T query(int l, int r, T v) {\n\
    \        T ls = 0, rs = 0;\n        for (l += n, r += n + 1; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) {\n                ls += lower_bound(all(st[l]),\
    \ v) - begin(st[l]);\n                l++;\n            }\n            if (r &\
    \ 1) {\n                r--;\n                rs += lower_bound(all(st[r]), v)\
    \ - begin(st[r]);\n            }\n        }\n        return ls + rs;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/mergesort_tree.h
  requiredBy: []
  timestamp: '2024-10-25 20:41:56-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: datastructures/static/mergesort_tree.h
layout: document
redirect_from:
- /library/datastructures/static/mergesort_tree.h
- /library/datastructures/static/mergesort_tree.h.html
title: datastructures/static/mergesort_tree.h
---
