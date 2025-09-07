---
title: Ordered Set
documentation_of: ./src/datastructures/ordered_set.h
---

GNU PBDS ordered set with order statistics (find by rank, rank by value).

## Operations

- `insert(x)`: Insert element `x`
- `erase(x)`: Remove element `x`
- `find_by_order(k)`: Find k-th smallest element (0-indexed)
- `order_of_key(x)`: Count elements strictly less than `x`

## Complexity

- All operations: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
ordered_set<int> os;
os.insert(5);
os.insert(3);
os.insert(7);

// Find 1st smallest (0-indexed)
auto it = os.find_by_order(1); // Points to 5

// Count elements < 6
int count = os.order_of_key(6); // Returns 2
```

## Notes

Typedef for GNU PBDS tree. Maintains elements in sorted order with efficient rank operations.