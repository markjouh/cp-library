---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graphs/euler_tour.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/* Given a rooted undirected tree, computes (tin, tout) such that if vertex\
    \ v\n * were assigned to position tin[v] for all v, the interval [tin[v], tout[v])\n\
    \ * would contain exactly the subtree rooted at v for all v.\n */\n\n#pragma once\n\
    \nstruct euler_tour {\n    vector<int> tin, tout;\n\n    euler_tour(const vector<vector<int>>\
    \ &g, int root = 0) : adj(g) {\n        dfs(root, -1);\n    }\n\nprivate:\n  \
    \  int time = 0;\n    const vector<vector<int>> &adj;\n\n    void dfs(int u, int\
    \ par) {\n        tin[u] = time++;\n        for (int v : adj[u]) {\n         \
    \   if (v != par) {\n                dfs(v, u);\n            }\n        }\n  \
    \      tout[u] = time;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/euler_tour.hpp
  requiredBy: []
  timestamp: '2024-08-26 11:12:12-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/euler_tour.hpp
layout: document
redirect_from:
- /library/graphs/euler_tour.hpp
- /library/graphs/euler_tour.hpp.html
title: graphs/euler_tour.hpp
---
