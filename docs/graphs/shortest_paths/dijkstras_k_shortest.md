---
title: K Shortest Paths using Modified Dijkstra
documentation_of: ./src/graphs/shortest_paths/dijkstras_k_shortest.h
---

Finds up to k shortest paths from source to all vertices using modified Dijkstra's algorithm.

## Operations

- `dijkstras_k_shortest<T>(g, k, start)`: Returns k shortest distances to each vertex

## Complexity

- Time: $O(k \times (V + E) \log V)$
- Space: $O(k \times V)$

## Usage

{% raw %}
```cpp
vector<vector<pair<int, int>>> g = {
  {{1, 1}, {2, 4}},
  {{2, 2}, {3, 5}},
  {{3, 1}},
  {}
};

auto distances = dijkstras_k_shortest<int>(g, 3, 0);

for (int v = 0; v < distances.size(); v++) {
  for (int dist : distances[v]) {
    cout << dist << " ";
  }
}
```
{% endraw %}

## Notes

Returns `distances[v]` with up to k shortest distances to vertex `v` in increasing order.