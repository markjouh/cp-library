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
  bundledCode: "#line 1 \"graphs/trees/tree_paths.h\"\ntemplate <class T, auto op,\
    \ auto id>\nstruct tree_paths {\n    int log;\n    vector<int> dep;\n    vector<vector<int>>\
    \ up;\n    vector<vector<T>> val;\n\n    tree_paths(const vector<vector<pair<int,\
    \ int>>> &g, int root = 0) {\n        log = __lg(sz(g)) + 1;\n        dep.resize(sz(g),\
    \ -1);\n        up = vector(sz(g), vector<int>(log, -1));\n        val = vector(sz(g),\
    \ vector<T>(log, id()));\n\n        queue<int> q;\n        dep[root] = 0;\n  \
    \      q.push(root);\n        while (sz(q)) {\n            int u = q.front();\n\
    \            q.pop();\n            for (auto [v, w] : g[u]) {\n              \
    \  if (dep[v] == -1) {\n                    dep[v] = dep[u] + 1;\n           \
    \         up[v][0] = u;\n                    val[v][0] = w;\n                \
    \    for (int i = 1; i < log; i++) {\n                        if (up[v][i - 1]\
    \ == -1) {\n                            break;\n                        }\n  \
    \                      up[v][i] = up[up[v][i - 1]][i - 1];\n                 \
    \       val[v][i] = op(val[v][i - 1], val[up[v][i - 1]][i - 1]);\n           \
    \         }\n                    q.push(v);\n                }\n            }\n\
    \        }\n    }\n\n    T query(int x, int y) {\n        if (dep[x] < dep[y])\
    \ {\n            swap(x, y);\n        }\n        T res = id();\n        const\
    \ int diff = dep[x] - dep[y];\n        for (int i = 0; i < log; i++) {\n     \
    \       if (x != -1 && ((diff >> i) & 1)) {\n                res = op(res, val[x][i]);\n\
    \                x = up[x][i];\n            }\n        }\n        if (x == y)\
    \ {\n            return res;\n        }\n        for (int i = log - 1; i >= 0;\
    \ i--) {\n            if (up[x][i] != up[y][i]) {\n                res = op(res,\
    \ val[x][i]);\n                res = op(res, val[y][i]);\n                x =\
    \ up[x][i];\n                y = up[y][i];\n            }\n        }\n       \
    \ res = op(res, val[x][0]);\n        res = op(res, val[y][0]);\n        return\
    \ res;\n    }\n};\n"
  code: "template <class T, auto op, auto id>\nstruct tree_paths {\n    int log;\n\
    \    vector<int> dep;\n    vector<vector<int>> up;\n    vector<vector<T>> val;\n\
    \n    tree_paths(const vector<vector<pair<int, int>>> &g, int root = 0) {\n  \
    \      log = __lg(sz(g)) + 1;\n        dep.resize(sz(g), -1);\n        up = vector(sz(g),\
    \ vector<int>(log, -1));\n        val = vector(sz(g), vector<T>(log, id()));\n\
    \n        queue<int> q;\n        dep[root] = 0;\n        q.push(root);\n     \
    \   while (sz(q)) {\n            int u = q.front();\n            q.pop();\n  \
    \          for (auto [v, w] : g[u]) {\n                if (dep[v] == -1) {\n \
    \                   dep[v] = dep[u] + 1;\n                    up[v][0] = u;\n\
    \                    val[v][0] = w;\n                    for (int i = 1; i < log;\
    \ i++) {\n                        if (up[v][i - 1] == -1) {\n                \
    \            break;\n                        }\n                        up[v][i]\
    \ = up[up[v][i - 1]][i - 1];\n                        val[v][i] = op(val[v][i\
    \ - 1], val[up[v][i - 1]][i - 1]);\n                    }\n                  \
    \  q.push(v);\n                }\n            }\n        }\n    }\n\n    T query(int\
    \ x, int y) {\n        if (dep[x] < dep[y]) {\n            swap(x, y);\n     \
    \   }\n        T res = id();\n        const int diff = dep[x] - dep[y];\n    \
    \    for (int i = 0; i < log; i++) {\n            if (x != -1 && ((diff >> i)\
    \ & 1)) {\n                res = op(res, val[x][i]);\n                x = up[x][i];\n\
    \            }\n        }\n        if (x == y) {\n            return res;\n  \
    \      }\n        for (int i = log - 1; i >= 0; i--) {\n            if (up[x][i]\
    \ != up[y][i]) {\n                res = op(res, val[x][i]);\n                res\
    \ = op(res, val[y][i]);\n                x = up[x][i];\n                y = up[y][i];\n\
    \            }\n        }\n        res = op(res, val[x][0]);\n        res = op(res,\
    \ val[y][0]);\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/trees/tree_paths.h
  requiredBy: []
  timestamp: '2025-02-15 20:52:13-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/trees/tree_paths.h
layout: document
redirect_from:
- /library/graphs/trees/tree_paths.h
- /library/graphs/trees/tree_paths.h.html
title: graphs/trees/tree_paths.h
---
