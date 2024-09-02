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
  bundledCode: "#line 2 \"utils/my_random.hpp\"\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T>\nT randint(T lo, T hi) {\n  return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\nT randreal(T lo, T hi) {\n  return uniform_real_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\nvoid randshuf(T &a) {\n  for (int i =\
    \ 1; i < sz(a); i++) {\n    swap(a[i], a[randint(0, i)]);\n  }\n}\n"
  code: "#pragma once\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T>\nT randint(T lo, T hi) {\n  return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\nT randreal(T lo, T hi) {\n  return uniform_real_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\nvoid randshuf(T &a) {\n  for (int i =\
    \ 1; i < sz(a); i++) {\n    swap(a[i], a[randint(0, i)]);\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: utils/my_random.hpp
  requiredBy: []
  timestamp: '2024-09-01 01:23:14-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/custom/numeric/binary_search_reals.test.cpp
documentation_of: utils/my_random.hpp
layout: document
redirect_from:
- /library/utils/my_random.hpp
- /library/utils/my_random.hpp.html
title: utils/my_random.hpp
---
