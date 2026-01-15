---
title: Binary Lifting
documentation_of: ./src/graphs/trees/binary_lifting.h
---

Binary lifting for LCA queries and k-th ancestor queries in trees.

## Operations

- `BinaryLifting(g, root)`: Construct for tree `g` with given `root` (default: 0)
- `lca(x, y)`: Find lowest common ancestor of vertices `x` and `y`
- `anc(x, k)`: Find k-th ancestor of vertex `x` (returns -1 if doesn't exist)
- `dist(x, y)`: Find distance (number of edges) between vertices `x` and `y`

## Members

- `dep[u]`: Depth of vertex `u` (root has depth 0)
- `up[u][i]`: The $2^i$-th ancestor of vertex `u`

## Complexity

- Construction: $O(n \log n)$
- Query: $O(\log n)$
- Space: $O(n \log n)$

## Usage

{% raw %}
```cpp
vector<vector<int>> tree = {{1, 2}, {0, 3}, {0}, {1}};
BinaryLifting bl(tree, 0);

int ancestor = bl.lca(2, 3);     // LCA of vertices 2 and 3
int kth_anc = bl.anc(3, 2);      // 2nd ancestor of vertex 3
int d = bl.dist(2, 3);           // Distance between 2 and 3
```
{% endraw %}

## Notes

Precomputes $2^i$-th ancestors for all vertices using BFS from root.
