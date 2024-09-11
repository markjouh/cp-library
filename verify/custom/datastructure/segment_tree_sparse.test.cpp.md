---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/segtree/segment_tree_sparse.hpp
    title: datastructures/segtree/segment_tree_sparse.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/datastructure/segment_tree_sparse.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"verify/boilerplate.hpp\"\
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
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"datastructures/segtree/segment_tree_sparse.hpp\"\
    \n\ntemplate <class T, T(*op)(T, T), T(*id)()>\nstruct SparseSegmentTree {\n \
    \ SparseSegmentTree() {}\n  \n  SparseSegmentTree(int n) {\n    log = __lg(n -\
    \ 1) + 1;\n    treeSize = 1 << log;\n    st.push_back(id());\n    ch.emplace_back(-1,\
    \ -1);\n  }\n\n  void set(int p, T v) {\n    buf[0] = idx = 0;\n    int tl = 0,\
    \ tr = treeSize;\n    while (tl + 1 != tr) {\n      int mid = (tl + tr) >> 1;\n\
    \      if (p < mid) {\n        buf[idx + 1] = getL(buf[idx]);\n        tr = mid;\n\
    \      } else {\n        buf[idx + 1] = getR(buf[idx]);\n        tl = mid;\n \
    \     }\n      idx++;\n    }\n    st[buf[idx--]] = v;\n    while (idx >= 0) {\n\
    \      pull(buf[idx--]);\n    }\n  }\n\n  T query(int l, int r) {\n    return\
    \ query(l, r + 1, 0, 0, treeSize);\n  }\n\nprivate:\n  int log, treeSize;\n  vector<T>\
    \ st;\n  vector<pair<int, int>> ch;\n\n  int buf[32];\n  int idx;\n\n  int getL(int\
    \ x) {\n    if (ch[x].first == -1) {\n      ch[x].first = sz(st);\n      st.push_back(id());\n\
    \      ch.emplace_back(-1, -1);\n    }\n    return ch[x].first;\n  }\n\n  int\
    \ getR(int x) {\n    if (ch[x].second == -1) {\n      ch[x].second = sz(st);\n\
    \      st.push_back(id());\n      ch.emplace_back(-1, -1);\n    }\n    return\
    \ ch[x].second;\n  }\n\n  void pull(int x) {\n    if (ch[x].first == -1) {\n \
    \     st[x] = st[ch[x].second];\n    } else if (ch[x].second != -1) {\n      st[x]\
    \ = op(st[ch[x].first], st[ch[x].second]);\n    } else {\n      st[x] = st[ch[x].first];\n\
    \    }\n  }\n\n  T query(int l, int r, int x, int tl, int tr) {\n    if (x ==\
    \ -1 || tl >= r || tr <= l) {\n      return id();\n    }\n    if (tl >= l && tr\
    \ <= r) {\n      return st[x];\n    }\n    int mid = (tl + tr) >> 1;\n    return\
    \ op(query(l, r, ch[x].first, tl, mid), query(l, r, ch[x].second, mid, tr));\n\
    \  }\n};\n#line 5 \"verify/custom/datastructure/segment_tree_sparse.test.cpp\"\
    \n\nconst int N = 1e9, Q = 5e4;\n\ni64 op(i64 x, i64 y) {\n  return x + y;\n}\n\
    \ni64 id() {\n  return 0;\n}\n\nint main() {\n  vector<pair<int, int>> a;\n  SparseSegmentTree<i64,\
    \ op, id> st(N);\n\n  for (int i = 0; i < Q; i++) {\n    if (randBool()) {\n \
    \     const int p = randInt(N), v = randInt(1e9);\n      bool flag = false;\n\
    \      for (auto &b : a) {\n        if (b.first == p) {\n          flag = true;\n\
    \          b.second = v;\n          break;\n        }\n      }\n      if (!flag)\
    \ {\n        a.emplace_back(p, v);\n      }\n      st.set(p, v);\n    } else {\n\
    \      int l = randInt(N), r = randInt(N);\n      if (l > r) {\n        swap(l,\
    \ r);\n      }\n      i64 sum = 0;\n      for (auto [p, v] : a) {\n        if\
    \ (p >= l && p <= r) {\n          sum += v;\n        }\n      }\n      assert(st.query(l,\
    \ r) == sum);\n    }\n  }\n\n  cerr << \"Tests passed\\n\";\n\n  int a_, b_;\n\
    \  cin >> a_ >> b_;\n  cout << a_ + b_ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../boilerplate.hpp\"\n#include \"../../../datastructures/segtree/segment_tree_sparse.hpp\"\
    \n\nconst int N = 1e9, Q = 5e4;\n\ni64 op(i64 x, i64 y) {\n  return x + y;\n}\n\
    \ni64 id() {\n  return 0;\n}\n\nint main() {\n  vector<pair<int, int>> a;\n  SparseSegmentTree<i64,\
    \ op, id> st(N);\n\n  for (int i = 0; i < Q; i++) {\n    if (randBool()) {\n \
    \     const int p = randInt(N), v = randInt(1e9);\n      bool flag = false;\n\
    \      for (auto &b : a) {\n        if (b.first == p) {\n          flag = true;\n\
    \          b.second = v;\n          break;\n        }\n      }\n      if (!flag)\
    \ {\n        a.emplace_back(p, v);\n      }\n      st.set(p, v);\n    } else {\n\
    \      int l = randInt(N), r = randInt(N);\n      if (l > r) {\n        swap(l,\
    \ r);\n      }\n      i64 sum = 0;\n      for (auto [p, v] : a) {\n        if\
    \ (p >= l && p <= r) {\n          sum += v;\n        }\n      }\n      assert(st.query(l,\
    \ r) == sum);\n    }\n  }\n\n  cerr << \"Tests passed\\n\";\n\n  int a_, b_;\n\
    \  cin >> a_ >> b_;\n  cout << a_ + b_ << '\\n';\n}"
  dependsOn:
  - utils/random.hpp
  - utils/timer.hpp
  - datastructures/segtree/segment_tree_sparse.hpp
  isVerificationFile: true
  path: verify/custom/datastructure/segment_tree_sparse.test.cpp
  requiredBy: []
  timestamp: '2024-09-11 15:33:10-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/datastructure/segment_tree_sparse.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/datastructure/segment_tree_sparse.test.cpp
- /verify/verify/custom/datastructure/segment_tree_sparse.test.cpp.html
title: verify/custom/datastructure/segment_tree_sparse.test.cpp
---
