---
title: Segment Tree
documentation_of: ../../datastructures/segment_tree.hpp
---

### Overview

The segment tree is a data structure that stores an array of objects with an associative merge operation and identity element. It supports arbitary point updates and range queries in $O(\log{n})$.

### Usage

* `SegmentTree<T>(x)`: Builds a segment tree of length x, or from the vector x. The complexity is $O(n)$ in both cases.
* `set(k, x)`: Sets the value at index k to x.
* `query(l, r)`: Returns the range aggregate over the interval $[l, r]$.