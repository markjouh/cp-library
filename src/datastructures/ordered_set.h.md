---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/merge_sort_tree.h
    title: src/datastructures/merge_sort_tree.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/ordered_set.h\"\n#include <ext/pb_ds/assoc_container.hpp>\
    \ \n#include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds; \n\ntemplate\
    \ <class T>\nusing ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ntemplate <class T>\nstruct ordered_multiset {\n  int time = 0;\n  ordered_set<pair<T,\
    \ int>> st;\n\n  void insert(T x) {\n    st.insert({x, time++});\n  }\n  void\
    \ extract(T x) {\n    auto it = st.lower_bound({x, 0});\n    if (it != end(st)\
    \ && it->fi == x) {\n      st.erase(it);\n    }\n  }\n\n  T find_by_order(int\
    \ k) {\n    return (*st.find_by_order(k)).first;\n  }\n  int order_of_key(T x)\
    \ {\n    return st.order_of_key({x, 0});\n  }\n};\n"
  code: "#include <ext/pb_ds/assoc_container.hpp> \n#include <ext/pb_ds/tree_policy.hpp>\n\
    \nusing namespace __gnu_pbds; \n\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\ntemplate\
    \ <class T>\nstruct ordered_multiset {\n  int time = 0;\n  ordered_set<pair<T,\
    \ int>> st;\n\n  void insert(T x) {\n    st.insert({x, time++});\n  }\n  void\
    \ extract(T x) {\n    auto it = st.lower_bound({x, 0});\n    if (it != end(st)\
    \ && it->fi == x) {\n      st.erase(it);\n    }\n  }\n\n  T find_by_order(int\
    \ k) {\n    return (*st.find_by_order(k)).first;\n  }\n  int order_of_key(T x)\
    \ {\n    return st.order_of_key({x, 0});\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/ordered_set.h
  requiredBy:
  - src/datastructures/merge_sort_tree.h
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: src/datastructures/ordered_set.h
layout: document
redirect_from:
- /library/src/datastructures/ordered_set.h
- /library/src/datastructures/ordered_set.h.html
title: src/datastructures/ordered_set.h
---
