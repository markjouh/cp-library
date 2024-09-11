---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/binary_trie.hpp
    title: numeric/binary_trie.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 1 \"\
    verify/boilerplate.hpp\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    #line 2 \"utils/random.hpp\"\n\n#include <type_traits>\n\n// ----------------------------------------------------\n\
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
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"numeric/binary_trie.hpp\"\
    \n\nstruct BinaryTrie {\n  vector<array<int, 2>> nxt;\n  vector<int> cnt;\n\n\
    \  BinaryTrie() : nxt(1, {-1, -1}), cnt(1, 0) {}\n\n  int count(unsigned int x)\
    \ {\n    int pos = 0;\n    for (int i = 31; i >= 0; i--) {\n      pos = nxt[pos][(x\
    \ >> i) & 1];\n      if (pos == -1) {\n        return 0;\n      }\n    }\n   \
    \ return cnt[pos];\n  }\n\n  void insert(unsigned int x) {\n    int pos = 0;\n\
    \    for (int i = 31; i >= 0; i--) {\n      bool dir = (x >> i) & 1;\n      if\
    \ (nxt[pos][dir] == -1) {\n        nxt[pos][dir] = sz(nxt);\n        nxt.push_back({-1,\
    \ -1});\n        cnt.push_back(0);\n      }\n      pos = nxt[pos][dir];\n    \
    \  cnt[pos]++;\n    }\n  }\n\n  void remove(unsigned int x) {\n    int pos = 0;\n\
    \    for (int i = 31; i >= 0; i--) {\n      pos = nxt[pos][(x >> i) & 1];\n  \
    \    cnt[pos]--;\n    }\n  }\n\n  unsigned int minXor(unsigned int x) {\n    int\
    \ pos = 0;\n    unsigned int res = 0;\n    for (int i = 31; i >= 0; i--) {\n \
    \     bool dir = (x >> i) & 1;\n      if (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]]\
    \ == 0) {\n        res |= 1 << i;\n        pos = nxt[pos][dir ^ 1];\n      } else\
    \ {\n        pos = nxt[pos][dir];\n      }\n    }\n    return res;\n  }\n\n  unsigned\
    \ int maxXor(unsigned int x) {\n    static const unsigned int mask = -1;\n   \
    \ return mask ^ minXor(x ^ mask);\n  }\n};\n#line 5 \"verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n\nint main() {\n  int q;\n  cin >> q;\n  BinaryTrie bt;\n  while (q--) {\n \
    \   int t, x;\n    cin >> t >> x;\n    if (t == 0) {\n      if (bt.count(x) ==\
    \ 0) {\n        bt.insert(x);\n      }\n    } else if (t == 1) {\n      if (bt.count(x)\
    \ == 1) {\n        bt.remove(x);\n      }\n    } else {\n      cout << bt.minXor(x)\
    \ << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../boilerplate.hpp\"\n#include \"../../../numeric/binary_trie.hpp\"\n\n\
    int main() {\n  int q;\n  cin >> q;\n  BinaryTrie bt;\n  while (q--) {\n    int\
    \ t, x;\n    cin >> t >> x;\n    if (t == 0) {\n      if (bt.count(x) == 0) {\n\
    \        bt.insert(x);\n      }\n    } else if (t == 1) {\n      if (bt.count(x)\
    \ == 1) {\n        bt.remove(x);\n      }\n    } else {\n      cout << bt.minXor(x)\
    \ << '\\n';\n    }\n  }\n}"
  dependsOn:
  - utils/random.hpp
  - utils/timer.hpp
  - numeric/binary_trie.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2024-09-11 14:56:51-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp.html
title: verify/library_checker/data_structure/set_xor_min.test.cpp
---
