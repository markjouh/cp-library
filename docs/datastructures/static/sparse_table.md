---
title: Sparse Table
documentation_of: ./src/datastructures/static/sparse_table.h
---

Static range minimum/maximum queries with $O(1)$ query time using sparse table.

## Operations

- `SparseTable<T, op>(arr)`: Construct from array with idempotent operation `op`
- `query(l, r)`: Query range `[l, r]` with the given operation

## Provided Operations

- `min_op<T>`: Returns minimum of two values
- `max_op<T>`: Returns maximum of two values

## Complexity

- Construction: $O(n \log n)$
- Query: $O(1)$
- Space: $O(n \log n)$

## Usage

```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9, 2};

// Range minimum queries
SparseTable<int, min_op<int>> st(arr);
int range_min = st.query(1, 5);  // Min of arr[1..5]

// Range maximum queries
SparseTable<int, max_op<int>> st_max(arr);
int range_max = st_max.query(2, 6);
```

## Notes

Operation must be idempotent: `op(x, x) = x`. Common operations: min, max, gcd, bitwise AND/OR.
