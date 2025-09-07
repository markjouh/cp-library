---
title: Simulated Annealing
documentation_of: ./src/heuristic/simulated_annealing.h
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