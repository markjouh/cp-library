---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/segment_tree/segtree.h
    title: datastructures/segment_tree/segtree.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"datastructures/segment_tree/segtree.h\"\ntemplate <class\
    \ T, auto op, auto id>\nstruct segtree {\n    int n;\n    vector<T> st;\n\n  \
    \  segtree(int n_) : n(n_), st(2 * n, id()) {}\n\n    segtree(const vector<T>\
    \ &a) : n(sz(a)), st(2 * n) {\n        copy(all(a), begin(st) + n);\n        for\
    \ (int i = n - 1; i > 0; i--) {\n            st[i] = op(st[i << 1], st[i << 1\
    \ | 1]);\n        }\n    }\n\n    T get(int p) {\n        return st[p + n];\n\
    \    }\n\n    T query(int l, int r) {\n        T ls = id(), rs = id();\n     \
    \   for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1)\
    \ {\n                ls = op(ls, st[l++]);\n            }\n            if (r &\
    \ 1) {\n                rs = op(st[--r], rs);\n            }\n        }\n    \
    \    return op(ls, rs);\n    }\n\n    void set(int p, T val) {\n        for (st[p\
    \ += n] = val, p >>= 1; p > 0; p >>= 1) {\n            st[p] = op(st[p << 1],\
    \ st[p << 1 | 1]);\n        }\n    }\n};\n#line 2 \"datastructures/segment_tree/segtree_set.h\"\
    \n\ntemplate <class T, auto op, auto id>\nstruct segtree_set {\n    int n;\n \
    \   set<int> free;\n    set<pair<T, int>> used;\n    Segtree<T, op, id> st;\n\n\
    \    segtree_set(int n_) : n(n_), st(n) {\n        for (int i = 0; i < n; i++)\
    \ {\n            free.insert(i);\n        }\n    }\n\n    void insert(T x) {\n\
    \        assert(!free.empty());\n        T p = *begin(free);\n        free.erase(begin(free));\n\
    \        st.set(p, x);\n        used.emplace(x, p);\n    }\n\n    void remove(T\
    \ x) {\n        auto it = used.lower_bound({x, -1});\n        assert(it->first\
    \ == x);\n        st.set(it->second, id());\n        free.insert(it->second);\n\
    \        used.erase(it);\n    }\n\n    T query() {\n        return st.query(0,\
    \ n - 1);\n    }\n};\n"
  code: "#include \"segtree.h\"\n\ntemplate <class T, auto op, auto id>\nstruct segtree_set\
    \ {\n    int n;\n    set<int> free;\n    set<pair<T, int>> used;\n    Segtree<T,\
    \ op, id> st;\n\n    segtree_set(int n_) : n(n_), st(n) {\n        for (int i\
    \ = 0; i < n; i++) {\n            free.insert(i);\n        }\n    }\n\n    void\
    \ insert(T x) {\n        assert(!free.empty());\n        T p = *begin(free);\n\
    \        free.erase(begin(free));\n        st.set(p, x);\n        used.emplace(x,\
    \ p);\n    }\n\n    void remove(T x) {\n        auto it = used.lower_bound({x,\
    \ -1});\n        assert(it->first == x);\n        st.set(it->second, id());\n\
    \        free.insert(it->second);\n        used.erase(it);\n    }\n\n    T query()\
    \ {\n        return st.query(0, n - 1);\n    }\n};"
  dependsOn:
  - datastructures/segment_tree/segtree.h
  isVerificationFile: false
  path: datastructures/segment_tree/segtree_set.h
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segment_tree/segtree_set.h
layout: document
redirect_from:
- /library/datastructures/segment_tree/segtree_set.h
- /library/datastructures/segment_tree/segtree_set.h.html
title: datastructures/segment_tree/segtree_set.h
---