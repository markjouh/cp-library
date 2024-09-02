---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/static/sparse_table.hpp
    title: datastructures/static/sparse_table.hpp
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
    verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <climits>\n#include <cmath>\n\
    #include <cstdint>\n#include <cstring>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\nusing namespace std;\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class\
    \ T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n#else\n  int\
    \ res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n}\n\n\
    template <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1\
    \ : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return b >\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"datastructures/static/sparse_table.hpp\"\n\ntemplate <class\
    \ T, T(*op)(T, T)>\nstruct SparseTable {\n  int n, log;\n  vector<vector<T>> table;\n\
    \n  SparseTable(const vector<T> &a) : n(sz(a)), log(lg(n) + 1) {\n    table.resize(log);\n\
    \    table[0] = a;\n    for (int i = 1; i < log; i++) {\n      table[i].resize(n\
    \ - (1 << i) + 1);\n      for (int j = 0; j < sz(table[i]); j++) {\n        table[i][j]\
    \ = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n      }\n    }\n \
    \ }\n\n  T query(int l, int r) {\n    assert(l <= r);\n    int i = lg(++r - l);\n\
    \    return op(table[i][l], table[i][r - (1 << i)]);\n  }\n};\n#line 5 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n\nint op(int x, int y) {\n  return x < y ? x : y;\n}\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    cin >> a[i];\n  }\n  SparseTable<int, op> rmq(a);\n  while (q--) {\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << rmq.query(l, r - 1) << '\\n';\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../boilerplate.hpp\"\n#include \"../../../datastructures/static/sparse_table.hpp\"\
    \n\nint op(int x, int y) {\n  return x < y ? x : y;\n}\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    cin >> a[i];\n  }\n  SparseTable<int, op> rmq(a);\n  while (q--) {\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << rmq.query(l, r - 1) << '\\n';\n\
    \  }\n}"
  dependsOn:
  - datastructures/static/sparse_table.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2024-09-01 21:11:12-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp.html
title: verify/library_checker/data_structure/static_rmq.test.cpp
---
