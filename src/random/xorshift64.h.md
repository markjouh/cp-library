---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://isaku-wada.my.coocan.jp/rand/rand.html
    - https://github.com/maspypy/library/blob/bd963151adcd2ad29642a2dcea65a15420d1767d/random/base.hpp
  bundledCode: "#line 1 \"src/random/xorshift64.h\"\n// http://isaku-wada.my.coocan.jp/rand/rand.html\n\
    // https://github.com/maspypy/library/blob/bd963151adcd2ad29642a2dcea65a15420d1767d/random/base.hpp\n\
    \nuint64_t rng() {\n  static uint64_t x = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 0x8cde9e0f1d3b04d7;\n  x ^= x << 7;\n  x ^= x >> 9;\n  return x;\n}\n\nuint64_t\
    \ rng(uint64_t n) {\n  return rng() % n;\n}\n\nint64_t rng(int64_t l, int64_t\
    \ r) {\n  return l + rng() % (r - l);\n}\n\ntemplate <class T>\nvoid shuffle(vector<T>\
    \ &a) {\n  for (int i = 0; i < sz(a); i++) {\n    int j = rng() % (i + 1);\n \
    \   if (i != j) {\n      swap(a[i], a[j]);\n    }\n  }\n}\n"
  code: "// http://isaku-wada.my.coocan.jp/rand/rand.html\n// https://github.com/maspypy/library/blob/bd963151adcd2ad29642a2dcea65a15420d1767d/random/base.hpp\n\
    \nuint64_t rng() {\n  static uint64_t x = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 0x8cde9e0f1d3b04d7;\n  x ^= x << 7;\n  x ^= x >> 9;\n  return x;\n}\n\nuint64_t\
    \ rng(uint64_t n) {\n  return rng() % n;\n}\n\nint64_t rng(int64_t l, int64_t\
    \ r) {\n  return l + rng() % (r - l);\n}\n\ntemplate <class T>\nvoid shuffle(vector<T>\
    \ &a) {\n  for (int i = 0; i < sz(a); i++) {\n    int j = rng() % (i + 1);\n \
    \   if (i != j) {\n      swap(a[i], a[j]);\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/random/xorshift64.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/random/xorshift64.h
layout: document
title: XorShift64 Random Number Generator
---

Fast pseudo-random number generator using XorShift algorithm with 64-bit state.

## Operations

- `XorShift64()`: Initialize with time-based seed
- `XorShift64(seed)`: Initialize with custom seed
- `operator()`: Generate next random 64-bit integer
- `operator()(n)`: Generate random integer in `[0, n)`

## Complexity

- All operations: $O(1)$
- Space: $O(1)$

## Usage

```cpp
XorShift64 rng;

// Generate random 64-bit integers
uint64_t rand1 = rng();
uint64_t rand2 = rng();

// Generate random integer in [0, 100)
int rand_bounded = rng(100);

// Custom seed
XorShift64 seeded_rng(12345);
```

## Notes

Period of $2^{64} - 1$. Much faster than `std::mt19937` for competitive programming needs.