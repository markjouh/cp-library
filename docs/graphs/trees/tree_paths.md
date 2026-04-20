---
title: Tree Paths
documentation_of: ./src/graphs/trees/tree_paths.h
---

Binary lifting over a weighted tree, aggregating edge values along paths between vertices.

## Operations

- `TreePaths<T, op, id>(g, root)`: Build from weighted adjacency list `g` (edges are `{neighbor, weight}`), rooted at `root` (default: 0)
- `query(x, y)`: Aggregate edge values along the path from `x` to `y`

## Template Parameters

- `T`: Value type
- `op`: Associative binary function `(T, T) -> T`
- `id`: Function `() -> T` returning the identity for `op`

## Complexity

- Construction: $O(n \log n)$
- Query: $O(\log n)$
- Space: $O(n \log n)$

## Usage

{% raw %}
```cpp
auto op = [](int a, int b) { return a + b; };
auto id = []() { return 0; };

vector<vector<pair<int, int>>> g = {{{1, 3}, {2, 5}}, {{0, 3}}, {{0, 5}}};
TreePaths<int, op, id> tp(g, 0);

int path_sum = tp.query(1, 2);  // 3 + 5 = 8
```
{% endraw %}

## Notes

`(T, op)` must form a monoid with identity `id()`. Edge values, not vertex values, are aggregated.
