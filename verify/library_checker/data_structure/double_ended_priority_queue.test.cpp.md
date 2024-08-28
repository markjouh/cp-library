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
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/w_ary_tree.hpp\"\
    \n\nconst int LO = numeric_limits<int>::min(), HI = numeric_limits<int>::max();\n\
    const int N = 1 << 18;\n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int>\
    \ queries, vals;\n  for (int i = 0; i < n; i++) {\n    int x;\n    cin >> x;\n\
    \    queries.push_back(x);\n    vals.push_back(x);\n  }\n  for (int i = 0; i <\
    \ q; i++) {\n    int t;\n    cin >> t;\n    if (t == 0) {\n      int x;\n    \
    \  cin >> x;\n      queries.push_back(x);\n      vals.push_back(x);\n    } else\
    \ if (t == 1) {\n      queries.push_back(LO);\n    } else {\n      queries.push_back(HI);\n\
    \    }\n  }\n  sort(all(vals));\n  vals.resize(unique(all(vals)) - begin(vals));\n\
    \n  array<int, 3> cnt{};\n  array<WAryTree<1 << 18>, 3> ds;\n  for (int x : queries)\
    \ {\n    if (x == LO) {\n      for (int i = 0; i < 3; i++) {\n        if (cnt[i]\
    \ > 0) {\n          int rem = ds[i].get_min();\n          cout << vals[i * N +\
    \ rem] << '\\n';\n          ds[i].extract(rem);\n          cnt[i]--;\n       \
    \   break;\n        }\n      }\n    } else if (x == HI) {\n      for (int i =\
    \ 2; i >= 0; i--) {\n        if (cnt[i] > 0) {\n          int rem = ds[i].get_max();\n\
    \          cout << vals[i * N + rem] << '\\n';\n          ds[i].extract(rem);\n\
    \          cnt[i]--;\n          break;\n        }\n      }\n    } else {\n   \
    \   int idx = lower_bound(all(vals), x) - begin(vals);\n      ds[idx / N].insert(idx\
    \ % N);\n      cnt[idx / N]++;\n    }\n  }\n}"
  dependsOn:
  - datastructures/w_ary_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-08-28 03:43:10-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
- /verify/verify/library_checker/data_structure/double_ended_priority_queue.test.cpp.html
title: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
---
