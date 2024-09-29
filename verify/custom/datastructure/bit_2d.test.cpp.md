---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_indexed_tree/bit.h
    title: datastructures/binary_indexed_tree/bit.h
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_indexed_tree/bit_2d.h
    title: datastructures/binary_indexed_tree/bit_2d.h
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/datastructure/bit_2d.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing ld = long double;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 2 \"\
    datastructures/binary_indexed_tree/bit_2d.h\"\n\n#line 2 \"datastructures/binary_indexed_tree/bit.h\"\
    \n\ntemplate <class T>\nstruct BIT {\n    int n;\n    vector<T> ft;\n\n    BIT(int\
    \ n_) : n(n_), ft(n + 1) {}\n\n    BIT(const vector<T> &a) : n(sz(a)), ft(n +\
    \ 1) {\n        for (int i = 1; i <= n; i++) {\n            ft[i] += a[i - 1];\n\
    \            if (i + (i & -i) <= n) {\n                ft[i + (i & -i)] += ft[i];\n\
    \            }\n        }\n    }\n\n    void add(int p, T v) {\n        for (p++;\
    \ p <= n; p += p & -p) {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int\
    \ r) {\n        T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n        \
    \    res += ft[r];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l - 1);\n    }\n};\n#line 4 \"datastructures/binary_indexed_tree/bit_2d.h\"\
    \n\ntemplate <class T>\nstruct BIT2D {\n    int n;\n    vector<BIT<T>> ft;\n\n\
    \    BIT2D(int n_, int m) : n(n_), ft(n + 1, BIT<T>(m)) {}\n\n    void add(int\
    \ r, int c, T v) {\n        for (r++; r <= n; r += r & -r) {\n            ft[r].add(c,\
    \ v);\n        }\n    }\n\n    T sum(int r, int c) {\n        if (r < 0 || c <\
    \ 0) {\n            return 0;\n        }\n        T res = 0;\n        for (r++;\
    \ r > 0; r -= r & -r) {\n            res += ft[r].sum(c);\n        }\n       \
    \ return res;\n    }\n\n    T sum(int r1, int c1, int r2, int c2) {\n        return\
    \ sum(r2, c2) - sum(r2, c1 - 1) - sum(r1 - 1, c2) + sum(r1 - 1, c1 - 1);\n   \
    \ }\n};\n#line 5 \"verify/custom/datastructure/bit_2d.test.cpp\"\n\nconst int\
    \ N = 100, M = 100, Q = 1e4;\nconst int MXV = 1e6;\n\nint main() {\n    vector<vector<ll>>\
    \ a(N, vector<ll>(M));\n    BIT2D<ll> ft(N, M);\n\n    for (int i = 0; i < N;\
    \ i++) {\n        a[i] = rand_vec<ll>(M, 0, MXV);\n        for (int j = 0; j <\
    \ M; j++) {\n            ft.add(i, j, a[i][j]);\n        }\n    }\n\n    for (int\
    \ i = 0; i < Q; i++) {\n        if (rand_bool()) {\n            int r = rand_int(N),\
    \ c = rand_int(M);\n            const int v = rand_int(MXV);\n            \n \
    \           a[r][c] += v;\n            ft.add(r, c, v);\n        } else {\n  \
    \          int r1 = rand_int(N), c1 = rand_int(M), r2 = rand_int(N), c2 = rand_int(M);\n\
    \            if (r1 > r2) {\n                swap(r1, r2);\n            }\n  \
    \          if (c1 > c2) {\n                swap(c1, c2);\n            }\n    \
    \        ll brute = 0;\n            for (int r = r1; r <= r2; r++) {\n       \
    \         for (int c = c1; c <= c2; c++) {\n                    brute += a[r][c];\n\
    \                }\n            }\n            assert(brute == ft.sum(r1, c1,\
    \ r2, c2));\n        }\n    }\n\n    cerr << \"Tests passed\\n\";\n    int a_,\
    \ b_;\n    cin >> a_ >> b_;\n    cout << a_ + b_ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../datastructures/binary_indexed_tree/bit_2d.h\"\
    \n\nconst int N = 100, M = 100, Q = 1e4;\nconst int MXV = 1e6;\n\nint main() {\n\
    \    vector<vector<ll>> a(N, vector<ll>(M));\n    BIT2D<ll> ft(N, M);\n\n    for\
    \ (int i = 0; i < N; i++) {\n        a[i] = rand_vec<ll>(M, 0, MXV);\n       \
    \ for (int j = 0; j < M; j++) {\n            ft.add(i, j, a[i][j]);\n        }\n\
    \    }\n\n    for (int i = 0; i < Q; i++) {\n        if (rand_bool()) {\n    \
    \        int r = rand_int(N), c = rand_int(M);\n            const int v = rand_int(MXV);\n\
    \            \n            a[r][c] += v;\n            ft.add(r, c, v);\n     \
    \   } else {\n            int r1 = rand_int(N), c1 = rand_int(M), r2 = rand_int(N),\
    \ c2 = rand_int(M);\n            if (r1 > r2) {\n                swap(r1, r2);\n\
    \            }\n            if (c1 > c2) {\n                swap(c1, c2);\n  \
    \          }\n            ll brute = 0;\n            for (int r = r1; r <= r2;\
    \ r++) {\n                for (int c = c1; c <= c2; c++) {\n                 \
    \   brute += a[r][c];\n                }\n            }\n            assert(brute\
    \ == ft.sum(r1, c1, r2, c2));\n        }\n    }\n\n    cerr << \"Tests passed\\\
    n\";\n    int a_, b_;\n    cin >> a_ >> b_;\n    cout << a_ + b_ << '\\n';\n}\n"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/binary_indexed_tree/bit_2d.h
  - datastructures/binary_indexed_tree/bit.h
  isVerificationFile: true
  path: verify/custom/datastructure/bit_2d.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 01:50:21-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/datastructure/bit_2d.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/datastructure/bit_2d.test.cpp
- /verify/verify/custom/datastructure/bit_2d.test.cpp.html
title: verify/custom/datastructure/bit_2d.test.cpp
---
