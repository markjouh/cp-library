---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/mod_int.hpp
    title: numeric/mod_int.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"verify/aizu/ntl/power.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#line 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing\
    \ namespace std;\n\n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r)\
    \ for (int i = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define\
    \ rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l,\
    \ r) for (int i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0,\
    \ n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class\
    \ T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n#else\n  int\
    \ res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n}\n\n\
    template <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1\
    \ : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return b >\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"numeric/mod_int.hpp\"\n\ntemplate <int MOD>\nstruct ModInt\
    \ {\n  int v;\n \n  ModInt(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD)\
    \ + (x < 0) * MOD) {}\n \n  friend ModInt pow(ModInt base, int exp) {\n    ModInt\
    \ res = 1;\n    while (exp) {\n      if (exp & 1) {\n        res *= base;\n  \
    \    }\n      base *= base;\n      exp >>= 1;\n    }\n    return res;\n  }\n \n\
    \  ModInt &operator+=(ModInt b) {\n    if ((v += b.v) >= MOD) {\n      v -= MOD;\n\
    \    }\n    return *this;\n  }\n \n  ModInt &operator-=(ModInt b) {\n    if ((v\
    \ -= b.v) < 0) {\n      v += MOD;\n    }\n    return *this;\n  }\n \n  ModInt\
    \ &operator*=(ModInt b) {\n    v = int(1ll * v * b.v % MOD);\n    return *this;\n\
    \  }\n \n  ModInt &operator/=(ModInt b) {\n    v = int(1ll * v * pow(b, MOD -\
    \ 2).v % MOD);\n    return *this;\n  }\n \n  friend ModInt operator+(ModInt a,\
    \ ModInt b) {\n    return a += b;\n  }\n \n  friend ModInt operator-(ModInt a,\
    \ ModInt b) {\n    return a -= b;\n  }\n \n  friend ModInt operator*(ModInt a,\
    \ ModInt b) {\n    return a *= b;\n  }\n \n  friend ModInt operator/(ModInt a,\
    \ ModInt b) {\n    return a /= b;\n  }\n \n  friend ostream &operator<<(ostream\
    \ &os, ModInt a) {\n    return os << a.v;\n  }\n};\n#line 5 \"verify/aizu/ntl/power.test.cpp\"\
    \n\nusing mint = ModInt<1000000007>;\n\nint main() {\n  int m, n;\n  cin >> m\
    \ >> n;\n  cout << pow(mint(m), n) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../numeric/mod_int.hpp\"\
    \n\nusing mint = ModInt<1000000007>;\n\nint main() {\n  int m, n;\n  cin >> m\
    \ >> n;\n  cout << pow(mint(m), n) << '\\n';\n}"
  dependsOn:
  - numeric/mod_int.hpp
  isVerificationFile: true
  path: verify/aizu/ntl/power.test.cpp
  requiredBy: []
  timestamp: '2024-09-03 12:19:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/ntl/power.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/ntl/power.test.cpp
- /verify/verify/aizu/ntl/power.test.cpp.html
title: verify/aizu/ntl/power.test.cpp
---
