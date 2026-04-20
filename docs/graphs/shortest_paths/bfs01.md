---
title: 0-1 BFS
documentation_of: ./src/graphs/shortest_paths/bfs01.h
---

Shortest paths on graphs with edge weights in $\{0, 1\}$ using a deque.

## Operations

- `bfs01(g, start)`: Return vector of shortest distances from `start`; `g[u]` stores `{neighbor, weight}` pairs with weight `0` or `1`

## Complexity

- Time: $O(V + E)$
- Space: $O(V)$

## Usage

{% raw %}
```cpp
vector<vector<pair<int, bool>>> g = {
  {{1, 0}, {2, 1}},
  {{3, 1}},
  {{3, 0}},
  {}
};

vector<int> dist = bfs01(g, 0);
```
{% endraw %}

## Notes

Weight-0 edges are pushed to the front of the deque, weight-1 edges to the back, preserving BFS layer order.
