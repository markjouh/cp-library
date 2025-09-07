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
  bundledCode: "#line 1 \"src/datastructures/chtholly_tree.h\"\n// With this treasure,\
    \ I summon...\ntemplate <class T>\nstruct ChthollyTree {\n  struct Seg {\n   \
    \ int l, r;\n    T val;\n\n    Seg() {}\n    Seg(int l_, int r_, T v) : l(l_),\
    \ r(r_), val(v) {}\n\n    bool operator<(const Seg &b) const {\n      return l\
    \ < b.l;\n    }\n  };\n\n  int n;\n  set<Seg> st;\n\n  using Iter = typename set<Seg>::iterator;\n\
    \n  ChthollyTree(int n_, T v) : n(n_) {\n    st.emplace(make_pair(0, n - 1), v);\n\
    \  }\n  ChthollyTree(const vector<T> &a) : n(a.size()) {\n    int p = -1;\n  \
    \  for (int i = 0; i < n; i++) {\n      if (i == n - 1 || a[i] != a[i + 1]) {\n\
    \        st.emplace(Seg(p + 1, i, a[i]));\n        p = i;\n      }\n    }\n  }\n\
    \n  template <class U>\n  void traverse(int l, int r, U f) {\n    try_split(find_seg(l),\
    \ l);\n    try_split(find_seg(r), r + 1);\n\n    Iter it = find_seg(l), end =\
    \ ++find_seg(r);\n    while (it != end) {\n      f(it++);\n    }\n  }\n\n  template\
    \ <class U>\n  void apply(int l, int r, U f) {\n    Seg buf;\n    traverse(l,\
    \ r, [&](Iter it) {\n      Seg s = *it;\n      st.erase(it);\n      T v = f(s.val);\n\
    \      if (v != buf.val || s.l == l) {\n        if (s.l != l) {\n          st.insert(buf);\n\
    \        }\n        buf.l = s.l;\n        buf.val = v;\n      }\n      buf.r =\
    \ s.r;\n    });\n    st.insert(buf);\n  }\n\nprivate:\n  Iter find_seg(int x)\
    \ const {\n    assert(x >= 0 && x < n);\n    return --st.upper_bound(Seg(x, INT_MAX,\
    \ T{}));\n  }\n\n  void try_split(Iter it, int x) {\n    if (it->l < x && it->r\
    \ >= x) {\n      Seg ls = Seg(it->l, x - 1, it->val);\n      Seg rs = Seg(x, it->r,\
    \ it->val);\n      st.erase(it);\n      st.insert(ls);\n      st.insert(rs);\n\
    \    }\n  }\n};\n"
  code: "// With this treasure, I summon...\ntemplate <class T>\nstruct ChthollyTree\
    \ {\n  struct Seg {\n    int l, r;\n    T val;\n\n    Seg() {}\n    Seg(int l_,\
    \ int r_, T v) : l(l_), r(r_), val(v) {}\n\n    bool operator<(const Seg &b) const\
    \ {\n      return l < b.l;\n    }\n  };\n\n  int n;\n  set<Seg> st;\n\n  using\
    \ Iter = typename set<Seg>::iterator;\n\n  ChthollyTree(int n_, T v) : n(n_) {\n\
    \    st.emplace(make_pair(0, n - 1), v);\n  }\n  ChthollyTree(const vector<T>\
    \ &a) : n(a.size()) {\n    int p = -1;\n    for (int i = 0; i < n; i++) {\n  \
    \    if (i == n - 1 || a[i] != a[i + 1]) {\n        st.emplace(Seg(p + 1, i, a[i]));\n\
    \        p = i;\n      }\n    }\n  }\n\n  template <class U>\n  void traverse(int\
    \ l, int r, U f) {\n    try_split(find_seg(l), l);\n    try_split(find_seg(r),\
    \ r + 1);\n\n    Iter it = find_seg(l), end = ++find_seg(r);\n    while (it !=\
    \ end) {\n      f(it++);\n    }\n  }\n\n  template <class U>\n  void apply(int\
    \ l, int r, U f) {\n    Seg buf;\n    traverse(l, r, [&](Iter it) {\n      Seg\
    \ s = *it;\n      st.erase(it);\n      T v = f(s.val);\n      if (v != buf.val\
    \ || s.l == l) {\n        if (s.l != l) {\n          st.insert(buf);\n       \
    \ }\n        buf.l = s.l;\n        buf.val = v;\n      }\n      buf.r = s.r;\n\
    \    });\n    st.insert(buf);\n  }\n\nprivate:\n  Iter find_seg(int x) const {\n\
    \    assert(x >= 0 && x < n);\n    return --st.upper_bound(Seg(x, INT_MAX, T{}));\n\
    \  }\n\n  void try_split(Iter it, int x) {\n    if (it->l < x && it->r >= x) {\n\
    \      Seg ls = Seg(it->l, x - 1, it->val);\n      Seg rs = Seg(x, it->r, it->val);\n\
    \      st.erase(it);\n      st.insert(ls);\n      st.insert(rs);\n    }\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/chtholly_tree.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructures/chtholly_tree.h
layout: document
redirect_from:
- /library/src/datastructures/chtholly_tree.h
- /library/src/datastructures/chtholly_tree.h.html
title: src/datastructures/chtholly_tree.h
---
