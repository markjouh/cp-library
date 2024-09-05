---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/binary_search.hpp
    title: numeric/binary_search.hpp
  - icon: ':heavy_check_mark:'
    path: strings/hashing.hpp
    title: strings/hashing.hpp
  - icon: ':heavy_check_mark:'
    path: utils/builtins.hpp
    title: utils/builtins.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n\
    #line 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n#include\
    \ <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing namespace\
    \ std;\n\n#line 2 \"utils/builtins.hpp\"\n\n#if !__has_builtin(__lg)\ntemplate\
    \ <class T>\nint __lg(T x) {\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n\
    \  }\n  return res;\n}\n#endif\n\n#if !__has_builtin(__builtin_popcount)\nint\
    \ __builtin_popcount(unsigned int x) {\n  int res = 0;\n  for (int i = 0; i <\
    \ 32; i++) {\n    res += (x >> i) & 1;\n  }\n  return res;\n}\n#endif\n\n#if !__has_builtin(__builtin_popcountll)\n\
    int __builtin_popcountll(unsigned long long x) {\n  int res = 0;\n  for (int i\
    \ = 0; i < 64; i++) {\n    res += (x >> i) & 1;\n  }\n  return res;\n}\n}\n#endif\n\
    #line 2 \"utils/random.hpp\"\n\n#include <type_traits>\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \n// ----------------------------------------------------\n// Section: Basic random\
    \ data generation\n// ----------------------------------------------------\n\n\
    template <class T>\nT rnd(T lo, T hi) {\n  static_assert(is_arithmetic_v<T>, \"\
    Invalid type for rnd()\");\n  if constexpr (is_integral_v<T>) {\n    return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n  } else {\n    return uniform_real_distribution<T>(lo, hi)(rng_64);\n\
    \  }\n}\n\ntemplate <class T>\nconstexpr T def_val() {\n  if constexpr (is_floating_point_v<T>)\
    \ {\n    return 1;\n  } else {\n    return numeric_limits<T>::max() / 2;\n  }\n\
    }\n\n// ----------------------------------------------------\n//  => Bool wrapper\n\
    // ----------------------------------------------------\n\nbool randbool() {\n\
    \  return rnd<int>(0, 1);\n}\n\n// ----------------------------------------------------\n\
    //  => Int wrappers\n// ----------------------------------------------------\n\
    \nint randint(int lo, int hi) {\n  return rnd<int>(lo, hi);\n}\n\nint randint(int\
    \ hi) {\n  return randint(0, hi - 1);\n}\n\nint randint() {\n  return randint(def_val<int>());\n\
    }\n\n// ----------------------------------------------------\n//  => Long long\
    \ wrappers\n// ----------------------------------------------------\n\nlong long\
    \ randlong(long long lo, long long hi) {\n  return rnd<long long>(lo, hi);\n}\n\
    \nlong long randlong(long long hi) {\n  return randlong(0, hi);\n}\n\nlong long\
    \ randlong() {\n  return randlong(def_val<long long>());\n}\n\n// ----------------------------------------------------\n\
    //  => Double wrappers\n// ----------------------------------------------------\n\
    \ndouble randdoub(double lo, double hi) {\n  return rnd<double>(lo, hi);\n}\n\n\
    double randdoub(double hi) {\n  return randdoub(0, hi);\n}\n\ndouble randdoub()\
    \ {\n  return randdoub(1);\n}\n\n// ----------------------------------------------------\n\
    //  => Vector wrappers\n// ----------------------------------------------------\n\
    \ntemplate <class T>\nvector<T> randvec(int n, T lo, T hi) {\n  vector<T> res(n);\n\
    \  for (int i = 0; i < n; i++) {\n    res[i] = rnd<T>(lo, hi);\n  }\n  return\
    \ res;\n}\n\ntemplate <class T>\nvector<T> randvec(int n, T hi) {\n  return randvec<T>(n,\
    \ 0, hi);\n}\n\ntemplate <class T>\nvector<T> randvec(int n) {\n  return randvec<T>(n,\
    \ def_val<T>());\n}\n\n// ----------------------------------------------------\n\
    //  => Array wrappers\n// ----------------------------------------------------\n\
    \ntemplate <class T, size_t N>\narray<T, N> randarr(T lo, T hi) {\n  array<T,\
    \ N> res;\n  for (int i = 0; i < N; i++) {\n    res[i] = rnd<T>(lo, hi);\n  }\n\
    \  return res;\n}\n\ntemplate <class T, size_t N>\narray<T, N> randarr(T hi) {\n\
    \  return randarr<T, N>(0, hi);\n}\n\ntemplate <class T, size_t N>\narray<T, N>\
    \ randarr() {\n  return randarr<T, N>(def_val<T>());\n}\n\n// ----------------------------------------------------\n\
    // Section: Graph generation from Prufer sequences\n// ----------------------------------------------------\n\
    \nvector<pair<int, int>> gen_tree_edges(int n) {\n  const vector<int> prufer =\
    \ randvec(n - 2, 0, n - 1);\n  vector<int> deg(n, 1);\n  for (int x : prufer)\
    \ {\n    deg[x]++;\n  }\n  priority_queue<int, vector<int>, greater<>> leaves;\n\
    \  for (int i = 0; i < n; i++) {\n    if (deg[i] == 1) {\n      leaves.push(i);\n\
    \    }\n  }\n\n  vector<pair<int, int>> res;\n  res.reserve(n - 1);\n  for (int\
    \ v : prufer) {\n    int u = leaves.top();\n    leaves.pop();\n\n    res.push_back(minmax(u,\
    \ v));\n    deg[u]--, deg[v]--;\n\n    if (deg[v] == 1) {\n      leaves.push(v);\n\
    \    }\n  }\n\n  int r1 = -1, r2 = -1;\n  for (int i = 0; i < n; i++) {\n    if\
    \ (deg[i] == 1) {\n      (r1 == -1 ? r1 : r2) = i;\n    }\n  }\n  res.emplace_back(r1,\
    \ r2);\n\n  return res;\n}\n\nvector<pair<int, int>> gen_graph_edges(int n, int\
    \ m) {\n  assert(m >= n - 1 && m <= 1ll * n * (n - 1) / 2);\n\n  auto res = gen_tree_edges(n);\n\
    \  set<pair<int, int>> have;\n  for (auto [u, v] : res) {\n    have.emplace(u,\
    \ v);\n  }\n\n  while (ssize(res) < m) {\n    int u = randint(n), v = randint(n\
    \ - 1);\n    v += v >= u;\n    if (u > v) {\n      swap(u, v);\n    }\n    if\
    \ (!have.count({u, v})) {\n      res.emplace_back(u, v);\n      have.emplace(u,\
    \ v);\n    }\n  }\n  return res;\n}\n\n// ----------------------------------------------------\n\
    //  => Adjacency list wrappers\n// ----------------------------------------------------\n\
    \nvector<vector<int>> gen_graph(int n, int m, bool dir = false) {\n  vector<vector<int>>\
    \ g(n);\n  for (auto [u, v] : gen_graph_edges(n, m)) {\n    if (dir) {\n     \
    \ if (randbool()) {\n        swap(u, v);\n      }\n      g[u].push_back(v);\n\
    \    } else {\n      g[u].push_back(v);\n      g[v].push_back(u);\n    }\n  }\n\
    \  return g;\n}\n\nvector<vector<pair<int, int>>> gen_w_graph(int n, int m, int\
    \ lo = 1, int hi = def_val<int>(), bool dir = false) {\n  vector<vector<pair<int,\
    \ int>>> g(n);\n  for (auto [u, v] : gen_graph_edges(n, m)) {\n    const int w\
    \ = randint(lo, hi);\n    if (dir) {\n      if (randbool()) {\n        swap(u,\
    \ v);\n      }\n      g[u].emplace_back(v, w);\n    } else {\n      g[u].emplace_back(v,\
    \ w);\n      g[v].emplace_back(u, w);\n    }\n  }\n  return g;\n}\n#line 2 \"\
    utils/timer.hpp\"\n\nchrono::time_point<chrono::high_resolution_clock> timer;\n\
    \nvoid set_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n}\n\
    \nlong long elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}\n#line 25 \"verify/boilerplate.hpp\"\n\n#define arg4(a,\
    \ b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    #define pb push_back\n#define eb emplace_back\n#define fi first\n#define se second\n\
    \ntemplate <class T>\nusing vec = vector<T>;\n\nusing ll = long long;\nusing pii\
    \ = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class T>\nbool ckmin(T\
    \ &a, const T &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\n\
    bool ckmax(T &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate\
    \ <class T = int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\n\
    struct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"numeric/binary_search.hpp\"\
    \n\ntemplate <class T, class U>\nT bsmin(T lo, T hi, U f) {\n  assert(lo <= hi);\n\
    \  hi++;\n  for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n    hi -= (hi\
    \ - i >= lo && f(hi - i)) * i;\n  }\n  return hi;\n}\n\ntemplate <class T, class\
    \ U>\nT bsmax(T lo, T hi, U f) {\n  assert(lo <= hi);\n  lo--;\n  for (T i = T(1)\
    \ << __lg(hi - lo); i > 0; i >>= 1) {\n    lo += (lo + i <= hi && f(lo + i)) *\
    \ i;\n  }\n  return lo;\n}\n#line 2 \"strings/hashing.hpp\"\n\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst ll H_MOD = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0,\
    \ H_MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nusing mul_t = __int128_t;\n\nstruct\
    \ Hash {\n  ll val;\n  int len;\n\n  Hash(ll x, int y) : val(x), len(y) {}\n\n\
    \  Hash operator+(Hash b) {\n    return Hash((mul_t(val) * pow_b[b.len] + b.val)\
    \ % H_MOD, len + b.len);\n  }\n\n  bool operator==(Hash b) {\n    return val ==\
    \ b.val && len == b.len;\n  }\n};\n\nstruct StringHash {\n  int len;\n  vector<ll>\
    \ h;\n\n  template <class T>\n  StringHash(const T &s) : len(sz(s)), h(len + 1)\
    \ {\n    for (int i = 0; i < len; i++) {\n      h[i + 1] = (mul_t(h[i]) * H_BASE\
    \ + s[i]) % H_MOD;\n    }\n    while (sz(pow_b) <= len) {\n      pow_b.push_back(mul_t(pow_b.back())\
    \ * H_BASE % H_MOD);\n    }\n  }\n\n  Hash get(int l, int r) {\n    r++;\n   \
    \ return Hash(((h[r] - mul_t(h[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r\
    \ - l);\n  }\n\n  Hash get() {\n    return get(0, sz(h) - 1);\n  }\n};\n#line\
    \ 6 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\n\nint main()\
    \ {\n  string s;\n  cin >> s;\n  string rev = s;\n  reverse(all(rev));\n  StringHash\
    \ a(s), b(rev);\n  const int n = sz(s);\n  vector<int> ans(2 * n - 1);\n  for\
    \ (int i = 0; i < n; i++) {\n    ans[2 * i] = 2 * bsmax(0, min(i, n - i - 1),\
    \ [&](int d) {\n      return a.get(i - d, i) == b.get(n - i - 1 - d, n - i - 1);\n\
    \    }) + 1;\n  }\n  for (int i = 0; i < n - 1; i++) {\n    ans[2 * i + 1] = 2\
    \ * bsmax(0, min(i, n - i - 2), [&](int d) {\n      return a.get(i - d, i) ==\
    \ b.get(n - i - 2 - d, n - i - 2);\n    }) + 2;\n  }\n  for (int i = 0; i < 2\
    \ * n - 1; i++) {\n    cout << ans[i] << ' ';\n  }\n  cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../numeric/binary_search.hpp\"\
    \n#include \"../../../strings/hashing.hpp\"\n\nint main() {\n  string s;\n  cin\
    \ >> s;\n  string rev = s;\n  reverse(all(rev));\n  StringHash a(s), b(rev);\n\
    \  const int n = sz(s);\n  vector<int> ans(2 * n - 1);\n  for (int i = 0; i <\
    \ n; i++) {\n    ans[2 * i] = 2 * bsmax(0, min(i, n - i - 1), [&](int d) {\n \
    \     return a.get(i - d, i) == b.get(n - i - 1 - d, n - i - 1);\n    }) + 1;\n\
    \  }\n  for (int i = 0; i < n - 1; i++) {\n    ans[2 * i + 1] = 2 * bsmax(0, min(i,\
    \ n - i - 2), [&](int d) {\n      return a.get(i - d, i) == b.get(n - i - 2 -\
    \ d, n - i - 2);\n    }) + 2;\n  }\n  for (int i = 0; i < 2 * n - 1; i++) {\n\
    \    cout << ans[i] << ' ';\n  }\n  cout << '\\n';\n}"
  dependsOn:
  - utils/builtins.hpp
  - utils/random.hpp
  - utils/timer.hpp
  - numeric/binary_search.hpp
  - strings/hashing.hpp
  isVerificationFile: true
  path: verify/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 17:05:59-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---
