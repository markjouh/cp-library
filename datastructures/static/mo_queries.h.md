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
    \ int B>\nstruct MoQueries {\n    vector<array<int, 3>> queries;\n    vector<T>\
    \ res;\n\n    MoQueries() {}\n\n    void insert(int l, int r) {\n        queries.push_back({l,\
    \ r, sz(queries)});\n    }\n\n    template<class AddL, class DelL, class AddR,\
    \ class DelR, class Query>\n    void solve(AddL addL, DelL delL, AddR addR, DelR\
    \ delR, Query query) {\n        sort(all(queries), [](array<int, 3> a, array<int,\
    \ 3> b) {\n            if (a[1] / B != b[1] / B) {\n                return a[1]\
    \ / B < b[1] / B;\n            }\n            return a[0] < b[0];\n        });\n\
    \        res.resize(sz(queries));\n\n        int curL = 0, curR = -1;\n      \
    \  for (auto [l, r, idx] : queries) {\n            while (curL > l) {\n      \
    \          addL(--curL);\n            }\n            while (curR < r) {\n    \
    \            addR(++curR);\n            }\n            while (curL < l) {\n  \
    \              delL(curL++);\n            }\n            while (curR > r) {\n\
    \                delR(curR--);\n            }\n            res[idx] = query();\n\
    \        }\n    }\n\n    template<class Add, class Del, class Query>\n    void\
    \ solve(Add add, Del del, Query query) {\n        solve<Add, Del, Add, Del, Query>(add,\
    \ del, add, del, query);\n    }\n};\n"
  code: "template <class T, int B>\nstruct MoQueries {\n    vector<array<int, 3>>\
    \ queries;\n    vector<T> res;\n\n    MoQueries() {}\n\n    void insert(int l,\
    \ int r) {\n        queries.push_back({l, r, sz(queries)});\n    }\n\n    template<class\
    \ AddL, class DelL, class AddR, class DelR, class Query>\n    void solve(AddL\
    \ addL, DelL delL, AddR addR, DelR delR, Query query) {\n        sort(all(queries),\
    \ [](array<int, 3> a, array<int, 3> b) {\n            if (a[1] / B != b[1] / B)\
    \ {\n                return a[1] / B < b[1] / B;\n            }\n            return\
    \ a[0] < b[0];\n        });\n        res.resize(sz(queries));\n\n        int curL\
    \ = 0, curR = -1;\n        for (auto [l, r, idx] : queries) {\n            while\
    \ (curL > l) {\n                addL(--curL);\n            }\n            while\
    \ (curR < r) {\n                addR(++curR);\n            }\n            while\
    \ (curL < l) {\n                delL(curL++);\n            }\n            while\
    \ (curR > r) {\n                delR(curR--);\n            }\n            res[idx]\
    \ = query();\n        }\n    }\n\n    template<class Add, class Del, class Query>\n\
    \    void solve(Add add, Del del, Query query) {\n        solve<Add, Del, Add,\
    \ Del, Query>(add, del, add, del, query);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/static/mo_queries.h
  requiredBy: []
  timestamp: '2024-10-25 20:41:56-04:00'
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
