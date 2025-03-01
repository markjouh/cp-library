---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructures/static/sparse_table.h
    title: datastructures/static/sparse_table.h
  - icon: ':x:'
    path: template/template.h
    title: template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"\
    template/template.h\"\n#include <bits/stdc++.h>\n \nusing namespace std;\n \n\
    #define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l);\
    \ i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__,\
    \ rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1;\
    \ i >= int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__,\
    \ per3, per2) (__VA_ARGS__)\n \n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n \n#define pb push_back\n#define eb emplace_back\n#define fi first\n\
    #define se second\n \nusing ll = long long;\nusing pi = pair<int, int>;\nusing\
    \ pl = pair<ll, ll>;\nusing vi = vector<int>;\nusing vl = vector<ll>;\nusing vpi\
    \ = vector<pi>;\nusing vpl = vector<pl>;\n \ntemplate <class T>\nbool ckmin(T\
    \ &a, const T b) {\n    return b < a ? a = b, 1 : 0; \n}\ntemplate <class T>\n\
    bool ckmax(T &a, const T b) {\n    return b > a ? a = b, 1 : 0;\n}\n \ntemplate\
    \ <class T, class U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n\
    \    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi -= (hi -\
    \ i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\ntemplate <class T, class\
    \ U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n    for (T\
    \ i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo += (lo + i <= hi &&\
    \ f(lo + i)) * i;\n    }\n    return lo;\n}\n\ntemplate <class T, class = void>\n\
    struct is_range : false_type {};\ntemplate <class T>\nstruct is_range<T, void_t<decltype(begin(declval<T>())),\
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
    }\n#line 1 \"datastructures/static/sparse_table.h\"\ntemplate <class T, auto op>\n\
    struct sparse_table {\n    int n, log;\n    vector<vector<T>> st;\n\n    sparse_table()\
    \ {}\n    sparse_table(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1) {\n  \
    \      st.resize(log);\n        st[0] = a;\n        for (int i = 1; i < log; i++)\
    \ {\n            st[i].resize(n - (1 << i) + 1);\n            for (int j = 0;\
    \ j < sz(st[i]); j++) {\n                st[i][j] = op(st[i - 1][j], st[i - 1][j\
    \ + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T query(int l, int\
    \ r) {\n        assert(l <= r);\n        int i = __lg(++r - l);\n        return\
    \ op(st[i][l], st[i][r - (1 << i)]);\n    }\n};\n\ntemplate <class T>\nT min_op(T\
    \ x, T y) {\n    return x < y ? x : y;\n}\ntemplate <class T>\nT max_op(T x, T\
    \ y) {\n    return x > y ? x : y;\n}\n#line 5 \"verify/library_checker/data_structure/static_rmq.test.cpp\"\
    \n\nint op(int x, int y) {\n    return x < y ? x : y;\n}\n\nint main() {\n   \
    \ int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        cin >> a[i];\n    }\n    sparse_table<int, op> rmq(a);\n\
    \    while (q--) {\n        int l, r;\n        cin >> l >> r;\n        cout <<\
    \ rmq.query(l, r - 1) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../datastructures/static/sparse_table.h\"\
    \n\nint op(int x, int y) {\n    return x < y ? x : y;\n}\n\nint main() {\n   \
    \ int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i\
    \ < n; i++) {\n        cin >> a[i];\n    }\n    sparse_table<int, op> rmq(a);\n\
    \    while (q--) {\n        int l, r;\n        cin >> l >> r;\n        cout <<\
    \ rmq.query(l, r - 1) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.h
  - datastructures/static/sparse_table.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_rmq.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 17:36:32-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_rmq.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp
- /verify/verify/library_checker/data_structure/static_rmq.test.cpp.html
title: verify/library_checker/data_structure/static_rmq.test.cpp
---
