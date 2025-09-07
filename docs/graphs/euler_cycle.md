---
title: Eulerian Cycle
documentation_of: ./src/graphs/euler_cycle.h
---

Find Eulerian cycle/path in directed graphs using Hierholzer's algorithm.

## Operations

- `euler_cycle(g)`: Find Eulerian cycle starting from vertex 0
- Returns vector of vertices in cycle order

## Complexity

- Time: $O(V + E)$
- Space: $O(E)$

## Usage

{% raw %}
```cpp
vector<vector<int>> g = {{1}, {2}, {0}};
vector<int> cycle = euler_cycle(g);

if (!cycle.empty()) {
  // Found Eulerian cycle
  for (int v : cycle) {
  cout << v << " ";
  }
}
```
{% endraw %}

## Notes

Requires all vertices with nonzero degree to have equal in-degree and out-degree. Returns empty vector if no cycle exists.