---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructures/fentree/fenwick_tree.hpp
    title: datastructures/fentree/fenwick_tree.hpp
  - icon: ':x:'
    path: datastructures/fentree/fenwick_tree_2d.hpp
    title: datastructures/fentree/fenwick_tree_2d.hpp
  - icon: ':question:'
    path: misc/compress.hpp
    title: misc/compress.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
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
    } init_io;\n#line 2 \"misc/compress.hpp\"\n\ntemplate <class T>\nstruct Compress\
    \ {\n  vector<T> vals;\n\n  Compress() {}\n\n  Compress(const vector<T> &a) :\
    \ vals(a) {\n    init();\n  }\n\n  void init() {\n    sort(all(vals));\n    vals.resize(unique(all(vals))\
    \ - begin(vals));\n  }\n\n  void insert(T x) {\n    vals.push_back(x);\n  }\n\n\
    \  int get(T x) {\n    return lower_bound(all(vals), x) - begin(vals);\n  }\n\n\
    \  friend size_t size(const Compress &x) {\n    return size(x.vals);\n  }\n\n\
    \  T operator[](int p) {\n    return vals[p];\n  }\n};\n#line 2 \"datastructures/fentree/fenwick_tree_2d.hpp\"\
    \n\n#line 2 \"datastructures/fentree/fenwick_tree.hpp\"\n\ntemplate <class T>\n\
    struct FenwickTree {\n  int n;\n  vector<T> ft;\n\n  FenwickTree(int n_) : n(n_),\
    \ ft(n + 1) {}\n\n  FenwickTree(const vector<T> &a) : n(sz(a)), ft(n + 1) {\n\
    \    for (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n      if (i + (i\
    \ & -i) <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n  }\n\n \
    \ void add(int p, T v) {\n    for (p++; p <= n; p += p & -p) {\n      ft[p] +=\
    \ v;\n    }\n  }\n\n  T sum(int r) {\n    T res = 0;\n    for (r++; r > 0; r -=\
    \ r & -r) {\n      res += ft[r];\n    }\n    return res;\n  }\n\n  T sum(int l,\
    \ int r) {\n    return sum(r) - sum(l - 1);\n  }\n};\n#line 4 \"datastructures/fentree/fenwick_tree_2d.hpp\"\
    \n\ntemplate <class T>\nstruct FenwickTree2d {\n  int n;\n  vector<FenwickTree<T>>\
    \ ft;\n\n  FenwickTree2d(int n_, int m) : n(n_), ft(n + 1, FenwickTree<T>(m))\
    \ {}\n\n  void add(int r, int c, T v) {\n    for (r++; r <= n; r += r & -r) {\n\
    \      ft[r].add(c, v);\n    }\n  }\n\n  T sum(int r, int c) {\n    if (r < 0\
    \ || c < 0) {\n      return 0;\n    }\n    T res = 0;\n    for (r++; r > 0; r\
    \ -= r & -r) {\n      res += ft[r].sum(c);\n    }\n    return res;\n  }\n\n  T\
    \ sum(int r1, int c1, int r2, int c2) {\n    return sum(r2, c2) - sum(r2, c1 -\
    \ 1) - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1);\n  }\n};\n#line 6 \"verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vec<array<int, 3>> pts(n);\n\
    \  Compress<int> rows, cols;\n  for (auto &[r, c, w] : pts) {\n    cin >> r >>\
    \ c >> w;\n    rows.insert(r);\n    cols.insert(c);\n  }\n  vec<array<int, 5>>\
    \ qry(q);\n  for (auto &[t, l, d, r, u] : qry) {\n    cin >> t >> l >> d >> r;\n\
    \    rows.insert(l);\n    cols.insert(d);\n    if (t) {\n      cin >> u;\n   \
    \   r--, u--;\n      rows.insert(r);\n      cols.insert(u);\n    }\n  }\n\n  rows.init();\n\
    \  cols.init();\n  FenwickTree2d<ll> ft(sz(rows), sz(cols));\n  for (auto [r,\
    \ c, w] : pts) {\n    r = rows.get(r), c = cols.get(c);\n    ft.add(r, c, w);\n\
    \  }\n  for (auto [t, l, d, r, u] : qry) {\n    l = rows.get(l), d = cols.get(d);\n\
    \    if (t) {\n      r = rows.get(r), u = cols.get(u);\n      cout << ft.sum(l,\
    \ d, r, u) << '\\n';\n    } else {\n      ft.add(l, d, r);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../boilerplate.hpp\"\n#include \"../../../misc/compress.hpp\"\n\
    #include \"../../../datastructures/fentree/fenwick_tree_2d.hpp\"\n\nint main()\
    \ {\n  int n, q;\n  cin >> n >> q;\n  vec<array<int, 3>> pts(n);\n  Compress<int>\
    \ rows, cols;\n  for (auto &[r, c, w] : pts) {\n    cin >> r >> c >> w;\n    rows.insert(r);\n\
    \    cols.insert(c);\n  }\n  vec<array<int, 5>> qry(q);\n  for (auto &[t, l, d,\
    \ r, u] : qry) {\n    cin >> t >> l >> d >> r;\n    rows.insert(l);\n    cols.insert(d);\n\
    \    if (t) {\n      cin >> u;\n      r--, u--;\n      rows.insert(r);\n     \
    \ cols.insert(u);\n    }\n  }\n\n  rows.init();\n  cols.init();\n  FenwickTree2d<ll>\
    \ ft(sz(rows), sz(cols));\n  for (auto [r, c, w] : pts) {\n    r = rows.get(r),\
    \ c = cols.get(c);\n    ft.add(r, c, w);\n  }\n  for (auto [t, l, d, r, u] : qry)\
    \ {\n    l = rows.get(l), d = cols.get(d);\n    if (t) {\n      r = rows.get(r),\
    \ u = cols.get(u);\n      cout << ft.sum(l, d, r, u) << '\\n';\n    } else {\n\
    \      ft.add(l, d, r);\n    }\n  }\n}"
  dependsOn:
  - misc/compress.hpp
  - datastructures/fentree/fenwick_tree_2d.hpp
  - datastructures/fentree/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 15:13:46-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
- /verify/verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp.html
title: verify/library_checker/data_structure/point_add_rectangle_sum.test.cpp
---
