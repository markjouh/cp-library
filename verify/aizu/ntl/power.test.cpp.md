---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: numeric/mint.h
    title: numeric/mint.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
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
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate\
    \ <class T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line\
    \ 1 \"numeric/mint.h\"\ntemplate <int MOD>\nstruct Mint {\n    int v;\n \n   \
    \ Mint(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n\
    \ \n    friend Mint pow(Mint base, ll exp) {\n        Mint res = 1;\n        while\
    \ (exp) {\n            if (exp & 1) {\n                res *= base;\n        \
    \    }\n            base *= base;\n            exp >>= 1;\n        }\n       \
    \ return res;\n    }\n\n    Mint &operator+=(Mint b) {\n        v = v + b.v -\
    \ (v + b.v >= MOD) * MOD;\n        return *this;\n    }\n    Mint &operator-=(Mint\
    \ b) {\n        v = v - b.v + (v < b.v) * MOD;\n        return *this;\n    }\n\
    \    Mint &operator*=(Mint b) {\n        v = int(1ll * v * b.v % MOD);\n     \
    \   return *this;\n    }\n    Mint &operator/=(Mint b) {\n        v = int(1ll\
    \ * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n    }\n    friend Mint\
    \ operator+(Mint a, Mint b) {\n        return a += b;\n    }\n    friend Mint\
    \ operator-(Mint a, Mint b) {\n        return a -= b;\n    }\n    friend Mint\
    \ operator*(Mint a, Mint b) {\n        return a *= b;\n    }\n    friend Mint\
    \ operator/(Mint a, Mint b) {\n        return a /= b;\n    }\n    friend ostream\
    \ &operator<<(ostream &os, Mint a) {\n        return os << a.v;\n    }\n};\n\n\
    // using mi = Mint<int(1e9 + 7)>;\n// using mi = Mint<998244353>;\n\n// vector<mi>\
    \ fact, inv_fact;\n\n// void gen_fact(int n) {\n//     fact.resize(n + 1);\n//\
    \     inv_fact.resize(n + 1);\n//     fact[0] = fact[1] = inv_fact[0] = inv_fact[1]\
    \ = 1;\n//     for (int i = 2; i <= n; i++) {\n//         fact[i] = fact[i - 1]\
    \ * i;\n//     }\n//     inv_fact[n] = 1 / fact[n];\n//     for (int i = n - 1;\
    \ i >= 2; i--) {\n//         inv_fact[i] = inv_fact[i + 1] * (i + 1);\n//    \
    \ }\n// }\n\n// mi nck(int n, int k) {\n//     if (n < k || k < 0) {\n//     \
    \    return 0;\n//     }\n//     return fact[n] * inv_fact[k] * inv_fact[n - k];\n\
    // }\n#line 5 \"verify/aizu/ntl/power.test.cpp\"\n\nusing mi = Mint<1000000007>;\n\
    \nint main() {\n    int m, n;\n    cin >> m >> n;\n    cout << pow(mi(m), n) <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../numeric/mint.h\"\
    \n\nusing mi = Mint<1000000007>;\n\nint main() {\n    int m, n;\n    cin >> m\
    \ >> n;\n    cout << pow(mi(m), n) << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - numeric/mint.h
  isVerificationFile: true
  path: verify/aizu/ntl/power.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 20:01:05-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/ntl/power.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/ntl/power.test.cpp
- /verify/verify/aizu/ntl/power.test.cpp.html
title: verify/aizu/ntl/power.test.cpp
---
