---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/static/mo_queries.h\"\ntemplate <class T,\
    \ int K>\nstruct mo_queries {\n    vector<array<int, 3>> queries;\n    vector<T>\
    \ res;\n\n    mo_queries() {}\n\n    void insert(int l, int r) {\n        queries.push_back({l,\
    \ r, sz(queries)});\n    }\n\n    template <class F1, class F2, class F3, class\
    \ F4, class F5>\n    void solve(F1 add_l, F2 del_l, F3 add_r, F4 del_r, F5 query)\
    \ {\n        sort(all(queries), [](array<int, 3> a, array<int, 3> b) {\n     \
    \       if (a[1] / K != b[1] / K) {\n                return a[1] / K < b[1] /\
    \ K;\n            }\n            return a[0] < b[0];\n        });\n        res.resize(sz(queries));\n\
    \n        int cur_l = 0, cur_r = -1;\n        for (auto [l, r, idx] : queries)\
    \ {\n            while (cur_l > l) {\n                add_l(--cur_l);\n      \
    \      }\n            while (cur_r < r) {\n                add_r(++cur_r);\n \
    \           }\n            while (cur_l < l) {\n                del_l(cur_l++);\n\
    \            }\n            while (cur_r > r) {\n                del_r(cur_r--);\n\
    \            }\n            res[idx] = query();\n        }\n    }\n\n    template\
    \ <class F1, class F2, class F3>\n    void solve(F1 add, F2 del, F3 query) {\n\
    \        solve<F1, F2, F1, F2, F3>(add, del, add, del, query);\n    }\n};\n"
  code: "template <class T, int K>\nstruct mo_queries {\n    vector<array<int, 3>>\
    \ queries;\n    vector<T> res;\n\n    mo_queries() {}\n\n    void insert(int l,\
    \ int r) {\n        queries.push_back({l, r, sz(queries)});\n    }\n\n    template\
    \ <class F1, class F2, class F3, class F4, class F5>\n    void solve(F1 add_l,\
    \ F2 del_l, F3 add_r, F4 del_r, F5 query) {\n        sort(all(queries), [](array<int,\
    \ 3> a, array<int, 3> b) {\n            if (a[1] / K != b[1] / K) {\n        \
    \        return a[1] / K < b[1] / K;\n            }\n            return a[0] <\
    \ b[0];\n        });\n        res.resize(sz(queries));\n\n        int cur_l =\
    \ 0, cur_r = -1;\n        for (auto [l, r, idx] : queries) {\n            while\
    \ (cur_l > l) {\n                add_l(--cur_l);\n            }\n            while\
    \ (cur_r < r) {\n                add_r(++cur_r);\n            }\n            while\
    \ (cur_l < l) {\n                del_l(cur_l++);\n            }\n            while\
    \ (cur_r > r) {\n                del_r(cur_r--);\n            }\n            res[idx]\
    \ = query();\n        }\n    }\n\n    template <class F1, class F2, class F3>\n\
    \    void solve(F1 add, F2 del, F3 query) {\n        solve<F1, F2, F1, F2, F3>(add,\
    \ del, add, del, query);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/mo_queries.h
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
documentation_of: datastructures/static/mo_queries.h
layout: document
redirect_from:
- /library/datastructures/static/mo_queries.h
- /library/datastructures/static/mo_queries.h.html
title: datastructures/static/mo_queries.h
---
