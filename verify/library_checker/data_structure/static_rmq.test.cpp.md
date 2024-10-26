---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/static/rmq.h
    title: datastructures/static/rmq.h
  - icon: ':heavy_check_mark:'
    path: template/template.h
    title: template/template.h
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"\
    template/template.h\"\n#include <bits/stdc++.h>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \ \nusing namespace std;\nusing namespace __gnu_pbds;\n \n#ifdef LOCAL\n#include\
    \ <utils>\n#else\n#define dbg(...)\n#endif\n \n#define arg4(a, b, c, d, ...) d\n\
    \ \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define rep2(i,\
    \ n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n\
    \ \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define\
    \ per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \ \n#define bg(x) begin(x)\n#define all(x) bg(x), end(x)\n#define sz(x) int(size(x))\n\
    \ \n#define acc accumulate\n#define mne min_element\n#define mxe max_element\n\
    #define lb lower_bound\n#define ub upper_bound\n \n#define pb push_back\n#define\
    \ eb emplace_back\n#define pbk pop_back\n#define ins insert\n#define era erase\n\
    \ \n#define fi first\n#define se second\n \ntemplate <class T, size_t N> using\
    \ arr = array<T, N>;\ntemplate <class T> using vec = vector<T>;\ntemplate <class\
    \ T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ \nusing ll = long long;\nusing ld = long double;\nusing str = string;\n \nusing\
    \ pi = pair<int, int>;\nusing pl = pair<ll, ll>;\n \nusing vb = vec<bool>;\nusing\
    \ vi = vec<int>; \nusing vl = vec<ll>;\nusing vd = vec<ld>;\nusing vs = vec<str>;\n\
    using vpi = vec<pi>;\nusing vpl = vec<pl>;\n\ntemplate <class T>\nbool ckmin(T\
    \ &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class T>\nbool ckmax(T\
    \ &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T, class\
    \ U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T\
    \ i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi -= (hi - i >= lo &&\
    \ f(hi - i)) * i;\n    }\n    return hi;\n}\ntemplate <class T, class U>\nT bsmax(T\
    \ lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n \
    \   }\n    return lo;\n}\n\nconst int INF = INT_MAX / 2;\nconst ll INFL = LLONG_MAX\
    \ / 2;\n\n// void solve() {\n// }\n\n// int main() {\n//     cin.tie(0)->sync_with_stdio(0);\n\
    //     cin.exceptions(cin.failbit);\n\n//     int t = 1;\n//     // cin >> t;\n\
    //     while (t--) {\n//         solve();\n//     }\n// }\n#line 2 \"datastructures/static/rmq.h\"\
    \n\ntemplate <class T>\nT min_f(T x, T y) {\n    return x < y ? x : y;\n}\ntemplate\
    \ <class T>\nT max_f(T x, T y) {\n    return x > y ? x : y;\n}\n\ntemplate <class\
    \ T, auto op = min_f<T>>\nstruct RMQ {\n    int n, log;\n    vector<vector<T>>\
    \ st;\n\n    RMQ() {}\n    RMQ(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1)\
    \ {\n        st.resize(log);\n        st[0] = a;\n        for (int i = 1; i <\
    \ log; i++) {\n            st[i].resize(n - (1 << i) + 1);\n            for (int\
    \ j = 0; j < sz(st[i]); j++) {\n                st[i][j] = op(st[i - 1][j], st[i\
    \ - 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int\
    \ l, int r) {\n        assert(l <= r);\n        int i = __lg(++r - l);\n     \
    \   return op(st[i][l], st[i][r - (1 << i)]);\n    }\n};\n#line 5 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n\nint op(int x, int y) {\n    return x < y ? x : y;\n}\n\nint main() {\n   \
    \ int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        cin >> a[i];\n    }\n    RMQ<int, op> rmq(a);\n    while\
    \ (q--) {\n        int l, r;\n        cin >> l >> r;\n        cout << rmq.query(l,\
    \ r - 1) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../datastructures/static/rmq.h\"\
    \n\nint op(int x, int y) {\n    return x < y ? x : y;\n}\n\nint main() {\n   \
    \ int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        cin >> a[i];\n    }\n    RMQ<int, op> rmq(a);\n    while\
    \ (q--) {\n        int l, r;\n        cin >> l >> r;\n        cout << rmq.query(l,\
    \ r - 1) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/static/rmq.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 20:32:34-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp.html
title: verify/library_checker/data_structure/static_rmq.test.cpp
---
