---
title: XorShift Random Number Generator
documentation_of: ./src/random/xorshift64.h
---

Fast pseudo-random number generator using XorShift algorithm with time-based seeding.

## Operations

- `rng()`: Generate random 64-bit unsigned integer
- `rng(n)`: Generate random integer in `[0, n)`
- `rng(l, r)`: Generate random integer in `[l, r)`
- `shuffle(a)`: Randomly shuffle vector `a` in-place

## Complexity

- All operations: $O(1)$
- `shuffle`: $O(n)$
- Space: $O(1)$

## Usage

```cpp
// Generate random 64-bit integers
uint64_t rand1 = rng();
uint64_t rand2 = rng();

// Generate random integer in [0, 100)
uint64_t rand_bounded = rng(100);

// Generate random integer in [10, 20)
int64_t rand_range = rng(10, 20);

// Shuffle a vector
vector<int> v = {1, 2, 3, 4, 5};
shuffle(v);
```

## Notes

Uses time-based seeding for non-deterministic behavior. Much faster than `std::mt19937` for competitive programming.
