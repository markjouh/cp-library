---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/custom/numeric/binary_search_reals.test.cpp
    title: verify/custom/numeric/binary_search_reals.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/random.hpp\"\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T>\nT randint(T n) {\n  return uniform_int_distribution<T>(0,\
    \ n)(rng_64);\n}\n\ntemplate <class T>\nT randint(T lo, T hi) {\n  return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\ndouble randreal(T n = 1) {\n  return\
    \ uniform_real_distribution<double>(0, n)(rng_64);\n}\n\ntemplate <class T>\n\
    double randreal(T lo, T hi) {\n  return uniform_real_distribution<double>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\nvoid shuffle_array(T &a) {\n  for (int\
    \ i = 1; i < sz(a); i++) {\n    swap(a[i], a[randint(0, i)]);\n  }\n}\n"
  code: "#pragma once\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T>\nT randint(T n) {\n  return uniform_int_distribution<T>(0,\
    \ n)(rng_64);\n}\n\ntemplate <class T>\nT randint(T lo, T hi) {\n  return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\ndouble randreal(T n = 1) {\n  return\
    \ uniform_real_distribution<double>(0, n)(rng_64);\n}\n\ntemplate <class T>\n\
    double randreal(T lo, T hi) {\n  return uniform_real_distribution<double>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\nvoid shuffle_array(T &a) {\n  for (int\
    \ i = 1; i < sz(a); i++) {\n    swap(a[i], a[randint(0, i)]);\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: utils/random.hpp
  requiredBy: []
  timestamp: '2024-09-03 11:43:32-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/custom/numeric/binary_search_reals.test.cpp
documentation_of: utils/random.hpp
layout: document
redirect_from:
- /library/utils/random.hpp
- /library/utils/random.hpp.html
title: utils/random.hpp
---
