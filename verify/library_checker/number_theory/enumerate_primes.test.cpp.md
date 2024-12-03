---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/sieve_factor.h
    title: numeric/sieve_factor.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  - icon: ':question:'
    path: utils/bits/stdc++.h
    title: utils/bits/stdc++.h
  - icon: ':question:'
    path: utils/compat.h
    title: utils/compat.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/random.h
    title: utils/random.h
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
    \ 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
    \ b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    \n#define pb push_back\n#define eb emplace_back\n#define fi first\n#define se\
    \ second\n\nusing ll = long long;\nusing ld = long double;\nusing pi = pair<int,\
    \ int>;\nusing pl = pair<ll, ll>;\n\ntemplate <class T> using vec = vector<T>;\n\
    using vb = vec<bool>;\nusing vi = vec<int>; \nusing vl = vec<ll>;\nusing vd =\
    \ vec<ld>;\nusing vs = vec<string>;\nusing vpi = vec<pi>;\nusing vpl = vec<pl>;\n\
    \ntemplate <class T, size_t N> using arr = array<T, N>;\ntemplate <size_t N> using\
    \ ai = array<int, N>;\ntemplate <size_t N> using al = array<ll, N>;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0; \n}\ntemplate\
    \ <class T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\n\
    template <class T, class U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n\
    \    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi\
    \ -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\ntemplate <class\
    \ T, class U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n\
    \    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo += (lo +\
    \ i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}\n\nconst int INF = 1e9;\n\
    const ll INFL = 1e18;\n\n// void solve() {\n// }\n\n// int32_t main() {\n//  \
    \   cin.tie(0)->sync_with_stdio(0);\n//     cin.exceptions(cin.failbit);\n\n//\
    \     int t = 1;\n//     // cin >> t;\n//     while (t--) {\n//         solve();\n\
    //     }\n\n//     return 0;\n// }\n#line 1 \"numeric/sieve_factor.h\"\n/*\n|\
    \           | $\\max_{1 \\leq k \\leq n} \\tau(k)$ | $\\pi(n)$ |\n| ---------\
    \ | -------------------------------- | -------- |\n| $10^1$    | 4           \
    \                     | 4        |\n| $10^2$    | 12                         \
    \      | 25       |\n| $10^3$    | 32                               | 168    \
    \  |\n| $10^4$    | 64                               | 1229     |\n| $10^5$  \
    \  | 128                              | 9592     |\n| $10^6$    | 240        \
    \                      | 78498    |\n| $10^7$    | 448                       \
    \       | 664579   |\n| $10^8$    | 768                              | 5761455\
    \  |\n| $10^9$    | 1344                             | 50847534 |\n| $10^{10}$\
    \ | 2304                             |          |\n| $10^{11}$ | 4032        \
    \                     |          |\n| $10^{12}$ | 6720                       \
    \      |          |\n| $10^{13}$ | 10752                            |        \
    \  |\n| $10^{14}$ | 17280                            |          |\n| $10^{15}$\
    \ | 26880                            |          |\n| $10^{16}$ | 41472       \
    \                     |          |\n| $10^{17}$ | 64512                      \
    \      |          |\n| $10^{18}$ | 103680                           |        \
    \  |\n*/\n\nvector<int> mn_factor, primes;\n\nvoid sieve(int n) {\n    mn_factor.resize(n\
    \ + 1);\n    for (int i = 2; i <= n; i++) {\n        if (!mn_factor[i]) {\n  \
    \          mn_factor[i] = i;\n            primes.push_back(i);\n            for\
    \ (ll j = 1ll * i * i; j <= n; j += i) {\n                if (!mn_factor[j]) {\n\
    \                    mn_factor[j] = i;\n                }\n            }\n   \
    \     }\n    }\n}\n\ntemplate <class T>\nauto factorize(T x) {\n    vector<pair<T,\
    \ int>> res;\n\n    // O(log x) if sieved up to x\n    if (x <= sz(mn_factor)\
    \ - 1) {\n        while (x > 1) {\n            int y = mn_factor[x];\n       \
    \     res.emplace_back(y, 0);\n            while (x % y == 0) {\n            \
    \    x /= y;\n                res.back().second++;\n            }\n        }\n\
    \        return res;\n    }\n\n    // O(sqrt x log x) otherwise, must have sieved\
    \ to sqrt(x)\n    for (int p : primes) {\n        if (1ll * p * p > x) {\n   \
    \         break;\n        }\n        int exp = 0;\n        while (x % p == 0)\
    \ {\n            x /= p;\n            exp++;\n        }\n        if (exp) {\n\
    \            res.emplace_back(p, exp);\n        }\n    }\n    if (x > 1) {\n \
    \       res.emplace_back(x, 1);\n    }\n    return res;\n}\n\ntemplate <class\
    \ T>\nauto gen_divisors(T x) {\n    vector<T> res = {1};\n    for (auto [p, exp]\
    \ : factorize(x)) {\n        const int old_size = sz(res);\n        T coeff =\
    \ 1;\n        for (int i = 0; i < exp; i++) {\n            coeff *= p;\n     \
    \       for (int j = 0; j < old_size; j++) {\n                res.push_back(coeff\
    \ * res[j]);\n            }\n        }\n    }\n    return res;\n}\n#line 5 \"\
    verify/library_checker/number_theory/enumerate_primes.test.cpp\"\n\nint main()\
    \ {\n    int n, a, b;\n    cin >> n >> a >> b;\n    sieve(n);\n    cout << sz(primes)\
    \ << ' ';\n    vector<int> res;\n    for (int i = b; i < sz(primes); i += a) {\n\
    \        res.push_back(primes[i]);\n    }\n    cout << sz(res) << '\\n';\n   \
    \ for (int x : res) {\n        cout << x << ' ';\n    }\n    cout << '\\n';\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include \"../../../template/template.h\"\n#include \"../../../numeric/sieve_factor.h\"\
    \n\nint main() {\n    int n, a, b;\n    cin >> n >> a >> b;\n    sieve(n);\n \
    \   cout << sz(primes) << ' ';\n    vector<int> res;\n    for (int i = b; i <\
    \ sz(primes); i += a) {\n        res.push_back(primes[i]);\n    }\n    cout <<\
    \ sz(res) << '\\n';\n    for (int x : res) {\n        cout << x << ' ';\n    }\n\
    \    cout << '\\n';\n}"
  dependsOn:
  - template/template.h
  - utils/bits/stdc++.h
  - utils/compat.h
  - utils/debug.h
  - utils/random.h
  - numeric/sieve_factor.h
  isVerificationFile: true
  path: verify/library_checker/number_theory/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number_theory/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp.html
title: verify/library_checker/number_theory/enumerate_primes.test.cpp
---
