---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../datastructures/fenwick_tree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/fenwick_tree.hpp\"\
    \n#include \"../../../graphs/tree/euler_tour.hpp\"\n\nint main() {\n  int n, q;\n\
    \  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++) {\n    cin\
    \ >> a[i];\n  }\n  vector<vector<int>> g(n);\n  for (int i = 1; i < n; i++) {\n\
    \    int p;\n    cin >> p;\n    g[p].pb(i);\n  }\n  EulerTour et(g);\n  FenwickTree<ll>\
    \ ft(n);\n  for (int i = 0; i < n; i++) {\n    ft.add(et.tin[i], a[i]);\n  }\n\
    \  while (q--) {\n    bool t;\n    int u;\n    cin >> t >> u;\n    if (t) {\n\
    \      cout << ft.sum(et.tin[u], et.tout[u] - 1) << '\\n';\n    } else {\n   \
    \   int x;\n      cin >> x;\n      ft.add(et.tin[u], x);\n    }\n  }\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp.html
title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
---
