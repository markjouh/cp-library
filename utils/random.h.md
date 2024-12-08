---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: template/template.h
    title: template/template.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
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
    path: verify/library_checker/data_structure/associative_array.test.cpp
    title: verify/library_checker/data_structure/associative_array.test.cpp
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
    path: verify/library_checker/string/suffix_array.test.cpp
    title: verify/library_checker/string/suffix_array.test.cpp
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
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"utils/random.h\"\n\n\n\n#include <cassert>\n#include <chrono>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <type_traits>\n\n\
    namespace cp_utils {\n\nusing namespace std;\n\nusing ll = long long;\n\nmt19937_64\
    \ twister(chrono::steady_clock::now().time_since_epoch().count());\n\ntemplate\
    \ <class T>\nT unifint(T lo, T hi) {\n    return uniform_int_distribution<T>(lo,\
    \ hi)(twister);\n}\ntemplate <class T>\nT unifreal(T lo, T hi) {\n    return uniform_real_distribution<T>(lo,\
    \ hi)(twister);\n}\n\nuint32_t xorshift32_state = twister() % UINT_MAX;\n\nuint32_t\
    \ xorshift32() {\n    uint32_t x = xorshift32_state;\n    x ^= x << 13;\n    x\
    \ ^= x >> 17;\n    x ^= x << 5;\n    return xorshift32_state = x;\n}\n\nint randint(int\
    \ mod) {\n    return xorshift32() % mod;\n}\nint randint(int lo, int hi) {\n \
    \   return lo + (lo < hi ? randint(hi - lo) : 0);\n}\n\nstring randstr(int n,\
    \ int k) {\n    string s(n, ' ');\n    for (int i = 0; i < n; i++) {\n       \
    \ s[i] = char('a' + randint(k));\n    }\n    return s;\n}\n\ntemplate <class T>\n\
    void randshuf(T l, T r) {\n    shuffle(l, r, twister);\n}\n\ntemplate <class T>\n\
    vector<T> randvec(int n, T lo, T hi) {\n    vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        res[i] = unifint<T>(lo, hi);\n    }\n    return\
    \ res;\n}\n\ntemplate <class T>\nvector<T> randvec(int n, T mod) {\n    return\
    \ randvec<T>(n, 0, mod - 1);\n}\n\nauto gen_tree_edges(int n) {\n    const vector<int>\
    \ prufer = randvec(n - 2, 0, n - 1);\n    vector<int> deg(n, 1);\n    for (int\
    \ x : prufer) {\n        deg[x]++;\n    }\n    priority_queue<int, vector<int>,\
    \ greater<>> leaves;\n    for (int i = 0; i < n; i++) {\n        if (deg[i] ==\
    \ 1) {\n            leaves.push(i);\n        }\n    }\n\n    vector<pair<int,\
    \ int>> res;\n    res.reserve(n - 1);\n    for (int v : prufer) {\n        int\
    \ u = leaves.top();\n        leaves.pop();\n\n        res.push_back(minmax(u,\
    \ v));\n        deg[u]--, deg[v]--;\n\n        if (deg[v] == 1) {\n          \
    \  leaves.push(v);\n        }\n    }\n\n    int x = -1, y = -1;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (deg[i] == 1) {\n            (x == -1 ? x :\
    \ y) = i;\n        }\n    }\n    res.emplace_back(x, y);\n\n    return res;\n\
    }\n\nauto gen_graph_edges(int n, int m) {\n    assert(m >= n - 1 && m <= 1ll *\
    \ n * (n - 1) / 2);\n\n    auto res = gen_tree_edges(n);\n    set<pair<int, int>>\
    \ have;\n    for (auto [u, v] : res) {\n        have.emplace(u, v);\n    }\n\n\
    \    while (ssize(res) < m) {\n        int u = randint(n), v = randint(n - 1);\n\
    \        v += v >= u;\n        if (u > v) {\n            swap(u, v);\n       \
    \ }\n        if (!have.count({u, v})) {\n            res.emplace_back(u, v);\n\
    \            have.emplace(u, v);\n        }\n    }\n    return res;\n}\n\nauto\
    \ gen_graph(int n, int m, bool dir = false) {\n    vector<vector<int>> g(n);\n\
    \    for (auto [u, v] : gen_graph_edges(n, m)) {\n        if (dir) {\n       \
    \     if (randint(1)) {\n                swap(u, v);\n            }\n        \
    \    g[u].push_back(v);\n        } else {\n            g[u].push_back(v);\n  \
    \          g[v].push_back(u);\n        }\n    }\n    return g;\n}\n\nauto gen_tree(int\
    \ n, bool dir = false) {\n    return gen_graph(n, n - 1, dir);\n}\n\nauto gen_weighted_graph(int\
    \ n, int m, int min_w = 1, int max_w = 100, bool dir = false) {\n    vector<vector<pair<int,\
    \ int>>> g(n);\n    for (auto [u, v] : gen_graph_edges(n, m)) {\n        const\
    \ int w = randint(min_w, max_w);\n        if (dir) {\n            if (randint(1))\
    \ {\n                swap(u, v);\n            }\n            g[u].emplace_back(v,\
    \ w);\n        } else {\n            g[u].emplace_back(v, w);\n            g[v].emplace_back(u,\
    \ w);\n        }\n    }\n    return g;\n}\n\nauto gen_weighted_tree(int n, int\
    \ min_w = 1, int max_w = 100, bool dir = false) {\n    return gen_weighted_graph(n,\
    \ n - 1, min_w, max_w, dir);\n}\n\n} // namespace cp_utils\n\n\n"
  code: "#ifndef RANDOM_H\n#define RANDOM_H\n\n#include <cassert>\n#include <chrono>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <type_traits>\n\n\
    namespace cp_utils {\n\nusing namespace std;\n\nusing ll = long long;\n\nmt19937_64\
    \ twister(chrono::steady_clock::now().time_since_epoch().count());\n\ntemplate\
    \ <class T>\nT unifint(T lo, T hi) {\n    return uniform_int_distribution<T>(lo,\
    \ hi)(twister);\n}\ntemplate <class T>\nT unifreal(T lo, T hi) {\n    return uniform_real_distribution<T>(lo,\
    \ hi)(twister);\n}\n\nuint32_t xorshift32_state = twister() % UINT_MAX;\n\nuint32_t\
    \ xorshift32() {\n    uint32_t x = xorshift32_state;\n    x ^= x << 13;\n    x\
    \ ^= x >> 17;\n    x ^= x << 5;\n    return xorshift32_state = x;\n}\n\nint randint(int\
    \ mod) {\n    return xorshift32() % mod;\n}\nint randint(int lo, int hi) {\n \
    \   return lo + (lo < hi ? randint(hi - lo) : 0);\n}\n\nstring randstr(int n,\
    \ int k) {\n    string s(n, ' ');\n    for (int i = 0; i < n; i++) {\n       \
    \ s[i] = char('a' + randint(k));\n    }\n    return s;\n}\n\ntemplate <class T>\n\
    void randshuf(T l, T r) {\n    shuffle(l, r, twister);\n}\n\ntemplate <class T>\n\
    vector<T> randvec(int n, T lo, T hi) {\n    vector<T> res(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        res[i] = unifint<T>(lo, hi);\n    }\n    return\
    \ res;\n}\n\ntemplate <class T>\nvector<T> randvec(int n, T mod) {\n    return\
    \ randvec<T>(n, 0, mod - 1);\n}\n\nauto gen_tree_edges(int n) {\n    const vector<int>\
    \ prufer = randvec(n - 2, 0, n - 1);\n    vector<int> deg(n, 1);\n    for (int\
    \ x : prufer) {\n        deg[x]++;\n    }\n    priority_queue<int, vector<int>,\
    \ greater<>> leaves;\n    for (int i = 0; i < n; i++) {\n        if (deg[i] ==\
    \ 1) {\n            leaves.push(i);\n        }\n    }\n\n    vector<pair<int,\
    \ int>> res;\n    res.reserve(n - 1);\n    for (int v : prufer) {\n        int\
    \ u = leaves.top();\n        leaves.pop();\n\n        res.push_back(minmax(u,\
    \ v));\n        deg[u]--, deg[v]--;\n\n        if (deg[v] == 1) {\n          \
    \  leaves.push(v);\n        }\n    }\n\n    int x = -1, y = -1;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (deg[i] == 1) {\n            (x == -1 ? x :\
    \ y) = i;\n        }\n    }\n    res.emplace_back(x, y);\n\n    return res;\n\
    }\n\nauto gen_graph_edges(int n, int m) {\n    assert(m >= n - 1 && m <= 1ll *\
    \ n * (n - 1) / 2);\n\n    auto res = gen_tree_edges(n);\n    set<pair<int, int>>\
    \ have;\n    for (auto [u, v] : res) {\n        have.emplace(u, v);\n    }\n\n\
    \    while (ssize(res) < m) {\n        int u = randint(n), v = randint(n - 1);\n\
    \        v += v >= u;\n        if (u > v) {\n            swap(u, v);\n       \
    \ }\n        if (!have.count({u, v})) {\n            res.emplace_back(u, v);\n\
    \            have.emplace(u, v);\n        }\n    }\n    return res;\n}\n\nauto\
    \ gen_graph(int n, int m, bool dir = false) {\n    vector<vector<int>> g(n);\n\
    \    for (auto [u, v] : gen_graph_edges(n, m)) {\n        if (dir) {\n       \
    \     if (randint(1)) {\n                swap(u, v);\n            }\n        \
    \    g[u].push_back(v);\n        } else {\n            g[u].push_back(v);\n  \
    \          g[v].push_back(u);\n        }\n    }\n    return g;\n}\n\nauto gen_tree(int\
    \ n, bool dir = false) {\n    return gen_graph(n, n - 1, dir);\n}\n\nauto gen_weighted_graph(int\
    \ n, int m, int min_w = 1, int max_w = 100, bool dir = false) {\n    vector<vector<pair<int,\
    \ int>>> g(n);\n    for (auto [u, v] : gen_graph_edges(n, m)) {\n        const\
    \ int w = randint(min_w, max_w);\n        if (dir) {\n            if (randint(1))\
    \ {\n                swap(u, v);\n            }\n            g[u].emplace_back(v,\
    \ w);\n        } else {\n            g[u].emplace_back(v, w);\n            g[v].emplace_back(u,\
    \ w);\n        }\n    }\n    return g;\n}\n\nauto gen_weighted_tree(int n, int\
    \ min_w = 1, int max_w = 100, bool dir = false) {\n    return gen_weighted_graph(n,\
    \ n - 1, min_w, max_w, dir);\n}\n\n} // namespace cp_utils\n\n#endif // RANDOM_H"
  dependsOn: []
  isVerificationFile: false
  path: utils/random.h
  requiredBy:
  - template/template.h
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/aizu/alds1/number_of_inversions.test.cpp
  - verify/aizu/ntl/power.test.cpp
  - verify/aizu/dsl/rmq.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
  - verify/library_checker/data_structure/static_rmq.test.cpp
  - verify/library_checker/data_structure/set_xor_min.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/associative_array.test.cpp
  - verify/library_checker/string/suffix_array.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/scc.test.cpp
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - verify/library_checker/tree/lca.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
documentation_of: utils/random.h
layout: document
redirect_from:
- /library/utils/random.h
- /library/utils/random.h.html
title: utils/random.h
---
