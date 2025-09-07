---
title: Fast LCA (Lowest Common Ancestor)
documentation_of: ./src/trees/fast_lca.h
---

Fast LCA queries using sparse table with $O(1)$ query time after linear preprocessing.

## Operations

- `FastLCA(g, root)`: Construct for tree `g` with given `root`
- `lca(u, v)`: Find lowest common ancestor of vertices `u` and `v`

## Complexity

- Construction: $O(n \log n)$
- Query: $O(1)$
- Space: $O(n \log n)$

## Usage

{% raw %}
```cpp
vector<vector<int>> tree = {{1, 2}, {0, 3}, {0}, {1}};
FastLCA lca_solver(tree, 0);

int ancestor = lca_solver.lca(2, 3);
```
{% endraw %}

## Notes

Uses Euler tour and sparse table for RMQ. Requires tree structure (connected, acyclic graph).

**Sparse Table Optimization**: The implementation uses a sparse table on the depth array from Euler tour traversal. The sparse table is built in $O(n \log n)$ with $O(1)$ RMQ queries using the fact that `min(a, b) = a` if `depth[a] <= depth[b]`, enabling overlap-safe range minimum queries.