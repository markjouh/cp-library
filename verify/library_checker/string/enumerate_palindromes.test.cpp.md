---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: common/binsearch.h
    title: common/binsearch.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: strings/hashing.h
    title: strings/hashing.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/encode.h
    title: utils/encode.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n\
    #line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\nusing\
    \ ld = long double;\n\ntemplate <class T>\nbool ckmin(T &a, T b) {\n    return\
    \ b < a ? a = b, 1 : 0;\n}\ntemplate <class T>\nbool ckmax(T &a, T b) {\n    return\
    \ b > a ? a = b, 1 : 0;\n}\n#line 2 \"common/binsearch.h\"\n\ntemplate <class\
    \ T, class U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n\
    \    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi -= (hi -\
    \ i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\n\ntemplate <class T, class\
    \ U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n    for (T\
    \ i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo += (lo + i <= hi &&\
    \ f(lo + i)) * i;\n    }\n    return lo;\n}\n#line 2 \"strings/hashing.h\"\n\n\
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());\n\nconst\
    \ ll H_MOD = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0,\
    \ H_MOD)(rng);\n\nvector<ll> pow_b = {1};\n\nstruct Hash {\n    ll val;\n    int\
    \ len;\n\n    Hash(ll x, int y) : val(x), len(y) {}\n\n    Hash operator+(Hash\
    \ b) {\n        return Hash((__int128_t(val) * pow_b[b.len] + b.val) % H_MOD,\
    \ len + b.len);\n    }\n\n    friend bool operator==(const Hash &a, const Hash\
    \ &b) {\n        return a.val == b.val && a.len == b.len;\n    }\n};\n\nstruct\
    \ StringHash {\n    int len;\n    vector<ll> h;\n\n    template <class T>\n  \
    \  StringHash(const T &s) : len(sz(s)), h(len + 1) {\n        for (int i = 0;\
    \ i < len; i++) {\n            h[i + 1] = (__int128_t(h[i]) * H_BASE + s[i]) %\
    \ H_MOD;\n        }\n        while (sz(pow_b) <= len) {\n            pow_b.push_back(__int128_t(pow_b.back())\
    \ * H_BASE % H_MOD);\n        }\n    }\n\n    Hash get(int l, int r) {\n     \
    \   r++;\n        return Hash(((h[r] - __int128_t(h[l]) * pow_b[r - l]) % H_MOD\
    \ + H_MOD) % H_MOD, r - l);\n    }\n\n    Hash get() {\n        return get(0,\
    \ sz(h) - 1);\n    }\n};\n#line 6 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n\nint main() {\n    string s;\n    cin >> s;\n    string rev = s;\n    reverse(all(rev));\n\
    \    StringHash a(s), b(rev);\n    const int n = sz(s);\n    vector<int> ans(2\
    \ * n - 1);\n    for (int i = 0; i < n; i++) {\n        ans[2 * i] = 2 * bsmax(0,\
    \ min(i, n - i - 1), [&](int d) {\n            return a.get(i - d, i) == b.get(n\
    \ - i - 1 - d, n - i - 1);\n        }) + 1;\n    }\n    for (int i = 0; i < n\
    \ - 1; i++) {\n        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int\
    \ d) {\n            return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);\n\
    \        }) + 2;\n    }\n    for (int i = 0; i < 2 * n - 1; i++) {\n        cout\
    \ << ans[i] << ' ';\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../common/binsearch.h\"\
    \n#include \"../../../strings/hashing.h\"\n\nint main() {\n    string s;\n   \
    \ cin >> s;\n    string rev = s;\n    reverse(all(rev));\n    StringHash a(s),\
    \ b(rev);\n    const int n = sz(s);\n    vector<int> ans(2 * n - 1);\n    for\
    \ (int i = 0; i < n; i++) {\n        ans[2 * i] = 2 * bsmax(0, min(i, n - i -\
    \ 1), [&](int d) {\n            return a.get(i - d, i) == b.get(n - i - 1 - d,\
    \ n - i - 1);\n        }) + 1;\n    }\n    for (int i = 0; i < n - 1; i++) {\n\
    \        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int d) {\n     \
    \       return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);\n        })\
    \ + 2;\n    }\n    for (int i = 0; i < 2 * n - 1; i++) {\n        cout << ans[i]\
    \ << ' ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - common/binsearch.h
  - strings/hashing.h
  isVerificationFile: true
  path: verify/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---
