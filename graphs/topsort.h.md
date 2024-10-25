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
  bundledCode: "#line 1 \"graphs/topsort.h\"\nauto topsort(const vector<vector<int>>\
    \ &g) {\n    vector<int> deg(sz(g));\n    for (int u = 0; u < sz(g); u++) {\n\
    \        for (int v : g[u]) {\n            deg[v]++;\n        }\n    }\n    queue<int>\
    \ q;\n    for (int i = 0; i < sz(g); i++) {\n        if (deg[i] == 0) {\n    \
    \        q.push(i);\n        }\n    }\n    vector<int> res;\n    while (!q.empty())\
    \ {\n        int u = q.front();\n        q.pop();\n        res.push_back(u);\n\
    \        for (int v : g[u]) {\n            if (--deg[v] == 0) {\n            \
    \    q.push(v);\n            }\n        }\n    }\n    return res;\n}\n"
  code: "auto topsort(const vector<vector<int>> &g) {\n    vector<int> deg(sz(g));\n\
    \    for (int u = 0; u < sz(g); u++) {\n        for (int v : g[u]) {\n       \
    \     deg[v]++;\n        }\n    }\n    queue<int> q;\n    for (int i = 0; i <\
    \ sz(g); i++) {\n        if (deg[i] == 0) {\n            q.push(i);\n        }\n\
    \    }\n    vector<int> res;\n    while (!q.empty()) {\n        int u = q.front();\n\
    \        q.pop();\n        res.push_back(u);\n        for (int v : g[u]) {\n \
    \           if (--deg[v] == 0) {\n                q.push(v);\n            }\n\
    \        }\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graphs/topsort.h
  requiredBy: []
  timestamp: '2024-10-25 19:46:34-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/topsort.h
layout: document
redirect_from:
- /library/graphs/topsort.h
- /library/graphs/topsort.h.html
title: graphs/topsort.h
---
