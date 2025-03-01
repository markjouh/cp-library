---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: numeric/mint.h
    title: numeric/mint.h
  - icon: ':x:'
    path: template/template.h
    title: template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"verify/aizu/ntl/power.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#line 1 \"template/template.h\"\n#include <bits/stdc++.h>\n \nusing namespace\
    \ std;\n \n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int\
    \ i = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...)\
    \ arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int\
    \ i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define\
    \ per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n \n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n \n#define pb push_back\n#define eb emplace_back\n\
    #define fi first\n#define se second\n \nusing ll = long long;\nusing pi = pair<int,\
    \ int>;\nusing pl = pair<ll, ll>;\nusing vi = vector<int>;\nusing vl = vector<ll>;\n\
    using vpi = vector<pi>;\nusing vpl = vector<pl>;\n \ntemplate <class T>\nbool\
    \ ckmin(T &a, const T b) {\n    return b < a ? a = b, 1 : 0; \n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, const T b) {\n    return b > a ? a = b, 1 : 0;\n}\n \n\
    template <class T, class U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n\
    \    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi\
    \ -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\ntemplate <class\
    \ T, class U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n\
    \    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo += (lo +\
    \ i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}\n\ntemplate <class T, class\
    \ = void>\nstruct is_range : false_type {};\ntemplate <class T>\nstruct is_range<T,\
    \ void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>> : true_type\
    \ {};\ntemplate <class T>\nusing enable_if_cont = enable_if_t<!is_same<T, string>::value\
    \ && is_range<T>::value, bool>;\n\ntemplate <class T, class U>\nistream &operator>>(istream\
    \ &is, pair<T, U> &p) {\n    is >> p.fi >> p.se;\n    return is;\n}\ntemplate\
    \ <class T, class U>\nostream &operator<<(ostream &os, const pair<T, U> &p) {\n\
    \    os << p.fi << ' ' << p.se;\n    return os;\n}\ntemplate <class T, enable_if_cont<T>\
    \ = true>\nistream &operator>>(istream &is, T &v) {\n    for (auto &x : v) {\n\
    \        is >> x;\n    }\n    return is;\n}\ntemplate <class T, enable_if_cont<T>\
    \ = true>\nostream &operator<<(ostream &os, const T &v) {\n    for (int i = 0;\
    \ i < sz(v); i++) {\n        os << v[i];\n        if (i != sz(v) - 1) {\n    \
    \        os << (is_range<typename T::value_type>::value ? '\\n' : ' ');\n    \
    \    }\n    }\n    return os;\n}\n\ntemplate <class ...T>\nvoid re(T &...a) {\n\
    \    (cin >> ... >> a);\n}\ntemplate <class ...T>\nvoid pr(const T &...a) {\n\
    \    int p = 0;\n    ((cout << a << (++p == sizeof...(T) ? '\\n' : ' ')), ...);\n\
    }\n \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n \n\
    const int INF = 1e9;\nconst ll INFL = 1e18;\n\nvoid solve() {\n}\n\nint32_t main()\
    \ {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\n\
    \    int t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n\
    }\n#line 1 \"numeric/mint.h\"\ntemplate <int MOD>\nstruct mint {\n    int v;\n\
    \ \n    mint(ll x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) *\
    \ MOD) {}\n \n    friend mint pow(mint base, ll exp) {\n        mint res = 1;\n\
    \        while (exp) {\n            if (exp & 1) {\n                res *= base;\n\
    \            }\n            base *= base;\n            exp >>= 1;\n        }\n\
    \        return res;\n    }\n\n    mint &operator+=(mint b) {\n        v = v +\
    \ b.v - (v + b.v >= MOD) * MOD;\n        return *this;\n    }\n    mint &operator-=(mint\
    \ b) {\n        v = v - b.v + (v < b.v) * MOD;\n        return *this;\n    }\n\
    \    mint &operator*=(mint b) {\n        v = int(1ll * v * b.v % MOD);\n     \
    \   return *this;\n    }\n    mint &operator/=(mint b) {\n        v = int(1ll\
    \ * v * pow(b, MOD - 2).v % MOD);\n        return *this;\n    }\n    friend mint\
    \ operator+(mint a, mint b) {\n        return a += b;\n    }\n    friend mint\
    \ operator-(mint a, mint b) {\n        return a -= b;\n    }\n    friend mint\
    \ operator*(mint a, mint b) {\n        return a *= b;\n    }\n    friend mint\
    \ operator/(mint a, mint b) {\n        return a /= b;\n    }\n    friend ostream\
    \ &operator<<(ostream &os, mint a) {\n        return os << a.v;\n    }\n};\n\n\
    // using mi = mint<int(1e9 + 7)>;\n// using mi = mint<998244353>;\n\n// vector<mi>\
    \ fact, inv_fact;\n\n// void gen_fact(int n) {\n//     fact.resize(n + 1);\n//\
    \     inv_fact.resize(n + 1);\n//     fact[0] = fact[1] = inv_fact[0] = inv_fact[1]\
    \ = 1;\n//     for (int i = 2; i <= n; i++) {\n//         fact[i] = fact[i - 1]\
    \ * i;\n//     }\n//     inv_fact[n] = 1 / fact[n];\n//     for (int i = n - 1;\
    \ i >= 2; i--) {\n//         inv_fact[i] = inv_fact[i + 1] * (i + 1);\n//    \
    \ }\n// }\n\n// mi nck(int n, int k) {\n//     if (n < k || k < 0) {\n//     \
    \    return 0;\n//     }\n//     return fact[n] * inv_fact[k] * inv_fact[n - k];\n\
    // }\n#line 5 \"verify/aizu/ntl/power.test.cpp\"\n\nusing mi = mint<1000000007>;\n\
    \nint main() {\n    int m, n;\n    cin >> m >> n;\n    cout << pow(mi(m), n) <<\
    \ '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../numeric/mint.h\"\
    \n\nusing mi = mint<1000000007>;\n\nint main() {\n    int m, n;\n    cin >> m\
    \ >> n;\n    cout << pow(mi(m), n) << '\\n';\n}"
  dependsOn:
  - template/template.h
  - numeric/mint.h
  isVerificationFile: true
  path: verify/aizu/ntl/power.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 17:36:32-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aizu/ntl/power.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/ntl/power.test.cpp
- /verify/verify/aizu/ntl/power.test.cpp.html
title: verify/aizu/ntl/power.test.cpp
---
