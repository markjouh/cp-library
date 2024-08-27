---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/associative_array.test.cpp
    title: verify/library_checker/data_structure/associative_array.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/hash_table.hpp\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t x) {\n       \
    \ x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate<class K, class\
    \ V> using hash_table = __gnu_pbds::gp_hash_table<K, V, custom_hash>;\n"
  code: "#pragma once\n#include <ext/pb_ds/assoc_container.hpp>\n\nstruct custom_hash\
    \ {\n    static uint64_t splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n\
    \        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27))\
    \ * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n    }\n\n    size_t operator()(uint64_t\
    \ x) const {\n        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate<class K,\
    \ class V> using hash_table = __gnu_pbds::gp_hash_table<K, V, custom_hash>;\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/hash_table.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/associative_array.test.cpp
documentation_of: datastructures/hash_table.hpp
layout: document
redirect_from:
- /library/datastructures/hash_table.hpp
- /library/datastructures/hash_table.hpp.html
title: datastructures/hash_table.hpp
---
