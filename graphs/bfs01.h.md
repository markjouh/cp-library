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
  bundledCode: "#line 2 \"graphs/bfs01.h\"\n\nint my_deque[1 << 17];\n \nauto bfs01(const\
    \ vector<vector<pair<int, bool>>> &g, int start = 0) {\n    vector<int> dist(sz(g),\
    \ INT_MAX / 2);\n    int l = 1 << 16, r = l;\n    \n    dist[start] = 0;\n   \
    \ my_deque[l] = start;\n \n    while (l <= r) {\n        int u = my_deque[l++];\n\
    \        for (auto [v, w] : g[u]) {\n            if (dist[u] + w < dist[v]) {\n\
    \                dist[v] = dist[u] + w;\n                if (w) {\n          \
    \          my_deque[++r] = v;\n                } else {\n                    my_deque[--l]\
    \ = v;\n                }\n            }\n        }\n    }\n    return dist;\n\
    }\n"
  code: "#pragma once\n\nint my_deque[1 << 17];\n \nauto bfs01(const vector<vector<pair<int,\
    \ bool>>> &g, int start = 0) {\n    vector<int> dist(sz(g), INT_MAX / 2);\n  \
    \  int l = 1 << 16, r = l;\n    \n    dist[start] = 0;\n    my_deque[l] = start;\n\
    \ \n    while (l <= r) {\n        int u = my_deque[l++];\n        for (auto [v,\
    \ w] : g[u]) {\n            if (dist[u] + w < dist[v]) {\n                dist[v]\
    \ = dist[u] + w;\n                if (w) {\n                    my_deque[++r]\
    \ = v;\n                } else {\n                    my_deque[--l] = v;\n   \
    \             }\n            }\n        }\n    }\n    return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graphs/bfs01.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/bfs01.h
layout: document
redirect_from:
- /library/graphs/bfs01.h
- /library/graphs/bfs01.h.html
title: graphs/bfs01.h
---
