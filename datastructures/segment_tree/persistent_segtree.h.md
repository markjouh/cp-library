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
  bundledCode: "#line 1 \"datastructures/segment_tree/persistent_segtree.h\"\ntemplate\
    \ <class T, auto op, auto id>\nstruct persistent_segtree {\n    int log, tree_sz,\
    \ updates;\n    vector<T> st;\n    vector<array<int, 2>> ch;\n\n    persistent_segtree()\
    \ {}\n\n    persistent_segtree(int n) {\n        log = __lg(n) + 1;\n        tree_sz\
    \ = 1 << log;\n        st.resize(tree_sz << 1, id());\n        ch.resize(tree_sz\
    \ << 1);\n        for (int i = tree_sz - 1; i > 0; i--) {\n            ch[i] =\
    \ {i << 1, i << 1 | 1};\n        }\n    }\n\n    int get_root(int t = -1) {\n\
    \        if (t == -1) {\n            t = updates;\n        }\n        return t\
    \ == 0 ? 1 : tree_sz + (t - 1) * (log - 1) + 1;\n    }\n\n    void update(int\
    \ p, T val) {\n        int x = get_root(), tl = 0, tr = tree_sz;\n        for\
    \ (int i = 0; i < log - 1; i++) {\n            st.push_back(id());\n         \
    \   int mid = (tl + tr) >> 1;\n            if (p < mid) {\n                ch.push_back({sz(st),\
    \ ch[x][1]});\n                x = ch[x][0];\n                tr = mid;\n    \
    \        } else {\n                ch.push_back({ch[x][0], sz(st)});\n       \
    \         x = ch[x][1];\n                tl = mid;\n            }\n        }\n\
    \        st.push_back(val);\n        for (int i = sz(st) - 2; i >= sz(st) - log;\
    \ i--) {\n            st[i] = op(st[ch[i][0]], st[ch[i][1]]);\n        }\n   \
    \     updates++;\n    }\n\n    T query(int l, int r, int x, int tl, int tr) {\n\
    \        if (tl >= r || tr <= l) {\n            return id();\n        }\n    \
    \    if (tl >= l && tr <= r) {\n            return st[x];\n        }\n       \
    \ int mid = (tl + tr) >> 1;\n        return op(query(l, r, ch[x][0], tl, mid),\
    \ query(l, r, ch[x][1], mid, tr));\n    }\n\n    T query(int l, int r, int t =\
    \ -1) {\n        return query(l, r + 1, get_root(t), 0, tree_sz);\n    }\n};\n"
  code: "template <class T, auto op, auto id>\nstruct persistent_segtree {\n    int\
    \ log, tree_sz, updates;\n    vector<T> st;\n    vector<array<int, 2>> ch;\n\n\
    \    persistent_segtree() {}\n\n    persistent_segtree(int n) {\n        log =\
    \ __lg(n) + 1;\n        tree_sz = 1 << log;\n        st.resize(tree_sz << 1, id());\n\
    \        ch.resize(tree_sz << 1);\n        for (int i = tree_sz - 1; i > 0; i--)\
    \ {\n            ch[i] = {i << 1, i << 1 | 1};\n        }\n    }\n\n    int get_root(int\
    \ t = -1) {\n        if (t == -1) {\n            t = updates;\n        }\n   \
    \     return t == 0 ? 1 : tree_sz + (t - 1) * (log - 1) + 1;\n    }\n\n    void\
    \ update(int p, T val) {\n        int x = get_root(), tl = 0, tr = tree_sz;\n\
    \        for (int i = 0; i < log - 1; i++) {\n            st.push_back(id());\n\
    \            int mid = (tl + tr) >> 1;\n            if (p < mid) {\n         \
    \       ch.push_back({sz(st), ch[x][1]});\n                x = ch[x][0];\n   \
    \             tr = mid;\n            } else {\n                ch.push_back({ch[x][0],\
    \ sz(st)});\n                x = ch[x][1];\n                tl = mid;\n      \
    \      }\n        }\n        st.push_back(val);\n        for (int i = sz(st) -\
    \ 2; i >= sz(st) - log; i--) {\n            st[i] = op(st[ch[i][0]], st[ch[i][1]]);\n\
    \        }\n        updates++;\n    }\n\n    T query(int l, int r, int x, int\
    \ tl, int tr) {\n        if (tl >= r || tr <= l) {\n            return id();\n\
    \        }\n        if (tl >= l && tr <= r) {\n            return st[x];\n   \
    \     }\n        int mid = (tl + tr) >> 1;\n        return op(query(l, r, ch[x][0],\
    \ tl, mid), query(l, r, ch[x][1], mid, tr));\n    }\n\n    T query(int l, int\
    \ r, int t = -1) {\n        return query(l, r + 1, get_root(t), 0, tree_sz);\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segment_tree/persistent_segtree.h
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segment_tree/persistent_segtree.h
layout: document
redirect_from:
- /library/datastructures/segment_tree/persistent_segtree.h
- /library/datastructures/segment_tree/persistent_segtree.h.html
title: datastructures/segment_tree/persistent_segtree.h
---
