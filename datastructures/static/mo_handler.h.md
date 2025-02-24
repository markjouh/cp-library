---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/static/mo_handler.h\"\n// Abstracts away\
    \ the ordering and boundary movement logic for Mo's algorithm.\n// For answering\
    \ arbitrary range queries on a static 1D array.\n\ntemplate <class T, int K>\n\
    struct MoHandler {\n  vector<array<int, 3>> queries;\n\n  MoHandler() {}\n\n \
    \ void insert(int l, int r) {\n    queries.push_back({l, r, int(queries.size())});\n\
    \  }\n\n  template <class F1, class F2, class F3, class F4, class F5>\n  void\
    \ run(F1 add_l, F2 del_l, F3 add_r, F4 del_r, F5 answer) {\n    sort(queries.begin(),\
    \ queries.end(), [](array<int, 3> a, array<int, 3> b) {\n      if (a[1] / K !=\
    \ b[1] / K) {\n        return a[1] / K < b[1] / K;\n      }\n      return a[0]\
    \ < b[0];\n    });\n\n    int cur_l = 0, cur_r = -1;\n    for (auto [l, r, idx]\
    \ : queries) {\n      while (cur_l > l) {\n        add_l(--cur_l);\n      }\n\
    \      while (cur_r < r) {\n        add_r(++cur_r);\n      }\n      while (cur_l\
    \ < l) {\n        del_l(cur_l++);\n      }\n      while (cur_r > r) {\n      \
    \  del_r(cur_r--);\n      }\n      answer(idx);\n    }\n  }\n\n  template <class\
    \ F1, class F2, class F3>\n  void run(F1 add, F2 del, F3 answer) {\n    run<F1,\
    \ F2, F1, F2, F3>(add, del, add, del, answer);\n  }\n};\n"
  code: "// Abstracts away the ordering and boundary movement logic for Mo's algorithm.\n\
    // For answering arbitrary range queries on a static 1D array.\n\ntemplate <class\
    \ T, int K>\nstruct MoHandler {\n  vector<array<int, 3>> queries;\n\n  MoHandler()\
    \ {}\n\n  void insert(int l, int r) {\n    queries.push_back({l, r, int(queries.size())});\n\
    \  }\n\n  template <class F1, class F2, class F3, class F4, class F5>\n  void\
    \ run(F1 add_l, F2 del_l, F3 add_r, F4 del_r, F5 answer) {\n    sort(queries.begin(),\
    \ queries.end(), [](array<int, 3> a, array<int, 3> b) {\n      if (a[1] / K !=\
    \ b[1] / K) {\n        return a[1] / K < b[1] / K;\n      }\n      return a[0]\
    \ < b[0];\n    });\n\n    int cur_l = 0, cur_r = -1;\n    for (auto [l, r, idx]\
    \ : queries) {\n      while (cur_l > l) {\n        add_l(--cur_l);\n      }\n\
    \      while (cur_r < r) {\n        add_r(++cur_r);\n      }\n      while (cur_l\
    \ < l) {\n        del_l(cur_l++);\n      }\n      while (cur_r > r) {\n      \
    \  del_r(cur_r--);\n      }\n      answer(idx);\n    }\n  }\n\n  template <class\
    \ F1, class F2, class F3>\n  void run(F1 add, F2 del, F3 answer) {\n    run<F1,\
    \ F2, F1, F2, F3>(add, del, add, del, answer);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/mo_handler.h
  requiredBy: []
  timestamp: '2025-02-24 14:31:59-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/static/mo_handler.h
layout: document
redirect_from:
- /library/datastructures/static/mo_handler.h
- /library/datastructures/static/mo_handler.h.html
title: datastructures/static/mo_handler.h
---
