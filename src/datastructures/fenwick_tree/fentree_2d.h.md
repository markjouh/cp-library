---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/fenwick_tree/fentree.h
    title: Fenwick Tree (Binary Indexed Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/fenwick_tree/fentree.h\"\ntemplate <class\
    \ T>\nstruct Fentree {\n  int n;\n  vector<T> ft;\n\n  Fentree(int n_) : n(n_),\
    \ ft(n + 1) {}\n\n  Fentree(const vector<T> &a) : n(sz(a)), ft(n + 1) {\n    for\
    \ (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n      if (i + (i & -i)\
    \ <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n  }\n\n  void add(int\
    \ p, T v) {\n    for (p++; p <= n; p += p & -p) {\n      ft[p] += v;\n    }\n\
    \  }\n\n  T sum(int r) {\n    T res = 0;\n    for (r++; r > 0; r -= r & -r) {\n\
    \      res += ft[r];\n    }\n    return res;\n  }\n\n  T sum(int l, int r) {\n\
    \    return sum(r) - sum(l - 1);\n  }\n};\n#line 2 \"src/datastructures/fenwick_tree/fentree_2d.h\"\
    \n\ntemplate <class T>\nstruct Fentree2D {\n  int n;\n  vector<Fentree<T>> ft;\n\
    \n  Fentree2D(int n_, int m) : n(n_), ft(n + 1, Fentree<T>(m)) {}\n\n  void add(int\
    \ r, int c, T v) {\n    for (r++; r <= n; r += r & -r) {\n      ft[r].add(c, v);\n\
    \    }\n  }\n\n  T sum(int r, int c) {\n    if (r < 0 || c < 0) {\n      return\
    \ 0;\n    }\n    T res = 0;\n    for (r++; r > 0; r -= r & -r) {\n      res +=\
    \ ft[r].sum(c);\n    }\n    return res;\n  }\n\n  T sum(int r1, int c1, int r2,\
    \ int c2) {\n    return sum(r2, c2) - sum(r2, c1 - 1) - sum(r1 - 1, c2) + sum(r1\
    \ - 1, c1 - 1);\n  }\n};\n"
  code: "#include \"fentree.h\"\n\ntemplate <class T>\nstruct Fentree2D {\n  int n;\n\
    \  vector<Fentree<T>> ft;\n\n  Fentree2D(int n_, int m) : n(n_), ft(n + 1, Fentree<T>(m))\
    \ {}\n\n  void add(int r, int c, T v) {\n    for (r++; r <= n; r += r & -r) {\n\
    \      ft[r].add(c, v);\n    }\n  }\n\n  T sum(int r, int c) {\n    if (r < 0\
    \ || c < 0) {\n      return 0;\n    }\n    T res = 0;\n    for (r++; r > 0; r\
    \ -= r & -r) {\n      res += ft[r].sum(c);\n    }\n    return res;\n  }\n\n  T\
    \ sum(int r1, int c1, int r2, int c2) {\n    return sum(r2, c2) - sum(r2, c1 -\
    \ 1) - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1);\n  }\n};"
  dependsOn:
  - src/datastructures/fenwick_tree/fentree.h
  isVerificationFile: false
  path: src/datastructures/fenwick_tree/fentree_2d.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructures/fenwick_tree/fentree_2d.h
layout: document
title: 2D Fenwick Tree
---

Two-dimensional Fenwick tree for efficient point updates and rectangular range sum queries.

## Operations

- `Fentree2D(n, m)`: Construct `n × m` 2D Fenwick tree
- `add(r, c, v)`: Add value `v` to element at `(r, c)`
- `sum(r, c)`: Get prefix sum from `(0, 0)` to `(r, c)`
- `sum(r1, c1, r2, c2)`: Get sum of rectangle `(r1, c1)` to `(r2, c2)`

## Complexity

- Construction: $O(1)$
- Update: $O(\log n \times \log m)$
- Query: $O(\log n \times \log m)$
- Space: $O(n \times m)$

## Usage

```cpp
// Create 2D Fenwick tree
Fentree2D<int> ft2d(n, m);

// Add 5 to position (2, 3)
ft2d.add(2, 3, 5);

// Get rectangle sum from (1, 1) to (3, 3)
int rect_sum = ft2d.sum(1, 1, 3, 3);
```

## Notes

Uses vector of 1D Fenwick trees. Rectangle queries use inclusion-exclusion principle.