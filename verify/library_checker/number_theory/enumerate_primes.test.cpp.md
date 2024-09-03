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
  bundledCode: "#line 1 \"verify/library_checker/number_theory/enumerate_primes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#line\
    \ 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n#include\
    \ <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing namespace\
    \ std;\n\n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i\
    \ = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...)\
    \ arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int\
    \ i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define\
    \ per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n#define eb emplace_back\n\
    #define fi first\n#define se second\n\nusing ll = long long;\nusing pii = pair<int,\
    \ int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n\
    \  return __lg(x);\n#else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n \
    \ }\n  return res;\n#endif\n}\n\ntemplate <class T>\nbool ckmin(T &a, const T\
    \ &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T =\
    \ int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\nstruct InitIO\
    \ {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"numeric/number_theory.hpp\"\
    \n\nvector<int> mn_fac, primes;\n\nvoid sieve(int n) {\n  mn_fac.resize(n + 1);\n\
    \  for (int i = 2; i <= n; i++) {\n    if (!mn_fac[i]) {\n      mn_fac[i] = i;\n\
    \      primes.push_back(i);\n      for (ll j = 1ll * i * i; j <= n; j += i) {\n\
    \        if (!mn_fac[j]) {\n          mn_fac[j] = i;\n        }\n      }\n   \
    \ }\n  }\n}\n\ntemplate<class T> vector<pair<T, int>> factor(T num) {\n  vector<pair<T,\
    \ int>> res;\n\n  if (num <= sz(mn_fac) - 1) {\n    while (num > 1) {\n      int\
    \ fac = mn_fac[num];\n      res.emplace_back(fac, 0);\n      while (num % fac\
    \ == 0) {\n        num /= fac;\n        res.back().second++;\n      }\n    }\n\
    \    return res;\n  }\n\n  for (int p : primes) {\n    if (1ll * p * p > num)\
    \ {\n      break;\n    }\n    int exp = 0;\n    while (num % p == 0) {\n     \
    \ num /= p;\n      exp++;\n    }\n    if (exp) {\n      res.emplace_back(p, exp);\n\
    \    }\n  }\n  if (num > 1) {\n    res.emplace_back(num, 1);\n  }\n  return res;\n\
    }\n\ntemplate<class T> vector<T> gen_divisors(vector<pair<T, int>> facs) {\n \
    \ vector<T> res = {1};\n  for (auto [p, exp] : facs) {\n    const int prev_layer\
    \ = sz(res);\n    T coeff = 1;\n    for (int i = 0; i < exp; i++) {\n      coeff\
    \ *= p;\n      for (int j = 0; j < prev_layer; j++) {\n        res.push_back(coeff\
    \ * res[j]);\n      }\n    }\n  }\n  return res;\n}\n#line 5 \"verify/library_checker/number_theory/enumerate_primes.test.cpp\"\
    \n\nint main() {\n  int n, a, b;\n  cin >> n >> a >> b;\n  sieve(n);\n  cout <<\
    \ sz(primes) << ' ';\n  vector<int> res;\n  for (int i = b; i < sz(primes); i\
    \ += a) {\n    res.push_back(primes[i]);\n  }\n  cout << sz(res) << '\\n';\n \
    \ for (int x : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include \"../../boilerplate.hpp\"\n#include \"../../../numeric/number_theory.hpp\"\
    \n\nint main() {\n  int n, a, b;\n  cin >> n >> a >> b;\n  sieve(n);\n  cout <<\
    \ sz(primes) << ' ';\n  vector<int> res;\n  for (int i = b; i < sz(primes); i\
    \ += a) {\n    res.push_back(primes[i]);\n  }\n  cout << sz(res) << '\\n';\n \
    \ for (int x : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n}"
  dependsOn:
  - numeric/number_theory.hpp
  isVerificationFile: true
  path: verify/library_checker/number_theory/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2024-09-03 12:19:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number_theory/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp.html
title: verify/library_checker/number_theory/enumerate_primes.test.cpp
---
