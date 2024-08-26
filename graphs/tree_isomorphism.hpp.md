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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graphs/tree_isomorphism.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/* Takes in rooted trees and generates perfect hashes of all subtrees in\
    \ O(N * log(N)).\n * Two trees are isomorphic if and only if their hashes match.\n\
    \ */\n\n#pragma once\n\nstruct tree_isomorphism {\n    map<vector<int>, int> hashes;\n\
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
  timestamp: '2024-08-26 16:40:45-04:00'
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
