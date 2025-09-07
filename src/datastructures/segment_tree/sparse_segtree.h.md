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
  bundledCode: "#line 1 \"src/datastructures/segment_tree/sparse_segtree.h\"\ntemplate\
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
    \ mid, tr));\n  }\n};\n"
  code: "template <class T, auto op, auto id>\nstruct SparseSegtree {\n  SparseSegtree()\
    \ {}\n\n  SparseSegtree(int n) {\n    log = __lg(n) + 1;\n    tree_sz = 1 << log;\n\
    \    st.push_back(id());\n    ch.emplace_back(-1, -1);\n  }\n\n  void set(int\
    \ p, T v) {\n    buf[0] = idx = 0;\n    int tl = 0, tr = tree_sz;\n    while (tl\
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
    \ mid, tr));\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/segment_tree/sparse_segtree.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructures/segment_tree/sparse_segtree.h
layout: document
title: Sparse Segment Tree
---

Segment tree for large coordinate ranges with dynamic node allocation.

## Operations

- `SparseSegtree(max_coord)`: Create for coordinate range `[0, max_coord)`
- `update(pos, val)`: Update position with value
- `query(l, r)`: Query range sum/operation

## Complexity

- All operations: $O(\log(\text{max\_coord}))$
- Space: $O(k \log(\text{max\_coord}))$ where $k$ is updates

## Usage

```cpp
SparseSegtree<ll> sparse_seg(1e9); // Large coordinate range

sparse_seg.update(1000000, 5);
sparse_seg.update(999999999, 10);

ll sum = sparse_seg.query(999999, 1000001);
```

## Notes

Only allocates nodes for accessed coordinates. Efficient for large coordinate ranges with sparse updates.

**Coordinate Compression**: While this uses dynamic allocation, for better cache performance with known coordinates, consider explicit coordinate compression where you map coordinates to dense indices `[0, k)` before using a regular segment tree.