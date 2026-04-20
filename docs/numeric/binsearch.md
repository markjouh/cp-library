---
title: Binary Search
documentation_of: ./src/numeric/binsearch.h
---

Generic binary search for finding boundaries in monotonic functions.

## Operations

- `bsmax(lo, hi, f)`: Find largest `x` in `[lo, hi]` where `f(x)` is true
- `bsmin(lo, hi, f)`: Find smallest `x` in `[lo, hi]` where `f(x)` is true

## Complexity

- Time: $O(\log(hi - lo) \cdot T_f)$ where $T_f$ is the time for one evaluation of `f`
- Space: $O(1)$

## Usage

```cpp
// Find largest x where x^2 <= 100
int result = bsmax(0, 100, [](int x) {
  return x * x <= 100;
});  // returns 10

// Find smallest x where x^2 >= 50
int result2 = bsmin(0, 100, [](int x) {
  return x * x >= 50;
});  // returns 8
```

## Notes

For `bsmax`, function `f` must be monotonic: if `f(x)` is true, then `f(y)` is true for all `y <= x`. For `bsmin`, the opposite: if `f(x)` is true, then `f(y)` is true for all `y >= x`. Uses bit manipulation for efficient boundary detection.
