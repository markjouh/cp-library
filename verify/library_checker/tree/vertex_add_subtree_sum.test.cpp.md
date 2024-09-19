---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/bit/bit.h
    title: datastructures/bit/bit.h
  - icon: ':heavy_check_mark:'
    path: graphs/tree/euler_tour.h
    title: graphs/tree/euler_tour.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes: {}
  bundledCode: "#line 1 \"verify/library_checker/tree/vertex_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    \n#line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
    \ b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    #define pb push_back\n#define eb emplace_back\n#define f first\n#define s second\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n    return b <\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n\
    \    return b > a ? a = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n    \
    \    cin.tie(0)->sync_with_stdio(0);\n        cin.exceptions(cin.failbit);\n \
    \       cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 2 \"datastructures/bit/bit.h\"\
    \n\ntemplate <class T>\nstruct BIT {\n    int n;\n    vector<T> ft;\n\n    BIT(int\
    \ n_) : n(n_), ft(n + 1) {}\n\n    BIT(const vector<T> &a) : n(sz(a)), ft(n +\
    \ 1) {\n        for (int i = 1; i <= n; i++) {\n            ft[i] += a[i - 1];\n\
    \            if (i + (i & -i) <= n) {\n                ft[i + (i & -i)] += ft[i];\n\
    \            }\n        }\n    }\n\n    void add(int p, T v) {\n        for (p++;\
    \ p <= n; p += p & -p) {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int\
    \ r) {\n        T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n        \
    \    res += ft[r];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l - 1);\n    }\n};\n#line 2 \"graphs/tree/euler_tour.h\"\
    \n\nstruct EulerTour {\n    vector<int> tin, tout;\n\n    EulerTour(const vector<vector<int>>\
    \ &g, int root = 0) : adj(g) {\n        tin.resize(sz(g));\n        tout.resize(sz(g));\n\
    \        dfs(root, -1);\n    }\n\nprivate:\n    int time = 0;\n    const vector<vector<int>>\
    \ &adj;\n\n    void dfs(int u, int par) {\n        tin[u] = time++;\n        for\
    \ (int v : adj[u]) {\n            if (v != par) {\n                dfs(v, u);\n\
    \            }\n        }\n        tout[u] = time;\n    }\n};\n#line 6 \"verify/library_checker/tree/vertex_add_subtree_sum.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n \
    \   for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    vector<vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n\
    \        g[p].push_back(i);\n    }\n    EulerTour et(g);\n    BIT<ll> ft(n);\n\
    \    for (int i = 0; i < n; i++) {\n        ft.add(et.tin[i], a[i]);\n    }\n\
    \    while (q--) {\n        bool t;\n        int u;\n        cin >> t >> u;\n\
    \        if (t) {\n            cout << ft.sum(et.tin[u], et.tout[u] - 1) << '\\\
    n';\n        } else {\n            int x;\n            cin >> x;\n           \
    \ ft.add(et.tin[u], x);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../datastructures/bit/bit.h\"\
    \n#include \"../../../graphs/tree/euler_tour.h\"\n\nint main() {\n    int n, q;\n\
    \    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i < n; i++) {\n\
    \        cin >> a[i];\n    }\n    vector<vector<int>> g(n);\n    for (int i =\
    \ 1; i < n; i++) {\n        int p;\n        cin >> p;\n        g[p].push_back(i);\n\
    \    }\n    EulerTour et(g);\n    BIT<ll> ft(n);\n    for (int i = 0; i < n; i++)\
    \ {\n        ft.add(et.tin[i], a[i]);\n    }\n    while (q--) {\n        bool\
    \ t;\n        int u;\n        cin >> t >> u;\n        if (t) {\n            cout\
    \ << ft.sum(et.tin[u], et.tout[u] - 1) << '\\n';\n        } else {\n         \
    \   int x;\n            cin >> x;\n            ft.add(et.tin[u], x);\n       \
    \ }\n    }\n}"
  dependsOn:
  - misc/template.h
  - datastructures/bit/bit.h
  - graphs/tree/euler_tour.h
  isVerificationFile: true
  path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp.html
title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
---
