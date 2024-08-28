---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/number_theory.hpp
    title: numeric/number_theory.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include \"../../boilerplate.hpp\"\n#include \"../../../numeric/number_theory.hpp\"\
    \n\nusing namespace number_theory;\n\nint main() {\n  int n, a, b;\n  cin >> n\
    \ >> a >> b;\n  sieve(n);\n  cout << sz(primes) << ' ';\n  vector<int> res;\n\
    \  for (int i = b; i < sz(primes); i += a) {\n    res.push_back(primes[i]);\n\
    \  }\n  cout << sz(res) << '\\n';\n  for (int x : res) {\n    cout << x << ' ';\n\
    \  }\n  cout << '\\n';\n}"
  dependsOn:
  - numeric/number_theory.hpp
  isVerificationFile: true
  path: verify/library_checker/number_theory/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2024-08-28 03:43:10-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number_theory/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp.html
title: verify/library_checker/number_theory/enumerate_primes.test.cpp
---
