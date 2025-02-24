---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/ordered_set.h
    title: datastructures/ordered_set.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/ordered_set.h\"\n#include <ext/pb_ds/assoc_container.hpp>\
    \ \n#include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds; \n\ntemplate\
    \ <class T>\nusing ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ntemplate <class T>\nstruct ordered_multiset {\n  int time = 0;\n  ordered_set<pair<T,\
    \ int>> st;\n \n  void insert(T x) {\n    st.insert({x, time++});\n  }\n \n  void\
    \ extract(T x) {\n    auto it = st.lower_bound({x, 0});\n    if (it != end(st)\
    \ && it->first == x) {\n      st.erase(it);\n    }\n  }\n \n  T find_by_order(int\
    \ k) {\n    return (*st.find_by_order(k)).first;\n  }\n \n  int order_of_key(T\
    \ x) {\n    return st.order_of_key({x, 0});\n  }\n};\n#line 2 \"datastructures/mergesort_tree.h\"\
    \n\ntemplate <class T>\nstruct mergesort_tree {\n    int n;\n    vector<ordered_set<pair<T,\
    \ int>>> st;\n \n    mergesort_tree(const vector<T> &a) : n(sz(a)), st(2 * n)\
    \ {\n        for (int i = 0; i < n; i++) {\n            for (int p = i + n; p\
    \ > 0; p >>= 1) {\n                st[p].insert({a[i], i});\n            }\n \
    \       }\n    }\n \n    int query(int l, int r, T v) {\n        int res = 0;\n\
    \        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l\
    \ & 1) {\n                res += st[l++].order_of_key({v, 0});\n            }\n\
    \            if (r & 1) {\n                res += st[--r].order_of_key({v, 0});\n\
    \            }\n        }\n        return res;\n    }\n \n    void set(int p,\
    \ T v) {\n        const auto old = *begin(st[p + n]);\n        for (p += n; p\
    \ > 0; p >>= 1) {\n            st[p].erase(old);\n            st[p].insert(v);\n\
    \        }\n    }\n};\n"
  code: "#include \"ordered_set.h\"\n\ntemplate <class T>\nstruct mergesort_tree {\n\
    \    int n;\n    vector<ordered_set<pair<T, int>>> st;\n \n    mergesort_tree(const\
    \ vector<T> &a) : n(sz(a)), st(2 * n) {\n        for (int i = 0; i < n; i++) {\n\
    \            for (int p = i + n; p > 0; p >>= 1) {\n                st[p].insert({a[i],\
    \ i});\n            }\n        }\n    }\n \n    int query(int l, int r, T v) {\n\
    \        int res = 0;\n        for (l += n, r += n + 1; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) {\n                res += st[l++].order_of_key({v,\
    \ 0});\n            }\n            if (r & 1) {\n                res += st[--r].order_of_key({v,\
    \ 0});\n            }\n        }\n        return res;\n    }\n \n    void set(int\
    \ p, T v) {\n        const auto old = *begin(st[p + n]);\n        for (p += n;\
    \ p > 0; p >>= 1) {\n            st[p].erase(old);\n            st[p].insert(v);\n\
    \        }\n    }\n};"
  dependsOn:
  - datastructures/ordered_set.h
  isVerificationFile: false
  path: datastructures/mergesort_tree.h
  requiredBy: []
  timestamp: '2025-02-24 12:15:36-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: datastructures/mergesort_tree.h
layout: document
redirect_from:
- /library/datastructures/mergesort_tree.h
- /library/datastructures/mergesort_tree.h.html
title: datastructures/mergesort_tree.h
---
