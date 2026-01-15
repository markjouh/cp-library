---
title: Edmonds-Karp Maximum Flow
documentation_of: ./src/flow/edmonds_karp_max_flow.h
---

Maximum flow algorithm using Edmonds-Karp implementation with BFS to find augmenting paths.

## Operations

- `EdmondsKarpMaxFlow(n, s, t)`: Create flow network with `n` vertices, source `s`, sink `t`
- `add(u, v, cap)`: Add directed edge from `u` to `v` with capacity `cap` (default: `INT_MAX`)
- `max_flow()`: Compute and return maximum flow value

## Complexity

- Time: $O(VE^2)$
- Space: $O(V + E)$

## Usage

```cpp
int n = 4;
EdmondsKarpMaxFlow flow(n, 0, 3);  // source=0, sink=3

// Add edges with capacities
flow.add(0, 1, 10);
flow.add(0, 2, 5);
flow.add(1, 3, 8);
flow.add(2, 3, 10);

int result = flow.max_flow();  // returns 13
```

## Notes

Uses BFS to ensure shortest augmenting paths. Edges are stored in adjacency list format with reverse edges for residual graph.
