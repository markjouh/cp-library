---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: numeric/sieve_factor.h
    title: numeric/sieve_factor.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"verify/library_checker/number_theory/enumerate_primes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#line\
    \ 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    #ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate\
    \ <class T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line\
    \ 1 \"numeric/sieve_factor.h\"\nvector<int> mn_factor, primes;\n\nvoid sieve(int\
    \ n) {\n    mn_factor.resize(n + 1);\n    for (int i = 2; i <= n; i++) {\n   \
    \     if (!mn_factor[i]) {\n            mn_factor[i] = i;\n            primes.push_back(i);\n\
    \            for (ll j = 1ll * i * i; j <= n; j += i) {\n                if (!mn_factor[j])\
    \ {\n                    mn_factor[j] = i;\n                }\n            }\n\
    \        }\n    }\n}\n\ntemplate <class T>\nauto factorize(T x) {\n    vector<pair<T,\
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
    #include \"../../../misc/template.h\"\n#include \"../../../numeric/sieve_factor.h\"\
    \n\nint main() {\n    int n, a, b;\n    cin >> n >> a >> b;\n    sieve(n);\n \
    \   cout << sz(primes) << ' ';\n    vector<int> res;\n    for (int i = b; i <\
    \ sz(primes); i += a) {\n        res.push_back(primes[i]);\n    }\n    cout <<\
    \ sz(res) << '\\n';\n    for (int x : res) {\n        cout << x << ' ';\n    }\n\
    \    cout << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - numeric/sieve_factor.h
  isVerificationFile: true
  path: verify/library_checker/number_theory/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 20:01:05-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/number_theory/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp.html
title: verify/library_checker/number_theory/enumerate_primes.test.cpp
---
