---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/template.cpp\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n\
    #define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a\
    \ ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n \
    \ return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr\
    \ T inf = numeric_limits<T>::max() / 2;\n\nvoid solve() {\n}\n\nint main() {\n\
    \  cin.tie(0)->sync_with_stdio(0);\n  cin.exceptions(cin.failbit);\n\n  int t\
    \ = 1;\n  // cin >> t;\n  while (t--) {\n    solve();\n  }\n}\n"
  code: "#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include\
    \ <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x), end(x)\n\
    #define sz(x) int(size(x))\n#define pb push_back\n#define eb emplace_back\n#define\
    \ fi first\n#define se second\n\nusing ll = long long;\n\ntemplate <class T>\n\
    bool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate\
    \ <class T>\nbool ckmax(T &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n\
    }\n\ntemplate <class T = int>\nstatic constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n\nvoid solve() {\n}\n\nint main() {\n  cin.tie(0)->sync_with_stdio(0);\n\
    \  cin.exceptions(cin.failbit);\n\n  int t = 1;\n  // cin >> t;\n  while (t--)\
    \ {\n    solve();\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/template.cpp
  requiredBy: []
  timestamp: '2024-09-05 23:15:12-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/template.cpp
layout: document
redirect_from:
- /library/misc/template.cpp
- /library/misc/template.cpp.html
title: misc/template.cpp
---
