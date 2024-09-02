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
  bundledCode: "#line 2 \"datastructures/segtree/segment_tree_lazy.hpp\"\n\ntemplate\
    \ <class T, auto op, auto t_id, class U, auto mapping, auto comp, auto u_id>\n\
    struct LazySegmentTree {\n  LazySegmentTree(int x) {\n    init(x);\n    pull_all();\n\
    \  }\n\n  LazySegmentTree(const vector<T> &a) {\n    init(sz(a));\n    copy(all(a),\
    \ begin(st) + size);\n    pull_all();\n  }\n\n  void set(int p, T v) {\n    push_path(p\
    \ += size);\n    st[p] = v;\n    pull_path(p);\n  }\n\n  void update(int p, U\
    \ v) {\n    push_path(p += size);\n    st[p] = mapping(st[p], v);\n    pull_path(p);\n\
    \  }\n\n  void update(int l, int r, U v) {\n    update(l, r + 1, v, 1, 0, size);\n\
    \  }\n\n  T get_all() {\n    return st[1];\n  }\n\n  T get(int p) {\n    push_path(p\
    \ += size);\n    return st[p];\n  }\n\n  T query(int l, int r) {\n    return query(l,\
    \ r + 1, 1, 0, size);\n  }\n\n  template <class F>\n  int find_first(F f) {\n\
    \    T pref = t_id();\n    int x = 1;\n    while (x < size) {\n      push(x);\n\
    \      if (f(op(pref, st[x << 1]))) {\n        x = x << 1;\n      } else {\n \
    \       pref = op(pref, st[x << 1]);\n        x = x << 1 | 1;\n      }\n    }\n\
    \    return f(op(pref, st[x])) ? x - size : n;\n  }\n\n  template <class F>\n\
    \  int find_last(F f) {\n    T suff = t_id();\n    int x = 1;\n    while (x <\
    \ size) {\n      push(x);\n      if (f(st[x << 1 | 1], suff)) {\n        x = x\
    \ << 1 | 1;\n      } else {\n        suff = op(st[x << 1 | 1], suff);\n      \
    \  x = x << 1;\n      }\n    }\n    return f(op(st[x], suff)) ? x - size : -1;\n\
    \  }\n  \nprivate:\n  int n, log, size;\n  vector<T> st;\n  vector<U> lz;\n\n\
    \  void init(int x) {\n    n = x;\n    log = lg(n - 1) + 1;\n    size = 1 << log;\n\
    \    st.resize(size << 1, t_id());\n    lz.resize(size, u_id());\n  }\n\n  void\
    \ pull(int x) {\n    st[x] = op(st[x << 1], st[x << 1 | 1]);\n  }\n\n  void pull_path(int\
    \ x) {\n    for (int i = 1; i <= log; i++) {\n      pull(x >> i);\n    }\n  }\n\
    \n  void pull_all() {\n    for (int i = size - 1; i > 0; i--) {\n      pull(i);\n\
    \    }\n  }\n\n  void apply(int x) {\n    st[x] = mapping(st[x], lz[x >> 1]);\n\
    \    if (x < size) {\n      lz[x] = comp(lz[x], lz[x >> 1]);\n    }\n  }\n\n \
    \ void push(int x) {\n    apply(x << 1);\n    apply(x << 1 | 1);\n    lz[x] =\
    \ u_id();\n  }\n\n  void push_path(int x) {\n    for (int i = log; i > 0; i--)\
    \ {\n      push(x >> i);\n    }\n  }\n\n  void update(int l, int r, U v, int x,\
    \ int tl, int tr) {\n    if (tl >= r || tr <= l) {\n      return;\n    }\n   \
    \ if (tl >= l && tr <= r) {\n      st[x] = mapping(st[x], v);\n      if (x < size)\
    \ {\n        lz[x] = comp(lz[x], v);\n      }\n      return;\n    }\n    push(x);\n\
    \    int mid = (tl + tr) >> 1;\n    update(l, r, v, x << 1, tl, mid);\n    update(l,\
    \ r, v, x << 1 | 1, mid, tr);\n    pull(x);\n  }\n\n  T query(int l, int r, int\
    \ x, int tl, int tr) {\n    if (tl >= r || tr <= l) {\n      return t_id();\n\
    \    }\n    if (tl >= l && tr <= r) {\n      return st[x];\n    }\n    push(x);\n\
    \    int mid = (tl + tr) >> 1;\n    return op(query(l, r, x << 1, tl, mid), query(l,\
    \ r, x << 1 | 1, mid, tr));\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class T, auto op, auto t_id, class U, auto mapping,\
    \ auto comp, auto u_id>\nstruct LazySegmentTree {\n  LazySegmentTree(int x) {\n\
    \    init(x);\n    pull_all();\n  }\n\n  LazySegmentTree(const vector<T> &a) {\n\
    \    init(sz(a));\n    copy(all(a), begin(st) + size);\n    pull_all();\n  }\n\
    \n  void set(int p, T v) {\n    push_path(p += size);\n    st[p] = v;\n    pull_path(p);\n\
    \  }\n\n  void update(int p, U v) {\n    push_path(p += size);\n    st[p] = mapping(st[p],\
    \ v);\n    pull_path(p);\n  }\n\n  void update(int l, int r, U v) {\n    update(l,\
    \ r + 1, v, 1, 0, size);\n  }\n\n  T get_all() {\n    return st[1];\n  }\n\n \
    \ T get(int p) {\n    push_path(p += size);\n    return st[p];\n  }\n\n  T query(int\
    \ l, int r) {\n    return query(l, r + 1, 1, 0, size);\n  }\n\n  template <class\
    \ F>\n  int find_first(F f) {\n    T pref = t_id();\n    int x = 1;\n    while\
    \ (x < size) {\n      push(x);\n      if (f(op(pref, st[x << 1]))) {\n       \
    \ x = x << 1;\n      } else {\n        pref = op(pref, st[x << 1]);\n        x\
    \ = x << 1 | 1;\n      }\n    }\n    return f(op(pref, st[x])) ? x - size : n;\n\
    \  }\n\n  template <class F>\n  int find_last(F f) {\n    T suff = t_id();\n \
    \   int x = 1;\n    while (x < size) {\n      push(x);\n      if (f(st[x << 1\
    \ | 1], suff)) {\n        x = x << 1 | 1;\n      } else {\n        suff = op(st[x\
    \ << 1 | 1], suff);\n        x = x << 1;\n      }\n    }\n    return f(op(st[x],\
    \ suff)) ? x - size : -1;\n  }\n  \nprivate:\n  int n, log, size;\n  vector<T>\
    \ st;\n  vector<U> lz;\n\n  void init(int x) {\n    n = x;\n    log = lg(n - 1)\
    \ + 1;\n    size = 1 << log;\n    st.resize(size << 1, t_id());\n    lz.resize(size,\
    \ u_id());\n  }\n\n  void pull(int x) {\n    st[x] = op(st[x << 1], st[x << 1\
    \ | 1]);\n  }\n\n  void pull_path(int x) {\n    for (int i = 1; i <= log; i++)\
    \ {\n      pull(x >> i);\n    }\n  }\n\n  void pull_all() {\n    for (int i =\
    \ size - 1; i > 0; i--) {\n      pull(i);\n    }\n  }\n\n  void apply(int x) {\n\
    \    st[x] = mapping(st[x], lz[x >> 1]);\n    if (x < size) {\n      lz[x] = comp(lz[x],\
    \ lz[x >> 1]);\n    }\n  }\n\n  void push(int x) {\n    apply(x << 1);\n    apply(x\
    \ << 1 | 1);\n    lz[x] = u_id();\n  }\n\n  void push_path(int x) {\n    for (int\
    \ i = log; i > 0; i--) {\n      push(x >> i);\n    }\n  }\n\n  void update(int\
    \ l, int r, U v, int x, int tl, int tr) {\n    if (tl >= r || tr <= l) {\n   \
    \   return;\n    }\n    if (tl >= l && tr <= r) {\n      st[x] = mapping(st[x],\
    \ v);\n      if (x < size) {\n        lz[x] = comp(lz[x], v);\n      }\n     \
    \ return;\n    }\n    push(x);\n    int mid = (tl + tr) >> 1;\n    update(l, r,\
    \ v, x << 1, tl, mid);\n    update(l, r, v, x << 1 | 1, mid, tr);\n    pull(x);\n\
    \  }\n\n  T query(int l, int r, int x, int tl, int tr) {\n    if (tl >= r || tr\
    \ <= l) {\n      return t_id();\n    }\n    if (tl >= l && tr <= r) {\n      return\
    \ st[x];\n    }\n    push(x);\n    int mid = (tl + tr) >> 1;\n    return op(query(l,\
    \ r, x << 1, tl, mid), query(l, r, x << 1 | 1, mid, tr));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segtree/segment_tree_lazy.hpp
  requiredBy: []
  timestamp: '2024-09-01 20:19:28-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segtree/segment_tree_lazy.hpp
layout: document
redirect_from:
- /library/datastructures/segtree/segment_tree_lazy.hpp
- /library/datastructures/segtree/segment_tree_lazy.hpp.html
title: datastructures/segtree/segment_tree_lazy.hpp
---
