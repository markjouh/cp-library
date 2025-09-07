---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/segment_tree/segtree.h
    title: Segment Tree
  - icon: ':question:'
    path: src/template/template.h
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #line 1 \"src/template/template.h\"\n/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"src/datastructures/segment_tree/segtree.h\"\ntemplate <class\
    \ T, auto op, auto id>\nstruct Segtree {\n  int n;\n  vector<T> st;\n\n  Segtree(int\
    \ n_) : n(n_), st(2 * n, id()) {}\n\n  Segtree(const vector<T> &a) : n(sz(a)),\
    \ st(2 * n) {\n    copy(all(a), begin(st) + n);\n    for (int i = n - 1; i > 0;\
    \ i--) {\n      st[i] = op(st[i << 1], st[i << 1 | 1]);\n    }\n  }\n\n  void\
    \ set(int p, T val) {\n    for (st[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n\
    \      st[p] = op(st[p << 1], st[p << 1 | 1]);\n    }\n  }\n\n  T get(int p) {\n\
    \    return st[p + n];\n  }\n\n  T query(int l, int r) {\n    T ls = id(), rs\
    \ = id();\n    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n      if (l\
    \ & 1) {\n        ls = op(ls, st[l++]);\n      }\n      if (r & 1) {\n       \
    \ rs = op(st[--r], rs);\n      }\n    }\n    return op(ls, rs);\n  }\n};\n#line\
    \ 5 \"src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  \n\
    \  auto op = [](ll a, ll b) { return a + b; };\n  auto id = []() { return 0LL;\
    \ };\n  \n  Segtree<ll, op, id> seg(n);\n  \n  for (int i = 0; i < n; i++) {\n\
    \    ll a;\n    cin >> a;\n    seg.set(i, a);\n  }\n  \n  while (q--) {\n    int\
    \ t;\n    cin >> t;\n    if (t == 0) {\n      int p;\n      ll x;\n      cin >>\
    \ p >> x;\n      seg.set(p, seg.get(p) + x);\n    } else {\n      int l, r;\n\
    \      cin >> l >> r;\n      cout << seg.query(l, r - 1) << '\\n';\n    }\n  }\n\
    \  \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../../template/template.h\"\n#include \"../../../datastructures/segment_tree/segtree.h\"\
    \n\nusing ll = long long;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  \n\
    \  auto op = [](ll a, ll b) { return a + b; };\n  auto id = []() { return 0LL;\
    \ };\n  \n  Segtree<ll, op, id> seg(n);\n  \n  for (int i = 0; i < n; i++) {\n\
    \    ll a;\n    cin >> a;\n    seg.set(i, a);\n  }\n  \n  while (q--) {\n    int\
    \ t;\n    cin >> t;\n    if (t == 0) {\n      int p;\n      ll x;\n      cin >>\
    \ p >> x;\n      seg.set(p, seg.get(p) + x);\n    } else {\n      int l, r;\n\
    \      cin >> l >> r;\n      cout << seg.query(l, r - 1) << '\\n';\n    }\n  }\n\
    \  \n  return 0;\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/segment_tree/segtree.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 18:08:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp
- /verify/src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp.html
title: src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp
---
