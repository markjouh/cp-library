---
title: Ordered Set
documentation_of: ./src/datastructures/ordered_set.h
---

Sorted set with order-statistic queries, built on the PBDS tree. `OrderedMultiset` wraps it to support duplicates.

## Operations

`ordered_set<T>` (PBDS tree):
- `insert(x)`, `erase(x)`: Insert or remove `x`
- `find_by_order(k)`: Iterator to the `k`-th smallest element (0-indexed)
- `order_of_key(x)`: Count of elements strictly less than `x`

`OrderedMultiset<T>`:
- `insert(x)`: Insert `x` (duplicates allowed)
- `extract(x)`: Remove one occurrence of `x`
- `find_by_order(k)`: `k`-th smallest value
- `order_of_key(x)`: Count of elements strictly less than `x`

## Complexity

- All operations: $O(\log n)$
- Space: $O(n)$

## Usage

```cpp
ordered_set<int> os;
os.insert(5);
os.insert(3);
os.insert(7);

int kth = *os.find_by_order(1);  // 5
int rank = os.order_of_key(6);   // 2

OrderedMultiset<int> ms;
ms.insert(4);
ms.insert(4);
ms.extract(4);  // still contains one 4
```

## Notes

`ordered_set<T>` rejects duplicates; `OrderedMultiset` pairs each value with a unique timestamp internally to allow them.
