---
title: Tree Isomorphism
documentation_of: ../../graphs/tree_isomorphism.hpp
---

### Overview

A class that takes in rooted trees and computes perfect hashes for all their subtrees in $O(n \log{n})$. Subtrees from different trees can be compared.

### Usage

* `gen(g, root)`: Computes and returns hashes for all subtrees of g.