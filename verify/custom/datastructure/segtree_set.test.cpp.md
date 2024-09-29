---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/segment_tree/segtree.h
    title: datastructures/segment_tree/segtree.h
  - icon: ':heavy_check_mark:'
    path: datastructures/segment_tree/segtree_set.h
    title: datastructures/segment_tree/segtree_set.h
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
  bundledCode: "#line 1 \"verify/custom/datastructure/segtree_set.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing ld = long double;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 2 \"\
    datastructures/segment_tree/segtree_set.h\"\n\n#line 2 \"datastructures/segment_tree/segtree.h\"\
    \n\ntemplate <class T, auto op, auto id>\nstruct Segtree {\n    int n;\n    vector<T>\
    \ st;\n\n    Segtree(int n_) : n(n_), st(2 * n, id()) {}\n\n    Segtree(const\
    \ vector<T> &a) : n(sz(a)), st(2 * n) {\n        copy(all(a), begin(st) + n);\n\
    \        for (int i = n - 1; i > 0; i--) {\n            st[i] = op(st[i << 1],\
    \ st[i << 1 | 1]);\n        }\n    }\n\n    T get(int p) {\n        return st[p\
    \ + n];\n    }\n\n    T query(int l, int r) {\n        T ls = id(), rs = id();\n\
    \        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l\
    \ & 1) {\n                ls = op(ls, st[l++]);\n            }\n            if\
    \ (r & 1) {\n                rs = op(st[--r], rs);\n            }\n        }\n\
    \        return op(ls, rs);\n    }\n\n    void set(int p, T val) {\n        for\
    \ (st[p += n] = val, p >>= 1; p > 0; p >>= 1) {\n            st[p] = op(st[p <<\
    \ 1], st[p << 1 | 1]);\n        }\n    }\n};\n#line 4 \"datastructures/segment_tree/segtree_set.h\"\
    \n\ntemplate <class T, auto op, auto id>\nstruct SegtreeSet {\n    int n;\n  \
    \  set<int> free;\n    set<pair<T, int>> used;\n    Segtree<T, op, id> st;\n\n\
    \    SegtreeSet(int n_) : n(n_), st(n) {\n        for (int i = 0; i < n; i++)\
    \ {\n            free.insert(i);\n        }\n    }\n\n    void insert(T x) {\n\
    \        assert(!free.empty());\n        T p = *begin(free);\n        free.erase(begin(free));\n\
    \        st.set(p, x);\n        used.emplace(x, p);\n    }\n\n    void remove(T\
    \ x) {\n        auto it = used.lower_bound({x, -1});\n        assert(it->first\
    \ == x);\n        st.set(it->second, id());\n        free.insert(it->second);\n\
    \        used.erase(it);\n    }\n\n    T query() {\n        return st.query(0,\
    \ n - 1);\n    }\n};\n#line 5 \"verify/custom/datastructure/segtree_set.test.cpp\"\
    \n\nint xor_op(int a, int b) {\n    return a ^ b;\n}\n\nint add_op(int a, int\
    \ b) {\n    return a + b;\n}\n\nint gcd_op(int a, int b) {\n    return gcd(a,\
    \ b);\n}\n\nint id() {\n    return 0;\n}\n\ntemplate <auto op, int N, int MXV>\n\
    void test() {\n    vector<int> naive(N, id());\n    SegtreeSet<int, op, id> st(N);\n\
    \n    for (int i = 0; i < N; i++) {\n        int x = rand_int(MXV);\n        st.insert(x);\n\
    \        naive[i] = x;\n        assert(accumulate(all(naive), id(), op) == st.query());\n\
    \    }\n\n    for (int i = 0; i < N / 2; i++) {\n        int x = naive[i];\n \
    \       st.remove(x);\n        naive[i] = id();\n        assert(accumulate(all(naive),\
    \ id(), op) == st.query());\n    }\n}\n\nint main() {\n    for (int i = 0; i <\
    \ 100; i++) {\n        test<xor_op, 100, 1000000>();\n    }\n    for (int i =\
    \ 0; i < 100; i++) {\n        test<add_op, 100, 1000000>();\n    }\n    for (int\
    \ i = 0; i < 1000; i++) {\n        test<gcd_op, 10, 100>();\n    }\n\n    cerr\
    \ << \"Tests passed\\n\";\n    int a_, b_;\n    cin >> a_ >> b_;\n    cout <<\
    \ a_ + b_ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../datastructures/segment_tree/segtree_set.h\"\
    \n\nint xor_op(int a, int b) {\n    return a ^ b;\n}\n\nint add_op(int a, int\
    \ b) {\n    return a + b;\n}\n\nint gcd_op(int a, int b) {\n    return gcd(a,\
    \ b);\n}\n\nint id() {\n    return 0;\n}\n\ntemplate <auto op, int N, int MXV>\n\
    void test() {\n    vector<int> naive(N, id());\n    SegtreeSet<int, op, id> st(N);\n\
    \n    for (int i = 0; i < N; i++) {\n        int x = rand_int(MXV);\n        st.insert(x);\n\
    \        naive[i] = x;\n        assert(accumulate(all(naive), id(), op) == st.query());\n\
    \    }\n\n    for (int i = 0; i < N / 2; i++) {\n        int x = naive[i];\n \
    \       st.remove(x);\n        naive[i] = id();\n        assert(accumulate(all(naive),\
    \ id(), op) == st.query());\n    }\n}\n\nint main() {\n    for (int i = 0; i <\
    \ 100; i++) {\n        test<xor_op, 100, 1000000>();\n    }\n    for (int i =\
    \ 0; i < 100; i++) {\n        test<add_op, 100, 1000000>();\n    }\n    for (int\
    \ i = 0; i < 1000; i++) {\n        test<gcd_op, 10, 100>();\n    }\n\n    cerr\
    \ << \"Tests passed\\n\";\n    int a_, b_;\n    cin >> a_ >> b_;\n    cout <<\
    \ a_ + b_ << '\\n';\n}\n"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/segment_tree/segtree_set.h
  - datastructures/segment_tree/segtree.h
  isVerificationFile: true
  path: verify/custom/datastructure/segtree_set.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 01:50:21-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/datastructure/segtree_set.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/datastructure/segtree_set.test.cpp
- /verify/verify/custom/datastructure/segtree_set.test.cpp.html
title: verify/custom/datastructure/segtree_set.test.cpp
---
