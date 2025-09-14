---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/graph/scc.test.cpp
    title: src/verify/library_checker/graph/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graphs/kosaraju_scc.h\"\nstruct KosarajuScc {\n  int\
    \ sccs = 0;\n  vector<int> comp;\n  vector<vector<int>> members, cg;\n\n  KosarajuScc(const\
    \ vector<vector<int>> &g_) : g(g_) {\n    comp.resize(ssize(g), -1);\n    tg.resize(ssize(g));\n\
    \    vis.resize(ssize(g));\n    ord.reserve(ssize(g));\n    for (int i = 0; i\
    \ < ssize(g); i++) {\n      if (!vis[i]) {\n        dfs_setup(i);\n      }\n \
    \   }\n    for (int i = ssize(ord) - 1; i >= 0; i--) {\n      if (comp[ord[i]]\
    \ == -1) {\n        members.emplace_back();\n        dfs_build(ord[i]);\n    \
    \    sccs++;\n      }\n    }\n    tg.clear();\n    vis.clear();\n    ord.clear();\n\
    \n    cg.resize(sccs);\n    vector<int> prev(sccs, -1);\n    for (int i = 0; i\
    \ < sccs; i++) {\n      for (int u : members[i]) {\n        for (int v : g[u])\
    \ {\n          if (comp[v] != i && prev[comp[v]] < i) {\n            cg[i].push_back(comp[v]);\n\
    \            prev[comp[v]] = i;\n          }\n        }\n      }\n    }\n  }\n\
    \nprivate:\n  const vector<vector<int>> &g;\n  vector<vector<int>> tg;\n  vector<bool>\
    \ vis;\n  vector<int> ord;\n\n  void dfs_setup(int u) {\n    vis[u] = true;\n\
    \    for (int v : g[u]) {\n      tg[v].push_back(u);\n      if (!vis[v]) {\n \
    \       dfs_setup(v);\n      }\n    }\n    ord.push_back(u);\n  }\n\n  void dfs_build(int\
    \ u) {\n    comp[u] = sccs;\n    members[sccs].push_back(u);\n    for (int v :\
    \ tg[u]) {\n      if (comp[v] == -1) {\n        dfs_build(v);\n      }\n    }\n\
    \  }\n};\n"
  code: "struct KosarajuScc {\n  int sccs = 0;\n  vector<int> comp;\n  vector<vector<int>>\
    \ members, cg;\n\n  KosarajuScc(const vector<vector<int>> &g_) : g(g_) {\n   \
    \ comp.resize(ssize(g), -1);\n    tg.resize(ssize(g));\n    vis.resize(ssize(g));\n\
    \    ord.reserve(ssize(g));\n    for (int i = 0; i < ssize(g); i++) {\n      if\
    \ (!vis[i]) {\n        dfs_setup(i);\n      }\n    }\n    for (int i = ssize(ord)\
    \ - 1; i >= 0; i--) {\n      if (comp[ord[i]] == -1) {\n        members.emplace_back();\n\
    \        dfs_build(ord[i]);\n        sccs++;\n      }\n    }\n    tg.clear();\n\
    \    vis.clear();\n    ord.clear();\n\n    cg.resize(sccs);\n    vector<int> prev(sccs,\
    \ -1);\n    for (int i = 0; i < sccs; i++) {\n      for (int u : members[i]) {\n\
    \        for (int v : g[u]) {\n          if (comp[v] != i && prev[comp[v]] < i)\
    \ {\n            cg[i].push_back(comp[v]);\n            prev[comp[v]] = i;\n \
    \         }\n        }\n      }\n    }\n  }\n\nprivate:\n  const vector<vector<int>>\
    \ &g;\n  vector<vector<int>> tg;\n  vector<bool> vis;\n  vector<int> ord;\n\n\
    \  void dfs_setup(int u) {\n    vis[u] = true;\n    for (int v : g[u]) {\n   \
    \   tg[v].push_back(u);\n      if (!vis[v]) {\n        dfs_setup(v);\n      }\n\
    \    }\n    ord.push_back(u);\n  }\n\n  void dfs_build(int u) {\n    comp[u] =\
    \ sccs;\n    members[sccs].push_back(u);\n    for (int v : tg[u]) {\n      if\
    \ (comp[v] == -1) {\n        dfs_build(v);\n      }\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/kosaraju_scc.h
  requiredBy: []
  timestamp: '2025-09-14 12:12:28-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/graph/scc.test.cpp
documentation_of: src/graphs/kosaraju_scc.h
layout: document
title: Kosaraju's Algorithm for Strongly Connected Components
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

{% raw %}
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
{% endraw %}

## Notes

Components numbered in reverse topological order. Condensation graph automatically built with duplicate edges removed.