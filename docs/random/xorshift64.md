---
title: XorShift64 Random Number Generator
documentation_of: ./src/random/xorshift64.h
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