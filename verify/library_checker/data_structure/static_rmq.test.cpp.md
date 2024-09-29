---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/static/rmq.h
    title: datastructures/static/rmq.h
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':heavy_check_mark:'
    path: utils/encode.h
    title: utils/encode.h
  - icon: ':heavy_check_mark:'
    path: utils/my_random.h
    title: utils/my_random.h
  - icon: ':heavy_check_mark:'
    path: utils/my_timer.h
    title: utils/my_timer.h
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
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"\
    misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef\
    \ LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\nusing ld = long\
    \ double;\n\ntemplate <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a\
    \ = b, 1 : 0;\n}\ntemplate <class T>\nbool ckmax(T &a, T b) {\n    return b >\
    \ a ? a = b, 1 : 0;\n}\n#line 2 \"datastructures/static/rmq.h\"\n\ntemplate <class\
    \ T, auto op>\nstruct RMQ {\n    int n, log;\n    vector<vector<T>> st;\n\n  \
    \  RMQ() {}\n    RMQ(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1) {\n    \
    \    st.resize(log);\n        st[0] = a;\n        for (int i = 1; i < log; i++)\
    \ {\n            st[i].resize(n - (1 << i) + 1);\n            for (int j = 0;\
    \ j < sz(st[i]); j++) {\n                st[i][j] = op(st[i - 1][j], st[i - 1][j\
    \ + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int l, int\
    \ r) {\n        assert(l <= r);\n        int i = __lg(++r - l);\n        return\
    \ op(st[i][l], st[i][r - (1 << i)]);\n    }\n};\n#line 5 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n\nint op(int x, int y) {\n    return x < y ? x : y;\n}\n\nint main() {\n   \
    \ int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        cin >> a[i];\n    }\n    RMQ<int, op> rmq(a);\n    while\
    \ (q--) {\n        int l, r;\n        cin >> l >> r;\n        cout << rmq.query(l,\
    \ r - 1) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../../misc/template.h\"\n#include \"../../../datastructures/static/rmq.h\"\
    \n\nint op(int x, int y) {\n    return x < y ? x : y;\n}\n\nint main() {\n   \
    \ int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        cin >> a[i];\n    }\n    RMQ<int, op> rmq(a);\n    while\
    \ (q--) {\n        int l, r;\n        cin >> l >> r;\n        cout << rmq.query(l,\
    \ r - 1) << '\\n';\n    }\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/static/rmq.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 00:50:10-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp.html
title: verify/library_checker/data_structure/static_rmq.test.cpp
---
