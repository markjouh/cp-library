---
title: Simulated Annealing
documentation_of: ./src/heuristic/simulated_annealing.h
---

Template for simulated annealing optimization with time-based temperature control.

## Structure

Define a `State` struct with:
- `State()`: Constructor for initial state
- `edit()`: Apply random modification to current state
- `undo()`: Revert the last `edit()` call
- `eval()`: Return cost of current state (lower is better)

## Operations

- `anneal(ms)`: Run simulated annealing for `ms` milliseconds, returns best state found

## Complexity

- Time: Runs for specified milliseconds
- Space: $O(\text{state\_size})$

## Usage

```cpp
struct State {
  vector<int> perm;
  int last_i, last_j;

  State() : perm(n) {
    iota(perm.begin(), perm.end(), 0);
  }

  void edit() {
    last_i = rng(n);
    last_j = rng(n);
    swap(perm[last_i], perm[last_j]);
  }

  void undo() {
    swap(perm[last_i], perm[last_j]);
  }

  int eval() const {
    return calculate_cost(perm);
  }
};

State best = anneal(1900);  // Run for 1900ms
```

## Notes

Temperature decreases exponentially from `temp_start` to `temp_end`. Acceptance probability follows $e^{-\Delta E / T}$. Adjust `temp_start` and `temp_end` constants in the code for your problem.
