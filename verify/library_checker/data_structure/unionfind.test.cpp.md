---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/dsu.h
    title: datastructures/dsu.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes: {}
  bundledCode: "#line 1 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"\
    misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef\
    \ LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
    \ b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    #define pb push_back\n#define eb emplace_back\n#define f first\n#define s second\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n    return b <\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n\
    \    return b > a ? a = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n    \
    \    cin.tie(0)->sync_with_stdio(0);\n        cin.exceptions(cin.failbit);\n \
    \       cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 2 \"datastructures/dsu.h\"\
    \n\nstruct DSU {\n    vector<int> a;\n\n    DSU(int n) : a(n, -1) {}\n\n    int\
    \ size(int x) {\n        return -a[find(x)];\n    }\n\n    int find(int x) {\n\
    \        return a[x] < 0 ? x : a[x] = find(a[x]);\n    }\n\n    bool join(int\
    \ x, int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y)\
    \ {\n            return 0;\n        }\n        if (a[x] > a[y]) {\n          \
    \  swap(x, y);\n        }\n        a[x] += a[y];\n        a[y] = x;\n        return\
    \ 1;\n    }\n};\n#line 5 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    DSU dsu(n);\n    while\
    \ (q--) {\n        bool t;\n        int x, y;\n        cin >> t >> x >> y;\n \
    \       if (t) {\n            cout << (dsu.find(x) == dsu.find(y)) << '\\n';\n\
    \        } else {\n            dsu.join(x, y);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../misc/template.h\"\n#include \"../../../datastructures/dsu.h\"\n\n\
    int main() {\n    int n, q;\n    cin >> n >> q;\n    DSU dsu(n);\n    while (q--)\
    \ {\n        bool t;\n        int x, y;\n        cin >> t >> x >> y;\n       \
    \ if (t) {\n            cout << (dsu.find(x) == dsu.find(y)) << '\\n';\n     \
    \   } else {\n            dsu.join(x, y);\n        }\n    }\n}"
  dependsOn:
  - misc/template.h
  - datastructures/dsu.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/unionfind.test.cpp
- /verify/verify/library_checker/data_structure/unionfind.test.cpp.html
title: verify/library_checker/data_structure/unionfind.test.cpp
---
