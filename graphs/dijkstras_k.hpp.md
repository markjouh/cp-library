---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/dijkstras_k.hpp\"\n\ntemplate <class T>\nauto dijkstrasK(const\
    \ vector<vector<pair<int, int>>> &g, int k, int start = 0) {\n  priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\n  vector<vector<T>>\
    \ dist(sz(g));\n  for (int i = 0; i < sz(g); i++) {\n    dist[i].reserve(k);\n\
    \  }\n  \n  pq.emplace(0, start);\n\n  while (sz(pq)) {\n    auto [d, u] = pq.top();\n\
    \    pq.pop();\n    if (sz(dist[u]) == k) {\n      continue;\n    }\n    dist[u].push_back(d);\n\
    \    for (auto [v, w] : g[u]) {\n      pq.emplace(d + w, v);\n    }\n  }\n  return\
    \ dist;\n}\n"
  code: "#pragma once\n\ntemplate <class T>\nauto dijkstrasK(const vector<vector<pair<int,\
    \ int>>> &g, int k, int start = 0) {\n  priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> pq;\n\n  vector<vector<T>> dist(sz(g));\n  for\
    \ (int i = 0; i < sz(g); i++) {\n    dist[i].reserve(k);\n  }\n  \n  pq.emplace(0,\
    \ start);\n\n  while (sz(pq)) {\n    auto [d, u] = pq.top();\n    pq.pop();\n\
    \    if (sz(dist[u]) == k) {\n      continue;\n    }\n    dist[u].push_back(d);\n\
    \    for (auto [v, w] : g[u]) {\n      pq.emplace(d + w, v);\n    }\n  }\n  return\
    \ dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graphs/dijkstras_k.hpp
  requiredBy: []
  timestamp: '2024-09-17 14:25:28-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/dijkstras_k.hpp
layout: document
redirect_from:
- /library/graphs/dijkstras_k.hpp
- /library/graphs/dijkstras_k.hpp.html
title: graphs/dijkstras_k.hpp
---
