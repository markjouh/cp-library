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
  bundledCode: "#line 1 \"src/graphs/shortest_paths/dijkstras_k_shortest.h\"\ntemplate\
    \ <class T>\nauto dijkstras_k_shortest(const vector<vector<pair<int, int>>> &g,\
    \ int k, int start = 0) {\n  priority_queue<pair<T, int>, vector<pair<T, int>>,\
    \ greater<pair<T, int>>> pq;\n\n  vector<vector<T>> dist(sz(g));\n  for (int i\
    \ = 0; i < sz(g); i++) {\n    dist[i].reserve(k);\n  }\n\n  pq.emplace(0, start);\n\
    \n  while (sz(pq)) {\n    auto [d, u] = pq.top();\n    pq.pop();\n    if (sz(dist[u])\
    \ == k) {\n      continue;\n    }\n    dist[u].push_back(d);\n    for (auto [v,\
    \ w] : g[u]) {\n      pq.emplace(d + w, v);\n    }\n  }\n  return dist;\n}\n"
  code: "template <class T>\nauto dijkstras_k_shortest(const vector<vector<pair<int,\
    \ int>>> &g, int k, int start = 0) {\n  priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> pq;\n\n  vector<vector<T>> dist(sz(g));\n  for\
    \ (int i = 0; i < sz(g); i++) {\n    dist[i].reserve(k);\n  }\n\n  pq.emplace(0,\
    \ start);\n\n  while (sz(pq)) {\n    auto [d, u] = pq.top();\n    pq.pop();\n\
    \    if (sz(dist[u]) == k) {\n      continue;\n    }\n    dist[u].push_back(d);\n\
    \    for (auto [v, w] : g[u]) {\n      pq.emplace(d + w, v);\n    }\n  }\n  return\
    \ dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/shortest_paths/dijkstras_k_shortest.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/graphs/shortest_paths/dijkstras_k_shortest.h
layout: document
redirect_from:
- /library/src/graphs/shortest_paths/dijkstras_k_shortest.h
- /library/src/graphs/shortest_paths/dijkstras_k_shortest.h.html
title: src/graphs/shortest_paths/dijkstras_k_shortest.h
---
