---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/custom/graphs/topsort.test.cpp
    title: verify/custom/graphs/topsort.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/topsort.h\"\n\nauto topsort(const vector<vector<int>>\
    \ &g) {\n    vector<int> deg(sz(g));\n    for (int u = 0; u < sz(g); u++) {\n\
    \        for (int v : g[u]) {\n            deg[v]++;\n        }\n    }\n    queue<int>\
    \ q;\n    for (int i = 0; i < sz(g); i++) {\n        if (deg[i] == 0) {\n    \
    \        q.push(i);\n        }\n    }\n    vector<int> res;\n    while (!q.empty())\
    \ {\n        int u = q.front();\n        q.pop();\n        res.push_back(u);\n\
    \        for (int v : g[u]) {\n            if (--deg[v] == 0) {\n            \
    \    q.push(v);\n            }\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n\nauto topsort(const vector<vector<int>> &g) {\n    vector<int>\
    \ deg(sz(g));\n    for (int u = 0; u < sz(g); u++) {\n        for (int v : g[u])\
    \ {\n            deg[v]++;\n        }\n    }\n    queue<int> q;\n    for (int\
    \ i = 0; i < sz(g); i++) {\n        if (deg[i] == 0) {\n            q.push(i);\n\
    \        }\n    }\n    vector<int> res;\n    while (!q.empty()) {\n        int\
    \ u = q.front();\n        q.pop();\n        res.push_back(u);\n        for (int\
    \ v : g[u]) {\n            if (--deg[v] == 0) {\n                q.push(v);\n\
    \            }\n        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graphs/topsort.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/custom/graphs/topsort.test.cpp
documentation_of: graphs/topsort.h
layout: document
redirect_from:
- /library/graphs/topsort.h
- /library/graphs/topsort.h.html
title: graphs/topsort.h
---
