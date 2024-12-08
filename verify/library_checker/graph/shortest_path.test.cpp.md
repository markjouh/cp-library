---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/shortest_paths/dijkstras.h
    title: graphs/shortest_paths/dijkstras.h
  - icon: ':heavy_check_mark:'
    path: template/template.h
    title: template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/library_checker/graph/shortest_path.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#line 1 \"\
    template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\
    #line 1 \"graphs/shortest_paths/dijkstras.h\"\ntemplate <class T>\nauto dijkstras(const\
    \ vector<vector<pair<int, int>>> &g, int start = 0) {\n    priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\n    vector<T> dist(sz(g),\
    \ numeric_limits<T>::max());\n    vector<int> from(sz(g), -1);\n    \n    dist[start]\
    \ = 0;\n    pq.emplace(0, start);\n\n    while (sz(pq)) {\n        auto [d, u]\
    \ = pq.top();\n        pq.pop();\n        if (d != dist[u]) {\n            continue;\n\
    \        }\n        for (auto [v, w] : g[u]) {\n            if (d + w < dist[v])\
    \ {\n                dist[v] = d + w;\n                from[v] = u;\n        \
    \        pq.emplace(dist[v], v);\n            }\n        }\n    }\n    return\
    \ make_pair(dist, from);\n}\n#line 5 \"verify/library_checker/graph/shortest_path.test.cpp\"\
    \n\nint main() {\n    int n, m, s, t;\n    cin >> n >> m >> s >> t;\n    vector<vector<pair<int,\
    \ int>>> g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v, w;\n    \
    \    cin >> u >> v >> w;\n        g[u].emplace_back(v, w);\n    }\n    \n    auto\
    \ [dist, from] = dijkstras<ll>(g, s);\n    if (dist[t] != LLONG_MAX) {\n     \
    \   cout << dist[t] << ' ';\n        vector<pair<int, int>> path;\n        int\
    \ p = t;\n        while (p != s) {\n            path.emplace_back(from[p], p);\n\
    \            p = from[p];\n        }\n        reverse(all(path));\n        cout\
    \ << sz(path) << '\\n';\n        for (auto [u, v] : path) {\n            cout\
    \ << u << ' ' << v << '\\n';\n        }\n    } else {\n        cout << -1 << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../graphs/shortest_paths/dijkstras.h\"\
    \n\nint main() {\n    int n, m, s, t;\n    cin >> n >> m >> s >> t;\n    vector<vector<pair<int,\
    \ int>>> g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v, w;\n    \
    \    cin >> u >> v >> w;\n        g[u].emplace_back(v, w);\n    }\n    \n    auto\
    \ [dist, from] = dijkstras<ll>(g, s);\n    if (dist[t] != LLONG_MAX) {\n     \
    \   cout << dist[t] << ' ';\n        vector<pair<int, int>> path;\n        int\
    \ p = t;\n        while (p != s) {\n            path.emplace_back(from[p], p);\n\
    \            p = from[p];\n        }\n        reverse(all(path));\n        cout\
    \ << sz(path) << '\\n';\n        for (auto [u, v] : path) {\n            cout\
    \ << u << ' ' << v << '\\n';\n        }\n    } else {\n        cout << -1 << '\\\
    n';\n    }\n}"
  dependsOn:
  - template/template.h
  - graphs/shortest_paths/dijkstras.h
  isVerificationFile: true
  path: verify/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-12-07 19:52:17-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/shortest_path.test.cpp
- /verify/verify/library_checker/graph/shortest_path.test.cpp.html
title: verify/library_checker/graph/shortest_path.test.cpp
---
