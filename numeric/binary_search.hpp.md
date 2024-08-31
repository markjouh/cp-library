---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/binary_search.hpp\"\n\ntemplate <class T, class\
    \ U>\nT bsmin(T lo, T hi, U f) {\n  assert(lo <= hi);\n  hi++;\n  for (T i = T(1)\
    \ << __lg(hi - lo); i > 0; i >>= 1) {\n    hi -= (hi - i >= lo && f(hi - i)) *\
    \ i;\n  }\n  return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi,\
    \ U f) {\n  assert(lo <= hi);\n  lo--;\n  for (T i = T(1) << __lg(hi - lo); i\
    \ > 0; i >>= 1) {\n    lo += (lo + i <= hi && f(lo + i)) * i;\n  }\n  return lo;\n\
    }\n"
  code: "#pragma once\n\ntemplate <class T, class U>\nT bsmin(T lo, T hi, U f) {\n\
    \  assert(lo <= hi);\n  hi++;\n  for (T i = T(1) << __lg(hi - lo); i > 0; i >>=\
    \ 1) {\n    hi -= (hi - i >= lo && f(hi - i)) * i;\n  }\n  return hi;\n}\n\ntemplate\
    \ <class T, class U>\nT bsmax(T lo, T hi, U f) {\n  assert(lo <= hi);\n  lo--;\n\
    \  for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n    lo += (lo + i <= hi\
    \ && f(lo + i)) * i;\n  }\n  return lo;\n}"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binary_search.hpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: numeric/binary_search.hpp
layout: document
title: Binary Search
---

### Overview

Given a monotonic boolean function taking in an integer position value x, calculates the first/last x that returns `true` in $O(\log{(hi - lo)}) * T_f$.

### Usage

* `bsmin(lo, hi, f)`: Returns the min $x \in [lo, hi]$ such that $f(x)$, or $hi + 1$ if all false. 
* `bsmax(lo, hi, f)`: Returns the max $x \in [lo, hi]$ such that $f(x)$, or $lo - 1$ if all false.