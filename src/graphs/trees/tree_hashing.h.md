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
    \  vector<int> res(sz(g));\n  \n  auto dfs = [&](auto &&self, int u, int par)\
    \ -> void {\n    vector<int> ch;\n    for (int v : g[u]) {\n      if (v != par)\
    \ {\n        self(self, v, u);\n        ch.push_back(res[v]);\n      }\n    }\n\
    \    sort(all(ch));\n    if (!tree_hashes.count(ch)) {\n      tree_hashes[ch]\
    \ = sz(tree_hashes);\n    }\n    res[u] = tree_hashes[ch];\n  };\n\n  dfs(dfs,\
    \ root, -1);\n\n  return res;\n}\n"
  code: "map<vector<int>, int> tree_hashes;\n\nauto hash_tree(const vector<vector<int>>\
    \ &g, int root = 0) {\n  vector<int> res(sz(g));\n  \n  auto dfs = [&](auto &&self,\
    \ int u, int par) -> void {\n    vector<int> ch;\n    for (int v : g[u]) {\n \
    \     if (v != par) {\n        self(self, v, u);\n        ch.push_back(res[v]);\n\
    \      }\n    }\n    sort(all(ch));\n    if (!tree_hashes.count(ch)) {\n     \
    \ tree_hashes[ch] = sz(tree_hashes);\n    }\n    res[u] = tree_hashes[ch];\n \
    \ };\n\n  dfs(dfs, root, -1);\n\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/trees/tree_hashing.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
documentation_of: src/graphs/trees/tree_hashing.h
layout: document
redirect_from:
- /library/src/graphs/trees/tree_hashing.h
- /library/src/graphs/trees/tree_hashing.h.html
title: src/graphs/trees/tree_hashing.h
---
