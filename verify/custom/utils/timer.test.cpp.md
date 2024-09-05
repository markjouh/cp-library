---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/random.hpp
    title: utils/random.hpp
  - icon: ':heavy_check_mark:'
    path: utils/timer.hpp
    title: utils/timer.hpp
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
  bundledCode: "#line 1 \"verify/custom/utils/timer.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#include <unistd.h>\n\n#line 1 \"\
    verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <climits>\n#include <cmath>\n\
    #include <cstdint>\n#include <cstring>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\nusing namespace std;\n\n#define\
    \ arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r);\
    \ i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3,\
    \ rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >=\
    \ int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__,\
    \ per3, per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n#define pb push_back\n#define eb emplace_back\n#define fi first\n\
    #define se second\n\ntemplate <class T>\nusing vec = vector<T>;\n\nusing ll =\
    \ long long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate\
    \ <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n#else\n\
    \  int res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n\
    }\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a =\
    \ b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return\
    \ b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf\
    \ = numeric_limits<T>::max() / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"utils/random.hpp\"\n\n#include <type_traits>\n\nmt19937_64\
    \ rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\ntemplate\
    \ <class T>\nT rnd(T lo, T hi) {\n  static_assert(is_arithmetic_v<T>, \"Invalid\
    \ type for rnd()\");\n  if constexpr (is_integral_v<T>) {\n    return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n  } else {\n    return uniform_real_distribution<T>(lo, hi)(rng_64);\n\
    \  }\n}\n\ntemplate <class T>\nconstexpr T def_val() {\n  if constexpr (is_floating_point_v<T>)\
    \ {\n    return 1;\n  } else {\n    return inf<T>;\n  }\n}\n\n/* ---- Boolean\
    \ wrapper ---- */\n\nbool randbool() {\n  return rnd<int>(0, 1);\n}\n\n/* ----\
    \ Int wrappers ---- */\n\nint randint(int lo, int hi) {\n  return rnd<int>(lo,\
    \ hi);\n}\n\nint randint(int hi) {\n  return randint(0, hi - 1);\n}\n\nint randint()\
    \ {\n  return randint(inf<int>);\n}\n\n/* ---- Long long wrappers ---- */\n\n\
    ll randlong(ll lo, ll hi) {\n  return rnd<ll>(lo, hi);\n}\n\nll randlong(ll hi)\
    \ {\n  return randlong(0, hi);\n}\n\nll randlong() {\n  return randlong(inf<ll>);\n\
    }\n\n/* ---- Double wrappers ---- */\n\ndouble randdoub(double lo, double hi)\
    \ {\n  return rnd<double>(lo, hi);\n}\n\ndouble randdoub(double hi) {\n  return\
    \ randdoub(0, hi);\n}\n\ndouble randdoub() {\n  return randdoub(1);\n}\n\n/* ----\
    \ Vector wrappers ---- */\n\ntemplate <class T>\nvec<T> randvec(int n, T lo, T\
    \ hi) {\n  vec<T> res(n);\n  rep(i, n) {\n    res[i] = rnd<T>(lo, hi);\n  }\n\
    \  return res;\n}\n\ntemplate <class T>\nvec<T> randvec(int n, T hi) {\n  return\
    \ randvec<T>(n, 0, hi);\n}\n\ntemplate <class T>\nvec<T> randvec(int n) {\n  return\
    \ randvec<T>(n, def_val<T>());\n}\n\n/* ---- Array wrappers ---- */\n\ntemplate\
    \ <class T, size_t N>\narray<T, N> randarr(T lo, T hi) {\n  array<T, N> res;\n\
    \  rep(i, N) {\n    res[i] = rnd<T>(lo, hi);\n  }\n  return res;\n}\n\ntemplate\
    \ <class T, size_t N>\narray<T, N> randarr(T hi) {\n  return randarr<T, N>(0,\
    \ hi);\n}\n\ntemplate <class T, size_t N>\narray<T, N> randarr() {\n  return randarr<T,\
    \ N>(def_val<T>());\n}\n\n/* ---- Graph generation from Prufer sequences ----\
    \ */\n\nvec<pii> gen_tree_edges(int n) {\n  const vec<int> prufer = randvec(n\
    \ - 2, 0, n - 1);\n  vec<int> deg(n, 1);\n  for (int x : prufer) {\n    deg[x]++;\n\
    \  }\n  priority_queue<int, vec<int>, greater<>> leaves;\n  rep(i, n) {\n    if\
    \ (deg[i] == 1) {\n      leaves.push(i);\n    }\n  }\n\n  vec<pii> res;\n  res.reserve(n\
    \ - 1);\n  for (int v : prufer) {\n    int u = leaves.top();\n    leaves.pop();\n\
    \n    res.pb(minmax(u, v));\n    deg[u]--, deg[v]--;\n\n    if (deg[v] == 1) {\n\
    \      leaves.push(v);\n    }\n  }\n\n  int r1 = -1, r2 = -1;\n  rep(i, n) {\n\
    \    if (deg[i] == 1) {\n      (r1 == -1 ? r1 : r2) = i;\n    }\n  }\n  assert(r2\
    \ != -1);\n  res.eb(r1, r2);\n\n  return res;\n}\n\nvec<pii> gen_graph_edges(int\
    \ n, int m) {\n  assert(m >= n - 1 && m <= 1ll * n * (n - 1) / 2);\n\n  auto res\
    \ = gen_tree_edges(n);\n  set<pii> have;\n  for (auto [u, v] : res) {\n    have.emplace(u,\
    \ v);\n  }\n\n  while (sz(res) < m) {\n    int u = rnd<>(0, n - 1), v = rnd<>(0,\
    \ n - 2);\n    v += v >= u;\n    if (u > v) {\n      swap(u, v);\n    }\n    if\
    \ (!have.count({u, v})) {\n      res.eb(u, v);\n      have.emplace(u, v);\n  \
    \  }\n  }\n  return res;\n}\n\nvec<vec<int>> gen_graph(int n, int m, bool directed\
    \ = false) {\n  vec<vec<int>> g(n);\n  for (auto [u, v] : gen_graph_edges(n, m))\
    \ {\n    if (directed) {\n      if (rnd<>(0, 1)) {\n        swap(u, v);\n    \
    \  }\n      g[u].pb(v);\n    } else {\n      g[u].pb(v);\n      g[v].pb(u);\n\
    \    }\n  }\n  return g;\n}\n\nvec<vec<pii>> gen_w_graph(int n, int m, int lo\
    \ = 1, int hi = inf<>, bool directed = false) {\n  vec<vec<pii>> g(n);\n  for\
    \ (auto [u, v] : gen_graph_edges(n, m)) {\n    const int w = rnd<>(lo, hi);\n\
    \    if (directed) {\n      if (rnd<>(0, 1)) {\n        swap(u, v);\n      }\n\
    \      g[u].eb(v, w);\n    } else {\n      g[u].eb(v, w);\n      g[v].eb(u, w);\n\
    \    }\n  }\n  return g;\n}\n#line 2 \"utils/timer.hpp\"\n\nchrono::time_point<chrono::high_resolution_clock>\
    \ timer;\n\nvoid set_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n\
    }\n\nll elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}\n#line 8 \"verify/custom/utils/timer.test.cpp\"\n\n//\
    \ Kind of pointless, but I'll write a test for\n// completionism's sake...\n\n\
    const int TESTS = 10;\n\nint main() {\n  rep(i, TESTS) {\n    const int rand_ms\
    \ = randint(50, 500);\n    set_timer();\n    usleep(rand_ms * 1000);\n    assert(abs(elapsed()\
    \ - rand_ms) < 10);\n  }\n\n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <unistd.h>\n\
    \n#include \"../../boilerplate.hpp\"\n#include \"../../../utils/random.hpp\"\n\
    #include \"../../../utils/timer.hpp\"\n\n// Kind of pointless, but I'll write\
    \ a test for\n// completionism's sake...\n\nconst int TESTS = 10;\n\nint main()\
    \ {\n  rep(i, TESTS) {\n    const int rand_ms = randint(50, 500);\n    set_timer();\n\
    \    usleep(rand_ms * 1000);\n    assert(abs(elapsed() - rand_ms) < 10);\n  }\n\
    \n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin >> a >> b;\n  cout << a\
    \ + b << '\\n';\n}"
  dependsOn:
  - utils/random.hpp
  - utils/timer.hpp
  isVerificationFile: true
  path: verify/custom/utils/timer.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 16:18:48-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/timer.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/timer.test.cpp
- /verify/verify/custom/utils/timer.test.cpp.html
title: verify/custom/utils/timer.test.cpp
---
