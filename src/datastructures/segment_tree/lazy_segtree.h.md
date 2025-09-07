---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
    title: src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
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
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
documentation_of: src/datastructures/segment_tree/lazy_segtree.h
layout: document
title: Lazily Propagated Segment Tree
---

A segment tree with lazy propagation, supporting range updates and range queries in logarithmic time. It is highly generic, defined by user-provided functions for data aggregation and updates.

The template requires seven parameters to define its behavior:
- `T`: The type of data stored in the tree's nodes (e.g., `long long` for sums).
- `op`: A binary function `(T, T) -> T` that merges data from two child nodes. For range sum, this is addition; for range minimum, it is `min`.
- `t_id`: A function `() -> T` returning the identity for `op` (e.g., `0` for sum, infinity for `min`).
- `U`: The type representing a pending update. For a range-add query, `U` would be the type of the value being added (e.g., `long long`). For a range-set query, `U` would be the type of the value being set.
- `mapping`: A function `(T, U) -> T` that applies an update `U` to a data node `T`. For range-add, this would be `(current_sum, value_to_add) -> new_sum`.
- `comp`: A function `(U, U) -> U` that composes two pending updates. For range-add, if an "add 5" operation is pending and a new "add 3" arrives, this function combines them into an "add 8" operation.
- `u_id`: A function `() -> U` returning an update that does nothing. For range-add, this is `0`.

## Operations
- `LazySegtree(n)`: Constructs a tree of size `n`.
- `set(p, val)`: Sets the value at index `p` to `val`.
- `get(p)`: Retrieves the value at index `p`.
- `update(p, v)`: Applies an update `v` of type `U` to the element at index `p`.
- `update(l, r, v)`: Applies an update `v` of type `U` to the range `[l, r]`.
- `query(l, r)`: Queries the aggregated value over the range `[l, r]`.
- `query_all()`: Queries the aggregated value over the entire tree.
- `find_first(f)`: Finds the first index `i` for which `f(query(0, i))` is true.
- `find_last(f)`: Finds the last index `i` for which `f(query(i, n-1))` is true.

## Complexity
- Construction: $O(n)$
- All operations: $O(\log n)$
- Space: $O(n)$

## Usage
```cpp
// Example: Range Add, Range Sum
// T is long long, U is long long
auto op = [](long long a, long long b) { return a + b; };
auto t_id = []() { return 0LL; };
auto mapping = [](long long current_node_val, long long update_val) { 
  return current_node_val + update_val; 
};
auto comp = [](long long existing_lazy, long long new_lazy) { 
  return existing_lazy + new_lazy; 
};
auto u_id = []() { return 0LL; };

LazySegtree<long long, op, t_id, long long, mapping, comp, u_id> seg(n);
seg.update(2, 5, 5); // Add 5 to range [2, 5]
long long sum = seg.query(3, 7); // Get sum of range [3, 7]
```

## Notes
The pair `(T, op)` must form a monoid with `t_id` as the identity. The pair `(U, comp)` must form a monoid with `u_id` as the identity. The `mapping` function must distribute over `op`.
