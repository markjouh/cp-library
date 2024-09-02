---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/w_ary_tree.hpp
    title: datastructures/w_ary_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"verify/library_checker/data_structure/double_ended_priority_queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#line 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing\
    \ namespace std;\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    #define pb push_back\n#define eb emplace_back\n#define fi first\n#define se second\n\
    \nusing ll = long long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n\
    #else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n\
    }\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a =\
    \ b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return\
    \ b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf\
    \ = numeric_limits<T>::max() / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"datastructures/w_ary_tree.hpp\"\n\ntemplate <int N>\nstruct\
    \ WAryTree {\n  uint32_t freq[N];\n  uint64_t l0[(N >> 6) + 1], l1[(N >> 12) +\
    \ 1], root;\n\n  WAryTree() {\n    memset(freq, 0, sizeof freq);\n    memset(l0,\
    \ 0, sizeof l0);\n    memset(l1, 0, sizeof l1);\n    root = 0;\n  }\n\n  void\
    \ insert(int x) {\n    freq[x]++;\n    if (freq[x] == 1) {\n      l0[x >> 6] |=\
    \ 1ull << (x & 63);\n      if (__builtin_popcountll(l0[x >> 6]) == 1) {\n    \
    \    l1[x >> 12] |= 1ull << ((x >> 6) & 63);\n        if (__builtin_popcountll(l1[x\
    \ >> 12]) == 1) {\n          root |= 1ull << ((x >> 12) & 63);\n        }\n  \
    \    }\n    }\n  }\n\n  void extract(int x) {\n    freq[x]--;\n    if (freq[x]\
    \ == 0) {\n      l0[x >> 6] ^= 1ull << (x & 63);\n      if (__builtin_popcountll(l0[x\
    \ >> 6]) == 0) {\n        l1[x >> 12] ^= 1ull << ((x >> 6) & 63);\n        if\
    \ (__builtin_popcountll(l1[x >> 12]) == 0) {\n          root ^= 1ull << ((x >>\
    \ 12) & 63);\n        }\n      }\n    }\n  }\n\n  int get_min() {\n    uint32_t\
    \ p = __builtin_ctzll(root);\n    p = (p << 6) + __builtin_ctzll(l1[p]);\n   \
    \ p = (p << 6) + __builtin_ctzll(l0[p]);\n    return p;\n  }\n\n  int get_max()\
    \ {\n    uint32_t p = 63 - __builtin_clzll(root);\n    p = (p << 6) + 63 - __builtin_clzll(l1[p]);\n\
    \    p = (p << 6) + 63 - __builtin_clzll(l0[p]);\n    return p;\n  }\n};\n#line\
    \ 5 \"verify/library_checker/data_structure/double_ended_priority_queue.test.cpp\"\
    \n\nconst int LO = numeric_limits<int>::min(), HI = numeric_limits<int>::max();\n\
    const int N = 1 << 18;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int>\
    \ queries, vals;\n  for (int i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n\
    \    queries.push_back(x);\n    vals.push_back(x);\n  }\n  for (int i = 0; i <\
    \ q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int x;\n    \
    \  cin >> x;\n      queries.push_back(x);\n      vals.push_back(x);\n    } else\
    \ if (t == 1) {\n      queries.push_back(LO);\n    } else {\n      queries.push_back(HI);\n\
    \    }\n  }\n  sort(all(vals));\n  vals.resize(unique(all(vals)) - begin(vals));\n\
    \n  array<int, 3> cnt{};\n  array<WAryTree<1 << 18>, 3> ds;\n  for (int x : queries)\
    \ {\n    if (x == LO) {\n      for (int i = 0; i < 3; i++) {\n        if (cnt[i]\
    \ > 0) {\n          int rem = ds[i].get_min();\n          cout << vals[i * N +\
    \ rem] << '\\n';\n          ds[i].extract(rem);\n          cnt[i]--;\n       \
    \   break;\n        }\n      }\n    } else if (x == HI) {\n      for (int i =\
    \ 2; i >= 0; i--) {\n        if (cnt[i] > 0) {\n          int rem = ds[i].get_max();\n\
    \          cout << vals[i * N + rem] << '\\n';\n          ds[i].extract(rem);\n\
    \          cnt[i]--;\n          break;\n        }\n      }\n    } else {\n   \
    \   int idx = lower_bound(all(vals), x) - begin(vals);\n      ds[idx / N].insert(idx\
    \ % N);\n      cnt[idx / N]++;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/w_ary_tree.hpp\"\
    \n\nconst int LO = numeric_limits<int>::min(), HI = numeric_limits<int>::max();\n\
    const int N = 1 << 18;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int>\
    \ queries, vals;\n  for (int i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n\
    \    queries.push_back(x);\n    vals.push_back(x);\n  }\n  for (int i = 0; i <\
    \ q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int x;\n    \
    \  cin >> x;\n      queries.push_back(x);\n      vals.push_back(x);\n    } else\
    \ if (t == 1) {\n      queries.push_back(LO);\n    } else {\n      queries.push_back(HI);\n\
    \    }\n  }\n  sort(all(vals));\n  vals.resize(unique(all(vals)) - begin(vals));\n\
    \n  array<int, 3> cnt{};\n  array<WAryTree<1 << 18>, 3> ds;\n  for (int x : queries)\
    \ {\n    if (x == LO) {\n      for (int i = 0; i < 3; i++) {\n        if (cnt[i]\
    \ > 0) {\n          int rem = ds[i].get_min();\n          cout << vals[i * N +\
    \ rem] << '\\n';\n          ds[i].extract(rem);\n          cnt[i]--;\n       \
    \   break;\n        }\n      }\n    } else if (x == HI) {\n      for (int i =\
    \ 2; i >= 0; i--) {\n        if (cnt[i] > 0) {\n          int rem = ds[i].get_max();\n\
    \          cout << vals[i * N + rem] << '\\n';\n          ds[i].extract(rem);\n\
    \          cnt[i]--;\n          break;\n        }\n      }\n    } else {\n   \
    \   int idx = lower_bound(all(vals), x) - begin(vals);\n      ds[idx / N].insert(idx\
    \ % N);\n      cnt[idx / N]++;\n    }\n  }\n}"
  dependsOn:
  - datastructures/w_ary_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-09-01 21:11:12-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
- /verify/verify/library_checker/data_structure/double_ended_priority_queue.test.cpp.html
title: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
---
