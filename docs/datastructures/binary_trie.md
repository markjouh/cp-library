---
title: Binary Trie
documentation_of: ./src/datastructures/binary_trie.h
---

Binary trie for efficient XOR queries on integers with global XOR filter support.

## Operations

- `BinaryTrie<T>()`: Create empty trie for type `T`
- `insert(x, v=1)`: Add `v` to count of integer `x` (use `v=-1` to remove)
- `min_xor(x)`: Find minimum XOR of `x` with any element in trie
- `max_xor(x)`: Find maximum XOR of `x` with any element in trie
- `operator^=(x)`: Apply global XOR filter to all elements

## Complexity

- All operations: $O(W)$ where $W$ is bit width of type `T`
- Space: $O(k \cdot W)$ where $k$ is number of unique elements

## Usage

```cpp
BinaryTrie<int> trie;
trie.insert(5);   // Add 5
trie.insert(3);   // Add 3
trie.insert(7);   // Add 7

int mn = trie.min_xor(2);  // Min XOR with 2
int mx = trie.max_xor(2);  // Max XOR with 2

trie.insert(5, -1);  // Remove one occurrence of 5

trie ^= 4;  // XOR all elements by 4 (lazy, O(1))
```

## Notes

Bit width `W` is `sizeof(T) * 8` (32 for `int`, 64 for `long long`). The `^=` operator applies a lazy XOR filter without modifying the trie structure.
