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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ numeric/matrix.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/* A square matrix, used for applying linear transformations.\n * `operator*=`:\
    \ O(N^3)\n * `pow(matrix<T, N>, k)`: O(N^3 * log(k))\n */\n\n#pragma once\n#include\
    \ \"mod_int.hpp\"\n\ntemplate<class T, int N> struct matrix {\n    array<array<T,\
    \ N>, N> vals{};\n\n    matrix() {\n        for (int i = 0; i < N; i++) {\n  \
    \          vals[i][i] = 1;\n        }\n    }\n\n    array<T, N> &operator[](int\
    \ p) {\n        return vals[p];\n    }\n\n    friend matrix pow(matrix base, int\
    \ exp) {\n        matrix res;\n        while (exp) {\n            if (exp & 1)\
    \ {\n                res *= base;\n            }\n            base *= base;\n\
    \            exp >>= 1;\n        }\n        return res;\n    }\n\n    matrix &operator*=(matrix\
    \ b) {\n        array<array<T, N>, N> res{};\n        for (int i = 0; i < N; i++)\
    \ {\n            for (int j = 0; j < N; j++) {\n                for (int k = 0;\
    \ k < N; k++) {\n                    res[i][j] += vals[i][k] * b.vals[k][j];\n\
    \                }\n            }\n        }\n        vals = res;\n        return\
    \ *this;\n    }\n\n    friend matrix operator*(matrix a, matrix b) {\n       \
    \ return a *= b;\n    }\n};\n"
  dependsOn:
  - numeric/mod_int.hpp
  isVerificationFile: false
  path: numeric/matrix.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/matrix.hpp
layout: document
redirect_from:
- /library/numeric/matrix.hpp
- /library/numeric/matrix.hpp.html
title: numeric/matrix.hpp
---
