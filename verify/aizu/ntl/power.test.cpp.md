---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: numeric/mint.h
    title: numeric/mint.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/my_random.h
    title: utils/my_random.h
  - icon: ':question:'
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
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\nusing\
    \ ld = long double;\n\ntemplate <class T>\nbool ckmin(T &a, T b) {\n    return\
    \ b < a ? a = b, 1 : 0;\n}\ntemplate <class T>\nbool ckmax(T &a, T b) {\n    return\
    \ b > a ? a = b, 1 : 0;\n}\n#line 2 \"numeric/mint.h\"\n\ntemplate <int MOD>\n\
    struct Mint {\n    int v;\n \n    Mint(ll x = 0) : v(int(-MOD < x && x < MOD ?\
    \ x : x % MOD) + (x < 0) * MOD) {}\n \n    friend Mint pow(Mint base, ll exp)\
    \ {\n        Mint res = 1;\n        while (exp) {\n            if (exp & 1) {\n\
    \                res *= base;\n            }\n            base *= base;\n    \
    \        exp >>= 1;\n        }\n        return res;\n    }\n\n    Mint &operator+=(Mint\
    \ b) {\n        v = v + b.v - (v + b.v >= MOD) * MOD;\n        return *this;\n\
    \    }\n    Mint &operator-=(Mint b) {\n        v = v - b.v + (v < b.v) * MOD;\n\
    \        return *this;\n    }\n    Mint &operator*=(Mint b) {\n        v = int(1ll\
    \ * v * b.v % MOD);\n        return *this;\n    }\n    Mint &operator/=(Mint b)\
    \ {\n        v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n\
    \    }\n    friend Mint operator+(Mint a, Mint b) {\n        return a += b;\n\
    \    }\n    friend Mint operator-(Mint a, Mint b) {\n        return a -= b;\n\
    \    }\n    friend Mint operator*(Mint a, Mint b) {\n        return a *= b;\n\
    \    }\n    friend Mint operator/(Mint a, Mint b) {\n        return a /= b;\n\
    \    }\n    friend ostream &operator<<(ostream &os, Mint a) {\n        return\
    \ os << a.v;\n    }\n};\n\n// using mi = Mint<int(1e9 + 7)>;\n// using mi = Mint<998244353>;\n\
    #line 5 \"verify/aizu/ntl/power.test.cpp\"\n\nusing mi = Mint<1000000007>;\n\n\
    int main() {\n    int m, n;\n    cin >> m >> n;\n    cout << pow(mi(m), n) <<\
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
  timestamp: '2024-10-12 02:07:15-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/ntl/power.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/ntl/power.test.cpp
- /verify/verify/aizu/ntl/power.test.cpp.html
title: verify/aizu/ntl/power.test.cpp
---
