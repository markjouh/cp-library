---
title: Euler Tour
documentation_of: ../../graphs/euler_tour.hpp
---

### Overview

Given a tree, computes an euler tour.

In a euler tour, if each vertex $v$ is placed at $tin_v$, the interval $[tin_v, tout_v)$ contains exactly the subtree rooted at $v$.

### Usage

* `EulerTour(g, root)`: Computes an euler tour. $O(n)$