---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: verify/library_checker/number_theory/enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"numeric/sieve_factor.h\"\nvector<int> mn_factor, primes;\n\
    \nvoid sieve(int n) {\n    mn_factor.resize(n + 1);\n    for (int i = 2; i <=\
    \ n; i++) {\n        if (!mn_factor[i]) {\n            mn_factor[i] = i;\n   \
    \         primes.push_back(i);\n            for (ll j = 1ll * i * i; j <= n; j\
    \ += i) {\n                if (!mn_factor[j]) {\n                    mn_factor[j]\
    \ = i;\n                }\n            }\n        }\n    }\n}\n\ntemplate <class\
    \ T>\nauto factorize(T x) {\n    vector<pair<T, int>> res;\n\n    // O(log x)\
    \ if sieved up to x\n    if (x <= sz(mn_factor) - 1) {\n        while (x > 1)\
    \ {\n            int y = mn_factor[x];\n            res.emplace_back(y, 0);\n\
    \            while (x % y == 0) {\n                x /= y;\n                res.back().second++;\n\
    \            }\n        }\n        return res;\n    }\n\n    // O(sqrt x log x)\
    \ otherwise, must have sieved to sqrt(x)\n    for (int p : primes) {\n       \
    \ if (1ll * p * p > x) {\n            break;\n        }\n        int exp = 0;\n\
    \        while (x % p == 0) {\n            x /= p;\n            exp++;\n     \
    \   }\n        if (exp) {\n            res.emplace_back(p, exp);\n        }\n\
    \    }\n    if (x > 1) {\n        res.emplace_back(x, 1);\n    }\n    return res;\n\
    }\n\ntemplate <class T>\nauto gen_divisors(T x) {\n    vector<T> res = {1};\n\
    \    for (auto [p, exp] : factorize(x)) {\n        const int old_size = sz(res);\n\
    \        T coeff = 1;\n        for (int i = 0; i < exp; i++) {\n            coeff\
    \ *= p;\n            for (int j = 0; j < old_size; j++) {\n                res.push_back(coeff\
    \ * res[j]);\n            }\n        }\n    }\n    return res;\n}\n"
  code: "vector<int> mn_factor, primes;\n\nvoid sieve(int n) {\n    mn_factor.resize(n\
    \ + 1);\n    for (int i = 2; i <= n; i++) {\n        if (!mn_factor[i]) {\n  \
    \          mn_factor[i] = i;\n            primes.push_back(i);\n            for\
    \ (ll j = 1ll * i * i; j <= n; j += i) {\n                if (!mn_factor[j]) {\n\
    \                    mn_factor[j] = i;\n                }\n            }\n   \
    \     }\n    }\n}\n\ntemplate <class T>\nauto factorize(T x) {\n    vector<pair<T,\
    \ int>> res;\n\n    // O(log x) if sieved up to x\n    if (x <= sz(mn_factor)\
    \ - 1) {\n        while (x > 1) {\n            int y = mn_factor[x];\n       \
    \     res.emplace_back(y, 0);\n            while (x % y == 0) {\n            \
    \    x /= y;\n                res.back().second++;\n            }\n        }\n\
    \        return res;\n    }\n\n    // O(sqrt x log x) otherwise, must have sieved\
    \ to sqrt(x)\n    for (int p : primes) {\n        if (1ll * p * p > x) {\n   \
    \         break;\n        }\n        int exp = 0;\n        while (x % p == 0)\
    \ {\n            x /= p;\n            exp++;\n        }\n        if (exp) {\n\
    \            res.emplace_back(p, exp);\n        }\n    }\n    if (x > 1) {\n \
    \       res.emplace_back(x, 1);\n    }\n    return res;\n}\n\ntemplate <class\
    \ T>\nauto gen_divisors(T x) {\n    vector<T> res = {1};\n    for (auto [p, exp]\
    \ : factorize(x)) {\n        const int old_size = sz(res);\n        T coeff =\
    \ 1;\n        for (int i = 0; i < exp; i++) {\n            coeff *= p;\n     \
    \       for (int j = 0; j < old_size; j++) {\n                res.push_back(coeff\
    \ * res[j]);\n            }\n        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: numeric/sieve_factor.h
  requiredBy: []
  timestamp: '2024-10-25 20:01:05-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
documentation_of: numeric/sieve_factor.h
layout: document
redirect_from:
- /library/numeric/sieve_factor.h
- /library/numeric/sieve_factor.h.html
title: numeric/sieve_factor.h
---
