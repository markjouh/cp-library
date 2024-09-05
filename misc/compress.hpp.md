---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/priority_queue.test.cpp
    title: verify/aizu/alds1/priority_queue.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/compress.hpp\"\n\ntemplate <class T>\nstruct Compress\
    \ {\n  vector<T> vals;\n\n  Compress() {}\n\n  Compress(const vector<T> &a) :\
    \ vals(a) {\n    init();\n  }\n\n  void init() {\n    sort(all(vals));\n    vals.resize(unique(all(vals))\
    \ - begin(vals));\n  }\n\n  void insert(T x) {\n    vals.push_back(x);\n  }\n\n\
    \  int get(T x) {\n    return lower_bound(all(vals), x) - begin(vals);\n  }\n\n\
    \  friend size_t size(const Compress &x) {\n    return size(x.vals);\n  }\n\n\
    \  T operator[](int p) {\n    return vals[p];\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T>\nstruct Compress {\n  vector<T> vals;\n\
    \n  Compress() {}\n\n  Compress(const vector<T> &a) : vals(a) {\n    init();\n\
    \  }\n\n  void init() {\n    sort(all(vals));\n    vals.resize(unique(all(vals))\
    \ - begin(vals));\n  }\n\n  void insert(T x) {\n    vals.push_back(x);\n  }\n\n\
    \  int get(T x) {\n    return lower_bound(all(vals), x) - begin(vals);\n  }\n\n\
    \  friend size_t size(const Compress &x) {\n    return size(x.vals);\n  }\n\n\
    \  T operator[](int p) {\n    return vals[p];\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.hpp
  requiredBy: []
  timestamp: '2024-09-05 15:13:46-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aizu/alds1/priority_queue.test.cpp
  - verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
documentation_of: misc/compress.hpp
layout: document
redirect_from:
- /library/misc/compress.hpp
- /library/misc/compress.hpp.html
title: misc/compress.hpp
---
