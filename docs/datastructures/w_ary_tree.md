---
title: 64-ary Tree
documentation_of: ../../datastructures/w_ary_tree.hpp
---

### Overview

A tree data structure that takes advantage of hardware intrinsics to support multiset operations on a frequency table, with $O(\log_{64}{n})$ operations and an extremely small constant factor.

TODO: Implement predecessor/successor queries

### Usage

* `w_ary_tree<T>(n)`: Builds an empty 64-ary tree capable of storing values $[0, n)$. $O(n)$
* `insert(x)`: Inserts x into the multiset.
* `extract(x)`: Erases an instance of x from the multiset.
* `get_min(x)`: Returns the minimum value in the set.
* `get_max(x)`: Returns the maximum value in the set.