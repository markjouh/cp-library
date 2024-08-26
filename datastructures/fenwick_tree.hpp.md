---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree_extended.hpp
    title: datastructures/fenwick_tree_extended.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructures/fenwick_tree.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/* A data structure that supports point updates and range queries\n * or\
    \ vice versa with modificiations.\n * `add(x, y)`, `sum(x, y)`: O(log(y))\n */\n\
    \n#pragma once\n\ntemplate<class T> struct fenwick_tree {\n    int n;\n    vector<T>\
    \ tree;\n\n    fenwick_tree(int x) : n(x), tree(n + 1) {}\n\n    fenwick_tree(const\
    \ vector<T> &a) : n(sz(a)), tree(n + 1) {\n        for (int i = 1; i <= n; i++)\
    \ {\n            tree[i] += a[i - 1];\n            if (i + (i & -i) <= n) {\n\
    \                tree[i + (i & -i)] += tree[i];\n            }\n        }\n  \
    \  }\n\n    void add(int p, T v) {\n        assert(p >= 0);\n        for (p++;\
    \ p <= n; p += p & -p) {\n            tree[p] += v;\n        }\n    }\n\n    T\
    \ sum(int r) {\n        assert(r < n);\n        T res = 0;\n        for (r++;\
    \ r > 0; r -= r & -r) {\n            res += tree[r];\n        }\n        return\
    \ res;\n    }\n\n    T sum(int l, int r) {\n        return sum(r) - sum(l - 1);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/fenwick_tree.hpp
  requiredBy:
  - datastructures/fenwick_tree_extended.hpp
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
documentation_of: datastructures/fenwick_tree.hpp
layout: document
redirect_from:
- /library/datastructures/fenwick_tree.hpp
- /library/datastructures/fenwick_tree.hpp.html
title: datastructures/fenwick_tree.hpp
---
