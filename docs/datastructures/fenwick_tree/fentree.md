---
title: Fenwick Tree (Binary Indexed Tree)
documentation_of: ./src/datastructures/fenwick_tree/fentree.h
---

Efficient point updates and prefix sum queries using binary indexed tree structure.

## Operations

- `Fentree(n)`: Construct with size `n` (zero-initialized)
- `Fentree(arr)`: Construct from array
- `add(p, v)`: Add value `v` to element at position `p`
- `sum(r)`: Get prefix sum from index `0` to `r`
- `sum(l, r)`: Get range sum from index `l` to `r`

## Complexity

- Construction: $O(n)$ from array, $O(1)$ zero-initialized
- Update: $O(\log n)$
- Query: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
// Create from array
vector<int> arr = {1, 3, 5, 7, 9};
Fentree<int> ft(arr);

// Add 5 to element at index 2
ft.add(2, 5);

// Get prefix sum [0, 3]
int prefix_sum = ft.sum(3);

// Get range sum [1, 4]
int range_sum = ft.sum(1, 4);
```

## Notes

Uses 1-based indexing internally. Each position stores sum of range determined by `lowbit(i)`.