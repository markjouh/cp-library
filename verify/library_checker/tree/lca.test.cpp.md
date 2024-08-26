---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/binary_lifts.hpp
    title: graphs/binary_lifts.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ verify/library_checker/tree/lca.test.cpp: line 22: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include <algorithm>\n\
    #include <array>\n#include <bitset>\n#include <cassert>\n#include <chrono>\n#include\
    \ <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <vector>\n\n#ifdef LOCAL\n\
    #include \"debug.hpp\"\n#else\n#define dbg(...)\n#endif\n\nusing namespace std;\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long\
    \ long;\nusing db = double;\n\ntemplate<class T> bool ckmin(T &a, const T b) {\n\
    \    return b < a ? a = b, 1 : 0;\n}\n\ntemplate<class T> bool ckmax(T &a, const\
    \ T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\n#include \"../../../graphs/binary_lifts.hpp\"\
    \n\nvoid solve() {\n    int n, q;\n    cin >> n >> q;\n    vector<vector<int>>\
    \ g(n);\n    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n\
    \        g[p].push_back(i);\n    }\n    binary_lifts bl(g);\n    while (q--) {\n\
    \        int u, v;\n        cin >> u >> v;\n        cout << bl.lca(u, v) << '\\\
    n';\n    }\n}\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \n    int t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n\
    \n    return 0;\n}"
  dependsOn:
  - graphs/binary_lifts.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/lca.test.cpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/lca.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/lca.test.cpp
- /verify/verify/library_checker/tree/lca.test.cpp.html
title: verify/library_checker/tree/lca.test.cpp
---
