---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/mergesort_tree.h
    title: datastructures/mergesort_tree.h
  - icon: ':heavy_check_mark:'
    path: datastructures/ordered_set.h
    title: datastructures/ordered_set.h
  - icon: ':heavy_check_mark:'
    path: numeric/binsearch.h
    title: numeric/binsearch.h
  - icon: ':heavy_check_mark:'
    path: template/template.h
    title: template/template.h
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
    \ 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long\
    \ long;\n#line 1 \"numeric/binsearch.h\"\ntemplate <class T, class U>\nT bsmin(T\
    \ lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i)) * i;\n \
    \   }\n    return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U\
    \ f) {\n    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi - lo);\
    \ i > 0; i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n    }\n \
    \   return lo;\n}\n#line 1 \"datastructures/ordered_set.h\"\n#include <ext/pb_ds/assoc_container.hpp>\
    \ \n#include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds; \n\ntemplate\
    \ <class T>\nusing ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ntemplate <class T>\nstruct ordered_multiset {\n    int time = 0;\n    ordered_set<pair<T,\
    \ int>> st;\n\n    void insert(T x) {\n        st.insert({x, time++});\n    }\n\
    \    void extract(T x) {\n        auto it = st.lower_bound({x, 0});\n        if\
    \ (it != end(st) && it->fi == x) {\n            st.erase(it);\n        }\n   \
    \ }\n\n    T find_by_order(int k) {\n        return (*st.find_by_order(k)).first;\n\
    \    }\n    int order_of_key(T x) {\n        return st.order_of_key({x, 0});\n\
    \    }\n};\n#line 2 \"datastructures/mergesort_tree.h\"\n\ntemplate <class T>\n\
    struct mergesort_tree {\n    int n;\n    vector<ordered_set<pair<T, int>>> st;\n\
    \ \n    mergesort_tree(const vector<T> &a) : n(sz(a)), st(2 * n) {\n        for\
    \ (int i = 0; i < n; i++) {\n            for (int p = i + n; p > 0; p >>= 1) {\n\
    \                st[p].insert({a[i], i});\n            }\n        }\n    }\n \n\
    \    int query(int l, int r, T v) {\n        int res = 0;\n        for (l += n,\
    \ r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n         \
    \       res += st[l++].order_of_key({v, 0});\n            }\n            if (r\
    \ & 1) {\n                res += st[--r].order_of_key({v, 0});\n            }\n\
    \        }\n        return res;\n    }\n \n    void set(int p, T v) {\n      \
    \  const auto old = *begin(st[p + n]);\n        for (p += n; p > 0; p >>= 1) {\n\
    \            st[p].erase(old);\n            st[p].insert(v);\n        }\n    }\n\
    };\n#line 6 \"verify/library_checker/data_structure/range_kth_smallest.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n \
    \   for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    mergesort_tree<int>\
    \ mt(a);\n    while (q--) {\n        int l, r, k;\n        cin >> l >> r >> k;\n\
    \        r--;\n        cout << bsmin(0, int(1e9), [&](int x) {\n            return\
    \ mt.query(l, r, x + 1) >= k + 1;\n        }) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../template/template.h\"\n#include \"../../../numeric/binsearch.h\"\
    \n#include \"../../../datastructures/mergesort_tree.h\"\n\nint main() {\n    int\
    \ n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        cin >> a[i];\n    }\n    mergesort_tree<int> mt(a);\n    while\
    \ (q--) {\n        int l, r, k;\n        cin >> l >> r >> k;\n        r--;\n \
    \       cout << bsmin(0, int(1e9), [&](int x) {\n            return mt.query(l,\
    \ r, x + 1) >= k + 1;\n        }) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.h
  - numeric/binsearch.h
  - datastructures/mergesort_tree.h
  - datastructures/ordered_set.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2024-12-07 19:52:17-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp.html
title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
---