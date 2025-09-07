---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/static/mo_handler.h\"\ntemplate <int\
    \ K>\nstruct MoHandler {\n  vector<array<int, 3>> queries;\n \n  MoHandler() {}\n\
    \ \n  void add(int l, int r) {\n    queries.push_back({l, r, int(queries.size())});\n\
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
  path: src/datastructures/static/mo_handler.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
documentation_of: src/datastructures/static/mo_handler.h
layout: document
title: Mo's Algorithm Handler
---

Mo's algorithm for offline range queries with efficient query reordering.

## Operations

- `MoHandler(n)`: Initialize for array of size `n`
- `add_query(l, r)`: Add range query `[l, r]`
- `process(add_fn, remove_fn, answer_fn)`: Process all queries with given functions

## Complexity

- Time: $O((n + q) \sqrt{n})$ where $q$ is number of queries
- Space: $O(q)$

## Usage

```cpp
MoHandler mo(n);
for (auto [l, r] : queries) {
  mo.add_query(l, r);
}

vector<int> answers(queries.size());
mo.process(
  [&](int pos) { /* add element at pos */ },
  [&](int pos) { /* remove element at pos */ },
  [&](int query_id) { answers[query_id] = current_answer; }
);
```

## Notes

Reorders queries to minimize pointer movements. Requires add/remove operations to be efficient and reversible.

**Block Size Optimization**: Uses block size of $\sqrt{n}$ for optimal $O((n + q)\sqrt{n})$ complexity. For arrays with $n > 10^5$, consider tuning block size to $\sqrt{n} \times c$ where $c \approx 1.5$ for better cache performance, though this changes the theoretical complexity slightly.