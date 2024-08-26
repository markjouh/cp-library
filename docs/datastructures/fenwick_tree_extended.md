---
title: Range Add Range Query Fenwick Tree
documentation_of: ../../datastructures/fenwick_tree_extended.hpp
---

### Overview

A data structure that uses two point update fenwick trees to achieve both range adds and range sums in $O(\log(n))$.

For a reversible operation like addition, supporting prefix operations naturally extends to range operations, so let's focus on that for now. When we query a prefix $r$, completed prefix updates at some $p \leq r$ have contribution capped by their position, while for updates with $p \gt r$, it's capped by our position. We can reflect both of these possible "pulls" using two fenwick trees `inside` and `outside`, with `inside` storing a capped, fixed contribution, and `outside` storing a coefficient to apply to future query positions.

### Operations

* `fenwick_tree<T>(x)`: Builds a fenwick tree of length x, or from the vector x. The complexity is $O(n)$ in both cases.
* `add(l, r, x)`: Adds x to the interval $[l, r]$. $O(\log{n})$
* `sum(l, r)`: Returns the sum of the interval $[l, r]$. $O(\log{n})$.