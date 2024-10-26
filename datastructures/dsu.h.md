---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/dsu.h\"\nstruct DSU {\n    vector<int> a;\n\
    \n    DSU(int n) : a(n, -1) {}\n\n    int size(int x) {\n        return -a[find(x)];\n\
    \    }\n\n    int find(int x) {\n        return a[x] < 0 ? x : a[x] = find(a[x]);\n\
    \    }\n\n    bool join(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if (x == y) {\n            return 0;\n        }\n        if (a[x] > a[y])\
    \ {\n            swap(x, y);\n        }\n        a[x] += a[y];\n        a[y] =\
    \ x;\n        return 1;\n    }\n};\n"
  code: "struct DSU {\n    vector<int> a;\n\n    DSU(int n) : a(n, -1) {}\n\n    int\
    \ size(int x) {\n        return -a[find(x)];\n    }\n\n    int find(int x) {\n\
    \        return a[x] < 0 ? x : a[x] = find(a[x]);\n    }\n\n    bool join(int\
    \ x, int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y)\
    \ {\n            return 0;\n        }\n        if (a[x] > a[y]) {\n          \
    \  swap(x, y);\n        }\n        a[x] += a[y];\n        a[y] = x;\n        return\
    \ 1;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/dsu.h
  requiredBy: []
  timestamp: '2024-10-25 20:08:44-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/unionfind.test.cpp
documentation_of: datastructures/dsu.h
layout: document
redirect_from:
- /library/datastructures/dsu.h
- /library/datastructures/dsu.h.html
title: datastructures/dsu.h
---
