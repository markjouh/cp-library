---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/binsearch.h
    title: numeric/binsearch.h
  - icon: ':heavy_check_mark:'
    path: strings/hashing.h
    title: strings/hashing.h
  - icon: ':question:'
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
    #line 1 \"template/template.h\"\n/**\n *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"numeric/binsearch.h\"\ntemplate <class T, class U>\nT bsmin(T\
    \ lo, T hi, U f) {\n  assert(lo <= hi);\n  hi++;\n  for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n    hi -= (hi - i >= lo && f(hi - i)) * i;\n  }\n\
    \  return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f) {\n\
    \  assert(lo <= hi);\n  lo--;\n  for (T i = T(1) << __lg(hi - lo); i > 0; i >>=\
    \ 1) {\n    lo += (lo + i <= hi && f(lo + i)) * i;\n  }\n  return lo;\n}\n#line\
    \ 1 \"strings/hashing.h\"\nnamespace hashing {\n\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \nconst uint64_t MOD = (1ll << 61) - 1;\nconst uint64_t B = uniform_int_distribution<uint64_t>(0,\
    \ MOD)(mt);\n\nuint64_t add(uint64_t a, uint64_t b) {\n  a += b;\n  if (a >= MOD)\
    \ {\n    a -= MOD;\n  }\n  return a;\n}\n\nuint64_t sub(uint64_t a, uint64_t b)\
    \ {\n  a += MOD - b;\n  if (a >= MOD) {\n    a -= MOD;\n  }\n  return a;\n}\n\n\
    uint64_t mul(uint64_t a, uint64_t b) {\n  uint64_t l1 = (uint32_t) a, h1 = a >>\
    \ 32, l2 = (uint32_t) b, h2 = b >> 32;\n  uint64_t l = l1 * l2, m = l1 * h2 +\
    \ l2 * h1, h = h1 * h2;\n  uint64_t ret = (l & MOD) + (l >> 61) + (h << 3) + (m\
    \ >> 29) + (m << 35 >> 3) + 1;\n  ret = (ret & MOD) + (ret >> 61);\n  ret = (ret\
    \ & MOD) + (ret >> 61);\n  return ret - 1;\n}\n\ntemplate<typename T, typename\
    \ = void>\nstruct is_iterable : false_type {};\ntemplate<typename T>\nstruct is_iterable<T,\
    \ void_t<\n  decltype(begin(declval<T&>())),\n  decltype(end(declval<T&>()))\n\
    >> : true_type {};\n\ntemplate<typename T>\nstruct is_tuple : false_type {};\n\
    template<typename... Ts>\nstruct is_tuple<tuple<Ts...>> : true_type {};\ntemplate<typename\
    \ T, typename U>\nstruct is_tuple<pair<T, U>> : true_type {};\n\ntemplate<typename\
    \ T>\nuint64_t hash_one(const T &t) {\n  if constexpr (is_tuple<T>::value) {\n\
    \    uint64_t res = 0;\n    apply([&](const auto &...elems) {\n      ((res = add(mul(res,\
    \ B), hash_one(elems))), ...);\n    }, t);\n    return res;\n  } else if constexpr\
    \ (is_iterable<T>::value) {\n    uint64_t res = 0;\n    for (const auto &x : t)\n\
    \      res = add(mul(res, B), hash_one(x));\n    return res;\n  } else {\n   \
    \ return static_cast<uint64_t>(t);\n  }\n}\n\ntemplate<typename ...Args>\nuint64_t\
    \ hash(const Args &...args) {\n  uint64_t res = 0;\n  ((res = add(mul(res, B),\
    \ hash_one(args))), ...);\n  return res;\n}\n\nvector<uint64_t> pow_b = {1};\n\
    \nstruct SegHash {\n  uint64_t val;\n  int len;\n\n  SegHash(uint64_t x, int y)\
    \ : val(x), len(y) {}\n\n  SegHash operator+(SegHash b) const {\n    return SegHash(add(mul(val,\
    \ pow_b[b.len]), b.val), len + b.len);\n  }\n\n  bool operator==(SegHash b) const\
    \ {\n    return val == b.val;\n  }\n};\n\nstruct RollingHash {\n  int n;\n  vector<uint64_t>\
    \ h;\n\n  template <class T>\n  RollingHash(const T &s) : n(s.size()), h(n + 1)\
    \ {\n    for (int i = 0; i < n; i++) {\n      h[i + 1] = add(mul(h[i], B), s[i]);\n\
    \    }\n    int p = pow_b.size();\n    if (p < n + 1) {\n      pow_b.resize(n\
    \ + 1);\n      for (int i = p; i <= n; i++) {\n        pow_b[i] = mul(pow_b[i\
    \ - 1], B);\n      }\n    }\n  }\n\n  SegHash get(int l, int r) const {\n    assert(l\
    \ < ++r);\n    return SegHash(sub(h[r], mul(h[l], pow_b[r - l])), r - l);\n  }\n\
    \n  SegHash get_all() const {\n    return SegHash(h[n], n);\n  }\n};\n\n} // namespace\
    \ hashing\n#line 6 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n\nint main() {\n    string s;\n    cin >> s;\n    string rev = s;\n    reverse(all(rev));\n\
    \    hashing::RollingHash a(s), b(rev);\n    const int n = sz(s);\n    vector<int>\
    \ ans(2 * n - 1);\n    for (int i = 0; i < n; i++) {\n        ans[2 * i] = 2 *\
    \ bsmax(0, min(i, n - i - 1), [&](int d) {\n            return a.get(i - d, i)\
    \ == b.get(n - i - 1 - d, n - i - 1);\n        }) + 1;\n    }\n    for (int i\
    \ = 0; i < n - 1; i++) {\n        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i -\
    \ 2), [&](int d) {\n            return a.get(i - d, i) == b.get(n - i - 2 - d,\
    \ n - i - 2);\n        }) + 2;\n    }\n    for (int i = 0; i < 2 * n - 1; i++)\
    \ {\n        cout << ans[i] << ' ';\n    }\n    cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../numeric/binsearch.h\"\
    \n#include \"../../../strings/hashing.h\"\n\nint main() {\n    string s;\n   \
    \ cin >> s;\n    string rev = s;\n    reverse(all(rev));\n    hashing::RollingHash\
    \ a(s), b(rev);\n    const int n = sz(s);\n    vector<int> ans(2 * n - 1);\n \
    \   for (int i = 0; i < n; i++) {\n        ans[2 * i] = 2 * bsmax(0, min(i, n\
    \ - i - 1), [&](int d) {\n            return a.get(i - d, i) == b.get(n - i -\
    \ 1 - d, n - i - 1);\n        }) + 1;\n    }\n    for (int i = 0; i < n - 1; i++)\
    \ {\n        ans[2 * i + 1] = 2 * bsmax(0, min(i, n - i - 2), [&](int d) {\n \
    \           return a.get(i - d, i) == b.get(n - i - 2 - d, n - i - 2);\n     \
    \   }) + 2;\n    }\n    for (int i = 0; i < 2 * n - 1; i++) {\n        cout <<\
    \ ans[i] << ' ';\n    }\n    cout << '\\n';\n}"
  dependsOn:
  - template/template.h
  - numeric/binsearch.h
  - strings/hashing.h
  isVerificationFile: true
  path: verify/library_checker/string/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2025-03-18 16:29:46-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---
