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
  bundledCode: "#line 2 \"graphs/centroid_decomposition.hpp\"\n\nstruct CentroidDecomposition\
    \ {\n\tvector<int> cd_par;\n\n\tCentroidDecomposition(const vector<vector<int>>\
    \ &g) : cd_par(sz(g)), adj(g), blocked(sz(g)), st_size(sz(g)) {\n\t\tfor (int\
    \ i = 0; i < sz(g); i++) {\n\t\t\tif (st_size[i] == 0) {\n\t\t\t\tbuild(i, -1);\n\
    \t\t\t}\n\t\t}\n\t\tblocked.clear();\n\t\tst_size.clear();\n\t}\nprivate:\n\t\
    const vector<vector<int>> &adj;\n\tvector<bool> blocked;\n\tvector<int> st_size;\n\
    \n\tvoid get_sizes(int u, int par) {\n\t\tst_size[u] = 1;\n\t\tfor (int v : adj[u])\
    \ {\n\t\t\tif (v != par && !blocked[v]) {\n\t\t\t\tget_sizes(v, u);\n\t\t\t\t\
    st_size[u] += st_size[v];\n\t\t\t}\n\t\t}\n\t}\n\n\tint find_centroid(int u, int\
    \ par, int tree_sz) {\n\t\tint nxt = -1;\n\t\tfor (int v : adj[u]) {\n\t\t\tif\
    \ (v != par && !blocked[v] && st_size[v] * 2 > tree_sz) {\n\t\t\t\tnxt = v;\n\t\
    \t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treturn nxt == -1 ? u : find_centroid(nxt, u,\
    \ tree_sz);\n\t}\n\n\tvoid build(int u, int par) {\n\t\tget_sizes(u, -1);\n\t\t\
    const int root = find_centroid(u, -1, st_size[u]);\n\t\tcd_par[root] = par;\n\t\
    \tblocked[root] = true;\n\t\tfor (int v : adj[root]) {\n\t\t\tif (!blocked[v])\
    \ {\n\t\t\t\tbuild(v, root);\n\t\t\t}\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n\nstruct CentroidDecomposition {\n\tvector<int> cd_par;\n\n\
    \tCentroidDecomposition(const vector<vector<int>> &g) : cd_par(sz(g)), adj(g),\
    \ blocked(sz(g)), st_size(sz(g)) {\n\t\tfor (int i = 0; i < sz(g); i++) {\n\t\t\
    \tif (st_size[i] == 0) {\n\t\t\t\tbuild(i, -1);\n\t\t\t}\n\t\t}\n\t\tblocked.clear();\n\
    \t\tst_size.clear();\n\t}\nprivate:\n\tconst vector<vector<int>> &adj;\n\tvector<bool>\
    \ blocked;\n\tvector<int> st_size;\n\n\tvoid get_sizes(int u, int par) {\n\t\t\
    st_size[u] = 1;\n\t\tfor (int v : adj[u]) {\n\t\t\tif (v != par && !blocked[v])\
    \ {\n\t\t\t\tget_sizes(v, u);\n\t\t\t\tst_size[u] += st_size[v];\n\t\t\t}\n\t\t\
    }\n\t}\n\n\tint find_centroid(int u, int par, int tree_sz) {\n\t\tint nxt = -1;\n\
    \t\tfor (int v : adj[u]) {\n\t\t\tif (v != par && !blocked[v] && st_size[v] *\
    \ 2 > tree_sz) {\n\t\t\t\tnxt = v;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\treturn\
    \ nxt == -1 ? u : find_centroid(nxt, u, tree_sz);\n\t}\n\n\tvoid build(int u,\
    \ int par) {\n\t\tget_sizes(u, -1);\n\t\tconst int root = find_centroid(u, -1,\
    \ st_size[u]);\n\t\tcd_par[root] = par;\n\t\tblocked[root] = true;\n\t\tfor (int\
    \ v : adj[root]) {\n\t\t\tif (!blocked[v]) {\n\t\t\t\tbuild(v, root);\n\t\t\t\
    }\n\t\t}\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/centroid_decomposition.hpp
layout: document
title: Centroid Decomposition
---

### Overview

A centroid of a tree is a vertex that splits the tree into subtrees of size $\leq \frac{n}{2}$ if removed. By this property, recursively splitting a tree by a centroid creates $O(\log{n})$ layers of subgraphs of $O(n)$ total size each. Centroid decomposition is a divide and conquer technique for trees that uses this idea.

I can't list all its possible applications, but this is a common usage I've personally encountered often.

Broadly, if the objective is to consider all solutions, CD lets us reframe the problem into:
1. Root the tree at a centroid, and consider all solutions that depend on the root or objects belonging to different child subtrees of the root.
2. For the purposes of considering the remaining solutions, the root is irrelevant, and all of its child subtrees are now independent from each other. Break the tree apart from the root and solve the children separately, starting from step 1.

### Usage

* `centroid_decomp(g)`: Builds a centroid decomposition tree `cd_par` in $O(n \log{n})$.
* `cd_par`: Representing the deletion times of vertices during our centroid decomposition using a partially ordered set, `cd_par[x]` is the predecessor of `x`.