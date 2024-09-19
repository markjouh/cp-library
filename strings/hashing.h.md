---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"strings/hashing.h\"\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst ll H_MOD = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0,\
    \ H_MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nstruct Hash {\n    ll val;\n    int\
    \ len;\n\n    Hash(ll x, int y) : val(x), len(y) {}\n\n    Hash operator+(Hash\
    \ b) {\n        return Hash((__int128_t(val) * pow_b[b.len] + b.val) % H_MOD,\
    \ len + b.len);\n    }\n\n    bool operator==(Hash b) {\n        return val ==\
    \ b.val && len == b.len;\n    }\n};\n\nstruct StringHash {\n    int len;\n   \
    \ vector<ll> h;\n\n    template <class T>\n    StringHash(const T &s) : len(sz(s)),\
    \ h(len + 1) {\n        for (int i = 0; i < len; i++) {\n            h[i + 1]\
    \ = (__int128_t(h[i]) * H_BASE + s[i]) % H_MOD;\n        }\n        while (sz(pow_b)\
    \ <= len) {\n            pow_b.push_back(__int128_t(pow_b.back()) * H_BASE % H_MOD);\n\
    \        }\n    }\n\n    Hash get(int l, int r) {\n        r++;\n        return\
    \ Hash(((h[r] - __int128_t(h[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r -\
    \ l);\n    }\n\n    Hash get() {\n        return get(0, sz(h) - 1);\n    }\n};\n"
  code: "#pragma once\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst ll H_MOD = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0,\
    \ H_MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nstruct Hash {\n    ll val;\n    int\
    \ len;\n\n    Hash(ll x, int y) : val(x), len(y) {}\n\n    Hash operator+(Hash\
    \ b) {\n        return Hash((__int128_t(val) * pow_b[b.len] + b.val) % H_MOD,\
    \ len + b.len);\n    }\n\n    bool operator==(Hash b) {\n        return val ==\
    \ b.val && len == b.len;\n    }\n};\n\nstruct StringHash {\n    int len;\n   \
    \ vector<ll> h;\n\n    template <class T>\n    StringHash(const T &s) : len(sz(s)),\
    \ h(len + 1) {\n        for (int i = 0; i < len; i++) {\n            h[i + 1]\
    \ = (__int128_t(h[i]) * H_BASE + s[i]) % H_MOD;\n        }\n        while (sz(pow_b)\
    \ <= len) {\n            pow_b.push_back(__int128_t(pow_b.back()) * H_BASE % H_MOD);\n\
    \        }\n    }\n\n    Hash get(int l, int r) {\n        r++;\n        return\
    \ Hash(((h[r] - __int128_t(h[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r -\
    \ l);\n    }\n\n    Hash get() {\n        return get(0, sz(h) - 1);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: strings/hashing.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: strings/hashing.h
layout: document
redirect_from:
- /library/strings/hashing.h
- /library/strings/hashing.h.html
title: strings/hashing.h
---
