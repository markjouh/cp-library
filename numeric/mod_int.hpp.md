---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/ntl/power.test.cpp
    title: verify/aizu/ntl/power.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/mod_int.hpp\"\n\ntemplate<int MOD> struct mod_int\
    \ {\n    int v;\n \n    mod_int(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x\
    \ % MOD) + (x < 0) * MOD) {}\n \n    friend mod_int pow(mod_int base, int exp)\
    \ {\n        mod_int res = 1;\n        while (exp) {\n            if (exp & 1)\
    \ {\n                res *= base;\n            }\n            base *= base;\n\
    \            exp >>= 1;\n        }\n        return res;\n    }\n \n    mod_int\
    \ &operator+=(mod_int b) {\n        if ((v += b.v) >= MOD) {\n            v -=\
    \ MOD;\n        }\n        return *this;\n    }\n \n    mod_int &operator-=(mod_int\
    \ b) {\n        if ((v -= b.v) < 0) {\n            v += MOD;\n        }\n    \
    \    return *this;\n    }\n \n    mod_int &operator*=(mod_int b) {\n        v\
    \ = int(1ll * v * b.v % MOD);\n        return *this;\n    }\n \n    mod_int &operator/=(mod_int\
    \ b) {\n        v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n\
    \    }\n \n    friend mod_int operator+(mod_int a, mod_int b) {\n        return\
    \ a += b;\n    }\n \n    friend mod_int operator-(mod_int a, mod_int b) {\n  \
    \      return a -= b;\n    }\n \n    friend mod_int operator*(mod_int a, mod_int\
    \ b) {\n        return a *= b;\n    }\n \n    friend mod_int operator/(mod_int\
    \ a, mod_int b) {\n        return a /= b;\n    }\n \n    friend ostream &operator<<(ostream\
    \ &os, mod_int a) {\n        return os << a.v;\n    }\n};\n"
  code: "#pragma once\n\ntemplate<int MOD> struct mod_int {\n    int v;\n \n    mod_int(ll\
    \ x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n \n \
    \   friend mod_int pow(mod_int base, int exp) {\n        mod_int res = 1;\n  \
    \      while (exp) {\n            if (exp & 1) {\n                res *= base;\n\
    \            }\n            base *= base;\n            exp >>= 1;\n        }\n\
    \        return res;\n    }\n \n    mod_int &operator+=(mod_int b) {\n       \
    \ if ((v += b.v) >= MOD) {\n            v -= MOD;\n        }\n        return *this;\n\
    \    }\n \n    mod_int &operator-=(mod_int b) {\n        if ((v -= b.v) < 0) {\n\
    \            v += MOD;\n        }\n        return *this;\n    }\n \n    mod_int\
    \ &operator*=(mod_int b) {\n        v = int(1ll * v * b.v % MOD);\n        return\
    \ *this;\n    }\n \n    mod_int &operator/=(mod_int b) {\n        v = int(1ll\
    \ * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n    }\n \n    friend\
    \ mod_int operator+(mod_int a, mod_int b) {\n        return a += b;\n    }\n \n\
    \    friend mod_int operator-(mod_int a, mod_int b) {\n        return a -= b;\n\
    \    }\n \n    friend mod_int operator*(mod_int a, mod_int b) {\n        return\
    \ a *= b;\n    }\n \n    friend mod_int operator/(mod_int a, mod_int b) {\n  \
    \      return a /= b;\n    }\n \n    friend ostream &operator<<(ostream &os, mod_int\
    \ a) {\n        return os << a.v;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/mod_int.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:00:53-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/ntl/power.test.cpp
documentation_of: numeric/mod_int.hpp
layout: document
redirect_from:
- /library/numeric/mod_int.hpp
- /library/numeric/mod_int.hpp.html
title: numeric/mod_int.hpp
---
