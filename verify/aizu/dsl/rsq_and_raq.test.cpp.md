---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree_extended.hpp
    title: Range Add Range Query Fenwick Tree
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ verify/boilerplate.hpp: line 21: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/fenwick_tree_extended.hpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    extended_fenwick<ll>\
    \ ft(n);\n    while (q--) {\n        bool t;\n        int l, r;\n        cin >>\
    \ t >> l >> r;\n        l--; r--;\n        if (t) {\n            cout << ft.sum(l,\
    \ r) << '\\n';\n        } else {\n            int x;\n            cin >> x;\n\
    \            ft.add(l, r, x);\n        }\n    }\n}"
  dependsOn:
  - datastructures/fenwick_tree_extended.hpp
  - datastructures/fenwick_tree.hpp
  isVerificationFile: true
  path: verify/aizu/dsl/rsq_and_raq.test.cpp
  requiredBy: []
  timestamp: '2024-08-26 21:14:45-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/dsl/rsq_and_raq.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/dsl/rsq_and_raq.test.cpp
- /verify/verify/aizu/dsl/rsq_and_raq.test.cpp.html
title: verify/aizu/dsl/rsq_and_raq.test.cpp
---
