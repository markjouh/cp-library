---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/debug.hpp
    title: utils/debug.hpp
  - icon: ':heavy_check_mark:'
    path: utils/random.hpp
    title: utils/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/utils/debug.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"verify/boilerplate.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdint>\n\
    #include <cstring>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <vector>\n\nusing namespace std;\n\n#define arg4(a, b, c, d,\
    \ ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define\
    \ rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n\
    \ \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define\
    \ per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\ntemplate <class\
    \ T>\nusing vec = vector<T>;\n\nusing ll = long long;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n\ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n\
    \  return __lg(x);\n#else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n \
    \ }\n  return res;\n#endif\n}\n\ntemplate <class T>\nbool ckmin(T &a, const T\
    \ &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T =\
    \ int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\nstruct InitIO\
    \ {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"utils/random.hpp\"\
    \n\n#include <type_traits>\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T = int>\nT rnd(T lo, T hi) {\n  static_assert(is_arithmetic_v<T>,\
    \ \"Invalid type for rnd()\");\n  if constexpr (is_integral_v<T>) {\n    return\
    \ uniform_int_distribution<T>(lo, hi)(rng_64);\n  } else {\n    return uniform_real_distribution<T>(lo,\
    \ hi)(rng_64);\n  }\n}\n\ntemplate <class T = int>\nvec<T> rnd_vec(int n, T lo,\
    \ T hi) {\n  vec<T> res(n);\n  rep(i, n) {\n    res[i] = rnd<T>(lo, hi);\n  }\n\
    \  return res;\n}\n\nvec<pii> rnd_tree_edges(int n) {\n  const vec<int> prufer\
    \ = rnd_vec(n - 2, 0, n - 1);\n  vec<int> deg(n, 1);\n  for (int x : prufer) {\n\
    \    deg[x]++;\n  }\n  priority_queue<int, vec<int>, greater<>> leaves;\n  rep(i,\
    \ n) {\n    if (deg[i] == 1) {\n      leaves.push(i);\n    }\n  }\n\n  vec<pii>\
    \ res;\n  res.reserve(n - 1);\n  for (int v : prufer) {\n    int u = leaves.top();\n\
    \    leaves.pop();\n\n    res.pb(minmax(u, v));\n    deg[u]--, deg[v]--;\n\n \
    \   if (deg[v] == 1) {\n      leaves.push(v);\n    }\n  }\n\n  int r1 = -1, r2\
    \ = -1;\n  rep(i, n) {\n    if (deg[i] == 1) {\n      (r1 == -1 ? r1 : r2) = i;\n\
    \    }\n  }\n  assert(r2 != -1);\n  res.eb(r1, r2);\n\n  return res;\n}\n\nvec<pii>\
    \ rnd_graph_edges(int n, int m) {\n  assert(m >= n - 1 && m <= 1ll * n * (n -\
    \ 1) / 2);\n\n  auto res = rnd_tree_edges(n);\n  set<pii> have;\n  for (auto [u,\
    \ v] : res) {\n    have.emplace(u, v);\n  }\n\n  while (sz(res) < m) {\n    int\
    \ u = rnd<>(0, n - 1), v = rnd<>(0, n - 2);\n    v += v >= u;\n    if (u > v)\
    \ {\n      swap(u, v);\n    }\n    if (!have.count({u, v})) {\n      res.eb(u,\
    \ v);\n      have.emplace(u, v);\n    }\n  }\n  return res;\n}\n\nvec<vec<int>>\
    \ rnd_graph(int n, int m, bool directed = false) {\n  vec<vec<int>> g(n);\n  for\
    \ (auto [u, v] : rnd_graph_edges(n, m)) {\n    if (directed) {\n      if (rnd<>(0,\
    \ 1)) {\n        swap(u, v);\n      }\n      g[u].pb(v);\n    } else {\n     \
    \ g[u].pb(v);\n      g[v].pb(u);\n    }\n  }\n  return g;\n}\n\nvec<vec<pii>>\
    \ rnd_wgraph(int n, int m, int lo = 1, int hi = inf<>, bool directed = false)\
    \ {\n  vec<vec<pii>> g(n);\n  for (auto [u, v] : rnd_graph_edges(n, m)) {\n  \
    \  const int w = rnd<>(lo, hi);\n    if (directed) {\n      if (rnd<>(0, 1)) {\n\
    \        swap(u, v);\n      }\n      g[u].eb(v, w);\n    } else {\n      g[u].eb(v,\
    \ w);\n      g[v].eb(u, w);\n    }\n  }\n  return g;\n}\n#line 2 \"utils/debug.hpp\"\
    \n\nnamespace debug_internal {\n\nusing namespace std;\n\ntemplate <typename T>\n\
    concept is_core = requires(T x) {\n  cerr << x;\n};\n\ntemplate <typename T>\n\
    concept is_pair = requires(T x) {\n  x.first;\n  x.second;\n};\n\ntemplate <typename\
    \ T>\nconcept is_iterable = ranges::range<T>;\n\ntemplate <typename T>\nvoid print(T\
    \ x) {\n  if constexpr (is_core<T>) {\n    cerr << x;\n  } else if constexpr (is_pair<T>)\
    \ {\n    cerr << '(';\n    print(x.first);\n    cerr << \", \";\n    print(x.second);\n\
    \    cerr << ')';\n  } else if constexpr (is_iterable<T>) {\n    cerr << '[';\n\
    \    bool flag = false;\n    for (auto y : x) {\n      if (flag) {\n        cerr\
    \ << \", \";\n      }\n      print(y);\n      flag = true;\n    }\n    cerr <<\
    \ ']';\n  } else {\n    cerr << \"Unknown type\";\n  }\n}\n\ntemplate <typename\
    \ T>\nvoid debug(string s, T x) {\n  cerr << \"\\033[1;35m\" << s << \"\\033[0;0m\
    \ = \";\n  print(x);\n  cerr << endl;\n}\n\ntemplate <typename T, typename...\
    \ Args>\nvoid debug(string s, T x, Args... args) {\n  int idx = 0, layer = 0;\n\
    \  while (idx < ssize(s) && (s[idx] != ',' || layer != 0)) {\n    layer += s[idx]\
    \ == '(' || s[idx] == '{';\n    layer -= s[idx] == ')' || s[idx] == '}';\n   \
    \ idx++;\n  }\n  cerr << \"\\033[1;35m\" << s.substr(0, idx) << \"\\033[0;0m =\
    \ \";\n  print(x);\n  cerr << \"\\033[1;32m | \\033[0;0m\";\n  debug(s.substr(s.find_first_not_of('\
    \ ', idx + 1)), args...);\n}\n}\n\n#define dbg(...) debug_internal::debug(#__VA_ARGS__,\
    \ __VA_ARGS__)\n#line 6 \"verify/custom/utils/debug.test.cpp\"\n\n// Just some\
    \ random stuff, make sure\n// the output looks right\n\nint main() {\n  const\
    \ int n = rnd<>(0, 100);\n  vec<int> p = rnd_vec<>(n, 1, 100);\n  dbg(p);\n\n\
    \  map<int, vector<int>> mp;\n  for (int i = 0; i < 100; i++) {\n    mp[rnd<>(1,\
    \ 100)] = rnd_vec(100, 1, 100);\n  }\n  dbg(mp);\n\n  array<double, 100> arr;\n\
    \  for (int i = 0; i < 100; i++) {\n    arr[i] = rnd<double>(0, 1);\n  }\n  dbg(arr);\n\
    \n  int a, b;\n  cin >> a >> b;\n  cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../boilerplate.hpp\"\n#include \"../../../utils/random.hpp\"\n#include \"../../../utils/debug.hpp\"\
    \n\n// Just some random stuff, make sure\n// the output looks right\n\nint main()\
    \ {\n  const int n = rnd<>(0, 100);\n  vec<int> p = rnd_vec<>(n, 1, 100);\n  dbg(p);\n\
    \n  map<int, vector<int>> mp;\n  for (int i = 0; i < 100; i++) {\n    mp[rnd<>(1,\
    \ 100)] = rnd_vec(100, 1, 100);\n  }\n  dbg(mp);\n\n  array<double, 100> arr;\n\
    \  for (int i = 0; i < 100; i++) {\n    arr[i] = rnd<double>(0, 1);\n  }\n  dbg(arr);\n\
    \n  int a, b;\n  cin >> a >> b;\n  cout << a + b << '\\n';\n}"
  dependsOn:
  - utils/random.hpp
  - utils/debug.hpp
  isVerificationFile: true
  path: verify/custom/utils/debug.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 17:54:50-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/debug.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/debug.test.cpp
- /verify/verify/custom/utils/debug.test.cpp.html
title: verify/custom/utils/debug.test.cpp
---
