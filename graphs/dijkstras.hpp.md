---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
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
    \ graphs/dijkstras.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/* Given a weighted graph, computes and constructs the shortest paths from\
    \ the\n * starting vertex.\n * `dijkstras((V, E))`: O((|V| + |E|) * log(|V|))\n\
    \ */\n\n#pragma once\n\ntemplate<class T> auto dijkstras(const vector<vector<pair<int,\
    \ int>>> &g, int start = 0) {\n    priority_queue<pair<T, int>, vector<pair<T,\
    \ int>>, greater<pair<T, int>>> pq;\n\n    vector<T> dist(sz(g), numeric_limits<T>::max());\n\
    \    vector<int> from(sz(g), -1);\n    \n    dist[start] = 0;\n    pq.emplace(0,\
    \ start);\n\n    while (sz(pq)) {\n        auto [d, u] = pq.top();\n        pq.pop();\n\
    \        if (d != dist[u]) {\n            continue;\n        }\n        for (auto\
    \ [v, w] : g[u]) {\n            if (ckmin(dist[v], d + w)) {\n               \
    \ from[v] = u;\n                pq.emplace(dist[v], v);\n            }\n     \
    \   }\n    }\n    return make_pair(dist, from);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graphs/dijkstras.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/graph/shortest_path.test.cpp
documentation_of: graphs/dijkstras.hpp
layout: document
redirect_from:
- /library/graphs/dijkstras.hpp
- /library/graphs/dijkstras.hpp.html
title: graphs/dijkstras.hpp
---
