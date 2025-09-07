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
  bundledCode: "#line 1 \"src/graphs/topsort.h\"\nauto topsort(const vector<vector<int>>\
    \ &g) {\n  vector<int> deg(sz(g));\n  for (int u = 0; u < sz(g); u++) {\n    for\
    \ (int v : g[u]) {\n      deg[v]++;\n    }\n  }\n  queue<int> q;\n  for (int i\
    \ = 0; i < sz(g); i++) {\n    if (deg[i] == 0) {\n      q.push(i);\n    }\n  }\n\
    \  vector<int> res;\n  while (!q.empty()) {\n    int u = q.front();\n    q.pop();\n\
    \    res.push_back(u);\n    for (int v : g[u]) {\n      if (--deg[v] == 0) {\n\
    \        q.push(v);\n      }\n    }\n  }\n  return res;\n}\n"
  code: "auto topsort(const vector<vector<int>> &g) {\n  vector<int> deg(sz(g));\n\
    \  for (int u = 0; u < sz(g); u++) {\n    for (int v : g[u]) {\n      deg[v]++;\n\
    \    }\n  }\n  queue<int> q;\n  for (int i = 0; i < sz(g); i++) {\n    if (deg[i]\
    \ == 0) {\n      q.push(i);\n    }\n  }\n  vector<int> res;\n  while (!q.empty())\
    \ {\n    int u = q.front();\n    q.pop();\n    res.push_back(u);\n    for (int\
    \ v : g[u]) {\n      if (--deg[v] == 0) {\n        q.push(v);\n      }\n    }\n\
    \  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/topsort.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/topsort.h
layout: document
title: Topological Sort using Kahn's Algorithm
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