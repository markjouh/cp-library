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
  bundledCode: "#line 1 \"src/graphs/euler_cycle.h\"\nauto euler_cycle(const vector<vector<int>>\
    \ &g) {\n  vector<vector<pair<int, int>>> h(sz(g));\n  vector<int> deg(sz(g));\n\
    \  int cnt = 0;\n  for (int u = 0; u < sz(g); u++) {\n    int self = 0;\n    for\
    \ (int v : g[u]) {\n      if ((u == v && self % 2) || u < v) {\n        h[u].emplace_back(v,\
    \ cnt);\n        h[v].emplace_back(u, cnt);\n        deg[u]++, deg[v]++;\n   \
    \     cnt++;\n      }\n      self += u == v;\n    }\n  }\n\n  vector<bool> removed(cnt);\n\
    \  vector<int> stk, res;\n  stk.push_back(0);\n  while (sz(stk)) {\n    int u\
    \ = stk.back();\n    if (deg[u] == 0) {\n      res.push_back(u);\n      stk.pop_back();\n\
    \    } else {\n      while (removed[h[u].back().second]) {\n        h[u].pop_back();\n\
    \      }\n      auto [v, idx] = h[u].back();\n      h[u].pop_back();\n\n     \
    \ deg[u]--, deg[v]--;\n      removed[idx] = true;\n\n      stk.push_back(v);\n\
    \    }\n  }\n  return res;\n}\n"
  code: "auto euler_cycle(const vector<vector<int>> &g) {\n  vector<vector<pair<int,\
    \ int>>> h(sz(g));\n  vector<int> deg(sz(g));\n  int cnt = 0;\n  for (int u =\
    \ 0; u < sz(g); u++) {\n    int self = 0;\n    for (int v : g[u]) {\n      if\
    \ ((u == v && self % 2) || u < v) {\n        h[u].emplace_back(v, cnt);\n    \
    \    h[v].emplace_back(u, cnt);\n        deg[u]++, deg[v]++;\n        cnt++;\n\
    \      }\n      self += u == v;\n    }\n  }\n\n  vector<bool> removed(cnt);\n\
    \  vector<int> stk, res;\n  stk.push_back(0);\n  while (sz(stk)) {\n    int u\
    \ = stk.back();\n    if (deg[u] == 0) {\n      res.push_back(u);\n      stk.pop_back();\n\
    \    } else {\n      while (removed[h[u].back().second]) {\n        h[u].pop_back();\n\
    \      }\n      auto [v, idx] = h[u].back();\n      h[u].pop_back();\n\n     \
    \ deg[u]--, deg[v]--;\n      removed[idx] = true;\n\n      stk.push_back(v);\n\
    \    }\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/euler_cycle.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/euler_cycle.h
layout: document
title: Eulerian Cycle
---

Find Eulerian cycle/path in directed graphs using Hierholzer's algorithm.

## Operations

- `euler_cycle(g)`: Find Eulerian cycle starting from vertex 0
- Returns vector of vertices in cycle order

## Complexity

- Time: $O(V + E)$
- Space: $O(E)$

## Usage

{% raw %}
```cpp
vector<vector<int>> g = {{1}, {2}, {0}};
vector<int> cycle = euler_cycle(g);

if (!cycle.empty()) {
  // Found Eulerian cycle
  for (int v : cycle) {
  cout << v << " ";
  }
}
```
{% endraw %}

## Notes

Requires all vertices with nonzero degree to have equal in-degree and out-degree. Returns empty vector if no cycle exists.