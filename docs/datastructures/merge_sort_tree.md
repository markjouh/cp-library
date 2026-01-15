---
title: Merge Sort Tree
documentation_of: ./src/datastructures/merge_sort_tree.h
---

Segment tree where each node contains an ordered set of elements in its range for order statistics queries.

## Operations

- `MergeSortTree<T>(arr)`: Construct from array
- `query(l, r, v)`: Count elements in `[l, r]` strictly less than `v`

## Complexity

- Construction: $O(n \log n)$
- Query: $O(\log^2 n)$
- Space: $O(n \log n)$

## Usage

```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9, 2};
MergeSortTree<int> mst(arr);

// Count elements in [1, 5] strictly less than 4
int count = mst.query(1, 5, 4);  // Returns 3 (elements: 1, 1, 2)

// Count elements in [0, 6] strictly less than 5
int count2 = mst.query(0, 6, 5);  // Returns 5
```

## Notes

Uses `ordered_set` with `(value, index)` pairs to handle duplicates. Each element appears in $O(\log n)$ nodes. Requires `ordered_set.h` include.
