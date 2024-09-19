---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: numeric/mod_int.h
    title: numeric/mod_int.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':heavy_check_mark:'
    path: utils/encode.h
    title: utils/encode.h
  - icon: ':heavy_check_mark:'
    path: utils/my_random.h
    title: utils/my_random.h
  - icon: ':heavy_check_mark:'
    path: utils/my_timer.h
    title: utils/my_timer.h
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
    \n\n#line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
    \ b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    #define pb push_back\n#define eb emplace_back\n#define f first\n#define s second\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n    return b <\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n\
    \    return b > a ? a = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n    \
    \    cin.tie(0)->sync_with_stdio(0);\n        cin.exceptions(cin.failbit);\n \
    \       cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 2 \"numeric/mod_int.h\"\
    \n\ntemplate <int MOD>\nstruct ModInt {\n    int v;\n \n    ModInt(ll x = 0) :\
    \ v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n \n    friend\
    \ ModInt pow(ModInt base, int exp) {\n        ModInt res = 1;\n        while (exp)\
    \ {\n            if (exp & 1) {\n                res *= base;\n            }\n\
    \            base *= base;\n            exp >>= 1;\n        }\n        return\
    \ res;\n    }\n \n    ModInt &operator+=(ModInt b) {\n        if ((v += b.v) >=\
    \ MOD) {\n            v -= MOD;\n        }\n        return *this;\n    }\n \n\
    \    ModInt &operator-=(ModInt b) {\n        if ((v -= b.v) < 0) {\n         \
    \   v += MOD;\n        }\n        return *this;\n    }\n \n    ModInt &operator*=(ModInt\
    \ b) {\n        v = int(1ll * v * b.v % MOD);\n        return *this;\n    }\n\
    \ \n    ModInt &operator/=(ModInt b) {\n        v = int(1ll * v * pow(b, MOD -\
    \ 2).v % MOD);\n        return *this;\n    }\n \n    friend ModInt operator+(ModInt\
    \ a, ModInt b) {\n        return a += b;\n    }\n \n    friend ModInt operator-(ModInt\
    \ a, ModInt b) {\n        return a -= b;\n    }\n \n    friend ModInt operator*(ModInt\
    \ a, ModInt b) {\n        return a *= b;\n    }\n \n    friend ModInt operator/(ModInt\
    \ a, ModInt b) {\n        return a /= b;\n    }\n \n    friend ostream &operator<<(ostream\
    \ &os, ModInt a) {\n        return os << a.v;\n    }\n};\n#line 5 \"verify/aizu/ntl/power.test.cpp\"\
    \n\nusing mint = ModInt<1000000007>;\n\nint main() {\n    int m, n;\n    cin >>\
    \ m >> n;\n    cout << pow(mint(m), n) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../numeric/mod_int.h\"\
    \n\nusing mint = ModInt<1000000007>;\n\nint main() {\n    int m, n;\n    cin >>\
    \ m >> n;\n    cout << pow(mint(m), n) << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - numeric/mod_int.h
  isVerificationFile: true
  path: verify/aizu/ntl/power.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/ntl/power.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/ntl/power.test.cpp
- /verify/verify/aizu/ntl/power.test.cpp.html
title: verify/aizu/ntl/power.test.cpp
---
