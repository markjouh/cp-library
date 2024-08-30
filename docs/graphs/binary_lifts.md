---
title: Binary Lifting
documentation_of: ../../graphs/binary_lifts.hpp
---

### Overview

Computes binary lifts for a tree, enabling $O(\log{n})$ LCA.

### Usage

* `BinaryLifting(g, root)`: Computes binary lifts. $O(n \log{n})$.
* `par(x)`: Returns the immediate parent of x.
* `anc(x, k)`: Finds the kth ancestor of x.
* `lca(x, y)`: Finds the least common ancestor of x and y.
* `dist(x, y)`: Computes the distance between x and y.