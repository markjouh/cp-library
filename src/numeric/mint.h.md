---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/numeric/mint.h\"\ntemplate <int MOD>\nstruct Mint {\n\
    \  int v;\n\n  Mint(int64_t x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD)\
    \ + (x < 0) * MOD) {}\n \n  friend Mint pow(Mint base, int64_t exp) {\n    Mint\
    \ res = 1;\n    while (exp) {\n      if (exp & 1) {\n        res *= base;\n  \
    \    }\n      base *= base;\n      exp >>= 1;\n    }\n    return res;\n  }\n\n\
    \  Mint &operator+=(Mint b) {\n    v = v + b.v - (v + b.v >= MOD) * MOD;\n   \
    \ return *this;\n  }\n  Mint &operator-=(Mint b) {\n    v = v - b.v + (v < b.v)\
    \ * MOD;\n    return *this;\n  }\n  Mint &operator*=(Mint b) {\n    v = int(1ll\
    \ * v * b.v % MOD);\n    return *this;\n  }\n  Mint &operator/=(Mint b) {\n  \
    \  v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n    return *this;\n  }\n  friend\
    \ Mint operator+(Mint a, Mint b) {\n    return a += b;\n  }\n  friend Mint operator-(Mint\
    \ a, Mint b) {\n    return a -= b;\n  }\n  friend Mint operator*(Mint a, Mint\
    \ b) {\n    return a *= b;\n  }\n  friend Mint operator/(Mint a, Mint b) {\n \
    \   return a /= b;\n  }\n  friend ostream &operator<<(ostream &os, Mint a) {\n\
    \    return os << a.v;\n  }\n};\n\n// using mi = Mint<int(1e9 + 7)>;\n// using\
    \ mi = Mint<998244353>;\n\n// vector<mi> fact, inv_fact;\n\n// void gen_fact(int\
    \ n) {\n//   fact.resize(n + 1);\n//   inv_fact.resize(n + 1);\n//   fact[0] =\
    \ fact[1] = inv_fact[0] = inv_fact[1] = 1;\n//   for (int i = 2; i <= n; i++)\
    \ {\n//     fact[i] = fact[i - 1] * i;\n//   }\n//   inv_fact[n] = 1 / fact[n];\n\
    //   for (int i = n - 1; i >= 2; i--) {\n//     inv_fact[i] = inv_fact[i + 1]\
    \ * (i + 1);\n//   }\n// }\n\n// mi nck(int n, int k) {\n//   if (n < k || k <\
    \ 0) {\n//     return 0;\n//   }\n//   return fact[n] * inv_fact[k] * inv_fact[n\
    \ - k];\n// }\n"
  code: "template <int MOD>\nstruct Mint {\n  int v;\n\n  Mint(int64_t x = 0) : v(int(-MOD\
    \ < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n \n  friend Mint pow(Mint\
    \ base, int64_t exp) {\n    Mint res = 1;\n    while (exp) {\n      if (exp &\
    \ 1) {\n        res *= base;\n      }\n      base *= base;\n      exp >>= 1;\n\
    \    }\n    return res;\n  }\n\n  Mint &operator+=(Mint b) {\n    v = v + b.v\
    \ - (v + b.v >= MOD) * MOD;\n    return *this;\n  }\n  Mint &operator-=(Mint b)\
    \ {\n    v = v - b.v + (v < b.v) * MOD;\n    return *this;\n  }\n  Mint &operator*=(Mint\
    \ b) {\n    v = int(1ll * v * b.v % MOD);\n    return *this;\n  }\n  Mint &operator/=(Mint\
    \ b) {\n    v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n    return *this;\n \
    \ }\n  friend Mint operator+(Mint a, Mint b) {\n    return a += b;\n  }\n  friend\
    \ Mint operator-(Mint a, Mint b) {\n    return a -= b;\n  }\n  friend Mint operator*(Mint\
    \ a, Mint b) {\n    return a *= b;\n  }\n  friend Mint operator/(Mint a, Mint\
    \ b) {\n    return a /= b;\n  }\n  friend ostream &operator<<(ostream &os, Mint\
    \ a) {\n    return os << a.v;\n  }\n};\n\n// using mi = Mint<int(1e9 + 7)>;\n\
    // using mi = Mint<998244353>;\n\n// vector<mi> fact, inv_fact;\n\n// void gen_fact(int\
    \ n) {\n//   fact.resize(n + 1);\n//   inv_fact.resize(n + 1);\n//   fact[0] =\
    \ fact[1] = inv_fact[0] = inv_fact[1] = 1;\n//   for (int i = 2; i <= n; i++)\
    \ {\n//     fact[i] = fact[i - 1] * i;\n//   }\n//   inv_fact[n] = 1 / fact[n];\n\
    //   for (int i = n - 1; i >= 2; i--) {\n//     inv_fact[i] = inv_fact[i + 1]\
    \ * (i + 1);\n//   }\n// }\n\n// mi nck(int n, int k) {\n//   if (n < k || k <\
    \ 0) {\n//     return 0;\n//   }\n//   return fact[n] * inv_fact[k] * inv_fact[n\
    \ - k];\n// }"
  dependsOn: []
  isVerificationFile: false
  path: src/numeric/mint.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numeric/mint.h
layout: document
redirect_from:
- /library/src/numeric/mint.h
- /library/src/numeric/mint.h.html
title: src/numeric/mint.h
---
