---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/fenwick_tree/fentree.h
    title: src/datastructures/fenwick_tree/fentree.h
  - icon: ':heavy_check_mark:'
    path: src/template/template.h
    title: src/template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #line 1 \"src/template/template.h\"\n/**\n *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"src/datastructures/fenwick_tree/fentree.h\"\ntemplate <class\
    \ T>\nstruct Fentree {\n  int n;\n  vector<T> ft;\n\n  Fentree(int n_) : n(n_),\
    \ ft(n + 1) {}\n\n  Fentree(const vector<T> &a) : n(sz(a)), ft(n + 1) {\n    for\
    \ (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n      if (i + (i & -i)\
    \ <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n  }\n\n  void add(int\
    \ p, T v) {\n    for (p++; p <= n; p += p & -p) {\n      ft[p] += v;\n    }\n\
    \  }\n\n  T sum(int r) {\n    T res = 0;\n    for (r++; r > 0; r -= r & -r) {\n\
    \      res += ft[r];\n    }\n    return res;\n  }\n\n  T sum(int l, int r) {\n\
    \    return sum(r) - sum(l - 1);\n  }\n};\n#line 5 \"src/verify/library_checker/data_structure/point_add_range_sum.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int64_t> a(n);\n  for\
    \ (int i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  Fentree<int64_t> ft(a);\n\
    \  while (q--) {\n    bool t;\n    int x, y;\n    cin >> t >> x >> y;\n    if\
    \ (t) {\n      cout << ft.sum(x, y - 1) << '\\n';\n    } else {\n      ft.add(x,\
    \ y);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../../template/template.h\"\n#include \"../../../datastructures/fenwick_tree/fentree.h\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int64_t> a(n);\n  for\
    \ (int i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  Fentree<int64_t> ft(a);\n\
    \  while (q--) {\n    bool t;\n    int x, y;\n    cin >> t >> x >> y;\n    if\
    \ (t) {\n      cout << ft.sum(x, y - 1) << '\\n';\n    } else {\n      ft.add(x,\
    \ y);\n    }\n  }\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/fenwick_tree/fentree.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 13:11:03-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
- /verify/src/verify/library_checker/data_structure/point_add_range_sum.test.cpp.html
title: src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
---
