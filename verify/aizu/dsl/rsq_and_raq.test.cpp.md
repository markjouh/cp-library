---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fentree/fenwick_tree.hpp
    title: datastructures/fentree/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: datastructures/fentree/fenwick_tree_range_add_range_sum.hpp
    title: datastructures/fentree/fenwick_tree_range_add_range_sum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"verify/aizu/dsl/rsq_and_raq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\n\n#line\
    \ 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n#include\
    \ <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing namespace\
    \ std;\n\n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i\
    \ = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...)\
    \ arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int\
    \ i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define\
    \ per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n#define eb emplace_back\n\
    #define fi first\n#define se second\n\ntemplate <class T>\nusing vec = vector<T>;\n\
    \nusing ll = long long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n\
    #else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n\
    }\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a =\
    \ b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return\
    \ b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf\
    \ = numeric_limits<T>::max() / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"datastructures/fentree/fenwick_tree_range_add_range_sum.hpp\"\
    \n\n#line 2 \"datastructures/fentree/fenwick_tree.hpp\"\n\ntemplate <class T>\n\
    struct FenwickTree {\n  int n;\n  vector<T> ft;\n\n  FenwickTree(int n_) : n(n_),\
    \ ft(n + 1) {}\n\n  FenwickTree(const vector<T> &a) : n(sz(a)), ft(n + 1) {\n\
    \    for (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n      if (i + (i\
    \ & -i) <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n  }\n\n \
    \ void add(int p, T v) {\n    for (p++; p <= n; p += p & -p) {\n      ft[p] +=\
    \ v;\n    }\n  }\n\n  T sum(int r) {\n    T res = 0;\n    for (r++; r > 0; r -=\
    \ r & -r) {\n      res += ft[r];\n    }\n    return res;\n  }\n\n  T sum(int l,\
    \ int r) {\n    return sum(r) - sum(l - 1);\n  }\n};\n#line 4 \"datastructures/fentree/fenwick_tree_range_add_range_sum.hpp\"\
    \n\ntemplate <class T>\nstruct RangeAddRangeSumFT {\n  int n;\n  FenwickTree<T>\
    \ in_pref, os_pref;\n\n  RangeAddRangeSumFT(int n_) : n(n_), in_pref(n), os_pref(n)\
    \ {}\n\n  T sum(int r) {\n    return in_pref.sum(r - 1) + os_pref.sum(n - r -\
    \ 1) * (r + 1);\n  }\n\n  T sum(int l, int r) {\n    return sum(r) - (l > 0 ?\
    \ sum(l - 1) : 0);\n  }\n\n  void add(int r, T v) {\n    in_pref.add(r, v * (r\
    \ + 1));\n    os_pref.add(n - r - 1, v);\n  }\n\n  void add(int l, int r, T v)\
    \ {\n    add(r, v);\n    if (l > 0) {\n      add(l - 1, T(0) - T(v));\n    }\n\
    \  }\n};\n#line 5 \"verify/aizu/dsl/rsq_and_raq.test.cpp\"\n\nint main() {\n \
    \ int n, q;\n  cin >> n >> q;\n  RangeAddRangeSumFT<ll> ft(n);\n  while (q--)\
    \ {\n    bool t;\n    int l, r;\n    cin >> t >> l >> r;\n    l--; r--;\n    if\
    \ (t) {\n      cout << ft.sum(l, r) << '\\n';\n    } else {\n      int x;\n  \
    \    cin >> x;\n      ft.add(l, r, x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/fentree/fenwick_tree_range_add_range_sum.hpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  RangeAddRangeSumFT<ll> ft(n);\n\
    \  while (q--) {\n    bool t;\n    int l, r;\n    cin >> t >> l >> r;\n    l--;\
    \ r--;\n    if (t) {\n      cout << ft.sum(l, r) << '\\n';\n    } else {\n   \
    \   int x;\n      cin >> x;\n      ft.add(l, r, x);\n    }\n  }\n}"
  dependsOn:
  - datastructures/fentree/fenwick_tree_range_add_range_sum.hpp
  - datastructures/fentree/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/aizu/dsl/rsq_and_raq.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 15:13:46-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/dsl/rsq_and_raq.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/dsl/rsq_and_raq.test.cpp
- /verify/verify/aizu/dsl/rsq_and_raq.test.cpp.html
title: verify/aizu/dsl/rsq_and_raq.test.cpp
---
