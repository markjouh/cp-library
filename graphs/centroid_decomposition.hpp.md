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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graphs/centroid_decomposition.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/* Given an undirected forest, builds a centroid decomposition forest.\n\
    \ * `cd_par[x]` is the last vertex we chose as a centroid and split before x in\
    \ the poset.\n * `centroid_decomp()`: O(N * log(N))\n */\n\n#pragma once\n\nstruct\
    \ centroid_decomp {\n    vector<int> cd_par;\n\n    centroid_decomp(const vector<vector<int>>\
    \ &g) : cd_par(sz(g)), adj(g), blocked(sz(g)), st_size(sz(g)) {\n        for (int\
    \ i = 0; i < sz(g); i++) {\n            if (st_size[i] == 0) {\n             \
    \   build(i, -1);\n            }\n        }\n        blocked.clear();\n      \
    \  st_size.clear();\n    }\nprivate:\n    const vector<vector<int>> &adj;\n  \
    \  vector<bool> blocked;\n    vector<int> st_size;\n\n    void get_sizes(int u,\
    \ int par) {\n        st_size[u] = 1;\n        for (int v : adj[u]) {\n      \
    \      if (v != par && !blocked[v]) {\n                get_sizes(v, u);\n    \
    \            st_size[u] += st_size[v];\n            }\n        }\n    }\n\n  \
    \  int find_centroid(int u, int par, int tree_sz) {\n        int nxt = -1;\n \
    \       for (int v : adj[u]) {\n            if (v != par && !blocked[v] && st_size[v]\
    \ * 2 > tree_sz) {\n                nxt = v;\n                break;\n       \
    \     }\n        }\n        return nxt == -1 ? u : find_centroid(nxt, u, tree_sz);\n\
    \    }\n\n    void build(int u, int par) {\n        get_sizes(u, -1);\n      \
    \  const int root = find_centroid(u, -1, st_size[u]);\n        cd_par[root] =\
    \ par;\n        blocked[root] = true;\n        for (int v : adj[root]) {\n   \
    \         if (!blocked[v]) {\n                build(v, root);\n            }\n\
    \        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graphs/centroid_decomposition.hpp
- /library/graphs/centroid_decomposition.hpp.html
title: graphs/centroid_decomposition.hpp
---
