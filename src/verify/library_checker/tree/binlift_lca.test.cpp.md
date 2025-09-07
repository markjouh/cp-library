---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graphs/trees/binary_lifting.h
    title: Binary Lifting
  - icon: ':heavy_check_mark:'
    path: src/template/template.h
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"src/verify/library_checker/tree/binlift_lca.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"src/template/template.h\"\
    \n/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define sz(x) int(size(x))\n#define all(x) begin(x), end(x)\n#line 1 \"src/graphs/trees/binary_lifting.h\"\
    \nstruct BinaryLifting {\n  int log;\n  vector<int> dep;\n  vector<vector<int>>\
    \ up;\n\n  BinaryLifting(const vector<vector<int>> &g, int root = 0) {\n    log\
    \ = __lg(sz(g)) + 1;\n    dep.resize(sz(g), -1);\n    up = vector(sz(g), vector<int>(log,\
    \ -1));\n\n    queue<int> q;\n    dep[root] = 0;\n    q.push(root);\n    while\
    \ (sz(q)) {\n      int u = q.front();\n      q.pop();\n      for (int v : g[u])\
    \ {\n        if (dep[v] == -1) {\n          dep[v] = dep[u] + 1;\n          up[v][0]\
    \ = u;\n          for (int i = 1; i < log; i++) {\n            if (up[v][i - 1]\
    \ == -1) {\n              break;\n            }\n            up[v][i] = up[up[v][i\
    \ - 1]][i - 1];\n          }\n          q.push(v);\n        }\n      }\n    }\n\
    \  }\n\n  int anc(int x, int k) {\n    for (int i = 0; i < log; i++) {\n     \
    \ if (x != -1 && ((k >> i) & 1)) {\n        x = up[x][i];\n      }\n    }\n  \
    \  return x;\n  }\n\n  int lca(int x, int y) {\n    if (dep[x] < dep[y]) {\n \
    \     swap(x, y);\n    }\n    x = anc(x, dep[x] - dep[y]);\n    if (x == y) {\n\
    \      return x;\n    }\n    for (int i = log - 1; i >= 0; i--) {\n      if (up[x][i]\
    \ != up[y][i]) {\n        x = up[x][i];\n        y = up[y][i];\n      }\n    }\n\
    \    return up[x][0];\n  }\n\n  int dist(int x, int y) {\n    return dep[x] +\
    \ dep[y] - 2 * dep[lca(x, y)];\n  }\n};\n#line 5 \"src/verify/library_checker/tree/binlift_lca.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<vector<int>> g(n);\n\
    \  for (int i = 1; i < n; i++) {\n    int p;\n    cin >> p;\n    g[p].push_back(i);\n\
    \  }\n  BinaryLifting bl(g);\n  while (q--) {\n    int u, v;\n    cin >> u >>\
    \ v;\n    cout << bl.lca(u, v) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../../template/template.h\"\
    \n#include \"../../../graphs/trees/binary_lifting.h\"\n\nint main() {\n  int n,\
    \ q;\n  cin >> n >> q;\n  vector<vector<int>> g(n);\n  for (int i = 1; i < n;\
    \ i++) {\n    int p;\n    cin >> p;\n    g[p].push_back(i);\n  }\n  BinaryLifting\
    \ bl(g);\n  while (q--) {\n    int u, v;\n    cin >> u >> v;\n    cout << bl.lca(u,\
    \ v) << '\\n';\n  }\n}"
  dependsOn:
  - src/template/template.h
  - src/graphs/trees/binary_lifting.h
  isVerificationFile: true
  path: src/verify/library_checker/tree/binlift_lca.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/tree/binlift_lca.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/tree/binlift_lca.test.cpp
- /verify/src/verify/library_checker/tree/binlift_lca.test.cpp.html
title: src/verify/library_checker/tree/binlift_lca.test.cpp
---
