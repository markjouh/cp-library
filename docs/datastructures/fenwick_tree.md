---
title: Fenwick Tree
documentation_of: ../../datastructures/fenwick_tree.hpp
---

#### Overview

A fenwick tree is a data structure that stores an array and supports $O(\log{n})$ point updates and range queries. It's generally used for adds/sums.

#### Operations

* `fenwick_tree<T>(x)`: Builds a fenwick tree of length x, or from the vector x. The complexity is $O(n)$ in both cases.
* `add(k, x)`: Adds x to index k. $O(\log{n})$
* `sum(l, r)`: Returns the sum of the interval $[l, r]$. $O(\log{n})$.

#### More Details

The reason fenwick trees are seldom used outside of sum queries is because their functionality is just a small subset of that of segment trees, with their only advantage being a noticable but rarely crucial edge in terms of constant factor. It's not possible to compute range queries if the operation being applied doesn't have an inverse, and AFAIK the same goes for any sort of updates (even if it can be done, it'd probably come at the cost of the simplicity that make FTs desirable in the first place).

We can modify the datastructure to support range updates and point queries instead by swapping the contents of the inner loops of the update and query functions, but it's not covered in this library out of simplicity, and because we can get both range updates and range queries using two point update fenwick trees in tandem anyway.