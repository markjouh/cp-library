---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/custom/utils/random_graph.test.cpp
    title: verify/custom/utils/random_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/dijkstras.hpp\"\n\ntemplate <class T>\nauto dijkstras(const\
    \ vector<vector<pair<int, int>>> &g, int start = 0) {\n  priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\n  vector<T> dist(sz(g),\
    \ numeric_limits<T>::max());\n  vector<int> from(sz(g), -1);\n  \n  dist[start]\
    \ = 0;\n  pq.emplace(0, start);\n\n  while (sz(pq)) {\n    auto [d, u] = pq.top();\n\
    \    pq.pop();\n    if (d != dist[u]) {\n      continue;\n    }\n    for (auto\
    \ [v, w] : g[u]) {\n      if (ckmin(dist[v], d + w)) {\n        from[v] = u;\n\
    \        pq.emplace(dist[v], v);\n      }\n    }\n  }\n  return make_pair(dist,\
    \ from);\n}\n"
  code: "#pragma once\n\ntemplate <class T>\nauto dijkstras(const vector<vector<pair<int,\
    \ int>>> &g, int start = 0) {\n  priority_queue<pair<T, int>, vector<pair<T, int>>,\
    \ greater<pair<T, int>>> pq;\n\n  vector<T> dist(sz(g), numeric_limits<T>::max());\n\
    \  vector<int> from(sz(g), -1);\n  \n  dist[start] = 0;\n  pq.emplace(0, start);\n\
    \n  while (sz(pq)) {\n    auto [d, u] = pq.top();\n    pq.pop();\n    if (d !=\
    \ dist[u]) {\n      continue;\n    }\n    for (auto [v, w] : g[u]) {\n      if\
    \ (ckmin(dist[v], d + w)) {\n        from[v] = u;\n        pq.emplace(dist[v],\
    \ v);\n      }\n    }\n  }\n  return make_pair(dist, from);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/dijkstras.hpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/custom/utils/random_graph.test.cpp
documentation_of: graphs/dijkstras.hpp
layout: document
redirect_from:
- /library/graphs/dijkstras.hpp
- /library/graphs/dijkstras.hpp.html
title: graphs/dijkstras.hpp
---
