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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
  bundledCode: "#line 1 \"verify/aizu/alds1/priority_queue.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\n\n\
    #line 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n#include\
    \ <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing namespace\
    \ std;\n\n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i\
    \ = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...)\
    \ arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int\
    \ i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define\
    \ per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n#define eb emplace_back\n\
    #define fi first\n#define se second\n\nusing ll = long long;\nusing pii = pair<int,\
    \ int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n\
    \  return __lg(x);\n#else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n \
    \ }\n  return res;\n#endif\n}\n\ntemplate <class T>\nbool ckmin(T &a, const T\
    \ &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T =\
    \ int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\nstruct InitIO\
    \ {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"datastructures/w_ary_tree.hpp\"\
    \n\ntemplate <int N>\nstruct WAryTree {\n  uint32_t freq[N];\n  uint64_t l0[(N\
    \ >> 6) + 1], l1[(N >> 12) + 1], root;\n\n  WAryTree() {\n    memset(freq, 0,\
    \ sizeof freq);\n    memset(l0, 0, sizeof l0);\n    memset(l1, 0, sizeof l1);\n\
    \    root = 0;\n  }\n\n  void insert(int x) {\n    freq[x]++;\n    if (freq[x]\
    \ == 1) {\n      l0[x >> 6] |= 1ull << (x & 63);\n      if (__builtin_popcountll(l0[x\
    \ >> 6]) == 1) {\n        l1[x >> 12] |= 1ull << ((x >> 6) & 63);\n        if\
    \ (__builtin_popcountll(l1[x >> 12]) == 1) {\n          root |= 1ull << ((x >>\
    \ 12) & 63);\n        }\n      }\n    }\n  }\n\n  void extract(int x) {\n    freq[x]--;\n\
    \    if (freq[x] == 0) {\n      l0[x >> 6] ^= 1ull << (x & 63);\n      if (__builtin_popcountll(l0[x\
    \ >> 6]) == 0) {\n        l1[x >> 12] ^= 1ull << ((x >> 6) & 63);\n        if\
    \ (__builtin_popcountll(l1[x >> 12]) == 0) {\n          root ^= 1ull << ((x >>\
    \ 12) & 63);\n        }\n      }\n    }\n  }\n\n  int get_min() {\n    uint32_t\
    \ p = __builtin_ctzll(root);\n    p = (p << 6) + __builtin_ctzll(l1[p]);\n   \
    \ p = (p << 6) + __builtin_ctzll(l0[p]);\n    return p;\n  }\n\n  int get_max()\
    \ {\n    uint32_t p = 63 - __builtin_clzll(root);\n    p = (p << 6) + 63 - __builtin_clzll(l1[p]);\n\
    \    p = (p << 6) + 63 - __builtin_clzll(l0[p]);\n    return p;\n  }\n};\n#line\
    \ 5 \"verify/aizu/alds1/priority_queue.test.cpp\"\n\nint main() {\n  string s;\n\
    \  int x;\n  vector<int> queries;\n  vector<int> vals;\n  while (cin >> s) {\n\
    \    if (s == \"end\") {\n      break;\n    }\n    if (s == \"insert\") {\n  \
    \    cin >> x;\n      queries.push_back(x);\n      vals.push_back(x);\n    } else\
    \ {\n      queries.push_back(-1);\n    }\n  }\n  sort(all(vals));\n  vals.resize(unique(all(vals))\
    \ - begin(vals));\n  WAryTree<2000000> ds;\n  for (auto x : queries) {\n    if\
    \ (x == -1) {\n      int mx_idx = ds.get_max();\n      cout << vals[mx_idx] <<\
    \ '\\n';\n      ds.extract(mx_idx);\n    } else {\n      ds.insert(lower_bound(all(vals),\
    \ x) - begin(vals));\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/w_ary_tree.hpp\"\
    \n\nint main() {\n  string s;\n  int x;\n  vector<int> queries;\n  vector<int>\
    \ vals;\n  while (cin >> s) {\n    if (s == \"end\") {\n      break;\n    }\n\
    \    if (s == \"insert\") {\n      cin >> x;\n      queries.push_back(x);\n  \
    \    vals.push_back(x);\n    } else {\n      queries.push_back(-1);\n    }\n \
    \ }\n  sort(all(vals));\n  vals.resize(unique(all(vals)) - begin(vals));\n  WAryTree<2000000>\
    \ ds;\n  for (auto x : queries) {\n    if (x == -1) {\n      int mx_idx = ds.get_max();\n\
    \      cout << vals[mx_idx] << '\\n';\n      ds.extract(mx_idx);\n    } else {\n\
    \      ds.insert(lower_bound(all(vals), x) - begin(vals));\n    }\n  }\n}"
  dependsOn:
  - datastructures/w_ary_tree.hpp
  isVerificationFile: true
  path: verify/aizu/alds1/priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-09-03 12:19:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/priority_queue.test.cpp
- /verify/verify/aizu/alds1/priority_queue.test.cpp.html
title: verify/aizu/alds1/priority_queue.test.cpp
---
