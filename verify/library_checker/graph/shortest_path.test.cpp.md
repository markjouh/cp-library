---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/dijkstras.hpp
    title: Dijkstra's Shortest Paths
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../../boilerplate.hpp\"\n#include \"../../../graphs/dijkstras.hpp\"\n\nint\
    \ main() {\n  int n, m, s, t;\n  cin >> n >> m >> s >> t;\n  vector<vector<pii>>\
    \ g(n);\n  for (int i = 0; i < m; i++) {\n    int u, v, w;\n    cin >> u >> v\
    \ >> w;\n    g[u].eb(v, w);\n  }\n  auto [dist, from] = dijkstras<ll>(g, s);\n\
    \  if (dist[t] != numeric_limits<ll>::max()) {\n    cout << dist[t] << ' ';\n\
    \    vector<pii> path;\n    int p = t;\n    while (p != s) {\n      path.eb(from[p],\
    \ p);\n      p = from[p];\n    }\n    reverse(all(path));\n    cout << sz(path)\
    \ << '\\n';\n    for (auto [u, v] : path) {\n      cout << u << ' ' << v << '\\\
    n';\n    }\n  } else {\n    cout << -1 << '\\n';\n  }\n}"
  dependsOn:
  - graphs/dijkstras.hpp
  isVerificationFile: true
  path: verify/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/shortest_path.test.cpp
- /verify/verify/library_checker/graph/shortest_path.test.cpp.html
title: verify/library_checker/graph/shortest_path.test.cpp
---
