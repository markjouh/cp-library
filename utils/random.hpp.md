---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/priority_queue.test.cpp
    title: verify/aizu/alds1/priority_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/ntl/power.test.cpp
    title: verify/aizu/ntl/power.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/datastructure/fenwick_tree_range_add.test.cpp
    title: verify/custom/datastructure/fenwick_tree_range_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/datastructure/segment_tree_sparse.test.cpp
    title: verify/custom/datastructure/segment_tree_sparse.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/associative_array.test.cpp
    title: verify/library_checker/data_structure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
    title: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/set_xor_min.test.cpp
    title: verify/library_checker/data_structure/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/scc.test.cpp
    title: verify/library_checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: verify/library_checker/number_theory/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/lca.test.cpp
    title: verify/library_checker/tree/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/random.hpp\"\n\n#include <type_traits>\n\nmt19937_64\
    \ rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\n// ----------------------------------------------------\n\
    // Section: Basic random data generation\n// ----------------------------------------------------\n\
    \ntemplate <class T>\nT rnd(T lo, T hi) {\n  static_assert(is_arithmetic_v<T>,\
    \ \"Invalid type for rnd()\");\n  if constexpr (is_integral_v<T>) {\n    return\
    \ uniform_int_distribution<T>(lo, hi)(rng_64);\n  } else {\n    return uniform_real_distribution<T>(lo,\
    \ hi)(rng_64);\n  }\n}\n\ntemplate <class T>\nconstexpr T def_val() {\n  if constexpr\
    \ (is_floating_point_v<T>) {\n    return 1;\n  } else {\n    return numeric_limits<T>::max()\
    \ / 2;\n  }\n}\n\n// ----------------------------------------------------\n//\
    \  => Bool wrapper\n// ----------------------------------------------------\n\n\
    bool randbool() {\n  return rnd<int>(0, 1);\n}\n\n// ----------------------------------------------------\n\
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
    \ w);\n      g[v].emplace_back(u, w);\n    }\n  }\n  return g;\n}\n"
  code: "#pragma once\n\n#include <type_traits>\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \ w);\n      g[v].emplace_back(u, w);\n    }\n  }\n  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: utils/random.hpp
  requiredBy: []
  timestamp: '2024-09-05 17:05:59-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rmq.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/aizu/ntl/power.test.cpp
  - verify/aizu/alds1/priority_queue.test.cpp
  - verify/aizu/alds1/number_of_inversions.test.cpp
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
  - verify/library_checker/tree/lca.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - verify/library_checker/graph/scc.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/data_structure/static_rmq.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
  - verify/library_checker/data_structure/set_xor_min.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/data_structure/associative_array.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/custom/datastructure/segment_tree_sparse.test.cpp
  - verify/custom/datastructure/fenwick_tree_range_add.test.cpp
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
