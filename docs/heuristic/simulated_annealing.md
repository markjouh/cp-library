---
title: Simulated Annealing
documentation_of: ./src/heuristic/simulated_annealing.h
---

Simulated annealing optimization driven by wall-clock time with exponentially decaying temperature.

## Operations

- `anneal(ms)`: Run annealing for `ms` milliseconds and return the final `State`

## State Requirements

User defines a `State` struct providing:
- `State()`: Initial state
- `edit()`: Apply a random mutation
- `undo()`: Revert the last `edit()`
- `eval() const`: Return current cost (lower is better)

## Complexity

- Time: $O(\text{ms})$ wall-clock, with cost per iteration dominated by `edit` and `eval`
- Space: $O(1)$ beyond the state itself

## Usage

```cpp
struct State {
  vector<int> perm;
  int i, j;

  State() : perm(n) { iota(perm.begin(), perm.end(), 0); }
  void edit() { i = rng(n); j = rng(n); swap(perm[i], perm[j]); }
  void undo() { swap(perm[i], perm[j]); }
  int eval() const { return cost(perm); }
};

State result = anneal(1900);
```

## Notes

Temperature decays exponentially from `temp_start` to `temp_end`; acceptance probability for worsening moves is $e^{-\Delta / T}$. Returns the final state, not the best seen; track the best inside `State` if needed. Tune `temp_start` and `temp_end` constants in the source for the problem.
