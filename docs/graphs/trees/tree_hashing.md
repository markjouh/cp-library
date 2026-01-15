---
title: Tree Hashing
documentation_of: ./src/graphs/trees/tree_hashing.h
---

Computes hash values for tree isomorphism detection and subtree comparison.

## Operations

- `hash_tree(g, root)`: Compute hash for each vertex in tree rooted at `root`
- Returns vector where `res[u]` is the hash of subtree rooted at `u`

## Global Variables

- `tree_hashes`: Map from child hash vectors to unique integer IDs

## Complexity

- Time: $O(n \log n)$ due to sorting children hashes
- Space: $O(n)$

## Usage

{% raw %}
```cpp
vector<vector<int>> tree1 = {{1, 2}, {0}, {0}};
vector<vector<int>> tree2 = {{1}, {0, 2}, {1}};

auto hashes1 = hash_tree(tree1, 0);
auto hashes2 = hash_tree(tree2, 1);

// Compare root hashes
if (hashes1[0] == hashes2[1]) {
  // Trees are isomorphic when rooted at these vertices
}
```
{% endraw %}

## Notes

Hash values depend on tree structure but not vertex labels. Two subtrees with the same hash have identical structure. The `tree_hashes` map persists across calls, allowing comparison of subtrees from different trees.
