---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../../graphs/dijkstras.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../graphs/dijkstras.h\"\n\n// Just\
    \ a sanity check - makes sure the result is valid\n\nconst int T = 100;\nconst\
    \ int INF = INT_MAX / 2;\n\nint main() {\n    for (int i = 0; i < T; i++) {\n\
    \        const int n = rand_int(1e2, 1e4), root = rand_int(n);\n        auto g\
    \ = gen_graph(n, n - 1 + rand_int(n));\n\n        vector<int> dist(n, INF);\n\
    \        queue<int> q;\n        dist[root] = 0;\n        q.push(root);\n\n   \
    \     while (sz(q)) {\n            int u = q.front();\n            q.pop();\n\
    \            for (int v : g[u]) {\n                if (dist[v] == INF) {\n   \
    \                 dist[v] = dist[u] + 1;\n                    q.push(v);\n   \
    \             }\n            }\n        }\n        assert(find(all(dist), INF)\
    \ == end(dist));\n    }\n\n    for (int i = 0; i < T; i++) {\n        const int\
    \ n = rand_int(1e2, 1e4), root = rand_int(n);\n        auto g = gen_weighted_graph(n,\
    \ n - 1 + rand_int(n));\n        \n        auto from = dijkstras<ll>(g, root).second;\n\
    \        from[root] = root;\n        assert(find(all(from), -1) == end(from));\n\
    \    }\n\n    cerr << \"Tests passed\" << endl;\n\n    int a, b;\n    cin >> a\
    \ >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn: []
  isVerificationFile: true
  path: verify/custom/utils/random_graph.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/custom/utils/random_graph.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/random_graph.test.cpp
- /verify/verify/custom/utils/random_graph.test.cpp.html
title: verify/custom/utils/random_graph.test.cpp
---
