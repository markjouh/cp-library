---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/segment_tree/segtree_sparse.h\"\n\ntemplate\
    \ <class T, auto op, auto id>\nstruct SegtreeSparse {\n    SegtreeSparse() {}\n\
    \    \n    SegtreeSparse(int n) {\n        log = __lg(n) + 1;\n        tree_sz\
    \ = 1 << log;\n        st.push_back(id());\n        ch.emplace_back(-1, -1);\n\
    \    }\n\n    void set(int p, T v) {\n        buf[0] = idx = 0;\n        int tl\
    \ = 0, tr = tree_sz;\n        while (tl + 1 != tr) {\n            int mid = (tl\
    \ + tr) >> 1;\n            if (p < mid) {\n                buf[idx + 1] = get_l(buf[idx]);\n\
    \                tr = mid;\n            } else {\n                buf[idx + 1]\
    \ = get_r(buf[idx]);\n                tl = mid;\n            }\n            idx++;\n\
    \        }\n        st[buf[idx--]] = v;\n        while (idx >= 0) {\n        \
    \    pull(buf[idx--]);\n        }\n    }\n\n    T query(int l, int r) {\n    \
    \    return get(l, r + 1, 0, 0, tree_sz);\n    }\n\nprivate:\n    int log, tree_sz;\n\
    \    vector<T> st;\n    vector<pair<int, int>> ch;\n\n    int buf[32];\n    int\
    \ idx;\n\n    int get_l(int x) {\n        if (ch[x].first == -1) {\n         \
    \   ch[x].first = sz(st);\n            st.push_back(id());\n            ch.emplace_back(-1,\
    \ -1);\n        }\n        return ch[x].first;\n    }\n\n    int get_r(int x)\
    \ {\n        if (ch[x].second == -1) {\n            ch[x].second = sz(st);\n \
    \           st.push_back(id());\n            ch.emplace_back(-1, -1);\n      \
    \  }\n        return ch[x].second;\n    }\n\n    void pull(int x) {\n        if\
    \ (ch[x].first == -1) {\n            st[x] = st[ch[x].second];\n        } else\
    \ if (ch[x].second != -1) {\n            st[x] = op(st[ch[x].first], st[ch[x].second]);\n\
    \        } else {\n            st[x] = st[ch[x].first];\n        }\n    }\n\n\
    \    T get(int l, int r, int x, int tl, int tr) {\n        if (x == -1 || tl >=\
    \ r || tr <= l) {\n            return id();\n        }\n        if (tl >= l &&\
    \ tr <= r) {\n            return st[x];\n        }\n        int mid = (tl + tr)\
    \ >> 1;\n        return op(get(l, r, ch[x].first, tl, mid), get(l, r, ch[x].second,\
    \ mid, tr));\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T, auto op, auto id>\nstruct SegtreeSparse\
    \ {\n    SegtreeSparse() {}\n    \n    SegtreeSparse(int n) {\n        log = __lg(n)\
    \ + 1;\n        tree_sz = 1 << log;\n        st.push_back(id());\n        ch.emplace_back(-1,\
    \ -1);\n    }\n\n    void set(int p, T v) {\n        buf[0] = idx = 0;\n     \
    \   int tl = 0, tr = tree_sz;\n        while (tl + 1 != tr) {\n            int\
    \ mid = (tl + tr) >> 1;\n            if (p < mid) {\n                buf[idx +\
    \ 1] = get_l(buf[idx]);\n                tr = mid;\n            } else {\n   \
    \             buf[idx + 1] = get_r(buf[idx]);\n                tl = mid;\n   \
    \         }\n            idx++;\n        }\n        st[buf[idx--]] = v;\n    \
    \    while (idx >= 0) {\n            pull(buf[idx--]);\n        }\n    }\n\n \
    \   T query(int l, int r) {\n        return get(l, r + 1, 0, 0, tree_sz);\n  \
    \  }\n\nprivate:\n    int log, tree_sz;\n    vector<T> st;\n    vector<pair<int,\
    \ int>> ch;\n\n    int buf[32];\n    int idx;\n\n    int get_l(int x) {\n    \
    \    if (ch[x].first == -1) {\n            ch[x].first = sz(st);\n           \
    \ st.push_back(id());\n            ch.emplace_back(-1, -1);\n        }\n     \
    \   return ch[x].first;\n    }\n\n    int get_r(int x) {\n        if (ch[x].second\
    \ == -1) {\n            ch[x].second = sz(st);\n            st.push_back(id());\n\
    \            ch.emplace_back(-1, -1);\n        }\n        return ch[x].second;\n\
    \    }\n\n    void pull(int x) {\n        if (ch[x].first == -1) {\n         \
    \   st[x] = st[ch[x].second];\n        } else if (ch[x].second != -1) {\n    \
    \        st[x] = op(st[ch[x].first], st[ch[x].second]);\n        } else {\n  \
    \          st[x] = st[ch[x].first];\n        }\n    }\n\n    T get(int l, int\
    \ r, int x, int tl, int tr) {\n        if (x == -1 || tl >= r || tr <= l) {\n\
    \            return id();\n        }\n        if (tl >= l && tr <= r) {\n    \
    \        return st[x];\n        }\n        int mid = (tl + tr) >> 1;\n       \
    \ return op(get(l, r, ch[x].first, tl, mid), get(l, r, ch[x].second, mid, tr));\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segment_tree/segtree_sparse.h
  requiredBy: []
  timestamp: '2024-10-25 19:29:34-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segment_tree/segtree_sparse.h
layout: document
redirect_from:
- /library/datastructures/segment_tree/segtree_sparse.h
- /library/datastructures/segment_tree/segtree_sparse.h.html
title: datastructures/segment_tree/segtree_sparse.h
---
