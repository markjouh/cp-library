---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: src/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/graphs/trees/tree_hashing.h\"\nmap<vector<int>, int>\
    \ tree_hashes;\n\nauto hash_tree(const vector<vector<int>> &g, int root = 0) {\n\
    \  vector<int> res(ssize(g));\n  \n  auto dfs = [&](auto &&self, int u, int par)\
    \ -> void {\n    vector<int> ch;\n    for (int v : g[u]) {\n      if (v != par)\
    \ {\n        self(self, v, u);\n        ch.push_back(res[v]);\n      }\n    }\n\
    \    sort(all(ch));\n    if (!tree_hashes.count(ch)) {\n      tree_hashes[ch]\
    \ = ssize(tree_hashes);\n    }\n    res[u] = tree_hashes[ch];\n  };\n\n  dfs(dfs,\
    \ root, -1);\n\n  return res;\n}\n"
  code: "map<vector<int>, int> tree_hashes;\n\nauto hash_tree(const vector<vector<int>>\
    \ &g, int root = 0) {\n  vector<int> res(ssize(g));\n  \n  auto dfs = [&](auto\
    \ &&self, int u, int par) -> void {\n    vector<int> ch;\n    for (int v : g[u])\
    \ {\n      if (v != par) {\n        self(self, v, u);\n        ch.push_back(res[v]);\n\
    \      }\n    }\n    sort(all(ch));\n    if (!tree_hashes.count(ch)) {\n     \
    \ tree_hashes[ch] = ssize(tree_hashes);\n    }\n    res[u] = tree_hashes[ch];\n\
    \  };\n\n  dfs(dfs, root, -1);\n\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/trees/tree_hashing.h
  requiredBy: []
  timestamp: '2025-09-14 12:12:28-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
documentation_of: src/graphs/trees/tree_hashing.h
layout: document
title: Tree Hashing
---

Computes hash values for tree isomorphism detection and subtree comparison.

## Operations

- `tree_hash(g, root)`: Compute hash of tree rooted at given vertex
- Returns hash value for the tree structure

## Complexity

- Time: $O(n)$
- Space: $O(n)$

## Usage

{% raw %}
```cpp
vector<vector<int>> tree1 = {{1, 2}, {0}, {0}};
vector<vector<int>> tree2 = {{1}, {0, 2}, {1}};

auto hash1 = tree_hash(tree1, 0);
auto hash2 = tree_hash(tree2, 1);

if (hash1 == hash2) {
  // Trees are isomorphic when rooted appropriately
}
```
{% endraw %}

## Notes

Hash value depends on tree structure but not vertex labels. Useful for detecting isomorphic subtrees.
