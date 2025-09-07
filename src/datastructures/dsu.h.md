---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/unionfind.test.cpp
    title: src/verify/library_checker/data_structure/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/dsu.h\"\nstruct DSU {\n  vector<int>\
    \ a;\n\n  DSU(int n) : a(n, -1) {}\n\n  int size(int x) {\n    return -a[find(x)];\n\
    \  }\n\n  int find(int x) {\n    return a[x] < 0 ? x : a[x] = find(a[x]);\n  }\n\
    \n  bool join(int x, int y) {\n    x = find(x);\n    y = find(y);\n    if (x ==\
    \ y) {\n      return 0;\n    }\n    if (a[x] > a[y]) {\n      swap(x, y);\n  \
    \  }\n    a[x] += a[y];\n    a[y] = x;\n    return 1;\n  }\n};\n"
  code: "struct DSU {\n  vector<int> a;\n\n  DSU(int n) : a(n, -1) {}\n\n  int size(int\
    \ x) {\n    return -a[find(x)];\n  }\n\n  int find(int x) {\n    return a[x] <\
    \ 0 ? x : a[x] = find(a[x]);\n  }\n\n  bool join(int x, int y) {\n    x = find(x);\n\
    \    y = find(y);\n    if (x == y) {\n      return 0;\n    }\n    if (a[x] > a[y])\
    \ {\n      swap(x, y);\n    }\n    a[x] += a[y];\n    a[y] = x;\n    return 1;\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/dsu.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/unionfind.test.cpp
documentation_of: src/datastructures/dsu.h
layout: document
title: Disjoint Set Union (DSU)
---

Union-Find data structure with path compression and union by size optimization.

## Operations

- `DSU(n)`: Construct for `n` elements `(0` to `n-1)`
- `find(x)`: Find representative of set containing `x`
- `join(x, y)`: Merge sets containing `x` and `y`, return `true` if different sets
- `size(x)`: Get size of set containing `x`

## Complexity

- All operations: $O(\alpha(n))$ amortized
- Space: $O(n)$

## Usage

```cpp
DSU dsu(n);

// Check if in same set
if (dsu.find(x) == dsu.find(y)) {
  // Same set
}

// Merge sets
if (dsu.join(x, y)) {
  // Were in different sets, now merged
}

int setSize = dsu.size(x);
```

## Notes

$\alpha(n)$ is inverse Ackermann function, effectively constant. Uses union by size and path compression.