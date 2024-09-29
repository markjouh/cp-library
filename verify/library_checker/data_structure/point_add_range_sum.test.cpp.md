---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_indexed_tree/bit.h
    title: datastructures/binary_indexed_tree/bit.h
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"verify/library_checker/data_structure/point_add_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\nusing\
    \ ld = long double;\n\ntemplate <class T>\nbool ckmin(T &a, T b) {\n    return\
    \ b < a ? a = b, 1 : 0;\n}\ntemplate <class T>\nbool ckmax(T &a, T b) {\n    return\
    \ b > a ? a = b, 1 : 0;\n}\n#line 2 \"datastructures/binary_indexed_tree/bit.h\"\
    \n\ntemplate <class T>\nstruct BIT {\n    int n;\n    vector<T> ft;\n\n    BIT(int\
    \ n_) : n(n_), ft(n + 1) {}\n\n    BIT(const vector<T> &a) : n(sz(a)), ft(n +\
    \ 1) {\n        for (int i = 1; i <= n; i++) {\n            ft[i] += a[i - 1];\n\
    \            if (i + (i & -i) <= n) {\n                ft[i + (i & -i)] += ft[i];\n\
    \            }\n        }\n    }\n\n    void add(int p, T v) {\n        for (p++;\
    \ p <= n; p += p & -p) {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int\
    \ r) {\n        T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n        \
    \    res += ft[r];\n        }\n        return res;\n    }\n\n    T sum(int l,\
    \ int r) {\n        return sum(r) - sum(l - 1);\n    }\n};\n#line 5 \"verify/library_checker/data_structure/point_add_range_sum.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n  \
    \  for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    BIT<ll> ft(a);\n\
    \    while (q--) {\n        bool t;\n        int x, y;\n        cin >> t >> x\
    \ >> y;\n        if (t) {\n            cout << ft.sum(x, y - 1) << '\\n';\n  \
    \      } else {\n            ft.add(x, y);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../../misc/template.h\"\n#include \"../../../datastructures/binary_indexed_tree/bit.h\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<ll> a(n);\n  \
    \  for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    BIT<ll> ft(a);\n\
    \    while (q--) {\n        bool t;\n        int x, y;\n        cin >> t >> x\
    \ >> y;\n        if (t) {\n            cout << ft.sum(x, y - 1) << '\\n';\n  \
    \      } else {\n            ft.add(x, y);\n        }\n    }\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/binary_indexed_tree/bit.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/point_add_range_sum.test.cpp
- /verify/verify/library_checker/data_structure/point_add_range_sum.test.cpp.html
title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
---
