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
  bundledCode: "#line 2 \"graphs/euler_tour.hpp\"\n\nstruct euler_tour {\n    vector<int>\
    \ tin, tout;\n\n    euler_tour(const vector<vector<int>> &g, int root = 0) : adj(g)\
    \ {\n        dfs(root, -1);\n    }\n\nprivate:\n    int time = 0;\n    const vector<vector<int>>\
    \ &adj;\n\n    void dfs(int u, int par) {\n        tin[u] = time++;\n        for\
    \ (int v : adj[u]) {\n            if (v != par) {\n                dfs(v, u);\n\
    \            }\n        }\n        tout[u] = time;\n    }\n};\n"
  code: "#pragma once\n\nstruct euler_tour {\n    vector<int> tin, tout;\n\n    euler_tour(const\
    \ vector<vector<int>> &g, int root = 0) : adj(g) {\n        dfs(root, -1);\n \
    \   }\n\nprivate:\n    int time = 0;\n    const vector<vector<int>> &adj;\n\n\
    \    void dfs(int u, int par) {\n        tin[u] = time++;\n        for (int v\
    \ : adj[u]) {\n            if (v != par) {\n                dfs(v, u);\n     \
    \       }\n        }\n        tout[u] = time;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/euler_tour.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/euler_tour.hpp
layout: document
redirect_from:
- /library/graphs/euler_tour.hpp
- /library/graphs/euler_tour.hpp.html
title: graphs/euler_tour.hpp
---
