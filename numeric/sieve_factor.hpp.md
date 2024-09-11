---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: verify/library_checker/number_theory/enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/sieve_factor.hpp\"\n\nvector<int> minPF, primes;\n\
    \nvoid sieve(int n) {\n  minPF.resize(n + 1);\n  for (int i = 2; i <= n; i++)\
    \ {\n    if (!minPF[i]) {\n      minPF[i] = i;\n      primes.push_back(i);\n \
    \     for (i64 j = 1ll * i * i; j <= n; j += i) {\n        if (!minPF[j]) {\n\
    \          minPF[j] = i;\n        }\n      }\n    }\n  }\n}\n\ntemplate <class\
    \ T>\nvector<pair<T, int>> factor(T num) {\n  vector<pair<T, int>> res;\n\n  if\
    \ (num <= sz(minPF) - 1) {\n    while (num > 1) {\n      int fac = minPF[num];\n\
    \      res.emplace_back(fac, 0);\n      while (num % fac == 0) {\n        num\
    \ /= fac;\n        res.back().second++;\n      }\n    }\n    return res;\n  }\n\
    \n  for (int p : primes) {\n    if (1ll * p * p > num) {\n      break;\n    }\n\
    \    int exp = 0;\n    while (num % p == 0) {\n      num /= p;\n      exp++;\n\
    \    }\n    if (exp) {\n      res.emplace_back(p, exp);\n    }\n  }\n  if (num\
    \ > 1) {\n    res.emplace_back(num, 1);\n  }\n  return res;\n}\n\ntemplate <class\
    \ T>\nvector<T> genDivisors(vector<pair<T, int>> facs) {\n  vector<T> res = {1};\n\
    \  for (auto [p, exp] : facs) {\n    const int oldSize = sz(res);\n    T coeff\
    \ = 1;\n    for (int i = 0; i < exp; i++) {\n      coeff *= p;\n      for (int\
    \ j = 0; j < oldSize; j++) {\n        res.push_back(coeff * res[j]);\n      }\n\
    \    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n\nvector<int> minPF, primes;\n\nvoid sieve(int n) {\n  minPF.resize(n\
    \ + 1);\n  for (int i = 2; i <= n; i++) {\n    if (!minPF[i]) {\n      minPF[i]\
    \ = i;\n      primes.push_back(i);\n      for (i64 j = 1ll * i * i; j <= n; j\
    \ += i) {\n        if (!minPF[j]) {\n          minPF[j] = i;\n        }\n    \
    \  }\n    }\n  }\n}\n\ntemplate <class T>\nvector<pair<T, int>> factor(T num)\
    \ {\n  vector<pair<T, int>> res;\n\n  if (num <= sz(minPF) - 1) {\n    while (num\
    \ > 1) {\n      int fac = minPF[num];\n      res.emplace_back(fac, 0);\n     \
    \ while (num % fac == 0) {\n        num /= fac;\n        res.back().second++;\n\
    \      }\n    }\n    return res;\n  }\n\n  for (int p : primes) {\n    if (1ll\
    \ * p * p > num) {\n      break;\n    }\n    int exp = 0;\n    while (num % p\
    \ == 0) {\n      num /= p;\n      exp++;\n    }\n    if (exp) {\n      res.emplace_back(p,\
    \ exp);\n    }\n  }\n  if (num > 1) {\n    res.emplace_back(num, 1);\n  }\n  return\
    \ res;\n}\n\ntemplate <class T>\nvector<T> genDivisors(vector<pair<T, int>> facs)\
    \ {\n  vector<T> res = {1};\n  for (auto [p, exp] : facs) {\n    const int oldSize\
    \ = sz(res);\n    T coeff = 1;\n    for (int i = 0; i < exp; i++) {\n      coeff\
    \ *= p;\n      for (int j = 0; j < oldSize; j++) {\n        res.push_back(coeff\
    \ * res[j]);\n      }\n    }\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: numeric/sieve_factor.hpp
  requiredBy: []
  timestamp: '2024-09-11 14:56:51-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
documentation_of: numeric/sieve_factor.hpp
layout: document
redirect_from:
- /library/numeric/sieve_factor.hpp
- /library/numeric/sieve_factor.hpp.html
title: numeric/sieve_factor.hpp
---
