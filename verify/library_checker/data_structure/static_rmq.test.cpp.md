---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/sparse_table.hpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"\
    verify/boilerplate.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class\
    \ T> bool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate\
    \ <class T> bool ckmax(T &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\
    \nconst int INF = INT_MAX / 2;\nconst ll INFLL = LLONG_MAX / 2;\n\nstruct InitIO\
    \ {\n    InitIO() {\n        cin.tie(0)->sync_with_stdio(0);\n        cin.exceptions(cin.failbit);\n\
    \        cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 2 \"datastructures/sparse_table.hpp\"\
    \n\ntemplate <class T, T(*op)(T, T)>\nstruct SparseTable {\n  int n, lg;\n  vector<vector<T>>\
    \ table;\n\n  SparseTable(const vector<T> &a) : n(sz(a)), lg(__lg(n) + 1) {\n\
    \    table.resize(lg);\n    table[0] = a;\n    for (int i = 1; i < lg; i++) {\n\
    \      table[i].resize(n - (1 << i) + 1);\n      for (int j = 0; j < sz(table[i]);\
    \ j++) {\n        table[i][j] = op(table[i - 1][j], table[i - 1][j + (1 << (i\
    \ - 1))]);\n      }\n    }\n  }\n\n  T query(int l, int r) {\n    assert(l <=\
    \ r);\n    int i = __lg(++r - l);\n    return op(table[i][l], table[i][r - (1\
    \ << i)]);\n  }\n};\n#line 5 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n\nint op(int x, int y) {\n  return x < y ? x : y;\n}\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    cin >> a[i];\n  }\n  SparseTable<int, op> rmq(a);\n  while (q--) {\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << rmq.query(l, r - 1) << '\\n';\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../boilerplate.hpp\"\n#include \"../../../datastructures/sparse_table.hpp\"\
    \n\nint op(int x, int y) {\n  return x < y ? x : y;\n}\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    cin >> a[i];\n  }\n  SparseTable<int, op> rmq(a);\n  while (q--) {\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << rmq.query(l, r - 1) << '\\n';\n\
    \  }\n}"
  dependsOn:
  - datastructures/sparse_table.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 12:05:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp.html
title: verify/library_checker/data_structure/static_rmq.test.cpp
---
