---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/dijkstras.hpp
    title: graphs/dijkstras.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ verify/library_checker/graph/shortest_path.test.cpp: line 22: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n#include\
    \ <chrono>\n#include <cmath>\n#include <cstdint>\n#include <cstring>\n#include\
    \ <functional>\n#include <iomanip>\n#include <iostream>\n#include <map>\n#include\
    \ <numeric>\n#include <queue>\n#include <random>\n#include <set>\n#include <vector>\n\
    \n#ifdef LOCAL\n#include \"debug.hpp\"\n#else\n#define dbg(...)\n#endif\n\nusing\
    \ namespace std;\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    \nusing ll = long long;\nusing db = double;\n\ntemplate<class T> bool ckmin(T\
    \ &a, const T b) {\n    return b < a ? a = b, 1 : 0;\n}\n\ntemplate<class T> bool\
    \ ckmax(T &a, const T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\n#include \"\
    ../../../graphs/dijkstras.hpp\"\n\nvoid solve() {\n    int n, m, s, t;\n    cin\
    \ >> n >> m >> s >> t;\n    vector<vector<pair<int, int>>> g(n);\n    for (int\
    \ i = 0; i < m; i++) {\n        int u, v, w;\n        cin >> u >> v >> w;\n  \
    \      g[u].emplace_back(v, w);\n    }\n    auto [dist, from] = dijkstras<ll>(g,\
    \ s);\n    if (dist[t] != numeric_limits<ll>::max()) {\n        cout << dist[t]\
    \ << ' ';\n        vector<pair<int, int>> path;\n        int p = t;\n        while\
    \ (p != s) {\n            path.emplace_back(from[p], p);\n            p = from[p];\n\
    \        }\n        reverse(all(path));\n        cout << sz(path) << '\\n';\n\
    \        for (auto [u, v] : path) {\n            cout << u << ' ' << v << '\\\
    n';\n        }\n    } else {\n        cout << -1 << '\\n';\n    }\n}\n\nint main()\
    \ {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\n\
    \    int t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n\
    \n    return 0;\n}"
  dependsOn:
  - graphs/dijkstras.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-08-26 15:21:12-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/shortest_path.test.cpp
- /verify/verify/library_checker/graph/shortest_path.test.cpp.html
title: verify/library_checker/graph/shortest_path.test.cpp
---