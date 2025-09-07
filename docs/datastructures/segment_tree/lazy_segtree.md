---
title: Lazy Propagation Segment Tree
documentation_of: ./src/datastructures/segment_tree/lazy_segtree.h
---

Segment tree with lazy propagation for efficient range updates and range queries.

## Operations

- `LazySegtree<T, op, id, F, mapping, composition>(n)`: Construct with size `n`
- `set(p, val)`: Set element at position `p` to `val`
- `get(p)`: Get element at position `p`
- `query(l, r)`: Query range `[l, r]`
- `apply(p, f)`: Apply function `f` to element at `p`
- `apply(l, r, f)`: Apply function `f` to range `[l, r]`

## Complexity

- Construction: $O(n)$
- All operations: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
// Range add, range sum
auto op = [](ll a, ll b) { return a + b; };
auto e = []() { return 0LL; };
auto mapping = [](ll f, ll x) { return f + x; };
auto composition = [](ll f, ll g) { return f + g; };

LazySegtree<ll, op, e, ll, mapping, composition> seg(n);
seg.apply(l, r, add_val); // Add add_val to range [l, r]
ll sum = seg.query(l, r);  // Get sum of range [l, r]
```

## Notes

Requires monoid for data and composition of update functions. Supports both point and range operations.