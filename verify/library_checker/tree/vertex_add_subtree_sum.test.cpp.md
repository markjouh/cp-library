---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree/fentree.h
    title: datastructures/fenwick_tree/fentree.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"verify/library_checker/tree/vertex_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    \n#line 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing\
    \ ll = long long;\n#line 1 \"datastructures/fenwick_tree/fentree.h\"\ntemplate\
    \ <class T>\nstruct fentree {\n    int n;\n    vector<T> ft;\n\n    fentree(int\
    \ n_) : n(n_), ft(n + 1) {}\n\n    fentree(const vector<T> &a) : n(sz(a)), ft(n\
    \ + 1) {\n        for (int i = 1; i <= n; i++) {\n            ft[i] += a[i - 1];\n\
    \            if (i + (i & -i) <= n) {\n                ft[i + (i & -i)] += ft[i];\n\
    \            }\n        }\n    }\n\n    void add(int p, T v) {\n        for (p++;\
    \ p <= n; p += p & -p) {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int\
    \ r) {\n        T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n        \
    \    res += ft[r];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l - 1);\n    }\n};\n#line 5 \"verify/library_checker/tree/vertex_add_subtree_sum.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n \
    \   for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    vector<vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n\
    \        g[p].push_back(i);\n    }\n    \n    int time = 0;\n    vector<int> tin(n),\
    \ tout(n);\n\n    auto dfs = [&](auto &&self, int u, int par) -> void {\n    \
    \    tin[u] = time++;\n        for (int v : g[u]) {\n            if (v != par)\
    \ {\n                self(self, v, u);\n            }\n        }\n        tout[u]\
    \ = time;\n    };\n\n    dfs(dfs, 0, -1);\n\n    fentree<ll> ft(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        ft.add(tin[i], a[i]);\n    }\n    while (q--)\
    \ {\n        bool t;\n        int u;\n        cin >> t >> u;\n        if (t) {\n\
    \            cout << ft.sum(tin[u], tout[u] - 1) << '\\n';\n        } else {\n\
    \            int x;\n            cin >> x;\n            ft.add(tin[u], x);\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../datastructures/fenwick_tree/fentree.h\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n \
    \   for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    vector<vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n\
    \        g[p].push_back(i);\n    }\n    \n    int time = 0;\n    vector<int> tin(n),\
    \ tout(n);\n\n    auto dfs = [&](auto &&self, int u, int par) -> void {\n    \
    \    tin[u] = time++;\n        for (int v : g[u]) {\n            if (v != par)\
    \ {\n                self(self, v, u);\n            }\n        }\n        tout[u]\
    \ = time;\n    };\n\n    dfs(dfs, 0, -1);\n\n    fentree<ll> ft(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        ft.add(tin[i], a[i]);\n    }\n    while (q--)\
    \ {\n        bool t;\n        int u;\n        cin >> t >> u;\n        if (t) {\n\
    \            cout << ft.sum(tin[u], tout[u] - 1) << '\\n';\n        } else {\n\
    \            int x;\n            cin >> x;\n            ft.add(tin[u], x);\n \
    \       }\n    }\n}"
  dependsOn:
  - template/template.h
  - datastructures/fenwick_tree/fentree.h
  isVerificationFile: true
  path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-12-07 19:52:17-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp.html
title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
---