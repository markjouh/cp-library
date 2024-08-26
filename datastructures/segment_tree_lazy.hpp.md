---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructures/segment_tree_lazy.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/* A standard segment tree with lazy updates.\n * `segment_tree(x)`: O(N)`\n\
    \ * `update(l, r, v)`, `query(l, r)`: O(log(N))\n */\n\n#pragma once\n\ntemplate<class\
    \ T> struct lazy_segtree {\n    const T id = 0;\n    const T lz_id = 0;\n\n  \
    \  T merge(T a, T b) {\n        return a + b;\n    }\n\n    void push(int x, int\
    \ tl, int tr) {\n        if (lazy[x] != lz_id) {\n            tree[x] += (tr -\
    \ tl) * lazy[x]; // Make sure this checks out!\n            if (tl + 1 != tr)\
    \ {\n                lazy[2 * x + 1] += lazy[x];\n                lazy[2 * x +\
    \ 2] += lazy[x];\n            }\n            lazy[x] = lz_id;\n        }\n   \
    \ }\n\n    // Modify above ^^\n\n    lazy_segtree(int x) {\n        init(x);\n\
    \    }\n\n    lazy_segtree(const vector<T> &a) {\n        init(sz(a));\n     \
    \   build(a, 0, 0, n);\n    }\n\n    T query(int l, int r) {\n        return query(l,\
    \ r + 1, 0, 0, n);\n    }\n\n    void update(int l, int r, int v) {\n        update(l,\
    \ r + 1, v, 0, 0, n);\n    }\n\n    // int walk() {\n    //     return walk(0,\
    \ 0, n);\n    // }\n\nprivate:\n    int n;\n    vector<T> tree, lazy;\n\n    void\
    \ init(int sz) {\n        n = 1;\n        while (n < sz) {\n            n *= 2;\n\
    \        }\n        tree.resize(2 * n, id);\n        lazy.resize(2 * n, lz_id);\n\
    \    }\n\n    void build(vector<T> &a, int x, int tl, int tr) {\n        if (tl\
    \ + 1 == tr) {\n            if (tl < sz(a)) {\n                tree[x] = a[tl];\n\
    \            }\n            return;\n        }\n        int mid = (tl + tr) /\
    \ 2;\n        build(a, 2 * x + 1, tl, mid);\n        build(a, 2 * x + 2, mid,\
    \ tr);\n        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);\n    }\n\n\
    \    T query(int l, int r, int x, int tl, int tr) {\n        push(x, tl, tr);\n\
    \        if (tl >= r || tr <= l) {\n            return id;\n        }\n      \
    \  if (tl >= l && tr <= r) {\n            return tree[x];\n        }\n       \
    \ int mid = (tl + tr) / 2;\n        return merge(query(l, r, 2 * x + 1, tl, mid),\
    \ query(l, r, 2 * x + 2, mid, tr));\n    }\n\n    void update(int l, int r, int\
    \ v, int x, int tl, int tr) {\n        push(x, tl, tr);\n        if (tl >= r ||\
    \ tr <= l) {\n            return;\n        }\n        if (tl >= l && tr <= r)\
    \ {\n            lazy[x] += v;\n            push(x, tl, tr);\n            return;\n\
    \        }\n        int mid = (tl + tr) / 2;\n        update(l, r, v, 2 * x +\
    \ 1, tl, mid);\n        update(l, r, v, 2 * x + 2, mid, tr);\n        tree[x]\
    \ = merge(tree[2 * x + 1], tree[2 * x + 2]);\n    }\n\n    // int walk(int x,\
    \ int tl, int tr) {\n    //     push(x, tl, tr);\n    //     if (tl + 1 == tr)\
    \ {\n    //         return tl;\n    //     }\n    //     int mid = (tl + tr) /\
    \ 2;\n    //     push(2 * x + 1, tl, mid);\n    //     push(2 * x + 2, mid, tr);\n\
    \    //     if (...) {\n    //         return walk(2 * x + 1, tl, mid);\n    //\
    \     } else {\n    //         return walk(2 * x + 2, mid, tr);\n    //     }\n\
    \    // }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segment_tree_lazy.hpp
  requiredBy: []
  timestamp: '2024-08-26 11:12:12-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segment_tree_lazy.hpp
layout: document
redirect_from:
- /library/datastructures/segment_tree_lazy.hpp
- /library/datastructures/segment_tree_lazy.hpp.html
title: datastructures/segment_tree_lazy.hpp
---
