---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
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
    \ datastructures/segment_tree.hpp: line 7: #pragma once found in a non-first line\n"
  code: "/* A data structure that stores an array of objects with an identity element\n\
    \ * and associative binary operator.\n * `segment_tree(x)`: O(N)\n * `update(x,\
    \ y)`, `query(x, y)`: O(log(N))\n */\n\n#pragma once\n\ntemplate<class T, T(*op)(T,\
    \ T), T(*id)()> struct segment_tree {\n    int n;\n    vector<T> tree;\n\n   \
    \ segment_tree(int sz) : n(sz), tree(2 * n, id()) {}\n\n    segment_tree(const\
    \ vector<T> &a) : n(sz(a)), tree(2 * n) {\n        copy(begin(a), end(a), begin(tree)\
    \ + n);\n        for (int i = n - 1; i > 0; i--) {\n            tree[i] = op(tree[i\
    \ << 1], tree[i << 1 | 1]);\n        }\n    }\n\n    T query(int l, int r) {\n\
    \        T ls = id(), rs = id();\n        for (l += n, r += n + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) {\n                ls = op(ls, tree[l++]);\n\
    \            }\n            if (r & 1) {\n                rs = op(tree[--r], rs);\n\
    \            }\n        }\n        return op(ls, rs);\n    }\n\n    void set(int\
    \ p, T val) {\n        for (tree[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n \
    \           tree[p] = op(tree[p << 1], tree[p << 1 | 1]);\n        }\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segment_tree.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/dsl/rmq.test.cpp
documentation_of: datastructures/segment_tree.hpp
layout: document
redirect_from:
- /library/datastructures/segment_tree.hpp
- /library/datastructures/segment_tree.hpp.html
title: datastructures/segment_tree.hpp
---
