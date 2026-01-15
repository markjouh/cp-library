---
title: Sparse Segment Tree
documentation_of: ./src/datastructures/segment_tree/sparse_segtree.h
---

Segment tree for large coordinate ranges with dynamic node allocation.

## Operations

- `SparseSegtree<T, op, id>(n)`: Create for coordinate range `[0, n)`
- `set(pos, val)`: Set value at position `pos`
- `query(l, r)`: Query aggregate over range `[l, r]`

## Complexity

- All operations: $O(\log n)$
- Space: $O(k \log n)$ where $k$ is number of `set` operations

## Usage

```cpp
auto add = [](ll a, ll b) { return a + b; };
auto zero = []() { return 0LL; };

SparseSegtree<ll, add, zero> st(1e9);  // Large coordinate range

st.set(1000000, 5);
st.set(999999999, 10);

ll sum = st.query(999999, 1000001);
```

## Notes

Only allocates nodes for accessed coordinates. Efficient for large coordinate ranges with sparse updates. For better cache performance with known coordinates, consider coordinate compression with a regular segment tree.
