---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/segment_tree/lazy_segtree.h
    title: Lazily Propagated Segment Tree
  - icon: ':question:'
    path: src/template/template.h
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\
    \n#line 1 \"src/template/template.h\"\n/**\n  *    author: mark\n**/\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#define sz(x) int(size(x))\n#define\
    \ all(x) begin(x), end(x)\n#line 1 \"src/datastructures/segment_tree/lazy_segtree.h\"\
    \ntemplate <class T, auto op, auto t_id, class U, auto mapping, auto comp, auto\
    \ u_id>\nstruct LazySegtree {\n  LazySegtree(int n_, T v = t_id()) {\n    init(n_,\
    \ v);\n    pull_all();\n  }\n\n  LazySegtree(const vector<T> &a) {\n    init(sz(a),\
    \ t_id());\n    copy(all(a), begin(st) + tree_sz);\n    pull_all();\n  }\n\n \
    \ void set(int p, T v) {\n    push_path(p += tree_sz);\n    st[p] = v;\n    pull_path(p);\n\
    \  }\n\n  void update(int p, U v) {\n    push_path(p += tree_sz);\n    st[p] =\
    \ mapping(st[p], v);\n    pull_path(p);\n  }\n\n  void update(int l, int r, U\
    \ v) {\n    assert(0 <= l && l <= r && r < n);\n    l += tree_sz;\n    r += tree_sz\
    \ + 1;\n\n    push_range(l, r);\n\n    int l2 = l, r2 = r;\n    while (l2 < r2)\
    \ {\n      if (l2 & 1) {\n        apply(l2++, v);\n      }\n      if (r2 & 1)\
    \ {\n        apply(--r2, v);\n      }\n      l2 >>= 1;\n      r2 >>= 1;\n    }\n\
    \n    pull_range(l, r);\n  }\n\n  T get(int p) {\n    push_path(p += tree_sz);\n\
    \    return st[p];\n  }\n\n  T query(int l, int r) {\n    assert(0 <= l && l <=\
    \ r && r < n);\n    l += tree_sz;\n    r += tree_sz + 1;\n\n    push_range(l,\
    \ r);\n\n    T ls = t_id(), rs = t_id();\n    while (l < r) {\n      if (l & 1)\
    \ {\n        ls = op(ls, st[l++]);\n      }\n      if (r & 1) {\n        rs =\
    \ op(st[--r], rs);\n      }\n      l >>= 1;\n      r >>= 1;\n    }\n    return\
    \ op(ls, rs);\n  }\n\n  T query_all() {\n    return st[1];\n  }\n\n  template\
    \ <class F>\n  int find_first(F f) {\n    T pref = t_id();\n    int x = 1;\n \
    \   for (int i = 0; i < log; i++) {\n      push(x);\n      if (f(op(pref, st[x\
    \ << 1]))) {\n        x = x << 1;\n      } else {\n        pref = op(pref, st[x\
    \ << 1]);\n        x = x << 1 | 1;\n      }\n    }\n    return f(op(pref, st[x]))\
    \ ? x - tree_sz : n;\n  }\n\n  template <class F>\n  int find_last(F f) {\n  \
    \  T suff = t_id();\n    int x = 1;\n    for (int i = 0; i < log; i++) {\n   \
    \   push(x);\n      if (f(op(st[x << 1 | 1], suff))) {\n        x = x << 1 | 1;\n\
    \      } else {\n        suff = op(st[x << 1 | 1], suff);\n        x = x << 1;\n\
    \      }\n    }\n    return f(op(st[x], suff)) ? x - tree_sz : -1;\n  }\n  \n\
    private:\n  int n, log, tree_sz;\n  vector<T> st;\n  vector<U> lz;\n\n  void init(int\
    \ n_, T v) {\n    n = n_;\n    log = __lg(n - 1) + 1;\n    tree_sz = 1 << log;\n\
    \    st.resize(tree_sz << 1, v);\n    lz.resize(tree_sz, u_id());\n  }\n\n  void\
    \ apply(int x, U y) {\n    st[x] = mapping(st[x], y);\n    if (x < tree_sz) {\n\
    \      lz[x] = comp(lz[x], y);\n    }\n  }\n\n  void push(int x) {\n    apply(x\
    \ << 1, lz[x]);\n    apply(x << 1 | 1, lz[x]);\n    lz[x] = u_id();\n  }\n\n \
    \ void push_path(int x) {\n    for (int i = log; i > 0; i--) {\n      push(x >>\
    \ i);\n    }\n  }\n\n  void push_range(int l, int r) {\n    for (int i = log;\
    \ i >= 1; i--) {\n      if (((l >> i) << i) != l) {\n        push(l >> i);\n \
    \     }\n      if (((r >> i) << i) != r) {\n        push((r - 1) >> i);\n    \
    \  }\n    }\n  }\n\n  void pull(int x) {\n    st[x] = op(st[x << 1], st[x << 1\
    \ | 1]);\n  }\n\n  void pull_path(int x) {\n    for (int i = 1; i <= log; i++)\
    \ {\n      pull(x >> i);\n    }\n  }\n\n  void pull_range(int l, int r) {\n  \
    \  for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) != l) {\n     \
    \   pull(l >> i);\n      }\n      if (((r >> i) << i) != r) {\n        pull((r\
    \ - 1) >> i);\n      }\n    }\n  }\n\n  void pull_all() {\n    for (int i = tree_sz\
    \ - 1; i > 0; i--) {\n      pull(i);\n    }\n  }\n};\n#line 5 \"src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp\"\
    \n\nusing ll = long long;\n\nconst ll MOD = 998244353;\n\nstruct S {\n  ll sum,\
    \ size;\n};\n\nstruct F {\n  ll a, b;\n};\n\nS op(S l, S r) {\n  return {(l.sum\
    \ + r.sum) % MOD, l.size + r.size};\n}\n\nS t_id() {\n  return {0, 0};\n}\n\n\
    S mapping(S x, F f) {\n  return {(f.a * x.sum % MOD + f.b * x.size % MOD) % MOD,\
    \ x.size};\n}\n\nF comp(F f, F g) {\n  return {g.a * f.a % MOD, (g.a * f.b % MOD\
    \ + g.b) % MOD};\n}\n\nF u_id() {\n  return {1, 0};\n}\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  \n  LazySegtree<S, op, t_id, F, mapping, comp, u_id>\
    \ seg(n);\n  \n  for (int i = 0; i < n; i++) {\n    ll a;\n    cin >> a;\n   \
    \ seg.set(i, {a, 1});\n  }\n  \n  while (q--) {\n    int t;\n    cin >> t;\n \
    \   if (t == 0) {\n      int l, r;\n      ll b, c;\n      cin >> l >> r >> b >>\
    \ c;\n      seg.update(l, r - 1, {b, c});\n    } else {\n      int l, r;\n   \
    \   cin >> l >> r;\n      cout << seg.query(l, r - 1).sum << '\\n';\n    }\n \
    \ }\n  \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../datastructures/segment_tree/lazy_segtree.h\"\
    \n\nusing ll = long long;\n\nconst ll MOD = 998244353;\n\nstruct S {\n  ll sum,\
    \ size;\n};\n\nstruct F {\n  ll a, b;\n};\n\nS op(S l, S r) {\n  return {(l.sum\
    \ + r.sum) % MOD, l.size + r.size};\n}\n\nS t_id() {\n  return {0, 0};\n}\n\n\
    S mapping(S x, F f) {\n  return {(f.a * x.sum % MOD + f.b * x.size % MOD) % MOD,\
    \ x.size};\n}\n\nF comp(F f, F g) {\n  return {g.a * f.a % MOD, (g.a * f.b % MOD\
    \ + g.b) % MOD};\n}\n\nF u_id() {\n  return {1, 0};\n}\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  \n  LazySegtree<S, op, t_id, F, mapping, comp, u_id>\
    \ seg(n);\n  \n  for (int i = 0; i < n; i++) {\n    ll a;\n    cin >> a;\n   \
    \ seg.set(i, {a, 1});\n  }\n  \n  while (q--) {\n    int t;\n    cin >> t;\n \
    \   if (t == 0) {\n      int l, r;\n      ll b, c;\n      cin >> l >> r >> b >>\
    \ c;\n      seg.update(l, r - 1, {b, c});\n    } else {\n      int l, r;\n   \
    \   cin >> l >> r;\n      cout << seg.query(l, r - 1).sum << '\\n';\n    }\n \
    \ }\n  \n  return 0;\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/segment_tree/lazy_segtree.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 18:13:39-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
- /verify/src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp.html
title: src/verify/library_checker/data_structure/range_affine_range_sum.test.cpp
---
