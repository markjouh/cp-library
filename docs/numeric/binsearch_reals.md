---
title: Binary Search on Reals
documentation_of: ./src/numeric/binsearch_reals.h
---

Binary search on floating-point values with bit-level precision.

## Operations

- `bsmax_reals(lo, hi, f)`: Find largest `x` in `[lo, hi]` where `f(x)` is true
- `bsmin_reals(lo, hi, f)`: Find smallest `x` in `[lo, hi]` where `f(x)` is true

## Complexity

- Time: $O(64 \times T_f)$ where $T_f$ is function evaluation time
- Space: $O(1)$

## Usage

```cpp
// Find square root of 2
double sqrt2 = bsmax_reals(0.0, 2.0, [](double x) {
  return x * x <= 2.0;
});

// Find smallest x where x^3 >= 10
double cbrt10 = bsmin_reals(0.0, 10.0, [](double x) {
  return x * x * x >= 10.0;
});
```

## Notes

Uses bit-level binary search on the IEEE 754 representation of doubles, giving maximum precision without needing an epsilon parameter. Iterates over the 64 bits of the double representation.
