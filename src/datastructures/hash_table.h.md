---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/associative_array.test.cpp
    title: src/verify/library_checker/data_structure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/hash_table.h\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nstruct CustomHash {\n  static uint64_t splitmix64(uint64_t x) {\n    x += 0x9e3779b97f4a7c15;\n\
    \    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return x ^ (x >> 31);\n  }\n\n  size_t operator()(uint64_t x) const {\n \
    \   static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return splitmix64(x + FIXED_RANDOM);\n  }\n};\n\ntemplate <class T, class\
    \ U>\nusing hash_table = __gnu_pbds::gp_hash_table<T, U, CustomHash>;\n"
  code: "#include <ext/pb_ds/assoc_container.hpp>\n\nstruct CustomHash {\n  static\
    \ uint64_t splitmix64(uint64_t x) {\n    x += 0x9e3779b97f4a7c15;\n    x = (x\
    \ ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return x ^ (x >> 31);\n  }\n\n  size_t operator()(uint64_t x) const {\n \
    \   static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return splitmix64(x + FIXED_RANDOM);\n  }\n};\n\ntemplate <class T, class\
    \ U>\nusing hash_table = __gnu_pbds::gp_hash_table<T, U, CustomHash>;"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/hash_table.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/associative_array.test.cpp
  - src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
documentation_of: src/datastructures/hash_table.h
layout: document
title: Hash Table
---

Custom hash table implementation with open addressing for competitive programming.

## Operations

- `HashTable()`: Create empty hash table
- `insert(key, value)`: Insert key-value pair
- `find(key)`: Find value associated with key
- `erase(key)`: Remove key from table

## Complexity

- Average case: $O(1)$ for all operations
- Worst case: $O(n)$ for all operations
- Space: $O(n)$

## Usage

```cpp
HashTable<int, string> ht;
ht.insert(42, "answer");
ht.insert(13, "lucky");

auto result = ht.find(42);
if (result != ht.end()) {
  cout << result->second; // "answer"
}

ht.erase(13);
```

## Notes

Uses open addressing with linear probing. Designed for competitive programming with predictable performance characteristics.