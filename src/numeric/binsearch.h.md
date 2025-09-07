---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/string/enumerate_palindromes.test.cpp
    title: src/verify/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/numeric/binsearch.h\"\ntemplate <class T, class U>\n\
    T bsmin(T lo, T hi, U f) {\n  assert(lo <= hi);\n  hi++;\n  for (T i = T(1) <<\
    \ __lg(hi - lo); i > 0; i >>= 1) {\n    hi -= (hi - i >= lo && f(hi - i)) * i;\n\
    \  }\n  return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f)\
    \ {\n  assert(lo <= hi);\n  lo--;\n  for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n    lo += (lo + i <= hi && f(lo + i)) * i;\n  }\n  return lo;\n\
    }\n"
  code: "template <class T, class U>\nT bsmin(T lo, T hi, U f) {\n  assert(lo <= hi);\n\
    \  hi++;\n  for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n    hi -= (hi\
    \ - i >= lo && f(hi - i)) * i;\n  }\n  return hi;\n}\n\ntemplate <class T, class\
    \ U>\nT bsmax(T lo, T hi, U f) {\n  assert(lo <= hi);\n  lo--;\n  for (T i = T(1)\
    \ << __lg(hi - lo); i > 0; i >>= 1) {\n    lo += (lo + i <= hi && f(lo + i)) *\
    \ i;\n  }\n  return lo;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/numeric/binsearch.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - src/verify/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: src/numeric/binsearch.h
layout: document
redirect_from:
- /library/src/numeric/binsearch.h
- /library/src/numeric/binsearch.h.html
title: src/numeric/binsearch.h
---
