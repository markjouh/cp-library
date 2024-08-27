---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/binary_search.hpp
    title: numeric/binary_search.hpp
  - icon: ':heavy_check_mark:'
    path: strings/hashing.hpp
    title: strings/hashing.hpp
  - icon: ':heavy_check_mark:'
    path: verify/boilerplate.hpp
    title: verify/boilerplate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../numeric/binary_search.hpp\"\
    \n#include \"../../../strings/hashing.hpp\"\n\nusing namespace hashing;\n\nint\
    \ main() {\n    string s;\n    cin >> s;\n    string rev = s;\n    reverse(all(rev));\n\
    \    str_hash a(s), b(rev);\n    const int n = sz(s);\n    vector<int> ans(2 *\
    \ n - 1);\n    for (int i = 0; i < n; i++) {\n        ans[2 * i] = 2 * bsmax(0,\
    \ min(i, n - i - 1), [&](int d) {\n            return a.get(i - d, i) == b.get(n\
    \ - i - 1 - d, n - i - 1);\n        }) + 1;\n    }\n    for (int i = 0; i < n\
    \ - 1; i++) {\n        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int\
    \ d) {\n            return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);\n\
    \        }) + 2;\n    }\n    for (int i = 0; i < 2 * n - 1; i++) {\n        cout\
    \ << ans[i] << ' ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - verify/boilerplate.hpp
  - numeric/binary_search.hpp
  - strings/hashing.hpp
  isVerificationFile: true
  path: verify/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-08-26 22:51:38-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---
