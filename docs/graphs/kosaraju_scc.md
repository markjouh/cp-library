---
title: Kosaraju's SCC
documentation_of: ../../graphs/kosaraju_scc.hpp
---

### Overview

Let $tin$ and $tout$ be the result of DFSing on a directed graph $G$ and storing the enter and exit times of each vertex. We can prove using simple casework that if $u$ has an edge to $v$ in the condensation graph, $tout_u > tout_v$. Thus, the component with the maximum $tout$ must be a source node in the condensation graph. If we build the transpose graph of $G$, the set of reachable vertices from the maximal $tout$ is exactly its SCC, since reachability from within the same component doesn't change, but we're no longer able to exit the component. Repeat this isolate/explore process on the maximal unvisited $tout$ and we have our SCCs.

Produces a condensation graph with edges between component ids `c_adj`, as well as a set of member vertices for each component `members`.

### Usage

* `KosarajuSCC(g)`: Computes the SCCs of g and builds a condensation graph. $O(n)$