---
title: Centroid Decomposition
documentation_of: ./src/graphs/trees/centroid_decomposition.h
---

Recursive decomposition of a tree by centroids, producing a balanced auxiliary tree of depth $O(\log n)$.

## Operations

- `CentroidDecomp(g)`: Build centroid decomposition of tree `g`

## Members

- `root`: Root of the centroid tree
- `par[u]`: Parent of `u` in the centroid tree (`-1` for the root)
- `tree[u]`: Children of `u` in the centroid tree

## Complexity

- Construction: $O(n \log n)$
- Space: $O(n)$

## Usage

{% raw %}
```cpp
vector<vector<int>> g = {{1, 2}, {0, 3}, {0}, {1}};
CentroidDecomp cd(g);

int r = cd.root;
for (int v : cd.tree[r]) {
  // v is a child of r in the centroid tree
}
```
{% endraw %}

## Notes

Each subtree of the centroid tree has size at most half of its parent, so depth is $O(\log n)$. Used for divide-and-conquer on tree paths.
