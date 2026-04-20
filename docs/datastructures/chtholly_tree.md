---
title: Chtholly Tree
documentation_of: ./src/datastructures/chtholly_tree.h
---

Represents an array as a set of disjoint equal-value intervals. Also known as an Old Driver Tree (ODT).

## Operations

- `ChthollyTree(n, v)`: Construct size `n` initialized to value `v`
- `ChthollyTree(arr)`: Construct from array
- `traverse(l, r, f)`: Apply `f` to each segment iterator overlapping `[l, r]`
- `apply(l, r, f)`: Apply value transform `f` to `[l, r]`, merging adjacent equal segments

## Complexity

- Amortized (random data or frequent range assignments): $O(\log n)$ per operation
- Worst case: $O(k \log s)$ where `s` is the current segment count and `k` is segments touched; `s` and `k` can be $\Theta(n)$
- Space: $O(s)$

## Usage

```cpp
vector<int> arr = {1, 1, 2, 2, 2, 3, 3};
ChthollyTree<int> ct(arr);

ct.apply(2, 5, [](int x) { return 10; });

int sum = 0;
ct.traverse(0, 6, [&](auto it) {
  sum += it->val * (it->r - it->l + 1);
});
```

## Notes

Efficient only when the number of segments stays small. Range-assignment operations merge segments, keeping the amortized bound valid. On adversarial inputs with many point splits, performance degrades to linear. Not a general segment-tree replacement.
