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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructures/hash_table.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/* A hash table using gnu pbds, with optional anti-hack hash function.\n\
    \ * `operator[]`: O(1), but expensive\n */\n\n#pragma once\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t x) {\n       \
    \ x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate<class K, class\
    \ V> using hash_table = __gnu_pbds::gp_hash_table<K, V, custom_hash>;\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/hash_table.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/hash_table.hpp
layout: document
redirect_from:
- /library/datastructures/hash_table.hpp
- /library/datastructures/hash_table.hpp.html
title: datastructures/hash_table.hpp
---
