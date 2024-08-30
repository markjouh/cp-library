---
title: Centroid Decomposition
documentation_of: ../../graphs/centroid_decomposition.hpp
---

### Overview

A centroid of a tree is a vertex that splits the tree into subtrees of size $\leq \frac{n}{2}$ if removed. By this property, recursively splitting a tree by a centroid creates $O(\log{n})$ layers of subgraphs of $O(n)$ total size each. Centroid decomposition is a divide and conquer technique for trees that uses this idea.

I can't list all its possible applications, but this is a common usage I've personally encountered often.

Broadly, if the objective is to consider all solutions, CD lets us reframe the problem into:
1. Root the tree at a centroid, and consider all solutions that depend on the root or objects belonging to different child subtrees of the root.
2. For the purposes of considering the remaining solutions, the root is irrelevant, and all of its child subtrees are now independent from each other. Break the tree apart from the root and solve the children separately, starting from step 1.

### Usage

* `CentroidDecomposition(g)`: Builds a centroid decomposition tree `cd_par` in $O(n \log{n})$.
* `cd_par`: Representing the deletion times of vertices during our centroid decomposition using a partially ordered set, `cd_par[x]` is the predecessor of `x`.