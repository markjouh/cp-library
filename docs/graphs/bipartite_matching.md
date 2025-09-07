---
title: Bipartite Matching
documentation_of: ./src/graphs/bipartite_matching.h
---

Maximum matching in bipartite graphs using augmenting path algorithm.

## Operations

- `bipartite_matching(g, n_left, n_right)`: Find maximum matching
- Returns vector of matched pairs

## Complexity

- Time: $O(VE)$ 
- Space: $O(V)$

## Usage

```cpp
// Bipartite graph with left vertices [0, n_left) and right vertices [0, n_right)
vector<vector<int>> g(n_left);
g[left_vertex].push_back(right_vertex); // Add edge

auto matching = bipartite_matching(g, n_left, n_right);
int max_matching_size = matching.size();
```

## Notes

Uses DFS-based augmenting path search. Returns pairs `(left_vertex, right_vertex)` in maximum matching.