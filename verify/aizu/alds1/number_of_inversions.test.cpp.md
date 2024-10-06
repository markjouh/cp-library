---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: common/order_statistic_tree.h
    title: common/order_statistic_tree.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/encode.h
    title: utils/encode.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"verify/aizu/alds1/number_of_inversions.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\nusing\
    \ ld = long double;\n\ntemplate <class T>\nbool ckmin(T &a, T b) {\n    return\
    \ b < a ? a = b, 1 : 0;\n}\ntemplate <class T>\nbool ckmax(T &a, T b) {\n    return\
    \ b > a ? a = b, 1 : 0;\n}\n#line 2 \"common/order_statistic_tree.h\"\n\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n\nusing namespace __gnu_pbds;\n\ntemplate <class\
    \ T>\nusing OSTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    #line 5 \"verify/aizu/alds1/number_of_inversions.test.cpp\"\n\nint main() {\n\
    \    int n;\n    cin >> n;\n    ll ans = 0;\n    OSTree<int> st;\n    for (int\
    \ i = 0; i < n; i++) {\n        int x;\n        cin >> x;\n        ans += sz(st)\
    \ - st.order_of_key(x + 1);\n        st.insert(x);\n    }\n    cout << ans <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../common/order_statistic_tree.h\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    ll ans = 0;\n    OSTree<int>\
    \ st;\n    for (int i = 0; i < n; i++) {\n        int x;\n        cin >> x;\n\
    \        ans += sz(st) - st.order_of_key(x + 1);\n        st.insert(x);\n    }\n\
    \    cout << ans << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - common/order_statistic_tree.h
  isVerificationFile: true
  path: verify/aizu/alds1/number_of_inversions.test.cpp
  requiredBy: []
  timestamp: '2024-10-05 23:54:04-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/number_of_inversions.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/number_of_inversions.test.cpp
- /verify/verify/aizu/alds1/number_of_inversions.test.cpp.html
title: verify/aizu/alds1/number_of_inversions.test.cpp
---
