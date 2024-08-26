---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/segment_tree.hpp
    title: datastructures/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ verify/aizu/dsl/rmq.test.cpp: line 22: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <cstdint>\n#include <cstring>\n\
    #include <functional>\n#include <iomanip>\n#include <iostream>\n#include <map>\n\
    #include <numeric>\n#include <queue>\n#include <random>\n#include <set>\n#include\
    \ <vector>\n\n#ifdef LOCAL\n#include \"debug.hpp\"\n#else\n#define dbg(...)\n\
    #endif\n\nusing namespace std;\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing db = double;\n\ntemplate<class\
    \ T> bool ckmin(T &a, const T b) {\n    return b < a ? a = b, 1 : 0;\n}\n\ntemplate<class\
    \ T> bool ckmax(T &a, const T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\n#include\
    \ \"../../../datastructures/segment_tree.hpp\"\n\nint op(int x, int y) {\n   \
    \ return x < y ? x : y;\n}\n\nint id() {\n    return numeric_limits<int>::max();\n\
    }\n\nvoid solve() {\n    int n, q;\n    cin >> n >> q;\n    segment_tree<int,\
    \ op, id> st(n);\n    while (q--) {\n        bool t;\n        int x, y;\n    \
    \    cin >> t >> x >> y;\n        if (t) {\n            cout << st.query(x, y)\
    \ << '\\n';\n        } else {\n            st.set(x, y);\n        }\n    }\n}\n\
    \nint main() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \n    int t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n\
    \n    return 0;\n}"
  dependsOn:
  - datastructures/segment_tree.hpp
  isVerificationFile: true
  path: verify/aizu/dsl/rmq.test.cpp
  requiredBy: []
  timestamp: '2024-08-26 15:34:27-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/dsl/rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/dsl/rmq.test.cpp
- /verify/verify/aizu/dsl/rmq.test.cpp.html
title: verify/aizu/dsl/rmq.test.cpp
---
