---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graphs/trees/tree_isomorphism.h\"\n\nstruct TreeIsomorphism\
    \ {\n    map<vector<int>, int> hashes;\n\n    vector<int> gen(const vector<vector<int>>\
    \ &g, int rt = 0) {\n        vector<int> res(sz(g));\n        dfs(rt, -1, g, res);\n\
    \        return res;\n    }\n\nprivate:\n    void dfs(int u, int par, auto &g,\
    \ auto &res) {\n        vector<int> children;\n        for (int v : g[u]) {\n\
    \            if (v != par) {\n                dfs(v, u, g, res);\n           \
    \     children.push_back(res[v]);\n            }\n        }\n        sort(all(children));\n\
    \        if (!hashes.count(children)) {\n            hashes[children] = sz(hashes);\n\
    \        }\n        res[u] = hashes[children];\n    }\n};\n"
  code: "#pragma once\n\nstruct TreeIsomorphism {\n    map<vector<int>, int> hashes;\n\
    \n    vector<int> gen(const vector<vector<int>> &g, int rt = 0) {\n        vector<int>\
    \ res(sz(g));\n        dfs(rt, -1, g, res);\n        return res;\n    }\n\nprivate:\n\
    \    void dfs(int u, int par, auto &g, auto &res) {\n        vector<int> children;\n\
    \        for (int v : g[u]) {\n            if (v != par) {\n                dfs(v,\
    \ u, g, res);\n                children.push_back(res[v]);\n            }\n  \
    \      }\n        sort(all(children));\n        if (!hashes.count(children)) {\n\
    \            hashes[children] = sz(hashes);\n        }\n        res[u] = hashes[children];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/trees/tree_isomorphism.h
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
documentation_of: graphs/trees/tree_isomorphism.h
layout: document
redirect_from:
- /library/graphs/trees/tree_isomorphism.h
- /library/graphs/trees/tree_isomorphism.h.html
title: graphs/trees/tree_isomorphism.h
---
