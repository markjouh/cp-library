---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/segtree/segment_tree.hpp
    title: datastructures/segtree/segment_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/2006/submission/280125218
  bundledCode: "#line 2 \"datastructures/segtree/segment_tree_set.hpp\"\n\n// https://codeforces.com/contest/2006/submission/280125218\n\
    \n#line 2 \"datastructures/segtree/segment_tree.hpp\"\n\ntemplate <class T, T(*op)(T,\
    \ T), T(*id)()>\nstruct SegmentTree {\n  int n;\n  vector<T> st;\n\n  SegmentTree(int\
    \ sz) : n(sz), st(2 * n, id()) {}\n\n  SegmentTree(const vector<T> &a) : n(sz(a)),\
    \ st(2 * n) {\n    copy(begin(a), end(a), begin(st) + n);\n    for (int i = n\
    \ - 1; i > 0; i--) {\n      st[i] = op(st[i << 1], st[i << 1 | 1]);\n    }\n \
    \ }\n\n  T get(int p) {\n    return st[p + n];\n  }\n\n  T query(int l, int r)\
    \ {\n    T ls = id(), rs = id();\n    for (l += n, r += n + 1; l < r; l >>= 1,\
    \ r >>= 1) {\n      if (l & 1) {\n        ls = op(ls, st[l++]);\n      }\n   \
    \   if (r & 1) {\n        rs = op(st[--r], rs);\n      }\n    }\n    return op(ls,\
    \ rs);\n  }\n\n  void set(int p, T val) {\n    for (st[p += n] = val, p >>= 1;\
    \ p > 0; p >>= 1) {\n      st[p] = op(st[p << 1], st[p << 1 | 1]);\n    }\n  }\n\
    };\n#line 6 \"datastructures/segtree/segment_tree_set.hpp\"\n\ntemplate <class\
    \ T, T(*op)(T, T), T(*id)()>\nstruct SegmentTreeSet {\n  int n;\n  set<int> free;\n\
    \  set<pair<T, int>> used;\n  SegmentTree<T, op, id> st;\n\n  SegmentTreeSet(int\
    \ n_) : n(n_), st(n) {\n    for (int i = 0; i < n; i++) {\n      free.insert(i);\n\
    \    }\n  }\n\n  void insert(T x) {\n    assert(!free.empty());\n    T p = *begin(free);\n\
    \    free.erase(begin(free));\n    st.set(p, x);\n    used.emplace(x, p);\n  }\n\
    \n  void extract(T x) {\n    auto it = used.lower_bound({x, -1});\n    assert(it->fi\
    \ == x);\n    st.set(it->se, id());\n    free.insert(it->se);\n    used.erase(it);\n\
    \  }\n\n  T query() {\n    return st.query(0, n - 1);\n  }\n};\n"
  code: "#pragma once\n\n// https://codeforces.com/contest/2006/submission/280125218\n\
    \n#include \"segment_tree.hpp\"\n\ntemplate <class T, T(*op)(T, T), T(*id)()>\n\
    struct SegmentTreeSet {\n  int n;\n  set<int> free;\n  set<pair<T, int>> used;\n\
    \  SegmentTree<T, op, id> st;\n\n  SegmentTreeSet(int n_) : n(n_), st(n) {\n \
    \   for (int i = 0; i < n; i++) {\n      free.insert(i);\n    }\n  }\n\n  void\
    \ insert(T x) {\n    assert(!free.empty());\n    T p = *begin(free);\n    free.erase(begin(free));\n\
    \    st.set(p, x);\n    used.emplace(x, p);\n  }\n\n  void extract(T x) {\n  \
    \  auto it = used.lower_bound({x, -1});\n    assert(it->fi == x);\n    st.set(it->se,\
    \ id());\n    free.insert(it->se);\n    used.erase(it);\n  }\n\n  T query() {\n\
    \    return st.query(0, n - 1);\n  }\n};"
  dependsOn:
  - datastructures/segtree/segment_tree.hpp
  isVerificationFile: false
  path: datastructures/segtree/segment_tree_set.hpp
  requiredBy: []
  timestamp: '2024-09-07 12:53:26-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segtree/segment_tree_set.hpp
layout: document
redirect_from:
- /library/datastructures/segtree/segment_tree_set.hpp
- /library/datastructures/segtree/segment_tree_set.hpp.html
title: datastructures/segtree/segment_tree_set.hpp
---
