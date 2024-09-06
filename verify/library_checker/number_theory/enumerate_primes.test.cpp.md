---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/number_theory.hpp
    title: numeric/number_theory.hpp
  - icon: ':question:'
    path: utils/random.hpp
    title: utils/random.hpp
  - icon: ':question:'
    path: utils/timer.hpp
    title: utils/timer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"verify/library_checker/number_theory/enumerate_primes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#line\
    \ 1 \"verify/boilerplate.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#line 2 \"utils/random.hpp\"\n\n#include <type_traits>\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \ - timer)).count();\n}\n#line 7 \"verify/boilerplate.hpp\"\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n#define\
    \ eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long long;\n\
    \ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a = b,\
    \ 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return b\
    \ > a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf =\
    \ numeric_limits<T>::max() / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"numeric/number_theory.hpp\"\n\nvector<int> mn_fac, primes;\n\
    \nvoid sieve(int n) {\n  mn_fac.resize(n + 1);\n  for (int i = 2; i <= n; i++)\
    \ {\n    if (!mn_fac[i]) {\n      mn_fac[i] = i;\n      primes.push_back(i);\n\
    \      for (ll j = 1ll * i * i; j <= n; j += i) {\n        if (!mn_fac[j]) {\n\
    \          mn_fac[j] = i;\n        }\n      }\n    }\n  }\n}\n\ntemplate<class\
    \ T> vector<pair<T, int>> factor(T num) {\n  vector<pair<T, int>> res;\n\n  if\
    \ (num <= sz(mn_fac) - 1) {\n    while (num > 1) {\n      int fac = mn_fac[num];\n\
    \      res.emplace_back(fac, 0);\n      while (num % fac == 0) {\n        num\
    \ /= fac;\n        res.back().second++;\n      }\n    }\n    return res;\n  }\n\
    \n  for (int p : primes) {\n    if (1ll * p * p > num) {\n      break;\n    }\n\
    \    int exp = 0;\n    while (num % p == 0) {\n      num /= p;\n      exp++;\n\
    \    }\n    if (exp) {\n      res.emplace_back(p, exp);\n    }\n  }\n  if (num\
    \ > 1) {\n    res.emplace_back(num, 1);\n  }\n  return res;\n}\n\ntemplate<class\
    \ T> vector<T> gen_divisors(vector<pair<T, int>> facs) {\n  vector<T> res = {1};\n\
    \  for (auto [p, exp] : facs) {\n    const int prev_layer = sz(res);\n    T coeff\
    \ = 1;\n    for (int i = 0; i < exp; i++) {\n      coeff *= p;\n      for (int\
    \ j = 0; j < prev_layer; j++) {\n        res.push_back(coeff * res[j]);\n    \
    \  }\n    }\n  }\n  return res;\n}\n#line 5 \"verify/library_checker/number_theory/enumerate_primes.test.cpp\"\
    \n\nint main() {\n  int n, a, b;\n  cin >> n >> a >> b;\n  sieve(n);\n  cout <<\
    \ sz(primes) << ' ';\n  vector<int> res;\n  for (int i = b; i < sz(primes); i\
    \ += a) {\n    res.push_back(primes[i]);\n  }\n  cout << sz(res) << '\\n';\n \
    \ for (int x : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include \"../../boilerplate.hpp\"\n#include \"../../../numeric/number_theory.hpp\"\
    \n\nint main() {\n  int n, a, b;\n  cin >> n >> a >> b;\n  sieve(n);\n  cout <<\
    \ sz(primes) << ' ';\n  vector<int> res;\n  for (int i = b; i < sz(primes); i\
    \ += a) {\n    res.push_back(primes[i]);\n  }\n  cout << sz(res) << '\\n';\n \
    \ for (int x : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n}"
  dependsOn:
  - utils/random.hpp
  - utils/timer.hpp
  - numeric/number_theory.hpp
  isVerificationFile: true
  path: verify/library_checker/number_theory/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 22:57:47-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number_theory/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp.html
title: verify/library_checker/number_theory/enumerate_primes.test.cpp
---
