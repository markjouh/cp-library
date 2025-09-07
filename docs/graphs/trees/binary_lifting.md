---
title: Binary Lifting
documentation_of: ./src/trees/binary_lifting.h
---

Binary lifting for LCA queries and k-th ancestor queries in trees.

## Operations

- `BinaryLifting(g, root)`: Construct for tree `g` with given `root`
- `lca(u, v)`: Find lowest common ancestor of vertices `u` and `v`
- `kth_ancestor(u, k)`: Find k-th ancestor of vertex `u` (returns -1 if doesn't exist)

## Complexity

- Construction: $O(n \log n)$
- Query: $O(\log n)$
- Space: $O(n \log n)$

## Usage

{% raw %}
```cpp
vector<vector<int>> tree = {{1, 2}, {0, 3}, {0}, {1}};
BinaryLifting bl(tree, 0);

int ancestor = bl.lca(2, 3);
int kth_anc = bl.kth_ancestor(3, 2); // 2nd ancestor of vertex 3
```
{% endraw %}

## Notes

Precomputes 2^i-th ancestors for all vertices. Supports both LCA and k-th ancestor queries.