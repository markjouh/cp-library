---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/custom/utils/random_graph.test.cpp
    title: verify/custom/utils/random_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/dijkstras.h\"\n\ntemplate <class T>\nauto dijkstras(const\
    \ vector<vector<pair<int, int>>> &g, int start = 0) {\n    priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\n    vector<T> dist(sz(g),\
    \ numeric_limits<T>::max());\n    vector<int> from(sz(g), -1);\n    \n    dist[start]\
    \ = 0;\n    pq.emplace(0, start);\n\n    while (sz(pq)) {\n        auto [d, u]\
    \ = pq.top();\n        pq.pop();\n        if (d != dist[u]) {\n            continue;\n\
    \        }\n        for (auto [v, w] : g[u]) {\n            if (ckmin(dist[v],\
    \ d + w)) {\n                from[v] = u;\n                pq.emplace(dist[v],\
    \ v);\n            }\n        }\n    }\n    return make_pair(dist, from);\n}\n"
  code: "#pragma once\n\ntemplate <class T>\nauto dijkstras(const vector<vector<pair<int,\
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
  path: graphs/dijkstras.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/custom/utils/random_graph.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
documentation_of: graphs/dijkstras.h
layout: document
redirect_from:
- /library/graphs/dijkstras.h
- /library/graphs/dijkstras.h.html
title: graphs/dijkstras.h
---
