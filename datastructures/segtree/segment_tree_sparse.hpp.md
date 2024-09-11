---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/custom/datastructure/segment_tree_sparse.test.cpp
    title: verify/custom/datastructure/segment_tree_sparse.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/segtree/segment_tree_sparse.hpp\"\n\ntemplate\
    \ <class T, T(*op)(T, T), T(*id)()>\nstruct SparseSegmentTree {\n  SparseSegmentTree()\
    \ {}\n  \n  SparseSegmentTree(int n) {\n    log = __lg(n - 1) + 1;\n    treeSize\
    \ = 1 << log;\n    st.push_back(id());\n    ch.emplace_back(-1, -1);\n  }\n\n\
    \  void set(int p, T v) {\n    buf[0] = idx = 0;\n    int tl = 0, tr = treeSize;\n\
    \    while (tl + 1 != tr) {\n      int mid = (tl + tr) >> 1;\n      if (p < mid)\
    \ {\n        buf[idx + 1] = getL(buf[idx]);\n        tr = mid;\n      } else {\n\
    \        buf[idx + 1] = getR(buf[idx]);\n        tl = mid;\n      }\n      idx++;\n\
    \    }\n    st[buf[idx--]] = v;\n    while (idx >= 0) {\n      pull(buf[idx--]);\n\
    \    }\n  }\n\n  T query(int l, int r) {\n    return query(l, r + 1, 0, 0, treeSize);\n\
    \  }\n\nprivate:\n  int log, treeSize;\n  vector<T> st;\n  vector<pair<int, int>>\
    \ ch;\n\n  int buf[32];\n  int idx;\n\n  int getL(int x) {\n    if (ch[x].fi ==\
    \ -1) {\n      ch[x].fi = sz(st);\n      st.push_back(id());\n      ch.emplace_back(-1,\
    \ -1);\n    }\n    return ch[x].fi;\n  }\n\n  int getR(int x) {\n    if (ch[x].se\
    \ == -1) {\n      ch[x].se = sz(st);\n      st.push_back(id());\n      ch.emplace_back(-1,\
    \ -1);\n    }\n    return ch[x].se;\n  }\n\n  void pull(int x) {\n    if (ch[x].fi\
    \ == -1) {\n      st[x] = st[ch[x].se];\n    } else if (ch[x].se != -1) {\n  \
    \    st[x] = op(st[ch[x].fi], st[ch[x].se]);\n    } else {\n      st[x] = st[ch[x].fi];\n\
    \    }\n  }\n\n  T query(int l, int r, int x, int tl, int tr) {\n    if (x ==\
    \ -1 || tl >= r || tr <= l) {\n      return id();\n    }\n    if (tl >= l && tr\
    \ <= r) {\n      return st[x];\n    }\n    int mid = (tl + tr) >> 1;\n    return\
    \ op(query(l, r, ch[x].fi, tl, mid), query(l, r, ch[x].se, mid, tr));\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T, T(*op)(T, T), T(*id)()>\nstruct SparseSegmentTree\
    \ {\n  SparseSegmentTree() {}\n  \n  SparseSegmentTree(int n) {\n    log = __lg(n\
    \ - 1) + 1;\n    treeSize = 1 << log;\n    st.push_back(id());\n    ch.emplace_back(-1,\
    \ -1);\n  }\n\n  void set(int p, T v) {\n    buf[0] = idx = 0;\n    int tl = 0,\
    \ tr = treeSize;\n    while (tl + 1 != tr) {\n      int mid = (tl + tr) >> 1;\n\
    \      if (p < mid) {\n        buf[idx + 1] = getL(buf[idx]);\n        tr = mid;\n\
    \      } else {\n        buf[idx + 1] = getR(buf[idx]);\n        tl = mid;\n \
    \     }\n      idx++;\n    }\n    st[buf[idx--]] = v;\n    while (idx >= 0) {\n\
    \      pull(buf[idx--]);\n    }\n  }\n\n  T query(int l, int r) {\n    return\
    \ query(l, r + 1, 0, 0, treeSize);\n  }\n\nprivate:\n  int log, treeSize;\n  vector<T>\
    \ st;\n  vector<pair<int, int>> ch;\n\n  int buf[32];\n  int idx;\n\n  int getL(int\
    \ x) {\n    if (ch[x].fi == -1) {\n      ch[x].fi = sz(st);\n      st.push_back(id());\n\
    \      ch.emplace_back(-1, -1);\n    }\n    return ch[x].fi;\n  }\n\n  int getR(int\
    \ x) {\n    if (ch[x].se == -1) {\n      ch[x].se = sz(st);\n      st.push_back(id());\n\
    \      ch.emplace_back(-1, -1);\n    }\n    return ch[x].se;\n  }\n\n  void pull(int\
    \ x) {\n    if (ch[x].fi == -1) {\n      st[x] = st[ch[x].se];\n    } else if\
    \ (ch[x].se != -1) {\n      st[x] = op(st[ch[x].fi], st[ch[x].se]);\n    } else\
    \ {\n      st[x] = st[ch[x].fi];\n    }\n  }\n\n  T query(int l, int r, int x,\
    \ int tl, int tr) {\n    if (x == -1 || tl >= r || tr <= l) {\n      return id();\n\
    \    }\n    if (tl >= l && tr <= r) {\n      return st[x];\n    }\n    int mid\
    \ = (tl + tr) >> 1;\n    return op(query(l, r, ch[x].fi, tl, mid), query(l, r,\
    \ ch[x].se, mid, tr));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segtree/segment_tree_sparse.hpp
  requiredBy: []
  timestamp: '2024-09-11 14:41:57-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/custom/datastructure/segment_tree_sparse.test.cpp
documentation_of: datastructures/segtree/segment_tree_sparse.hpp
layout: document
redirect_from:
- /library/datastructures/segtree/segment_tree_sparse.hpp
- /library/datastructures/segtree/segment_tree_sparse.hpp.html
title: datastructures/segtree/segment_tree_sparse.hpp
---
