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
  bundledCode: "#line 2 \"numeric/mod_int.h\"\n\ntemplate <int MOD>\nstruct ModInt\
    \ {\n    int v;\n \n    ModInt(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x %\
    \ MOD) + (x < 0) * MOD) {}\n \n    friend ModInt pow(ModInt base, int exp) {\n\
    \        ModInt res = 1;\n        while (exp) {\n            if (exp & 1) {\n\
    \                res *= base;\n            }\n            base *= base;\n    \
    \        exp >>= 1;\n        }\n        return res;\n    }\n \n    ModInt &operator+=(ModInt\
    \ b) {\n        if ((v += b.v) >= MOD) {\n            v -= MOD;\n        }\n \
    \       return *this;\n    }\n \n    ModInt &operator-=(ModInt b) {\n        if\
    \ ((v -= b.v) < 0) {\n            v += MOD;\n        }\n        return *this;\n\
    \    }\n \n    ModInt &operator*=(ModInt b) {\n        v = int(1ll * v * b.v %\
    \ MOD);\n        return *this;\n    }\n \n    ModInt &operator/=(ModInt b) {\n\
    \        v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n\
    \    }\n \n    friend ModInt operator+(ModInt a, ModInt b) {\n        return a\
    \ += b;\n    }\n \n    friend ModInt operator-(ModInt a, ModInt b) {\n       \
    \ return a -= b;\n    }\n \n    friend ModInt operator*(ModInt a, ModInt b) {\n\
    \        return a *= b;\n    }\n \n    friend ModInt operator/(ModInt a, ModInt\
    \ b) {\n        return a /= b;\n    }\n \n    friend ostream &operator<<(ostream\
    \ &os, ModInt a) {\n        return os << a.v;\n    }\n};\n"
  code: "#pragma once\n\ntemplate <int MOD>\nstruct ModInt {\n    int v;\n \n    ModInt(ll\
    \ x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n \n \
    \   friend ModInt pow(ModInt base, int exp) {\n        ModInt res = 1;\n     \
    \   while (exp) {\n            if (exp & 1) {\n                res *= base;\n\
    \            }\n            base *= base;\n            exp >>= 1;\n        }\n\
    \        return res;\n    }\n \n    ModInt &operator+=(ModInt b) {\n        if\
    \ ((v += b.v) >= MOD) {\n            v -= MOD;\n        }\n        return *this;\n\
    \    }\n \n    ModInt &operator-=(ModInt b) {\n        if ((v -= b.v) < 0) {\n\
    \            v += MOD;\n        }\n        return *this;\n    }\n \n    ModInt\
    \ &operator*=(ModInt b) {\n        v = int(1ll * v * b.v % MOD);\n        return\
    \ *this;\n    }\n \n    ModInt &operator/=(ModInt b) {\n        v = int(1ll *\
    \ v * pow(b, MOD - 2).v % MOD);\n        return *this;\n    }\n \n    friend ModInt\
    \ operator+(ModInt a, ModInt b) {\n        return a += b;\n    }\n \n    friend\
    \ ModInt operator-(ModInt a, ModInt b) {\n        return a -= b;\n    }\n \n \
    \   friend ModInt operator*(ModInt a, ModInt b) {\n        return a *= b;\n  \
    \  }\n \n    friend ModInt operator/(ModInt a, ModInt b) {\n        return a /=\
    \ b;\n    }\n \n    friend ostream &operator<<(ostream &os, ModInt a) {\n    \
    \    return os << a.v;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: numeric/mod_int.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/ntl/power.test.cpp
documentation_of: numeric/mod_int.h
layout: document
redirect_from:
- /library/numeric/mod_int.h
- /library/numeric/mod_int.h.html
title: numeric/mod_int.h
---
