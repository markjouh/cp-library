---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/order_statistic_tree.hpp
    title: Order Statistic Tree
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ verify/boilerplate.hpp: line 5: unable to process #include in #if / #ifdef /\
    \ #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/order_statistic_tree.hpp\"\
    \n\nint main() {\n  int n;\n  cin >> n;\n  ll ans = 0;\n  OrderStatisticTree<int>\
    \ st;\n  for (int i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n    ans +=\
    \ sz(st) - st.order_of_key(x + 1);\n    st.insert(x);\n  }\n  cout << ans << '\\\
    n';\n}"
  dependsOn:
  - datastructures/order_statistic_tree.hpp
  isVerificationFile: true
  path: verify/aizu/alds1/number_of_inversions.test.cpp
  requiredBy: []
  timestamp: '2024-08-30 00:27:56-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/number_of_inversions.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/number_of_inversions.test.cpp
- /verify/verify/aizu/alds1/number_of_inversions.test.cpp.html
title: verify/aizu/alds1/number_of_inversions.test.cpp
---
