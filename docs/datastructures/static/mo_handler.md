---
title: Mo's Algorithm Handler
documentation_of: ./src/datastructures/static/mo_handler.h
---

Mo's algorithm for offline range queries with efficient query reordering.

## Operations

- `MoHandler(n)`: Initialize for array of size `n`
- `add_query(l, r)`: Add range query `[l, r]`
- `process(add_fn, remove_fn, answer_fn)`: Process all queries with given functions

## Complexity

- Time: $O((n + q) \sqrt{n})$ where $q$ is number of queries
- Space: $O(q)$

## Usage

```cpp
MoHandler mo(n);
for (auto [l, r] : queries) {
  mo.add_query(l, r);
}

vector<int> answers(queries.size());
mo.process(
  [&](int pos) { /* add element at pos */ },
  [&](int pos) { /* remove element at pos */ },
  [&](int query_id) { answers[query_id] = current_answer; }
);
```

## Notes

Reorders queries to minimize pointer movements. Requires add/remove operations to be efficient and reversible.

**Block Size Optimization**: Uses block size of $\sqrt{n}$ for optimal $O((n + q)\sqrt{n})$ complexity. For arrays with $n > 10^5$, consider tuning block size to $\sqrt{n} \times c$ where $c \approx 1.5$ for better cache performance, though this changes the theoretical complexity slightly.