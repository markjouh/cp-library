---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/custom/numeric/binary_search_reals.test.cpp
    title: verify/custom/numeric/binary_search_reals.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/binary_search_reals.hpp\"\n\ntemplate <class T>\n\
    double bsminReals(double lo, double hi, T f) {\n  static_assert(sizeof(u64) >=\
    \ sizeof(double));\n  assert(lo <= hi);\n  u64 l = reinterpret_cast<u64&>(lo),\
    \ r = reinterpret_cast<u64&>(hi) + 1;\n  for (u64 i = 1ull << __lg(r - l); i >\
    \ 0; i >>= 1) {\n    u64 nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\n\
    double bsmaxReals(double lo, double hi, T f) {\n  static_assert(sizeof(u64) >=\
    \ sizeof(double));\n  assert(lo <= hi);\n  u64 l = reinterpret_cast<u64&>(lo)\
    \ - 1, r = reinterpret_cast<u64&>(hi);\n  for (u64 i = 1ull << __lg(r - l); i\
    \ > 0; i >>= 1) {\n    u64 nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n"
  code: "#pragma once\n\ntemplate <class T>\ndouble bsminReals(double lo, double hi,\
    \ T f) {\n  static_assert(sizeof(u64) >= sizeof(double));\n  assert(lo <= hi);\n\
    \  u64 l = reinterpret_cast<u64&>(lo), r = reinterpret_cast<u64&>(hi) + 1;\n \
    \ for (u64 i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n    u64 nxt = r - i;\n\
    \    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt))) * i;\n  }\n  return\
    \ reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\ndouble bsmaxReals(double\
    \ lo, double hi, T f) {\n  static_assert(sizeof(u64) >= sizeof(double));\n  assert(lo\
    \ <= hi);\n  u64 l = reinterpret_cast<u64&>(lo) - 1, r = reinterpret_cast<u64&>(hi);\n\
    \  for (u64 i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n    u64 nxt = l + i;\n\
    \    l += (nxt <= r && f(reinterpret_cast<double&>(nxt))) * i;\n  }\n  return\
    \ reinterpret_cast<double&>(l);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binary_search_reals.hpp
  requiredBy: []
  timestamp: '2024-09-11 14:56:51-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/custom/numeric/binary_search_reals.test.cpp
documentation_of: numeric/binary_search_reals.hpp
layout: document
redirect_from:
- /library/numeric/binary_search_reals.hpp
- /library/numeric/binary_search_reals.hpp.html
title: numeric/binary_search_reals.hpp
---
