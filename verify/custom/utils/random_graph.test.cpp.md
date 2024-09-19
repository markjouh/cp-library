---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graphs/dijkstras.h
    title: graphs/dijkstras.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/utils/random_graph.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define arg4(a, b, c, d, ...) d\n \n#define\
    \ rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i,\
    \ 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define\
    \ per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n)\
    \ per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define f first\n#define s second\n\nusing ll = long\
    \ long;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, const T &b) {\n    return b < a ? a = b, 1 : 0;\n\
    }\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n    return b > a ? a\
    \ = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n        cin.tie(0)->sync_with_stdio(0);\n\
    \        cin.exceptions(cin.failbit);\n        cout << setprecision(10) << fixed;\n\
    \    }\n} init_io;\n#line 2 \"graphs/dijkstras.h\"\n\ntemplate <class T>\nauto\
    \ dijkstras(const vector<vector<pair<int, int>>> &g, int start = 0) {\n    priority_queue<pair<T,\
    \ int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;\n\n    vector<T> dist(sz(g),\
    \ numeric_limits<T>::max());\n    vector<int> from(sz(g), -1);\n    \n    dist[start]\
    \ = 0;\n    pq.emplace(0, start);\n\n    while (sz(pq)) {\n        auto [d, u]\
    \ = pq.top();\n        pq.pop();\n        if (d != dist[u]) {\n            continue;\n\
    \        }\n        for (auto [v, w] : g[u]) {\n            if (ckmin(dist[v],\
    \ d + w)) {\n                from[v] = u;\n                pq.emplace(dist[v],\
    \ v);\n            }\n        }\n    }\n    return make_pair(dist, from);\n}\n\
    #line 5 \"verify/custom/utils/random_graph.test.cpp\"\n\n// Just a sanity check\
    \ - makes sure the result is valid\n\nconst int T = 100;\nconst int INF = INT_MAX\
    \ / 2;\n\nint main() {\n    for (int i = 0; i < T; i++) {\n        const int n\
    \ = rand_int(1e2, 1e4), root = rand_int(n);\n        auto g = gen_graph(n, n -\
    \ 1 + rand_int(n));\n\n        vector<int> dist(n, INF);\n        queue<int> q;\n\
    \        dist[root] = 0;\n        q.push(root);\n\n        while (sz(q)) {\n \
    \           int u = q.front();\n            q.pop();\n            for (int v :\
    \ g[u]) {\n                if (dist[v] == INF) {\n                    dist[v]\
    \ = dist[u] + 1;\n                    q.push(v);\n                }\n        \
    \    }\n        }\n        assert(find(all(dist), INF) == end(dist));\n    }\n\
    \n    for (int i = 0; i < T; i++) {\n        const int n = rand_int(1e2, 1e4),\
    \ root = rand_int(n);\n        auto g = gen_weighted_graph(n, n - 1 + rand_int(n));\n\
    \        \n        auto from = dijkstras<ll>(g, root).second;\n        from[root]\
    \ = root;\n        assert(find(all(from), -1) == end(from));\n    }\n\n    cerr\
    \ << \"Tests passed\" << endl;\n\n    int a, b;\n    cin >> a >> b;\n    cout\
    \ << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../graphs/dijkstras.h\"\n\n// Just\
    \ a sanity check - makes sure the result is valid\n\nconst int T = 100;\nconst\
    \ int INF = INT_MAX / 2;\n\nint main() {\n    for (int i = 0; i < T; i++) {\n\
    \        const int n = rand_int(1e2, 1e4), root = rand_int(n);\n        auto g\
    \ = gen_graph(n, n - 1 + rand_int(n));\n\n        vector<int> dist(n, INF);\n\
    \        queue<int> q;\n        dist[root] = 0;\n        q.push(root);\n\n   \
    \     while (sz(q)) {\n            int u = q.front();\n            q.pop();\n\
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
  - graphs/dijkstras.h
  isVerificationFile: true
  path: verify/custom/utils/random_graph.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/custom/utils/random_graph.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/random_graph.test.cpp
- /verify/verify/custom/utils/random_graph.test.cpp.html
title: verify/custom/utils/random_graph.test.cpp
---
