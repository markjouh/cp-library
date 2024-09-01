---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/binary_search_reals.hpp
    title: numeric/binary_search_reals.hpp
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
  bundledCode: "#line 1 \"verify/custom/numeric/binary_search_reals.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"verify/boilerplate.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#define all(x) begin(x), end(x)\n\
    #define sz(x) int(size(x))\n#define pb push_back\n#define eb emplace_back\n#define\
    \ fi first\n#define se second\n\nusing ll = long long;\nusing pii = pair<int,\
    \ int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class T> bool ckmin(T &a, const\
    \ T &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T> bool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\nconst int INF = INT_MAX\
    \ / 2;\nconst ll INFLL = LLONG_MAX / 2;\n\nstruct InitIO {\n  InitIO() {\n   \
    \ cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n    cout\
    \ << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"local/my_random.hpp\"\
    \n\nnamespace my_random {\n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T>\nT randint(T lo, T hi) {\n  return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\nT randreal(T lo, T hi) {\n  return uniform_real_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\nvoid randshuf(T &a) {\n  for (int i =\
    \ 1; i < sz(a); i++) {\n    swap(a[i], a[randint(0, i)]);\n  }\n}\n};\n#line 2\
    \ \"numeric/binary_search_reals.hpp\"\n\ntemplate <class T>\ndouble bsmin_reals(double\
    \ lo, double hi, T f) {\n  static_assert(sizeof(uint64_t) >= sizeof(double));\n\
    \  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo), r = reinterpret_cast<uint64_t&>(hi)\
    \ + 1;\n  for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n    uint64_t\
    \ nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt))) * i;\n\
    \  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\ndouble\
    \ bsmax_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t) >=\
    \ sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n  for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n#line 6 \"verify/custom/numeric/binary_search_reals.test.cpp\"\
    \n\nusing namespace my_random;\n\nconst int TESTS = 1e6;\nconst double MXV = 1e12,\
    \ ERROR = 1e-3;\n\nvoid test() {\n  // Search for exact double value, should have\
    \ no error\n  const double t1 = randreal<double>(0, DBL_MAX);\n  double left =\
    \ bsmax_reals(0, DBL_MAX, [&](double x) {\n    return x <= t1;\n  });\n  assert(left\
    \ == t1);\n  double right = bsmin_reals(0, DBL_MAX, [&](double x) {\n    return\
    \ x >= t1;\n  });\n  assert(right == t1);\n\n  // Try computing sqrt\n  const\
    \ double t2 = randreal<double>(0, MXV);\n  double sqrt_val = bsmax_reals(0, MXV,\
    \ [&](double x) {\n    return x * x <= t2;\n  });\n  double sqrt_res = sqrt_val\
    \ * sqrt_val;\n  assert(sqrt_res <= t2 && t2 - sqrt_res < ERROR);\n\n  // Try\
    \ computing cbrt\n  const double t3 = randreal<double>(0, MXV);\n  double cbrt_val\
    \ = bsmax_reals(0, MXV, [&](double x) {\n    return x * x * x <= t3;\n  });\n\
    \  double cbrt_res = cbrt_val * cbrt_val * cbrt_val;\n  assert(cbrt_res <= t3\
    \ && t3 - cbrt_res < ERROR);\n}\n\nint main() {\n  for (int i = 0; i < TESTS;\
    \ i++) {\n    test();\n  }\n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../boilerplate.hpp\"\n#include \"../../../local/my_random.hpp\"\n#include \"\
    ../../../numeric/binary_search_reals.hpp\"\n\nusing namespace my_random;\n\nconst\
    \ int TESTS = 1e6;\nconst double MXV = 1e12, ERROR = 1e-3;\n\nvoid test() {\n\
    \  // Search for exact double value, should have no error\n  const double t1 =\
    \ randreal<double>(0, DBL_MAX);\n  double left = bsmax_reals(0, DBL_MAX, [&](double\
    \ x) {\n    return x <= t1;\n  });\n  assert(left == t1);\n  double right = bsmin_reals(0,\
    \ DBL_MAX, [&](double x) {\n    return x >= t1;\n  });\n  assert(right == t1);\n\
    \n  // Try computing sqrt\n  const double t2 = randreal<double>(0, MXV);\n  double\
    \ sqrt_val = bsmax_reals(0, MXV, [&](double x) {\n    return x * x <= t2;\n  });\n\
    \  double sqrt_res = sqrt_val * sqrt_val;\n  assert(sqrt_res <= t2 && t2 - sqrt_res\
    \ < ERROR);\n\n  // Try computing cbrt\n  const double t3 = randreal<double>(0,\
    \ MXV);\n  double cbrt_val = bsmax_reals(0, MXV, [&](double x) {\n    return x\
    \ * x * x <= t3;\n  });\n  double cbrt_res = cbrt_val * cbrt_val * cbrt_val;\n\
    \  assert(cbrt_res <= t3 && t3 - cbrt_res < ERROR);\n}\n\nint main() {\n  for\
    \ (int i = 0; i < TESTS; i++) {\n    test();\n  }\n  cerr << \"Tests passed\\\
    n\";\n\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << '\\n';\n}"
  dependsOn:
  - numeric/binary_search_reals.hpp
  isVerificationFile: true
  path: verify/custom/numeric/binary_search_reals.test.cpp
  requiredBy: []
  timestamp: '2024-09-01 01:14:09-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/numeric/binary_search_reals.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/numeric/binary_search_reals.test.cpp
- /verify/verify/custom/numeric/binary_search_reals.test.cpp.html
title: verify/custom/numeric/binary_search_reals.test.cpp
---
