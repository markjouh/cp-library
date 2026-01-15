---
title: Merge Sort Tree
documentation_of: ./src/datastructures/merge_sort_tree.h
---

Segment tree where each node contains an ordered set of elements in its range for order statistics queries with point updates.

## Operations

- `MergeSortTree<T>(arr)`: Construct from array
- `query(l, r, v)`: Count elements in `[l, r]` strictly less than `v`
- `set(p, v)`: Update element at position `p` to value `v`

## Complexity

- Construction: $O(n \log^2 n)$
- Query: $O(\log^2 n)$
- Update: $O(\log^2 n)$
- Space: $O(n \log n)$

## Usage

```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9, 2};
MergeSortTree<int> mst(arr);

// Count elements in [1, 5] strictly less than 4
int count = mst.query(1, 5, 4);  // Returns 2

// Update element at position 2
mst.set(2, 0);  // Change arr[2] from 4 to 0
```

## Notes

Uses PBDS `ordered_set` with `(value, index)` pairs to handle duplicates and enable O(log n) insertions/deletions per node. Requires `ordered_set.h` include.
