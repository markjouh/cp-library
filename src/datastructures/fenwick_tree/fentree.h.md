---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/datastructures/fenwick_tree/dual_fentree.h
    title: Dual Fenwick Tree
  - icon: ':warning:'
    path: src/datastructures/fenwick_tree/fentree_2d.h
    title: 2D Fenwick Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: src/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/fenwick_tree/fentree.h\"\ntemplate <class\
    \ T>\nstruct Fentree {\n  int n;\n  vector<T> ft;\n\n  Fentree(int n_) : n(n_),\
    \ ft(n + 1) {}\n\n  Fentree(const vector<T> &a) : n(ssize(a)), ft(n + 1) {\n \
    \   for (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n      if (i + (i\
    \ & -i) <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n  }\n\n \
    \ void add(int p, T v) {\n    for (p++; p <= n; p += p & -p) {\n      ft[p] +=\
    \ v;\n    }\n  }\n\n  T sum(int r) {\n    T res = 0;\n    for (r++; r > 0; r -=\
    \ r & -r) {\n      res += ft[r];\n    }\n    return res;\n  }\n\n  T sum(int l,\
    \ int r) {\n    return sum(r) - sum(l - 1);\n  }\n};\n"
  code: "template <class T>\nstruct Fentree {\n  int n;\n  vector<T> ft;\n\n  Fentree(int\
    \ n_) : n(n_), ft(n + 1) {}\n\n  Fentree(const vector<T> &a) : n(ssize(a)), ft(n\
    \ + 1) {\n    for (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n     \
    \ if (i + (i & -i) <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n\
    \  }\n\n  void add(int p, T v) {\n    for (p++; p <= n; p += p & -p) {\n     \
    \ ft[p] += v;\n    }\n  }\n\n  T sum(int r) {\n    T res = 0;\n    for (r++; r\
    \ > 0; r -= r & -r) {\n      res += ft[r];\n    }\n    return res;\n  }\n\n  T\
    \ sum(int l, int r) {\n    return sum(r) - sum(l - 1);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/fenwick_tree/fentree.h
  requiredBy:
  - src/datastructures/fenwick_tree/fentree_2d.h
  - src/datastructures/fenwick_tree/dual_fentree.h
  timestamp: '2026-01-15 15:27:11+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - src/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
documentation_of: src/datastructures/fenwick_tree/fentree.h
layout: document
title: Fenwick Tree (Binary Indexed Tree)
---

Efficient point updates and prefix sum queries using binary indexed tree structure.

## Operations

- `Fentree(n)`: Construct with size `n` (zero-initialized)
- `Fentree(arr)`: Construct from array
- `add(p, v)`: Add value `v` to element at position `p`
- `sum(r)`: Get prefix sum from index `0` to `r`
- `sum(l, r)`: Get range sum from index `l` to `r`

## Complexity

- Construction: $O(n)$ from array, $O(1)$ zero-initialized
- Update: $O(\log n)$
- Query: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
// Create from array
vector<int> arr = {1, 3, 5, 7, 9};
Fentree<int> ft(arr);

// Add 5 to element at index 2
ft.add(2, 5);

// Get prefix sum [0, 3]
int prefix_sum = ft.sum(3);

// Get range sum [1, 4]
int range_sum = ft.sum(1, 4);
```

## Notes

Uses 1-based indexing internally. Each position stores sum of range determined by `lowbit(i)`.