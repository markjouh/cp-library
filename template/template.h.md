---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':x:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  - icon: ':x:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
  - icon: ':x:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  - icon: ':x:'
    path: verify/aizu/ntl/power.test.cpp
    title: verify/aizu/ntl/power.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/set_xor_min.test.cpp
    title: verify/library_checker/data_structure/set_xor_min.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
  - icon: ':x:'
    path: verify/library_checker/graph/scc.test.cpp
    title: verify/library_checker/graph/scc.test.cpp
  - icon: ':x:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: verify/library_checker/number_theory/enumerate_primes.test.cpp
  - icon: ':x:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':x:'
    path: verify/library_checker/string/suffix_array.test.cpp
    title: verify/library_checker/string/suffix_array.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/binlift_lca.test.cpp
    title: verify/library_checker/tree/binlift_lca.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/rmq_lca.test.cpp
    title: verify/library_checker/tree/rmq_lca.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.h\"\n#include <bits/stdc++.h>\n \nusing\
    \ namespace std;\n \n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r)\
    \ for (int i = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define\
    \ rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l,\
    \ r) for (int i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0,\
    \ n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n \n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n \n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n \nusing ll = long\
    \ long;\nusing pi = pair<int, int>;\nusing pl = pair<ll, ll>;\nusing vi = vector<int>;\n\
    using vl = vector<ll>;\nusing vpi = vector<pi>;\nusing vpl = vector<pl>;\n \n\
    template <class T>\nbool ckmin(T &a, const T b) {\n    return b < a ? a = b, 1\
    \ : 0; \n}\ntemplate <class T>\nbool ckmax(T &a, const T b) {\n    return b >\
    \ a ? a = b, 1 : 0;\n}\n \ntemplate <class T, class U>\nT bsmin(T lo, T hi, U\
    \ f) {\n    assert(lo <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo);\
    \ i > 0; i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n \
    \   return hi;\n}\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f) {\n \
    \   assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n    }\n    return\
    \ lo;\n}\n\ntemplate <class T, class = void>\nstruct is_range : false_type {};\n\
    template <class T>\nstruct is_range<T, void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>\
    \ : true_type {};\ntemplate <class T>\nusing enable_if_cont = enable_if_t<!is_same<T,\
    \ string>::value && is_range<T>::value, bool>;\n\ntemplate <class T, class U>\n\
    istream &operator>>(istream &is, pair<T, U> &p) {\n    is >> p.fi >> p.se;\n \
    \   return is;\n}\ntemplate <class T, class U>\nostream &operator<<(ostream &os,\
    \ const pair<T, U> &p) {\n    os << p.fi << ' ' << p.se;\n    return os;\n}\n\
    template <class T, enable_if_cont<T> = true>\nistream &operator>>(istream &is,\
    \ T &v) {\n    for (auto &x : v) {\n        is >> x;\n    }\n    return is;\n\
    }\ntemplate <class T, enable_if_cont<T> = true>\nostream &operator<<(ostream &os,\
    \ const T &v) {\n    for (int i = 0; i < sz(v); i++) {\n        os << v[i];\n\
    \        if (i != sz(v) - 1) {\n            os << (is_range<typename T::value_type>::value\
    \ ? '\\n' : ' ');\n        }\n    }\n    return os;\n}\n\ntemplate <class ...T>\n\
    void re(T &...a) {\n    (cin >> ... >> a);\n}\ntemplate <class ...T>\nvoid pr(const\
    \ T &...a) {\n    int p = 0;\n    ((cout << a << (++p == sizeof...(T) ? '\\n'\
    \ : ' ')), ...);\n}\n \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ \nconst int INF = 1e9;\nconst ll INFL = 1e18;\n\nvoid solve() {\n}\n\nint32_t\
    \ main() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \n    int t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n\
    }\n"
  code: "#include <bits/stdc++.h>\n \nusing namespace std;\n \n#define arg4(a, b,\
    \ c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    \ \n#define pb push_back\n#define eb emplace_back\n#define fi first\n#define se\
    \ second\n \nusing ll = long long;\nusing pi = pair<int, int>;\nusing pl = pair<ll,\
    \ ll>;\nusing vi = vector<int>;\nusing vl = vector<ll>;\nusing vpi = vector<pi>;\n\
    using vpl = vector<pl>;\n \ntemplate <class T>\nbool ckmin(T &a, const T b) {\n\
    \    return b < a ? a = b, 1 : 0; \n}\ntemplate <class T>\nbool ckmax(T &a, const\
    \ T b) {\n    return b > a ? a = b, 1 : 0;\n}\n \ntemplate <class T, class U>\n\
    T bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T i = T(1)\
    \ << __lg(hi - lo); i > 0; i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i))\
    \ * i;\n    }\n    return hi;\n}\ntemplate <class T, class U>\nT bsmax(T lo, T\
    \ hi, U f) {\n    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n \
    \   }\n    return lo;\n}\n\ntemplate <class T, class = void>\nstruct is_range\
    \ : false_type {};\ntemplate <class T>\nstruct is_range<T, void_t<decltype(begin(declval<T>())),\
    \ decltype(end(declval<T>()))>> : true_type {};\ntemplate <class T>\nusing enable_if_cont\
    \ = enable_if_t<!is_same<T, string>::value && is_range<T>::value, bool>;\n\ntemplate\
    \ <class T, class U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n    is\
    \ >> p.fi >> p.se;\n    return is;\n}\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    os << p.fi << ' ' << p.se;\n    return os;\n\
    }\ntemplate <class T, enable_if_cont<T> = true>\nistream &operator>>(istream &is,\
    \ T &v) {\n    for (auto &x : v) {\n        is >> x;\n    }\n    return is;\n\
    }\ntemplate <class T, enable_if_cont<T> = true>\nostream &operator<<(ostream &os,\
    \ const T &v) {\n    for (int i = 0; i < sz(v); i++) {\n        os << v[i];\n\
    \        if (i != sz(v) - 1) {\n            os << (is_range<typename T::value_type>::value\
    \ ? '\\n' : ' ');\n        }\n    }\n    return os;\n}\n\ntemplate <class ...T>\n\
    void re(T &...a) {\n    (cin >> ... >> a);\n}\ntemplate <class ...T>\nvoid pr(const\
    \ T &...a) {\n    int p = 0;\n    ((cout << a << (++p == sizeof...(T) ? '\\n'\
    \ : ' ')), ...);\n}\n \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ \nconst int INF = 1e9;\nconst ll INFL = 1e18;\n\nvoid solve() {\n}\n\nint32_t\
    \ main() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \n    int t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: template/template.h
  requiredBy: []
  timestamp: '2025-02-28 17:36:32-08:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - verify/library_checker/tree/rmq_lca.test.cpp
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - verify/library_checker/tree/binlift_lca.test.cpp
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/library_checker/string/suffix_array.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/scc.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/data_structure/static_rmq.test.cpp
  - verify/library_checker/data_structure/set_xor_min.test.cpp
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/aizu/dsl/rmq.test.cpp
  - verify/aizu/ntl/power.test.cpp
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/aizu/alds1/number_of_inversions.test.cpp
documentation_of: template/template.h
layout: document
redirect_from:
- /library/template/template.h
- /library/template/template.h.html
title: template/template.h
---
