---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/binary_search.hpp
    title: Binary Search
  - icon: ':heavy_check_mark:'
    path: strings/hashing.hpp
    title: String Hashing
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
    #line 1 \"verify/boilerplate.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define\
    \ pb push_back\n#define eb emplace_back\n#define fi first\n#define se second\n\
    \nusing ll = long long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate <class T> bool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1\
    \ : 0;\n}\n\ntemplate <class T> bool ckmax(T &a, const T &b) {\n  return b > a\
    \ ? a = b, 1 : 0;\n}\n\nconst int INF = INT_MAX / 2;\nconst ll INFLL = LLONG_MAX\
    \ / 2;\n\nstruct InitIO {\n    InitIO() {\n        cin.tie(0)->sync_with_stdio(0);\n\
    \        cin.exceptions(cin.failbit);\n        cout << setprecision(10) << fixed;\n\
    \    }\n} init_io;\n#line 2 \"numeric/binary_search.hpp\"\n\ntemplate <class T,\
    \ class U>\nT bsmin(T lo, T hi, U f) {\n  assert(lo <= hi);\n  hi++;\n  for (T\
    \ i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n    hi -= (hi - i >= lo && f(hi\
    \ - i)) * i;\n  }\n  return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo,\
    \ T hi, U f) {\n  assert(lo <= hi);\n  lo--;\n  for (T i = T(1) << __lg(hi - lo);\
    \ i > 0; i >>= 1) {\n    lo += (lo + i <= hi && f(lo + i)) * i;\n  }\n  return\
    \ lo;\n}\n#line 2 \"strings/hashing.hpp\"\n\nnamespace hashing {\n  \nmt19937_64\
    \ rng(chrono::steady_clock::now().time_since_epoch().count());\n\nconst ll H_MOD\
    \ = (1ll << 61) - 1;\nconst ll H_BASE = uniform_int_distribution<ll>(0, H_MOD)(rng);\n\
    \nvector<ll> pow_b = {1};\n\nusing mul_t = __int128_t;\n\nstruct Hash {\n  ll\
    \ val;\n  int len;\n\n  Hash(ll x, int y) : val(x), len(y) {}\n\n  Hash operator+(Hash\
    \ b) {\n    return Hash((mul_t(val) * pow_b[b.len] + b.val) % H_MOD, len + b.len);\n\
    \  }\n\n  bool operator==(Hash b) {\n    return val == b.val && len == b.len;\n\
    \  }\n};\n\nstruct StringHash {\n  int len;\n  vector<ll> h;\n\n  template <class\
    \ T>\n  StringHash(const T &s) : len(sz(s)), h(len + 1) {\n    for (int i = 0;\
    \ i < len; i++) {\n      h[i + 1] = (mul_t(h[i]) * H_BASE + s[i]) % H_MOD;\n \
    \   }\n    while (sz(pow_b) <= len) {\n      pow_b.push_back(mul_t(pow_b.back())\
    \ * H_BASE % H_MOD);\n    }\n  }\n\n  Hash get(int l, int r) {\n    r++;\n   \
    \ return Hash(((h[r] - mul_t(h[l]) * pow_b[r - l]) % H_MOD + H_MOD) % H_MOD, r\
    \ - l);\n  }\n\n  Hash get() {\n    return get(0, sz(h) - 1);\n  }\n};\n}\n#line\
    \ 6 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\n\nusing\
    \ namespace hashing;\n\nint main() {\n  string s;\n  cin >> s;\n  string rev =\
    \ s;\n  reverse(all(rev));\n  StringHash a(s), b(rev);\n  const int n = sz(s);\n\
    \  vector<int> ans(2 * n - 1);\n  for (int i = 0; i < n; i++) {\n    ans[2 * i]\
    \ = 2 * bsmax(0, min(i, n - i - 1), [&](int d) {\n      return a.get(i - d, i)\
    \ == b.get(n - i - 1 - d, n - i - 1);\n    }) + 1;\n  }\n  for (int i = 0; i <\
    \ n - 1; i++) {\n    ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int\
    \ d) {\n      return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);\n   \
    \ }) + 2;\n  }\n  for (int i = 0; i < 2 * n - 1; i++) {\n    cout << ans[i] <<\
    \ ' ';\n  }\n  cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../numeric/binary_search.hpp\"\
    \n#include \"../../../strings/hashing.hpp\"\n\nusing namespace hashing;\n\nint\
    \ main() {\n  string s;\n  cin >> s;\n  string rev = s;\n  reverse(all(rev));\n\
    \  StringHash a(s), b(rev);\n  const int n = sz(s);\n  vector<int> ans(2 * n -\
    \ 1);\n  for (int i = 0; i < n; i++) {\n    ans[2 * i] = 2 * bsmax(0, min(i, n\
    \ - i - 1), [&](int d) {\n      return a.get(i - d, i) == b.get(n - i - 1 - d,\
    \ n - i - 1);\n    }) + 1;\n  }\n  for (int i = 0; i < n - 1; i++) {\n    ans[2\
    \ * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int d) {\n      return a.get(i\
    \ - d, i) == b.get(n - i - 2 - d, n - i - 2);\n    }) + 2;\n  }\n  for (int i\
    \ = 0; i < 2 * n - 1; i++) {\n    cout << ans[i] << ' ';\n  }\n  cout << '\\n';\n\
    }"
  dependsOn:
  - numeric/binary_search.hpp
  - strings/hashing.hpp
  isVerificationFile: true
  path: verify/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-08-31 12:05:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---
