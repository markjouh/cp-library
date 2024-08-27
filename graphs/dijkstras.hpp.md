---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/dijkstras.hpp\"\n\ntemplate<class T> auto dijkstras(const\
    \ vector<vector<pair<int, int>>> &g, int start = 0) {\n    priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\n    vector<T> dist(sz(g),\
    \ numeric_limits<T>::max());\n    vector<int> from(sz(g), -1);\n    \n    dist[start]\
    \ = 0;\n    pq.emplace(0, start);\n\n    while (sz(pq)) {\n        auto [d, u]\
    \ = pq.top();\n        pq.pop();\n        if (d != dist[u]) {\n            continue;\n\
    \        }\n        for (auto [v, w] : g[u]) {\n            if (ckmin(dist[v],\
    \ d + w)) {\n                from[v] = u;\n                pq.emplace(dist[v],\
    \ v);\n            }\n        }\n    }\n    return make_pair(dist, from);\n}\n"
  code: "#pragma once\n\ntemplate<class T> auto dijkstras(const vector<vector<pair<int,\
    \ int>>> &g, int start = 0) {\n    priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> pq;\n\n    vector<T> dist(sz(g), numeric_limits<T>::max());\n\
    \    vector<int> from(sz(g), -1);\n    \n    dist[start] = 0;\n    pq.emplace(0,\
    \ start);\n\n    while (sz(pq)) {\n        auto [d, u] = pq.top();\n        pq.pop();\n\
    \        if (d != dist[u]) {\n            continue;\n        }\n        for (auto\
    \ [v, w] : g[u]) {\n            if (ckmin(dist[v], d + w)) {\n               \
    \ from[v] = u;\n                pq.emplace(dist[v], v);\n            }\n     \
    \   }\n    }\n    return make_pair(dist, from);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/dijkstras.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/shortest_path.test.cpp
documentation_of: graphs/dijkstras.hpp
layout: document
title: Dijkstra's Shortest Paths
---

### Overview

Given a graph $G = (V, E)$, constructs the shortest paths from a specified starting vertex $s$ to each vertex reachable from $s$ in $O(\lvert E \rvert + \lvert V \rvert \log{\lvert V \rvert})$.

### Usage

* `dijkstras(g, s = 0)`: Returns a pair `dist, from`, the lengths of the shortest paths from s and the parent array of the shortest path tree rooted at s, respectively.