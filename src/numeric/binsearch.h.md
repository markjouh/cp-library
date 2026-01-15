---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/string/enumerate_palindromes.test.cpp
    title: src/verify/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/numeric/binsearch.h\"\ntemplate <class T, class U>\n\
    T bsmin(T lo, T hi, U f) {\n  assert(lo <= hi);\n  hi++;\n  for (T i = T(1) <<\
    \ __lg(hi - lo); i > 0; i >>= 1) {\n    hi -= (hi - i >= lo && f(hi - i)) * i;\n\
    \  }\n  return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f)\
    \ {\n  assert(lo <= hi);\n  lo--;\n  for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n    lo += (lo + i <= hi && f(lo + i)) * i;\n  }\n  return lo;\n\
    }\n"
  code: "template <class T, class U>\nT bsmin(T lo, T hi, U f) {\n  assert(lo <= hi);\n\
    \  hi++;\n  for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n    hi -= (hi\
    \ - i >= lo && f(hi - i)) * i;\n  }\n  return hi;\n}\n\ntemplate <class T, class\
    \ U>\nT bsmax(T lo, T hi, U f) {\n  assert(lo <= hi);\n  lo--;\n  for (T i = T(1)\
    \ << __lg(hi - lo); i > 0; i >>= 1) {\n    lo += (lo + i <= hi && f(lo + i)) *\
    \ i;\n  }\n  return lo;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/numeric/binsearch.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/string/enumerate_palindromes.test.cpp
  - src/verify/library_checker/data_structure/range_kth_smallest.test.cpp
documentation_of: src/numeric/binsearch.h
layout: document
title: Binary Search
---

Generic binary search for finding boundaries in monotonic functions.

## Operations

- `bsmax(lo, hi, f)`: Find largest `x` in `[lo, hi]` where `f(x)` is true
- `bsmin(lo, hi, f)`: Find smallest `x` in `[lo, hi]` where `f(x)` is true

## Complexity

- Time: $O(\log(hi - lo) \times T_f)$ where $T_f$ is time for function evaluation
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
