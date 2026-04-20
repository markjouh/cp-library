---
title: 2D Fenwick Tree
documentation_of: ./src/datastructures/fenwick_tree/fentree_2d.h
---

Two-dimensional Fenwick tree for efficient point updates and rectangular range sum queries.

## Operations

- `Fentree2D(n, m)`: Construct `n × m` 2D Fenwick tree
- `add(r, c, v)`: Add value `v` to element at `(r, c)`
- `sum(r, c)`: Get prefix sum from `(0, 0)` to `(r, c)`
- `sum(r1, c1, r2, c2)`: Get sum of rectangle `(r1, c1)` to `(r2, c2)`

## Complexity

- Construction: $O(1)$
- Update: $O(\log n \log m)$
- Query: $O(\log n \log m)$
- Space: $O(nm)$

## Usage

```cpp
// Create 2D Fenwick tree
Fentree2D<int> ft2d(n, m);

// Add 5 to position (2, 3)
ft2d.add(2, 3, 5);

// Get rectangle sum from (1, 1) to (3, 3)
int rect_sum = ft2d.sum(1, 1, 3, 3);
```

## Notes

Uses vector of 1D Fenwick trees. Rectangle queries use inclusion-exclusion principle.