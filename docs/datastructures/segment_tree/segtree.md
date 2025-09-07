---
title: Segment Tree
documentation_of: ./src/datastructures/segment_tree/segtree.h
---

Supports efficient range queries and point updates using associative operations.

## Operations

- `Segtree<T, op, id>(n)`: Construct with size `n`
- `Segtree<T, op, id>(arr)`: Construct from array
- `set(p, val)`: Set element at position `p` to `val`
- `get(p)`: Get current value at position `p`
- `query(l, r)`: Query aggregate value over range `[l, r]`

## Complexity

- Construction: $O(n)$
- Update: $O(\log n)$
- Query: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
auto add = [](int a, int b) { return a + b; };
auto zero = []() { return 0; };

// Range sum queries
Segtree<int, add, zero> st(n);
st.set(2, 10);
int sum = st.query(1, 4);

// Range min queries
auto min_op = [](int a, int b) { return min(a, b); };
auto inf = []() { return INT_MAX; };
Segtree<int, min_op, inf> min_st(arr);
```

## Notes

Operation must be associative. Identity element satisfies `op(x, id()) = x`.