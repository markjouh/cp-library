---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: numeric/mod_int.hpp
    title: numeric/mod_int.hpp
  _extendedRequiredBy: []
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
    \ os << a.v;\n    }\n};\n#line 3 \"numeric/matrix.hpp\"\n\ntemplate<class T, int\
    \ N> struct matrix {\n    array<array<T, N>, N> vals{};\n\n    matrix() {\n  \
    \      for (int i = 0; i < N; i++) {\n            vals[i][i] = 1;\n        }\n\
    \    }\n\n    array<T, N> &operator[](int p) {\n        return vals[p];\n    }\n\
    \n    friend matrix pow(matrix base, int exp) {\n        matrix res;\n       \
    \ while (exp) {\n            if (exp & 1) {\n                res *= base;\n  \
    \          }\n            base *= base;\n            exp >>= 1;\n        }\n \
    \       return res;\n    }\n\n    matrix &operator*=(matrix b) {\n        array<array<T,\
    \ N>, N> res{};\n        for (int i = 0; i < N; i++) {\n            for (int j\
    \ = 0; j < N; j++) {\n                for (int k = 0; k < N; k++) {\n        \
    \            res[i][j] += vals[i][k] * b.vals[k][j];\n                }\n    \
    \        }\n        }\n        vals = res;\n        return *this;\n    }\n\n \
    \   friend matrix operator*(matrix a, matrix b) {\n        return a *= b;\n  \
    \  }\n};\n"
  code: "#pragma once\n#include \"mod_int.hpp\"\n\ntemplate<class T, int N> struct\
    \ matrix {\n    array<array<T, N>, N> vals{};\n\n    matrix() {\n        for (int\
    \ i = 0; i < N; i++) {\n            vals[i][i] = 1;\n        }\n    }\n\n    array<T,\
    \ N> &operator[](int p) {\n        return vals[p];\n    }\n\n    friend matrix\
    \ pow(matrix base, int exp) {\n        matrix res;\n        while (exp) {\n  \
    \          if (exp & 1) {\n                res *= base;\n            }\n     \
    \       base *= base;\n            exp >>= 1;\n        }\n        return res;\n\
    \    }\n\n    matrix &operator*=(matrix b) {\n        array<array<T, N>, N> res{};\n\
    \        for (int i = 0; i < N; i++) {\n            for (int j = 0; j < N; j++)\
    \ {\n                for (int k = 0; k < N; k++) {\n                    res[i][j]\
    \ += vals[i][k] * b.vals[k][j];\n                }\n            }\n        }\n\
    \        vals = res;\n        return *this;\n    }\n\n    friend matrix operator*(matrix\
    \ a, matrix b) {\n        return a *= b;\n    }\n};\n"
  dependsOn:
  - numeric/mod_int.hpp
  isVerificationFile: false
  path: numeric/matrix.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/matrix.hpp
layout: document
redirect_from:
- /library/numeric/matrix.hpp
- /library/numeric/matrix.hpp.html
title: numeric/matrix.hpp
---
