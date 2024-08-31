---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/hash_table.hpp
    title: Hash Table
  - icon: ':heavy_check_mark:'
    path: datastructures/mo_queries.hpp
    title: datastructures/mo_queries.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_mode_query
    links:
    - https://judge.yosupo.jp/problem/static_range_mode_query
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/hash_table.hpp\"\
    \n#include \"../../../datastructures/mo_queries.hpp\"\n\nint main() {\n  int n,\
    \ q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++) {\n\
    \    cin >> a[i];\n  }\n  MoQueries<pair<int, int>, 300> mo;\n  while (q--) {\n\
    \    int l, r;\n    cin >> l >> r;\n    mo.insert(l, r - 1);\n  }\n  HashTable<int,\
    \ int> freq;\n  set<pair<int, int>> st;\n  auto add = [&](int p) {\n    if (freq.find(a[p])\
    \ != freq.end()) {\n      st.extract({freq[a[p]], a[p]});\n    }\n    freq[a[p]]++;\n\
    \    st.insert({freq[a[p]], a[p]});\n  };\n  auto del = [&](int p) {\n    if (freq.find(a[p])\
    \ != freq.end()) {\n      st.extract({freq[a[p]], a[p]});\n    }\n    freq[a[p]]--;\n\
    \    st.insert({freq[a[p]], a[p]});\n  };\n  auto query = [&]() {\n    return\
    \ make_pair(rbegin(st)->se, rbegin(st)->fi);\n  };\n  mo.solve(add, del, query);\n\
    \  for (auto [x, y] : mo.res) {\n    cout << x << ' ' << y << '\\n';\n  }\n}"
  dependsOn:
  - datastructures/hash_table.hpp
  - datastructures/mo_queries.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 12:00:19-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_range_mode_query.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_range_mode_query.test.cpp
- /verify/verify/library_checker/data_structure/static_range_mode_query.test.cpp.html
title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
---
