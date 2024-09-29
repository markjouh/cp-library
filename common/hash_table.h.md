---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/associative_array.test.cpp
    title: verify/library_checker/data_structure/associative_array.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"common/hash_table.h\"\n\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nstruct CustomHash {\n    static uint64_t splitmix64(uint64_t x) {\n        x\
    \ += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate <class T, class\
    \ U>\nusing HashTable = __gnu_pbds::gp_hash_table<T, U, CustomHash>;\n"
  code: "#pragma once\n\n#include <ext/pb_ds/assoc_container.hpp>\n\nstruct CustomHash\
    \ {\n    static uint64_t splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n\
    \        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27))\
    \ * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n    }\n\n    size_t operator()(uint64_t\
    \ x) const {\n        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate <class T,\
    \ class U>\nusing HashTable = __gnu_pbds::gp_hash_table<T, U, CustomHash>;"
  dependsOn: []
  isVerificationFile: false
  path: common/hash_table.h
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/library_checker/data_structure/associative_array.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
documentation_of: common/hash_table.h
layout: document
redirect_from:
- /library/common/hash_table.h
- /library/common/hash_table.h.html
title: common/hash_table.h
---
