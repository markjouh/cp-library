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
    double bsmin_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo),\
    \ r = reinterpret_cast<uint64_t&>(hi) + 1;\n  for (uint64_t i = 1ull << lg(r -\
    \ l); i > 0; i >>= 1) {\n    uint64_t nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\n\
    double bsmax_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n  for (uint64_t i = 1ull << lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n"
  code: "#pragma once\n\ntemplate <class T>\ndouble bsmin_reals(double lo, double\
    \ hi, T f) {\n  static_assert(sizeof(uint64_t) >= sizeof(double));\n  assert(lo\
    \ <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo), r = reinterpret_cast<uint64_t&>(hi)\
    \ + 1;\n  for (uint64_t i = 1ull << lg(r - l); i > 0; i >>= 1) {\n    uint64_t\
    \ nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt))) * i;\n\
    \  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\ndouble\
    \ bsmax_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t) >=\
    \ sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n  for (uint64_t i = 1ull << lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binary_search_reals.hpp
  requiredBy: []
  timestamp: '2024-09-01 21:11:12-04:00'
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
