---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/custom/numeric/binary_search_reals.test.cpp
    title: verify/custom/numeric/binary_search_reals.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/utils/debug.test.cpp
    title: verify/custom/utils/debug.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/utils/encode.test.cpp
    title: verify/custom/utils/encode.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/utils/random_graph.test.cpp
    title: verify/custom/utils/random_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/utils/timer.test.cpp
    title: verify/custom/utils/timer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/random.hpp\"\n\n#include <type_traits>\n\nmt19937_64\
    \ rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\ntemplate\
    \ <class T = int>\nT rnd(T lo, T hi) {\n  static_assert(is_arithmetic_v<T>, \"\
    Invalid type for rnd()\");\n  if constexpr (is_integral_v<T>) {\n    return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n  } else {\n    return uniform_real_distribution<T>(lo, hi)(rng_64);\n\
    \  }\n}\n\ntemplate <class T = int>\nvec<T> rnd_vec(int n, T lo, T hi) {\n  vec<T>\
    \ res(n);\n  rep(i, n) {\n    res[i] = rnd<T>(lo, hi);\n  }\n  return res;\n}\n\
    \nvec<pii> rnd_tree_edges(int n) {\n  const vec<int> prufer = rnd_vec(n - 2, 0,\
    \ n - 1);\n  vec<int> deg(n, 1);\n  for (int x : prufer) {\n    deg[x]++;\n  }\n\
    \  priority_queue<int, vec<int>, greater<>> leaves;\n  rep(i, n) {\n    if (deg[i]\
    \ == 1) {\n      leaves.push(i);\n    }\n  }\n\n  vec<pii> res;\n  res.reserve(n\
    \ - 1);\n  for (int v : prufer) {\n    int u = leaves.top();\n    leaves.pop();\n\
    \n    res.pb(minmax(u, v));\n    deg[u]--, deg[v]--;\n\n    if (deg[v] == 1) {\n\
    \      leaves.push(v);\n    }\n  }\n\n  int r1 = -1, r2 = -1;\n  rep(i, n) {\n\
    \    if (deg[i] == 1) {\n      (r1 == -1 ? r1 : r2) = i;\n    }\n  }\n  assert(r2\
    \ != -1);\n  res.eb(r1, r2);\n\n  return res;\n}\n\nvec<pii> rnd_graph_edges(int\
    \ n, int m) {\n  assert(m >= n - 1 && m <= 1ll * n * (n - 1) / 2);\n\n  auto res\
    \ = rnd_tree_edges(n);\n  set<pii> have;\n  for (auto [u, v] : res) {\n    have.emplace(u,\
    \ v);\n  }\n\n  while (sz(res) < m) {\n    int u = rnd<>(0, n - 1), v = rnd<>(0,\
    \ n - 2);\n    v += v >= u;\n    if (u > v) {\n      swap(u, v);\n    }\n    if\
    \ (!have.count({u, v})) {\n      res.eb(u, v);\n      have.emplace(u, v);\n  \
    \  }\n  }\n  return res;\n}\n\nvec<vec<int>> rnd_graph(int n, int m, bool directed\
    \ = false) {\n  vec<vec<int>> g(n);\n  for (auto [u, v] : rnd_graph_edges(n, m))\
    \ {\n    if (directed) {\n      if (rnd<>(0, 1)) {\n        swap(u, v);\n    \
    \  }\n      g[u].pb(v);\n    } else {\n      g[u].pb(v);\n      g[v].pb(u);\n\
    \    }\n  }\n  return g;\n}\n\nvec<vec<pii>> rnd_wgraph(int n, int m, int lo =\
    \ 1, int hi = inf<>, bool directed = false) {\n  vec<vec<pii>> g(n);\n  for (auto\
    \ [u, v] : rnd_graph_edges(n, m)) {\n    const int w = rnd<>(lo, hi);\n    if\
    \ (directed) {\n      if (rnd<>(0, 1)) {\n        swap(u, v);\n      }\n     \
    \ g[u].eb(v, w);\n    } else {\n      g[u].eb(v, w);\n      g[v].eb(u, w);\n \
    \   }\n  }\n  return g;\n}\n"
  code: "#pragma once\n\n#include <type_traits>\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T = int>\nT rnd(T lo, T hi) {\n  static_assert(is_arithmetic_v<T>,\
    \ \"Invalid type for rnd()\");\n  if constexpr (is_integral_v<T>) {\n    return\
    \ uniform_int_distribution<T>(lo, hi)(rng_64);\n  } else {\n    return uniform_real_distribution<T>(lo,\
    \ hi)(rng_64);\n  }\n}\n\ntemplate <class T = int>\nvec<T> rnd_vec(int n, T lo,\
    \ T hi) {\n  vec<T> res(n);\n  rep(i, n) {\n    res[i] = rnd<T>(lo, hi);\n  }\n\
    \  return res;\n}\n\nvec<pii> rnd_tree_edges(int n) {\n  const vec<int> prufer\
    \ = rnd_vec(n - 2, 0, n - 1);\n  vec<int> deg(n, 1);\n  for (int x : prufer) {\n\
    \    deg[x]++;\n  }\n  priority_queue<int, vec<int>, greater<>> leaves;\n  rep(i,\
    \ n) {\n    if (deg[i] == 1) {\n      leaves.push(i);\n    }\n  }\n\n  vec<pii>\
    \ res;\n  res.reserve(n - 1);\n  for (int v : prufer) {\n    int u = leaves.top();\n\
    \    leaves.pop();\n\n    res.pb(minmax(u, v));\n    deg[u]--, deg[v]--;\n\n \
    \   if (deg[v] == 1) {\n      leaves.push(v);\n    }\n  }\n\n  int r1 = -1, r2\
    \ = -1;\n  rep(i, n) {\n    if (deg[i] == 1) {\n      (r1 == -1 ? r1 : r2) = i;\n\
    \    }\n  }\n  assert(r2 != -1);\n  res.eb(r1, r2);\n\n  return res;\n}\n\nvec<pii>\
    \ rnd_graph_edges(int n, int m) {\n  assert(m >= n - 1 && m <= 1ll * n * (n -\
    \ 1) / 2);\n\n  auto res = rnd_tree_edges(n);\n  set<pii> have;\n  for (auto [u,\
    \ v] : res) {\n    have.emplace(u, v);\n  }\n\n  while (sz(res) < m) {\n    int\
    \ u = rnd<>(0, n - 1), v = rnd<>(0, n - 2);\n    v += v >= u;\n    if (u > v)\
    \ {\n      swap(u, v);\n    }\n    if (!have.count({u, v})) {\n      res.eb(u,\
    \ v);\n      have.emplace(u, v);\n    }\n  }\n  return res;\n}\n\nvec<vec<int>>\
    \ rnd_graph(int n, int m, bool directed = false) {\n  vec<vec<int>> g(n);\n  for\
    \ (auto [u, v] : rnd_graph_edges(n, m)) {\n    if (directed) {\n      if (rnd<>(0,\
    \ 1)) {\n        swap(u, v);\n      }\n      g[u].pb(v);\n    } else {\n     \
    \ g[u].pb(v);\n      g[v].pb(u);\n    }\n  }\n  return g;\n}\n\nvec<vec<pii>>\
    \ rnd_wgraph(int n, int m, int lo = 1, int hi = inf<>, bool directed = false)\
    \ {\n  vec<vec<pii>> g(n);\n  for (auto [u, v] : rnd_graph_edges(n, m)) {\n  \
    \  const int w = rnd<>(lo, hi);\n    if (directed) {\n      if (rnd<>(0, 1)) {\n\
    \        swap(u, v);\n      }\n      g[u].eb(v, w);\n    } else {\n      g[u].eb(v,\
    \ w);\n      g[v].eb(u, w);\n    }\n  }\n  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utils/random.hpp
  requiredBy: []
  timestamp: '2024-09-04 17:54:50-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/custom/utils/random_graph.test.cpp
  - verify/custom/utils/encode.test.cpp
  - verify/custom/utils/timer.test.cpp
  - verify/custom/utils/debug.test.cpp
  - verify/custom/numeric/binary_search_reals.test.cpp
documentation_of: utils/random.hpp
layout: document
redirect_from:
- /library/utils/random.hpp
- /library/utils/random.hpp.html
title: utils/random.hpp
---
