---
title: Tree Hashing
documentation_of: ./src/trees/tree_hashing.h
---

Computes hash values for tree isomorphism detection and subtree comparison.

## Operations

- `tree_hash(g, root)`: Compute hash of tree rooted at given vertex
- Returns hash value for the tree structure

## Complexity

- Time: $O(n)$
- Space: $O(n)$

## Usage

```cpp
vector<vector<int>> tree1 = {{1, 2}, {0}, {0}};
vector<vector<int>> tree2 = {{1}, {0, 2}, {1}};

auto hash1 = tree_hash(tree1, 0);
auto hash2 = tree_hash(tree2, 1);

if (hash1 == hash2) {
  // Trees are isomorphic when rooted appropriately
}
```

## Notes

Hash value depends on tree structure but not vertex labels. Useful for detecting isomorphic subtrees.