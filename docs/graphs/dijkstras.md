---
title: Dijkstra's Shortest Paths
documentation_of: ../../graphs/dijkstras.hpp
---

### Overview

Given a graph $G = (V, E)$, constructs the shortest paths from a specified starting vertex $s$ to each vertex reachable from $s$ in $O(|E| + |V| \log{V})$.

### Usage

* `dijkstras(g, s = 0)`: Returns a pair `dist, from`, the lengths of the shortest paths from s and the parent array of the shortest path tree rooted at s, respectively.