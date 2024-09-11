---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: numeric/binary_search_reals.hpp
    title: numeric/binary_search_reals.hpp
  - icon: ':question:'
    path: utils/random.hpp
    title: utils/random.hpp
  - icon: ':question:'
    path: utils/timer.hpp
    title: utils/timer.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/numeric/binary_search_reals.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"verify/boilerplate.hpp\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#line 2 \"utils/random.hpp\"\
    \n\n#include <type_traits>\n\n// ----------------------------------------------------\n\
    // Basic random data generation\n// ----------------------------------------------------\n\
    \nmt19937_64 rngEngine(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T>\nT myRand(T lo, T hi) {\n  static_assert(is_arithmetic_v<T>,\
    \ \"Invalid type for myRand()\");\n  if constexpr (is_integral_v<T>) {\n    return\
    \ uniform_int_distribution<T>(lo, hi)(rngEngine);\n  } else {\n    return uniform_real_distribution<T>(lo,\
    \ hi)(rngEngine);\n  }\n}\n\ntemplate <class T>\nconstexpr T defaultVal() {\n\
    \  if constexpr (is_floating_point_v<T>) {\n    return 1;\n  } else {\n    return\
    \ numeric_limits<T>::max() / 2;\n  }\n}\n\nbool randBool() {\n  return myRand<int>(0,\
    \ 1);\n}\n\nint randInt(int lo, int hi) {\n  return myRand<int>(lo, hi);\n}\n\n\
    int randInt(int hi) {\n  return randInt(0, hi - 1);\n}\n\nint randInt() {\n  return\
    \ randInt(defaultVal<int>());\n}\n\nlong long randLong(long long lo, long long\
    \ hi) {\n  return myRand<long long>(lo, hi);\n}\n\nlong long randLong(long long\
    \ hi) {\n  return randLong(0, hi);\n}\n\nlong long randLong() {\n  return randLong(defaultVal<long\
    \ long>());\n}\n\ndouble randDoub(double lo, double hi) {\n  return myRand<double>(lo,\
    \ hi);\n}\n\ndouble randDoub(double hi) {\n  return randDoub(0, hi);\n}\n\ndouble\
    \ randDoub() {\n  return randDoub(1);\n}\n\ntemplate <class T>\nvector<T> randVec(int\
    \ n, T lo, T hi) {\n  vector<T> res(n);\n  for (int i = 0; i < n; i++) {\n   \
    \ res[i] = myRand<T>(lo, hi);\n  }\n  return res;\n}\n\ntemplate <class T>\nvector<T>\
    \ randVec(int n, T hi) {\n  return randVec<T>(n, 0, hi);\n}\n\ntemplate <class\
    \ T>\nvector<T> randVec(int n) {\n  return randVec<T>(n, defaultVal<T>());\n}\n\
    \ntemplate <class T, size_t N>\narray<T, N> randArr(T lo, T hi) {\n  array<T,\
    \ N> res;\n  for (int i = 0; i < N; i++) {\n    res[i] = myRand<T>(lo, hi);\n\
    \  }\n  return res;\n}\n\ntemplate <class T, size_t N>\narray<T, N> randArr(T\
    \ hi) {\n  return randArr<T, N>(0, hi);\n}\n\ntemplate <class T, size_t N>\narray<T,\
    \ N> randArr() {\n  return randArr<T, N>(defaultVal<T>());\n}\n\n// ----------------------------------------------------\n\
    // Graph generation from Prufer sequences\n// ----------------------------------------------------\n\
    \nvector<pair<int, int>> genTreeEdges(int n) {\n  const vector<int> prufer = randVec(n\
    \ - 2, 0, n - 1);\n  vector<int> deg(n, 1);\n  for (int x : prufer) {\n    deg[x]++;\n\
    \  }\n  priority_queue<int, vector<int>, greater<>> leaves;\n  for (int i = 0;\
    \ i < n; i++) {\n    if (deg[i] == 1) {\n      leaves.push(i);\n    }\n  }\n\n\
    \  vector<pair<int, int>> res;\n  res.reserve(n - 1);\n  for (int v : prufer)\
    \ {\n    int u = leaves.top();\n    leaves.pop();\n\n    res.push_back(minmax(u,\
    \ v));\n    deg[u]--, deg[v]--;\n\n    if (deg[v] == 1) {\n      leaves.push(v);\n\
    \    }\n  }\n\n  int rootA = -1, rootB = -1;\n  for (int i = 0; i < n; i++) {\n\
    \    if (deg[i] == 1) {\n      (rootA == -1 ? rootA : rootB) = i;\n    }\n  }\n\
    \  res.emplace_back(rootA, rootB);\n\n  return res;\n}\n\nvector<pair<int, int>>\
    \ genGraphEdges(int n, int m) {\n  assert(m >= n - 1 && m <= 1ll * n * (n - 1)\
    \ / 2);\n\n  auto res = genTreeEdges(n);\n  set<pair<int, int>> have;\n  for (auto\
    \ [u, v] : res) {\n    have.emplace(u, v);\n  }\n\n  while (ssize(res) < m) {\n\
    \    int u = randInt(n), v = randInt(n - 1);\n    v += v >= u;\n    if (u > v)\
    \ {\n      swap(u, v);\n    }\n    if (!have.count({u, v})) {\n      res.emplace_back(u,\
    \ v);\n      have.emplace(u, v);\n    }\n  }\n  return res;\n}\n\nvector<vector<int>>\
    \ genGraph(int n, int m, bool dir = false) {\n  vector<vector<int>> g(n);\n  for\
    \ (auto [u, v] : genGraphEdges(n, m)) {\n    if (dir) {\n      if (randBool())\
    \ {\n        swap(u, v);\n      }\n      g[u].push_back(v);\n    } else {\n  \
    \    g[u].push_back(v);\n      g[v].push_back(u);\n    }\n  }\n  return g;\n}\n\
    \nvector<vector<pair<int, int>>> genWeightedGraph(int n, int m, int lo = 1, int\
    \ hi = defaultVal<int>(), bool dir = false) {\n  vector<vector<pair<int, int>>>\
    \ g(n);\n  for (auto [u, v] : genGraphEdges(n, m)) {\n    const int w = randInt(lo,\
    \ hi);\n    if (dir) {\n      if (randBool()) {\n        swap(u, v);\n      }\n\
    \      g[u].emplace_back(v, w);\n    } else {\n      g[u].emplace_back(v, w);\n\
    \      g[v].emplace_back(u, w);\n    }\n  }\n  return g;\n}\n#line 2 \"utils/timer.hpp\"\
    \n\nchrono::time_point<chrono::high_resolution_clock> timer;\n\nvoid startTimer()\
    \ {\n  timer = std::chrono::high_resolution_clock::now();\n}\n\nlong long elapsed()\
    \ {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}\n#line 7 \"verify/boilerplate.hpp\"\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing u32 = unsigned int;\n\
    using i64 = long long;\nusing u64 = unsigned long long;\n\ntemplate <class T>\n\
    bool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate\
    \ <class T>\nbool ckmax(T &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n\
    }\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"numeric/binary_search_reals.hpp\"\
    \n\ntemplate <class T>\ndouble bsminReals(double lo, double hi, T f) {\n  static_assert(sizeof(u64)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  u64 l = reinterpret_cast<u64&>(lo),\
    \ r = reinterpret_cast<u64&>(hi) + 1;\n  for (u64 i = 1ull << __lg(r - l); i >\
    \ 0; i >>= 1) {\n    u64 nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\n\
    double bsmaxReals(double lo, double hi, T f) {\n  static_assert(sizeof(u64) >=\
    \ sizeof(double));\n  assert(lo <= hi);\n  u64 l = reinterpret_cast<u64&>(lo)\
    \ - 1, r = reinterpret_cast<u64&>(hi);\n  for (u64 i = 1ull << __lg(r - l); i\
    \ > 0; i >>= 1) {\n    u64 nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n#line 5 \"verify/custom/numeric/binary_search_reals.test.cpp\"\
    \n\nconst int TESTS = 1e6;\nconst double MXV = 1e12, ERROR = 1e-3;\n\nvoid test()\
    \ {\n  // Search for exact double value, should have no error\n  const double\
    \ t1 = randDoub(inf<double>);\n  double left = bsmaxReals(0, inf<double>, [&](double\
    \ x) {\n    return x <= t1;\n  });\n  assert(left == t1);\n  double right = bsminReals(0,\
    \ inf<double>, [&](double x) {\n    return x >= t1;\n  });\n  assert(right ==\
    \ t1);\n\n  // Try computing sqrt\n  const double t2 = randDoub(MXV);\n  double\
    \ sqrtVal = bsmaxReals(0, MXV, [&](double x) {\n    return x * x <= t2;\n  });\n\
    \  double sqrtProd = sqrtVal * sqrtVal;\n  assert(sqrtProd <= t2 && t2 - sqrtProd\
    \ < ERROR);\n\n  // Try computing cbrt\n  const double t3 = randDoub(MXV);\n \
    \ double cbrtVal = bsmaxReals(0, MXV, [&](double x) {\n    return x * x * x <=\
    \ t3;\n  });\n  double cbrtProd = cbrtVal * cbrtVal * cbrtVal;\n  assert(cbrtProd\
    \ <= t3 && t3 - cbrtProd < ERROR);\n}\n\nint main() {\n  for (int i = 0; i < TESTS;\
    \ i++) {\n    test();\n  }\n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../boilerplate.hpp\"\n#include \"../../../numeric/binary_search_reals.hpp\"\
    \n\nconst int TESTS = 1e6;\nconst double MXV = 1e12, ERROR = 1e-3;\n\nvoid test()\
    \ {\n  // Search for exact double value, should have no error\n  const double\
    \ t1 = randDoub(inf<double>);\n  double left = bsmaxReals(0, inf<double>, [&](double\
    \ x) {\n    return x <= t1;\n  });\n  assert(left == t1);\n  double right = bsminReals(0,\
    \ inf<double>, [&](double x) {\n    return x >= t1;\n  });\n  assert(right ==\
    \ t1);\n\n  // Try computing sqrt\n  const double t2 = randDoub(MXV);\n  double\
    \ sqrtVal = bsmaxReals(0, MXV, [&](double x) {\n    return x * x <= t2;\n  });\n\
    \  double sqrtProd = sqrtVal * sqrtVal;\n  assert(sqrtProd <= t2 && t2 - sqrtProd\
    \ < ERROR);\n\n  // Try computing cbrt\n  const double t3 = randDoub(MXV);\n \
    \ double cbrtVal = bsmaxReals(0, MXV, [&](double x) {\n    return x * x * x <=\
    \ t3;\n  });\n  double cbrtProd = cbrtVal * cbrtVal * cbrtVal;\n  assert(cbrtProd\
    \ <= t3 && t3 - cbrtProd < ERROR);\n}\n\nint main() {\n  for (int i = 0; i < TESTS;\
    \ i++) {\n    test();\n  }\n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << '\\n';\n}"
  dependsOn:
  - utils/random.hpp
  - utils/timer.hpp
  - numeric/binary_search_reals.hpp
  isVerificationFile: true
  path: verify/custom/numeric/binary_search_reals.test.cpp
  requiredBy: []
  timestamp: '2024-09-11 14:56:51-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/custom/numeric/binary_search_reals.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/numeric/binary_search_reals.test.cpp
- /verify/verify/custom/numeric/binary_search_reals.test.cpp.html
title: verify/custom/numeric/binary_search_reals.test.cpp
---
