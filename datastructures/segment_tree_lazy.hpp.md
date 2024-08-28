---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/segment_tree_lazy.hpp\"\n\nstruct LazySegmentTree\
    \ {\n  using item_t = pair<int, int>;\n  using upd_t = int;\n\n  // Identity element,\
    \ null update tag\n  const item_t id = {INF, 1};\n  const upd_t lz_id = 0;\n\n\
    \  // Associative merge operation\n  item_t merge(item_t a, item_t b) {\n    if\
    \ (a.first == b.first) {\n      return {a.first, a.second + b.second};\n    }\
    \ else {\n      return a.first < b.first ? a : b;\n    }\n  }\n\n  // Apply a\
    \ lazy tag to a full segment\n  void apply(int x, upd_t v) {\n    lz[x] += v;\n\
    \  }\n\n  // Consume and propagate a lazy tag\n  void push(int x, int tl, int\
    \ tr) {\n    if (lz[x] != lz_id) {\n      st[x].first += lz[x];\n      if (tl\
    \ + 1 != tr) {\n        lz[2 * x + 1] += lz[x];\n        lz[2 * x + 2] += lz[x];\n\
    \      }\n      lz[x] = lz_id;\n    }\n  }\n\n  LazySegmentTree(int n_) {\n  \
    \  init(n_);\n  }\n\n  LazySegmentTree(const vector<item_t> &a) {\n    init(sz(a));\n\
    \    build(a, 0, 0, n);\n  }\n\n  item_t query() {\n    return st[0];\n  }\n\n\
    \  item_t query(int l, int r) {\n    return query(l, r + 1, 0, 0, n);\n  }\n\n\
    \  void update(int l, int r, upd_t v) {\n    update(l, r + 1, v, 0, 0, n);\n \
    \ }\n\nprivate:\n  int n;\n  vector<item_t> st;\n  vector<upd_t> lz;\n\n  void\
    \ init(int sz) {\n    n = 1;\n    while (n < sz) {\n      n *= 2;\n    }\n   \
    \ st.resize(2 * n, id);\n    lz.resize(2 * n, lz_id);\n  }\n\n  void build(const\
    \ vector<item_t> &a, int x, int tl, int tr) {\n    if (tl + 1 == tr) {\n     \
    \ if (tl < sz(a)) {\n        st[x] = a[tl];\n      }\n      return;\n    }\n \
    \   int mid = (tl + tr) / 2;\n    build(a, 2 * x + 1, tl, mid);\n    build(a,\
    \ 2 * x + 2, mid, tr);\n    st[x] = merge(st[2 * x + 1], st[2 * x + 2]);\n  }\n\
    \n  item_t query(int l, int r, int x, int tl, int tr) {\n    push(x, tl, tr);\n\
    \    if (tl >= r || tr <= l) {\n      return id;\n    }\n    if (tl >= l && tr\
    \ <= r) {\n      return st[x];\n    }\n    int mid = (tl + tr) / 2;\n    return\
    \ merge(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));\n \
    \ }\n\n  void update(int l, int r, int v, int x, int tl, int tr) {\n    push(x,\
    \ tl, tr);\n    if (tl >= r || tr <= l) {\n      return;\n    }\n    if (tl >=\
    \ l && tr <= r) {\n      apply(x, v);\n      push(x, tl, tr);\n      return;\n\
    \    }\n    int mid = (tl + tr) / 2;\n    update(l, r, v, 2 * x + 1, tl, mid);\n\
    \    update(l, r, v, 2 * x + 2, mid, tr);\n    st[x] = merge(st[2 * x + 1], st[2\
    \ * x + 2]);\n  }\n};\n"
  code: "#pragma once\n\nstruct LazySegmentTree {\n  using item_t = pair<int, int>;\n\
    \  using upd_t = int;\n\n  // Identity element, null update tag\n  const item_t\
    \ id = {INF, 1};\n  const upd_t lz_id = 0;\n\n  // Associative merge operation\n\
    \  item_t merge(item_t a, item_t b) {\n    if (a.first == b.first) {\n      return\
    \ {a.first, a.second + b.second};\n    } else {\n      return a.first < b.first\
    \ ? a : b;\n    }\n  }\n\n  // Apply a lazy tag to a full segment\n  void apply(int\
    \ x, upd_t v) {\n    lz[x] += v;\n  }\n\n  // Consume and propagate a lazy tag\n\
    \  void push(int x, int tl, int tr) {\n    if (lz[x] != lz_id) {\n      st[x].first\
    \ += lz[x];\n      if (tl + 1 != tr) {\n        lz[2 * x + 1] += lz[x];\n    \
    \    lz[2 * x + 2] += lz[x];\n      }\n      lz[x] = lz_id;\n    }\n  }\n\n  LazySegmentTree(int\
    \ n_) {\n    init(n_);\n  }\n\n  LazySegmentTree(const vector<item_t> &a) {\n\
    \    init(sz(a));\n    build(a, 0, 0, n);\n  }\n\n  item_t query() {\n    return\
    \ st[0];\n  }\n\n  item_t query(int l, int r) {\n    return query(l, r + 1, 0,\
    \ 0, n);\n  }\n\n  void update(int l, int r, upd_t v) {\n    update(l, r + 1,\
    \ v, 0, 0, n);\n  }\n\nprivate:\n  int n;\n  vector<item_t> st;\n  vector<upd_t>\
    \ lz;\n\n  void init(int sz) {\n    n = 1;\n    while (n < sz) {\n      n *= 2;\n\
    \    }\n    st.resize(2 * n, id);\n    lz.resize(2 * n, lz_id);\n  }\n\n  void\
    \ build(const vector<item_t> &a, int x, int tl, int tr) {\n    if (tl + 1 == tr)\
    \ {\n      if (tl < sz(a)) {\n        st[x] = a[tl];\n      }\n      return;\n\
    \    }\n    int mid = (tl + tr) / 2;\n    build(a, 2 * x + 1, tl, mid);\n    build(a,\
    \ 2 * x + 2, mid, tr);\n    st[x] = merge(st[2 * x + 1], st[2 * x + 2]);\n  }\n\
    \n  item_t query(int l, int r, int x, int tl, int tr) {\n    push(x, tl, tr);\n\
    \    if (tl >= r || tr <= l) {\n      return id;\n    }\n    if (tl >= l && tr\
    \ <= r) {\n      return st[x];\n    }\n    int mid = (tl + tr) / 2;\n    return\
    \ merge(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));\n \
    \ }\n\n  void update(int l, int r, int v, int x, int tl, int tr) {\n    push(x,\
    \ tl, tr);\n    if (tl >= r || tr <= l) {\n      return;\n    }\n    if (tl >=\
    \ l && tr <= r) {\n      apply(x, v);\n      push(x, tl, tr);\n      return;\n\
    \    }\n    int mid = (tl + tr) / 2;\n    update(l, r, v, 2 * x + 1, tl, mid);\n\
    \    update(l, r, v, 2 * x + 2, mid, tr);\n    st[x] = merge(st[2 * x + 1], st[2\
    \ * x + 2]);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segment_tree_lazy.hpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segment_tree_lazy.hpp
layout: document
redirect_from:
- /library/datastructures/segment_tree_lazy.hpp
- /library/datastructures/segment_tree_lazy.hpp.html
title: datastructures/segment_tree_lazy.hpp
---
