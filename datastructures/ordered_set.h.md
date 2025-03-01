---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: datastructures/mergesort_tree.h
    title: datastructures/mergesort_tree.h
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/ordered_set.h\"\n#include <ext/pb_ds/assoc_container.hpp>\
    \ \n#include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds; \n\ntemplate\
    \ <class T>\nusing ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ntemplate <class T>\nstruct ordered_multiset {\n    int time = 0;\n    ordered_set<pair<T,\
    \ int>> st;\n\n    void insert(T x) {\n        st.insert({x, time++});\n    }\n\
    \    void extract(T x) {\n        auto it = st.lower_bound({x, 0});\n        if\
    \ (it != end(st) && it->fi == x) {\n            st.erase(it);\n        }\n   \
    \ }\n\n    T find_by_order(int k) {\n        return (*st.find_by_order(k)).first;\n\
    \    }\n    int order_of_key(T x) {\n        return st.order_of_key({x, 0});\n\
    \    }\n};\n"
  code: "#include <ext/pb_ds/assoc_container.hpp> \n#include <ext/pb_ds/tree_policy.hpp>\n\
    \nusing namespace __gnu_pbds; \n\ntemplate <class T>\nusing ordered_set = tree<T,\
    \ null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\ntemplate\
    \ <class T>\nstruct ordered_multiset {\n    int time = 0;\n    ordered_set<pair<T,\
    \ int>> st;\n\n    void insert(T x) {\n        st.insert({x, time++});\n    }\n\
    \    void extract(T x) {\n        auto it = st.lower_bound({x, 0});\n        if\
    \ (it != end(st) && it->fi == x) {\n            st.erase(it);\n        }\n   \
    \ }\n\n    T find_by_order(int k) {\n        return (*st.find_by_order(k)).first;\n\
    \    }\n    int order_of_key(T x) {\n        return st.order_of_key({x, 0});\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/ordered_set.h
  requiredBy:
  - datastructures/mergesort_tree.h
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/aizu/alds1/number_of_inversions.test.cpp
documentation_of: datastructures/ordered_set.h
layout: document
redirect_from:
- /library/datastructures/ordered_set.h
- /library/datastructures/ordered_set.h.html
title: datastructures/ordered_set.h
---
