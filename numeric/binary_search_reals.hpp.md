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
  bundledCode: "#line 2 \"numeric/binary_search_reals.hpp\"\n\ntemplate <class T>\n\
    double bsmin_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo),\
    \ r = reinterpret_cast<uint64_t&>(hi) + 1;\n  for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\n\
    double bsmax_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n  for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n"
  code: "#pragma once\n\ntemplate <class T>\ndouble bsmin_reals(double lo, double\
    \ hi, T f) {\n  static_assert(sizeof(uint64_t) >= sizeof(double));\n  assert(lo\
    \ <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo), r = reinterpret_cast<uint64_t&>(hi)\
    \ + 1;\n  for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n    uint64_t\
    \ nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt))) * i;\n\
    \  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\ndouble\
    \ bsmax_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t) >=\
    \ sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n  for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binary_search_reals.hpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/binary_search_reals.hpp
layout: document
title: Binary Search on Reals
---

### Overview

Given a monotonic boolean function taking in a real position value x, calculates the first/last x that returns `true` in $O(\log{(hi - lo)}) * T_f$ (bounded by 64 in this `double` implementation).

### Usage

* `bsmin(lo, hi, f)`: Returns the min $x \in [lo, hi]$ such that $f(x)$, or $hi + 1$ if all false. 
* `bsmax(lo, hi, f)`: Returns the max $x \in [lo, hi]$ such that $f(x)$, or $lo - 1$ if all false.