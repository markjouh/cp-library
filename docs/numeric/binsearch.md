---
title: Binary Search
documentation_of: ./src/numeric/binsearch.h
---

Generic binary search for finding boundaries in monotonic functions.

## Operations

- `binsearch(l, r, f)`: Find largest `x` in `[l, r]` where `f(x)` is true

## Complexity

- Time: $O(\log(r - l) \times T_f)$ where $T_f$ is time for function evaluation
- Space: $O(1)$

## Usage

```cpp
// Find largest x where x^2 <= 100
int result = binsearch(0, 100, [](int x) {
  return x * x <= 100;
});

// Find insertion point in sorted array
auto pos = binsearch(0, (int)arr.size(), [&](int i) {
  return i >= arr.size() || arr[i] < target;
});
```

## Notes

Function `f` must be monotonic: if `f(x)` is true, then `f(y)` is true for all `y <= x`.

**Implementation Details**: For integer ranges, uses bit manipulation approach with rightward shifts for efficient boundary detection. The search space is halved using `(l + r + 1) / 2` to avoid infinite loops on adjacent boundaries.