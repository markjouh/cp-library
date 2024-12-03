---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/dsu.h
    title: datastructures/dsu.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  - icon: ':question:'
    path: utils/bits/stdc++.h
    title: utils/bits/stdc++.h
  - icon: ':question:'
    path: utils/compat.h
    title: utils/compat.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/random.h
    title: utils/random.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"\
    template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef\
    \ LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
    \ b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    \n#define pb push_back\n#define eb emplace_back\n#define fi first\n#define se\
    \ second\n\nusing ll = long long;\nusing ld = long double;\nusing pi = pair<int,\
    \ int>;\nusing pl = pair<ll, ll>;\n\ntemplate <class T> using vec = vector<T>;\n\
    using vb = vec<bool>;\nusing vi = vec<int>; \nusing vl = vec<ll>;\nusing vd =\
    \ vec<ld>;\nusing vs = vec<string>;\nusing vpi = vec<pi>;\nusing vpl = vec<pl>;\n\
    \ntemplate <class T, size_t N> using arr = array<T, N>;\ntemplate <size_t N> using\
    \ ai = array<int, N>;\ntemplate <size_t N> using al = array<ll, N>;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0; \n}\ntemplate\
    \ <class T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\n\
    template <class T, class U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n\
    \    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi\
    \ -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\ntemplate <class\
    \ T, class U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n\
    \    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo += (lo +\
    \ i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}\n\nconst int INF = 1e9;\n\
    const ll INFL = 1e18;\n\n// void solve() {\n// }\n\n// int32_t main() {\n//  \
    \   cin.tie(0)->sync_with_stdio(0);\n//     cin.exceptions(cin.failbit);\n\n//\
    \     int t = 1;\n//     // cin >> t;\n//     while (t--) {\n//         solve();\n\
    //     }\n\n//     return 0;\n// }\n#line 1 \"datastructures/dsu.h\"\nstruct dsu\
    \ {\n    vector<int> a;\n\n    dsu(int n) : a(n, -1) {}\n\n    int size(int x)\
    \ {\n        return -a[find(x)];\n    }\n\n    int find(int x) {\n        return\
    \ a[x] < 0 ? x : a[x] = find(a[x]);\n    }\n\n    bool join(int x, int y) {\n\
    \        x = find(x);\n        y = find(y);\n        if (x == y) {\n         \
    \   return 0;\n        }\n        if (a[x] > a[y]) {\n            swap(x, y);\n\
    \        }\n        a[x] += a[y];\n        a[y] = x;\n        return 1;\n    }\n\
    };\n#line 5 \"verify/library_checker/data_structure/unionfind.test.cpp\"\n\nint\
    \ main() {\n    int n, q;\n    cin >> n >> q;\n    dsu comps(n);\n    while (q--)\
    \ {\n        bool t;\n        int x, y;\n        cin >> t >> x >> y;\n       \
    \ if (t) {\n            cout << (comps.find(x) == comps.find(y)) << '\\n';\n \
    \       } else {\n            comps.join(x, y);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../datastructures/dsu.h\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    dsu comps(n);\n    while\
    \ (q--) {\n        bool t;\n        int x, y;\n        cin >> t >> x >> y;\n \
    \       if (t) {\n            cout << (comps.find(x) == comps.find(y)) << '\\\
    n';\n        } else {\n            comps.join(x, y);\n        }\n    }\n}"
  dependsOn:
  - template/template.h
  - utils/bits/stdc++.h
  - utils/compat.h
  - utils/debug.h
  - utils/random.h
  - datastructures/dsu.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/unionfind.test.cpp
- /verify/verify/library_checker/data_structure/unionfind.test.cpp.html
title: verify/library_checker/data_structure/unionfind.test.cpp
---
