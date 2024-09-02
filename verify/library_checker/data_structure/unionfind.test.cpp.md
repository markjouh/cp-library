---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/union_find.hpp
    title: datastructures/union_find.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"\
    verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <climits>\n#include <cmath>\n\
    #include <cstdint>\n#include <cstring>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\nusing namespace std;\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class\
    \ T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n#else\n  int\
    \ res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n}\n\n\
    template <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1\
    \ : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return b >\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"datastructures/union_find.hpp\"\n\nstruct UnionFind {\n\
    \  vector<int> a;\n\n  UnionFind(int n) : a(n, -1) {}\n\n  int size(int x) {\n\
    \    return -a[find(x)];\n  }\n\n  int find(int x) {\n    return a[x] < 0 ? x\
    \ : a[x] = find(a[x]);\n  }\n\n  bool join(int x, int y) {\n    x = find(x);\n\
    \    y = find(y);\n    if (x == y) {\n      return 0;\n    }\n    if (a[x] > a[y])\
    \ {\n      swap(x, y);\n    }\n    a[x] += a[y];\n    a[y] = x;\n    return 1;\n\
    \  }\n};\n#line 5 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  UnionFind uf(n);\n  while (q--)\
    \ {\n    bool t;\n    int x, y;\n    cin >> t >> x >> y;\n    if (t) {\n     \
    \ cout << (uf.find(x) == uf.find(y)) << '\\n';\n    } else {\n      uf.join(x,\
    \ y);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../boilerplate.hpp\"\n#include \"../../../datastructures/union_find.hpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  UnionFind uf(n);\n  while (q--)\
    \ {\n    bool t;\n    int x, y;\n    cin >> t >> x >> y;\n    if (t) {\n     \
    \ cout << (uf.find(x) == uf.find(y)) << '\\n';\n    } else {\n      uf.join(x,\
    \ y);\n    }\n  }\n}"
  dependsOn:
  - datastructures/union_find.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-09-01 21:11:12-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/unionfind.test.cpp
- /verify/verify/library_checker/data_structure/unionfind.test.cpp.html
title: verify/library_checker/data_structure/unionfind.test.cpp
---
