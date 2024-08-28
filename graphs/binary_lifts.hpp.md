---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/lca.test.cpp
    title: verify/library_checker/tree/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/binary_lifts.hpp\"\n\nstruct BinaryLifting {\n  int\
    \ lg;\n  vector<int> dep;\n  vector<vector<int>> up;\n\n  BinaryLifting(const\
    \ vector<vector<int>> &g, int root = 0) : lg(__lg(sz(g)) + 1), dep(sz(g), -1),\
    \ up(sz(g), vector<int>(lg, -1)) {\n    queue<int> q;\n    dep[root] = 0;\n  \
    \  q.push(root);\n    while (sz(q)) {\n      int u = q.front();\n      q.pop();\n\
    \      for (int v : g[u]) {\n        if (dep[v] == -1) {\n          dep[v] = dep[u]\
    \ + 1;\n          up[v][0] = u;\n          for (int i = 1; i < lg; i++) {\n  \
    \          if (up[v][i - 1] == -1) {\n              break;\n            }\n  \
    \          up[v][i] = up[up[v][i - 1]][i - 1];\n          }\n          q.push(v);\n\
    \        }\n      }\n    }\n  }\n\n  int par(int x) {\n    return up[x][0];\n\
    \  }\n\n  int anc(int x, int k) {\n    for (int i = 0; i < lg; i++) {\n      if\
    \ (x != -1 && ((k >> i) & 1)) {\n        x = up[x][i];\n      }\n    }\n    return\
    \ x;\n  }\n\n  int lca(int x, int y) {\n    if (dep[x] < dep[y]) {\n      swap(x,\
    \ y);\n    }\n    x = anc(x, dep[x] - dep[y]);\n    if (x == y) {\n      return\
    \ x;\n    }\n    for (int i = lg - 1; i >= 0; i--) {\n      if (up[x][i] != up[y][i])\
    \ {\n        x = up[x][i];\n        y = up[y][i];\n      }\n    }\n    return\
    \ up[x][0];\n  }\n\n  int dist(int x, int y) {\n    return dep[x] + dep[y] - 2\
    \ * dep[lca(x, y)];\n  }\n};\n"
  code: "#pragma once\n\nstruct BinaryLifting {\n  int lg;\n  vector<int> dep;\n \
    \ vector<vector<int>> up;\n\n  BinaryLifting(const vector<vector<int>> &g, int\
    \ root = 0) : lg(__lg(sz(g)) + 1), dep(sz(g), -1), up(sz(g), vector<int>(lg, -1))\
    \ {\n    queue<int> q;\n    dep[root] = 0;\n    q.push(root);\n    while (sz(q))\
    \ {\n      int u = q.front();\n      q.pop();\n      for (int v : g[u]) {\n  \
    \      if (dep[v] == -1) {\n          dep[v] = dep[u] + 1;\n          up[v][0]\
    \ = u;\n          for (int i = 1; i < lg; i++) {\n            if (up[v][i - 1]\
    \ == -1) {\n              break;\n            }\n            up[v][i] = up[up[v][i\
    \ - 1]][i - 1];\n          }\n          q.push(v);\n        }\n      }\n    }\n\
    \  }\n\n  int par(int x) {\n    return up[x][0];\n  }\n\n  int anc(int x, int\
    \ k) {\n    for (int i = 0; i < lg; i++) {\n      if (x != -1 && ((k >> i) & 1))\
    \ {\n        x = up[x][i];\n      }\n    }\n    return x;\n  }\n\n  int lca(int\
    \ x, int y) {\n    if (dep[x] < dep[y]) {\n      swap(x, y);\n    }\n    x = anc(x,\
    \ dep[x] - dep[y]);\n    if (x == y) {\n      return x;\n    }\n    for (int i\
    \ = lg - 1; i >= 0; i--) {\n      if (up[x][i] != up[y][i]) {\n        x = up[x][i];\n\
    \        y = up[y][i];\n      }\n    }\n    return up[x][0];\n  }\n\n  int dist(int\
    \ x, int y) {\n    return dep[x] + dep[y] - 2 * dep[lca(x, y)];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/binary_lifts.hpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/lca.test.cpp
documentation_of: graphs/binary_lifts.hpp
layout: document
redirect_from:
- /library/graphs/binary_lifts.hpp
- /library/graphs/binary_lifts.hpp.html
title: graphs/binary_lifts.hpp
---
