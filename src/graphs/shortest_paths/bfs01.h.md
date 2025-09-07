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
  bundledCode: "#line 1 \"src/graphs/shortest_paths/bfs01.h\"\nauto bfs01(const vector<vector<pair<int,\
    \ bool>>> &g, int start = 0) {\n  vector<int> dist(sz(g), INT_MAX / 2);\n\n  static\
    \ int dq[1 << 17];\n  int l = 1 << 16, r = l;\n\n  dist[start] = 0;\n  dq[l] =\
    \ start;\n\n  while (l <= r) {\n    int u = dq[l++];\n    for (auto [v, w] : g[u])\
    \ {\n      if (dist[u] + w < dist[v]) {\n        dist[v] = dist[u] + w;\n    \
    \    dq[w ? ++r : --l] = v;\n      }\n    }\n  }\n  return dist;\n}\n"
  code: "auto bfs01(const vector<vector<pair<int, bool>>> &g, int start = 0) {\n \
    \ vector<int> dist(sz(g), INT_MAX / 2);\n\n  static int dq[1 << 17];\n  int l\
    \ = 1 << 16, r = l;\n\n  dist[start] = 0;\n  dq[l] = start;\n\n  while (l <= r)\
    \ {\n    int u = dq[l++];\n    for (auto [v, w] : g[u]) {\n      if (dist[u] +\
    \ w < dist[v]) {\n        dist[v] = dist[u] + w;\n        dq[w ? ++r : --l] =\
    \ v;\n      }\n    }\n  }\n  return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/shortest_paths/bfs01.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/shortest_paths/bfs01.h
layout: document
title: 0-1 BFS
---

Shortest path algorithm for graphs with edge weights 0 or 1 using deque-based BFS.

## Operations

- `bfs01(g, start)`: Find shortest distances from `start` vertex

## Complexity

- Time: $O(V + E)$
- Space: $O(V)$

## Usage

{% raw %}
```cpp
// Graph with 0/1 weights: {destination, weight}
vector<vector<pair<int, int>>> g = {
  {{1, 0}, {2, 1}},
  {{3, 1}},
  {{3, 0}},
  {}
};

vector<int> dist = bfs01(g, 0);
```
{% endraw %}

## Notes

More efficient than Dijkstra for 0-1 weighted graphs. Uses deque to maintain optimal ordering.