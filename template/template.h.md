---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/bits/stdc++.h
    title: utils/bits/stdc++.h
  - icon: ':heavy_check_mark:'
    path: utils/compat.h
    title: utils/compat.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':heavy_check_mark:'
    path: utils/random.h
    title: utils/random.h
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/ntl/power.test.cpp
    title: verify/aizu/ntl/power.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/associative_array.test.cpp
    title: verify/library_checker/data_structure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/set_xor_min.test.cpp
    title: verify/library_checker/data_structure/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/scc.test.cpp
    title: verify/library_checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: verify/library_checker/number_theory/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/suffix_array.test.cpp
    title: verify/library_checker/string/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/lca.test.cpp
    title: verify/library_checker/tree/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing\
    \ namespace std;\n\n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n\
    #endif\n\n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i\
    \ = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...)\
    \ arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int\
    \ i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define\
    \ per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n\n#define pb push_back\n#define eb emplace_back\n\
    #define fi first\n#define se second\n\nusing ll = long long;\nusing ld = long\
    \ double;\nusing pi = pair<int, int>;\nusing pl = pair<ll, ll>;\n\ntemplate <class\
    \ T> using vec = vector<T>;\nusing vb = vec<bool>;\nusing vi = vec<int>; \nusing\
    \ vl = vec<ll>;\nusing vd = vec<ld>;\nusing vs = vec<string>;\nusing vpi = vec<pi>;\n\
    using vpl = vec<pl>;\n\ntemplate <class T, size_t N> using arr = array<T, N>;\n\
    template <size_t N> using ai = array<int, N>;\ntemplate <size_t N> using al =\
    \ array<ll, N>;\n\ntemplate <class T>\nbool ckmin(T &a, T b) {\n    return b <\
    \ a ? a = b, 1 : 0; \n}\ntemplate <class T>\nbool ckmax(T &a, T b) {\n    return\
    \ b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T, class U>\nT bsmin(T lo, T hi,\
    \ U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo);\
    \ i > 0; i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n \
    \   return hi;\n}\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f) {\n \
    \   assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n    }\n    return\
    \ lo;\n}\n\nconst int INF = 1e9;\nconst ll INFL = 1e18;\n\n// void solve() {\n\
    // }\n\n// int32_t main() {\n//     cin.tie(0)->sync_with_stdio(0);\n//     cin.exceptions(cin.failbit);\n\
    \n//     int t = 1;\n//     // cin >> t;\n//     while (t--) {\n//         solve();\n\
    //     }\n\n//     return 0;\n// }\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include\
    \ <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a, b, c, d, ...) d\n\
    \ \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define rep2(i,\
    \ n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n\
    \ \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define\
    \ per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\nusing ld = long double;\nusing pi = pair<int, int>;\nusing pl = pair<ll,\
    \ ll>;\n\ntemplate <class T> using vec = vector<T>;\nusing vb = vec<bool>;\nusing\
    \ vi = vec<int>; \nusing vl = vec<ll>;\nusing vd = vec<ld>;\nusing vs = vec<string>;\n\
    using vpi = vec<pi>;\nusing vpl = vec<pl>;\n\ntemplate <class T, size_t N> using\
    \ arr = array<T, N>;\ntemplate <size_t N> using ai = array<int, N>;\ntemplate\
    \ <size_t N> using al = array<ll, N>;\n\ntemplate <class T>\nbool ckmin(T &a,\
    \ T b) {\n    return b < a ? a = b, 1 : 0; \n}\ntemplate <class T>\nbool ckmax(T\
    \ &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T, class\
    \ U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T\
    \ i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi -= (hi - i >= lo &&\
    \ f(hi - i)) * i;\n    }\n    return hi;\n}\ntemplate <class T, class U>\nT bsmax(T\
    \ lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n \
    \   }\n    return lo;\n}\n\nconst int INF = 1e9;\nconst ll INFL = 1e18;\n\n//\
    \ void solve() {\n// }\n\n// int32_t main() {\n//     cin.tie(0)->sync_with_stdio(0);\n\
    //     cin.exceptions(cin.failbit);\n\n//     int t = 1;\n//     // cin >> t;\n\
    //     while (t--) {\n//         solve();\n//     }\n\n//     return 0;\n// }"
  dependsOn:
  - utils/bits/stdc++.h
  - utils/compat.h
  - utils/debug.h
  - utils/random.h
  isVerificationFile: false
  path: template/template.h
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/aizu/alds1/number_of_inversions.test.cpp
  - verify/aizu/ntl/power.test.cpp
  - verify/aizu/dsl/rmq.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
  - verify/library_checker/data_structure/static_rmq.test.cpp
  - verify/library_checker/data_structure/set_xor_min.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/associative_array.test.cpp
  - verify/library_checker/string/suffix_array.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/scc.test.cpp
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - verify/library_checker/tree/lca.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
documentation_of: template/template.h
layout: document
redirect_from:
- /library/template/template.h
- /library/template/template.h.html
title: template/template.h
---
