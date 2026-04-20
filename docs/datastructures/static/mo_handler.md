---
title: Mo's Algorithm Handler
documentation_of: ./src/datastructures/static/mo_handler.h
---

Mo's algorithm for offline range queries, sorting queries to minimize pointer movement.

## Operations

- `MoHandler<K>()`: Create empty handler with compile-time block size `K` (typically $\sqrt{n}$)
- `add(l, r)`: Register range query `[l, r]`
- `run(add_l, del_l, add_r, del_r, answer)`: Process queries with separate callbacks for each endpoint
- `run(add, del, answer)`: Overload when adding/removing from either end uses the same callback

## Complexity

- Time: $O((n + q) \sqrt{n} \cdot T)$ with $K = \sqrt{n}$, where $q$ is the number of queries and $T$ is the cost of a single boundary operation
- Space: $O(q)$

## Usage

```cpp
MoHandler<320> mo;  // K ~= sqrt(n) for n ~= 100000
for (auto [l, r] : queries) {
  mo.add(l, r);
}

vector<int> ans(queries.size());
// Symmetric case: add/remove don't depend on which end
mo.run(
  [&](int i) { /* include a[i] */ },
  [&](int i) { /* exclude a[i] */ },
  [&](int idx) { ans[idx] = current_answer; }
);
```

## Notes

The four-callback overload is for structures where the side matters: for example, maintaining a running value that depends on insertion order, or a deque-like structure where pushing to the front differs from pushing to the back. When the two ends are interchangeable, pass the same add and delete lambda via the three-callback overload.
