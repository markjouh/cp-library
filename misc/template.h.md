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
  - icon: ':x:'
    path: verify/custom/datastructure/fenwick_tree_range_add.test.cpp
    title: verify/custom/datastructure/fenwick_tree_range_add.test.cpp
  - icon: ':x:'
    path: verify/custom/datastructure/segment_tree_sparse.test.cpp
    title: verify/custom/datastructure/segment_tree_sparse.test.cpp
  - icon: ':x:'
    path: verify/custom/numeric/binary_search_reals.test.cpp
    title: verify/custom/numeric/binary_search_reals.test.cpp
  - icon: ':x:'
    path: verify/custom/utils/debug.test.cpp
    title: verify/custom/utils/debug.test.cpp
  - icon: ':x:'
    path: verify/custom/utils/encode.test.cpp
    title: verify/custom/utils/encode.test.cpp
  - icon: ':x:'
    path: verify/custom/utils/random_graph.test.cpp
    title: verify/custom/utils/random_graph.test.cpp
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
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n\
    #define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l);\
    \ i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__,\
    \ rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1;\
    \ i >= int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__,\
    \ per3, per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n#define pb push_back\n#define eb emplace_back\n#define f first\n\
    #define s second\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing u64\
    \ = unsigned long long;\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n\
    \    return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const\
    \ T &b) {\n    return b > a ? a = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO()\
    \ {\n        cin.tie(0)->sync_with_stdio(0);\n        cin.exceptions(cin.failbit);\n\
    \        cout << setprecision(10) << fixed;\n    }\n} init_io;\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include\
    \ <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a, b, c, d, ...) d\n\
    \ \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define rep2(i,\
    \ n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n\
    \ \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define\
    \ per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define f first\n#define s second\n\nusing ll = long\
    \ long;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, const T &b) {\n    return b < a ? a = b, 1 : 0;\n\
    }\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n    return b > a ? a\
    \ = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n        cin.tie(0)->sync_with_stdio(0);\n\
    \        cin.exceptions(cin.failbit);\n        cout << setprecision(10) << fixed;\n\
    \    }\n} init_io;"
  dependsOn: []
  isVerificationFile: false
  path: misc/template.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/custom/utils/encode.test.cpp
  - verify/custom/utils/debug.test.cpp
  - verify/custom/utils/random_graph.test.cpp
  - verify/custom/datastructure/fenwick_tree_range_add.test.cpp
  - verify/custom/datastructure/segment_tree_sparse.test.cpp
  - verify/custom/numeric/binary_search_reals.test.cpp
  - verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
  - verify/library_checker/data_structure/static_rmq.test.cpp
  - verify/library_checker/data_structure/associative_array.test.cpp
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - verify/library_checker/data_structure/set_xor_min.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/library_checker/graph/scc.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - verify/library_checker/tree/lca.test.cpp
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - verify/aizu/ntl/power.test.cpp
  - verify/aizu/alds1/priority_queue.test.cpp
  - verify/aizu/alds1/number_of_inversions.test.cpp
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/aizu/dsl/rmq.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
documentation_of: misc/template.h
layout: document
redirect_from:
- /library/misc/template.h
- /library/misc/template.h.html
title: misc/template.h
---
