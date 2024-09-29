---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/priority_queue.test.cpp
    title: verify/aizu/alds1/priority_queue.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"common/compress.h\"\n\ntemplate <class T>\nstruct Compress\
    \ {\n    vector<T> vals;\n\n    Compress() {}\n    Compress(const vector<T> &a)\
    \ : vals(a) {\n        init();\n    }\n    T operator[](int p) {\n        return\
    \ vals[p];\n    }\n    friend size_t size(const Compress &x) {\n        return\
    \ size(x.vals);\n    }\n\n    void init() {\n        sort(all(vals));\n      \
    \  vals.resize(unique(all(vals)) - begin(vals));\n    }\n    void insert(T x)\
    \ {\n        vals.push_back(x);\n    }\n    int get(T x) {\n        return lower_bound(all(vals),\
    \ x) - begin(vals);\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct Compress {\n    vector<T> vals;\n\
    \n    Compress() {}\n    Compress(const vector<T> &a) : vals(a) {\n        init();\n\
    \    }\n    T operator[](int p) {\n        return vals[p];\n    }\n    friend\
    \ size_t size(const Compress &x) {\n        return size(x.vals);\n    }\n\n  \
    \  void init() {\n        sort(all(vals));\n        vals.resize(unique(all(vals))\
    \ - begin(vals));\n    }\n    void insert(T x) {\n        vals.push_back(x);\n\
    \    }\n    int get(T x) {\n        return lower_bound(all(vals), x) - begin(vals);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: common/compress.h
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/priority_queue.test.cpp
documentation_of: common/compress.h
layout: document
redirect_from:
- /library/common/compress.h
- /library/common/compress.h.html
title: common/compress.h
---
