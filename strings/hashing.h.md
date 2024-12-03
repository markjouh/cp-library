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
  bundledCode: "#line 1 \"strings/hashing.h\"\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst ll MOD = (1ll << 61) - 1;\nconst ll B = uniform_int_distribution<ll>(0,\
    \ MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nstruct hash_val {\n    ll val;\n  \
    \  int len;\n\n    hash_val(ll x, int y) : val(x), len(y) {}\n\n    hash_val operator+(hash_val\
    \ b) {\n        return hash_val((__int128_t(val) * pow_b[b.len] + b.val) % MOD,\
    \ len + b.len);\n    }\n\n    friend bool operator==(const hash_val a, const hash_val\
    \ b) {\n        return a.val == b.val && a.len == b.len;\n    }\n};\n\nstruct\
    \ hash_string {\n    int len;\n    vector<ll> h;\n\n    template <class T>\n \
    \   hash_string(const T &s) : len(sz(s)), h(len + 1) {\n        for (int i = 0;\
    \ i < len; i++) {\n            h[i + 1] = (__int128_t(h[i]) * B + s[i]) % MOD;\n\
    \        }\n        while (sz(pow_b) <= len) {\n            pow_b.push_back(__int128_t(pow_b.back())\
    \ * B % MOD);\n        }\n    }\n\n    hash_val get(int l, int r) {\n        assert(l\
    \ < ++r);\n        return hash_val(((h[r] - __int128_t(h[l]) * pow_b[r - l]) %\
    \ MOD + MOD) % MOD, r - l);\n    }\n\n    hash_val get() {\n        return get(0,\
    \ sz(h) - 2);\n    }\n};\n"
  code: "mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst ll MOD = (1ll << 61) - 1;\nconst ll B = uniform_int_distribution<ll>(0,\
    \ MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nstruct hash_val {\n    ll val;\n  \
    \  int len;\n\n    hash_val(ll x, int y) : val(x), len(y) {}\n\n    hash_val operator+(hash_val\
    \ b) {\n        return hash_val((__int128_t(val) * pow_b[b.len] + b.val) % MOD,\
    \ len + b.len);\n    }\n\n    friend bool operator==(const hash_val a, const hash_val\
    \ b) {\n        return a.val == b.val && a.len == b.len;\n    }\n};\n\nstruct\
    \ hash_string {\n    int len;\n    vector<ll> h;\n\n    template <class T>\n \
    \   hash_string(const T &s) : len(sz(s)), h(len + 1) {\n        for (int i = 0;\
    \ i < len; i++) {\n            h[i + 1] = (__int128_t(h[i]) * B + s[i]) % MOD;\n\
    \        }\n        while (sz(pow_b) <= len) {\n            pow_b.push_back(__int128_t(pow_b.back())\
    \ * B % MOD);\n        }\n    }\n\n    hash_val get(int l, int r) {\n        assert(l\
    \ < ++r);\n        return hash_val(((h[r] - __int128_t(h[l]) * pow_b[r - l]) %\
    \ MOD + MOD) % MOD, r - l);\n    }\n\n    hash_val get() {\n        return get(0,\
    \ sz(h) - 2);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: strings/hashing.h
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
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
