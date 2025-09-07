---
title: Binary Trie
documentation_of: ./src/datastructures/binary_trie.h
---

Binary trie for efficient XOR queries and prefix operations on integers.

## Operations

- `BinaryTrie()`: Create empty trie
- `insert(x)`: Insert integer `x`
- `erase(x)`: Remove integer `x`
- `max_xor(x)`: Find maximum XOR with any element
- `min_xor(x)`: Find minimum XOR with any element

## Complexity

- All operations: $O(\log(\text{max\_value}))$ 
- Space: $O(k \log(\text{max\_value}))$ where $k$ is number of elements

## Usage

```cpp
BinaryTrie trie;
trie.insert(5);   // 101
trie.insert(3);   // 011
trie.insert(7);   // 111

int max_xor = trie.max_xor(2); // Max XOR with 010
int min_xor = trie.min_xor(2); // Min XOR with 010
```

## Notes

Builds tree structure based on binary representation. Efficient for XOR-related queries and bit manipulation problems.

**Bit Manipulation Details**: Processes integers bit by bit from most significant to least significant. For maximum XOR, at each level it tries to take the opposite bit path when possible. The trie depth is typically 30-32 levels for 32-bit integers, making operations effectively $O(30)$ in practice.