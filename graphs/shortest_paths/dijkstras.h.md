---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graphs/shortest_paths/dijkstras.h\"\ntemplate <class T>\n\
    auto dijkstras(const vector<vector<pair<int, int>>> &g, int start = 0) {\n   \
    \ priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\
    \n    vector<T> dist(sz(g), numeric_limits<T>::max());\n    vector<int> from(sz(g),\
    \ -1);\n    \n    dist[start] = 0;\n    pq.emplace(0, start);\n\n    while (sz(pq))\
    \ {\n        auto [d, u] = pq.top();\n        pq.pop();\n        if (d != dist[u])\
    \ {\n            continue;\n        }\n        for (auto [v, w] : g[u]) {\n  \
    \          if (d + w < dist[v]) {\n                dist[v] = d + w;\n        \
    \        from[v] = u;\n                pq.emplace(dist[v], v);\n            }\n\
    \        }\n    }\n    return make_pair(dist, from);\n}\n"
  code: "template <class T>\nauto dijkstras(const vector<vector<pair<int, int>>> &g,\
    \ int start = 0) {\n    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> pq;\n\n    vector<T> dist(sz(g), numeric_limits<T>::max());\n    vector<int>\
    \ from(sz(g), -1);\n    \n    dist[start] = 0;\n    pq.emplace(0, start);\n\n\
    \    while (sz(pq)) {\n        auto [d, u] = pq.top();\n        pq.pop();\n  \
    \      if (d != dist[u]) {\n            continue;\n        }\n        for (auto\
    \ [v, w] : g[u]) {\n            if (d + w < dist[v]) {\n                dist[v]\
    \ = d + w;\n                from[v] = u;\n                pq.emplace(dist[v],\
    \ v);\n            }\n        }\n    }\n    return make_pair(dist, from);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/shortest_paths/dijkstras.h
  requiredBy: []
  timestamp: '2024-10-25 19:46:34-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/graph/shortest_path.test.cpp
documentation_of: graphs/shortest_paths/dijkstras.h
layout: document
redirect_from:
- /library/graphs/shortest_paths/dijkstras.h
- /library/graphs/shortest_paths/dijkstras.h.html
title: graphs/shortest_paths/dijkstras.h
---
