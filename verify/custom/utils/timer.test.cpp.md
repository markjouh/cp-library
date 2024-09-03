---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: utils/random.hpp
    title: utils/random.hpp
  - icon: ':heavy_check_mark:'
    path: utils/timer.hpp
    title: utils/timer.hpp
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
  bundledCode: "#line 1 \"verify/custom/utils/timer.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#include <unistd.h>\n\n#line 1 \"\
    verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <chrono>\n#include <climits>\n#include <cmath>\n\
    #include <cstdint>\n#include <cstring>\n#include <functional>\n#include <iomanip>\n\
    #include <iostream>\n#include <map>\n#include <numeric>\n#include <queue>\n#include\
    \ <random>\n#include <set>\n#include <vector>\n\nusing namespace std;\n\n#define\
    \ arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r);\
    \ i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3,\
    \ rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >=\
    \ int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__,\
    \ per3, per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n#define pb push_back\n#define eb emplace_back\n#define fi first\n\
    #define se second\n\nusing ll = long long;\nusing pii = pair<int, int>;\nusing\
    \ pll = pair<ll, ll>;\n\ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n\
    \  return __lg(x);\n#else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n \
    \ }\n  return res;\n#endif\n}\n\ntemplate <class T>\nbool ckmin(T &a, const T\
    \ &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T =\
    \ int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\nstruct InitIO\
    \ {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"utils/random.hpp\"\
    \n\nmt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ntemplate <class T>\nT randint(T n) {\n  return uniform_int_distribution<T>(0,\
    \ n)(rng_64);\n}\n\ntemplate <class T>\nT randint(T lo, T hi) {\n  return uniform_int_distribution<T>(lo,\
    \ hi)(rng_64);\n}\n\ndouble randreal() {\n  return uniform_real_distribution<double>(0,\
    \ 1)(rng_64);\n}\n\ntemplate <class T>\ndouble randreal(T n) {\n  return uniform_real_distribution<double>(0,\
    \ n)(rng_64);\n}\n\ntemplate <class T>\ndouble randreal(T lo, T hi) {\n  return\
    \ uniform_real_distribution<double>(lo, hi)(rng_64);\n}\n\ntemplate <class T>\n\
    void shuffle_array(T &a) {\n  for (int i = 1; i < sz(a); i++) {\n    swap(a[i],\
    \ a[randint(0, i)]);\n  }\n}\n#line 2 \"utils/timer.hpp\"\n\nchrono::time_point<chrono::high_resolution_clock>\
    \ timer;\n\nvoid set_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n\
    }\n\nll elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}\n#line 8 \"verify/custom/utils/timer.test.cpp\"\n\n//\
    \ Kind of pointless, but I'll write a test for\n// completionism's sake...\n\n\
    const int TESTS = 10;\n\nint main() {\n  rep(i, TESTS) {\n    const int rand_ms\
    \ = randint(50, 500);\n    set_timer();\n    usleep(rand_ms * 1000);\n    assert(abs(elapsed()\
    \ - rand_ms) < 10);\n  }\n\n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <unistd.h>\n\
    \n#include \"../../boilerplate.hpp\"\n#include \"../../../utils/random.hpp\"\n\
    #include \"../../../utils/timer.hpp\"\n\n// Kind of pointless, but I'll write\
    \ a test for\n// completionism's sake...\n\nconst int TESTS = 10;\n\nint main()\
    \ {\n  rep(i, TESTS) {\n    const int rand_ms = randint(50, 500);\n    set_timer();\n\
    \    usleep(rand_ms * 1000);\n    assert(abs(elapsed() - rand_ms) < 10);\n  }\n\
    \n  cerr << \"Tests passed\\n\";\n\n  int a, b;\n  cin >> a >> b;\n  cout << a\
    \ + b << '\\n';\n}"
  dependsOn:
  - utils/random.hpp
  - utils/timer.hpp
  isVerificationFile: true
  path: verify/custom/utils/timer.test.cpp
  requiredBy: []
  timestamp: '2024-09-03 12:19:01-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/timer.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/timer.test.cpp
- /verify/verify/custom/utils/timer.test.cpp.html
title: verify/custom/utils/timer.test.cpp
---
