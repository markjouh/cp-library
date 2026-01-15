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
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/template/template.h\"\n/**\n  *    author: mark\n**/\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\n#define all(x) begin(x), end(x)\n"
  code: "/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define all(x) begin(x), end(x)"
  dependsOn: []
  isVerificationFile: false
  path: src/template/template.h
  requiredBy: []
  timestamp: '2026-01-15 15:27:11+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/string/enumerate_palindromes.test.cpp
  - src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - src/verify/library_checker/data_structure/unionfind.test.cpp
  - src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
  - src/verify/library_checker/data_structure/point_add_range_sum_segtree.test.cpp
  - src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - src/verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - src/verify/library_checker/data_structure/set_xor_min.test.cpp
  - src/verify/library_checker/data_structure/associative_array.test.cpp
  - src/verify/library_checker/data_structure/static_rmq.test.cpp
  - src/verify/library_checker/data_structure/static_range_sum_sparse.test.cpp
  - src/verify/library_checker/graph/scc.test.cpp
  - src/verify/library_checker/graph/shortest_path.test.cpp
  - src/verify/library_checker/number_theory/enumerate_primes.test.cpp
  - src/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - src/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - src/verify/library_checker/tree/binlift_lca.test.cpp
  - src/verify/library_checker/tree/fast_lca.test.cpp
documentation_of: src/template/template.h
layout: document
title: Template
---

Standard competitive programming template with common includes.

## Features

- Includes `<bits/stdc++.h>`
- `using namespace std`
- `all(x)` macro: expands to `begin(x), end(x)`

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

  sort(all(a));  // Uses the all() macro

  return 0;
}
```

## Notes

Provides minimal boilerplate for competitive programming. Use `ssize(x)` from C++20 for signed size.
