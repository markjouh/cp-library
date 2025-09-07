---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/graph/shortest_path.test.cpp
    title: src/verify/library_checker/graph/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graphs/shortest_paths/dijkstras.h\"\ntemplate <class\
    \ T>\nauto dijkstras(const vector<vector<pair<int, int>>> &g, int start = 0) {\n\
    \  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\
    \n  vector<T> dist(sz(g), numeric_limits<T>::max());\n  vector<int> from(sz(g),\
    \ -1);\n\n  dist[start] = 0;\n  pq.emplace(0, start);\n\n  while (sz(pq)) {\n\
    \    auto [d, u] = pq.top();\n    pq.pop();\n    if (d != dist[u]) {\n      continue;\n\
    \    }\n    for (auto [v, w] : g[u]) {\n      if (d + w < dist[v]) {\n       \
    \ dist[v] = d + w;\n        from[v] = u;\n        pq.emplace(dist[v], v);\n  \
    \    }\n    }\n  }\n  return make_pair(dist, from);\n}\n"
  code: "template <class T>\nauto dijkstras(const vector<vector<pair<int, int>>> &g,\
    \ int start = 0) {\n  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> pq;\n\n  vector<T> dist(sz(g), numeric_limits<T>::max());\n  vector<int>\
    \ from(sz(g), -1);\n\n  dist[start] = 0;\n  pq.emplace(0, start);\n\n  while (sz(pq))\
    \ {\n    auto [d, u] = pq.top();\n    pq.pop();\n    if (d != dist[u]) {\n   \
    \   continue;\n    }\n    for (auto [v, w] : g[u]) {\n      if (d + w < dist[v])\
    \ {\n        dist[v] = d + w;\n        from[v] = u;\n        pq.emplace(dist[v],\
    \ v);\n      }\n    }\n  }\n  return make_pair(dist, from);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/shortest_paths/dijkstras.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/graph/shortest_path.test.cpp
documentation_of: src/graphs/shortest_paths/dijkstras.h
layout: document
title: Dijkstra's Shortest Path Algorithm
---

Single-source shortest paths for weighted graphs with non-negative edge weights.

## Operations

- `dijkstras<T>(g, start)`: Returns `(distances, parent)` pair

## Complexity

- Time: $O((V + E) \log V)$
- Space: $O(V)$

## Usage

{% raw %}
```cpp
vector<vector<pair<int, int>>> g = {
  {{1, 4}, {2, 1}},
  {{3, 1}},
  {{1, 2}, {3, 5}},
  {}
};

auto [dist, parent] = dijkstras<int>(g, 0);

// Reconstruct path to vertex 3
vector<int> path;
int cur = 3;
while (cur != -1) {
  path.push_back(cur);
  cur = parent[cur];
}
reverse(path.begin(), path.end());
```
{% endraw %}

## Notes

Returns `numeric_limits<T>::max()` for unreachable vertices. Parent array has `-1` for source vertex.