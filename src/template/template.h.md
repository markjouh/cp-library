---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/associative_array.test.cpp
    title: src/verify/library_checker/data_structure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
    title: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp
    title: src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
    title: src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/set_xor_min.test.cpp
    title: src/verify/library_checker/data_structure/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp
    title: src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/static_rmq.test.cpp
    title: src/verify/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/unionfind.test.cpp
    title: src/verify/library_checker/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/graph/scc.test.cpp
    title: src/verify/library_checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/graph/shortest_path.test.cpp
    title: src/verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: src/verify/library_checker/number_theory/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/string/enumerate_palindromes.test.cpp
    title: src/verify/library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/tree/binlift_lca.test.cpp
    title: src/verify/library_checker/tree/binlift_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/tree/fast_lca.test.cpp
    title: src/verify/library_checker/tree/fast_lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: src/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: src/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/template/template.h\"\n/**\n  *    author: mark\n**/\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\n#define sz(x) int(size(x))\n\
    #define all(x) begin(x), end(x)\n"
  code: "/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x), end(x)"
  dependsOn: []
  isVerificationFile: false
  path: src/template/template.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
  - src/verify/library_checker/data_structure/set_xor_min.test.cpp
  - src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - src/verify/library_checker/data_structure/associative_array.test.cpp
  - src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp
  - src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp
  - src/verify/library_checker/data_structure/unionfind.test.cpp
  - src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
  - src/verify/library_checker/data_structure/static_rmq.test.cpp
  - src/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - src/verify/library_checker/tree/fast_lca.test.cpp
  - src/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - src/verify/library_checker/tree/binlift_lca.test.cpp
  - src/verify/library_checker/number_theory/enumerate_primes.test.cpp
  - src/verify/library_checker/graph/shortest_path.test.cpp
  - src/verify/library_checker/graph/scc.test.cpp
  - src/verify/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: src/template/template.h
layout: document
title: Template
---

Standard competitive programming template with common includes and optimizations.

## Features

- Fast I/O setup with `ios::sync_with_stdio(false)`
- Common includes: `<bits/stdc++.h>`, algorithm headers
- Useful macros and typedefs
- Debug utilities for local development

## Usage

```cpp
#include "template/template.h"

int main() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
  cin >> a[i];
  }
  
  // Your solution here
  
  return 0;
}
```

## Notes

Includes portable built-ins and explicit standard library includes for compatibility across different compilers.