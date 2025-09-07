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
    \tvector<int> res(sz(g));\n\t\n\tauto dfs = [&](auto &&self, int u, int par) ->\
    \ void {\n\t\tvector<int> ch;\n\t\tfor (int v : g[u]) {\n\t\t\tif (v != par) {\n\
    \t\t\t\tself(self, v, u);\n\t\t\t\tch.push_back(res[v]);\n\t\t\t}\n\t\t}\n\t\t\
    sort(all(ch));\n\t\tif (!tree_hashes.count(ch)) {\n\t\t\ttree_hashes[ch] = sz(tree_hashes);\n\
    \t\t}\n\t\tres[u] = tree_hashes[ch];\n\t};\n\n\tdfs(dfs, root, -1);\n\n\treturn\
    \ res;\n}\n"
  code: "map<vector<int>, int> tree_hashes;\n\nauto hash_tree(const vector<vector<int>>\
    \ &g, int root = 0) {\n\tvector<int> res(sz(g));\n\t\n\tauto dfs = [&](auto &&self,\
    \ int u, int par) -> void {\n\t\tvector<int> ch;\n\t\tfor (int v : g[u]) {\n\t\
    \t\tif (v != par) {\n\t\t\t\tself(self, v, u);\n\t\t\t\tch.push_back(res[v]);\n\
    \t\t\t}\n\t\t}\n\t\tsort(all(ch));\n\t\tif (!tree_hashes.count(ch)) {\n\t\t\t\
    tree_hashes[ch] = sz(tree_hashes);\n\t\t}\n\t\tres[u] = tree_hashes[ch];\n\t};\n\
    \n\tdfs(dfs, root, -1);\n\n\treturn res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/graphs/trees/tree_hashing.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
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
