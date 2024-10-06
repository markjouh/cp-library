---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/topsort.h
    title: graphs/topsort.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/encode.h
    title: utils/encode.h
  - icon: ':question:'
    path: utils/my_random.h
    title: utils/my_random.h
  - icon: ':question:'
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
  bundledCode: "#line 1 \"verify/custom/graphs/topsort.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing ld = long double;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 2 \"\
    graphs/topsort.h\"\n\nauto topsort(const vector<vector<int>> &g) {\n    vector<int>\
    \ deg(sz(g));\n    for (int u = 0; u < sz(g); u++) {\n        for (int v : g[u])\
    \ {\n            deg[v]++;\n        }\n    }\n    queue<int> q;\n    for (int\
    \ i = 0; i < sz(g); i++) {\n        if (deg[i] == 0) {\n            q.push(i);\n\
    \        }\n    }\n    vector<int> res;\n    while (!q.empty()) {\n        int\
    \ u = q.front();\n        q.pop();\n        res.push_back(u);\n        for (int\
    \ v : g[u]) {\n            if (--deg[v] == 0) {\n                q.push(v);\n\
    \            }\n        }\n    }\n    return res;\n}\n#line 5 \"verify/custom/graphs/topsort.test.cpp\"\
    \n\nconst int N = 500, T = 100;\n\nvoid test() {\n    int m = rand_int(N - 1,\
    \ N * (N - 1) / 2);\n\n    auto edges = gen_graph_edges(N, m);\n    vector<vector<int>>\
    \ g(N);\n    for (auto &[u, v] : edges) {\n        g[u].push_back(v);\n    }\n\
    \n    auto result = topsort(g);\n    vector<int> pos(sz(result));\n    for (int\
    \ i = 0; i < sz(result); i++) {\n        pos[result[i]] = i;\n    }\n\n    assert(sz(result)\
    \ == N);\n    for (auto [u, v] : edges) {\n        assert(pos[u] < pos[v]);\n\
    \    }\n}\n\nint main() {\n    for (int i = 0; i < T; i++) {\n        test();\n\
    \    }\n\n    cerr << \"All tests passed\\n\";\n    int a_, b_;\n    cin >> a_\
    \ >> b_;\n    cout << a_ + b_ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../graphs/topsort.h\"\n\nconst int\
    \ N = 500, T = 100;\n\nvoid test() {\n    int m = rand_int(N - 1, N * (N - 1)\
    \ / 2);\n\n    auto edges = gen_graph_edges(N, m);\n    vector<vector<int>> g(N);\n\
    \    for (auto &[u, v] : edges) {\n        g[u].push_back(v);\n    }\n\n    auto\
    \ result = topsort(g);\n    vector<int> pos(sz(result));\n    for (int i = 0;\
    \ i < sz(result); i++) {\n        pos[result[i]] = i;\n    }\n\n    assert(sz(result)\
    \ == N);\n    for (auto [u, v] : edges) {\n        assert(pos[u] < pos[v]);\n\
    \    }\n}\n\nint main() {\n    for (int i = 0; i < T; i++) {\n        test();\n\
    \    }\n\n    cerr << \"All tests passed\\n\";\n    int a_, b_;\n    cin >> a_\
    \ >> b_;\n    cout << a_ + b_ << '\\n';\n}\n"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - graphs/topsort.h
  isVerificationFile: true
  path: verify/custom/graphs/topsort.test.cpp
  requiredBy: []
  timestamp: '2024-10-05 23:54:04-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/graphs/topsort.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/graphs/topsort.test.cpp
- /verify/verify/custom/graphs/topsort.test.cpp.html
title: verify/custom/graphs/topsort.test.cpp
---
