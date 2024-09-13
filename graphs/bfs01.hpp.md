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
  bundledCode: "#line 2 \"graphs/bfs01.hpp\"\n\nint myDeque[1 << 17];\n \nauto bfs01(const\
    \ vector<vector<pair<int, bool>>> &g, int start = 0) {\n  vector<int> dist(sz(g),\
    \ INT_MAX / 2);\n  int dL = 1 << 16, dR = dL;\n  \n  dist[start] = 0;\n  myDeque[dL]\
    \ = start;\n \n  while (dL <= dR) {\n    int u = myDeque[dL++];\n    for (auto\
    \ [v, w] : g[u]) {\n      if (dist[u] + w < dist[v]) {\n        dist[v] = dist[u]\
    \ + w;\n        if (w) {\n          myDeque[++dR] = v;\n        } else {\n   \
    \       myDeque[--dL] = v;\n        }\n      }\n    }\n  }\n  return dist;\n}\n"
  code: "#pragma once\n\nint myDeque[1 << 17];\n \nauto bfs01(const vector<vector<pair<int,\
    \ bool>>> &g, int start = 0) {\n  vector<int> dist(sz(g), INT_MAX / 2);\n  int\
    \ dL = 1 << 16, dR = dL;\n  \n  dist[start] = 0;\n  myDeque[dL] = start;\n \n\
    \  while (dL <= dR) {\n    int u = myDeque[dL++];\n    for (auto [v, w] : g[u])\
    \ {\n      if (dist[u] + w < dist[v]) {\n        dist[v] = dist[u] + w;\n    \
    \    if (w) {\n          myDeque[++dR] = v;\n        } else {\n          myDeque[--dL]\
    \ = v;\n        }\n      }\n    }\n  }\n  return dist;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graphs/bfs01.hpp
  requiredBy: []
  timestamp: '2024-09-13 16:07:33-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/bfs01.hpp
layout: document
redirect_from:
- /library/graphs/bfs01.hpp
- /library/graphs/bfs01.hpp.html
title: graphs/bfs01.hpp
---
