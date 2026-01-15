---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/heuristic/simulated_annealing.h\"\nstruct State {\n\
    \  // ...\n\n  State() {\n  }\n\n  void edit() {\n  }\n\n  void undo() {\n  }\n\
    \n  int eval() const {\n  }\n};\n\nState anneal(int ms) {\n  const double temp_start\
    \ = 10, temp_end = 0.001;\n  clock_t start = clock();\n\n  State cur;\n  int cur_cost\
    \ = cur.eval(), new_cost, mn_cost = cur_cost;\n  while (true) {\n    double elapsed_frac\
    \ = double(clock() - start) / CLOCKS_PER_SEC * 1000 / ms;\n    if (elapsed_frac\
    \ >= 1) {\n      break;\n    }\n\n    cur.edit();\n    new_cost = cur.eval();\n\
    \n    double temp = temp_start * pow(temp_end / temp_start, elapsed_frac);\n \
    \   if (new_cost < cur_cost || double(rand()) / RAND_MAX < exp((cur_cost - new_cost)\
    \ / temp)) {\n      cur_cost = new_cost;\n    } else {\n      cur.undo();\n  \
    \  }\n\n    mn_cost = min(mn_cost, cur_cost);\n  }\n  return cur;\n}\n"
  code: "struct State {\n  // ...\n\n  State() {\n  }\n\n  void edit() {\n  }\n\n\
    \  void undo() {\n  }\n\n  int eval() const {\n  }\n};\n\nState anneal(int ms)\
    \ {\n  const double temp_start = 10, temp_end = 0.001;\n  clock_t start = clock();\n\
    \n  State cur;\n  int cur_cost = cur.eval(), new_cost, mn_cost = cur_cost;\n \
    \ while (true) {\n    double elapsed_frac = double(clock() - start) / CLOCKS_PER_SEC\
    \ * 1000 / ms;\n    if (elapsed_frac >= 1) {\n      break;\n    }\n\n    cur.edit();\n\
    \    new_cost = cur.eval();\n\n    double temp = temp_start * pow(temp_end / temp_start,\
    \ elapsed_frac);\n    if (new_cost < cur_cost || double(rand()) / RAND_MAX < exp((cur_cost\
    \ - new_cost) / temp)) {\n      cur_cost = new_cost;\n    } else {\n      cur.undo();\n\
    \    }\n\n    mn_cost = min(mn_cost, cur_cost);\n  }\n  return cur;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/heuristic/simulated_annealing.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/heuristic/simulated_annealing.h
layout: document
title: Simulated Annealing
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
