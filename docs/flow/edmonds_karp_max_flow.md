---
title: Edmonds-Karp Maximum Flow
documentation_of: ./src/flow/edmonds_karp_max_flow.h
---

Maximum flow algorithm using Edmonds-Karp implementation with BFS to find augmenting paths.

## Operations

- `edmonds_karp(capacity, source, sink)`: Find maximum flow from source to sink
- Returns maximum flow value

## Complexity

- Time: $O(VE^2)$
- Space: $O(V^2)$ for capacity matrix

## Usage

```cpp
int n = 4; // number of vertices
vector<vector<int>> capacity(n, vector<int>(n, 0));

// Add edges with capacities
capacity[0][1] = 10;
capacity[0][2] = 5;
capacity[1][3] = 8;
capacity[2][3] = 10;

int max_flow = edmonds_karp(capacity, 0, 3); // source=0, sink=3
```

## Notes

Uses BFS to ensure shortest augmenting paths. Modifies capacity matrix during execution to track residual graph.