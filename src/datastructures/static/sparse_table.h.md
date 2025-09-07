---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/graphs/trees/fast_lca.h
    title: Fast LCA (Lowest Common Ancestor)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/static_rmq.test.cpp
    title: src/verify/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/tree/fast_lca.test.cpp
    title: src/verify/library_checker/tree/fast_lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/static/sparse_table.h\"\ntemplate <class\
    \ T, auto op>\nstruct SparseTable {\n  int n, log;\n  vector<vector<T>> st;\n\n\
    \  SparseTable() {}\n  SparseTable(const vector<T> &a) : n(sz(a)), log(__lg(n)\
    \ + 1) {\n    st.resize(log);\n    st[0] = a;\n    for (int i = 1; i < log; i++)\
    \ {\n      st[i].resize(n - (1 << i) + 1);\n      for (int j = 0; j < sz(st[i]);\
    \ j++) {\n        st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n\
    \      }\n    }\n  }\n\n  T query(int l, int r) {\n    assert(l <= r);\n    int\
    \ i = __lg(++r - l);\n    return op(st[i][l], st[i][r - (1 << i)]);\n  }\n};\n\
    \ntemplate <class T>\nT min_op(T x, T y) {\n  return x < y ? x : y;\n}\ntemplate\
    \ <class T>\nT max_op(T x, T y) {\n  return x > y ? x : y;\n}\n"
  code: "template <class T, auto op>\nstruct SparseTable {\n  int n, log;\n  vector<vector<T>>\
    \ st;\n\n  SparseTable() {}\n  SparseTable(const vector<T> &a) : n(sz(a)), log(__lg(n)\
    \ + 1) {\n    st.resize(log);\n    st[0] = a;\n    for (int i = 1; i < log; i++)\
    \ {\n      st[i].resize(n - (1 << i) + 1);\n      for (int j = 0; j < sz(st[i]);\
    \ j++) {\n        st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n\
    \      }\n    }\n  }\n\n  T query(int l, int r) {\n    assert(l <= r);\n    int\
    \ i = __lg(++r - l);\n    return op(st[i][l], st[i][r - (1 << i)]);\n  }\n};\n\
    \ntemplate <class T>\nT min_op(T x, T y) {\n  return x < y ? x : y;\n}\ntemplate\
    \ <class T>\nT max_op(T x, T y) {\n  return x > y ? x : y;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/static/sparse_table.h
  requiredBy:
  - src/graphs/trees/fast_lca.h
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/static_rmq.test.cpp
  - src/verify/library_checker/tree/fast_lca.test.cpp
documentation_of: src/datastructures/static/sparse_table.h
layout: document
title: Sparse Table
---

Static range minimum/maximum queries with $O(1)$ query time using sparse table.

## Operations

- `SparseTable(arr, op)`: Construct from array with associative operation `op`
- `query(l, r)`: Query range `[l, r]` with the given operation

## Complexity

- Construction: $O(n \log n)$
- Query: $O(1)$
- Space: $O(n \log n)$

## Usage

```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9, 2};

// Range minimum queries
auto min_op = [](int a, int b) { return min(a, b); };
SparseTable<int> st(arr, min_op);
int range_min = st.query(1, 5); // Min of {1, 4, 1, 5, 9}

// Range maximum queries
auto max_op = [](int a, int b) { return max(a, b); };
SparseTable<int> st_max(arr, max_op);
int range_max = st_max.query(2, 6);
```

## Notes

Operation must be idempotent: `op(x, x) = x`. Common operations: min, max, gcd.

**Implementation Details**: Uses 2D table where `table[i][j]` stores the result for range of length `2^i` starting at position `j`. Query combines two overlapping ranges of length `2^k` where `k = floor(log2(r-l+1))`, leveraging idempotency to handle the overlap safely.