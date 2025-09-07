---
title: Lazily Propagated Segment Tree
documentation_of: ./src/datastructures/segment_tree/lazy_segtree.h
---

A segment tree with lazy propagation, supporting range updates and range queries in logarithmic time. It is highly generic, defined by user-provided functions for data aggregation and updates.

The template requires seven parameters to define its behavior:
- `T`: The type of data stored in the tree's nodes (e.g., `long long` for sums).
- `op`: A binary function `(T, T) -> T` that merges data from two child nodes. For range sum, this is addition; for range minimum, it is `min`.
- `t_id`: A function `() -> T` returning the identity for `op` (e.g., `0` for sum, infinity for `min`).
- `U`: The type representing a pending update. For a range-add query, `U` would be the type of the value being added (e.g., `long long`). For a range-set query, `U` would be the type of the value being set.
- `mapping`: A function `(T, U) -> T` that applies an update `U` to a data node `T`. For range-add, this would be `(current_sum, value_to_add) -> new_sum`.
- `comp`: A function `(U, U) -> U` that composes two pending updates. For range-add, if an "add 5" operation is pending and a new "add 3" arrives, this function combines them into an "add 8" operation.
- `u_id`: A function `() -> U` returning an update that does nothing. For range-add, this is `0`.

## Operations
- `LazySegtree(n)`: Constructs a tree of size `n`.
- `set(p, val)`: Sets the value at index `p` to `val`.
- `get(p)`: Retrieves the value at index `p`.
- `update(p, v)`: Applies an update `v` of type `U` to the element at index `p`.
- `update(l, r, v)`: Applies an update `v` of type `U` to the range `[l, r]`.
- `query(l, r)`: Queries the aggregated value over the range `[l, r]`.
- `query_all()`: Queries the aggregated value over the entire tree.
- `find_first(f)`: Finds the first index `i` for which `f(query(0, i))` is true.
- `find_last(f)`: Finds the last index `i` for which `f(query(i, n-1))` is true.

## Complexity
- Construction: $O(n)$
- All operations: $O(\log n)$
- Space: $O(n)$

## Usage
```cpp
// Example: Range Add, Range Sum
// T is long long, U is long long
auto op = [](long long a, long long b) { return a + b; };
auto t_id = []() { return 0LL; };
auto mapping = [](long long current_node_val, long long update_val) { 
  return current_node_val + update_val; 
};
auto comp = [](long long existing_lazy, long long new_lazy) { 
  return existing_lazy + new_lazy; 
};
auto u_id = []() { return 0LL; };

LazySegtree<long long, op, t_id, long long, mapping, comp, u_id> seg(n);
seg.update(2, 5, 5); // Add 5 to range [2, 5]
long long sum = seg.query(3, 7); // Get sum of range [3, 7]
```

## Notes
The pair `(T, op)` must form a monoid with `t_id` as the identity. The pair `(U, comp)` must form a monoid with `u_id` as the identity. The `mapping` function must distribute over `op`.
