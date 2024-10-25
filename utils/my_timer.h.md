---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/my_random.h
    title: utils/my_random.h
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
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
  bundledCode: "#line 2 \"utils/my_timer.h\"\n\n#include <cassert>\n#include <chrono>\n\
    #include <climits>\n#include <iostream>\n#include <map>\n#include <unistd.h>\n\
    #include <thread>\n\n#line 2 \"utils/my_random.h\"\n\n#line 5 \"utils/my_random.h\"\
    \n#include <queue>\n#include <random>\n#include <set>\n#include <type_traits>\n\
    \nusing namespace std;\n\nmt19937_64 rng_engine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \n// Core of random data generation\ntemplate <class T>\nT my_rand(T lo, T hi)\
    \ {\n    static_assert(is_arithmetic_v<T>, \"Invalid type for my_rand()\");\n\
    \    if constexpr (is_integral_v<T>) {\n        return uniform_int_distribution<T>(lo,\
    \ hi)(rng_engine);\n    } else {\n        return uniform_real_distribution<T>(lo,\
    \ hi)(rng_engine);\n    }\n}\n\n// Default value - uniform [0, 1] for reals\n\
    template <class T>\nconstexpr T default_val() {\n    if constexpr (is_floating_point_v<T>)\
    \ {\n        return 1;\n    } else {\n        return numeric_limits<T>::max()\
    \ / 2;\n    }\n}\n\ntemplate <class T>\nvoid rand_shuf(T &a) {\n    shuffle(begin(a),\
    \ end(a), rng_engine);\n}\n\nbool rand_bool() {\n    return my_rand<int>(0, 1);\n\
    }\n\nint rand_int(int lo, int hi) {\n    return my_rand<int>(lo, hi);\n}\n\nint\
    \ rand_int(int hi) {\n    return rand_int(0, hi - 1);\n}\n\nint rand_int() {\n\
    \    return rand_int(default_val<int>());\n}\n\nlong long rand_ll(long long lo,\
    \ long long hi) {\n    return my_rand<long long>(lo, hi);\n}\n\nlong long rand_ll(long\
    \ long hi) {\n    return rand_ll(0, hi);\n}\n\nlong long rand_ll() {\n    return\
    \ rand_ll(default_val<long long>());\n}\n\ndouble rand_db(double lo, double hi)\
    \ {\n    return my_rand<double>(lo, hi);\n}\n\ndouble rand_db(double hi) {\n \
    \   return rand_db(0, hi);\n}\n\ndouble rand_db() {\n    return rand_db(1);\n\
    }\n\nstring rand_str(int n, int k) {\n    string s(n, ' ');\n    for (int i =\
    \ 0; i < n; i++) {\n        s[i] = char('a' + rand_int(k));\n    }\n    return\
    \ s;\n}\n\ntemplate <class T>\nvector<T> rand_vec(int n, T lo, T hi) {\n    vector<T>\
    \ res(n);\n    for (int i = 0; i < n; i++) {\n        res[i] = my_rand<T>(lo,\
    \ hi);\n    }\n    return res;\n}\n\ntemplate <class T>\nvector<T> rand_vec(int\
    \ n, T hi) {\n    return rand_vec<T>(n, 0, hi);\n}\n\ntemplate <class T>\nvector<T>\
    \ rand_vec(int n) {\n    return rand_vec<T>(n, default_val<T>());\n}\n\ntemplate\
    \ <class T, size_t N>\narray<T, N> rand_arr(T lo, T hi) {\n    array<T, N> res;\n\
    \    for (int i = 0; i < int(N); i++) {\n        res[i] = my_rand<T>(lo, hi);\n\
    \    }\n    return res;\n}\n\ntemplate <class T, size_t N>\narray<T, N> rand_arr(T\
    \ hi) {\n    return rand_arr<T, N>(0, hi);\n}\n\ntemplate <class T, size_t N>\n\
    array<T, N> rand_arr() {\n    return rand_arr<T, N>(default_val<T>());\n}\n\n\
    // Uniformly generate trees from random Prufer sequences\nvector<pair<int, int>>\
    \ gen_tree_edges(int n) {\n    const vector<int> prufer = rand_vec(n - 2, 0, n\
    \ - 1);\n    vector<int> deg(n, 1);\n    for (int x : prufer) {\n        deg[x]++;\n\
    \    }\n    priority_queue<int, vector<int>, greater<>> leaves;\n    for (int\
    \ i = 0; i < n; i++) {\n        if (deg[i] == 1) {\n            leaves.push(i);\n\
    \        }\n    }\n\n    vector<pair<int, int>> res;\n    res.reserve(n - 1);\n\
    \    for (int v : prufer) {\n        int u = leaves.top();\n        leaves.pop();\n\
    \n        res.push_back(minmax(u, v));\n        deg[u]--, deg[v]--;\n\n      \
    \  if (deg[v] == 1) {\n            leaves.push(v);\n        }\n    }\n\n    int\
    \ x = -1, y = -1;\n    for (int i = 0; i < n; i++) {\n        if (deg[i] == 1)\
    \ {\n            (x == -1 ? x : y) = i;\n        }\n    }\n    res.emplace_back(x,\
    \ y);\n\n    return res;\n}\n\n// Generate arbitrary graphs by adding extra edges\
    \ to a spanning tree (probably not uniform, but good enough)\nvector<pair<int,\
    \ int>> gen_graph_edges(int n, int m) {\n    assert(m >= n - 1 && m <= 1ll * n\
    \ * (n - 1) / 2);\n\n    auto res = gen_tree_edges(n);\n    set<pair<int, int>>\
    \ have;\n    for (auto [u, v] : res) {\n        have.emplace(u, v);\n    }\n\n\
    \    while (ssize(res) < m) {\n        int u = rand_int(n), v = rand_int(n - 1);\n\
    \        v += v >= u;\n        if (u > v) {\n            swap(u, v);\n       \
    \ }\n        if (!have.count({u, v})) {\n            res.emplace_back(u, v);\n\
    \            have.emplace(u, v);\n        }\n    }\n    return res;\n}\n\nvector<vector<int>>\
    \ gen_graph(int n, int m, bool directed = false) {\n    vector<vector<int>> g(n);\n\
    \    for (auto [u, v] : gen_graph_edges(n, m)) {\n        if (directed) {\n  \
    \          if (rand_bool()) {\n                swap(u, v);\n            }\n  \
    \          g[u].push_back(v);\n        } else {\n            g[u].push_back(v);\n\
    \            g[v].push_back(u);\n        }\n    }\n    return g;\n}\n\nvector<vector<pair<int,\
    \ int>>> gen_weighted_graph(int n, int m, int lo = 1, int hi = default_val<int>(),\
    \ bool directed = false) {\n    vector<vector<pair<int, int>>> g(n);\n    for\
    \ (auto [u, v] : gen_graph_edges(n, m)) {\n        const int w = rand_int(lo,\
    \ hi);\n        if (directed) {\n            if (rand_bool()) {\n            \
    \    swap(u, v);\n            }\n            g[u].emplace_back(v, w);\n      \
    \  } else {\n            g[u].emplace_back(v, w);\n            g[v].emplace_back(u,\
    \ w);\n        }\n    }\n    return g;\n}\n#line 12 \"utils/my_timer.h\"\n\nnamespace\
    \ timer {\n\nusing namespace std;\nusing namespace chrono;\n\ntime_point<high_resolution_clock>\
    \ timer;\n\nvoid start() {\n    timer = high_resolution_clock::now();\n}\n\nlong\
    \ long get_ns() {\n    return duration_cast<nanoseconds>(high_resolution_clock::now()\
    \ - timer).count();\n}\nlong long get_ms() {\n    return duration_cast<milliseconds>(high_resolution_clock::now()\
    \ - timer).count();\n}\n\nvoid sleep_ns(long long ns) {\n    this_thread::sleep_for(chrono::nanoseconds(ns));\n\
    }\nvoid sleep_ms(long long ms) {\n    this_thread::sleep_for(chrono::milliseconds(ms));\n\
    }\n\n};\n"
  code: "#pragma once\n\n#include <cassert>\n#include <chrono>\n#include <climits>\n\
    #include <iostream>\n#include <map>\n#include <unistd.h>\n#include <thread>\n\n\
    #include \"my_random.h\"\n\nnamespace timer {\n\nusing namespace std;\nusing namespace\
    \ chrono;\n\ntime_point<high_resolution_clock> timer;\n\nvoid start() {\n    timer\
    \ = high_resolution_clock::now();\n}\n\nlong long get_ns() {\n    return duration_cast<nanoseconds>(high_resolution_clock::now()\
    \ - timer).count();\n}\nlong long get_ms() {\n    return duration_cast<milliseconds>(high_resolution_clock::now()\
    \ - timer).count();\n}\n\nvoid sleep_ns(long long ns) {\n    this_thread::sleep_for(chrono::nanoseconds(ns));\n\
    }\nvoid sleep_ms(long long ms) {\n    this_thread::sleep_for(chrono::milliseconds(ms));\n\
    }\n\n};"
  dependsOn:
  - utils/my_random.h
  isVerificationFile: false
  path: utils/my_timer.h
  requiredBy:
  - misc/template.h
  timestamp: '2024-10-12 02:07:15-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/priority_queue.test.cpp
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
  - verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
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
documentation_of: utils/my_timer.h
layout: document
redirect_from:
- /library/utils/my_timer.h
- /library/utils/my_timer.h.html
title: utils/my_timer.h
---
