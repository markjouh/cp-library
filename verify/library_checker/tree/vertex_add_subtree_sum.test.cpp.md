---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_indexed_tree/bit.h
    title: datastructures/binary_indexed_tree/bit.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  - icon: ':question:'
    path: utils/bits/stdc++.h
    title: utils/bits/stdc++.h
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
    \ std;\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\n#define\
    \ pb push_back\n#define eb emplace_back\n#define fi first\n#define se second\n\
    \nusing ll = long long;\n\n// void solve() {\n// }\n\n// int main() {\n//    \
    \ cin.tie(0)->sync_with_stdio(0);\n//     cin.exceptions(cin.failbit);\n\n// \
    \    int t = 1;\n//     // cin >> t;\n//     while (t--) {\n//         solve();\n\
    //     }\n\n//     return 0;\n// }\n#line 1 \"datastructures/binary_indexed_tree/bit.h\"\
    \ntemplate <class T>\nstruct BIT {\n    int n;\n    vector<T> ft;\n\n    BIT(int\
    \ n_) : n(n_), ft(n + 1) {}\n\n    BIT(const vector<T> &a) : n(sz(a)), ft(n +\
    \ 1) {\n        for (int i = 1; i <= n; i++) {\n            ft[i] += a[i - 1];\n\
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
    \ = time;\n    };\n\n    dfs(dfs, 0, -1);\n\n    BIT<ll> ft(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        ft.add(tin[i], a[i]);\n    }\n    while (q--)\
    \ {\n        bool t;\n        int u;\n        cin >> t >> u;\n        if (t) {\n\
    \            cout << ft.sum(tin[u], tout[u] - 1) << '\\n';\n        } else {\n\
    \            int x;\n            cin >> x;\n            ft.add(tin[u], x);\n \
    \       }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../datastructures/binary_indexed_tree/bit.h\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n \
    \   for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    vector<vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n\
    \        g[p].push_back(i);\n    }\n    \n    int time = 0;\n    vector<int> tin(n),\
    \ tout(n);\n\n    auto dfs = [&](auto &&self, int u, int par) -> void {\n    \
    \    tin[u] = time++;\n        for (int v : g[u]) {\n            if (v != par)\
    \ {\n                self(self, v, u);\n            }\n        }\n        tout[u]\
    \ = time;\n    };\n\n    dfs(dfs, 0, -1);\n\n    BIT<ll> ft(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        ft.add(tin[i], a[i]);\n    }\n    while (q--)\
    \ {\n        bool t;\n        int u;\n        cin >> t >> u;\n        if (t) {\n\
    \            cout << ft.sum(tin[u], tout[u] - 1) << '\\n';\n        } else {\n\
    \            int x;\n            cin >> x;\n            ft.add(tin[u], x);\n \
    \       }\n    }\n}"
  dependsOn:
  - template/template.h
  - utils/bits/stdc++.h
  - datastructures/binary_indexed_tree/bit.h
  isVerificationFile: true
  path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 20:34:38-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp.html
title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
---
