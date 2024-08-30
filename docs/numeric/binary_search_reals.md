---
title: Binary Search on Reals
documentation_of: ../../numeric/binary_search_reals.hpp
---

### Overview

Given a monotonic boolean function taking in a real position value x, calculates the first/last x that returns `true` in $O(\log{(hi - lo)}) * T_f$ (bounded by 64 in this `double` implementation).

### Usage

* `bsmin(lo, hi, f)`: Returns the min $x \in [lo, hi]$ such that $f(x)$, or $hi + 1$ if all false. 
* `bsmax(lo, hi, f)`: Returns the max $x \in [lo, hi]$ such that $f(x)$, or $lo - 1$ if all false.