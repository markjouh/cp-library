---
title: Hash Table
documentation_of: ../../datastructures/hash_table.hpp
---

### Overview

A hash table faster than `unordered_map`, using `__gnu_pbds`. The optional custom hash function protects against anti-hash tests, which are generally only a consideration on Codeforces.

### Usage

* `operator[]`: Access a key to read from or update. $O(1)$
* `HashTable::find(x) != HashTable::end()`: Check if a key exists. $O(1)$