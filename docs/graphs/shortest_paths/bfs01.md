---
title: 0-1 BFS
documentation_of: ./src/graphs/shortest_paths/bfs01.h
---

Shortest path algorithm for graphs with edge weights 0 or 1 using deque-based BFS.

## Operations

- `bfs01(g, start)`: Find shortest distances from `start` vertex

## Complexity

- Time: $O(V + E)$
- Space: $O(V)$

## Usage

{% raw %}
```cpp
// Graph with 0/1 weights: {destination, weight}
vector<vector<pair<int, int>>> g = {
  {{1, 0}, {2, 1}},
  {{3, 1}},
  {{3, 0}},
  {}
};

vector<int> dist = bfs01(g, 0);
```
{% endraw %}

## Notes

More efficient than Dijkstra for 0-1 weighted graphs. Uses deque to maintain optimal ordering.