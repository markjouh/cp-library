---
title: Sparse Table
documentation_of: ../../datastructures/sparse_table.hpp
---

### Overview

The sparse table is a data structure that's useful for answering static range queries in constant time given an idempotent merge operation (that is, applying it more than once won't change the result). Generally used for RMQ.

Sparse tables precompute the result for all subarrays with lengths of powers of 2 using range dp. This guaranteees there will always exist a pair of (not neccessarily distinct) intervals in our table which have a union equal to any valid query interval, allowing us to compute the answer in $O(1)$.

### Usage

* `SparseTable<T, op>(a)`: Builds a sparse table from the vector `a`. $O(n \log{n})$ time and memory.
* `query(l, r)`: Returns the range aggregate over the interval $[l, r]$. $O(1)$