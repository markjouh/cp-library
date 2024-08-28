---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/hash_table.hpp
    title: Hash Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/hash_table.hpp\"\
    \n\nint main() {\n  int q;\n  cin >> q;\n  HashTable<ll, ll> mp;\n  while (q--)\
    \ {\n    bool t;\n    ll k;\n    cin >> t >> k;\n    if (t) {\n      cout << mp[k]\
    \ << '\\n';\n    } else {\n      ll v;\n      cin >> v;\n      mp[k] = v;\n  \
    \  }\n  }\n}"
  dependsOn:
  - datastructures/hash_table.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/associative_array.test.cpp
  requiredBy: []
  timestamp: '2024-08-28 02:47:08-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/associative_array.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/associative_array.test.cpp
- /verify/verify/library_checker/data_structure/associative_array.test.cpp.html
title: verify/library_checker/data_structure/associative_array.test.cpp
---
