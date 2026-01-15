---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graphs/bipartite_matching.h\"\n// Left and right parts\
    \ should have separate numbering\n// ls_adj should contain the neighbors of the\
    \ left part\n// rs_match should be the size of the right part, and be initialized\
    \ with -1s\n\nbool find(int j, vector<vector<int>> &ls_adj, vector<int> &rs_match,\
    \ vector<int> &vis) {\n  if (rs_match[j] == -1) {\n    return 1;\n  }\n  vis[j]\
    \ = 1;\n  int di = rs_match[j];\n  for (int e : ls_adj[di]) {\n    if (!vis[e]\
    \ && find(e, ls_adj, rs_match, vis)) {\n      rs_match[e] = di;\n      return\
    \ 1;\n    }\n  }\n  return 0;\n}\n\nint bipartite_matching(vector<vector<int>>\
    \ &ls_adj, vector<int> &rs_match) {\n  vector<int> vis;\n  for (int i = 0; i <\
    \ ssize(ls_adj); i++) {\n    vis.assign(ssize(rs_match), 0);\n    for (int j :\
    \ ls_adj[i]) {\n      if (find(j, ls_adj, rs_match, vis)) {\n        rs_match[j]\
    \ = i;\n        break;\n      }\n    }\n  }\n  return ssize(rs_match) - count(all(rs_match),\
    \ -1);\n}\n"
  code: "// Left and right parts should have separate numbering\n// ls_adj should\
    \ contain the neighbors of the left part\n// rs_match should be the size of the\
    \ right part, and be initialized with -1s\n\nbool find(int j, vector<vector<int>>\
    \ &ls_adj, vector<int> &rs_match, vector<int> &vis) {\n  if (rs_match[j] == -1)\
    \ {\n    return 1;\n  }\n  vis[j] = 1;\n  int di = rs_match[j];\n  for (int e\
    \ : ls_adj[di]) {\n    if (!vis[e] && find(e, ls_adj, rs_match, vis)) {\n    \
    \  rs_match[e] = di;\n      return 1;\n    }\n  }\n  return 0;\n}\n\nint bipartite_matching(vector<vector<int>>\
    \ &ls_adj, vector<int> &rs_match) {\n  vector<int> vis;\n  for (int i = 0; i <\
    \ ssize(ls_adj); i++) {\n    vis.assign(ssize(rs_match), 0);\n    for (int j :\
    \ ls_adj[i]) {\n      if (find(j, ls_adj, rs_match, vis)) {\n        rs_match[j]\
    \ = i;\n        break;\n      }\n    }\n  }\n  return ssize(rs_match) - count(all(rs_match),\
    \ -1);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/bipartite_matching.h
  requiredBy: []
  timestamp: '2026-01-15 15:27:11+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/bipartite_matching.h
layout: document
title: Bipartite Matching
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
