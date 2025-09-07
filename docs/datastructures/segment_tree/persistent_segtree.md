---
title: Persistent Segment Tree
documentation_of: ./src/datastructures/segment_tree/persistent_segtree.h
---

Persistent segment tree supporting queries on previous versions with structural sharing.

## Operations

- `PersistentSegtree(n)`: Create initial version
- `set(version, pos, val)`: Create new version with updated position
- `query(version, l, r)`: Query range in specific version

## Complexity

- All operations: $O(\log n)$
- Space per version: $O(\log n)$ additional nodes

## Usage

```cpp
auto op = [](int a, int b) { return a + b; };
auto id = []() { return 0; };
PersistentSegtree<int, op, id> pst(n);

int v1 = pst.set(0, pos1, val1);  // Create version 1
int v2 = pst.set(v1, pos2, val2); // Create version 2

int sum_v1 = pst.query(v1, l, r); // Query version 1
int sum_v2 = pst.query(v2, l, r); // Query version 2
```

## Notes

Creates new tree nodes only for changed parts. Enables time-travel queries on data structure state.

**Memory Management**: Uses path copying - only nodes along the path from root to modified leaf are duplicated. With $k$ updates, total space is $O(n + k \log n)$. For memory efficiency with many versions, consider node pooling or garbage collection of unreferenced versions.