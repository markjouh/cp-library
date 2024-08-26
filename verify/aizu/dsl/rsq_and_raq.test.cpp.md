---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree_extended.hpp
    title: datastructures/fenwick_tree_extended.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ verify/aizu/dsl/rsq_and_raq.test.cpp: line 22: unable to process #include in\
    \ #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <cstdint>\n#include <cstring>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <vector>\n\n#ifdef LOCAL\n#include \"debug.hpp\"\n#else\n#define dbg(...)\n\
    #endif\n\nusing namespace std;\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing db = double;\n\ntemplate<class\
    \ T> bool ckmin(T &a, const T b) {\n    return b < a ? a = b, 1 : 0;\n}\n\ntemplate<class\
    \ T> bool ckmax(T &a, const T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\n#include\
    \ \"../../../datastructures/fenwick_tree_extended.hpp\"\n\nvoid solve() {\n  \
    \  int n, q;\n    cin >> n >> q;\n    extended_fenwick<ll> ft(n);\n    while (q--)\
    \ {\n        bool t;\n        int l, r;\n        cin >> t >> l >> r;\n       \
    \ l--; r--;\n        if (t) {\n            cout << ft.sum(l, r) << '\\n';\n  \
    \      } else {\n            int x;\n            cin >> x;\n            ft.add(l,\
    \ r, x);\n        }\n    }\n}\n\nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n\n    int t = 1;\n    // cin >> t;\n    while\
    \ (t--) {\n        solve();\n    }\n\n    return 0;\n}"
  dependsOn:
  - datastructures/fenwick_tree_extended.hpp
  - datastructures/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/aizu/dsl/rsq_and_raq.test.cpp
  requiredBy: []
  timestamp: '2024-08-26 18:36:05-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/dsl/rsq_and_raq.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/dsl/rsq_and_raq.test.cpp
- /verify/verify/aizu/dsl/rsq_and_raq.test.cpp.html
title: verify/aizu/dsl/rsq_and_raq.test.cpp
---
