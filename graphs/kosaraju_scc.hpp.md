---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/scc.test.cpp
    title: verify/library_checker/graph/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ graphs/kosaraju_scc.hpp: line 8: #pragma once found in a non-first line\n"
  code: "/* Kosaraju's algorithm for SCCs.\n * `comp[x]` is the component id, numbered\
    \ [0, sccs), of x.\n * `c_adj` represents the condensation graph through connections\
    \ between component ids.\n * `members[c]` holds the original vertex numbers of\
    \ the members of component c.\n * `kosaraju_scc(G)`: O(|G|)\n */\n\n#pragma once\n\
    \nstruct kosaraju_scc {\n    int sccs = 0;\n    vector<int> comp;\n    vector<vector<int>>\
    \ members, c_adj;\n\n    kosaraju_scc(const vector<vector<int>> &g) : comp(sz(g),\
    \ -1), adj(g), t_adj(sz(g)), vis(sz(g)) {\n        ord.reserve(sz(g));\n     \
    \   for (int i = 0; i < sz(g); i++) {\n            if (!vis[i]) {\n          \
    \      dfs_setup(i);\n            }\n        }\n        for (int i = sz(ord) -\
    \ 1; i >= 0; i--) {\n            if (comp[ord[i]] == -1) {\n                members.emplace_back();\n\
    \                dfs_build(ord[i]);\n                sccs++;\n            }\n\
    \        }\n        t_adj.clear();\n        vis.clear();\n        ord.clear();\n\
    \n        c_adj.resize(sccs);\n        vector<int> prev(sccs, -1);\n        for\
    \ (int i = 0; i < sccs; i++) {\n            for (int u : members[i]) {\n     \
    \           for (int v : adj[u]) {\n                    if (comp[v] != i && prev[comp[v]]\
    \ < i) {\n                        c_adj[i].push_back(comp[v]);\n             \
    \           prev[comp[v]] = i;\n                    }\n                }\n   \
    \         }\n        }\n    }\n\nprivate:\n    const vector<vector<int>> &adj;\n\
    \    vector<vector<int>> t_adj;\n    vector<bool> vis;\n    vector<int> ord;\n\
    \n    void dfs_setup(int u) {\n        vis[u] = true;\n        for (int v : adj[u])\
    \ {\n            t_adj[v].push_back(u);\n            if (!vis[v]) {\n        \
    \        dfs_setup(v);\n            }\n        }\n        ord.push_back(u);\n\
    \    }\n\n    void dfs_build(int u) {\n        comp[u] = sccs;\n        members[sccs].push_back(u);\n\
    \        for (int v : t_adj[u]) {\n            if (comp[v] == -1) {\n        \
    \        dfs_build(v);\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/kosaraju_scc.hpp
  requiredBy: []
  timestamp: '2024-08-26 11:12:12-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/scc.test.cpp
documentation_of: graphs/kosaraju_scc.hpp
layout: document
redirect_from:
- /library/graphs/kosaraju_scc.hpp
- /library/graphs/kosaraju_scc.hpp.html
title: graphs/kosaraju_scc.hpp
---
