---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/trees/tree_isomorphism.h
    title: graphs/trees/tree_isomorphism.h
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
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"verify/library_checker/tree/rooted_tree_isomorphism.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\nusing\
    \ ld = long double;\n\ntemplate <class T>\nbool ckmin(T &a, T b) {\n    return\
    \ b < a ? a = b, 1 : 0;\n}\ntemplate <class T>\nbool ckmax(T &a, T b) {\n    return\
    \ b > a ? a = b, 1 : 0;\n}\n#line 2 \"graphs/trees/tree_isomorphism.h\"\n\nstruct\
    \ TreeIsomorphism {\n    map<vector<int>, int> hashes;\n\n    vector<int> gen(const\
    \ vector<vector<int>> &g, int rt = 0) {\n        vector<int> res(sz(g));\n   \
    \     dfs(rt, -1, g, res);\n        return res;\n    }\n\nprivate:\n    void dfs(int\
    \ u, int par, auto &g, auto &res) {\n        vector<int> children;\n        for\
    \ (int v : g[u]) {\n            if (v != par) {\n                dfs(v, u, g,\
    \ res);\n                children.push_back(res[v]);\n            }\n        }\n\
    \        sort(all(children));\n        if (!hashes.count(children)) {\n      \
    \      hashes[children] = sz(hashes);\n        }\n        res[u] = hashes[children];\n\
    \    }\n};\n#line 5 \"verify/library_checker/tree/rooted_tree_isomorphism.test.cpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<vector<int>> g(n);\n \
    \   for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n       \
    \ g[p].push_back(i);\n    }\n    TreeIsomorphism iso;\n    auto res = iso.gen(g);\n\
    \    cout << sz(iso.hashes) << '\\n';\n    for (int x : res) {\n        cout <<\
    \ x << ' ';\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../graphs/trees/tree_isomorphism.h\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<vector<int>> g(n);\n \
    \   for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n       \
    \ g[p].push_back(i);\n    }\n    TreeIsomorphism iso;\n    auto res = iso.gen(g);\n\
    \    cout << sz(iso.hashes) << '\\n';\n    for (int x : res) {\n        cout <<\
    \ x << ' ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - graphs/trees/tree_isomorphism.h
  isVerificationFile: true
  path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp.html
title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
---
