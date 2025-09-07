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

Metaheuristic optimization algorithm using temperature-based acceptance probability.

## Operations

- `SimulatedAnnealing(initial_temp, cooling_rate)`: Initialize with temperature parameters
- `optimize(initial_state, neighbor_fn, cost_fn, max_iterations)`: Run optimization

## Complexity

- Time: $O(\text{iterations} \times T_{\text{neighbor}} \times T_{\text{cost}})$
- Space: $O(\text{state\_size})$

## Usage

```cpp
// Minimize a cost function
auto neighbor = [](State s) { return get_random_neighbor(s); };
auto cost = [](State s) { return calculate_cost(s); };

SimulatedAnnealing sa(1000.0, 0.95);
State best = sa.optimize(initial_state, neighbor, cost, 10000);
```

## Notes

Accepts worse solutions with probability decreasing over time. Effective for avoiding local optima in optimization problems.

**Temperature Tuning**: Acceptance probability follows $e^{-\Delta E / T}$ where $\Delta E$ is cost difference and $T$ is temperature. Initial temperature should allow ~80% acceptance of random moves. Cooling rate of 0.95-0.99 works well for most problems. Too fast cooling causes premature convergence; too slow wastes computation.