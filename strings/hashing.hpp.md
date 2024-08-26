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
  bundledCode: "#line 2 \"strings/hashing.hpp\"\n\nnamespace hashing {\n\nmt19937_64\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\n\nconst ll H_MOD\
    \ = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0, H_MOD)(rng);\n\
    \nvector<ll> pow_b = {1};\n\nstruct hash {\n    ll val;\n    int len;\n\n    hash(ll\
    \ x, int y) : val(x), len(y) {}\n\n    hash operator+(hash b) {\n        return\
    \ hash((__int128_t(val) * pow_b[b.len] + b.val) % H_MOD, len + b.len);\n    }\n\
    \n    bool operator==(hash b) {\n        return val == b.val && len == b.len;\n\
    \    }\n};\n\nstruct str_hash {\n    int len;\n    vector<ll> hashes;\n\n    template<class\
    \ T> str_hash(const T &s) : len(sz(s)), hashes(len + 1) {\n        for (int i\
    \ = 0; i < len; i++) {\n            hashes[i + 1] = (__int128_t(hashes[i]) * H_BASE\
    \ + s[i]) % H_MOD;\n        }\n        while (sz(pow_b) <= len) {\n          \
    \  pow_b.push_back(__int128_t(pow_b.back()) * H_BASE % H_MOD);\n        }\n  \
    \  }\n\n    hash get(int l, int r) {\n        return hash(((hashes[r] - __int128_t(hashes[l])\
    \ * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r - l);\n    }\n\n    hash get() {\n\
    \        return get(0, sz(hashes) - 1);\n    }\n};\n}\n"
  code: "#pragma once\n\nnamespace hashing {\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst ll H_MOD = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0,\
    \ H_MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nstruct hash {\n    ll val;\n    int\
    \ len;\n\n    hash(ll x, int y) : val(x), len(y) {}\n\n    hash operator+(hash\
    \ b) {\n        return hash((__int128_t(val) * pow_b[b.len] + b.val) % H_MOD,\
    \ len + b.len);\n    }\n\n    bool operator==(hash b) {\n        return val ==\
    \ b.val && len == b.len;\n    }\n};\n\nstruct str_hash {\n    int len;\n    vector<ll>\
    \ hashes;\n\n    template<class T> str_hash(const T &s) : len(sz(s)), hashes(len\
    \ + 1) {\n        for (int i = 0; i < len; i++) {\n            hashes[i + 1] =\
    \ (__int128_t(hashes[i]) * H_BASE + s[i]) % H_MOD;\n        }\n        while (sz(pow_b)\
    \ <= len) {\n            pow_b.push_back(__int128_t(pow_b.back()) * H_BASE % H_MOD);\n\
    \        }\n    }\n\n    hash get(int l, int r) {\n        return hash(((hashes[r]\
    \ - __int128_t(hashes[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r - l);\n\
    \    }\n\n    hash get() {\n        return get(0, sz(hashes) - 1);\n    }\n};\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: strings/hashing.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/hashing.hpp
layout: document
redirect_from:
- /library/strings/hashing.hpp
- /library/strings/hashing.hpp.html
title: strings/hashing.hpp
---
