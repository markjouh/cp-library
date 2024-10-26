---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/segment_tree/segtree.h
    title: datastructures/segment_tree/segtree.h
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"verify/aizu/dsl/rmq.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate\
    \ <class T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line\
    \ 1 \"datastructures/segment_tree/segtree.h\"\ntemplate <class T, auto op, auto\
    \ id>\nstruct Segtree {\n    int n;\n    vector<T> st;\n\n    Segtree(int n_)\
    \ : n(n_), st(2 * n, id()) {}\n\n    Segtree(const vector<T> &a) : n(sz(a)), st(2\
    \ * n) {\n        copy(all(a), begin(st) + n);\n        for (int i = n - 1; i\
    \ > 0; i--) {\n            st[i] = op(st[i << 1], st[i << 1 | 1]);\n        }\n\
    \    }\n\n    T get(int p) {\n        return st[p + n];\n    }\n\n    T query(int\
    \ l, int r) {\n        T ls = id(), rs = id();\n        for (l += n, r += n +\
    \ 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n                ls\
    \ = op(ls, st[l++]);\n            }\n            if (r & 1) {\n              \
    \  rs = op(st[--r], rs);\n            }\n        }\n        return op(ls, rs);\n\
    \    }\n\n    void set(int p, T val) {\n        for (st[p += n] = val, p >>= 1;\
    \ p > 0; p >>= 1) {\n            st[p] = op(st[p << 1], st[p << 1 | 1]);\n   \
    \     }\n    }\n};\n#line 5 \"verify/aizu/dsl/rmq.test.cpp\"\n\nint op(int x,\
    \ int y) {\n    return x < y ? x : y;\n}\n\nint id() {\n    return INT_MAX;\n\
    }\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    Segtree<int, op, id>\
    \ st(n);\n    while (q--) {\n        bool t;\n        int x, y;\n        cin >>\
    \ t >> x >> y;\n        if (t) {\n            cout << st.query(x, y) << '\\n';\n\
    \        } else {\n            st.set(x, y);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../datastructures/segment_tree/segtree.h\"\
    \n\nint op(int x, int y) {\n    return x < y ? x : y;\n}\n\nint id() {\n    return\
    \ INT_MAX;\n}\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    Segtree<int,\
    \ op, id> st(n);\n    while (q--) {\n        bool t;\n        int x, y;\n    \
    \    cin >> t >> x >> y;\n        if (t) {\n            cout << st.query(x, y)\
    \ << '\\n';\n        } else {\n            st.set(x, y);\n        }\n    }\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/segment_tree/segtree.h
  isVerificationFile: true
  path: verify/aizu/dsl/rmq.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 20:08:44-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/dsl/rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/dsl/rmq.test.cpp
- /verify/verify/aizu/dsl/rmq.test.cpp.html
title: verify/aizu/dsl/rmq.test.cpp
---
