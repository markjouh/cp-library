---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/numeric/mint.h
    title: Modular Integer (Mint)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"src/verify/library_checker/convolution_mod.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 1 \"src/numeric/mint.h\"\ntemplate\
    \ <int MOD>\nstruct Mint {\n  int v;\n\n  Mint(int64_t x = 0) : v(int(-MOD < x\
    \ && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n \n  friend Mint pow(Mint base,\
    \ int64_t exp) {\n    Mint res = 1;\n    while (exp) {\n      if (exp & 1) {\n\
    \        res *= base;\n      }\n      base *= base;\n      exp >>= 1;\n    }\n\
    \    return res;\n  }\n\n  Mint &operator+=(Mint b) {\n    v = v + b.v - (v +\
    \ b.v >= MOD) * MOD;\n    return *this;\n  }\n  Mint &operator-=(Mint b) {\n \
    \   v = v - b.v + (v < b.v) * MOD;\n    return *this;\n  }\n  Mint &operator*=(Mint\
    \ b) {\n    v = int(1ll * v * b.v % MOD);\n    return *this;\n  }\n  Mint &operator/=(Mint\
    \ b) {\n    v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n    return *this;\n \
    \ }\n  friend Mint operator+(Mint a, Mint b) {\n    return a += b;\n  }\n  friend\
    \ Mint operator-(Mint a, Mint b) {\n    return a -= b;\n  }\n  friend Mint operator*(Mint\
    \ a, Mint b) {\n    return a *= b;\n  }\n  friend Mint operator/(Mint a, Mint\
    \ b) {\n    return a /= b;\n  }\n  friend ostream &operator<<(ostream &os, Mint\
    \ a) {\n    return os << a.v;\n  }\n};\n\n// using mi = Mint<int(1e9 + 7)>;\n\
    // using mi = Mint<998244353>;\n\n// vector<mi> fact, inv_fact;\n\n// void gen_fact(int\
    \ n) {\n//   fact.resize(n + 1);\n//   inv_fact.resize(n + 1);\n//   fact[0] =\
    \ fact[1] = inv_fact[0] = inv_fact[1] = 1;\n//   for (int i = 2; i <= n; i++)\
    \ {\n//     fact[i] = fact[i - 1] * i;\n//   }\n//   inv_fact[n] = 1 / fact[n];\n\
    //   for (int i = n - 1; i >= 2; i--) {\n//     inv_fact[i] = inv_fact[i + 1]\
    \ * (i + 1);\n//   }\n// }\n\n// mi nck(int n, int k) {\n//   if (n < k || k <\
    \ 0) {\n//     return 0;\n//   }\n//   return fact[n] * inv_fact[k] * inv_fact[n\
    \ - k];\n// }\n#line 7 \"src/verify/library_checker/convolution_mod.test.cpp\"\
    \n\nusing mi = Mint<998244353>;\n\nconst int MOD = 998244353;\n\nvector<mi> convolution(vector<mi>\
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
    \ \n  return 0;\n}\n"
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
  dependsOn:
  - src/numeric/mint.h
  isVerificationFile: true
  path: src/verify/library_checker/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 19:14:12-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/convolution_mod.test.cpp
- /verify/src/verify/library_checker/convolution_mod.test.cpp.html
title: src/verify/library_checker/convolution_mod.test.cpp
---
