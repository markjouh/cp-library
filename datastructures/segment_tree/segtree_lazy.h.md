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
  bundledCode: "#line 2 \"datastructures/segment_tree/segtree_lazy.h\"\n\ntemplate\
    \ <class T, auto op, auto t_id, class U, auto mapping, auto comp, auto u_id>\n\
    struct LazySegtree {\n    LazySegtree(int n_, T v = t_id()) {\n        init(n_,\
    \ v);\n        pull_all();\n    }\n\n    LazySegtree(const vector<T> &a) {\n \
    \       init(sz(a), t_id());\n        copy(all(a), begin(st) + tree_sz);\n   \
    \     pull_all();\n    }\n\n    void set(int p, T v) {\n        push_path(p +=\
    \ tree_sz);\n        st[p] = v;\n        pull_path(p);\n    }\n\n    void update(int\
    \ p, U v) {\n        push_path(p += tree_sz);\n        st[p] = mapping(st[p],\
    \ v);\n        pull_path(p);\n    }\n\n    void update(int l, int r, U v) {\n\
    \        update(l, r + 1, v, 1, 0, tree_sz);\n    }\n\n    T get_all() {\n   \
    \     return st[1];\n    }\n\n    T get(int p) {\n        push_path(p += tree_sz);\n\
    \        return st[p];\n    }\n\n    T query(int l, int r) {\n        return query(l,\
    \ r + 1, 1, 0, tree_sz);\n    }\n\n    template <class F>\n    int find_first(F\
    \ f) {\n        T pref = t_id();\n        int x = 1;\n        while (x < tree_sz)\
    \ {\n            push(x);\n            if (f(op(pref, st[x << 1]))) {\n      \
    \          x = x << 1;\n            } else {\n                pref = op(pref,\
    \ st[x << 1]);\n                x = x << 1 | 1;\n            }\n        }\n  \
    \      return f(op(pref, st[x])) ? x - tree_sz : n;\n    }\n\n    template <class\
    \ F>\n    int find_last(F f) {\n        T suff = t_id();\n        int x = 1;\n\
    \        while (x < tree_sz) {\n            push(x);\n            if (f(st[x <<\
    \ 1 | 1], suff)) {\n                x = x << 1 | 1;\n            } else {\n  \
    \              suff = op(st[x << 1 | 1], suff);\n                x = x << 1;\n\
    \            }\n        }\n        return f(op(st[x], suff)) ? x - tree_sz : -1;\n\
    \    }\n    \nprivate:\n    int n, log, tree_sz;\n    vector<T> st;\n    vector<U>\
    \ lz;\n\n    void init(int n_, T v) {\n        n = n_;\n        log = __lg(n -\
    \ 1) + 1;\n        tree_sz = 1 << log;\n        st.resize(tree_sz << 1, v);\n\
    \        lz.resize(tree_sz, u_id());\n    }\n\n    void pull(int x) {\n      \
    \  st[x] = op(st[x << 1], st[x << 1 | 1]);\n    }\n\n    void pull_path(int x)\
    \ {\n        for (int i = 1; i <= log; i++) {\n            pull(x >> i);\n   \
    \     }\n    }\n\n    void pull_all() {\n        for (int i = tree_sz - 1; i >\
    \ 0; i--) {\n            pull(i);\n        }\n    }\n\n    void apply(int x) {\n\
    \        st[x] = mapping(st[x], lz[x >> 1]);\n        if (x < tree_sz) {\n   \
    \         lz[x] = comp(lz[x], lz[x >> 1]);\n        }\n    }\n\n    void push(int\
    \ x) {\n        apply(x << 1);\n        apply(x << 1 | 1);\n        lz[x] = u_id();\n\
    \    }\n\n    void push_path(int x) {\n        for (int i = log; i > 0; i--) {\n\
    \            push(x >> i);\n        }\n    }\n\n    void update(int l, int r,\
    \ U v, int x, int tl, int tr) {\n        if (tl >= r || tr <= l) {\n         \
    \   return;\n        }\n        if (tl >= l && tr <= r) {\n            st[x] =\
    \ mapping(st[x], v);\n            if (x < tree_sz) {\n                lz[x] =\
    \ comp(lz[x], v);\n            }\n            return;\n        }\n        push(x);\n\
    \        int mid = (tl + tr) >> 1;\n        update(l, r, v, x << 1, tl, mid);\n\
    \        update(l, r, v, x << 1 | 1, mid, tr);\n        pull(x);\n    }\n\n  \
    \  T query(int l, int r, int x, int tl, int tr) {\n        if (tl >= r || tr <=\
    \ l) {\n            return t_id();\n        }\n        if (tl >= l && tr <= r)\
    \ {\n            return st[x];\n        }\n        push(x);\n        int mid =\
    \ (tl + tr) >> 1;\n        return op(query(l, r, x << 1, tl, mid), query(l, r,\
    \ x << 1 | 1, mid, tr));\n    }\n};\n"
  code: "#pragma once\n\ntemplate <class T, auto op, auto t_id, class U, auto mapping,\
    \ auto comp, auto u_id>\nstruct LazySegtree {\n    LazySegtree(int n_, T v = t_id())\
    \ {\n        init(n_, v);\n        pull_all();\n    }\n\n    LazySegtree(const\
    \ vector<T> &a) {\n        init(sz(a), t_id());\n        copy(all(a), begin(st)\
    \ + tree_sz);\n        pull_all();\n    }\n\n    void set(int p, T v) {\n    \
    \    push_path(p += tree_sz);\n        st[p] = v;\n        pull_path(p);\n   \
    \ }\n\n    void update(int p, U v) {\n        push_path(p += tree_sz);\n     \
    \   st[p] = mapping(st[p], v);\n        pull_path(p);\n    }\n\n    void update(int\
    \ l, int r, U v) {\n        update(l, r + 1, v, 1, 0, tree_sz);\n    }\n\n   \
    \ T get_all() {\n        return st[1];\n    }\n\n    T get(int p) {\n        push_path(p\
    \ += tree_sz);\n        return st[p];\n    }\n\n    T query(int l, int r) {\n\
    \        return query(l, r + 1, 1, 0, tree_sz);\n    }\n\n    template <class\
    \ F>\n    int find_first(F f) {\n        T pref = t_id();\n        int x = 1;\n\
    \        while (x < tree_sz) {\n            push(x);\n            if (f(op(pref,\
    \ st[x << 1]))) {\n                x = x << 1;\n            } else {\n       \
    \         pref = op(pref, st[x << 1]);\n                x = x << 1 | 1;\n    \
    \        }\n        }\n        return f(op(pref, st[x])) ? x - tree_sz : n;\n\
    \    }\n\n    template <class F>\n    int find_last(F f) {\n        T suff = t_id();\n\
    \        int x = 1;\n        while (x < tree_sz) {\n            push(x);\n   \
    \         if (f(st[x << 1 | 1], suff)) {\n                x = x << 1 | 1;\n  \
    \          } else {\n                suff = op(st[x << 1 | 1], suff);\n      \
    \          x = x << 1;\n            }\n        }\n        return f(op(st[x], suff))\
    \ ? x - tree_sz : -1;\n    }\n    \nprivate:\n    int n, log, tree_sz;\n    vector<T>\
    \ st;\n    vector<U> lz;\n\n    void init(int n_, T v) {\n        n = n_;\n  \
    \      log = __lg(n - 1) + 1;\n        tree_sz = 1 << log;\n        st.resize(tree_sz\
    \ << 1, v);\n        lz.resize(tree_sz, u_id());\n    }\n\n    void pull(int x)\
    \ {\n        st[x] = op(st[x << 1], st[x << 1 | 1]);\n    }\n\n    void pull_path(int\
    \ x) {\n        for (int i = 1; i <= log; i++) {\n            pull(x >> i);\n\
    \        }\n    }\n\n    void pull_all() {\n        for (int i = tree_sz - 1;\
    \ i > 0; i--) {\n            pull(i);\n        }\n    }\n\n    void apply(int\
    \ x) {\n        st[x] = mapping(st[x], lz[x >> 1]);\n        if (x < tree_sz)\
    \ {\n            lz[x] = comp(lz[x], lz[x >> 1]);\n        }\n    }\n\n    void\
    \ push(int x) {\n        apply(x << 1);\n        apply(x << 1 | 1);\n        lz[x]\
    \ = u_id();\n    }\n\n    void push_path(int x) {\n        for (int i = log; i\
    \ > 0; i--) {\n            push(x >> i);\n        }\n    }\n\n    void update(int\
    \ l, int r, U v, int x, int tl, int tr) {\n        if (tl >= r || tr <= l) {\n\
    \            return;\n        }\n        if (tl >= l && tr <= r) {\n         \
    \   st[x] = mapping(st[x], v);\n            if (x < tree_sz) {\n             \
    \   lz[x] = comp(lz[x], v);\n            }\n            return;\n        }\n \
    \       push(x);\n        int mid = (tl + tr) >> 1;\n        update(l, r, v, x\
    \ << 1, tl, mid);\n        update(l, r, v, x << 1 | 1, mid, tr);\n        pull(x);\n\
    \    }\n\n    T query(int l, int r, int x, int tl, int tr) {\n        if (tl >=\
    \ r || tr <= l) {\n            return t_id();\n        }\n        if (tl >= l\
    \ && tr <= r) {\n            return st[x];\n        }\n        push(x);\n    \
    \    int mid = (tl + tr) >> 1;\n        return op(query(l, r, x << 1, tl, mid),\
    \ query(l, r, x << 1 | 1, mid, tr));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segment_tree/segtree_lazy.h
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segment_tree/segtree_lazy.h
layout: document
redirect_from:
- /library/datastructures/segment_tree/segtree_lazy.h
- /library/datastructures/segment_tree/segtree_lazy.h.html
title: datastructures/segment_tree/segtree_lazy.h
---
