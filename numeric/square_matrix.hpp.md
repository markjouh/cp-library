---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/square_matrix.hpp\"\n\ntemplate<class T, int N>\
    \ struct sq_matrix {\n    array<array<T, N>, N> vals{};\n\n    sq_matrix() {\n\
    \        for (int i = 0; i < N; i++) {\n            vals[i][i] = 1;\n        }\n\
    \    }\n\n    array<T, N> &operator[](int p) {\n        return vals[p];\n    }\n\
    \n    friend sq_matrix pow(sq_matrix base, int exp) {\n        sq_matrix res;\n\
    \        while (exp) {\n            if (exp & 1) {\n                res *= base;\n\
    \            }\n            base *= base;\n            exp >>= 1;\n        }\n\
    \        return res;\n    }\n\n    sq_matrix &operator*=(sq_matrix b) {\n    \
    \    array<array<T, N>, N> res{};\n        for (int i = 0; i < N; i++) {\n   \
    \         for (int j = 0; j < N; j++) {\n                for (int k = 0; k < N;\
    \ k++) {\n                    res[i][j] += vals[i][k] * b.vals[k][j];\n      \
    \          }\n            }\n        }\n        vals = res;\n        return *this;\n\
    \    }\n\n    friend sq_matrix operator*(sq_matrix a, sq_matrix b) {\n       \
    \ return a *= b;\n    }\n};\n"
  code: "#pragma once\n\ntemplate<class T, int N> struct sq_matrix {\n    array<array<T,\
    \ N>, N> vals{};\n\n    sq_matrix() {\n        for (int i = 0; i < N; i++) {\n\
    \            vals[i][i] = 1;\n        }\n    }\n\n    array<T, N> &operator[](int\
    \ p) {\n        return vals[p];\n    }\n\n    friend sq_matrix pow(sq_matrix base,\
    \ int exp) {\n        sq_matrix res;\n        while (exp) {\n            if (exp\
    \ & 1) {\n                res *= base;\n            }\n            base *= base;\n\
    \            exp >>= 1;\n        }\n        return res;\n    }\n\n    sq_matrix\
    \ &operator*=(sq_matrix b) {\n        array<array<T, N>, N> res{};\n        for\
    \ (int i = 0; i < N; i++) {\n            for (int j = 0; j < N; j++) {\n     \
    \           for (int k = 0; k < N; k++) {\n                    res[i][j] += vals[i][k]\
    \ * b.vals[k][j];\n                }\n            }\n        }\n        vals =\
    \ res;\n        return *this;\n    }\n\n    friend sq_matrix operator*(sq_matrix\
    \ a, sq_matrix b) {\n        return a *= b;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/square_matrix.hpp
  requiredBy: []
  timestamp: '2024-08-27 00:00:53-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/square_matrix.hpp
layout: document
redirect_from:
- /library/numeric/square_matrix.hpp
- /library/numeric/square_matrix.hpp.html
title: numeric/square_matrix.hpp
---
