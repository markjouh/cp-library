---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/dsu.h
    title: datastructures/dsu.h
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"\
    misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef\
    \ LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 1 \"\
    datastructures/dsu.h\"\nstruct DSU {\n    vector<int> a;\n\n    DSU(int n) : a(n,\
    \ -1) {}\n\n    int size(int x) {\n        return -a[find(x)];\n    }\n\n    int\
    \ find(int x) {\n        return a[x] < 0 ? x : a[x] = find(a[x]);\n    }\n\n \
    \   bool join(int x, int y) {\n        x = find(x);\n        y = find(y);\n  \
    \      if (x == y) {\n            return 0;\n        }\n        if (a[x] > a[y])\
    \ {\n            swap(x, y);\n        }\n        a[x] += a[y];\n        a[y] =\
    \ x;\n        return 1;\n    }\n};\n#line 5 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
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
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/dsu.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 20:08:44-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/unionfind.test.cpp
- /verify/verify/library_checker/data_structure/unionfind.test.cpp.html
title: verify/library_checker/data_structure/unionfind.test.cpp
---
