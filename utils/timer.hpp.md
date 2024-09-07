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
  bundledCode: "#line 2 \"utils/timer.hpp\"\n\nchrono::time_point<chrono::high_resolution_clock>\
    \ timer;\n\nvoid set_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n\
    }\n\nlong long elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}\n"
  code: "#pragma once\n\nchrono::time_point<chrono::high_resolution_clock> timer;\n\
    \nvoid set_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n}\n\
    \nlong long elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}"
  dependsOn: []
  isVerificationFile: false
  path: utils/timer.hpp
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
documentation_of: utils/timer.hpp
layout: document
redirect_from:
- /library/utils/timer.hpp
- /library/utils/timer.hpp.html
title: utils/timer.hpp
---
