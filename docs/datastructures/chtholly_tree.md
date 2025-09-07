---
title: Chtholly Tree
documentation_of: ./src/datastructures/chtholly_tree.h
---

A data structure that represents an array as a set of disjoint intervals of equal values. Also known as an Old Driver Tree (ODT).

## Operations

- `ChthollyTree(arr)`: Construct from array
- `ChthollyTree(n, val)`: Construct size `n` with value `val`
- `traverse(l, r, f)`: Apply function `f` to all segments in `[l, r]`
- `apply(l, r, f)`: Apply transformation `f` to values in `[l, r]`

## Complexity
- **Amortized (with random data):** $O(\log n)$ per operation.
- **Worst-case:** $O(k \log s)$, where `s` is the total number of segments and `k` is the number of segments in the range. This can be as bad as $O(n \log n)$ if `s` and `k` become linear in `n`.
- **Space:** $O(s)$, where `s` is the number of segments.

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
The efficiency of this structure hinges on the number of segments (`s`) remaining small. Its favorable amortized performance is achieved only with random data or a high frequency of range-assignment operations, which merge segments and reduce `s`.

**Performance Warning**: The worst-case performance is poor. Adversarial inputs (e.g., point updates that repeatedly split segments) can cause the number of segments to grow to $O(n)$. In such cases, an operation over a range containing `k` segments takes $O(k \log n)$ time. This structure should only be used when the problem guarantees random inputs or a structure that prevents segment proliferation. It is not a general-purpose replacement for a segment tree.
