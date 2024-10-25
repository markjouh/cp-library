---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/trees/tree_hashing.h
    title: graphs/trees/tree_hashing.h
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
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
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"verify/library_checker/tree/rooted_tree_isomorphism.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate\
    \ <class T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line\
    \ 1 \"graphs/trees/tree_hashing.h\"\nstruct TreeHashing {\n    map<vector<int>,\
    \ int> hash;\n\n    auto add(const vector<vector<int>> &g, int r = 0) {\n    \
    \    vector<int> res(sz(g));\n        \n        auto dfs = [&](auto &&self, int\
    \ u, int par) -> void {\n            vector<int> ch;\n            for (int v :\
    \ g[u]) {\n                if (v != par) {\n                    self(self, v,\
    \ u);\n                    ch.push_back(res[v]);\n                }\n        \
    \    }\n            sort(all(ch));\n            if (!hash.count(ch)) {\n     \
    \           hash[ch] = sz(hash);\n            }\n            res[u] = hash[ch];\n\
    \        };\n\n        dfs(dfs, r, -1);\n\n        return res;\n    }\n};\n#line\
    \ 5 \"verify/library_checker/tree/rooted_tree_isomorphism.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    cin >> n;\n    vector<vector<int>> g(n);\n    for (int i\
    \ = 1; i < n; i++) {\n        int p;\n        cin >> p;\n        g[p].push_back(i);\n\
    \    }\n    TreeHashing iso;\n    auto res = iso.add(g);\n    cout << sz(iso.hash)\
    \ << '\\n';\n    for (int x : res) {\n        cout << x << ' ';\n    }\n    cout\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../graphs/trees/tree_hashing.h\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<vector<int>> g(n);\n \
    \   for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n       \
    \ g[p].push_back(i);\n    }\n    TreeHashing iso;\n    auto res = iso.add(g);\n\
    \    cout << sz(iso.hash) << '\\n';\n    for (int x : res) {\n        cout <<\
    \ x << ' ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - graphs/trees/tree_hashing.h
  isVerificationFile: true
  path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 19:46:34-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp.html
title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
---
