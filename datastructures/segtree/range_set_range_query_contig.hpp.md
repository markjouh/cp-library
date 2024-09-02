---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: datastructures/segtree/segment_tree_lazy.hpp
    title: datastructures/segtree/segment_tree_lazy.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/2000/submission/279265358
  bundledCode: "#line 1 \"datastructures/segtree/range_set_range_query_contig.hpp\"\
    \n// https://codeforces.com/contest/2000/submission/279265358\n\n#line 2 \"datastructures/segtree/segment_tree_lazy.hpp\"\
    \n\ntemplate <class T, auto op, auto t_id, class U, auto mapping, auto comp, auto\
    \ u_id>\nstruct LazySegmentTree {\n  LazySegmentTree(int x) {\n    init(x);\n\
    \    pull_all();\n  }\n\n  LazySegmentTree(const vector<T> &a) {\n    init(sz(a));\n\
    \    copy(all(a), begin(st) + size);\n    pull_all();\n  }\n\n  void set(int p,\
    \ T v) {\n    push_path(p += size);\n    st[p] = v;\n    pull_path(p);\n  }\n\n\
    \  void update(int p, U v) {\n    push_path(p += size);\n    st[p] = mapping(st[p],\
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
    \ r, x << 1, tl, mid), query(l, r, x << 1 | 1, mid, tr));\n  }\n};\n#line 4 \"\
    datastructures/segtree/range_set_range_query_contig.hpp\"\n\nstruct Seg {\n  int\
    \ len, pref, suff, mx;\n\n  Seg(int x) : len(1), pref(x), suff(x), mx(x) {}\n\
    };\n\nSeg op(Seg a, Seg b) {\n  Seg res = a;\n  res.len = a.len + b.len;\n  res.pref\
    \ = a.pref + (a.pref == a.len ? b.pref : 0);\n  res.suff = b.suff + (b.suff ==\
    \ b.len ? a.suff : 0);\n  res.mx = max({a.mx, b.mx, a.suff + b.pref});\n  return\
    \ res;\n}\n\nSeg seg_id() {\n  return Seg(0);\n}\n\nstruct Upd {\n  short v;\n\
    \n  Upd(short x) {\n    v = x;\n  }\n};\n\nSeg mapping(Seg x, Upd y) {\n  if (y.v\
    \ == 1) {\n    x.pref = x.suff = x.mx = x.len;\n  }\n  if (y.v == 0) {\n    x.pref\
    \ = x.suff = x.mx = 0;\n  }\n  return x;\n}\n\nUpd comp(Upd x, Upd y) {\n  return\
    \ y.v != -1 ? y : x;\n}\n\nUpd upd_id() {\n  return Upd(-1);\n}\n"
  code: "// https://codeforces.com/contest/2000/submission/279265358\n\n#include \"\
    segment_tree_lazy.hpp\"\n\nstruct Seg {\n  int len, pref, suff, mx;\n\n  Seg(int\
    \ x) : len(1), pref(x), suff(x), mx(x) {}\n};\n\nSeg op(Seg a, Seg b) {\n  Seg\
    \ res = a;\n  res.len = a.len + b.len;\n  res.pref = a.pref + (a.pref == a.len\
    \ ? b.pref : 0);\n  res.suff = b.suff + (b.suff == b.len ? a.suff : 0);\n  res.mx\
    \ = max({a.mx, b.mx, a.suff + b.pref});\n  return res;\n}\n\nSeg seg_id() {\n\
    \  return Seg(0);\n}\n\nstruct Upd {\n  short v;\n\n  Upd(short x) {\n    v =\
    \ x;\n  }\n};\n\nSeg mapping(Seg x, Upd y) {\n  if (y.v == 1) {\n    x.pref =\
    \ x.suff = x.mx = x.len;\n  }\n  if (y.v == 0) {\n    x.pref = x.suff = x.mx =\
    \ 0;\n  }\n  return x;\n}\n\nUpd comp(Upd x, Upd y) {\n  return y.v != -1 ? y\
    \ : x;\n}\n\nUpd upd_id() {\n  return Upd(-1);\n}"
  dependsOn:
  - datastructures/segtree/segment_tree_lazy.hpp
  isVerificationFile: false
  path: datastructures/segtree/range_set_range_query_contig.hpp
  requiredBy: []
  timestamp: '2024-09-01 20:48:11-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segtree/range_set_range_query_contig.hpp
layout: document
redirect_from:
- /library/datastructures/segtree/range_set_range_query_contig.hpp
- /library/datastructures/segtree/range_set_range_query_contig.hpp.html
title: datastructures/segtree/range_set_range_query_contig.hpp
---
