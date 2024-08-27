---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: datastructures/w_ary_tree.hpp
    title: datastructures/w_ary_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ verify/boilerplate.hpp: line 21: unable to process #include in #if / #ifdef\
    \ / #ifndef other than include guards\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/w_ary_tree.hpp\"\
    \n\nconst int lo = numeric_limits<int>::min(), hi = numeric_limits<int>::max();\n\
    \nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> queries, vals;\n\
    \    for (int i = 0; i < n; i++) {\n        int x;\n        cin >> x;\n      \
    \  queries.push_back(x);\n        vals.push_back(x);\n    }\n    for (int i =\
    \ 0; i < q; i++) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n\
    \            int x;\n            cin >> x;\n            queries.push_back(x);\n\
    \            vals.push_back(x);\n        } else if (t == 1) {\n            queries.push_back(lo);\n\
    \        } else {\n            queries.push_back(hi);\n        }\n    }\n    sort(all(vals));\n\
    \    vals.resize(unique(all(vals)) - begin(vals));\n    w_ary_tree<20000000> ds;\n\
    \    for (int x : queries) {\n        if (x == lo) {\n            int rem = ds.get_min();\n\
    \            cout << vals[rem] << '\\n';\n            ds.extract(rem);\n     \
    \   } else if (x == hi) {\n            int rem = ds.get_max();\n            cout\
    \ << vals[rem] << '\\n';\n            ds.extract(rem);\n        } else {\n   \
    \         ds.insert(lower_bound(all(vals), x) - begin(vals));\n        }\n   \
    \ }\n}"
  dependsOn:
  - datastructures/w_ary_tree.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-08-26 23:16:44-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
- /verify/verify/library_checker/data_structure/double_ended_priority_queue.test.cpp.html
title: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
---
