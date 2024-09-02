---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/dijkstras.hpp
    title: graphs/dijkstras.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/library_checker/graph/shortest_path.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#line 1 \"\
    verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <climits>\n#include <cmath>\n\
    #include <cstdint>\n#include <cstring>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\nusing namespace std;\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class\
    \ T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n#else\n  int\
    \ res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n}\n\n\
    template <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1\
    \ : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return b >\
    \ a ? a = b, 1 : 0;\n}\n\nconst int INF = INT_MAX / 2;\nconst ll INFLL = LLONG_MAX\
    \ / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"graphs/dijkstras.hpp\"\n\ntemplate <class T>\nauto dijkstras(const\
    \ vector<vector<pair<int, int>>> &g, int start = 0) {\n  priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\n  vector<T> dist(sz(g),\
    \ numeric_limits<T>::max());\n  vector<int> from(sz(g), -1);\n  \n  dist[start]\
    \ = 0;\n  pq.emplace(0, start);\n\n  while (sz(pq)) {\n    auto [d, u] = pq.top();\n\
    \    pq.pop();\n    if (d != dist[u]) {\n      continue;\n    }\n    for (auto\
    \ [v, w] : g[u]) {\n      if (ckmin(dist[v], d + w)) {\n        from[v] = u;\n\
    \        pq.emplace(dist[v], v);\n      }\n    }\n  }\n  return make_pair(dist,\
    \ from);\n}\n#line 5 \"verify/library_checker/graph/shortest_path.test.cpp\"\n\
    \nint main() {\n  int n, m, s, t;\n  cin >> n >> m >> s >> t;\n  vector<vector<pii>>\
    \ g(n);\n  for (int i = 0; i < m; i++) {\n    int u, v, w;\n    cin >> u >> v\
    \ >> w;\n    g[u].eb(v, w);\n  }\n  auto [dist, from] = dijkstras<ll>(g, s);\n\
    \  if (dist[t] != numeric_limits<ll>::max()) {\n    cout << dist[t] << ' ';\n\
    \    vector<pii> path;\n    int p = t;\n    while (p != s) {\n      path.eb(from[p],\
    \ p);\n      p = from[p];\n    }\n    reverse(all(path));\n    cout << sz(path)\
    \ << '\\n';\n    for (auto [u, v] : path) {\n      cout << u << ' ' << v << '\\\
    n';\n    }\n  } else {\n    cout << -1 << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../../boilerplate.hpp\"\n#include \"../../../graphs/dijkstras.hpp\"\n\nint\
    \ main() {\n  int n, m, s, t;\n  cin >> n >> m >> s >> t;\n  vector<vector<pii>>\
    \ g(n);\n  for (int i = 0; i < m; i++) {\n    int u, v, w;\n    cin >> u >> v\
    \ >> w;\n    g[u].eb(v, w);\n  }\n  auto [dist, from] = dijkstras<ll>(g, s);\n\
    \  if (dist[t] != numeric_limits<ll>::max()) {\n    cout << dist[t] << ' ';\n\
    \    vector<pii> path;\n    int p = t;\n    while (p != s) {\n      path.eb(from[p],\
    \ p);\n      p = from[p];\n    }\n    reverse(all(path));\n    cout << sz(path)\
    \ << '\\n';\n    for (auto [u, v] : path) {\n      cout << u << ' ' << v << '\\\
    n';\n    }\n  } else {\n    cout << -1 << '\\n';\n  }\n}"
  dependsOn:
  - graphs/dijkstras.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-09-01 20:48:11-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/shortest_path.test.cpp
- /verify/verify/library_checker/graph/shortest_path.test.cpp.html
title: verify/library_checker/graph/shortest_path.test.cpp
---
