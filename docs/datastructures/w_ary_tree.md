---
title: W-ary Tree
documentation_of: ./src/datastructures/w_ary_tree.h
---

Integer set over a fixed universe $[0, 64^L)$, supporting flip, min, and max in near-constant time. Analogous to a van Emde Boas tree with branching factor 64, using a 64-bit mask at each level.

## Operations

- `WAryTree<L>()`: Construct empty set over $[0, 64^L)$
- `flip(p)`: Toggle presence of `p`
- `get_min()`: Return minimum element
- `get_max()`: Return maximum element

## Complexity

- All operations: $O(L) = O(\log_{64} N)$
- Space: $O(N)$

## Usage

```cpp
WAryTree<3> s;  // universe [0, 262144)

s.flip(100);
s.flip(2000);
s.flip(50);

int lo = s.get_min();  // 50
int hi = s.get_max();  // 2000

s.flip(50);            // remove 50
```

## Notes

For typical contest sizes (up to $\sim 10^7$), `L` is at most 4. Undefined behavior if `get_min` or `get_max` is called on an empty set. Prefer over `std::set<int>` when the universe is small and min/max queries dominate.
