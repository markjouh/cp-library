---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: common/binsearch.h
    title: common/binsearch.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/my_random.h
    title: utils/my_random.h
  - icon: ':question:'
    path: utils/my_timer.h
    title: utils/my_timer.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
  bundledCode: "#line 1 \"verify/aizu/alds1/binary_search.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\n\n\
    #line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate\
    \ <class T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line\
    \ 2 \"common/binsearch.h\"\n\ntemplate <class T, class U>\nT bsmin(T lo, T hi,\
    \ U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo);\
    \ i > 0; i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n \
    \   return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f) {\n\
    \    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n    }\n    return\
    \ lo;\n}\n#line 5 \"verify/aizu/alds1/binary_search.test.cpp\"\n\nint main() {\n\
    \    int n;\n    cin >> n;\n    vector<int> a(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        cin >> a[i];\n    }\n    sort(all(a));\n    int q;\n    cin\
    \ >> q;\n    int ans = 0;\n    while (q--) {\n        int x;\n        cin >> x;\n\
    \        int idx = bsmin(0, n - 1, [&](int p) {\n            return a[p] >= x;\n\
    \        });\n        ans += idx != n && a[idx] == x;\n    }\n    cout << ans\
    \ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../common/binsearch.h\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    vector<int> a(n);\n    for (int\
    \ i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    sort(all(a));\n    int\
    \ q;\n    cin >> q;\n    int ans = 0;\n    while (q--) {\n        int x;\n   \
    \     cin >> x;\n        int idx = bsmin(0, n - 1, [&](int p) {\n            return\
    \ a[p] >= x;\n        });\n        ans += idx != n && a[idx] == x;\n    }\n  \
    \  cout << ans << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - common/binsearch.h
  isVerificationFile: true
  path: verify/aizu/alds1/binary_search.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 19:29:34-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/binary_search.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/binary_search.test.cpp
- /verify/verify/aizu/alds1/binary_search.test.cpp.html
title: verify/aizu/alds1/binary_search.test.cpp
---
