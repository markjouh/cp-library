---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
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
    \ datastructures/union_find.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/* Connectivity data structure limited to edge insertions.\n * `size(x)`,\
    \ `find(x)`, `join(x, y)`: O(a(N)) = ~O(1)\n */\n\n#pragma once\n\nstruct union_find\
    \ {\n    vector<int> a;\n\n    union_find(int n) : a(n, -1) {}\n\n    int size(int\
    \ x) {\n        return -a[find(x)];\n    }\n\n    int find(int x) {\n        return\
    \ a[x] < 0 ? x : a[x] = find(a[x]);\n    }\n\n    bool join(int x, int y) {\n\
    \        x = find(x);\n        y = find(y);\n        if (x == y) {\n         \
    \   return 0;\n        }\n        if (a[x] > a[y]) {\n            swap(x, y);\n\
    \        }\n        a[x] += a[y];\n        a[y] = x;\n        return 1;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/union_find.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/unionfind.test.cpp
documentation_of: datastructures/union_find.hpp
layout: document
redirect_from:
- /library/datastructures/union_find.hpp
- /library/datastructures/union_find.hpp.html
title: datastructures/union_find.hpp
---
