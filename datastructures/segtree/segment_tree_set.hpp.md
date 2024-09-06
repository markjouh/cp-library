---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/2006/submission/280125218
  bundledCode: "#line 2 \"datastructures/segtree/segment_tree_set.hpp\"\n\n// https://codeforces.com/contest/2006/submission/280125218\n\
    \ntemplate <class T, T(*op)(T, T), T(*id)()>\nstruct SegmentTreeSet {\n  int n;\n\
    \  set<int> free;\n  set<pair<T, int>> used;\n  SegmentTree<T, op, id> st;\n\n\
    \  SegmentTreeSet(int n_) : n(n_), st(n) {\n    for (int i = 0; i < n; i++) {\n\
    \      free.insert(i);\n    }\n  }\n\n  void insert(T x) {\n    assert(!free.empty());\n\
    \    T p = *begin(free);\n    free.erase(begin(free));\n    st.set(p, x);\n  \
    \  used.emplace(x, p);\n  }\n\n  void extract(T x) {\n    auto it = used.lower_bound({x,\
    \ -1});\n    assert(it->fi == x);\n    st.set(it->se, id());\n    free.insert(it->se);\n\
    \    used.erase(it);\n  }\n\n  T query() {\n    return st.query(0, n - 1);\n \
    \ }\n};\n"
  code: "#pragma once\n\n// https://codeforces.com/contest/2006/submission/280125218\n\
    \ntemplate <class T, T(*op)(T, T), T(*id)()>\nstruct SegmentTreeSet {\n  int n;\n\
    \  set<int> free;\n  set<pair<T, int>> used;\n  SegmentTree<T, op, id> st;\n\n\
    \  SegmentTreeSet(int n_) : n(n_), st(n) {\n    for (int i = 0; i < n; i++) {\n\
    \      free.insert(i);\n    }\n  }\n\n  void insert(T x) {\n    assert(!free.empty());\n\
    \    T p = *begin(free);\n    free.erase(begin(free));\n    st.set(p, x);\n  \
    \  used.emplace(x, p);\n  }\n\n  void extract(T x) {\n    auto it = used.lower_bound({x,\
    \ -1});\n    assert(it->fi == x);\n    st.set(it->se, id());\n    free.insert(it->se);\n\
    \    used.erase(it);\n  }\n\n  T query() {\n    return st.query(0, n - 1);\n \
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segtree/segment_tree_set.hpp
  requiredBy: []
  timestamp: '2024-09-06 17:58:54-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segtree/segment_tree_set.hpp
layout: document
redirect_from:
- /library/datastructures/segtree/segment_tree_set.hpp
- /library/datastructures/segtree/segment_tree_set.hpp.html
title: datastructures/segtree/segment_tree_set.hpp
---
