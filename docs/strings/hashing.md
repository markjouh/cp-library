---
title: Polynomial Rolling Hash
documentation_of: ./src/strings/hashing.h
---

Polynomial rolling hash with 64-bit modulus $2^{61} - 1$ and randomized base for collision-resistant string hashing.

## Operations

- `hashing::hash_one(x)`: Hash single value (primitives, containers, tuples)
- `hashing::hash(args...)`: Hash multiple arguments
- `hashing::add(a, b)`, `sub(a, b)`, `mul(a, b)`: Modular arithmetic helpers
- `RollingHash(s)`: Construct from string/container
- `get(l, r)`: Get hash of substring `s[l..r]` (inclusive)
- `get_all()`: Get hash of entire string
- `SegHash + SegHash`: Concatenate hash segments

## Complexity

- Construction: $O(n)$
- Query: $O(1)$
- Space: $O(n)$

## Usage

```cpp
using namespace hashing;

string s = "hello";
RollingHash rh(s);
SegHash full = rh.get_all();
SegHash sub = rh.get(1, 3);  // "ell" (indices 1, 2, 3)

// Check if two substrings are equal
if (rh.get(0, 1) == rh.get(3, 4)) { /* "he" == "lo"? */ }

// Hash concatenation
SegHash combined = rh.get(0, 1) + rh.get(2, 4);  // "he" + "llo"

// Multi-argument hashing
auto h = hashing::hash(42, "test", vector<int>{1, 2, 3});
```

## Notes

Uses randomized base with time-based seeding. Supports strings, vectors, tuples, pairs, and primitives.
