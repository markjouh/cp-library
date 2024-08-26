---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: numeric/matrix.hpp
    title: numeric/matrix.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/mod_int.hpp\"\n\nconst int MOD = 1000000007;\n//\
    \ const int MOD = 998244353;\n\nstruct mint {\n    int v;\n \n    mint(ll x =\
    \ 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n \n    friend\
    \ mint pow(mint base, int exp) {\n        mint res = 1;\n        while (exp) {\n\
    \            if (exp & 1) {\n                res *= base;\n            }\n   \
    \         base *= base;\n            exp >>= 1;\n        }\n        return res;\n\
    \    }\n \n    mint &operator+=(mint b) {\n        if ((v += b.v) >= MOD) {\n\
    \            v -= MOD;\n        }\n        return *this;\n    }\n \n    mint &operator-=(mint\
    \ b) {\n        if ((v -= b.v) < 0) {\n            v += MOD;\n        }\n    \
    \    return *this;\n    }\n \n    mint &operator*=(mint b) {\n        v = int(1ll\
    \ * v * b.v % MOD);\n        return *this;\n    }\n \n    mint &operator/=(mint\
    \ b) {\n        v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n\
    \    }\n \n    friend mint operator+(mint a, mint b) {\n        return a += b;\n\
    \    }\n \n    friend mint operator-(mint a, mint b) {\n        return a -= b;\n\
    \    }\n \n    friend mint operator*(mint a, mint b) {\n        return a *= b;\n\
    \    }\n \n    friend mint operator/(mint a, mint b) {\n        return a /= b;\n\
    \    }\n \n    friend ostream &operator<<(ostream &os, mint a) {\n        return\
    \ os << a.v;\n    }\n};\n"
  code: "#pragma once\n\nconst int MOD = 1000000007;\n// const int MOD = 998244353;\n\
    \nstruct mint {\n    int v;\n \n    mint(ll x = 0) : v(int(-MOD < x && x < MOD\
    \ ? x : x % MOD) + (x < 0) * MOD) {}\n \n    friend mint pow(mint base, int exp)\
    \ {\n        mint res = 1;\n        while (exp) {\n            if (exp & 1) {\n\
    \                res *= base;\n            }\n            base *= base;\n    \
    \        exp >>= 1;\n        }\n        return res;\n    }\n \n    mint &operator+=(mint\
    \ b) {\n        if ((v += b.v) >= MOD) {\n            v -= MOD;\n        }\n \
    \       return *this;\n    }\n \n    mint &operator-=(mint b) {\n        if ((v\
    \ -= b.v) < 0) {\n            v += MOD;\n        }\n        return *this;\n  \
    \  }\n \n    mint &operator*=(mint b) {\n        v = int(1ll * v * b.v % MOD);\n\
    \        return *this;\n    }\n \n    mint &operator/=(mint b) {\n        v =\
    \ int(1ll * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n    }\n \n \
    \   friend mint operator+(mint a, mint b) {\n        return a += b;\n    }\n \n\
    \    friend mint operator-(mint a, mint b) {\n        return a -= b;\n    }\n\
    \ \n    friend mint operator*(mint a, mint b) {\n        return a *= b;\n    }\n\
    \ \n    friend mint operator/(mint a, mint b) {\n        return a /= b;\n    }\n\
    \ \n    friend ostream &operator<<(ostream &os, mint a) {\n        return os <<\
    \ a.v;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/mod_int.hpp
  requiredBy:
  - numeric/matrix.hpp
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/mod_int.hpp
layout: document
redirect_from:
- /library/numeric/mod_int.hpp
- /library/numeric/mod_int.hpp.html
title: numeric/mod_int.hpp
---
