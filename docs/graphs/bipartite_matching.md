---
title: Bipartite Matching
documentation_of: ./src/graphs/bipartite_matching.h
---

Maximum matching in bipartite graphs using augmenting path algorithm.

## Operations

- `bipartite_matching(ls_adj, rs_match)`: Find maximum matching, returns size of matching

## Complexity

- Time: $O(VE)$
- Space: $O(V)$

## Usage

```cpp
int n_left = 3, n_right = 4;
vector<vector<int>> ls_adj(n_left);  // Adjacency list for left vertices
vector<int> rs_match(n_right, -1);   // Must be initialized with -1s

// Add edges: left vertex -> right vertex
ls_adj[0].push_back(0);
ls_adj[0].push_back(1);
ls_adj[1].push_back(1);
ls_adj[2].push_back(2);

int matching_size = bipartite_matching(ls_adj, rs_match);

// rs_match[j] contains the left vertex matched to right vertex j (-1 if unmatched)
for (int j = 0; j < n_right; j++) {
  if (rs_match[j] != -1) {
    cout << rs_match[j] << " - " << j << endl;
  }
}
```

## Notes

Left and right parts use separate numbering `[0, n_left)` and `[0, n_right)`. The `rs_match` vector must be pre-allocated to `n_right` and initialized with `-1`s before calling.
