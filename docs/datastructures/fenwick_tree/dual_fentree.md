---
title: Range Add Range Sum Fenwick Tree
documentation_of: ./src/datastructures/fenwick_tree/dual_fentree.h
---

Fenwick tree supporting range add and range sum queries, implemented with two BITs.

## Operations

- `DualFentree(n)`: Construct size `n`, zero-initialized
- `add(r, v)`: Add `v` to every element in `[0, r]`
- `add(l, r, v)`: Add `v` to every element in `[l, r]`
- `sum(r)`: Prefix sum over `[0, r]`
- `sum(l, r)`: Range sum over `[l, r]`

## Complexity

- All operations: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
DualFentree<long long> ft(n);

ft.add(2, 5, 3);          // add 3 to a[2..5]
long long s = ft.sum(1, 4);  // sum of a[1..4]
```

## Notes

Uses two Fenwick trees to decompose range updates into prefix contributions, one linear in the index and one constant. Despite the name, this is not a "point-query" dual — it supports both range updates and range sum queries.
