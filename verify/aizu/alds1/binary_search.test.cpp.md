---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: numeric/binsearch.h
    title: numeric/binsearch.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes: {}
  bundledCode: "#line 1 \"verify/aizu/alds1/binary_search.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\n\n\
    #line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
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
    \       cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 2 \"numeric/binsearch.h\"\
    \n\ntemplate <class T, class U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <=\
    \ hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n \
    \       hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\n\ntemplate\
    \ <class T, class U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n\
    \    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo += (lo +\
    \ i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}\n#line 5 \"verify/aizu/alds1/binary_search.test.cpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    sort(all(a));\n    int\
    \ q;\n    cin >> q;\n    int ans = 0;\n    while (q--) {\n        int x;\n   \
    \     cin >> x;\n        int idx = bsmin(0, n - 1, [&](int p) {\n            return\
    \ a[p] >= x;\n        });\n        ans += idx != n && a[idx] == x;\n    }\n  \
    \  cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../numeric/binsearch.h\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    sort(all(a));\n    int\
    \ q;\n    cin >> q;\n    int ans = 0;\n    while (q--) {\n        int x;\n   \
    \     cin >> x;\n        int idx = bsmin(0, n - 1, [&](int p) {\n            return\
    \ a[p] >= x;\n        });\n        ans += idx != n && a[idx] == x;\n    }\n  \
    \  cout << ans << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - numeric/binsearch.h
  isVerificationFile: true
  path: verify/aizu/alds1/binary_search.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/binary_search.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/binary_search.test.cpp
- /verify/verify/aizu/alds1/binary_search.test.cpp.html
title: verify/aizu/alds1/binary_search.test.cpp
---
