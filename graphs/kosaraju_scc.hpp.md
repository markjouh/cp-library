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
  bundledCode: "#line 2 \"graphs/kosaraju_scc.hpp\"\n\nstruct kosaraju_scc {\n   \
    \ int sccs = 0;\n    vector<int> comp;\n    vector<vector<int>> members, c_adj;\n\
    \n    kosaraju_scc(const vector<vector<int>> &g) : comp(sz(g), -1), adj(g), t_adj(sz(g)),\
    \ vis(sz(g)) {\n        ord.reserve(sz(g));\n        for (int i = 0; i < sz(g);\
    \ i++) {\n            if (!vis[i]) {\n                dfs_setup(i);\n        \
    \    }\n        }\n        for (int i = sz(ord) - 1; i >= 0; i--) {\n        \
    \    if (comp[ord[i]] == -1) {\n                members.emplace_back();\n    \
    \            dfs_build(ord[i]);\n                sccs++;\n            }\n    \
    \    }\n        t_adj.clear();\n        vis.clear();\n        ord.clear();\n\n\
    \        c_adj.resize(sccs);\n        vector<int> prev(sccs, -1);\n        for\
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
  code: "#pragma once\n\nstruct kosaraju_scc {\n    int sccs = 0;\n    vector<int>\
    \ comp;\n    vector<vector<int>> members, c_adj;\n\n    kosaraju_scc(const vector<vector<int>>\
    \ &g) : comp(sz(g), -1), adj(g), t_adj(sz(g)), vis(sz(g)) {\n        ord.reserve(sz(g));\n\
    \        for (int i = 0; i < sz(g); i++) {\n            if (!vis[i]) {\n     \
    \           dfs_setup(i);\n            }\n        }\n        for (int i = sz(ord)\
    \ - 1; i >= 0; i--) {\n            if (comp[ord[i]] == -1) {\n               \
    \ members.emplace_back();\n                dfs_build(ord[i]);\n              \
    \  sccs++;\n            }\n        }\n        t_adj.clear();\n        vis.clear();\n\
    \        ord.clear();\n\n        c_adj.resize(sccs);\n        vector<int> prev(sccs,\
    \ -1);\n        for (int i = 0; i < sccs; i++) {\n            for (int u : members[i])\
    \ {\n                for (int v : adj[u]) {\n                    if (comp[v] !=\
    \ i && prev[comp[v]] < i) {\n                        c_adj[i].push_back(comp[v]);\n\
    \                        prev[comp[v]] = i;\n                    }\n         \
    \       }\n            }\n        }\n    }\n\nprivate:\n    const vector<vector<int>>\
    \ &adj;\n    vector<vector<int>> t_adj;\n    vector<bool> vis;\n    vector<int>\
    \ ord;\n\n    void dfs_setup(int u) {\n        vis[u] = true;\n        for (int\
    \ v : adj[u]) {\n            t_adj[v].push_back(u);\n            if (!vis[v])\
    \ {\n                dfs_setup(v);\n            }\n        }\n        ord.push_back(u);\n\
    \    }\n\n    void dfs_build(int u) {\n        comp[u] = sccs;\n        members[sccs].push_back(u);\n\
    \        for (int v : t_adj[u]) {\n            if (comp[v] == -1) {\n        \
    \        dfs_build(v);\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/kosaraju_scc.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/scc.test.cpp
documentation_of: graphs/kosaraju_scc.hpp
layout: document
title: Kosaraju's SCC
---

### Overview

Let $tin$ and $tout$ be the result of DFSing on a directed graph $G$ and storing the enter and exit times of each vertex. We can prove using simple casework that if $u$ has an edge to $v$ in the condensation graph, $tout_u > tout_v$. Thus, the component with the maximum $tout$ must be a source node in the condensation graph. If we build the transpose graph of $G$, the set of reachable vertices from the maximal $tout$ is exactly its SCC, since reachability from within the same component doesn't change, but we're no longer able to exit the component. Repeat this isolate/explore process on the maximal unvisited $tout$ and we have our SCCs.

Produces a condensation graph with edges between component ids `c_adj`, as well as a set of member vertices for each component `members`.

### Usage

* `kosaraju_scc(g)`: Computes the SCCs of g and builds a condensation graph. $O(n)$