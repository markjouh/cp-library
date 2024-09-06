---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/kosaraju_scc.hpp
    title: graphs/kosaraju_scc.hpp
  - icon: ':question:'
    path: utils/random.hpp
    title: utils/random.hpp
  - icon: ':question:'
    path: utils/timer.hpp
    title: utils/timer.hpp
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
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 2 \"utils/random.hpp\"\
    \n\n#include <type_traits>\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \n// ----------------------------------------------------\n// Section: Basic random\
    \ data generation\n// ----------------------------------------------------\n\n\
    template <class T>\nT rnd(T lo, T hi) {\n  static_assert(is_arithmetic_v<T>, \"\
    Invalid type for rnd()\");\n  if constexpr (is_integral_v<T>) {\n    return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n  } else {\n    return uniform_real_distribution<T>(lo, hi)(rng_64);\n\
    \  }\n}\n\ntemplate <class T>\nconstexpr T def_val() {\n  if constexpr (is_floating_point_v<T>)\
    \ {\n    return 1;\n  } else {\n    return numeric_limits<T>::max() / 2;\n  }\n\
    }\n\n// ----------------------------------------------------\n//  => Bool wrapper\n\
    // ----------------------------------------------------\n\nbool randbool() {\n\
    \  return rnd<int>(0, 1);\n}\n\n// ----------------------------------------------------\n\
    //  => Int wrappers\n// ----------------------------------------------------\n\
    \nint randint(int lo, int hi) {\n  return rnd<int>(lo, hi);\n}\n\nint randint(int\
    \ hi) {\n  return randint(0, hi - 1);\n}\n\nint randint() {\n  return randint(def_val<int>());\n\
    }\n\n// ----------------------------------------------------\n//  => Long long\
    \ wrappers\n// ----------------------------------------------------\n\nlong long\
    \ randlong(long long lo, long long hi) {\n  return rnd<long long>(lo, hi);\n}\n\
    \nlong long randlong(long long hi) {\n  return randlong(0, hi);\n}\n\nlong long\
    \ randlong() {\n  return randlong(def_val<long long>());\n}\n\n// ----------------------------------------------------\n\
    //  => Double wrappers\n// ----------------------------------------------------\n\
    \ndouble randdoub(double lo, double hi) {\n  return rnd<double>(lo, hi);\n}\n\n\
    double randdoub(double hi) {\n  return randdoub(0, hi);\n}\n\ndouble randdoub()\
    \ {\n  return randdoub(1);\n}\n\n// ----------------------------------------------------\n\
    //  => Vector wrappers\n// ----------------------------------------------------\n\
    \ntemplate <class T>\nvector<T> randvec(int n, T lo, T hi) {\n  vector<T> res(n);\n\
    \  for (int i = 0; i < n; i++) {\n    res[i] = rnd<T>(lo, hi);\n  }\n  return\
    \ res;\n}\n\ntemplate <class T>\nvector<T> randvec(int n, T hi) {\n  return randvec<T>(n,\
    \ 0, hi);\n}\n\ntemplate <class T>\nvector<T> randvec(int n) {\n  return randvec<T>(n,\
    \ def_val<T>());\n}\n\n// ----------------------------------------------------\n\
    //  => Array wrappers\n// ----------------------------------------------------\n\
    \ntemplate <class T, size_t N>\narray<T, N> randarr(T lo, T hi) {\n  array<T,\
    \ N> res;\n  for (int i = 0; i < N; i++) {\n    res[i] = rnd<T>(lo, hi);\n  }\n\
    \  return res;\n}\n\ntemplate <class T, size_t N>\narray<T, N> randarr(T hi) {\n\
    \  return randarr<T, N>(0, hi);\n}\n\ntemplate <class T, size_t N>\narray<T, N>\
    \ randarr() {\n  return randarr<T, N>(def_val<T>());\n}\n\n// ----------------------------------------------------\n\
    // Section: Graph generation from Prufer sequences\n// ----------------------------------------------------\n\
    \nvector<pair<int, int>> gen_tree_edges(int n) {\n  const vector<int> prufer =\
    \ randvec(n - 2, 0, n - 1);\n  vector<int> deg(n, 1);\n  for (int x : prufer)\
    \ {\n    deg[x]++;\n  }\n  priority_queue<int, vector<int>, greater<>> leaves;\n\
    \  for (int i = 0; i < n; i++) {\n    if (deg[i] == 1) {\n      leaves.push(i);\n\
    \    }\n  }\n\n  vector<pair<int, int>> res;\n  res.reserve(n - 1);\n  for (int\
    \ v : prufer) {\n    int u = leaves.top();\n    leaves.pop();\n\n    res.push_back(minmax(u,\
    \ v));\n    deg[u]--, deg[v]--;\n\n    if (deg[v] == 1) {\n      leaves.push(v);\n\
    \    }\n  }\n\n  int r1 = -1, r2 = -1;\n  for (int i = 0; i < n; i++) {\n    if\
    \ (deg[i] == 1) {\n      (r1 == -1 ? r1 : r2) = i;\n    }\n  }\n  res.emplace_back(r1,\
    \ r2);\n\n  return res;\n}\n\nvector<pair<int, int>> gen_graph_edges(int n, int\
    \ m) {\n  assert(m >= n - 1 && m <= 1ll * n * (n - 1) / 2);\n\n  auto res = gen_tree_edges(n);\n\
    \  set<pair<int, int>> have;\n  for (auto [u, v] : res) {\n    have.emplace(u,\
    \ v);\n  }\n\n  while (ssize(res) < m) {\n    int u = randint(n), v = randint(n\
    \ - 1);\n    v += v >= u;\n    if (u > v) {\n      swap(u, v);\n    }\n    if\
    \ (!have.count({u, v})) {\n      res.emplace_back(u, v);\n      have.emplace(u,\
    \ v);\n    }\n  }\n  return res;\n}\n\n// ----------------------------------------------------\n\
    //  => Adjacency list wrappers\n// ----------------------------------------------------\n\
    \nvector<vector<int>> gen_graph(int n, int m, bool dir = false) {\n  vector<vector<int>>\
    \ g(n);\n  for (auto [u, v] : gen_graph_edges(n, m)) {\n    if (dir) {\n     \
    \ if (randbool()) {\n        swap(u, v);\n      }\n      g[u].push_back(v);\n\
    \    } else {\n      g[u].push_back(v);\n      g[v].push_back(u);\n    }\n  }\n\
    \  return g;\n}\n\nvector<vector<pair<int, int>>> gen_w_graph(int n, int m, int\
    \ lo = 1, int hi = def_val<int>(), bool dir = false) {\n  vector<vector<pair<int,\
    \ int>>> g(n);\n  for (auto [u, v] : gen_graph_edges(n, m)) {\n    const int w\
    \ = randint(lo, hi);\n    if (dir) {\n      if (randbool()) {\n        swap(u,\
    \ v);\n      }\n      g[u].emplace_back(v, w);\n    } else {\n      g[u].emplace_back(v,\
    \ w);\n      g[v].emplace_back(u, w);\n    }\n  }\n  return g;\n}\n#line 2 \"\
    utils/timer.hpp\"\n\nchrono::time_point<chrono::high_resolution_clock> timer;\n\
    \nvoid set_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n}\n\
    \nlong long elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}\n#line 7 \"verify/boilerplate.hpp\"\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n#define\
    \ eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long long;\n\
    \ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a = b,\
    \ 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return b\
    \ > a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf =\
    \ numeric_limits<T>::max() / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
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
  - utils/random.hpp
  - utils/timer.hpp
  - graphs/kosaraju_scc.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/scc.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 22:57:47-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/scc.test.cpp
- /verify/verify/library_checker/graph/scc.test.cpp.html
title: verify/library_checker/graph/scc.test.cpp
---
