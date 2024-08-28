---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/tree_isomorphism.hpp\"\n\nstruct TreeIsomorphism\
    \ {\n\tmap<vector<int>, int> hashes;\n\n\tvector<int> gen(const vector<vector<int>>\
    \ &g, int root = 0) {\n\t\tvector<int> res(sz(g));\n\t\tdfs(root, -1, g, res);\n\
    \t\treturn res;\n\t}\n\nprivate:\n\tvoid dfs(int u, int par, auto &g, auto &res)\
    \ {\n\t\tvector<int> children;\n\t\tfor (int v : g[u]) {\n\t\t\tif (v != par)\
    \ {\n\t\t\t\tdfs(v, u, g, res);\n\t\t\t\tchildren.push_back(res[v]);\n\t\t\t}\n\
    \t\t}\n\t\tsort(all(children));\n\t\tif (!hashes.count(children)) {\n\t\t\thashes[children]\
    \ = sz(hashes);\n\t\t}\n\t\tres[u] = hashes[children];\n\t}\n};\n"
  code: "#pragma once\n\nstruct TreeIsomorphism {\n\tmap<vector<int>, int> hashes;\n\
    \n\tvector<int> gen(const vector<vector<int>> &g, int root = 0) {\n\t\tvector<int>\
    \ res(sz(g));\n\t\tdfs(root, -1, g, res);\n\t\treturn res;\n\t}\n\nprivate:\n\t\
    void dfs(int u, int par, auto &g, auto &res) {\n\t\tvector<int> children;\n\t\t\
    for (int v : g[u]) {\n\t\t\tif (v != par) {\n\t\t\t\tdfs(v, u, g, res);\n\t\t\t\
    \tchildren.push_back(res[v]);\n\t\t\t}\n\t\t}\n\t\tsort(all(children));\n\t\t\
    if (!hashes.count(children)) {\n\t\t\thashes[children] = sz(hashes);\n\t\t}\n\t\
    \tres[u] = hashes[children];\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/tree_isomorphism.hpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
documentation_of: graphs/tree_isomorphism.hpp
layout: document
redirect_from:
- /library/graphs/tree_isomorphism.hpp
- /library/graphs/tree_isomorphism.hpp.html
title: graphs/tree_isomorphism.hpp
---
