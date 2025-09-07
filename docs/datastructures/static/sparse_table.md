---
title: Sparse Table
documentation_of: ./src/datastructures/static/sparse_table.h
---

Static range minimum/maximum queries with $O(1)$ query time using sparse table.

## Operations

- `SparseTable(arr, op)`: Construct from array with associative operation `op`
- `query(l, r)`: Query range `[l, r]` with the given operation

## Complexity

- Construction: $O(n \log n)$
- Query: $O(1)$
- Space: $O(n \log n)$

## Usage

```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9, 2};

// Range minimum queries
auto min_op = [](int a, int b) { return min(a, b); };
SparseTable<int> st(arr, min_op);
int range_min = st.query(1, 5); // Min of {1, 4, 1, 5, 9}

// Range maximum queries
auto max_op = [](int a, int b) { return max(a, b); };
SparseTable<int> st_max(arr, max_op);
int range_max = st_max.query(2, 6);
```

## Notes

Operation must be idempotent: `op(x, x) = x`. Common operations: min, max, gcd.

**Implementation Details**: Uses 2D table where `table[i][j]` stores the result for range of length `2^i` starting at position `j`. Query combines two overlapping ranges of length `2^k` where `k = floor(log2(r-l+1))`, leveraging idempotency to handle the overlap safely.