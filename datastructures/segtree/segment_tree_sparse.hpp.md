---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/custom/datastructure/segment_tree_sparse.test.cpp
    title: verify/custom/datastructure/segment_tree_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/segtree/segment_tree_sparse.hpp\"\n\ntemplate\
    \ <class T, T(*op)(T, T), T(*id)()>\nstruct SparseSegmentTree {\n  SparseSegmentTree()\
    \ {}\n  \n  SparseSegmentTree(int n) {\n    log = __lg(n - 1) + 1;\n    tree_sz\
    \ = 1 << log;\n    st.push_back(id());\n    ch.emplace_back(-1, -1);\n  }\n\n\
    \  void set(int p, T v) {\n    vis_buf[0] = idx = 0;\n    int tl = 0, tr = tree_sz;\n\
    \    while (tl + 1 != tr) {\n      int mid = (tl + tr) >> 1;\n      if (p < mid)\
    \ {\n        vis_buf[idx + 1] = get_l(vis_buf[idx]);\n        tr = mid;\n    \
    \  } else {\n        vis_buf[idx + 1] = get_r(vis_buf[idx]);\n        tl = mid;\n\
    \      }\n      idx++;\n    }\n    st[vis_buf[idx--]] = v;\n    while (idx >=\
    \ 0) {\n      pull(vis_buf[idx--]);\n    }\n  }\n\n  T query(int l, int r) {\n\
    \    return query(l, r + 1, 0, 0, tree_sz);\n  }\n\nprivate:\n  int log, tree_sz;\n\
    \  vector<T> st;\n  vector<pii> ch;\n\n  int vis_buf[32];\n  int idx;\n\n  int\
    \ get_l(int x) {\n    if (ch[x].fi == -1) {\n      ch[x].fi = sz(st);\n      st.pb(id());\n\
    \      ch.eb(-1, -1);\n    }\n    return ch[x].fi;\n  }\n\n  int get_r(int x)\
    \ {\n    if (ch[x].se == -1) {\n      ch[x].se = sz(st);\n      st.pb(id());\n\
    \      ch.eb(-1, -1);\n    }\n    return ch[x].se;\n  }\n\n  void pull(int x)\
    \ {\n    if (ch[x].fi == -1) {\n      st[x] = st[ch[x].se];\n    } else if (ch[x].se\
    \ != -1) {\n      st[x] = op(st[ch[x].fi], st[ch[x].se]);\n    } else {\n    \
    \  st[x] = st[ch[x].fi];\n    }\n  }\n\n  T query(int l, int r, int x, int tl,\
    \ int tr) {\n    if (x == -1 || tl >= r || tr <= l) {\n      return id();\n  \
    \  }\n    if (tl >= l && tr <= r) {\n      return st[x];\n    }\n    int mid =\
    \ (tl + tr) >> 1;\n    return op(query(l, r, ch[x].fi, tl, mid), query(l, r, ch[x].se,\
    \ mid, tr));\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T, T(*op)(T, T), T(*id)()>\nstruct SparseSegmentTree\
    \ {\n  SparseSegmentTree() {}\n  \n  SparseSegmentTree(int n) {\n    log = __lg(n\
    \ - 1) + 1;\n    tree_sz = 1 << log;\n    st.push_back(id());\n    ch.emplace_back(-1,\
    \ -1);\n  }\n\n  void set(int p, T v) {\n    vis_buf[0] = idx = 0;\n    int tl\
    \ = 0, tr = tree_sz;\n    while (tl + 1 != tr) {\n      int mid = (tl + tr) >>\
    \ 1;\n      if (p < mid) {\n        vis_buf[idx + 1] = get_l(vis_buf[idx]);\n\
    \        tr = mid;\n      } else {\n        vis_buf[idx + 1] = get_r(vis_buf[idx]);\n\
    \        tl = mid;\n      }\n      idx++;\n    }\n    st[vis_buf[idx--]] = v;\n\
    \    while (idx >= 0) {\n      pull(vis_buf[idx--]);\n    }\n  }\n\n  T query(int\
    \ l, int r) {\n    return query(l, r + 1, 0, 0, tree_sz);\n  }\n\nprivate:\n \
    \ int log, tree_sz;\n  vector<T> st;\n  vector<pii> ch;\n\n  int vis_buf[32];\n\
    \  int idx;\n\n  int get_l(int x) {\n    if (ch[x].fi == -1) {\n      ch[x].fi\
    \ = sz(st);\n      st.pb(id());\n      ch.eb(-1, -1);\n    }\n    return ch[x].fi;\n\
    \  }\n\n  int get_r(int x) {\n    if (ch[x].se == -1) {\n      ch[x].se = sz(st);\n\
    \      st.pb(id());\n      ch.eb(-1, -1);\n    }\n    return ch[x].se;\n  }\n\n\
    \  void pull(int x) {\n    if (ch[x].fi == -1) {\n      st[x] = st[ch[x].se];\n\
    \    } else if (ch[x].se != -1) {\n      st[x] = op(st[ch[x].fi], st[ch[x].se]);\n\
    \    } else {\n      st[x] = st[ch[x].fi];\n    }\n  }\n\n  T query(int l, int\
    \ r, int x, int tl, int tr) {\n    if (x == -1 || tl >= r || tr <= l) {\n    \
    \  return id();\n    }\n    if (tl >= l && tr <= r) {\n      return st[x];\n \
    \   }\n    int mid = (tl + tr) >> 1;\n    return op(query(l, r, ch[x].fi, tl,\
    \ mid), query(l, r, ch[x].se, mid, tr));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segtree/segment_tree_sparse.hpp
  requiredBy: []
  timestamp: '2024-09-05 17:05:59-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/custom/datastructure/segment_tree_sparse.test.cpp
documentation_of: datastructures/segtree/segment_tree_sparse.hpp
layout: document
redirect_from:
- /library/datastructures/segtree/segment_tree_sparse.hpp
- /library/datastructures/segtree/segment_tree_sparse.hpp.html
title: datastructures/segtree/segment_tree_sparse.hpp
---
