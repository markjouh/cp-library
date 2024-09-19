---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/kosaraju_scc.h
    title: graphs/kosaraju_scc.h
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
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"verify/library_checker/graph/scc.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/scc\"\n\n#line 1 \"misc/template.h\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
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
    \    }\n} init_io;\n#line 2 \"graphs/kosaraju_scc.h\"\n\nstruct KosarajuSCC {\n\
    \    int sccs = 0;\n    vector<int> comp;\n    vector<vector<int>> members, cond_g;\n\
    \n    KosarajuSCC(const vector<vector<int>> &g_) : g(g_) {\n        comp.resize(sz(g),\
    \ -1);\n        rev_g.resize(sz(g));\n        vis.resize(sz(g));\n        ord.reserve(sz(g));\n\
    \        for (int i = 0; i < sz(g); i++) {\n            if (!vis[i]) {\n     \
    \           dfs_setup(i);\n            }\n        }\n        for (int i = sz(ord)\
    \ - 1; i >= 0; i--) {\n            if (comp[ord[i]] == -1) {\n               \
    \ members.emplace_back();\n                dfs_build(ord[i]);\n              \
    \  sccs++;\n            }\n        }\n        rev_g.clear();\n        vis.clear();\n\
    \        ord.clear();\n\n        cond_g.resize(sccs);\n        vector<int> prev(sccs,\
    \ -1);\n        for (int i = 0; i < sccs; i++) {\n            for (int u : members[i])\
    \ {\n                for (int v : g[u]) {\n                    if (comp[v] !=\
    \ i && prev[comp[v]] < i) {\n                        cond_g[i].push_back(comp[v]);\n\
    \                        prev[comp[v]] = i;\n                    }\n         \
    \       }\n            }\n        }\n    }\n\nprivate:\n    const vector<vector<int>>\
    \ &g;\n    vector<vector<int>> rev_g;\n    vector<bool> vis;\n    vector<int>\
    \ ord;\n\n    void dfs_setup(int u) {\n        vis[u] = true;\n        for (int\
    \ v : g[u]) {\n            rev_g[v].push_back(u);\n            if (!vis[v]) {\n\
    \                dfs_setup(v);\n            }\n        }\n        ord.push_back(u);\n\
    \    }\n\n    void dfs_build(int u) {\n        comp[u] = sccs;\n        members[sccs].push_back(u);\n\
    \        for (int v : rev_g[u]) {\n            if (comp[v] == -1) {\n        \
    \        dfs_build(v);\n            }\n        }\n    }\n};\n#line 5 \"verify/library_checker/graph/scc.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    cin >> n >> m;\n    vector<vector<int>> g(n);\n\
    \    for (int i = 0; i < m; i++) {\n        int u, v;\n        cin >> u >> v;\n\
    \        g[u].push_back(v);\n    }\n    KosarajuSCC scc(g);\n    cout << scc.sccs\
    \ << '\\n';\n    for (int i = 0; i < scc.sccs; i++) {\n        cout << sz(scc.members[i])\
    \ << ' ';\n        for (int x : scc.members[i]) {\n            cout << x << '\
    \ ';\n        }\n        cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../../misc/template.h\"\
    \n#include \"../../../graphs/kosaraju_scc.h\"\n\nint main() {\n    int n, m;\n\
    \    cin >> n >> m;\n    vector<vector<int>> g(n);\n    for (int i = 0; i < m;\
    \ i++) {\n        int u, v;\n        cin >> u >> v;\n        g[u].push_back(v);\n\
    \    }\n    KosarajuSCC scc(g);\n    cout << scc.sccs << '\\n';\n    for (int\
    \ i = 0; i < scc.sccs; i++) {\n        cout << sz(scc.members[i]) << ' ';\n  \
    \      for (int x : scc.members[i]) {\n            cout << x << ' ';\n       \
    \ }\n        cout << '\\n';\n    }\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - graphs/kosaraju_scc.h
  isVerificationFile: true
  path: verify/library_checker/graph/scc.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/scc.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/scc.test.cpp
- /verify/verify/library_checker/graph/scc.test.cpp.html
title: verify/library_checker/graph/scc.test.cpp
---
