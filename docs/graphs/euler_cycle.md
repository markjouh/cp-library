---
title: Eulerian Cycle
documentation_of: ./src/graphs/euler_cycle.h
---

Find Eulerian cycle in undirected graphs using Hierholzer's algorithm.

## Operations

- `euler_cycle(g)`: Find Eulerian cycle starting from vertex 0
- Returns vector of vertices in cycle order

## Complexity

- Time: $O(V + E)$
- Space: $O(E)$

## Usage

{% raw %}
```cpp
// Undirected graph: edges listed from each endpoint
vector<vector<int>> g = {{1, 2}, {0, 2}, {0, 1}};  // Triangle
vector<int> cycle = euler_cycle(g);
// cycle = [0, 2, 1, 0] or similar valid Eulerian cycle

for (int v : cycle) {
  cout << v << " ";
}
```
{% endraw %}

## Notes

Input is an undirected graph where `g[u]` contains all neighbors of `u`. Each edge should appear in both adjacency lists. Requires all vertices to have even degree for an Eulerian cycle to exist.
