---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree.hpp
    title: datastructures/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
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
    \ datastructures/fenwick_tree_extended.hpp: line 5: #pragma once found in a non-first\
    \ line\n"
  code: "/* Uses 2 fenwick trees to support both range updates and range queries.\n\
    \ * `add(l, r, v)`, `sum(l, r)`: O(log(r))\n */\n\n#pragma once\n#include \"fenwick_tree.hpp\"\
    \n\ntemplate<class T> struct extended_fenwick {\n    int n;\n    fenwick_tree<T>\
    \ inside, outside;\n\n    extended_fenwick(int x) : n(x), inside(n), outside(n)\
    \ {}\n\n    T sum(int r) {\n        return inside.sum(r - 1) + outside.sum(n -\
    \ r - 1) * (r + 1);\n    }\n\n    T sum(int l, int r) {\n        return sum(r)\
    \ - (l > 0 ? sum(l - 1) : 0);\n    }\n\n    void add(int r, T v) {\n        inside.add(r,\
    \ v * (r + 1));\n        outside.add(n - r - 1, v);\n    }\n\n    void add(int\
    \ l, int r, T v) {\n        add(r, v);\n        if (l > 0) {\n            add(l\
    \ - 1, T(0) - T(v));\n        }\n    }\n};\n"
  dependsOn:
  - datastructures/fenwick_tree.hpp
  isVerificationFile: false
  path: datastructures/fenwick_tree_extended.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rsq_and_raq.test.cpp
documentation_of: datastructures/fenwick_tree_extended.hpp
layout: document
redirect_from:
- /library/datastructures/fenwick_tree_extended.hpp
- /library/datastructures/fenwick_tree_extended.hpp.html
title: datastructures/fenwick_tree_extended.hpp
---
