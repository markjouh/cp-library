---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/tree/binary_lifting.hpp
    title: graphs/tree/binary_lifting.hpp
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
  bundledCode: "#line 1 \"verify/library_checker/tree/lca.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"verify/boilerplate.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdint>\n\
    #include <cstring>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <vector>\n\nusing namespace std;\n\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n#define eb emplace_back\n\
    #define fi first\n#define se second\n\nusing ll = long long;\nusing pii = pair<int,\
    \ int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n\
    \  return __lg(x);\n#else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n \
    \ }\n  return res;\n#endif\n}\n\ntemplate <class T>\nbool ckmin(T &a, const T\
    \ &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T =\
    \ int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\nstruct InitIO\
    \ {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"graphs/tree/binary_lifting.hpp\"\
    \n\nstruct BinaryLifting {\n  int log;\n  vector<int> dep;\n  vector<vector<int>>\
    \ up;\n\n  BinaryLifting(const vector<vector<int>> &g, int rt = 0) {\n    log\
    \ = lg(sz(g) - 1) + 1;\n    dep.resize(sz(g), -1);\n    up = vector(sz(g), vector<int>(log,\
    \ -1));\n\n    queue<int> q;\n    dep[rt] = 0;\n    q.push(rt);\n    while (sz(q))\
    \ {\n      int u = q.front();\n      q.pop();\n      for (int v : g[u]) {\n  \
    \      if (dep[v] == -1) {\n          dep[v] = dep[u] + 1;\n          up[v][0]\
    \ = u;\n          for (int i = 1; i < log; i++) {\n            if (up[v][i - 1]\
    \ == -1) {\n              break;\n            }\n            up[v][i] = up[up[v][i\
    \ - 1]][i - 1];\n          }\n          q.push(v);\n        }\n      }\n    }\n\
    \  }\n\n  int par(int x) {\n    return up[x][0];\n  }\n\n  int anc(int x, int\
    \ k) {\n    for (int i = 0; i < log; i++) {\n      if (x != -1 && ((k >> i) &\
    \ 1)) {\n        x = up[x][i];\n      }\n    }\n    return x;\n  }\n\n  int lca(int\
    \ x, int y) {\n    if (dep[x] < dep[y]) {\n      swap(x, y);\n    }\n    x = anc(x,\
    \ dep[x] - dep[y]);\n    if (x == y) {\n      return x;\n    }\n    for (int i\
    \ = log - 1; i >= 0; i--) {\n      if (up[x][i] != up[y][i]) {\n        x = up[x][i];\n\
    \        y = up[y][i];\n      }\n    }\n    return up[x][0];\n  }\n\n  int dist(int\
    \ x, int y) {\n    return dep[x] + dep[y] - 2 * dep[lca(x, y)];\n  }\n};\n#line\
    \ 5 \"verify/library_checker/tree/lca.test.cpp\"\n\nint main() {\n  int n, q;\n\
    \  cin >> n >> q;\n  vector<vector<int>> g(n);\n  for (int i = 1; i < n; i++)\
    \ {\n    int p;\n    cin >> p;\n    g[p].pb(i);\n  }\n  BinaryLifting bl(g);\n\
    \  while (q--) {\n    int u, v;\n    cin >> u >> v;\n    cout << bl.lca(u, v)\
    \ << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../boilerplate.hpp\"\
    \n#include \"../../../graphs/tree/binary_lifting.hpp\"\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<vector<int>> g(n);\n  for (int i = 1; i <\
    \ n; i++) {\n    int p;\n    cin >> p;\n    g[p].pb(i);\n  }\n  BinaryLifting\
    \ bl(g);\n  while (q--) {\n    int u, v;\n    cin >> u >> v;\n    cout << bl.lca(u,\
    \ v) << '\\n';\n  }\n}"
  dependsOn:
  - graphs/tree/binary_lifting.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/lca.test.cpp
  requiredBy: []
  timestamp: '2024-09-01 21:11:12-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/lca.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/lca.test.cpp
- /verify/verify/library_checker/tree/lca.test.cpp.html
title: verify/library_checker/tree/lca.test.cpp
---
