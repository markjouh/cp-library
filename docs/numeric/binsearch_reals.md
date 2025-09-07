---
title: Binary Search on Reals
documentation_of: ./src/numeric/binsearch_reals.h
---

Binary search for real-valued functions with specified precision.

## Operations

- `binsearch_reals(l, r, f, eps)`: Find value in `[l, r]` where `f(x)` transitions from true to false within precision `eps`

## Complexity

- Time: $O(\log((r - l) / \text{eps}) \times T_f)$ where $T_f$ is function evaluation time
- Space: $O(1)$

## Usage

```cpp
// Find square root of 2
double sqrt2 = binsearch_reals(0.0, 2.0, [](double x) {
  return x * x <= 2.0;
}, 1e-9);

// Find intersection point
double intersection = binsearch_reals(0.0, 10.0, [](double x) {
  return f(x) <= g(x);
}, 1e-12);
```

## Notes

Function must be monotonic. Continues until interval size is less than `eps`.