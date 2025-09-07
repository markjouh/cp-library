---
title: Merge Sort Tree
documentation_of: ./src/datastructures/merge_sort_tree.h
---

Segment tree where each node contains ordered set of elements in its range for order statistics queries.

## Operations

- `MergeSortTree(arr)`: Construct from array
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

// Count elements in [1, 5] less than 4
int count = mst.query(1, 5, 4); // Returns 2

// Update element at position 2
mst.set(2, 7);
```

## Notes

Uses ordered_set with element-index pairs to handle duplicates. Extra log factor from set operations.

**Memory Optimization**: The $O(n \log n)$ space bound comes from each element appearing in $O(\log n)$ nodes. For large datasets, consider using a persistent segment tree with coordinate compression, or offline processing with a sweep line to reduce memory usage.