---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"strings/hashing.hpp\"\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst ll H_MOD = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0,\
    \ H_MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nusing mul_t = __int128_t;\n\nstruct\
    \ Hash {\n  ll val;\n  int len;\n\n  Hash(ll x, int y) : val(x), len(y) {}\n\n\
    \  Hash operator+(Hash b) {\n    return Hash((mul_t(val) * pow_b[b.len] + b.val)\
    \ % H_MOD, len + b.len);\n  }\n\n  bool operator==(Hash b) {\n    return val ==\
    \ b.val && len == b.len;\n  }\n};\n\nstruct StringHash {\n  int len;\n  vector<ll>\
    \ h;\n\n  template <class T>\n  StringHash(const T &s) : len(sz(s)), h(len + 1)\
    \ {\n    for (int i = 0; i < len; i++) {\n      h[i + 1] = (mul_t(h[i]) * H_BASE\
    \ + s[i]) % H_MOD;\n    }\n    while (sz(pow_b) <= len) {\n      pow_b.push_back(mul_t(pow_b.back())\
    \ * H_BASE % H_MOD);\n    }\n  }\n\n  Hash get(int l, int r) {\n    r++;\n   \
    \ return Hash(((h[r] - mul_t(h[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r\
    \ - l);\n  }\n\n  Hash get() {\n    return get(0, sz(h) - 1);\n  }\n};\n"
  code: "#pragma once\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst ll H_MOD = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0,\
    \ H_MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nusing mul_t = __int128_t;\n\nstruct\
    \ Hash {\n  ll val;\n  int len;\n\n  Hash(ll x, int y) : val(x), len(y) {}\n\n\
    \  Hash operator+(Hash b) {\n    return Hash((mul_t(val) * pow_b[b.len] + b.val)\
    \ % H_MOD, len + b.len);\n  }\n\n  bool operator==(Hash b) {\n    return val ==\
    \ b.val && len == b.len;\n  }\n};\n\nstruct StringHash {\n  int len;\n  vector<ll>\
    \ h;\n\n  template <class T>\n  StringHash(const T &s) : len(sz(s)), h(len + 1)\
    \ {\n    for (int i = 0; i < len; i++) {\n      h[i + 1] = (mul_t(h[i]) * H_BASE\
    \ + s[i]) % H_MOD;\n    }\n    while (sz(pow_b) <= len) {\n      pow_b.push_back(mul_t(pow_b.back())\
    \ * H_BASE % H_MOD);\n    }\n  }\n\n  Hash get(int l, int r) {\n    r++;\n   \
    \ return Hash(((h[r] - mul_t(h[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r\
    \ - l);\n  }\n\n  Hash get() {\n    return get(0, sz(h) - 1);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: strings/hashing.hpp
  requiredBy: []
  timestamp: '2024-09-01 01:23:14-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: strings/hashing.hpp
layout: document
redirect_from:
- /library/strings/hashing.hpp
- /library/strings/hashing.hpp.html
title: strings/hashing.hpp
---
