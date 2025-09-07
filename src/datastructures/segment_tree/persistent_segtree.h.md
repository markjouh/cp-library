---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
    title: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/segment_tree/persistent_segtree.h\"\n\
    template <class T, auto op, auto id>\nstruct PersistentSegtree {\n  int log, tree_sz,\
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
    \ r + 1, get_root(t), 0, tree_sz);\n  }\n};\n"
  code: "template <class T, auto op, auto id>\nstruct PersistentSegtree {\n  int log,\
    \ tree_sz, updates;\n  vector<T> st;\n  vector<array<int, 2>> ch;\n\n  PersistentSegtree()\
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
    \ r + 1, get_root(t), 0, tree_sz);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/segment_tree/persistent_segtree.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
documentation_of: src/datastructures/segment_tree/persistent_segtree.h
layout: document
title: Persistent Segment Tree
---

Persistent segment tree supporting queries on previous versions with structural sharing.

## Operations

- `PersistentSegtree(n)`: Create initial version
- `set(version, pos, val)`: Create new version with updated position
- `query(version, l, r)`: Query range in specific version

## Complexity

- All operations: $O(\log n)$
- Space per version: $O(\log n)$ additional nodes

## Usage

```cpp
auto op = [](int a, int b) { return a + b; };
auto id = []() { return 0; };
PersistentSegtree<int, op, id> pst(n);

int v1 = pst.set(0, pos1, val1);  // Create version 1
int v2 = pst.set(v1, pos2, val2); // Create version 2

int sum_v1 = pst.query(v1, l, r); // Query version 1
int sum_v2 = pst.query(v2, l, r); // Query version 2
```

## Notes

Creates new tree nodes only for changed parts. Enables time-travel queries on data structure state.

**Memory Management**: Uses path copying - only nodes along the path from root to modified leaf are duplicated. With $k$ updates, total space is $O(n + k \log n)$. For memory efficiency with many versions, consider node pooling or garbage collection of unreferenced versions.