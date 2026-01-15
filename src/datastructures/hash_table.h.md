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
  - src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - src/verify/library_checker/data_structure/associative_array.test.cpp
documentation_of: src/datastructures/hash_table.h
layout: document
title: Hash Table
---

A fast hash table implementation using the Policy-Based Data Structures (PBDS) library's `gp_hash_table`. It is significantly faster than `std::unordered_map`.

A custom hash function is included to protect against anti-hash attacks, making it a safe choice for competitive programming platforms like Codeforces.

## Operations

- `hash_table()`: Create empty hash table (typedef for `__gnu_pbds::gp_hash_table`)
- `insert(key, value)`: Insert key-value pair (inherited from `gp_hash_table`)
- `find(key)`: Find value associated with key (inherited from `gp_hash_table`)
- `erase(key)`: Remove key from table (inherited from `gp_hash_table`)
- `operator[]`: Access element (inherited from `gp_hash_table`)

## Complexity

- Average case: $O(1)$ for all operations
- Worst case: $O(n)$ for all operations (made unlikely by the custom hash function)
- Space: $O(n)$

## Usage

Note: To use this header, you may need to include `<chrono>` in your source file for the custom hash function to compile properly.

```cpp
#include "datastructures/hash_table.h"
#include <iostream>
#include <string>
#include <chrono> // Required for hash function

int main() {
    hash_table<int, std::string> ht;
    ht.insert(42, "answer");
    ht.insert(13, "lucky");

    auto it = ht.find(42);
    if (it != ht.end()) {
        std::cout << it->second << std::endl; // "answer"
    }

    ht.erase(13);

    if (ht.find(13) == ht.end()) {
        std::cout << "13 not found" << std::endl;
    }

    return 0;
}
```

## Notes

The underlying implementation is `gp_hash_table` from `ext/pb_ds/assoc_container.hpp`. The custom hash function ensures reliable performance. This is implemented as a template alias, so all methods available in `gp_hash_table` are also available in `hash_table`.
