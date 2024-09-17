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
  bundledCode: "#line 2 \"graphs/topsort.hpp\"\n\nauto topsort(const vector<vector<int>>\
    \ &g) {\n  vector<int> deg(sz(g));\n  for (int u = 0; u < sz(g); u++) {\n    for\
    \ (int v : g[u]) {\n      deg[v]++;\n    }\n  }\n  queue<int> q;\n  for (int i\
    \ = 0; i < sz(g); i++) {\n    if (deg[i] == 0) {\n      q.push(i);\n    }\n  }\n\
    \  vector<int> res;\n  while (!q.empty()) {\n    int u = q.front();\n    q.pop();\n\
    \    res.push_back(u);\n    for (int v : g[u]) {\n      if (--deg[v] == 0) {\n\
    \        q.push(v);\n      }\n    }\n  }\n  return res;\n}\n"
  code: "#pragma once\n\nauto topsort(const vector<vector<int>> &g) {\n  vector<int>\
    \ deg(sz(g));\n  for (int u = 0; u < sz(g); u++) {\n    for (int v : g[u]) {\n\
    \      deg[v]++;\n    }\n  }\n  queue<int> q;\n  for (int i = 0; i < sz(g); i++)\
    \ {\n    if (deg[i] == 0) {\n      q.push(i);\n    }\n  }\n  vector<int> res;\n\
    \  while (!q.empty()) {\n    int u = q.front();\n    q.pop();\n    res.push_back(u);\n\
    \    for (int v : g[u]) {\n      if (--deg[v] == 0) {\n        q.push(v);\n  \
    \    }\n    }\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graphs/topsort.hpp
  requiredBy: []
  timestamp: '2024-09-17 14:25:28-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/topsort.hpp
layout: document
redirect_from:
- /library/graphs/topsort.hpp
- /library/graphs/topsort.hpp.html
title: graphs/topsort.hpp
---
