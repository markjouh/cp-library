---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/trees/tree_hashing.h
    title: graphs/trees/tree_hashing.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  - icon: ':question:'
    path: utils/bits/stdc++.h
    title: utils/bits/stdc++.h
  - icon: ':question:'
    path: utils/compat.h
    title: utils/compat.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/random.h
    title: utils/random.h
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
    \n\n#line 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n\
    #define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l);\
    \ i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__,\
    \ rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1;\
    \ i >= int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__,\
    \ per3, per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\n#define pb push_back\n#define eb emplace_back\n#define fi first\n\
    #define se second\n\nusing ll = long long;\nusing ld = long double;\nusing pi\
    \ = pair<int, int>;\nusing pl = pair<ll, ll>;\n\ntemplate <class T> using vec\
    \ = vector<T>;\nusing vb = vec<bool>;\nusing vi = vec<int>; \nusing vl = vec<ll>;\n\
    using vd = vec<ld>;\nusing vs = vec<string>;\nusing vpi = vec<pi>;\nusing vpl\
    \ = vec<pl>;\n\ntemplate <class T, size_t N> using arr = array<T, N>;\ntemplate\
    \ <size_t N> using ai = array<int, N>;\ntemplate <size_t N> using al = array<ll,\
    \ N>;\n\ntemplate <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b,\
    \ 1 : 0; \n}\ntemplate <class T>\nbool ckmax(T &a, T b) {\n    return b > a ?\
    \ a = b, 1 : 0;\n}\n\ntemplate <class T, class U>\nT bsmin(T lo, T hi, U f) {\n\
    \    assert(lo <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return\
    \ hi;\n}\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo\
    \ <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n\
    \        lo += (lo + i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}\n\n\
    const int INF = 1e9;\nconst ll INFL = 1e18;\n\n// void solve() {\n// }\n\n// int32_t\
    \ main() {\n//     cin.tie(0)->sync_with_stdio(0);\n//     cin.exceptions(cin.failbit);\n\
    \n//     int t = 1;\n//     // cin >> t;\n//     while (t--) {\n//         solve();\n\
    //     }\n\n//     return 0;\n// }\n#line 1 \"graphs/trees/tree_hashing.h\"\n\
    struct tree_hashing {\n    map<vector<int>, int> hash;\n\n    auto add(const vector<vector<int>>\
    \ &g, int r = 0) {\n        vector<int> res(sz(g));\n        \n        auto dfs\
    \ = [&](auto &&self, int u, int par) -> void {\n            vector<int> ch;\n\
    \            for (int v : g[u]) {\n                if (v != par) {\n         \
    \           self(self, v, u);\n                    ch.push_back(res[v]);\n   \
    \             }\n            }\n            sort(all(ch));\n            if (!hash.count(ch))\
    \ {\n                hash[ch] = sz(hash);\n            }\n            res[u] =\
    \ hash[ch];\n        };\n\n        dfs(dfs, r, -1);\n\n        return res;\n \
    \   }\n};\n#line 5 \"verify/library_checker/tree/rooted_tree_isomorphism.test.cpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<vector<int>> g(n);\n \
    \   for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n       \
    \ g[p].push_back(i);\n    }\n    tree_hashing iso;\n    auto res = iso.add(g);\n\
    \    cout << sz(iso.hash) << '\\n';\n    for (int x : res) {\n        cout <<\
    \ x << ' ';\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../graphs/trees/tree_hashing.h\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<vector<int>> g(n);\n \
    \   for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n       \
    \ g[p].push_back(i);\n    }\n    tree_hashing iso;\n    auto res = iso.add(g);\n\
    \    cout << sz(iso.hash) << '\\n';\n    for (int x : res) {\n        cout <<\
    \ x << ' ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - template/template.h
  - utils/bits/stdc++.h
  - utils/compat.h
  - utils/debug.h
  - utils/random.h
  - graphs/trees/tree_hashing.h
  isVerificationFile: true
  path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
- /verify/verify/library_checker/tree/rooted_tree_isomorphism.test.cpp.html
title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
---
