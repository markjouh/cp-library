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
    \ + (x < 0) * MOD) {}\n \n    friend Mint pow(Mint base, int exp) {\n        Mint\
    \ res = 1;\n        while (exp) {\n            if (exp & 1) res *= base;\n   \
    \         base *= base;\n            exp >>= 1;\n        }\n        return res;\n\
    \    }\n \n    Mint &operator+=(const Mint &b) { if ((v += b.v) >= MOD) v -= MOD;\
    \ return *this; }\n    Mint &operator-=(const Mint &b) { if ((v -= b.v) < 0) v\
    \ += MOD; return *this; }\n    Mint &operator*=(const Mint &b) { v = int(1ll *\
    \ v * b.v % MOD); return *this; }\n    Mint &operator/=(const Mint &b) { v = int(1ll\
    \ * v * pow(b, MOD - 2).v % MOD); return *this; }\n \n    Mint operator+(const\
    \ Mint &b) { return *this += b; }\n    Mint operator-(const Mint &b) { return\
    \ *this -= b; }\n    Mint operator*(const Mint &b) { return *this *= b; }\n  \
    \  Mint operator/(const Mint &b) { return *this /= b; }\n \n    friend ostream\
    \ &operator<<(ostream &os, const Mint &a) { return os << a.v; }\n};\n\n// using\
    \ mi = Mint<int(1e9 + 7)>;\n// using mi = Mint<998244353>;\n"
  code: "#pragma once\n\ntemplate <int MOD>\nstruct Mint {\n    int v;\n \n    Mint(ll\
    \ x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n \n \
    \   friend Mint pow(Mint base, int exp) {\n        Mint res = 1;\n        while\
    \ (exp) {\n            if (exp & 1) res *= base;\n            base *= base;\n\
    \            exp >>= 1;\n        }\n        return res;\n    }\n \n    Mint &operator+=(const\
    \ Mint &b) { if ((v += b.v) >= MOD) v -= MOD; return *this; }\n    Mint &operator-=(const\
    \ Mint &b) { if ((v -= b.v) < 0) v += MOD; return *this; }\n    Mint &operator*=(const\
    \ Mint &b) { v = int(1ll * v * b.v % MOD); return *this; }\n    Mint &operator/=(const\
    \ Mint &b) { v = int(1ll * v * pow(b, MOD - 2).v % MOD); return *this; }\n \n\
    \    Mint operator+(const Mint &b) { return *this += b; }\n    Mint operator-(const\
    \ Mint &b) { return *this -= b; }\n    Mint operator*(const Mint &b) { return\
    \ *this *= b; }\n    Mint operator/(const Mint &b) { return *this /= b; }\n \n\
    \    friend ostream &operator<<(ostream &os, const Mint &a) { return os << a.v;\
    \ }\n};\n\n// using mi = Mint<int(1e9 + 7)>;\n// using mi = Mint<998244353>;"
  dependsOn: []
  isVerificationFile: false
  path: numeric/mint.h
  requiredBy: []
  timestamp: '2024-09-23 12:38:14-04:00'
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
