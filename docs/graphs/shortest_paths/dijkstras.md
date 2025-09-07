---
title: Dijkstra's Shortest Path Algorithm
documentation_of: ./src/graphs/shortest_paths/dijkstras.h
---

Single-source shortest paths for weighted graphs with non-negative edge weights.

## Operations

- `dijkstras<T>(g, start)`: Returns `(distances, parent)` pair

## Complexity

- Time: $O((V + E) \log V)$
- Space: $O(V)$

## Usage

{% raw %}
```cpp
vector<vector<pair<int, int>>> g = {
  {{1, 4}, {2, 1}},
  {{3, 1}},
  {{1, 2}, {3, 5}},
  {}
};

auto [dist, parent] = dijkstras<int>(g, 0);

// Reconstruct path to vertex 3
vector<int> path;
int cur = 3;
while (cur != -1) {
  path.push_back(cur);
  cur = parent[cur];
}
reverse(path.begin(), path.end());
```
{% endraw %}

## Notes

Returns `numeric_limits<T>::max()` for unreachable vertices. Parent array has `-1` for source vertex.