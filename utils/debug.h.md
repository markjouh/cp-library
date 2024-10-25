---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  - icon: ':x:'
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
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/debug.h\"\n\nnamespace debug_internal {\n\nusing namespace\
    \ std;\n\ntemplate <typename T>\nconcept is_core = requires(T x) {\n    cerr <<\
    \ x;\n};\n\ntemplate <typename T>\nconcept is_pair = requires(T x) {\n    x.first;\n\
    \    x.second;\n};\n\ntemplate <typename T>\nconcept is_iterable = ranges::range<T>;\n\
    \ntemplate <typename T>\nvoid print(T x) {\n    if constexpr (is_core<T>) {\n\
    \        cerr << x;\n    } else if constexpr (is_pair<T>) {\n        cerr << '(';\n\
    \        print(x.first);\n        cerr << \", \";\n        print(x.second);\n\
    \        cerr << ')';\n    } else if constexpr (is_iterable<T>) {\n        cerr\
    \ << '[';\n        bool flag = false;\n        for (auto y : x) {\n          \
    \  if (flag) {\n                cerr << \", \";\n            }\n            print(y);\n\
    \            flag = true;\n        }\n        cerr << ']';\n    } else {\n   \
    \     cerr << \"Unknown type\";\n    }\n}\n\ntemplate <typename T>\nvoid debug(string\
    \ s, T x) {\n    cerr << \"\\033[1;35m\" << s << \"\\033[0;0m = \";\n    print(x);\n\
    \    cerr << endl;\n}\n\ntemplate <typename T, typename... Args>\nvoid debug(string\
    \ s, T x, Args... args) {\n    int idx = 0, layer = 0;\n    while (idx < ssize(s)\
    \ && (s[idx] != ',' || layer != 0)) {\n        layer += s[idx] == '(' || s[idx]\
    \ == '{';\n        layer -= s[idx] == ')' || s[idx] == '}';\n        idx++;\n\
    \    }\n    cerr << \"\\033[1;35m\" << s.substr(0, idx) << \"\\033[0;0m = \";\n\
    \    print(x);\n    cerr << \"\\033[1;32m | \\033[0;0m\";\n    debug(s.substr(s.find_first_not_of('\
    \ ', idx + 1)), args...);\n}\n}\n\n#define dbg(...) debug_internal::debug(#__VA_ARGS__,\
    \ __VA_ARGS__)\n"
  code: "#pragma once\n\nnamespace debug_internal {\n\nusing namespace std;\n\ntemplate\
    \ <typename T>\nconcept is_core = requires(T x) {\n    cerr << x;\n};\n\ntemplate\
    \ <typename T>\nconcept is_pair = requires(T x) {\n    x.first;\n    x.second;\n\
    };\n\ntemplate <typename T>\nconcept is_iterable = ranges::range<T>;\n\ntemplate\
    \ <typename T>\nvoid print(T x) {\n    if constexpr (is_core<T>) {\n        cerr\
    \ << x;\n    } else if constexpr (is_pair<T>) {\n        cerr << '(';\n      \
    \  print(x.first);\n        cerr << \", \";\n        print(x.second);\n      \
    \  cerr << ')';\n    } else if constexpr (is_iterable<T>) {\n        cerr << '[';\n\
    \        bool flag = false;\n        for (auto y : x) {\n            if (flag)\
    \ {\n                cerr << \", \";\n            }\n            print(y);\n \
    \           flag = true;\n        }\n        cerr << ']';\n    } else {\n    \
    \    cerr << \"Unknown type\";\n    }\n}\n\ntemplate <typename T>\nvoid debug(string\
    \ s, T x) {\n    cerr << \"\\033[1;35m\" << s << \"\\033[0;0m = \";\n    print(x);\n\
    \    cerr << endl;\n}\n\ntemplate <typename T, typename... Args>\nvoid debug(string\
    \ s, T x, Args... args) {\n    int idx = 0, layer = 0;\n    while (idx < ssize(s)\
    \ && (s[idx] != ',' || layer != 0)) {\n        layer += s[idx] == '(' || s[idx]\
    \ == '{';\n        layer -= s[idx] == ')' || s[idx] == '}';\n        idx++;\n\
    \    }\n    cerr << \"\\033[1;35m\" << s.substr(0, idx) << \"\\033[0;0m = \";\n\
    \    print(x);\n    cerr << \"\\033[1;32m | \\033[0;0m\";\n    debug(s.substr(s.find_first_not_of('\
    \ ', idx + 1)), args...);\n}\n}\n\n#define dbg(...) debug_internal::debug(#__VA_ARGS__,\
    \ __VA_ARGS__)\n"
  dependsOn: []
  isVerificationFile: false
  path: utils/debug.h
  requiredBy:
  - misc/template.h
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_SOME_WA
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
documentation_of: utils/debug.h
layout: document
redirect_from:
- /library/utils/debug.h
- /library/utils/debug.h.html
title: utils/debug.h
---
