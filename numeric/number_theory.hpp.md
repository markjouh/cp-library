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
  bundledCode: "#line 2 \"numeric/number_theory.hpp\"\n\nnamespace number_theory {\n\
    \nvector<int> mn_fac, primes;\n\nvoid sieve(int n) {\n    mn_fac.resize(n + 1);\n\
    \    for (int i = 2; i <= n; i++) {\n        if (!mn_fac[i]) {\n            mn_fac[i]\
    \ = i;\n            primes.push_back(i);\n            for (ll j = 1ll * i * i;\
    \ j <= n; j += i) {\n                if (!mn_fac[j]) {\n                    mn_fac[j]\
    \ = i;\n                }\n            }\n        }\n    }\n}\n\ntemplate<class\
    \ T> vector<pair<T, int>> factor(T num) {\n    vector<pair<T, int>> res;\n\n \
    \   if (num <= sz(mn_fac) - 1) {\n        while (num > 1) {\n            int fac\
    \ = mn_fac[num];\n            res.emplace_back(fac, 0);\n            while (num\
    \ % fac == 0) {\n                num /= fac;\n                res.back().second++;\n\
    \            }\n        }\n        return res;\n    }\n\n    for (int p : primes)\
    \ {\n        if (1ll * p * p > num) {\n            break;\n        }\n       \
    \ int exp = 0;\n        while (num % p == 0) {\n            num /= p;\n      \
    \      exp++;\n        }\n        if (exp) {\n            res.emplace_back(p,\
    \ exp);\n        }\n    }\n    if (num > 1) {\n        res.emplace_back(num, 1);\n\
    \    }\n    return res;\n}\n\ntemplate<class T> vector<T> gen_divisors(vector<pair<T,\
    \ int>> prime_facs) {\n    vector<T> res = {1};\n    for (auto [p, exp] : prime_facs)\
    \ {\n        const int prev_layer = sz(res);\n        T coeff = 1;\n        for\
    \ (int i = 0; i < exp; i++) {\n            coeff *= p;\n            for (int j\
    \ = 0; j < prev_layer; j++) {\n                res.push_back(coeff * res[j]);\n\
    \            }\n        }\n    }\n    return res;\n}\n};\n"
  code: "#pragma once\n\nnamespace number_theory {\n\nvector<int> mn_fac, primes;\n\
    \nvoid sieve(int n) {\n    mn_fac.resize(n + 1);\n    for (int i = 2; i <= n;\
    \ i++) {\n        if (!mn_fac[i]) {\n            mn_fac[i] = i;\n            primes.push_back(i);\n\
    \            for (ll j = 1ll * i * i; j <= n; j += i) {\n                if (!mn_fac[j])\
    \ {\n                    mn_fac[j] = i;\n                }\n            }\n  \
    \      }\n    }\n}\n\ntemplate<class T> vector<pair<T, int>> factor(T num) {\n\
    \    vector<pair<T, int>> res;\n\n    if (num <= sz(mn_fac) - 1) {\n        while\
    \ (num > 1) {\n            int fac = mn_fac[num];\n            res.emplace_back(fac,\
    \ 0);\n            while (num % fac == 0) {\n                num /= fac;\n   \
    \             res.back().second++;\n            }\n        }\n        return res;\n\
    \    }\n\n    for (int p : primes) {\n        if (1ll * p * p > num) {\n     \
    \       break;\n        }\n        int exp = 0;\n        while (num % p == 0)\
    \ {\n            num /= p;\n            exp++;\n        }\n        if (exp) {\n\
    \            res.emplace_back(p, exp);\n        }\n    }\n    if (num > 1) {\n\
    \        res.emplace_back(num, 1);\n    }\n    return res;\n}\n\ntemplate<class\
    \ T> vector<T> gen_divisors(vector<pair<T, int>> prime_facs) {\n    vector<T>\
    \ res = {1};\n    for (auto [p, exp] : prime_facs) {\n        const int prev_layer\
    \ = sz(res);\n        T coeff = 1;\n        for (int i = 0; i < exp; i++) {\n\
    \            coeff *= p;\n            for (int j = 0; j < prev_layer; j++) {\n\
    \                res.push_back(coeff * res[j]);\n            }\n        }\n  \
    \  }\n    return res;\n}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/number_theory.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
documentation_of: numeric/number_theory.hpp
layout: document
redirect_from:
- /library/numeric/number_theory.hpp
- /library/numeric/number_theory.hpp.html
title: numeric/number_theory.hpp
---
