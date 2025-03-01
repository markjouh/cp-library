---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/binsearch.h
    title: numeric/binsearch.h
  - icon: ':heavy_check_mark:'
    path: strings/hashing.h
    title: strings/hashing.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n\
    #line 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long\
    \ long;\n#line 1 \"numeric/binsearch.h\"\ntemplate <class T, class U>\nT bsmin(T\
    \ lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i)) * i;\n \
    \   }\n    return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U\
    \ f) {\n    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi - lo);\
    \ i > 0; i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n    }\n \
    \   return lo;\n}\n#line 1 \"strings/hashing.h\"\nmt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst ll MOD = (1ll << 61) - 1;\nconst ll B = uniform_int_distribution<ll>(0,\
    \ MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nstruct hash_val {\n    ll val;\n  \
    \  int len;\n\n    hash_val(ll x, int y) : val(x), len(y) {}\n\n    hash_val operator+(hash_val\
    \ b) {\n        return hash_val((__int128_t(val) * pow_b[b.len] + b.val) % MOD,\
    \ len + b.len);\n    }\n\n    friend bool operator==(const hash_val a, const hash_val\
    \ b) {\n        return a.val == b.val && a.len == b.len;\n    }\n};\n\nstruct\
    \ hash_string {\n    int len;\n    vector<ll> h;\n\n    template <class T>\n \
    \   hash_string(const T &s) : len(sz(s)), h(len + 1) {\n        for (int i = 0;\
    \ i < len; i++) {\n            h[i + 1] = (__int128_t(h[i]) * B + s[i]) % MOD;\n\
    \        }\n        while (sz(pow_b) <= len) {\n            pow_b.push_back(__int128_t(pow_b.back())\
    \ * B % MOD);\n        }\n    }\n\n    hash_val get(int l, int r) {\n        assert(l\
    \ < ++r);\n        return hash_val(((h[r] - __int128_t(h[l]) * pow_b[r - l]) %\
    \ MOD + MOD) % MOD, r - l);\n    }\n\n    hash_val get() {\n        return get(0,\
    \ sz(h) - 2);\n    }\n};\n#line 6 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n\nint main() {\n    string s;\n    cin >> s;\n    string rev = s;\n    reverse(all(rev));\n\
    \    hash_string a(s), b(rev);\n    const int n = sz(s);\n    vector<int> ans(2\
    \ * n - 1);\n    for (int i = 0; i < n; i++) {\n        ans[2 * i] = 2 * bsmax(0,\
    \ min(i, n - i - 1), [&](int d) {\n            return a.get(i - d, i) == b.get(n\
    \ - i - 1 - d, n - i - 1);\n        }) + 1;\n    }\n    for (int i = 0; i < n\
    \ - 1; i++) {\n        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int\
    \ d) {\n            return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);\n\
    \        }) + 2;\n    }\n    for (int i = 0; i < 2 * n - 1; i++) {\n        cout\
    \ << ans[i] << ' ';\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../numeric/binsearch.h\"\
    \n#include \"../../../strings/hashing.h\"\n\nint main() {\n    string s;\n   \
    \ cin >> s;\n    string rev = s;\n    reverse(all(rev));\n    hash_string a(s),\
    \ b(rev);\n    const int n = sz(s);\n    vector<int> ans(2 * n - 1);\n    for\
    \ (int i = 0; i < n; i++) {\n        ans[2 * i] = 2 * bsmax(0, min(i, n - i -\
    \ 1), [&](int d) {\n            return a.get(i - d, i) == b.get(n - i - 1 - d,\
    \ n - i - 1);\n        }) + 1;\n    }\n    for (int i = 0; i < n - 1; i++) {\n\
    \        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int d) {\n     \
    \       return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);\n        })\
    \ + 2;\n    }\n    for (int i = 0; i < 2 * n - 1; i++) {\n        cout << ans[i]\
    \ << ' ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - template/template.h
  - numeric/binsearch.h
  - strings/hashing.h
  isVerificationFile: true
  path: verify/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 17:42:52-08:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---
