---
title: Centroid Decomposition
documentation_of: ./src/graphs/trees/centroid_decomposition.h
---

Decomposes tree into centroid hierarchy for efficient path queries and updates.

## Operations

- `CentroidDecomposition(g)`: Build centroid decomposition of tree `g`
- Access decomposition tree structure through public members

## Complexity

- Construction: $O(n \log n)$
- Space: $O(n)$

## Usage

{% raw %}
```cpp
vector<vector<int>> tree = {{1, 2}, {0, 3}, {0}, {1}};
CentroidDecomposition cd(tree);

// Use centroid tree for path queries
// Implementation depends on specific problem requirements
```
{% endraw %}

## Notes

Creates auxiliary tree where each node's centroid subtrees have size at most n/2. Useful for path queries in trees.
