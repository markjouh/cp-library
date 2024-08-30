---
title: Lazy Segment Tree
documentation_of: ../../datastructures/union_find.hpp
---

### Overview

The union find is an online connectivity data structure that only supports edge insertions. Each component is defined by its leader element; vertices with the same leader element are connected - otherwise, they're disconnected.

Queries have inverse Ackermann complexity, which grows so slowly, they're functionally $O(1)$.

### Usage

* `UnionFind<T>(n)`: Initializes a union find of size n. $O(n)$
* `size(x)`: Returns the size of x's component.
* `find(x)`: Returns the leader element of vertex x.
* `join(x, y)`: If x and y aren't connected, connects them and returns `true`. Otherwise, returns `false`.