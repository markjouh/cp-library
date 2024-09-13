---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/w_ary_tree.hpp
    title: datastructures/w_ary_tree.hpp
  - icon: ':heavy_check_mark:'
    path: misc/compress.hpp
    title: misc/compress.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
  bundledCode: "#line 1 \"verify/aizu/alds1/priority_queue.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\n\n\
    #line 1 \"verify/boilerplate.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#line 2 \"utils/random.hpp\"\n\n#include <type_traits>\n\n// ----------------------------------------------------\n\
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
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"datastructures/w_ary_tree.hpp\"\
    \n\ntemplate <int N>\nstruct WAryTree {\n  uint32_t freq[N];\n  uint64_t l0[(N\
    \ >> 6) + 1], l1[(N >> 12) + 1], root;\n\n  WAryTree() {\n    memset(freq, 0,\
    \ sizeof freq);\n    memset(l0, 0, sizeof l0);\n    memset(l1, 0, sizeof l1);\n\
    \    root = 0;\n  }\n\n  void insert(int x) {\n    freq[x]++;\n    if (freq[x]\
    \ == 1) {\n      l0[x >> 6] |= 1ull << (x & 63);\n      if (__builtin_popcountll(l0[x\
    \ >> 6]) == 1) {\n        l1[x >> 12] |= 1ull << ((x >> 6) & 63);\n        if\
    \ (__builtin_popcountll(l1[x >> 12]) == 1) {\n          root |= 1ull << ((x >>\
    \ 12) & 63);\n        }\n      }\n    }\n  }\n\n  void remove(int x) {\n    freq[x]--;\n\
    \    if (freq[x] == 0) {\n      l0[x >> 6] ^= 1ull << (x & 63);\n      if (__builtin_popcountll(l0[x\
    \ >> 6]) == 0) {\n        l1[x >> 12] ^= 1ull << ((x >> 6) & 63);\n        if\
    \ (__builtin_popcountll(l1[x >> 12]) == 0) {\n          root ^= 1ull << ((x >>\
    \ 12) & 63);\n        }\n      }\n    }\n  }\n\n  int getMin() {\n    uint32_t\
    \ p = __builtin_ctzll(root);\n    p = (p << 6) + __builtin_ctzll(l1[p]);\n   \
    \ p = (p << 6) + __builtin_ctzll(l0[p]);\n    return p;\n  }\n\n  int getMax()\
    \ {\n    uint32_t p = 63 - __builtin_clzll(root);\n    p = (p << 6) + 63 - __builtin_clzll(l1[p]);\n\
    \    p = (p << 6) + 63 - __builtin_clzll(l0[p]);\n    return p;\n  }\n};\n#line\
    \ 2 \"misc/compress.hpp\"\n\ntemplate <class T>\nstruct Compress {\n  vector<T>\
    \ vals;\n\n  Compress() {}\n\n  Compress(const vector<T> &a) : vals(a) {\n   \
    \ init();\n  }\n\n  void init() {\n    sort(all(vals));\n    vals.resize(unique(all(vals))\
    \ - begin(vals));\n  }\n\n  void insert(T x) {\n    vals.push_back(x);\n  }\n\n\
    \  int get(T x) {\n    return lower_bound(all(vals), x) - begin(vals);\n  }\n\n\
    \  friend size_t size(const Compress &x) {\n    return size(x.vals);\n  }\n\n\
    \  T operator[](int p) {\n    return vals[p];\n  }\n};\n#line 6 \"verify/aizu/alds1/priority_queue.test.cpp\"\
    \n\nint main() {\n  string s;\n  int x;\n  vector<int> queries;\n  Compress<int>\
    \ vals;\n  while (cin >> s) {\n    if (s == \"end\") {\n      break;\n    }\n\
    \    if (s == \"insert\") {\n      cin >> x;\n      queries.push_back(x);\n  \
    \    vals.insert(x);\n    } else {\n      queries.push_back(-1);\n    }\n  }\n\
    \  vals.init();\n  WAryTree<2000000> ds;\n  for (auto x : queries) {\n    if (x\
    \ == -1) {\n      int idx = ds.getMax();\n      cout << vals[idx] << '\\n';\n\
    \      ds.remove(idx);\n    } else {\n      ds.insert(vals.get(x));\n    }\n \
    \ }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/w_ary_tree.hpp\"\
    \n#include \"../../../misc/compress.hpp\"\n\nint main() {\n  string s;\n  int\
    \ x;\n  vector<int> queries;\n  Compress<int> vals;\n  while (cin >> s) {\n  \
    \  if (s == \"end\") {\n      break;\n    }\n    if (s == \"insert\") {\n    \
    \  cin >> x;\n      queries.push_back(x);\n      vals.insert(x);\n    } else {\n\
    \      queries.push_back(-1);\n    }\n  }\n  vals.init();\n  WAryTree<2000000>\
    \ ds;\n  for (auto x : queries) {\n    if (x == -1) {\n      int idx = ds.getMax();\n\
    \      cout << vals[idx] << '\\n';\n      ds.remove(idx);\n    } else {\n    \
    \  ds.insert(vals.get(x));\n    }\n  }\n}"
  dependsOn:
  - utils/random.hpp
  - utils/timer.hpp
  - datastructures/w_ary_tree.hpp
  - misc/compress.hpp
  isVerificationFile: true
  path: verify/aizu/alds1/priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-09-13 16:07:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/priority_queue.test.cpp
- /verify/verify/aizu/alds1/priority_queue.test.cpp.html
title: verify/aizu/alds1/priority_queue.test.cpp
---
