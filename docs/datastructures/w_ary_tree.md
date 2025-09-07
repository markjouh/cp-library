---
title: W-ary Tree
documentation_of: ./src/datastructures/w_ary_tree.h
---

Generalized segment tree with configurable branching factor for optimized cache performance.

## Operations

- `WAryTree<W>(n)`: Create W-ary tree with branching factor `W`
- `set(pos, val)`: Set position to value  
- `query(l, r)`: Query range with specified operation

## Complexity

- All operations: $O(\log_W n)$
- Space: $O(n)$

## Usage

```cpp
// 4-ary tree (quaternary)
WAryTree<4> wtree(n);
wtree.set(pos, val);
int result = wtree.query(l, r);
```

## Notes

Higher branching factor reduces tree height but increases work per node. Optimal W depends on cache characteristics and operation complexity.

**Cache Optimization**: For typical competitive programming constraints ($n \leq 10^5$), $W = 4$ or $W = 8$ often performs better than binary trees due to improved cache locality, despite higher constant factors. The optimal choice depends on whether the bottleneck is memory access patterns or computational complexity.