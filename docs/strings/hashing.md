---
title: Polynomial Rolling Hash
documentation_of: ./src/strings/hashing.h
---

Polynomial rolling hash with 64-bit modulus $2^{61} - 1$ and randomized base for collision-resistant string hashing.

## Operations

- `hash_one(x)`: Hash single value of supported type
- `hash(args...)`: Hash multiple arguments  
- `add(a, b)`, `sub(a, b)`, `mul(a, b)`: Modular arithmetic
- `RollingHash(s)`: Construct from string/container
- `get(l, r)`: Get hash of `s[l..r-1]`
- `get_all()`: Get hash of entire string
- `operator+(other)`: Concatenate hash segments (`SegHash`)

## Complexity

- Construction: $O(n)$
- Query: $O(1)$
- Space: $O(n)$

## Usage

```cpp
string s = "hello";
RollingHash rh(s);
auto full_hash = rh.get_all();
auto substr_hash = rh.get(1, 4); // "ell"

// Multi-argument hashing
auto combined = hashing::hash(42, "test", vector<int>{1, 2, 3});

// Hash concatenation
SegHash seg1 = rh.get(0, 2);
SegHash seg2 = rh.get(2, 5);
SegHash combined = seg1 + seg2;
```

## Notes

Uses randomized base with time-based seeding. Supports strings, containers, tuples, and primitives.