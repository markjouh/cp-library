---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: common/binsearch.h
    title: common/binsearch.h
  - icon: ':heavy_check_mark:'
    path: datastructures/static/mergesort_tree.h
    title: datastructures/static/mergesort_tree.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/my_random.h
    title: utils/my_random.h
  - icon: ':question:'
    path: utils/my_timer.h
    title: utils/my_timer.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/library_checker/data_structure/range_kth_smallest.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
    \ 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    #ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate\
    \ <class T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line\
    \ 2 \"datastructures/static/mergesort_tree.h\"\n\ntemplate <class T>\nstruct MergesortTree\
    \ {\n    int n;\n    vector<vector<T>> st;\n\n    MergesortTree(const vector<T>\
    \ &a) : n(sz(a)), st(2 * n) {\n        for (int i = 0; i < n; i++) {\n       \
    \     st[i + n] = {a[i]};\n        }\n        for (int i = n - 1; i > 0; i--)\
    \ {\n            merge(begin(st[i << 1]), end(st[i << 1]), begin(st[i << 1 | 1]),\n\
    \                end(st[i << 1 | 1]), back_inserter(st[i]));\n        }\n    }\n\
    \n    T query(int l, int r, T v) {\n        T ls = 0, rs = 0;\n        for (l\
    \ += n, r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n   \
    \             ls += lower_bound(all(st[l]), v) - begin(st[l]);\n             \
    \   l++;\n            }\n            if (r & 1) {\n                r--;\n    \
    \            rs += lower_bound(all(st[r]), v) - begin(st[r]);\n            }\n\
    \        }\n        return ls + rs;\n    }\n};\n#line 2 \"common/binsearch.h\"\
    \n\ntemplate <class T, class U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <=\
    \ hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n \
    \       hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\n\ntemplate\
    \ <class T, class U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n\
    \    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo += (lo +\
    \ i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}\n#line 6 \"verify/library_checker/data_structure/range_kth_smallest.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n \
    \   for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    MergesortTree<int>\
    \ mt(a);\n    while (q--) {\n        int l, r, k;\n        cin >> l >> r >> k;\n\
    \        r--;\n        cout << bsmin(0, int(1e9), [&](int x) {\n            return\
    \ mt.query(l, r, x + 1) >= k + 1;\n        }) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../misc/template.h\"\n#include \"../../../datastructures/static/mergesort_tree.h\"\
    \n#include \"../../../common/binsearch.h\"\n\nint main() {\n    int n, q;\n  \
    \  cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i < n; i++) {\n\
    \        cin >> a[i];\n    }\n    MergesortTree<int> mt(a);\n    while (q--) {\n\
    \        int l, r, k;\n        cin >> l >> r >> k;\n        r--;\n        cout\
    \ << bsmin(0, int(1e9), [&](int x) {\n            return mt.query(l, r, x + 1)\
    \ >= k + 1;\n        }) << '\\n';\n    }\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/static/mergesort_tree.h
  - common/binsearch.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 19:29:34-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp.html
title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
---
