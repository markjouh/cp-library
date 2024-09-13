---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/debug.hpp
    title: utils/debug.hpp
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
  bundledCode: "#line 1 \"verify/custom/utils/debug.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"verify/boilerplate.hpp\"\
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
    \ randDoub() {\n  return randDoub(1);\n}\n\nstring randStr(int n, int k) {\n \
    \ string s(n, ' ');\n  for (int i = 0; i < n; i++) {\n    s[i] = char('a' + randInt(k));\n\
    \  }\n  return s;\n}\n\ntemplate <class T>\nvector<T> randVec(int n, T lo, T hi)\
    \ {\n  vector<T> res(n);\n  for (int i = 0; i < n; i++) {\n    res[i] = myRand<T>(lo,\
    \ hi);\n  }\n  return res;\n}\n\ntemplate <class T>\nvector<T> randVec(int n,\
    \ T hi) {\n  return randVec<T>(n, 0, hi);\n}\n\ntemplate <class T>\nvector<T>\
    \ randVec(int n) {\n  return randVec<T>(n, defaultVal<T>());\n}\n\ntemplate <class\
    \ T, size_t N>\narray<T, N> randArr(T lo, T hi) {\n  array<T, N> res;\n  for (int\
    \ i = 0; i < N; i++) {\n    res[i] = myRand<T>(lo, hi);\n  }\n  return res;\n\
    }\n\ntemplate <class T, size_t N>\narray<T, N> randArr(T hi) {\n  return randArr<T,\
    \ N>(0, hi);\n}\n\ntemplate <class T, size_t N>\narray<T, N> randArr() {\n  return\
    \ randArr<T, N>(defaultVal<T>());\n}\n\n// ----------------------------------------------------\n\
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
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"utils/debug.hpp\"\
    \n\nnamespace debug_internal {\n\nusing namespace std;\n\ntemplate <typename T>\n\
    concept isCore = requires(T x) {\n  cerr << x;\n};\n\ntemplate <typename T>\n\
    concept isPair = requires(T x) {\n  x.first;\n  x.second;\n};\n\ntemplate <typename\
    \ T>\nconcept isIterable = ranges::range<T>;\n\ntemplate <typename T>\nvoid print(T\
    \ x) {\n  if constexpr (isCore<T>) {\n    cerr << x;\n  } else if constexpr (isPair<T>)\
    \ {\n    cerr << '(';\n    print(x.first);\n    cerr << \", \";\n    print(x.second);\n\
    \    cerr << ')';\n  } else if constexpr (isIterable<T>) {\n    cerr << '[';\n\
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
    \ __VA_ARGS__)\n#line 5 \"verify/custom/utils/debug.test.cpp\"\n\n// Just some\
    \ random stuff, make sure\n// the output looks right\n\nint main() {\n  const\
    \ int n = randInt(100);\n  vector<int> p = randVec<int>(n);\n  dbg(p);\n\n  map<int,\
    \ vector<int>> mp;\n  for (int i = 0; i < 100; i++) {\n    mp[randInt()] = randVec<int>(100);\n\
    \  }\n  dbg(mp);\n\n  array<double, 100> arr = randArr<double, 100>();\n  dbg(arr);\n\
    \n  int a, b;\n  cin >> a >> b;\n  cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../boilerplate.hpp\"\n#include \"../../../utils/debug.hpp\"\n\n// Just some\
    \ random stuff, make sure\n// the output looks right\n\nint main() {\n  const\
    \ int n = randInt(100);\n  vector<int> p = randVec<int>(n);\n  dbg(p);\n\n  map<int,\
    \ vector<int>> mp;\n  for (int i = 0; i < 100; i++) {\n    mp[randInt()] = randVec<int>(100);\n\
    \  }\n  dbg(mp);\n\n  array<double, 100> arr = randArr<double, 100>();\n  dbg(arr);\n\
    \n  int a, b;\n  cin >> a >> b;\n  cout << a + b << '\\n';\n}"
  dependsOn:
  - utils/random.hpp
  - utils/timer.hpp
  - utils/debug.hpp
  isVerificationFile: true
  path: verify/custom/utils/debug.test.cpp
  requiredBy: []
  timestamp: '2024-09-13 16:07:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/debug.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/debug.test.cpp
- /verify/verify/custom/utils/debug.test.cpp.html
title: verify/custom/utils/debug.test.cpp
---
