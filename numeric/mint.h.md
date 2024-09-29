---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/ntl/power.test.cpp
    title: verify/aizu/ntl/power.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/mint.h\"\n\ntemplate <int MOD>\nstruct Mint {\n\
    \    int v;\n \n    Mint(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD)\
    \ + (x < 0) * MOD) {}\n \n    friend Mint pow(Mint base, ll exp) {\n        Mint\
    \ res = 1;\n        while (exp) {\n            if (exp & 1) {\n              \
    \  res *= base;\n            }\n            base *= base;\n            exp >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    Mint &operator+=(Mint b) {\n\
    \        v = v + b.v - (v + b.v >= MOD) * MOD;\n        return *this;\n    }\n\
    \    Mint &operator-=(Mint b) {\n        v = v - b.v + (v < b.v) * MOD;\n    \
    \    return *this;\n    }\n    Mint &operator*=(Mint b) {\n        v = int(1ll\
    \ * v * b.v % MOD);\n        return *this;\n    }\n    Mint &operator/=(Mint b)\
    \ {\n        v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n\
    \    }\n    friend Mint operator+(Mint a, Mint b) {\n        return a += b;\n\
    \    }\n    friend Mint operator-(Mint a, Mint b) {\n        return a -= b;\n\
    \    }\n    friend Mint operator*(Mint a, Mint b) {\n        return a *= b;\n\
    \    }\n    friend Mint operator/(Mint a, Mint b) {\n        return a /= b;\n\
    \    }\n    friend ostream &operator<<(ostream &os, Mint a) {\n        return\
    \ os << a.v;\n    }\n};\n\n// using mi = Mint<int(1e9 + 7)>;\n// using mi = Mint<998244353>;\n"
  code: "#pragma once\n\ntemplate <int MOD>\nstruct Mint {\n    int v;\n \n    Mint(ll\
    \ x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n \n \
    \   friend Mint pow(Mint base, ll exp) {\n        Mint res = 1;\n        while\
    \ (exp) {\n            if (exp & 1) {\n                res *= base;\n        \
    \    }\n            base *= base;\n            exp >>= 1;\n        }\n       \
    \ return res;\n    }\n\n    Mint &operator+=(Mint b) {\n        v = v + b.v -\
    \ (v + b.v >= MOD) * MOD;\n        return *this;\n    }\n    Mint &operator-=(Mint\
    \ b) {\n        v = v - b.v + (v < b.v) * MOD;\n        return *this;\n    }\n\
    \    Mint &operator*=(Mint b) {\n        v = int(1ll * v * b.v % MOD);\n     \
    \   return *this;\n    }\n    Mint &operator/=(Mint b) {\n        v = int(1ll\
    \ * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n    }\n    friend Mint\
    \ operator+(Mint a, Mint b) {\n        return a += b;\n    }\n    friend Mint\
    \ operator-(Mint a, Mint b) {\n        return a -= b;\n    }\n    friend Mint\
    \ operator*(Mint a, Mint b) {\n        return a *= b;\n    }\n    friend Mint\
    \ operator/(Mint a, Mint b) {\n        return a /= b;\n    }\n    friend ostream\
    \ &operator<<(ostream &os, Mint a) {\n        return os << a.v;\n    }\n};\n\n\
    // using mi = Mint<int(1e9 + 7)>;\n// using mi = Mint<998244353>;"
  dependsOn: []
  isVerificationFile: false
  path: numeric/mint.h
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/ntl/power.test.cpp
documentation_of: numeric/mint.h
layout: document
redirect_from:
- /library/numeric/mint.h
- /library/numeric/mint.h.html
title: numeric/mint.h
---
