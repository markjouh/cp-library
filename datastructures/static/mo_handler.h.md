---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/static/mo_handler.h\"\ntemplate <int K>\n\
    struct MoHandler {\n  vector<array<int, 3>> queries;\n \n  MoHandler() {}\n \n\
    \  void add(int l, int r) {\n    queries.push_back({l, r, int(queries.size())});\n\
    \  }\n \n  template <class F1, class F2, class F3, class F4, class F5>\n  void\
    \ run(F1 add_l, F2 del_l, F3 add_r, F4 del_r, F5 answer) {\n    sort(queries.begin(),\
    \ queries.end(), [](array<int, 3> a, array<int, 3> b) {\n      if (a[1] / K !=\
    \ b[1] / K) {\n        return a[1] / K < b[1] / K;\n      }\n      return a[0]\
    \ < b[0];\n    });\n \n    int cur_l = 0, cur_r = -1;\n    for (auto [l, r, idx]\
    \ : queries) {\n      while (cur_l > l) {\n        add_l(--cur_l);\n      }\n\
    \      while (cur_r < r) {\n        add_r(++cur_r);\n      }\n      while (cur_l\
    \ < l) {\n        del_l(cur_l++);\n      }\n      while (cur_r > r) {\n      \
    \  del_r(cur_r--);\n      }\n      answer(idx);\n    }\n  }\n \n  template <class\
    \ F1, class F2, class F3>\n  void run(F1 add, F2 del, F3 answer) {\n    run<F1,\
    \ F2, F1, F2, F3>(add, del, add, del, answer);\n  }\n};\n"
  code: "template <int K>\nstruct MoHandler {\n  vector<array<int, 3>> queries;\n\
    \ \n  MoHandler() {}\n \n  void add(int l, int r) {\n    queries.push_back({l,\
    \ r, int(queries.size())});\n  }\n \n  template <class F1, class F2, class F3,\
    \ class F4, class F5>\n  void run(F1 add_l, F2 del_l, F3 add_r, F4 del_r, F5 answer)\
    \ {\n    sort(queries.begin(), queries.end(), [](array<int, 3> a, array<int, 3>\
    \ b) {\n      if (a[1] / K != b[1] / K) {\n        return a[1] / K < b[1] / K;\n\
    \      }\n      return a[0] < b[0];\n    });\n \n    int cur_l = 0, cur_r = -1;\n\
    \    for (auto [l, r, idx] : queries) {\n      while (cur_l > l) {\n        add_l(--cur_l);\n\
    \      }\n      while (cur_r < r) {\n        add_r(++cur_r);\n      }\n      while\
    \ (cur_l < l) {\n        del_l(cur_l++);\n      }\n      while (cur_r > r) {\n\
    \        del_r(cur_r--);\n      }\n      answer(idx);\n    }\n  }\n \n  template\
    \ <class F1, class F2, class F3>\n  void run(F1 add, F2 del, F3 answer) {\n  \
    \  run<F1, F2, F1, F2, F3>(add, del, add, del, answer);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/mo_handler.h
  requiredBy: []
  timestamp: '2025-03-16 14:57:47-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
documentation_of: datastructures/static/mo_handler.h
layout: document
redirect_from:
- /library/datastructures/static/mo_handler.h
- /library/datastructures/static/mo_handler.h.html
title: datastructures/static/mo_handler.h
---
