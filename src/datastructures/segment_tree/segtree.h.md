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
  bundledCode: "#line 1 \"src/datastructures/segment_tree/segtree.h\"\ntemplate <class\
    \ T, auto op, auto id>\nstruct Segtree {\n  int n;\n  vector<T> st;\n\n  Segtree(int\
    \ n_) : n(n_), st(2 * n, id()) {}\n\n  Segtree(const vector<T> &a) : n(sz(a)),\
    \ st(2 * n) {\n    copy(all(a), begin(st) + n);\n    for (int i = n - 1; i > 0;\
    \ i--) {\n      st[i] = op(st[i << 1], st[i << 1 | 1]);\n    }\n  }\n\n  void\
    \ set(int p, T val) {\n    for (st[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n\
    \      st[p] = op(st[p << 1], st[p << 1 | 1]);\n    }\n  }\n\n  T get(int p) {\n\
    \    return st[p + n];\n  }\n\n  T query(int l, int r) {\n    T ls = id(), rs\
    \ = id();\n    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n      if (l\
    \ & 1) {\n        ls = op(ls, st[l++]);\n      }\n      if (r & 1) {\n       \
    \ rs = op(st[--r], rs);\n      }\n    }\n    return op(ls, rs);\n  }\n};\n"
  code: "template <class T, auto op, auto id>\nstruct Segtree {\n  int n;\n  vector<T>\
    \ st;\n\n  Segtree(int n_) : n(n_), st(2 * n, id()) {}\n\n  Segtree(const vector<T>\
    \ &a) : n(sz(a)), st(2 * n) {\n    copy(all(a), begin(st) + n);\n    for (int\
    \ i = n - 1; i > 0; i--) {\n      st[i] = op(st[i << 1], st[i << 1 | 1]);\n  \
    \  }\n  }\n\n  void set(int p, T val) {\n    for (st[p += n] = val, p >>= 1; p\
    \ > 0; p >>= 1) {\n      st[p] = op(st[p << 1], st[p << 1 | 1]);\n    }\n  }\n\
    \n  T get(int p) {\n    return st[p + n];\n  }\n\n  T query(int l, int r) {\n\
    \    T ls = id(), rs = id();\n    for (l += n, r += n + 1; l < r; l >>= 1, r >>=\
    \ 1) {\n      if (l & 1) {\n        ls = op(ls, st[l++]);\n      }\n      if (r\
    \ & 1) {\n        rs = op(st[--r], rs);\n      }\n    }\n    return op(ls, rs);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/segment_tree/segtree.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructures/segment_tree/segtree.h
layout: document
title: Segment Tree
---

Supports efficient range queries and point updates using associative operations.

## Operations

- `Segtree<T, op, id>(n)`: Construct with size `n`
- `Segtree<T, op, id>(arr)`: Construct from array
- `set(p, val)`: Set element at position `p` to `val`
- `get(p)`: Get current value at position `p`
- `query(l, r)`: Query aggregate value over range `[l, r]`

## Complexity

- Construction: $O(n)$
- Update: $O(\log n)$
- Query: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
auto add = [](int a, int b) { return a + b; };
auto zero = []() { return 0; };

// Range sum queries
Segtree<int, add, zero> st(n);
st.set(2, 10);
int sum = st.query(1, 4);

// Range min queries
auto min_op = [](int a, int b) { return min(a, b); };
auto inf = []() { return INT_MAX; };
Segtree<int, min_op, inf> min_st(arr);
```

## Notes

Operation must be associative. Identity element satisfies `op(x, id()) = x`.