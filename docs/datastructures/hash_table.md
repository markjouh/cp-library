---
title: Hash Table
documentation_of: ./src/datastructures/hash_table.h
---

A fast hash table implementation using the Policy-Based Data Structures (PBDS) library's `gp_hash_table`. It is significantly faster than `std::unordered_map`.

A custom hash function is included to protect against anti-hash attacks, making it a safe choice for competitive programming platforms like Codeforces.

## Operations

- `HashTable()`: Create empty hash table
- `insert(key, value)`: Insert key-value pair
- `find(key)`: Find value associated with key
- `erase(key)`: Remove key from table

## Complexity

- Average case: $O(1)$ for all operations
- Worst case: $O(n)$ for all operations (made unlikely by the custom hash function)
- Space: $O(n)$

## Usage

```cpp
#include "datastructures/hash_table.h"
#include <iostream>
#include <string>

int main() {
    HashTable<int, std::string> ht;
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

The underlying implementation is `gp_hash_table` from `ext/pb_ds/assoc_container.hpp`. The custom hash function ensures reliable performance.
