---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graphs/trees/tree_hashing.h\"\nstruct TreeHashing {\n  \
    \  map<vector<int>, int> hash;\n\n    auto add(const vector<vector<int>> &g, int\
    \ r = 0) {\n        vector<int> res(sz(g));\n        \n        auto dfs = [&](auto\
    \ &&self, int u, int par) -> void {\n            vector<int> ch;\n           \
    \ for (int v : g[u]) {\n                if (v != par) {\n                    self(self,\
    \ v, u);\n                    ch.push_back(res[v]);\n                }\n     \
    \       }\n            sort(all(ch));\n            if (!hash.count(ch)) {\n  \
    \              hash[ch] = sz(hash);\n            }\n            res[u] = hash[ch];\n\
    \        };\n\n        dfs(dfs, r, -1);\n\n        return res;\n    }\n};\n"
  code: "struct TreeHashing {\n    map<vector<int>, int> hash;\n\n    auto add(const\
    \ vector<vector<int>> &g, int r = 0) {\n        vector<int> res(sz(g));\n    \
    \    \n        auto dfs = [&](auto &&self, int u, int par) -> void {\n       \
    \     vector<int> ch;\n            for (int v : g[u]) {\n                if (v\
    \ != par) {\n                    self(self, v, u);\n                    ch.push_back(res[v]);\n\
    \                }\n            }\n            sort(all(ch));\n            if\
    \ (!hash.count(ch)) {\n                hash[ch] = sz(hash);\n            }\n \
    \           res[u] = hash[ch];\n        };\n\n        dfs(dfs, r, -1);\n\n   \
    \     return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/trees/tree_hashing.h
  requiredBy: []
  timestamp: '2024-10-25 19:46:34-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
documentation_of: graphs/trees/tree_hashing.h
layout: document
redirect_from:
- /library/graphs/trees/tree_hashing.h
- /library/graphs/trees/tree_hashing.h.html
title: graphs/trees/tree_hashing.h
---
