---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/w_ary_tree.hpp
    title: 64-ary Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
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
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/w_ary_tree.hpp\"\
    \n\nint main() {\n  string s;\n  int x;\n  vector<int> queries;\n  vector<int>\
    \ vals;\n  while (cin >> s) {\n    if (s == \"end\") {\n      break;\n    }\n\
    \    if (s == \"insert\") {\n      cin >> x;\n      queries.push_back(x);\n  \
    \    vals.push_back(x);\n    } else {\n      queries.push_back(-1);\n    }\n \
    \ }\n  sort(all(vals));\n  vals.resize(unique(all(vals)) - begin(vals));\n  WAryTree<2000000>\
    \ ds;\n  for (auto x : queries) {\n    if (x == -1) {\n      int mx_idx = ds.get_max();\n\
    \      cout << vals[mx_idx] << '\\n';\n      ds.extract(mx_idx);\n    } else {\n\
    \      ds.insert(lower_bound(all(vals), x) - begin(vals));\n    }\n  }\n}"
  dependsOn:
  - datastructures/w_ary_tree.hpp
  isVerificationFile: true
  path: verify/aizu/alds1/priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-08-28 03:43:10-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/priority_queue.test.cpp
- /verify/verify/aizu/alds1/priority_queue.test.cpp.html
title: verify/aizu/alds1/priority_queue.test.cpp
---
