---
title: Hash Table
documentation_of: ./src/datastructures/hash_table.h
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