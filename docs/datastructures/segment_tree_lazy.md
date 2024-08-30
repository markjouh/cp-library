---
title: Lazy Segment Tree
documentation_of: ../../datastructures/segment_tree_lazy.hpp
---

### Overview

The segment tree is a data structure that stores an array of objects with an associative merge operation and identity element. Lazy propagation allows for a variety of range update operations to be supported in $O(\log{n})$ as well.

### Usage

* `LazySegmentTree(x)`: Builds a segment tree of length x, or from the vector x. The complexity is $O(n)$ in both cases.
* `update(l, r, v)`: Applies an update with value v to the interval $[l, r]$.
* `query(l, r)`: Returns the range aggregate over the interval $[l, r]$.