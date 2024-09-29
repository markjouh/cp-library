---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/shortest_paths/dijkstras.h
    title: graphs/shortest_paths/dijkstras.h
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':heavy_check_mark:'
    path: utils/encode.h
    title: utils/encode.h
  - icon: ':heavy_check_mark:'
    path: utils/my_random.h
    title: utils/my_random.h
  - icon: ':heavy_check_mark:'
    path: utils/my_timer.h
    title: utils/my_timer.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/utils/random_graph.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing ld = long double;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 2 \"\
    graphs/shortest_paths/dijkstras.h\"\n\ntemplate <class T>\nauto dijkstras(const\
    \ vector<vector<pair<int, int>>> &g, int start = 0) {\n    priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\n    vector<T> dist(sz(g),\
    \ numeric_limits<T>::max());\n    vector<int> from(sz(g), -1);\n    \n    dist[start]\
    \ = 0;\n    pq.emplace(0, start);\n\n    while (sz(pq)) {\n        auto [d, u]\
    \ = pq.top();\n        pq.pop();\n        if (d != dist[u]) {\n            continue;\n\
    \        }\n        for (auto [v, w] : g[u]) {\n            if (d + w < dist[v])\
    \ {\n                dist[v] = d + w;\n                from[v] = u;\n        \
    \        pq.emplace(dist[v], v);\n            }\n        }\n    }\n    return\
    \ make_pair(dist, from);\n}\n#line 5 \"verify/custom/utils/random_graph.test.cpp\"\
    \n\n// Just a sanity check - makes sure the result is connected\n\nconst int T\
    \ = 100;\nconst int INF = INT_MAX / 2;\n\nint main() {\n    for (int i = 0; i\
    \ < T; i++) {\n        const int n = rand_int(1e2, 1e4), root = rand_int(n);\n\
    \        auto g = gen_graph(n, n - 1 + rand_int(n));\n\n        vector<int> dist(n,\
    \ INF);\n        queue<int> q;\n        dist[root] = 0;\n        q.push(root);\n\
    \n        while (sz(q)) {\n            int u = q.front();\n            q.pop();\n\
    \            for (int v : g[u]) {\n                if (dist[v] == INF) {\n   \
    \                 dist[v] = dist[u] + 1;\n                    q.push(v);\n   \
    \             }\n            }\n        }\n        assert(find(all(dist), INF)\
    \ == end(dist));\n    }\n\n    for (int i = 0; i < T; i++) {\n        const int\
    \ n = rand_int(1e2, 1e4), root = rand_int(n);\n        auto g = gen_weighted_graph(n,\
    \ n - 1 + rand_int(n));\n        \n        auto from = dijkstras<ll>(g, root).second;\n\
    \        from[root] = root;\n        assert(find(all(from), -1) == end(from));\n\
    \    }\n\n    cerr << \"Tests passed\" << endl;\n\n    int a, b;\n    cin >> a\
    \ >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../graphs/shortest_paths/dijkstras.h\"\
    \n\n// Just a sanity check - makes sure the result is connected\n\nconst int T\
    \ = 100;\nconst int INF = INT_MAX / 2;\n\nint main() {\n    for (int i = 0; i\
    \ < T; i++) {\n        const int n = rand_int(1e2, 1e4), root = rand_int(n);\n\
    \        auto g = gen_graph(n, n - 1 + rand_int(n));\n\n        vector<int> dist(n,\
    \ INF);\n        queue<int> q;\n        dist[root] = 0;\n        q.push(root);\n\
    \n        while (sz(q)) {\n            int u = q.front();\n            q.pop();\n\
    \            for (int v : g[u]) {\n                if (dist[v] == INF) {\n   \
    \                 dist[v] = dist[u] + 1;\n                    q.push(v);\n   \
    \             }\n            }\n        }\n        assert(find(all(dist), INF)\
    \ == end(dist));\n    }\n\n    for (int i = 0; i < T; i++) {\n        const int\
    \ n = rand_int(1e2, 1e4), root = rand_int(n);\n        auto g = gen_weighted_graph(n,\
    \ n - 1 + rand_int(n));\n        \n        auto from = dijkstras<ll>(g, root).second;\n\
    \        from[root] = root;\n        assert(find(all(from), -1) == end(from));\n\
    \    }\n\n    cerr << \"Tests passed\" << endl;\n\n    int a, b;\n    cin >> a\
    \ >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - graphs/shortest_paths/dijkstras.h
  isVerificationFile: true
  path: verify/custom/utils/random_graph.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 00:50:10-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/random_graph.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/random_graph.test.cpp
- /verify/verify/custom/utils/random_graph.test.cpp.html
title: verify/custom/utils/random_graph.test.cpp
---
