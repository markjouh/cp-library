---
title: Sparse Segment Tree
documentation_of: ./src/datastructures/segment_tree/sparse_segtree.h
---

Segment tree for large coordinate ranges with dynamic node allocation.

## Operations

- `SparseSegtree(max_coord)`: Create for coordinate range `[0, max_coord)`
- `update(pos, val)`: Update position with value
- `query(l, r)`: Query range sum/operation

## Complexity

- All operations: $O(\log(\text{max\_coord}))$
- Space: $O(k \log(\text{max\_coord}))$ where $k$ is updates

## Usage

```cpp
SparseSegtree<ll> sparse_seg(1e9); // Large coordinate range

sparse_seg.update(1000000, 5);
sparse_seg.update(999999999, 10);

ll sum = sparse_seg.query(999999, 1000001);
```

## Notes

Only allocates nodes for accessed coordinates. Efficient for large coordinate ranges with sparse updates.

**Coordinate Compression**: While this uses dynamic allocation, for better cache performance with known coordinates, consider explicit coordinate compression where you map coordinates to dense indices `[0, k)` before using a regular segment tree.