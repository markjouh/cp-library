---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/dsu.h
    title: src/datastructures/dsu.h
  - icon: ':heavy_check_mark:'
    path: src/template/template.h
    title: src/template/template.h
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
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"\
    src/template/template.h\"\n/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"src/datastructures/dsu.h\"\nstruct DSU {\n  vector<int> a;\n\
    \n  DSU(int n) : a(n, -1) {}\n\n  int size(int x) {\n    return -a[find(x)];\n\
    \  }\n\n  int find(int x) {\n    return a[x] < 0 ? x : a[x] = find(a[x]);\n  }\n\
    \n  bool join(int x, int y) {\n    x = find(x);\n    y = find(y);\n    if (x ==\
    \ y) {\n      return 0;\n    }\n    if (a[x] > a[y]) {\n      swap(x, y);\n  \
    \  }\n    a[x] += a[y];\n    a[y] = x;\n    return 1;\n  }\n};\n#line 5 \"src/verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  DSU comps(n);\n  while (q--)\
    \ {\n    bool t;\n    int x, y;\n    cin >> t >> x >> y;\n    if (t) {\n     \
    \ cout << (comps.find(x) == comps.find(y)) << '\\n';\n    } else {\n      comps.join(x,\
    \ y);\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../datastructures/dsu.h\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  DSU comps(n);\n  while (q--)\
    \ {\n    bool t;\n    int x, y;\n    cin >> t >> x >> y;\n    if (t) {\n     \
    \ cout << (comps.find(x) == comps.find(y)) << '\\n';\n    } else {\n      comps.join(x,\
    \ y);\n    }\n  }\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/dsu.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/unionfind.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/unionfind.test.cpp
- /verify/src/verify/library_checker/data_structure/unionfind.test.cpp.html
title: src/verify/library_checker/data_structure/unionfind.test.cpp
---
