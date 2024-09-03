---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: numeric/binary_search_reals.hpp
    title: numeric/binary_search_reals.hpp
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
  bundledCode: "#line 1 \"verify/custom/numeric/binary_search_reals.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"verify/boilerplate.hpp\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <climits>\n#include <cmath>\n#include <cstdint>\n\
    #include <cstring>\n#include <functional>\n#include <iomanip>\n#include <iostream>\n\
    #include <map>\n#include <numeric>\n#include <queue>\n#include <random>\n#include\
    \ <set>\n#include <vector>\n\nusing namespace std;\n\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n#define eb emplace_back\n\
    #define fi first\n#define se second\n\nusing ll = long long;\nusing pii = pair<int,\
    \ int>;\nusing pll = pair<ll, ll>;\n\ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n\
    \  return __lg(x);\n#else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n \
    \ }\n  return res;\n#endif\n}\n\ntemplate <class T>\nbool ckmin(T &a, const T\
    \ &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T =\
    \ int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\nstruct InitIO\
    \ {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"utils/random.hpp\"\
    \n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T>\nT randint(T lo, T hi) {\n  return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ntemplate <class T>\ndouble randreal(T lo, T hi) {\n  return\
    \ uniform_real_distribution<double>(lo, hi)(rng_64);\n}\n\ntemplate <class T>\n\
    void shuffle_array(T &a) {\n  for (int i = 1; i < sz(a); i++) {\n    swap(a[i],\
    \ a[randint(0, i)]);\n  }\n}\n#line 2 \"numeric/binary_search_reals.hpp\"\n\n\
    template <class T>\ndouble bsmin_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo),\
    \ r = reinterpret_cast<uint64_t&>(hi) + 1;\n  for (uint64_t i = 1ull << lg(r -\
    \ l); i > 0; i >>= 1) {\n    uint64_t nxt = r - i;\n    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(r);\n}\n\ntemplate <class T>\n\
    double bsmax_reals(double lo, double hi, T f) {\n  static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n  assert(lo <= hi);\n  uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n  for (uint64_t i = 1ull << lg(r\
    \ - l); i > 0; i >>= 1) {\n    uint64_t nxt = l + i;\n    l += (nxt <= r && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n  }\n  return reinterpret_cast<double&>(l);\n}\n#line 6 \"verify/custom/numeric/binary_search_reals.test.cpp\"\
    \n\nconst int TESTS = 1e6;\nconst double MXV = 1e12, ERROR = 1e-3;\n\nvoid test()\
    \ {\n  // Search for exact double value, should have no error\n  const double\
    \ t1 = randreal<double>(0, inf<double>);\n  double left = bsmax_reals(0, inf<double>,\
    \ [&](double x) {\n    return x <= t1;\n  });\n  assert(left == t1);\n  double\
    \ right = bsmin_reals(0, inf<double>, [&](double x) {\n    return x >= t1;\n \
    \ });\n  assert(right == t1);\n\n  // Try computing sqrt\n  const double t2 =\
    \ randreal<double>(0, MXV);\n  double sqrt_val = bsmax_reals(0, MXV, [&](double\
    \ x) {\n    return x * x <= t2;\n  });\n  double sqrt_res = sqrt_val * sqrt_val;\n\
    \  assert(sqrt_res <= t2 && t2 - sqrt_res < ERROR);\n\n  // Try computing cbrt\n\
    \  const double t3 = randreal<double>(0, MXV);\n  double cbrt_val = bsmax_reals(0,\
    \ MXV, [&](double x) {\n    return x * x * x <= t3;\n  });\n  double cbrt_res\
    \ = cbrt_val * cbrt_val * cbrt_val;\n  assert(cbrt_res <= t3 && t3 - cbrt_res\
    \ < ERROR);\n}\n\nint main() {\n  for (int i = 0; i < TESTS; i++) {\n    test();\n\
    \  }\n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../boilerplate.hpp\"\n#include \"../../../utils/random.hpp\"\n#include \"../../../numeric/binary_search_reals.hpp\"\
    \n\nconst int TESTS = 1e6;\nconst double MXV = 1e12, ERROR = 1e-3;\n\nvoid test()\
    \ {\n  // Search for exact double value, should have no error\n  const double\
    \ t1 = randreal<double>(0, inf<double>);\n  double left = bsmax_reals(0, inf<double>,\
    \ [&](double x) {\n    return x <= t1;\n  });\n  assert(left == t1);\n  double\
    \ right = bsmin_reals(0, inf<double>, [&](double x) {\n    return x >= t1;\n \
    \ });\n  assert(right == t1);\n\n  // Try computing sqrt\n  const double t2 =\
    \ randreal<double>(0, MXV);\n  double sqrt_val = bsmax_reals(0, MXV, [&](double\
    \ x) {\n    return x * x <= t2;\n  });\n  double sqrt_res = sqrt_val * sqrt_val;\n\
    \  assert(sqrt_res <= t2 && t2 - sqrt_res < ERROR);\n\n  // Try computing cbrt\n\
    \  const double t3 = randreal<double>(0, MXV);\n  double cbrt_val = bsmax_reals(0,\
    \ MXV, [&](double x) {\n    return x * x * x <= t3;\n  });\n  double cbrt_res\
    \ = cbrt_val * cbrt_val * cbrt_val;\n  assert(cbrt_res <= t3 && t3 - cbrt_res\
    \ < ERROR);\n}\n\nint main() {\n  for (int i = 0; i < TESTS; i++) {\n    test();\n\
    \  }\n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << '\\n';\n}"
  dependsOn:
  - utils/random.hpp
  - numeric/binary_search_reals.hpp
  isVerificationFile: true
  path: verify/custom/numeric/binary_search_reals.test.cpp
  requiredBy: []
  timestamp: '2024-09-02 21:09:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/numeric/binary_search_reals.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/numeric/binary_search_reals.test.cpp
- /verify/verify/custom/numeric/binary_search_reals.test.cpp.html
title: verify/custom/numeric/binary_search_reals.test.cpp
---
