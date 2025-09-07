---
title: Kosaraju's Algorithm for Strongly Connected Components
documentation_of: ./src/graphs/kosaraju_scc.h
---

Finds strongly connected components in directed graphs using two DFS passes.

## Operations

- `KosarajuScc(g)`: Constructor computing SCCs for adjacency list `g`
- `sccs`: Number of strongly connected components
- `comp[u]`: Component ID of vertex `u`
- `members[i]`: Vertices in component `i`
- `cg[i]`: Adjacency list of component `i` in condensation graph

## Complexity

- Time: $O(V + E)$
- Space: $O(V + E)$

## Usage

```cpp
vector<vector<int>> g = {{1}, {2}, {0, 3}, {}};
KosarajuScc scc(g);

for (int i = 0; i < g.size(); i++) {
  cout << "Vertex " << i << " in component " << scc.comp[i] << endl;
}

for (int i = 0; i < scc.sccs; i++) {
  for (int v : scc.members[i]) {
  cout << v << " ";
  }
}
```

## Notes

Components numbered in reverse topological order. Condensation graph automatically built with duplicate edges removed.