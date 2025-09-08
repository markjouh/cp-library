---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../numeric/mint.h:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"../../numeric/mint.h\"\n\
    \nusing mi = Mint<998244353>;\n\nconst int MOD = 998244353;\n\nvector<mi> convolution(vector<mi>\
    \ a, vector<mi> b) {\n  int n = a.size() + b.size() - 1;\n  int size = 1;\n  while\
    \ (size < n) size <<= 1;\n  \n  a.resize(size);\n  b.resize(size);\n  \n  auto\
    \ ntt = [&](vector<mi>& f, bool inv) {\n    int n = f.size();\n    if (n == 1)\
    \ return;\n    \n    mi g = pow(mi(3), (MOD - 1) / n);\n    if (inv) g = mi(1)\
    \ / g;\n    \n    for (int i = 1, j = 0; i < n; i++) {\n      int bit = n >> 1;\n\
    \      for (; j & bit; bit >>= 1) {\n        j ^= bit;\n      }\n      j ^= bit;\n\
    \      if (i < j) swap(f[i], f[j]);\n    }\n    \n    for (int len = 2; len <=\
    \ n; len <<= 1) {\n      mi w = pow(g, n / len);\n      for (int i = 0; i < n;\
    \ i += len) {\n        mi wn = 1;\n        for (int j = 0; j < len / 2; j++) {\n\
    \          mi u = f[i + j];\n          mi v = f[i + j + len / 2] * wn;\n     \
    \     f[i + j] = u + v;\n          f[i + j + len / 2] = u - v;\n          wn *=\
    \ w;\n        }\n      }\n    }\n    \n    if (inv) {\n      mi n_inv = mi(1)\
    \ / mi(n);\n      for (auto& x : f) x *= n_inv;\n    }\n  };\n  \n  ntt(a, false);\n\
    \  ntt(b, false);\n  \n  for (int i = 0; i < size; i++) {\n    a[i] *= b[i];\n\
    \  }\n  \n  ntt(a, true);\n  \n  a.resize(n);\n  return a;\n}\n\nint main() {\n\
    \  ios_base::sync_with_stdio(false);\n  cin.tie(nullptr);\n  \n  int n, m;\n \
    \ cin >> n >> m;\n  \n  vector<mi> a(n), b(m);\n  for (int i = 0; i < n; i++)\
    \ {\n    int x;\n    cin >> x;\n    a[i] = x;\n  }\n  \n  for (int i = 0; i <\
    \ m; i++) {\n    int x;\n    cin >> x;\n    b[i] = x;\n  }\n  \n  vector<mi> c\
    \ = convolution(a, b);\n  \n  for (int i = 0; i < n + m - 1; i++) {\n    cout\
    \ << c[i];\n    if (i < n + m - 2) cout << \" \";\n  }\n  cout << \"\\n\";\n \
    \ \n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: src/verify/library_checker/convolution/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: src/verify/library_checker/convolution/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/convolution/convolution_mod.test.cpp
- /verify/src/verify/library_checker/convolution/convolution_mod.test.cpp.html
title: src/verify/library_checker/convolution/convolution_mod.test.cpp
---
