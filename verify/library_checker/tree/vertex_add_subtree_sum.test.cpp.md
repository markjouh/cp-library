---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fentree/fenwick_tree.hpp
    title: datastructures/fentree/fenwick_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graphs/tree/euler_tour.hpp
    title: graphs/tree/euler_tour.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/library_checker/tree/vertex_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    \n#line 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing\
    \ namespace std;\n\n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r)\
    \ for (int i = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define\
    \ rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l,\
    \ r) for (int i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0,\
    \ n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\n#define\
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
    } init_io;\n#line 2 \"datastructures/fentree/fenwick_tree.hpp\"\n\ntemplate <class\
    \ T>\nstruct FenwickTree {\n  int n;\n  vector<T> ft;\n\n  FenwickTree(int x)\
    \ : n(x), ft(n + 1) {}\n\n  FenwickTree(const vector<T> &a) : n(sz(a)), ft(n +\
    \ 1) {\n    for (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n      if\
    \ (i + (i & -i) <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n\
    \  }\n\n  void add(int p, T v) {\n    // assert(p >= 0);\n    for (p++; p <= n;\
    \ p += p & -p) {\n      ft[p] += v;\n    }\n  }\n\n  T sum(int r) {\n    // assert(r\
    \ < n);\n    T res = 0;\n    for (r++; r > 0; r -= r & -r) {\n      res += ft[r];\n\
    \    }\n    return res;\n  }\n\n  T sum(int l, int r) {\n    return sum(r) - sum(l\
    \ - 1);\n  }\n};\n#line 2 \"graphs/tree/euler_tour.hpp\"\n\nstruct EulerTour {\n\
    \  vector<int> tin, tout;\n\n  EulerTour(const vector<vector<int>> &g, int root\
    \ = 0) : adj(g) {\n    tin.resize(sz(g));\n    tout.resize(sz(g));\n    dfs(root,\
    \ -1);\n  }\n\nprivate:\n  int time = 0;\n  const vector<vector<int>> &adj;\n\n\
    \  void dfs(int u, int par) {\n    tin[u] = time++;\n    for (int v : adj[u])\
    \ {\n      if (v != par) {\n        dfs(v, u);\n      }\n    }\n    tout[u] =\
    \ time;\n  }\n};\n#line 6 \"verify/library_checker/tree/vertex_add_subtree_sum.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int\
    \ i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  vector<vector<int>> g(n);\n \
    \ for (int i = 1; i < n; i++) {\n    int p;\n    cin >> p;\n    g[p].pb(i);\n\
    \  }\n  EulerTour et(g);\n  FenwickTree<ll> ft(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    ft.add(et.tin[i], a[i]);\n  }\n  while (q--) {\n    bool t;\n    int\
    \ u;\n    cin >> t >> u;\n    if (t) {\n      cout << ft.sum(et.tin[u], et.tout[u]\
    \ - 1) << '\\n';\n    } else {\n      int x;\n      cin >> x;\n      ft.add(et.tin[u],\
    \ x);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/fentree/fenwick_tree.hpp\"\
    \n#include \"../../../graphs/tree/euler_tour.hpp\"\n\nint main() {\n  int n, q;\n\
    \  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++) {\n    cin\
    \ >> a[i];\n  }\n  vector<vector<int>> g(n);\n  for (int i = 1; i < n; i++) {\n\
    \    int p;\n    cin >> p;\n    g[p].pb(i);\n  }\n  EulerTour et(g);\n  FenwickTree<ll>\
    \ ft(n);\n  for (int i = 0; i < n; i++) {\n    ft.add(et.tin[i], a[i]);\n  }\n\
    \  while (q--) {\n    bool t;\n    int u;\n    cin >> t >> u;\n    if (t) {\n\
    \      cout << ft.sum(et.tin[u], et.tout[u] - 1) << '\\n';\n    } else {\n   \
    \   int x;\n      cin >> x;\n      ft.add(et.tin[u], x);\n    }\n  }\n}"
  dependsOn:
  - datastructures/fentree/fenwick_tree.hpp
  - graphs/tree/euler_tour.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-09-03 12:19:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp.html
title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
---
