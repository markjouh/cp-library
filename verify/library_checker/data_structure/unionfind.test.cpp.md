---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/dsu.h
    title: datastructures/dsu.h
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
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"verify/library_checker/data_structure/unionfind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#line 1 \"\
    template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\
    #line 1 \"datastructures/dsu.h\"\nstruct dsu {\n    vector<int> a;\n\n    dsu(int\
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
  timestamp: '2024-12-07 19:52:17-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/unionfind.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/unionfind.test.cpp
- /verify/verify/library_checker/data_structure/unionfind.test.cpp.html
title: verify/library_checker/data_structure/unionfind.test.cpp
---
