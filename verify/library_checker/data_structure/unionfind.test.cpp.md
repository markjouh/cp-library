---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructures/dsu.h
    title: datastructures/dsu.h
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"\
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
    }\n#line 1 \"datastructures/dsu.h\"\nstruct dsu {\n    vector<int> a;\n\n    dsu(int\
    \ n) : a(n, -1) {}\n\n    int size(int x) {\n        return -a[find(x)];\n   \
    \ }\n\n    int find(int x) {\n        return a[x] < 0 ? x : a[x] = find(a[x]);\n\
    \    }\n\n    bool join(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if (x == y) {\n            return 0;\n        }\n        if (a[x] > a[y])\
    \ {\n            swap(x, y);\n        }\n        a[x] += a[y];\n        a[y] =\
    \ x;\n        return 1;\n    }\n};\n#line 5 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    dsu comps(n);\n    while\
    \ (q--) {\n        bool t;\n        int x, y;\n        cin >> t >> x >> y;\n \
    \       if (t) {\n            cout << (comps.find(x) == comps.find(y)) << '\\\
    n';\n        } else {\n            comps.join(x, y);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../datastructures/dsu.h\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    dsu comps(n);\n    while\
    \ (q--) {\n        bool t;\n        int x, y;\n        cin >> t >> x >> y;\n \
    \       if (t) {\n            cout << (comps.find(x) == comps.find(y)) << '\\\
    n';\n        } else {\n            comps.join(x, y);\n        }\n    }\n}"
  dependsOn:
  - template/template.h
  - datastructures/dsu.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 17:36:32-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/unionfind.test.cpp
- /verify/verify/library_checker/data_structure/unionfind.test.cpp.html
title: verify/library_checker/data_structure/unionfind.test.cpp
---
