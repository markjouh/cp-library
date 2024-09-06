---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/encode.hpp
    title: utils/encode.hpp
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
  bundledCode: "#line 1 \"verify/custom/utils/encode.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"verify/boilerplate.hpp\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 2 \"utils/random.hpp\"\
    \n\n#include <type_traits>\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    } init_io;\n#line 2 \"utils/encode.hpp\"\n\nconstexpr uint64_t pow_94[10] = {1,\
    \ 94, 8836, 830584, 78074896, 7339040224, 689869781056, 64847759419264, 6095689385410816,\
    \ 572994802228616704};\n\ntemplate <class T, int W>\nstring encode(T x) {\n  if\
    \ constexpr (is_integral_v<T>) {\n    string res(W, 0);\n    for (int i = 0; i\
    \ < W; i++) {\n      res[i] = char(33 + x % 94);\n      x /= 94;\n    }\n    return\
    \ res;\n  } else {\n    string res;\n    for (auto &y : x) {\n      res += encode<typename\
    \ T::value_type, W>(y);\n    }\n    return res;\n  }\n}\n\ntemplate <class T,\
    \ int W>\nT decode(string s) {\n  if constexpr (is_integral_v<T>) {\n    T res\
    \ = 0;\n    for (int i = 0; i < W; i++) {\n      res += pow_94[i] * uint64_t(s[i]\
    \ - 33);\n    }\n    return res;\n  } else {\n    constexpr int segs = tuple_size_v<T>;\n\
    \    const int len = ssize(s) / segs;\n    T res;\n    for (int i = 0; i < segs;\
    \ i++) {\n      res[i] = decode<typename T::value_type, W>(s.substr(len * i, len));\n\
    \    }\n    return res;\n  }\n}\n\n#define make_encoded(type, x, w) cout << \"\
    const \" << type << ' ' << #x << \" = decode<\" << type << \", \" << w << \">(R\\\
    \"zzzzz(\" << encode<decltype(x), w>(x) << \")zzzzz\\\")\" << endl\n#line 5 \"\
    verify/custom/utils/encode.test.cpp\"\n\nconst int TESTS = 1000;\n\nint main()\
    \ {\n  for (int i = 0; i < TESTS; i++) {\n    array<int, 2500> arr;\n    for (int\
    \ j = 0; j < 2500; j++) {\n      arr[j] = randint(inf<int>);\n    }\n    auto\
    \ enc = encode<decltype(arr), 5>(arr);\n    auto dec = decode<decltype(arr), 5>(enc);\n\
    \    assert(arr == dec);\n  }\n\n  for (int i = 0; i < TESTS; i++) {\n    array<array<int,\
    \ 50>, 50> arr;\n    for (int j = 0; j < 50; j++) {\n      for (int k = 0; k <\
    \ 50; k++) {\n        arr[j][k] = randint(inf<int>);\n      }\n    }\n    auto\
    \ enc = encode<decltype(arr), 5>(arr);\n    auto dec = decode<decltype(arr), 5>(enc);\n\
    \    assert(arr == dec);\n  }\n\n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n\
    \  cin >> a >> b;\n  cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../boilerplate.hpp\"\n#include \"../../../utils/encode.hpp\"\n\nconst int TESTS\
    \ = 1000;\n\nint main() {\n  for (int i = 0; i < TESTS; i++) {\n    array<int,\
    \ 2500> arr;\n    for (int j = 0; j < 2500; j++) {\n      arr[j] = randint(inf<int>);\n\
    \    }\n    auto enc = encode<decltype(arr), 5>(arr);\n    auto dec = decode<decltype(arr),\
    \ 5>(enc);\n    assert(arr == dec);\n  }\n\n  for (int i = 0; i < TESTS; i++)\
    \ {\n    array<array<int, 50>, 50> arr;\n    for (int j = 0; j < 50; j++) {\n\
    \      for (int k = 0; k < 50; k++) {\n        arr[j][k] = randint(inf<int>);\n\
    \      }\n    }\n    auto enc = encode<decltype(arr), 5>(arr);\n    auto dec =\
    \ decode<decltype(arr), 5>(enc);\n    assert(arr == dec);\n  }\n\n  cerr << \"\
    Tests passed\\n\";\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << '\\n';\n\
    }"
  dependsOn:
  - utils/random.hpp
  - utils/timer.hpp
  - utils/encode.hpp
  isVerificationFile: true
  path: verify/custom/utils/encode.test.cpp
  requiredBy: []
  timestamp: '2024-09-05 22:57:47-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/encode.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/encode.test.cpp
- /verify/verify/custom/utils/encode.test.cpp.html
title: verify/custom/utils/encode.test.cpp
---
