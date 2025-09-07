---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/datastructures/segment_tree/persistent_segtree.h
    title: Persistent Segment Tree
  - icon: ':question:'
    path: src/template/template.h
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #line 1 \"src/template/template.h\"\n/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"src/datastructures/segment_tree/persistent_segtree.h\"\ntemplate\
    \ <class T, auto op, auto id>\nstruct PersistentSegtree {\n  int log, tree_sz,\
    \ updates;\n  vector<T> st;\n  vector<array<int, 2>> ch;\n\n  PersistentSegtree()\
    \ {}\n\n  PersistentSegtree(int n) {\n    log = __lg(n) + 1;\n    tree_sz = 1\
    \ << log;\n    st.resize(tree_sz << 1, id());\n    ch.resize(tree_sz << 1);\n\
    \    for (int i = tree_sz - 1; i > 0; i--) {\n      ch[i] = {i << 1, i << 1 |\
    \ 1};\n    }\n  }\n\n  int get_root(int t = -1) {\n    if (t == -1) {\n      t\
    \ = updates;\n    }\n    return t == 0 ? 1 : tree_sz + (t - 1) * (log - 1) + 1;\n\
    \  }\n\n  void update(int p, T val) {\n    int x = get_root(), tl = 0, tr = tree_sz;\n\
    \    for (int i = 0; i < log - 1; i++) {\n      st.push_back(id());\n      int\
    \ mid = (tl + tr) >> 1;\n      if (p < mid) {\n        ch.push_back({sz(st), ch[x][1]});\n\
    \        x = ch[x][0];\n        tr = mid;\n      } else {\n        ch.push_back({ch[x][0],\
    \ sz(st)});\n        x = ch[x][1];\n        tl = mid;\n      }\n    }\n    st.push_back(val);\n\
    \    for (int i = sz(st) - 2; i >= sz(st) - log; i--) {\n      st[i] = op(st[ch[i][0]],\
    \ st[ch[i][1]]);\n    }\n    updates++;\n  }\n\n  T query(int l, int r, int x,\
    \ int tl, int tr) {\n    if (tl >= r || tr <= l) {\n      return id();\n    }\n\
    \    if (tl >= l && tr <= r) {\n      return st[x];\n    }\n    int mid = (tl\
    \ + tr) >> 1;\n    return op(query(l, r, ch[x][0], tl, mid), query(l, r, ch[x][1],\
    \ mid, tr));\n  }\n\n  T query(int l, int r, int t = -1) {\n    return query(l,\
    \ r + 1, get_root(t), 0, tree_sz);\n  }\n};\n#line 5 \"src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp\"\
    \n\nusing ll = long long;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  \n\
    \  auto op = [](ll a, ll b) { return a + b; };\n  auto id = []() { return 0LL;\
    \ };\n  \n  PersistentSegtree<ll, op, id> seg(n);\n  \n  for (int i = 0; i < n;\
    \ i++) {\n    ll a;\n    cin >> a;\n    seg.update(i, a);\n  }\n  \n  while (q--)\
    \ {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int p;\n      ll x;\n\
    \      cin >> p >> x;\n      ll cur = seg.query(p, p);\n      seg.update(p, cur\
    \ + x);\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.query(l,\
    \ r - 1) << '\\n';\n    }\n  }\n  \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../../template/template.h\"\n#include \"../../../datastructures/segment_tree/persistent_segtree.h\"\
    \n\nusing ll = long long;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  \n\
    \  auto op = [](ll a, ll b) { return a + b; };\n  auto id = []() { return 0LL;\
    \ };\n  \n  PersistentSegtree<ll, op, id> seg(n);\n  \n  for (int i = 0; i < n;\
    \ i++) {\n    ll a;\n    cin >> a;\n    seg.update(i, a);\n  }\n  \n  while (q--)\
    \ {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int p;\n      ll x;\n\
    \      cin >> p >> x;\n      ll cur = seg.query(p, p);\n      seg.update(p, cur\
    \ + x);\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.query(l,\
    \ r - 1) << '\\n';\n    }\n  }\n  \n  return 0;\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/segment_tree/persistent_segtree.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 18:13:39-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
- /verify/src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp.html
title: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
---
