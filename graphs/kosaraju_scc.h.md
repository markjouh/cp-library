---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/scc.test.cpp
    title: verify/library_checker/graph/scc.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graphs/kosaraju_scc.h\"\nstruct KosarajuSCC {\n    int sccs\
    \ = 0;\n    vector<int> comp;\n    vector<vector<int>> members, cg;\n\n    KosarajuSCC(const\
    \ vector<vector<int>> &g_) : g(g_) {\n        comp.resize(sz(g), -1);\n      \
    \  tg.resize(sz(g));\n        vis.resize(sz(g));\n        ord.reserve(sz(g));\n\
    \        for (int i = 0; i < sz(g); i++) {\n            if (!vis[i]) {\n     \
    \           dfs_setup(i);\n            }\n        }\n        for (int i = sz(ord)\
    \ - 1; i >= 0; i--) {\n            if (comp[ord[i]] == -1) {\n               \
    \ members.emplace_back();\n                dfs_build(ord[i]);\n              \
    \  sccs++;\n            }\n        }\n        tg.clear();\n        vis.clear();\n\
    \        ord.clear();\n\n        cg.resize(sccs);\n        vector<int> prev(sccs,\
    \ -1);\n        for (int i = 0; i < sccs; i++) {\n            for (int u : members[i])\
    \ {\n                for (int v : g[u]) {\n                    if (comp[v] !=\
    \ i && prev[comp[v]] < i) {\n                        cg[i].push_back(comp[v]);\n\
    \                        prev[comp[v]] = i;\n                    }\n         \
    \       }\n            }\n        }\n    }\n\nprivate:\n    const vector<vector<int>>\
    \ &g;\n    vector<vector<int>> tg;\n    vector<bool> vis;\n    vector<int> ord;\n\
    \n    void dfs_setup(int u) {\n        vis[u] = true;\n        for (int v : g[u])\
    \ {\n            tg[v].push_back(u);\n            if (!vis[v]) {\n           \
    \     dfs_setup(v);\n            }\n        }\n        ord.push_back(u);\n   \
    \ }\n\n    void dfs_build(int u) {\n        comp[u] = sccs;\n        members[sccs].push_back(u);\n\
    \        for (int v : tg[u]) {\n            if (comp[v] == -1) {\n           \
    \     dfs_build(v);\n            }\n        }\n    }\n};\n"
  code: "struct KosarajuSCC {\n    int sccs = 0;\n    vector<int> comp;\n    vector<vector<int>>\
    \ members, cg;\n\n    KosarajuSCC(const vector<vector<int>> &g_) : g(g_) {\n \
    \       comp.resize(sz(g), -1);\n        tg.resize(sz(g));\n        vis.resize(sz(g));\n\
    \        ord.reserve(sz(g));\n        for (int i = 0; i < sz(g); i++) {\n    \
    \        if (!vis[i]) {\n                dfs_setup(i);\n            }\n      \
    \  }\n        for (int i = sz(ord) - 1; i >= 0; i--) {\n            if (comp[ord[i]]\
    \ == -1) {\n                members.emplace_back();\n                dfs_build(ord[i]);\n\
    \                sccs++;\n            }\n        }\n        tg.clear();\n    \
    \    vis.clear();\n        ord.clear();\n\n        cg.resize(sccs);\n        vector<int>\
    \ prev(sccs, -1);\n        for (int i = 0; i < sccs; i++) {\n            for (int\
    \ u : members[i]) {\n                for (int v : g[u]) {\n                  \
    \  if (comp[v] != i && prev[comp[v]] < i) {\n                        cg[i].push_back(comp[v]);\n\
    \                        prev[comp[v]] = i;\n                    }\n         \
    \       }\n            }\n        }\n    }\n\nprivate:\n    const vector<vector<int>>\
    \ &g;\n    vector<vector<int>> tg;\n    vector<bool> vis;\n    vector<int> ord;\n\
    \n    void dfs_setup(int u) {\n        vis[u] = true;\n        for (int v : g[u])\
    \ {\n            tg[v].push_back(u);\n            if (!vis[v]) {\n           \
    \     dfs_setup(v);\n            }\n        }\n        ord.push_back(u);\n   \
    \ }\n\n    void dfs_build(int u) {\n        comp[u] = sccs;\n        members[sccs].push_back(u);\n\
    \        for (int v : tg[u]) {\n            if (comp[v] == -1) {\n           \
    \     dfs_build(v);\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/kosaraju_scc.h
  requiredBy: []
  timestamp: '2024-10-25 19:46:34-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/scc.test.cpp
documentation_of: graphs/kosaraju_scc.h
layout: document
redirect_from:
- /library/graphs/kosaraju_scc.h
- /library/graphs/kosaraju_scc.h.html
title: graphs/kosaraju_scc.h
---
