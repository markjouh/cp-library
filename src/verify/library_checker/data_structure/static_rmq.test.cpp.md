---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/static/sparse_table.h
    title: Sparse Table
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"\
    src/template/template.h\"\n/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"src/datastructures/static/sparse_table.h\"\ntemplate <class\
    \ T, auto op>\nstruct SparseTable {\n  int n, log;\n  vector<vector<T>> st;\n\n\
    \  SparseTable() {}\n  SparseTable(const vector<T> &a) : n(sz(a)), log(__lg(n)\
    \ + 1) {\n    st.resize(log);\n    st[0] = a;\n    for (int i = 1; i < log; i++)\
    \ {\n      st[i].resize(n - (1 << i) + 1);\n      for (int j = 0; j < sz(st[i]);\
    \ j++) {\n        st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n\
    \      }\n    }\n  }\n\n  T query(int l, int r) {\n    assert(l <= r);\n    int\
    \ i = __lg(++r - l);\n    return op(st[i][l], st[i][r - (1 << i)]);\n  }\n};\n\
    \ntemplate <class T>\nT min_op(T x, T y) {\n  return x < y ? x : y;\n}\ntemplate\
    \ <class T>\nT max_op(T x, T y) {\n  return x > y ? x : y;\n}\n#line 5 \"src/verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n\nint op(int x, int y) {\n  return x < y ? x : y;\n}\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    cin >> a[i];\n  }\n  SparseTable<int, op> rmq(a);\n  while (q--) {\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << rmq.query(l, r - 1) << '\\n';\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../datastructures/static/sparse_table.h\"\
    \n\nint op(int x, int y) {\n  return x < y ? x : y;\n}\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    cin >> a[i];\n  }\n  SparseTable<int, op> rmq(a);\n  while (q--) {\n\
    \    int l, r;\n    cin >> l >> r;\n    cout << rmq.query(l, r - 1) << '\\n';\n\
    \  }\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/static/sparse_table.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/static_rmq.test.cpp
- /verify/src/verify/library_checker/data_structure/static_rmq.test.cpp.html
title: src/verify/library_checker/data_structure/static_rmq.test.cpp
---
