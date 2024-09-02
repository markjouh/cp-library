---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/pbds/order_statistic_tree.hpp
    title: datastructures/pbds/order_statistic_tree.hpp
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
    \n\n#line 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing\
    \ namespace std;\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    #define pb push_back\n#define eb emplace_back\n#define fi first\n#define se second\n\
    \nusing ll = long long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n\
    #else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n\
    }\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a =\
    \ b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return\
    \ b > a ? a = b, 1 : 0;\n}\n\nconst int INF = INT_MAX / 2;\nconst ll INFLL = LLONG_MAX\
    \ / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"datastructures/pbds/order_statistic_tree.hpp\"\n\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n\nusing namespace __gnu_pbds;\n\ntemplate <class\
    \ T>\nusing OrderStatisticTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    #line 5 \"verify/aizu/alds1/number_of_inversions.test.cpp\"\n\nint main() {\n\
    \  int n;\n  cin >> n;\n  ll ans = 0;\n  OrderStatisticTree<int> st;\n  for (int\
    \ i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n    ans += sz(st) - st.order_of_key(x\
    \ + 1);\n    st.insert(x);\n  }\n  cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/pbds/order_statistic_tree.hpp\"\
    \n\nint main() {\n  int n;\n  cin >> n;\n  ll ans = 0;\n  OrderStatisticTree<int>\
    \ st;\n  for (int i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n    ans +=\
    \ sz(st) - st.order_of_key(x + 1);\n    st.insert(x);\n  }\n  cout << ans << '\\\
    n';\n}"
  dependsOn:
  - datastructures/pbds/order_statistic_tree.hpp
  isVerificationFile: true
  path: verify/aizu/alds1/number_of_inversions.test.cpp
  requiredBy: []
  timestamp: '2024-09-01 20:48:11-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/number_of_inversions.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/number_of_inversions.test.cpp
- /verify/verify/aizu/alds1/number_of_inversions.test.cpp.html
title: verify/aizu/alds1/number_of_inversions.test.cpp
---
