---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
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
    \ datastructures/sparse_table.hpp: line 7: #pragma once found in a non-first line\n"
  code: "/* A data structure that stores an array of objects with an associative and\n\
    \ * idempotent binary operator.\n * `sparse_table(x)`: O(N * log(N))\n * `query(l,\
    \ r)`: O(1)\n */\n\n#pragma once\n\ntemplate<class T, T(*op)(T, T)> struct sparse_table\
    \ {\n    int n, lg;\n    vector<vector<T>> table;\n\n    sparse_table(const vector<T>\
    \ &a) : n(sz(a)), lg(__lg(n) + 1), table(lg) {\n        table[0] = a;\n      \
    \  for (int i = 1; i < lg; i++) {\n            table[i].resize(n - (1 << i) +\
    \ 1);\n            for (int j = 0; j < sz(table[i]); j++) {\n                table[i][j]\
    \ = op(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);\n            }\n  \
    \      }\n    }\n\n    T query(int l, int r) {\n        assert(l <= r);\n    \
    \    int i = __lg(++r - l);\n        return op(table[i][l], table[i][r - (1 <<\
    \ i)]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/static_rmq.test.cpp
documentation_of: datastructures/sparse_table.hpp
layout: document
redirect_from:
- /library/datastructures/sparse_table.hpp
- /library/datastructures/sparse_table.hpp.html
title: datastructures/sparse_table.hpp
---
