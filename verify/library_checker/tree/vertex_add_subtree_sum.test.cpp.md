---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: graphs/euler_tour.hpp
    title: graphs/euler_tour.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/fenwick_tree.hpp\"\
    \n#include \"../../../graphs/euler_tour.hpp\"\n\nint main() {\n  int n, q;\n \
    \ cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++) {\n    cin\
    \ >> a[i];\n  }\n  vector<vector<int>> g(n);\n  for (int i = 1; i < n; i++) {\n\
    \    int p;\n    cin >> p;\n    g[p].pb(i);\n  }\n  EulerTour et(g);\n  FenwickTree<ll>\
    \ ft(n);\n  for (int i = 0; i < n; i++) {\n    ft.add(et.tin[i], a[i]);\n  }\n\
    \  while (q--) {\n    bool t;\n    int u;\n    cin >> t >> u;\n    if (t) {\n\
    \      cout << ft.sum(et.tin[u], et.tout[u] - 1) << '\\n';\n    } else {\n   \
    \   int x;\n      cin >> x;\n      ft.add(et.tin[u], x);\n    }\n  }\n}"
  dependsOn:
  - datastructures/fenwick_tree.hpp
  - graphs/euler_tour.hpp
  isVerificationFile: true
  path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
- /verify/verify/library_checker/tree/vertex_add_subtree_sum.test.cpp.html
title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
---
