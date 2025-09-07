---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/segment_tree/lazy_segtree.h\"\ntemplate\
    \ <class T, auto op, auto t_id, class U, auto mapping, auto comp, auto u_id>\n\
    struct LazySegtree {\n  LazySegtree(int n_, T v = t_id()) {\n    init(n_, v);\n\
    \    pull_all();\n  }\n\n  LazySegtree(const vector<T> &a) {\n    init(sz(a),\
    \ t_id());\n    copy(all(a), begin(st) + tree_sz);\n    pull_all();\n  }\n\n \
    \ void set(int p, T v) {\n    push_path(p += tree_sz);\n    st[p] = v;\n    pull_path(p);\n\
    \  }\n\n  void update(int p, U v) {\n    push_path(p += tree_sz);\n    st[p] =\
    \ mapping(st[p], v);\n    pull_path(p);\n  }\n\n  void update(int l, int r, U\
    \ v) {\n    assert(0 <= l && l <= r && r < n);\n    l += tree_sz;\n    r += tree_sz\
    \ + 1;\n\n    push_range(l, r);\n\n    int l2 = l, r2 = r;\n    while (l2 < r2)\
    \ {\n      if (l2 & 1) {\n        apply(l2++, v);\n      }\n      if (r2 & 1)\
    \ {\n        apply(--r2, v);\n      }\n      l2 >>= 1;\n      r2 >>= 1;\n    }\n\
    \n    pull_range(l, r);\n  }\n\n  T get(int p) {\n    push_path(p += tree_sz);\n\
    \    return st[p];\n  }\n\n  T query(int l, int r) {\n    assert(0 <= l && l <=\
    \ r && r < n);\n    l += tree_sz;\n    r += tree_sz + 1;\n\n    push_range(l,\
    \ r);\n\n    T ls = t_id(), rs = t_id();\n    while (l < r) {\n      if (l & 1)\
    \ {\n        ls = op(ls, st[l++]);\n      }\n      if (r & 1) {\n        rs =\
    \ op(st[--r], rs);\n      }\n      l >>= 1;\n      r >>= 1;\n    }\n    return\
    \ op(ls, rs);\n  }\n\n  T query_all() {\n    return st[1];\n  }\n\n  template\
    \ <class F>\n  int find_first(F f) {\n    T pref = t_id();\n    int x = 1;\n \
    \   for (int i = 0; i < log; i++) {\n      push(x);\n      if (f(op(pref, st[x\
    \ << 1]))) {\n        x = x << 1;\n      } else {\n        pref = op(pref, st[x\
    \ << 1]);\n        x = x << 1 | 1;\n      }\n    }\n    return f(op(pref, st[x]))\
    \ ? x - tree_sz : n;\n  }\n\n  template <class F>\n  int find_last(F f) {\n  \
    \  T suff = t_id();\n    int x = 1;\n    for (int i = 0; i < log; i++) {\n   \
    \   push(x);\n      if (f(op(st[x << 1 | 1], suff))) {\n        x = x << 1 | 1;\n\
    \      } else {\n        suff = op(st[x << 1 | 1], suff);\n        x = x << 1;\n\
    \      }\n    }\n    return f(op(st[x], suff)) ? x - tree_sz : -1;\n  }\n  \n\
    private:\n  int n, log, tree_sz;\n  vector<T> st;\n  vector<U> lz;\n\n  void init(int\
    \ n_, T v) {\n    n = n_;\n    log = __lg(n - 1) + 1;\n    tree_sz = 1 << log;\n\
    \    st.resize(tree_sz << 1, v);\n    lz.resize(tree_sz, u_id());\n  }\n\n  void\
    \ apply(int x, U y) {\n    st[x] = mapping(st[x], y);\n    if (x < tree_sz) {\n\
    \      lz[x] = comp(lz[x], y);\n    }\n  }\n\n  void push(int x) {\n    apply(x\
    \ << 1, lz[x]);\n    apply(x << 1 | 1, lz[x]);\n    lz[x] = u_id();\n  }\n\n \
    \ void push_path(int x) {\n    for (int i = log; i > 0; i--) {\n      push(x >>\
    \ i);\n    }\n  }\n\n  void push_range(int l, int r) {\n    for (int i = log;\
    \ i >= 1; i--) {\n      if (((l >> i) << i) != l) {\n        push(l >> i);\n \
    \     }\n      if (((r >> i) << i) != r) {\n        push((r - 1) >> i);\n    \
    \  }\n    }\n  }\n\n  void pull(int x) {\n    st[x] = op(st[x << 1], st[x << 1\
    \ | 1]);\n  }\n\n  void pull_path(int x) {\n    for (int i = 1; i <= log; i++)\
    \ {\n      pull(x >> i);\n    }\n  }\n\n  void pull_range(int l, int r) {\n  \
    \  for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) {\n     \
    \   pull(l >> i);\n      }\n      if (((r >> i) << i) != r) {\n        pull((r\
    \ - 1) >> i);\n      }\n    }\n  }\n\n  void pull_all() {\n    for (int i = tree_sz\
    \ - 1; i > 0; i--) {\n      pull(i);\n    }\n  }\n};\n"
  code: "template <class T, auto op, auto t_id, class U, auto mapping, auto comp,\
    \ auto u_id>\nstruct LazySegtree {\n  LazySegtree(int n_, T v = t_id()) {\n  \
    \  init(n_, v);\n    pull_all();\n  }\n\n  LazySegtree(const vector<T> &a) {\n\
    \    init(sz(a), t_id());\n    copy(all(a), begin(st) + tree_sz);\n    pull_all();\n\
    \  }\n\n  void set(int p, T v) {\n    push_path(p += tree_sz);\n    st[p] = v;\n\
    \    pull_path(p);\n  }\n\n  void update(int p, U v) {\n    push_path(p += tree_sz);\n\
    \    st[p] = mapping(st[p], v);\n    pull_path(p);\n  }\n\n  void update(int l,\
    \ int r, U v) {\n    assert(0 <= l && l <= r && r < n);\n    l += tree_sz;\n \
    \   r += tree_sz + 1;\n\n    push_range(l, r);\n\n    int l2 = l, r2 = r;\n  \
    \  while (l2 < r2) {\n      if (l2 & 1) {\n        apply(l2++, v);\n      }\n\
    \      if (r2 & 1) {\n        apply(--r2, v);\n      }\n      l2 >>= 1;\n    \
    \  r2 >>= 1;\n    }\n\n    pull_range(l, r);\n  }\n\n  T get(int p) {\n    push_path(p\
    \ += tree_sz);\n    return st[p];\n  }\n\n  T query(int l, int r) {\n    assert(0\
    \ <= l && l <= r && r < n);\n    l += tree_sz;\n    r += tree_sz + 1;\n\n    push_range(l,\
    \ r);\n\n    T ls = t_id(), rs = t_id();\n    while (l < r) {\n      if (l & 1)\
    \ {\n        ls = op(ls, st[l++]);\n      }\n      if (r & 1) {\n        rs =\
    \ op(st[--r], rs);\n      }\n      l >>= 1;\n      r >>= 1;\n    }\n    return\
    \ op(ls, rs);\n  }\n\n  T query_all() {\n    return st[1];\n  }\n\n  template\
    \ <class F>\n  int find_first(F f) {\n    T pref = t_id();\n    int x = 1;\n \
    \   for (int i = 0; i < log; i++) {\n      push(x);\n      if (f(op(pref, st[x\
    \ << 1]))) {\n        x = x << 1;\n      } else {\n        pref = op(pref, st[x\
    \ << 1]);\n        x = x << 1 | 1;\n      }\n    }\n    return f(op(pref, st[x]))\
    \ ? x - tree_sz : n;\n  }\n\n  template <class F>\n  int find_last(F f) {\n  \
    \  T suff = t_id();\n    int x = 1;\n    for (int i = 0; i < log; i++) {\n   \
    \   push(x);\n      if (f(op(st[x << 1 | 1], suff))) {\n        x = x << 1 | 1;\n\
    \      } else {\n        suff = op(st[x << 1 | 1], suff);\n        x = x << 1;\n\
    \      }\n    }\n    return f(op(st[x], suff)) ? x - tree_sz : -1;\n  }\n  \n\
    private:\n  int n, log, tree_sz;\n  vector<T> st;\n  vector<U> lz;\n\n  void init(int\
    \ n_, T v) {\n    n = n_;\n    log = __lg(n - 1) + 1;\n    tree_sz = 1 << log;\n\
    \    st.resize(tree_sz << 1, v);\n    lz.resize(tree_sz, u_id());\n  }\n\n  void\
    \ apply(int x, U y) {\n    st[x] = mapping(st[x], y);\n    if (x < tree_sz) {\n\
    \      lz[x] = comp(lz[x], y);\n    }\n  }\n\n  void push(int x) {\n    apply(x\
    \ << 1, lz[x]);\n    apply(x << 1 | 1, lz[x]);\n    lz[x] = u_id();\n  }\n\n \
    \ void push_path(int x) {\n    for (int i = log; i > 0; i--) {\n      push(x >>\
    \ i);\n    }\n  }\n\n  void push_range(int l, int r) {\n    for (int i = log;\
    \ i >= 1; i--) {\n      if (((l >> i) << i) != l) {\n        push(l >> i);\n \
    \     }\n      if (((r >> i) << i) != r) {\n        push((r - 1) >> i);\n    \
    \  }\n    }\n  }\n\n  void pull(int x) {\n    st[x] = op(st[x << 1], st[x << 1\
    \ | 1]);\n  }\n\n  void pull_path(int x) {\n    for (int i = 1; i <= log; i++)\
    \ {\n      pull(x >> i);\n    }\n  }\n\n  void pull_range(int l, int r) {\n  \
    \  for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) {\n     \
    \   pull(l >> i);\n      }\n      if (((r >> i) << i) != r) {\n        pull((r\
    \ - 1) >> i);\n      }\n    }\n  }\n\n  void pull_all() {\n    for (int i = tree_sz\
    \ - 1; i > 0; i--) {\n      pull(i);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/segment_tree/lazy_segtree.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructures/segment_tree/lazy_segtree.h
layout: document
title: Lazy Propagation Segment Tree
---

Segment tree with lazy propagation for efficient range updates and range queries.

## Operations

- `LazySegtree<T, op, id, F, mapping, composition>(n)`: Construct with size `n`
- `set(p, val)`: Set element at position `p` to `val`
- `get(p)`: Get element at position `p`
- `query(l, r)`: Query range `[l, r]`
- `apply(p, f)`: Apply function `f` to element at `p`
- `apply(l, r, f)`: Apply function `f` to range `[l, r]`

## Complexity

- Construction: $O(n)$
- All operations: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
// Range add, range sum
auto op = [](ll a, ll b) { return a + b; };
auto e = []() { return 0LL; };
auto mapping = [](ll f, ll x) { return f + x; };
auto composition = [](ll f, ll g) { return f + g; };

LazySegtree<ll, op, e, ll, mapping, composition> seg(n);
seg.apply(l, r, add_val); // Add add_val to range [l, r]
ll sum = seg.query(l, r);  // Get sum of range [l, r]
```

## Notes

Requires monoid for data and composition of update functions. Supports both point and range operations.