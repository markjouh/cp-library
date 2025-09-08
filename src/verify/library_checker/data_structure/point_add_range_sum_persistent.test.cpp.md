---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../datastructures/segment_tree/persistent_segtree.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../../template/template.h\"\n#include \"../../../datastructures/segment_tree/persistent_segtree.h\"\
    \n\nusing ll = long long;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  \n\
    \  auto op = [](ll a, ll b) { return a + b; };\n  auto id = []() { return 0LL;\
    \ };\n  \n  PersistentSegtree<ll, op, id> seg(n);\n  \n  for (int i = 0; i < n;\
    \ i++) {\n    ll a;\n    cin >> a;\n    seg.update(i, a);\n  }\n  \n  while (q--)\
    \ {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int p;\n      ll x;\n\
    \      cin >> p >> x;\n      ll cur = seg.query(p, p);\n      seg.update(p, cur\
    \ + x);\n    } else {\n      int l, r;\n      cin >> l >> r;\n      cout << seg.query(l,\
    \ r - 1) << '\\n';\n    }\n  }\n  \n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
- /verify/src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp.html
title: src/verify/library_checker/data_structure/point_add_range_sum_persistent.test.cpp
---
