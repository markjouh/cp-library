---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: src/verify/library_checker/number_theory/enumerate_primes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/numeric/sieve_factor.h\"\n/*\n|           | $\\max_{1\
    \ \\leq k \\leq n} \\tau(k)$ | $\\pi(n)$ |\n| --------- | --------------------------------\
    \ | -------- |\n| $10^1$    | 4                                | 4        |\n\
    | $10^2$    | 12                               | 25       |\n| $10^3$    | 32\
    \                               | 168      |\n| $10^4$    | 64               \
    \                | 1229     |\n| $10^5$    | 128                             \
    \ | 9592     |\n| $10^6$    | 240                              | 78498    |\n\
    | $10^7$    | 448                              | 664579   |\n| $10^8$    | 768\
    \                              | 5761455  |\n| $10^9$    | 1344              \
    \               | 50847534 |\n| $10^{10}$ | 2304                             |\
    \          |\n| $10^{11}$ | 4032                             |          |\n| $10^{12}$\
    \ | 6720                             |          |\n| $10^{13}$ | 10752       \
    \                     |          |\n| $10^{14}$ | 17280                      \
    \      |          |\n| $10^{15}$ | 26880                            |        \
    \  |\n| $10^{16}$ | 41472                            |          |\n| $10^{17}$\
    \ | 64512                            |          |\n| $10^{18}$ | 103680      \
    \                     |          |\n*/\n\nvector<int> mn_factor, primes;\n\nvoid\
    \ sieve(int n) {\n  mn_factor.resize(n + 1);\n  for (int i = 2; i <= n; i++) {\n\
    \    if (!mn_factor[i]) {\n      mn_factor[i] = i;\n      primes.push_back(i);\n\
    \      for (int64_t j = 1ll * i * i; j <= n; j += i) {\n        if (!mn_factor[j])\
    \ {\n          mn_factor[j] = i;\n        }\n      }\n    }\n  }\n}\n\ntemplate\
    \ <class T>\nauto factorize(T x) {\n  vector<pair<T, int>> res;\n\n  // O(log\
    \ x) if sieved up to x\n  if (x <= ssize(mn_factor) - 1) {\n    while (x > 1)\
    \ {\n      int y = mn_factor[x];\n      res.emplace_back(y, 0);\n      while (x\
    \ % y == 0) {\n        x /= y;\n        res.back().second++;\n      }\n    }\n\
    \    return res;\n  }\n\n  // O(sqrt x log x) otherwise, must have sieved to sqrt(x)\n\
    \  for (int p : primes) {\n    if (1ll * p * p > x) {\n      break;\n    }\n \
    \   int exp = 0;\n    while (x % p == 0) {\n      x /= p;\n      exp++;\n    }\n\
    \    if (exp) {\n      res.emplace_back(p, exp);\n    }\n  }\n  if (x > 1) {\n\
    \    res.emplace_back(x, 1);\n  }\n  return res;\n}\n\ntemplate <class T>\nauto\
    \ gen_divisors(T x) {\n  vector<T> res = {1};\n  for (auto [p, exp] : factorize(x))\
    \ {\n    const int old_size = ssize(res);\n    T coeff = 1;\n    for (int i =\
    \ 0; i < exp; i++) {\n      coeff *= p;\n      for (int j = 0; j < old_size; j++)\
    \ {\n        res.push_back(coeff * res[j]);\n      }\n    }\n  }\n  return res;\n\
    }\n"
  code: "/*\n|           | $\\max_{1 \\leq k \\leq n} \\tau(k)$ | $\\pi(n)$ |\n| ---------\
    \ | -------------------------------- | -------- |\n| $10^1$    | 4           \
    \                     | 4        |\n| $10^2$    | 12                         \
    \      | 25       |\n| $10^3$    | 32                               | 168    \
    \  |\n| $10^4$    | 64                               | 1229     |\n| $10^5$  \
    \  | 128                              | 9592     |\n| $10^6$    | 240        \
    \                      | 78498    |\n| $10^7$    | 448                       \
    \       | 664579   |\n| $10^8$    | 768                              | 5761455\
    \  |\n| $10^9$    | 1344                             | 50847534 |\n| $10^{10}$\
    \ | 2304                             |          |\n| $10^{11}$ | 4032        \
    \                     |          |\n| $10^{12}$ | 6720                       \
    \      |          |\n| $10^{13}$ | 10752                            |        \
    \  |\n| $10^{14}$ | 17280                            |          |\n| $10^{15}$\
    \ | 26880                            |          |\n| $10^{16}$ | 41472       \
    \                     |          |\n| $10^{17}$ | 64512                      \
    \      |          |\n| $10^{18}$ | 103680                           |        \
    \  |\n*/\n\nvector<int> mn_factor, primes;\n\nvoid sieve(int n) {\n  mn_factor.resize(n\
    \ + 1);\n  for (int i = 2; i <= n; i++) {\n    if (!mn_factor[i]) {\n      mn_factor[i]\
    \ = i;\n      primes.push_back(i);\n      for (int64_t j = 1ll * i * i; j <= n;\
    \ j += i) {\n        if (!mn_factor[j]) {\n          mn_factor[j] = i;\n     \
    \   }\n      }\n    }\n  }\n}\n\ntemplate <class T>\nauto factorize(T x) {\n \
    \ vector<pair<T, int>> res;\n\n  // O(log x) if sieved up to x\n  if (x <= ssize(mn_factor)\
    \ - 1) {\n    while (x > 1) {\n      int y = mn_factor[x];\n      res.emplace_back(y,\
    \ 0);\n      while (x % y == 0) {\n        x /= y;\n        res.back().second++;\n\
    \      }\n    }\n    return res;\n  }\n\n  // O(sqrt x log x) otherwise, must\
    \ have sieved to sqrt(x)\n  for (int p : primes) {\n    if (1ll * p * p > x) {\n\
    \      break;\n    }\n    int exp = 0;\n    while (x % p == 0) {\n      x /= p;\n\
    \      exp++;\n    }\n    if (exp) {\n      res.emplace_back(p, exp);\n    }\n\
    \  }\n  if (x > 1) {\n    res.emplace_back(x, 1);\n  }\n  return res;\n}\n\ntemplate\
    \ <class T>\nauto gen_divisors(T x) {\n  vector<T> res = {1};\n  for (auto [p,\
    \ exp] : factorize(x)) {\n    const int old_size = ssize(res);\n    T coeff =\
    \ 1;\n    for (int i = 0; i < exp; i++) {\n      coeff *= p;\n      for (int j\
    \ = 0; j < old_size; j++) {\n        res.push_back(coeff * res[j]);\n      }\n\
    \    }\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/numeric/sieve_factor.h
  requiredBy: []
  timestamp: '2025-09-14 12:12:28-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/number_theory/enumerate_primes.test.cpp
documentation_of: src/numeric/sieve_factor.h
layout: document
title: Sieve with Factorization
---

Sieve of Eratosthenes with prime factorization and divisor generation.

## Operations

- `sieve(n)`: Precompute primes and smallest prime factors up to `n`
- `factorize(x)`: Get prime factorization of `x` as vector of `(prime, exponent)` pairs
- `gen_divisors(x)`: Generate all divisors of `x`

## Global Variables

- `primes`: Vector of all primes up to `n`
- `mn_factor`: Vector where `mn_factor[i]` is the smallest prime factor of `i`

## Complexity

- `sieve`: $O(n \log \log n)$
- `factorize`: $O(\log x)$ if sieved up to `x`, $O(\sqrt{x} \log x)$ otherwise
- `gen_divisors`: $O(d(x))$ where $d(x)$ is the number of divisors
- Space: $O(n)$

## Usage

```cpp
sieve(100000);

// Check if prime
bool is_prime = (mn_factor[17] == 17);  // true

// Get prime factorization
auto factors = factorize(60);  // [(2, 2), (3, 1), (5, 1)] for 2^2 * 3 * 5

// Generate all divisors
auto divs = gen_divisors(12);  // [1, 2, 4, 3, 6, 12]
```

## Notes

Stores smallest prime factor for each number. Factorization extracts factors by repeatedly dividing by smallest factor. For numbers larger than sieved range, requires sieving up to $\sqrt{x}$.
