---
title: Topological Sort using Kahn's Algorithm
documentation_of: ./src/graphs/topsort.h
---

Topological sorting using Kahn's algorithm with in-degree counting for cycle detection.

## Operations

- `topsort(g)`: Returns vertices in topological order

## Complexity

- Time: $O(V + E)$
- Space: $O(V)$

## Usage

{% raw %}
```cpp
vector<vector<int>> g = {{1, 2}, {3}, {3}, {}};
vector<int> order = topsort(g);

// Check if ordering is complete (no cycles)
if (order.size() == g.size()) {
  cout << "Valid DAG" << endl;
} else {
  cout << "Graph contains cycles" << endl;
}
```
{% endraw %}

## Notes

Returns partial ordering if graph contains cycles. Uses BFS with zero in-degree vertices.