---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/kosaraju_scc.h
    title: graphs/kosaraju_scc.h
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/library_checker/graph/scc.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n\n#line 1 \"template/template.h\"\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\n#define all(x) begin(x), end(x)\n\
    #define sz(x) int(size(x))\n\nusing ll = long long;\n#line 1 \"graphs/kosaraju_scc.h\"\
    \nstruct kosaraju_scc {\n    int sccs = 0;\n    vector<int> comp;\n    vector<vector<int>>\
    \ members, cg;\n\n    kosaraju_scc(const vector<vector<int>> &g_) : g(g_) {\n\
    \        comp.resize(sz(g), -1);\n        tg.resize(sz(g));\n        vis.resize(sz(g));\n\
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
    \     dfs_build(v);\n            }\n        }\n    }\n};\n#line 5 \"verify/library_checker/graph/scc.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vector<vector<int>> g(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v;\n        cin >> u >> v;\n\
    \        g[u].push_back(v);\n    }\n    kosaraju_scc scc(g);\n    cout << scc.sccs\
    \ << '\\n';\n    for (int i = 0; i < scc.sccs; i++) {\n        cout << sz(scc.members[i])\
    \ << ' ';\n        for (int x : scc.members[i]) {\n            cout << x << '\
    \ ';\n        }\n        cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../../template/template.h\"\
    \n#include \"../../../graphs/kosaraju_scc.h\"\n\nint main() {\n    int n, m;\n\
    \    cin >> n >> m;\n    vector<vector<int>> g(n);\n    for (int i = 0; i < m;\
    \ i++) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \    }\n    kosaraju_scc scc(g);\n    cout << scc.sccs << '\\n';\n    for (int\
    \ i = 0; i < scc.sccs; i++) {\n        cout << sz(scc.members[i]) << ' ';\n  \
    \      for (int x : scc.members[i]) {\n            cout << x << ' ';\n       \
    \ }\n        cout << '\\n';\n    }\n}"
  dependsOn:
  - template/template.h
  - graphs/kosaraju_scc.h
  isVerificationFile: true
  path: verify/library_checker/graph/scc.test.cpp
  requiredBy: []
  timestamp: '2024-12-07 19:52:17-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/scc.test.cpp
- /verify/verify/library_checker/graph/scc.test.cpp.html
title: verify/library_checker/graph/scc.test.cpp
---
