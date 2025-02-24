---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/ordered_set.h
    title: datastructures/ordered_set.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
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
    \n\n#line 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing\
    \ ll = long long;\n#line 1 \"datastructures/ordered_set.h\"\n#include <ext/pb_ds/assoc_container.hpp>\
    \ \n#include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds; \n\ntemplate\
    \ <class T>\nusing ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ntemplate <class T>\nstruct ordered_multiset {\n  int time = 0;\n  ordered_set<pair<T,\
    \ int>> st;\n \n  void insert(T x) {\n    st.insert({x, time++});\n  }\n \n  void\
    \ extract(T x) {\n    auto it = st.lower_bound({x, 0});\n    if (it != end(st)\
    \ && it->first == x) {\n      st.erase(it);\n    }\n  }\n \n  T find_by_order(int\
    \ k) {\n    return (*st.find_by_order(k)).first;\n  }\n \n  int order_of_key(T\
    \ x) {\n    return st.order_of_key({x, 0});\n  }\n};\n#line 5 \"verify/aizu/alds1/number_of_inversions.test.cpp\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    ll ans = 0;\n    ordered_set<int>\
    \ st;\n    for (int i = 0; i < n; i++) {\n        int x;\n        cin >> x;\n\
    \        ans += sz(st) - st.order_of_key(x + 1);\n        st.insert(x);\n    }\n\
    \    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../datastructures/ordered_set.h\"\
    \n\nint main() {\n    int n;\n    cin >> n;\n    ll ans = 0;\n    ordered_set<int>\
    \ st;\n    for (int i = 0; i < n; i++) {\n        int x;\n        cin >> x;\n\
    \        ans += sz(st) - st.order_of_key(x + 1);\n        st.insert(x);\n    }\n\
    \    cout << ans << '\\n';\n}"
  dependsOn:
  - template/template.h
  - datastructures/ordered_set.h
  isVerificationFile: true
  path: verify/aizu/alds1/number_of_inversions.test.cpp
  requiredBy: []
  timestamp: '2025-02-24 12:15:36-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/number_of_inversions.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/number_of_inversions.test.cpp
- /verify/verify/aizu/alds1/number_of_inversions.test.cpp.html
title: verify/aizu/alds1/number_of_inversions.test.cpp
---
