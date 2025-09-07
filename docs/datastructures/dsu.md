---
title: Disjoint Set Union (DSU)
documentation_of: ./src/datastructures/dsu.h
---

Union-Find data structure with path compression and union by size optimization.

## Operations

- `DSU(n)`: Construct for `n` elements `(0` to `n-1)`
- `find(x)`: Find representative of set containing `x`
- `join(x, y)`: Merge sets containing `x` and `y`, return `true` if different sets
- `size(x)`: Get size of set containing `x`

## Complexity

- All operations: $O(\alpha(n))$ amortized
- Space: $O(n)$

## Usage

```cpp
DSU dsu(n);

// Check if in same set
if (dsu.find(x) == dsu.find(y)) {
  // Same set
}

// Merge sets
if (dsu.join(x, y)) {
  // Were in different sets, now merged
}

int setSize = dsu.size(x);
```

## Notes

$\alpha(n)$ is inverse Ackermann function, effectively constant. Uses union by size and path compression.