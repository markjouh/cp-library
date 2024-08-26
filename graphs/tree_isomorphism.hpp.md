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
  bundledCode: "#line 2 \"graphs/tree_isomorphism.hpp\"\n\nstruct tree_isomorphism\
    \ {\n    map<vector<int>, int> hashes;\n\n    vector<int> gen(const vector<vector<int>>\
    \ &g, int root = 0) {\n        vector<int> res(sz(g));\n        dfs(root, -1,\
    \ g, res);\n        return res;\n    }\n\nprivate:\n    void dfs(int u, int par,\
    \ auto &g, auto &res) {\n        vector<int> children;\n        for (int v : g[u])\
    \ {\n            if (v != par) {\n                dfs(v, u, g, res);\n       \
    \         children.push_back(res[v]);\n            }\n        }\n        sort(all(children));\n\
    \        if (!hashes.count(children)) {\n            hashes[children] = sz(hashes);\n\
    \        }\n        res[u] = hashes[children];\n    }\n};\n"
  code: "#pragma once\n\nstruct tree_isomorphism {\n    map<vector<int>, int> hashes;\n\
    \n    vector<int> gen(const vector<vector<int>> &g, int root = 0) {\n        vector<int>\
    \ res(sz(g));\n        dfs(root, -1, g, res);\n        return res;\n    }\n\n\
    private:\n    void dfs(int u, int par, auto &g, auto &res) {\n        vector<int>\
    \ children;\n        for (int v : g[u]) {\n            if (v != par) {\n     \
    \           dfs(v, u, g, res);\n                children.push_back(res[v]);\n\
    \            }\n        }\n        sort(all(children));\n        if (!hashes.count(children))\
    \ {\n            hashes[children] = sz(hashes);\n        }\n        res[u] = hashes[children];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/tree_isomorphism.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
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
