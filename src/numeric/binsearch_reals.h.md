---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/numeric/binsearch_reals.h\"\ntemplate <class T>\ndouble\
    \ bsmin_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t) >=\
    \ sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo),\
    \ r = reinterpret_cast<uint64_t&>(hi) + 1;\n  for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\n\
    double bsmax_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n  for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n"
  code: "template <class T>\ndouble bsmin_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo),\
    \ r = reinterpret_cast<uint64_t&>(hi) + 1;\n  for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\n\
    double bsmax_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n  for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/numeric/binsearch_reals.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numeric/binsearch_reals.h
layout: document
title: Binary Search on Reals
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