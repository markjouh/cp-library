---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/segtree/segment_tree.hpp
    title: datastructures/segtree/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"verify/aizu/dsl/rmq.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#line 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing\
    \ namespace std;\n\n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r)\
    \ for (int i = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define\
    \ rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l,\
    \ r) for (int i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0,\
    \ n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\ntemplate <class\
    \ T>\nusing vec = vector<T>;\n\nusing ll = long long;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n\ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n\
    \  return __lg(x);\n#else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n \
    \ }\n  return res;\n#endif\n}\n\ntemplate <class T>\nbool ckmin(T &a, const T\
    \ &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T =\
    \ int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\nstruct InitIO\
    \ {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"datastructures/segtree/segment_tree.hpp\"\
    \n\ntemplate <class T, T(*op)(T, T), T(*id)()>\nstruct SegmentTree {\n  int n;\n\
    \  vector<T> st;\n\n  SegmentTree(int sz) : n(sz), st(2 * n, id()) {}\n\n  SegmentTree(const\
    \ vector<T> &a) : n(sz(a)), st(2 * n) {\n    copy(begin(a), end(a), begin(st)\
    \ + n);\n    for (int i = n - 1; i > 0; i--) {\n      st[i] = op(st[i << 1], st[i\
    \ << 1 | 1]);\n    }\n  }\n\n  T get(int p) {\n    return st[p + n];\n  }\n\n\
    \  T query(int l, int r) {\n    T ls = id(), rs = id();\n    for (l += n, r +=\
    \ n + 1; l < r; l >>= 1, r >>= 1) {\n      if (l & 1) {\n        ls = op(ls, st[l++]);\n\
    \      }\n      if (r & 1) {\n        rs = op(st[--r], rs);\n      }\n    }\n\
    \    return op(ls, rs);\n  }\n\n  void set(int p, T val) {\n    for (st[p += n]\
    \ = val, p >>= 1; p > 0; p >>= 1) {\n      st[p] = op(st[p << 1], st[p << 1 |\
    \ 1]);\n    }\n  }\n};\n#line 5 \"verify/aizu/dsl/rmq.test.cpp\"\n\nint op(int\
    \ x, int y) {\n  return x < y ? x : y;\n}\n\nint id() {\n  return numeric_limits<int>::max();\n\
    }\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  SegmentTree<int, op, id> st(n);\n\
    \  while (q--) {\n    bool t;\n    int x, y;\n    cin >> t >> x >> y;\n    if\
    \ (t) {\n      cout << st.query(x, y) << '\\n';\n    } else {\n      st.set(x,\
    \ y);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/segtree/segment_tree.hpp\"\
    \n\nint op(int x, int y) {\n  return x < y ? x : y;\n}\n\nint id() {\n  return\
    \ numeric_limits<int>::max();\n}\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n\
    \  SegmentTree<int, op, id> st(n);\n  while (q--) {\n    bool t;\n    int x, y;\n\
    \    cin >> t >> x >> y;\n    if (t) {\n      cout << st.query(x, y) << '\\n';\n\
    \    } else {\n      st.set(x, y);\n    }\n  }\n}"
  dependsOn:
  - datastructures/segtree/segment_tree.hpp
  isVerificationFile: true
  path: verify/aizu/dsl/rmq.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 17:54:50-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/dsl/rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/dsl/rmq.test.cpp
- /verify/verify/aizu/dsl/rmq.test.cpp.html
title: verify/aizu/dsl/rmq.test.cpp
---
