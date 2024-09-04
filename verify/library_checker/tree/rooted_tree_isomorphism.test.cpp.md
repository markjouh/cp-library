---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/tree/tree_isomorphism.hpp
    title: graphs/tree/tree_isomorphism.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"verify/library_checker/tree/rooted_tree_isomorphism.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#line 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n\
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
    #define eb emplace_back\n#define fi first\n#define se second\n\ntemplate <class\
    \ T>\nusing vec = vector<T>;\n\nusing ll = long long;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n\ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n\
    \  return __lg(x);\n#else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n \
    \ }\n  return res;\n#endif\n}\n\ntemplate <class T>\nbool ckmin(T &a, const T\
    \ &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T =\
    \ int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\nstruct InitIO\
    \ {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"graphs/tree/tree_isomorphism.hpp\"\
    \n\nstruct TreeIsomorphism {\n  map<vector<int>, int> hashes;\n\n  vector<int>\
    \ gen(const vector<vector<int>> &g, int rt = 0) {\n    vector<int> res(sz(g));\n\
    \    dfs(rt, -1, g, res);\n    return res;\n  }\n\nprivate:\n  void dfs(int u,\
    \ int par, auto &g, auto &res) {\n    vector<int> children;\n    for (int v :\
    \ g[u]) {\n      if (v != par) {\n        dfs(v, u, g, res);\n        children.push_back(res[v]);\n\
    \      }\n    }\n    sort(all(children));\n    if (!hashes.count(children)) {\n\
    \      hashes[children] = sz(hashes);\n    }\n    res[u] = hashes[children];\n\
    \  }\n};\n#line 5 \"verify/library_checker/tree/rooted_tree_isomorphism.test.cpp\"\
    \n\nint main() {\n  int n;\n  cin >> n;\n  vector<vector<int>> g(n);\n  for (int\
    \ i = 1; i < n; i++) {\n    int p;\n    cin >> p;\n    g[p].push_back(i);\n  }\n\
    \  TreeIsomorphism iso;\n  auto res = iso.gen(g);\n  cout << sz(iso.hashes) <<\
    \ '\\n';\n  for (int x : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../graphs/tree/tree_isomorphism.hpp\"\
    \n\nint main() {\n  int n;\n  cin >> n;\n  vector<vector<int>> g(n);\n  for (int\
    \ i = 1; i < n; i++) {\n    int p;\n    cin >> p;\n    g[p].push_back(i);\n  }\n\
    \  TreeIsomorphism iso;\n  auto res = iso.gen(g);\n  cout << sz(iso.hashes) <<\
    \ '\\n';\n  for (int x : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n\
    }"
  dependsOn:
  - graphs/tree/tree_isomorphism.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 17:54:50-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp.html
title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
---
