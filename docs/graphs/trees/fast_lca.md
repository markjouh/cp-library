---
title: Fast LCA
documentation_of: ./src/graphs/trees/fast_lca.h
---

LCA queries via Euler tour and sparse table RMQ on the depth array.

## Operations

- `FastLCA(g)`: Build from tree `g`, rooted at vertex `0`
- `lca(u, v)`: Lowest common ancestor of `u` and `v`
- `dist(u, v)`: Distance (number of edges) between `u` and `v`

## Complexity

- Construction: $O(n \log n)$
- Query: $O(1)$
- Space: $O(n \log n)$

## Usage

{% raw %}
```cpp
vector<vector<int>> g = {{1, 2}, {0, 3}, {0}, {1}};
FastLCA lca(g);

int a = lca.lca(2, 3);
int d = lca.dist(2, 3);
```
{% endraw %}

## Notes

Root is fixed at vertex `0`. Relabel the tree if a different root is needed.
