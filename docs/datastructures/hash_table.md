---
title: Hash Table
documentation_of: ./src/datastructures/hash_table.h
---

Fast hash table using PBDS `gp_hash_table` with an anti-hash-attack custom hash, significantly faster than `std::unordered_map`.

## Operations

Template alias for `__gnu_pbds::gp_hash_table<T, U, CustomHash>`; all operations are inherited:
- `insert({key, value})`: Insert pair
- `find(key)`: Return iterator or `end()`
- `erase(key)`: Remove key
- `operator[](key)`: Access or insert

## Complexity

- Expected: $O(1)$ per operation
- Worst case: $O(n)$ per operation (made unlikely by the randomized hash)
- Space: $O(n)$

## Usage

```cpp
hash_table<int, string> ht;
ht.insert({42, "answer"});

auto it = ht.find(42);
if (it != ht.end()) {
  cout << it->second;
}

ht.erase(42);
```

## Notes

Hash seed is drawn from `chrono::steady_clock` at program start, so repeated runs use different hashes. Requires `<chrono>` (typically already included via the template).
