---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  - icon: ':question:'
    path: utils/bits/stdc++.h
    title: utils/bits/stdc++.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B
  bundledCode: "#line 1 \"verify/aizu/alds1/binary_search.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\n\n\
    #line 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\n\n// void solve() {\n// }\n\n// int main() {\n//     cin.tie(0)->sync_with_stdio(0);\n\
    //     cin.exceptions(cin.failbit);\n\n//     int t = 1;\n//     // cin >> t;\n\
    //     while (t--) {\n//         solve();\n//     }\n\n//     return 0;\n// }\n\
    #line 4 \"verify/aizu/alds1/binary_search.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    cin >> n;\n    vector<int> a(n);\n    for (int i = 0; i < n; i++) {\n\
    \        cin >> a[i];\n    }\n    sort(all(a));\n    int q;\n    cin >> q;\n \
    \   int ans = 0;\n    while (q--) {\n        int x;\n        cin >> x;\n     \
    \   int idx = bsmin(0, n - 1, [&](int p) {\n            return a[p] >= x;\n  \
    \      });\n        ans += idx != n && a[idx] == x;\n    }\n    cout << ans <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_4_B\"\
    \n\n#include \"../../../template/template.h\"\n\nint main() {\n    int n;\n  \
    \  cin >> n;\n    vector<int> a(n);\n    for (int i = 0; i < n; i++) {\n     \
    \   cin >> a[i];\n    }\n    sort(all(a));\n    int q;\n    cin >> q;\n    int\
    \ ans = 0;\n    while (q--) {\n        int x;\n        cin >> x;\n        int\
    \ idx = bsmin(0, n - 1, [&](int p) {\n            return a[p] >= x;\n        });\n\
    \        ans += idx != n && a[idx] == x;\n    }\n    cout << ans << '\\n';\n}"
  dependsOn:
  - template/template.h
  - utils/bits/stdc++.h
  isVerificationFile: true
  path: verify/aizu/alds1/binary_search.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 20:34:38-05:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aizu/alds1/binary_search.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/binary_search.test.cpp
- /verify/verify/aizu/alds1/binary_search.test.cpp.html
title: verify/aizu/alds1/binary_search.test.cpp
---
