---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ strings/hashing.hpp: line 8: #pragma once found in a non-first line\n"
  code: "/* Hashes strings according to the scheme described in rng-58's blog.\n *\
    \ https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html\n\
    \ * `str_hash(S)`: O(|S|)\n * `str_hash::get(l, r)`: O(1), returns a hash object\n\
    \ * `hash`: An object representing a substring. Can be joined with `+` and compared\
    \ in O(1), but not split further.\n */\n\n#pragma once\n\nnamespace hashing {\n\
    \nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\n\
    const ll H_MOD = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0,\
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
  timestamp: '2024-08-26 11:12:12-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/hashing.hpp
layout: document
redirect_from:
- /library/strings/hashing.hpp
- /library/strings/hashing.hpp.html
title: strings/hashing.hpp
---
