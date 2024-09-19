---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructures/bit/bit_range_add.h
    title: datastructures/bit/bit_range_add.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/datastructure/fenwick_tree_range_add.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define arg4(a, b, c, d, ...) d\n \n#define\
    \ rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i,\
    \ 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define\
    \ per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n)\
    \ per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define f first\n#define s second\n\nusing ll = long\
    \ long;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, const T &b) {\n    return b < a ? a = b, 1 : 0;\n\
    }\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n    return b > a ? a\
    \ = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n        cin.tie(0)->sync_with_stdio(0);\n\
    \        cin.exceptions(cin.failbit);\n        cout << setprecision(10) << fixed;\n\
    \    }\n} init_io;\n#line 2 \"datastructures/bit/bit_range_add.h\"\n\ntemplate\
    \ <class T>\nstruct RangeAddBIT {\n    int n;\n    vector<T> ft;\n\n    RangeAddBIT(int\
    \ n_) : n(n_), ft(n + 1) {}\n\n    RangeAddBIT(const vector<T> &a) : n(sz(a)),\
    \ ft(n + 1) {\n        for (int i = 0; i < n; i++) {\n            ft[i + 1] +=\
    \ a[i];\n            ft[i] -= a[i];\n        }\n        for (int i = n; i >= 1;\
    \ i--) {\n            ft[i - (i & -i)] += ft[i];\n        }\n    }\n\n    void\
    \ add(int r, T v) {\n        for (r++; r > 0; r -= r & -r) {\n            ft[r]\
    \ += v;\n        }\n    }\n\n    void add(int l, int r, T v) {\n        add(r,\
    \ v);\n        add(l - 1, T(0) - v);\n    }\n\n    T get(int p) {\n        T res\
    \ = 0;\n        for (p++; p <= n; p += p & -p) {\n            res += ft[p];\n\
    \        }\n        return res;\n    }\n};\n#line 5 \"verify/custom/datastructure/fenwick_tree_range_add.test.cpp\"\
    \n\nconst int N = 1e5, Q = 1e5;\n\nint main() {\n    vector<ll> a = rand_vec<ll>(N);\n\
    \    RangeAddBIT<ll> ft(a);\n    for (int i = 0; i < Q; i++) {\n        if (rand_bool())\
    \ {\n            int l = rand_int(N), r = rand_int(N);\n            if (l > r)\
    \ {\n                swap(l, r);\n            }\n            const int v = rand_int(1e9);\n\
    \            for (int j = l; j <= r; j++) {\n                a[j] += v;\n    \
    \        }\n            ft.add(l, r, v);\n        } else {\n            int p\
    \ = rand_int(N);\n            assert(a[p] == ft.get(p));\n        }\n    }\n\n\
    \    cerr << \"Tests passed\\n\";\n\n    int a_, b_;\n    cin >> a_ >> b_;\n \
    \   cout << a_ + b_ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../datastructures/bit/bit_range_add.h\"\
    \n\nconst int N = 1e5, Q = 1e5;\n\nint main() {\n    vector<ll> a = rand_vec<ll>(N);\n\
    \    RangeAddBIT<ll> ft(a);\n    for (int i = 0; i < Q; i++) {\n        if (rand_bool())\
    \ {\n            int l = rand_int(N), r = rand_int(N);\n            if (l > r)\
    \ {\n                swap(l, r);\n            }\n            const int v = rand_int(1e9);\n\
    \            for (int j = l; j <= r; j++) {\n                a[j] += v;\n    \
    \        }\n            ft.add(l, r, v);\n        } else {\n            int p\
    \ = rand_int(N);\n            assert(a[p] == ft.get(p));\n        }\n    }\n\n\
    \    cerr << \"Tests passed\\n\";\n\n    int a_, b_;\n    cin >> a_ >> b_;\n \
    \   cout << a_ + b_ << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - datastructures/bit/bit_range_add.h
  isVerificationFile: true
  path: verify/custom/datastructure/fenwick_tree_range_add.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/custom/datastructure/fenwick_tree_range_add.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/datastructure/fenwick_tree_range_add.test.cpp
- /verify/verify/custom/datastructure/fenwick_tree_range_add.test.cpp.html
title: verify/custom/datastructure/fenwick_tree_range_add.test.cpp
---
