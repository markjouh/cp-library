---
data:
  _extendedDependsOn: []
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
    path: verify/custom/datastructure/bit_2d.test.cpp
    title: verify/custom/datastructure/bit_2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/datastructure/bit_range_add.test.cpp
    title: verify/custom/datastructure/bit_range_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/datastructure/segment_tree_sparse.test.cpp
    title: verify/custom/datastructure/segment_tree_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/datastructure/segtree_set.test.cpp
    title: verify/custom/datastructure/segtree_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/custom/graphs/topsort.test.cpp
    title: verify/custom/graphs/topsort.test.cpp
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
  bundledCode: "#line 2 \"utils/encode.h\"\n\nconstexpr uint64_t pow94[10] = {1, 94,\
    \ 8836, 830584, 78074896, 7339040224, 689869781056, 64847759419264, 6095689385410816,\
    \ 572994802228616704};\n\n// Turn array into a base-94 encoded string\ntemplate\
    \ <class T, int W>\nstring encode(T x) {\n    if constexpr (is_integral_v<T>)\
    \ {\n        string res(W, 0);\n        for (int i = 0; i < W; i++) {\n      \
    \      res[i] = char(33 + x % 94);\n            x /= 94;\n        }\n        return\
    \ res;\n    } else {\n        string res;\n        for (auto &y : x) {\n     \
    \       res += encode<typename T::value_type, W>(y);\n        }\n        return\
    \ res;\n    }\n}\n\ntemplate <class T, int W>\nT decode(string s) {\n    if constexpr\
    \ (is_integral_v<T>) {\n        T res = 0;\n        for (int i = 0; i < W; i++)\
    \ {\n            res += pow94[i] * uint64_t(s[i] - 33);\n        }\n        return\
    \ res;\n    } else {\n        constexpr int segs = tuple_size_v<T>;\n        const\
    \ int len = ssize(s) / segs;\n        T res;\n        for (int i = 0; i < segs;\
    \ i++) {\n            res[i] = decode<typename T::value_type, W>(s.substr(len\
    \ * i, len));\n        }\n        return res;\n    }\n}\n\n// Generate code to\
    \ copy paste into frontend\n#define make_encoded(type, x, w) cout << \"const \"\
    \ << type << ' ' << #x << \" = decode<\" << type << \", \" << w << \">(R\\\"zzzzz(\"\
    \ << encode<decltype(x), w>(x) << \")zzzzz\\\")\" << endl\n"
  code: "#pragma once\n\nconstexpr uint64_t pow94[10] = {1, 94, 8836, 830584, 78074896,\
    \ 7339040224, 689869781056, 64847759419264, 6095689385410816, 572994802228616704};\n\
    \n// Turn array into a base-94 encoded string\ntemplate <class T, int W>\nstring\
    \ encode(T x) {\n    if constexpr (is_integral_v<T>) {\n        string res(W,\
    \ 0);\n        for (int i = 0; i < W; i++) {\n            res[i] = char(33 + x\
    \ % 94);\n            x /= 94;\n        }\n        return res;\n    } else {\n\
    \        string res;\n        for (auto &y : x) {\n            res += encode<typename\
    \ T::value_type, W>(y);\n        }\n        return res;\n    }\n}\n\ntemplate\
    \ <class T, int W>\nT decode(string s) {\n    if constexpr (is_integral_v<T>)\
    \ {\n        T res = 0;\n        for (int i = 0; i < W; i++) {\n            res\
    \ += pow94[i] * uint64_t(s[i] - 33);\n        }\n        return res;\n    } else\
    \ {\n        constexpr int segs = tuple_size_v<T>;\n        const int len = ssize(s)\
    \ / segs;\n        T res;\n        for (int i = 0; i < segs; i++) {\n        \
    \    res[i] = decode<typename T::value_type, W>(s.substr(len * i, len));\n   \
    \     }\n        return res;\n    }\n}\n\n// Generate code to copy paste into\
    \ frontend\n#define make_encoded(type, x, w) cout << \"const \" << type << ' '\
    \ << #x << \" = decode<\" << type << \", \" << w << \">(R\\\"zzzzz(\" << encode<decltype(x),\
    \ w>(x) << \")zzzzz\\\")\" << endl"
  dependsOn: []
  isVerificationFile: false
  path: utils/encode.h
  requiredBy:
  - misc/template.h
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/custom/utils/encode.test.cpp
  - verify/custom/utils/debug.test.cpp
  - verify/custom/utils/timer.test.cpp
  - verify/custom/utils/random_graph.test.cpp
  - verify/custom/graphs/topsort.test.cpp
  - verify/custom/datastructure/bit_2d.test.cpp
  - verify/custom/datastructure/segtree_set.test.cpp
  - verify/custom/datastructure/segment_tree_sparse.test.cpp
  - verify/custom/datastructure/bit_range_add.test.cpp
  - verify/custom/numeric/binary_search_reals.test.cpp
  - verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
  - verify/library_checker/data_structure/static_rmq.test.cpp
  - verify/library_checker/data_structure/associative_array.test.cpp
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - verify/library_checker/data_structure/set_xor_min.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/string/suffix_array.test.cpp
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
documentation_of: utils/encode.h
layout: document
redirect_from:
- /library/utils/encode.h
- /library/utils/encode.h.html
title: utils/encode.h
---
