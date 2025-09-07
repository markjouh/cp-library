---
title: Dual Fenwick Tree
documentation_of: ./src/datastructures/fenwick_tree/dual_fentree.h
---

Supports efficient range updates and point queries, dual to standard Fenwick tree.

## Operations

- `DualFentree(n)`: Construct with size `n`
- `add(r, v)`: Add `v` to all elements in `[0, r]`
- `add(l, r, v)`: Add `v` to all elements in `[l, r]`
- `sum(r)`: Get current value at position `r`
- `sum(l, r)`: Get sum of values in range `[l, r]`

## Complexity

- Construction: $O(n)$
- Update: $O(\log n)$
- Query: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
DualFentree<int> dft(n);

// Add 5 to range [2, 7]
dft.add(2, 7, 5);

// Get value at position 3
int value = dft.sum(3);

// Get range sum [1, 5]
int range_sum = dft.sum(1, 5);
```

## Notes

Uses two Fenwick trees for linear and constant components of range updates.