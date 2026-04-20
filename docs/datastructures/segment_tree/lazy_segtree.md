---
title: Lazily Propagated Segment Tree
documentation_of: ./src/datastructures/segment_tree/lazy_segtree.h
---

Segment tree with lazy propagation supporting range updates and range queries.

## Template Parameters

- `T`: Node value type
- `op`: Associative merge `(T, T) -> T`
- `t_id`: `() -> T` identity for `op`
- `U`: Lazy update type
- `mapping`: Apply update to a node, `(T, U) -> T`
- `comp`: Compose updates (old, new), `(U, U) -> U`
- `u_id`: `() -> U` identity for `comp`

## Operations

- `LazySegtree(n, v = t_id())`: Construct size `n` filled with `v`
- `LazySegtree(arr)`: Construct from array
- `set(p, v)`: Set element at `p` to `v`
- `get(p)`: Return element at `p`
- `update(p, v)`: Apply update `v` at index `p`
- `update(l, r, v)`: Apply update `v` to `[l, r]`
- `query(l, r)`: Aggregate over `[l, r]`
- `query_all()`: Aggregate over the full range
- `find_first(f)`: Smallest `i` such that `f(query(0, i))` is true, or `n`
- `find_last(f)`: Largest `i` such that `f(query(i, n - 1))` is true, or `-1`

## Complexity

- Construction: $O(n)$
- All other operations: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
// Range add, range sum
auto op = [](long long a, long long b) { return a + b; };
auto t_id = []() { return 0LL; };
auto mapping = [](long long x, long long u) { return x + u; };
auto comp = [](long long a, long long b) { return a + b; };
auto u_id = []() { return 0LL; };

LazySegtree<long long, op, t_id, long long, mapping, comp, u_id> st(n);
st.update(2, 5, 5);
long long s = st.query(3, 7);
```

## Notes

`(T, op, t_id)` and `(U, comp, u_id)` must form monoids, and `mapping` must distribute over `op`.
