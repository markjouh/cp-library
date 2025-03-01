---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/sieve_factor.h
    title: numeric/sieve_factor.h
  - icon: ':heavy_check_mark:'
    path: template/template.h
    title: template/template.h
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
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long\
    \ long;\n#line 1 \"numeric/sieve_factor.h\"\n/*\n|           | $\\max_{1 \\leq\
    \ k \\leq n} \\tau(k)$ | $\\pi(n)$ |\n| --------- | --------------------------------\
    \ | -------- |\n| $10^1$    | 4                                | 4        |\n\
    | $10^2$    | 12                               | 25       |\n| $10^3$    | 32\
    \                               | 168      |\n| $10^4$    | 64               \
    \                | 1229     |\n| $10^5$    | 128                             \
    \ | 9592     |\n| $10^6$    | 240                              | 78498    |\n\
    | $10^7$    | 448                              | 664579   |\n| $10^8$    | 768\
    \                              | 5761455  |\n| $10^9$    | 1344              \
    \               | 50847534 |\n| $10^{10}$ | 2304                             |\
    \          |\n| $10^{11}$ | 4032                             |          |\n| $10^{12}$\
    \ | 6720                             |          |\n| $10^{13}$ | 10752       \
    \                     |          |\n| $10^{14}$ | 17280                      \
    \      |          |\n| $10^{15}$ | 26880                            |        \
    \  |\n| $10^{16}$ | 41472                            |          |\n| $10^{17}$\
    \ | 64512                            |          |\n| $10^{18}$ | 103680      \
    \                     |          |\n*/\n\nvector<int> mn_factor, primes;\n\nvoid\
    \ sieve(int n) {\n    mn_factor.resize(n + 1);\n    for (int i = 2; i <= n; i++)\
    \ {\n        if (!mn_factor[i]) {\n            mn_factor[i] = i;\n           \
    \ primes.push_back(i);\n            for (ll j = 1ll * i * i; j <= n; j += i) {\n\
    \                if (!mn_factor[j]) {\n                    mn_factor[j] = i;\n\
    \                }\n            }\n        }\n    }\n}\n\ntemplate <class T>\n\
    auto factorize(T x) {\n    vector<pair<T, int>> res;\n\n    // O(log x) if sieved\
    \ up to x\n    if (x <= sz(mn_factor) - 1) {\n        while (x > 1) {\n      \
    \      int y = mn_factor[x];\n            res.emplace_back(y, 0);\n          \
    \  while (x % y == 0) {\n                x /= y;\n                res.back().second++;\n\
    \            }\n        }\n        return res;\n    }\n\n    // O(sqrt x log x)\
    \ otherwise, must have sieved to sqrt(x)\n    for (int p : primes) {\n       \
    \ if (1ll * p * p > x) {\n            break;\n        }\n        int exp = 0;\n\
    \        while (x % p == 0) {\n            x /= p;\n            exp++;\n     \
    \   }\n        if (exp) {\n            res.emplace_back(p, exp);\n        }\n\
    \    }\n    if (x > 1) {\n        res.emplace_back(x, 1);\n    }\n    return res;\n\
    }\n\ntemplate <class T>\nauto gen_divisors(T x) {\n    vector<T> res = {1};\n\
    \    for (auto [p, exp] : factorize(x)) {\n        const int old_size = sz(res);\n\
    \        T coeff = 1;\n        for (int i = 0; i < exp; i++) {\n            coeff\
    \ *= p;\n            for (int j = 0; j < old_size; j++) {\n                res.push_back(coeff\
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
  - numeric/sieve_factor.h
  isVerificationFile: true
  path: verify/library_checker/number_theory/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 17:42:52-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number_theory/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp.html
title: verify/library_checker/number_theory/enumerate_primes.test.cpp
---
