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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ numeric/mod_int.hpp: line 7: #pragma once found in a non-first line\n"
  code: "/* Type that performs arithmetic mod some large prime.\n * `operator$` for\
    \ $ in {+, -, *}: O(1)\n * `operator/`: O(log(MOD))\n * `pow(x, k)`: O(log(k))\n\
    \ */\n\n#pragma once\n\nconst int MOD = 1000000007;\n// const int MOD = 998244353;\n\
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
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/mod_int.hpp
layout: document
redirect_from:
- /library/numeric/mod_int.hpp
- /library/numeric/mod_int.hpp.html
title: numeric/mod_int.hpp
---
