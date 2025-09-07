---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/segment_tree/sparse_segtree.h
    title: Sparse Segment Tree
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#line\
    \ 1 \"src/template/template.h\"\n/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"src/datastructures/segment_tree/sparse_segtree.h\"\ntemplate\
    \ <class T, auto op, auto id>\nstruct SparseSegtree {\n  SparseSegtree() {}\n\n\
    \  SparseSegtree(int n) {\n    log = __lg(n) + 1;\n    tree_sz = 1 << log;\n \
    \   st.push_back(id());\n    ch.emplace_back(-1, -1);\n  }\n\n  void set(int p,\
    \ T v) {\n    buf[0] = idx = 0;\n    int tl = 0, tr = tree_sz;\n    while (tl\
    \ + 1 != tr) {\n      int mid = (tl + tr) >> 1;\n      if (p < mid) {\n      \
    \  buf[idx + 1] = get_l(buf[idx]);\n        tr = mid;\n      } else {\n      \
    \  buf[idx + 1] = get_r(buf[idx]);\n        tl = mid;\n      }\n      idx++;\n\
    \    }\n    st[buf[idx--]] = v;\n    while (idx >= 0) {\n      pull(buf[idx--]);\n\
    \    }\n  }\n\n  T query(int l, int r) {\n    return get(l, r + 1, 0, 0, tree_sz);\n\
    \  }\n\nprivate:\n  int log, tree_sz;\n  vector<T> st;\n  vector<pair<int, int>>\
    \ ch;\n\n  int buf[32];\n  int idx;\n\n  int get_l(int x) {\n    if (ch[x].first\
    \ == -1) {\n      ch[x].first = sz(st);\n      st.push_back(id());\n      ch.emplace_back(-1,\
    \ -1);\n    }\n    return ch[x].first;\n  }\n\n  int get_r(int x) {\n    if (ch[x].second\
    \ == -1) {\n      ch[x].second = sz(st);\n      st.push_back(id());\n      ch.emplace_back(-1,\
    \ -1);\n    }\n    return ch[x].second;\n  }\n\n  void pull(int x) {\n    if (ch[x].first\
    \ == -1) {\n      st[x] = st[ch[x].second];\n    } else if (ch[x].second != -1)\
    \ {\n      st[x] = op(st[ch[x].first], st[ch[x].second]);\n    } else {\n    \
    \  st[x] = st[ch[x].first];\n    }\n  }\n\n  T get(int l, int r, int x, int tl,\
    \ int tr) {\n    if (x == -1 || tl >= r || tr <= l) {\n      return id();\n  \
    \  }\n    if (tl >= l && tr <= r) {\n      return st[x];\n    }\n    int mid =\
    \ (tl + tr) >> 1;\n    return op(get(l, r, ch[x].first, tl, mid), get(l, r, ch[x].second,\
    \ mid, tr));\n  }\n};\n#line 5 \"src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  \n\
    \  auto op = [](ll a, ll b) { return a + b; };\n  auto id = []() { return 0LL;\
    \ };\n  \n  SparseSegtree<ll, op, id> seg(n);\n  \n  for (int i = 0; i < n; i++)\
    \ {\n    ll a;\n    cin >> a;\n    seg.set(i, a);\n  }\n  \n  while (q--) {\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << seg.query(l, r - 1) << '\\n';\n\
    \  }\n  \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include \"../../../template/template.h\"\n#include \"../../../datastructures/segment_tree/sparse_segtree.h\"\
    \n\nusing ll = long long;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  \n\
    \  auto op = [](ll a, ll b) { return a + b; };\n  auto id = []() { return 0LL;\
    \ };\n  \n  SparseSegtree<ll, op, id> seg(n);\n  \n  for (int i = 0; i < n; i++)\
    \ {\n    ll a;\n    cin >> a;\n    seg.set(i, a);\n  }\n  \n  while (q--) {\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << seg.query(l, r - 1) << '\\n';\n\
    \  }\n  \n  return 0;\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/segment_tree/sparse_segtree.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 18:08:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp
- /verify/src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp.html
title: src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp
---
