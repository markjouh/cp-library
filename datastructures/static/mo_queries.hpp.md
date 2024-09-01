---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/static/mo_queries.hpp\"\n\ntemplate <class\
    \ T, int B>\nstruct MoQueries {\n  vector<array<int, 3>> queries;\n  vector<T>\
    \ res;\n\n  MoQueries() {}\n\n  void insert(int l, int r) {\n    queries.push_back({l,\
    \ r, sz(queries)});\n  }\n\n  template<class AddL, class DelL, class AddR, class\
    \ DelR, class Query>\n  void solve(AddL add_l, DelL del_l, AddR add_r, DelR del_r,\
    \ Query query) {\n    sort(all(queries), [](array<int, 3> a, array<int, 3> b)\
    \ {\n      if (a[1] / B != b[1] / B) {\n        return a[1] / B < b[1] / B;\n\
    \      }\n      return a[0] < b[0];\n    });\n    res.resize(sz(queries));\n\n\
    \    int cur_l = 0, cur_r = -1;\n    for (auto [l, r, idx] : queries) {\n    \
    \  while (cur_l > l) {\n        add_l(--cur_l);\n      }\n      while (cur_r <\
    \ r) {\n        add_r(++cur_r);\n      }\n      while (cur_l < l) {\n        del_l(cur_l++);\n\
    \      }\n      while (cur_r > r) {\n        del_r(cur_r--);\n      }\n      res[idx]\
    \ = query();\n    }\n  }\n\n  template<class Add, class Del, class Query>\n  void\
    \ solve(Add add, Del del, Query query) {\n    solve<Add, Del, Add, Del, Query>(add,\
    \ del, add, del, query);\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T, int B>\nstruct MoQueries {\n  vector<array<int,\
    \ 3>> queries;\n  vector<T> res;\n\n  MoQueries() {}\n\n  void insert(int l, int\
    \ r) {\n    queries.push_back({l, r, sz(queries)});\n  }\n\n  template<class AddL,\
    \ class DelL, class AddR, class DelR, class Query>\n  void solve(AddL add_l, DelL\
    \ del_l, AddR add_r, DelR del_r, Query query) {\n    sort(all(queries), [](array<int,\
    \ 3> a, array<int, 3> b) {\n      if (a[1] / B != b[1] / B) {\n        return\
    \ a[1] / B < b[1] / B;\n      }\n      return a[0] < b[0];\n    });\n    res.resize(sz(queries));\n\
    \n    int cur_l = 0, cur_r = -1;\n    for (auto [l, r, idx] : queries) {\n   \
    \   while (cur_l > l) {\n        add_l(--cur_l);\n      }\n      while (cur_r\
    \ < r) {\n        add_r(++cur_r);\n      }\n      while (cur_l < l) {\n      \
    \  del_l(cur_l++);\n      }\n      while (cur_r > r) {\n        del_r(cur_r--);\n\
    \      }\n      res[idx] = query();\n    }\n  }\n\n  template<class Add, class\
    \ Del, class Query>\n  void solve(Add add, Del del, Query query) {\n    solve<Add,\
    \ Del, Add, Del, Query>(add, del, add, del, query);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/mo_queries.hpp
  requiredBy: []
  timestamp: '2024-08-31 22:39:57-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
documentation_of: datastructures/static/mo_queries.hpp
layout: document
redirect_from:
- /library/datastructures/static/mo_queries.hpp
- /library/datastructures/static/mo_queries.hpp.html
title: datastructures/static/mo_queries.hpp
---
