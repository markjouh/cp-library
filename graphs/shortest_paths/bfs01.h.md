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
  bundledCode: "#line 1 \"graphs/shortest_paths/bfs01.h\"\nauto bfs01(const vector<vector<pair<int,\
    \ bool>>> &g, int start = 0) {\n    vector<int> dist(sz(g), INT_MAX / 2);\n\n\
    \    static int dq[1 << 17];\n    int l = 1 << 16, r = l;\n    \n    dist[start]\
    \ = 0;\n    dq[l] = start;\n \n    while (l <= r) {\n        int u = dq[l++];\n\
    \        for (auto [v, w] : g[u]) {\n            if (dist[u] + w < dist[v]) {\n\
    \                dist[v] = dist[u] + w;\n                dq[w ? ++r : --l] = v;\n\
    \            }\n        }\n    }\n    return dist;\n}\n"
  code: "auto bfs01(const vector<vector<pair<int, bool>>> &g, int start = 0) {\n \
    \   vector<int> dist(sz(g), INT_MAX / 2);\n\n    static int dq[1 << 17];\n   \
    \ int l = 1 << 16, r = l;\n    \n    dist[start] = 0;\n    dq[l] = start;\n \n\
    \    while (l <= r) {\n        int u = dq[l++];\n        for (auto [v, w] : g[u])\
    \ {\n            if (dist[u] + w < dist[v]) {\n                dist[v] = dist[u]\
    \ + w;\n                dq[w ? ++r : --l] = v;\n            }\n        }\n   \
    \ }\n    return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graphs/shortest_paths/bfs01.h
  requiredBy: []
  timestamp: '2024-10-25 20:41:56-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/shortest_paths/bfs01.h
layout: document
redirect_from:
- /library/graphs/shortest_paths/bfs01.h
- /library/graphs/shortest_paths/bfs01.h.html
title: graphs/shortest_paths/bfs01.h
---
