---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree.hpp
    title: datastructures/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ verify/library_checker/data_structure/point_add_range_sum.test.cpp: line 22:\
    \ unable to process #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <cstdint>\n#include <cstring>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <vector>\n\n#ifdef LOCAL\n#include \"debug.hpp\"\n#else\n#define dbg(...)\n\
    #endif\n\nusing namespace std;\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing db = double;\n\ntemplate<class\
    \ T> bool ckmin(T &a, const T b) {\n    return b < a ? a = b, 1 : 0;\n}\n\ntemplate<class\
    \ T> bool ckmax(T &a, const T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\n#include\
    \ \"../../../datastructures/fenwick_tree.hpp\"\n\nvoid solve() {\n    int n, q;\n\
    \    cin >> n >> q;\n    vector<ll> a(n);\n    for (int i = 0; i < n; i++) {\n\
    \        cin >> a[i];\n    }\n    fenwick_tree<ll> ft(a);\n    while (q--) {\n\
    \        bool t;\n        int x, y;\n        cin >> t >> x >> y;\n        if (t)\
    \ {\n            cout << ft.sum(x, y - 1) << '\\n';\n        } else {\n      \
    \      ft.add(x, y);\n        }\n    }\n}\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n\n    int t = 1;\n    // cin >> t;\n    while\
    \ (t--) {\n        solve();\n    }\n\n    return 0;\n}"
  dependsOn:
  - datastructures/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/point_add_range_sum.test.cpp
- /verify/verify/library_checker/data_structure/point_add_range_sum.test.cpp.html
title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
---
