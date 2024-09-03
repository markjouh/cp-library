---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/kosaraju_scc.hpp
    title: graphs/kosaraju_scc.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/library_checker/graph/scc.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n\n#line 1 \"verify/boilerplate.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdint>\n\
    #include <cstring>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <vector>\n\nusing namespace std;\n\n#define arg4(a, b, c, d,\
    \ ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define\
    \ rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n\
    \ \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define\
    \ per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class\
    \ T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n#else\n  int\
    \ res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n}\n\n\
    template <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1\
    \ : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return b >\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"graphs/kosaraju_scc.hpp\"\n\nstruct KosarajuSCC {\n  int\
    \ sccs = 0;\n  vector<int> comp;\n  vector<vector<int>> members, c_adj;\n\n  KosarajuSCC(const\
    \ vector<vector<int>> &g) : adj(g) {\n    comp.resize(sz(g), -1);\n    t_adj.resize(sz(g));\n\
    \    vis.resize(sz(g));\n    ord.reserve(sz(g));\n    for (int i = 0; i < sz(g);\
    \ i++) {\n      if (!vis[i]) {\n        dfs_setup(i);\n      }\n    }\n    for\
    \ (int i = sz(ord) - 1; i >= 0; i--) {\n      if (comp[ord[i]] == -1) {\n    \
    \    members.emplace_back();\n        dfs_build(ord[i]);\n        sccs++;\n  \
    \    }\n    }\n    t_adj.clear();\n    vis.clear();\n    ord.clear();\n\n    c_adj.resize(sccs);\n\
    \    vector<int> prev(sccs, -1);\n    for (int i = 0; i < sccs; i++) {\n     \
    \ for (int u : members[i]) {\n        for (int v : adj[u]) {\n          if (comp[v]\
    \ != i && prev[comp[v]] < i) {\n            c_adj[i].push_back(comp[v]);\n   \
    \         prev[comp[v]] = i;\n          }\n        }\n      }\n    }\n  }\n\n\
    private:\n  const vector<vector<int>> &adj;\n  vector<vector<int>> t_adj;\n  vector<bool>\
    \ vis;\n  vector<int> ord;\n\n  void dfs_setup(int u) {\n    vis[u] = true;\n\
    \    for (int v : adj[u]) {\n      t_adj[v].push_back(u);\n      if (!vis[v])\
    \ {\n        dfs_setup(v);\n      }\n    }\n    ord.push_back(u);\n  }\n\n  void\
    \ dfs_build(int u) {\n    comp[u] = sccs;\n    members[sccs].push_back(u);\n \
    \   for (int v : t_adj[u]) {\n      if (comp[v] == -1) {\n        dfs_build(v);\n\
    \      }\n    }\n  }\n};\n#line 5 \"verify/library_checker/graph/scc.test.cpp\"\
    \n\nint main() {\n  int n, m;\n  cin >> n >> m;\n  vector<vector<int>> g(n);\n\
    \  for (int i = 0; i < m; i++) {\n    int u, v;\n    cin >> u >> v;\n    g[u].pb(v);\n\
    \  }\n  KosarajuSCC scc(g);\n  cout << scc.sccs << '\\n';\n  for (int i = 0; i\
    \ < scc.sccs; i++) {\n    cout << sz(scc.members[i]) << ' ';\n    for (int x :\
    \ scc.members[i]) {\n      cout << x << ' ';\n    }\n    cout << '\\n';\n  }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../boilerplate.hpp\"\
    \n#include \"../../../graphs/kosaraju_scc.hpp\"\n\nint main() {\n  int n, m;\n\
    \  cin >> n >> m;\n  vector<vector<int>> g(n);\n  for (int i = 0; i < m; i++)\
    \ {\n    int u, v;\n    cin >> u >> v;\n    g[u].pb(v);\n  }\n  KosarajuSCC scc(g);\n\
    \  cout << scc.sccs << '\\n';\n  for (int i = 0; i < scc.sccs; i++) {\n    cout\
    \ << sz(scc.members[i]) << ' ';\n    for (int x : scc.members[i]) {\n      cout\
    \ << x << ' ';\n    }\n    cout << '\\n';\n  }\n}"
  dependsOn:
  - graphs/kosaraju_scc.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/scc.test.cpp
  requiredBy: []
  timestamp: '2024-09-03 12:19:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/scc.test.cpp
- /verify/verify/library_checker/graph/scc.test.cpp.html
title: verify/library_checker/graph/scc.test.cpp
---
