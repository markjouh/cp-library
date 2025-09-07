---
title: Chtholly Tree
documentation_of: ./src/datastructures/chtholly_tree.h
---

ODT (Old Driver Tree) for efficient range operations on arrays with many consecutive equal values.

## Operations

- `ChthollyTree(arr)`: Construct from array
- `ChthollyTree(n, val)`: Construct size `n` with value `val`
- `traverse(l, r, f)`: Apply function `f` to all segments in `[l, r]`
- `apply(l, r, f)`: Apply transformation `f` to values in `[l, r]`

## Complexity

- Operations: $O(\log n + k)$ where $k$ is segments in range
- Space: $O(s)$ where $s$ is number of segments

## Usage

```cpp
vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
ChthollyTree<int> ct(arr);

// Set range [2, 5] to 10
ct.apply(2, 5, [](int x) { return 10; });

// Sum values in range [0, 6]
int sum = 0;
ct.traverse(0, 6, [&](auto it) {
  sum += it->val * (it->r - it->l + 1);
});
```

## Notes

Uses `std::set` to maintain segments. Automatically splits and merges segments based on value equality.

**Performance Warning**: The $O(\log n + k)$ complexity only amortizes to $O(\log n)$ per operation when interval bounds are random. In adversarial cases where intervals have structured patterns, performance may degrade significantly.