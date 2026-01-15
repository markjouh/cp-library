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
    \ ft(n + 1) {}\n\n  Fentree(const vector<T> &a) : n(ssize(a)), ft(n + 1) {\n \
    \   for (int i = 1; i <= n; i++) {\n      ft[i] += a[i - 1];\n      if (i + (i\
    \ & -i) <= n) {\n        ft[i + (i & -i)] += ft[i];\n      }\n    }\n  }\n\n \
    \ void add(int p, T v) {\n    for (p++; p <= n; p += p & -p) {\n      ft[p] +=\
    \ v;\n    }\n  }\n\n  T sum(int r) {\n    T res = 0;\n    for (r++; r > 0; r -=\
    \ r & -r) {\n      res += ft[r];\n    }\n    return res;\n  }\n\n  T sum(int l,\
    \ int r) {\n    return sum(r) - sum(l - 1);\n  }\n};\n#line 2 \"src/datastructures/fenwick_tree/dual_fentree.h\"\
    \n\ntemplate <class T>\nstruct DualFentree {\n  int n;\n  Fentree<T> pref, suff;\n\
    \n  DualFentree(int n_) : n(n_), pref(n), suff(n) {}\n\n  T sum(int r) {\n   \
    \ return pref.sum(r - 1) + suff.sum(n - r - 1) * (r + 1);\n  }\n\n  T sum(int\
    \ l, int r) {\n    return sum(r) - (l > 0 ? sum(l - 1) : 0);\n  }\n\n  void add(int\
    \ r, T v) {\n    pref.add(r, v * (r + 1));\n    suff.add(n - r - 1, v);\n  }\n\
    \n  void add(int l, int r, T v) {\n    add(r, v);\n    if (l > 0) {\n      add(l\
    \ - 1, T(0) - T(v));\n    }\n  }\n};\n"
  code: "#include \"fentree.h\"\n\ntemplate <class T>\nstruct DualFentree {\n  int\
    \ n;\n  Fentree<T> pref, suff;\n\n  DualFentree(int n_) : n(n_), pref(n), suff(n)\
    \ {}\n\n  T sum(int r) {\n    return pref.sum(r - 1) + suff.sum(n - r - 1) * (r\
    \ + 1);\n  }\n\n  T sum(int l, int r) {\n    return sum(r) - (l > 0 ? sum(l -\
    \ 1) : 0);\n  }\n\n  void add(int r, T v) {\n    pref.add(r, v * (r + 1));\n \
    \   suff.add(n - r - 1, v);\n  }\n\n  void add(int l, int r, T v) {\n    add(r,\
    \ v);\n    if (l > 0) {\n      add(l - 1, T(0) - T(v));\n    }\n  }\n};"
  dependsOn:
  - src/datastructures/fenwick_tree/fentree.h
  isVerificationFile: false
  path: src/datastructures/fenwick_tree/dual_fentree.h
  requiredBy: []
  timestamp: '2026-01-15 15:27:11+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructures/fenwick_tree/dual_fentree.h
layout: document
title: Dual Fenwick Tree
---

Supports efficient range updates and point queries, dual to standard Fenwick tree.

## Operations

- `DualFentree(n)`: Construct with size `n`
- `add(r, v)`: Add `v` to all elements in `[0, r]`
- `add(l, r, v)`: Add `v` to all elements in `[l, r]`
- `sum(r)`: Get current value at position `r`
- `sum(l, r)`: Get sum of values in range `[l, r]`

## Complexity

- Construction: $O(n)$
- Update: $O(\log n)$
- Query: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
DualFentree<int> dft(n);

// Add 5 to range [2, 7]
dft.add(2, 7, 5);

// Get value at position 3
int value = dft.sum(3);

// Get range sum [1, 5]
int range_sum = dft.sum(1, 5);
```

## Notes

Uses two Fenwick trees for linear and constant components of range updates.