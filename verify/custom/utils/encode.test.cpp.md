---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/encode.hpp
    title: utils/encode.hpp
  - icon: ':heavy_check_mark:'
    path: utils/random.hpp
    title: utils/random.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/utils/encode.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"verify/boilerplate.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdint>\n\
    #include <cstring>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <vector>\n\nusing namespace std;\n\n#define arg4(a, b, c, d,\
    \ ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define\
    \ rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n\
    \ \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define\
    \ per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class\
    \ T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n#else\n  int\
    \ res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n}\n\n\
    template <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a = b, 1\
    \ : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return b >\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"utils/random.hpp\"\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T>\nT randint(T n) {\n  return uniform_int_distribution<T>(0,\
    \ n)(rng_64);\n}\n\ntemplate <class T>\nT randint(T lo, T hi) {\n  return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ndouble randreal() {\n  return uniform_real_distribution<double>(0,\
    \ 1)(rng_64);\n}\n\ntemplate <class T>\ndouble randreal(T n) {\n  return uniform_real_distribution<double>(0,\
    \ n)(rng_64);\n}\n\ntemplate <class T>\ndouble randreal(T lo, T hi) {\n  return\
    \ uniform_real_distribution<double>(lo, hi)(rng_64);\n}\n\ntemplate <class T>\n\
    void shuffle_array(T &a) {\n  for (int i = 1; i < sz(a); i++) {\n    swap(a[i],\
    \ a[randint(0, i)]);\n  }\n}\n#line 2 \"utils/encode.hpp\"\n\nconstexpr ll pow_94[10]\
    \ = {1, 94, 8836, 830584, 78074896, 7339040224, 689869781056, 64847759419264,\
    \ 6095689385410816, 572994802228616704};\n\ntemplate <class T, int W>\nstring\
    \ encode(T x) {\n  if constexpr (is_integral_v<T>) {\n    string res(W, 0);\n\
    \    for (int i = 0; i < W; i++) {\n      res[i] = char(33 + x % 94);\n      x\
    \ /= 94;\n    }\n    return res;\n  } else {\n    string res;\n    for (auto &y\
    \ : x) {\n      res += encode<typename T::value_type, W>(y);\n    }\n    return\
    \ res;\n  }\n}\n\ntemplate <class T, int W>\nT decode(string s) {\n  if constexpr\
    \ (is_integral_v<T>) {\n    T res = 0;\n    for (int i = 0; i < W; i++) {\n  \
    \    res += pow_94[i] * ll(s[i] - 33);\n    }\n    return res;\n  } else {\n \
    \   constexpr int segs = tuple_size_v<T>;\n    const int len = sz(s) / segs;\n\
    \    T res;\n    for (int i = 0; i < segs; i++) {\n      res[i] = decode<typename\
    \ T::value_type, W>(s.substr(len * i, len));\n    }\n    return res;\n  }\n}\n\
    \n#define make_encoded(type, x, w) cout << \"const \" << type << ' ' << #x <<\
    \ \" = decode<\" << type << \", \" << w << \">(R\\\"zzzzz(\" << encode<decltype(x),\
    \ w>(x) << \")zzzzz\\\")\" << endl\n#line 6 \"verify/custom/utils/encode.test.cpp\"\
    \n\nconst int TESTS = 1000;\n\nint main() {\n  rep(i, TESTS) {\n    array<int,\
    \ 2500> arr;\n    rep(j, 2500) {\n      arr[j] = randint(1, inf<>);\n    }\n \
    \   auto enc = encode<decltype(arr), 5>(arr);\n    auto dec = decode<decltype(arr),\
    \ 5>(enc);\n    assert(arr == dec);\n  }\n\n  rep(i, TESTS) {\n    array<array<int,\
    \ 50>, 50> arr;\n    rep(j, 50) {\n      rep(k, 50) {\n        arr[j][k] = randint(1,\
    \ inf<>);\n      }\n    }\n    auto enc = encode<decltype(arr), 5>(arr);\n   \
    \ auto dec = decode<decltype(arr), 5>(enc);\n    assert(arr == dec);\n  }\n\n\
    \  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin >> a >> b;\n  cout << a\
    \ + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../boilerplate.hpp\"\n#include \"../../../utils/random.hpp\"\n#include \"../../../utils/encode.hpp\"\
    \n\nconst int TESTS = 1000;\n\nint main() {\n  rep(i, TESTS) {\n    array<int,\
    \ 2500> arr;\n    rep(j, 2500) {\n      arr[j] = randint(1, inf<>);\n    }\n \
    \   auto enc = encode<decltype(arr), 5>(arr);\n    auto dec = decode<decltype(arr),\
    \ 5>(enc);\n    assert(arr == dec);\n  }\n\n  rep(i, TESTS) {\n    array<array<int,\
    \ 50>, 50> arr;\n    rep(j, 50) {\n      rep(k, 50) {\n        arr[j][k] = randint(1,\
    \ inf<>);\n      }\n    }\n    auto enc = encode<decltype(arr), 5>(arr);\n   \
    \ auto dec = decode<decltype(arr), 5>(enc);\n    assert(arr == dec);\n  }\n\n\
    \  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin >> a >> b;\n  cout << a\
    \ + b << '\\n';\n}"
  dependsOn:
  - utils/random.hpp
  - utils/encode.hpp
  isVerificationFile: true
  path: verify/custom/utils/encode.test.cpp
  requiredBy: []
  timestamp: '2024-09-03 12:19:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/encode.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/encode.test.cpp
- /verify/verify/custom/utils/encode.test.cpp.html
title: verify/custom/utils/encode.test.cpp
---
