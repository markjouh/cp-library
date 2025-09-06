---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: numeric/sieve_factor.h
    title: numeric/sieve_factor.h
  - icon: ':x:'
    path: template/template.h
    title: template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"verify/library_checker/number_theory/enumerate_primes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#line\
    \ 1 \"template/template.h\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <cctype>\n#include <cerrno>\n#include\
    \ <cfloat>\n#include <chrono>\n#include <climits>\n#include <clocale>\n#include\
    \ <cmath>\n#include <complex>\n#include <csetjmp>\n#include <csignal>\n#include\
    \ <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <cwchar>\n#include\
    \ <cwctype>\n#include <deque>\n#include <exception>\n#include <forward_list>\n\
    #include <fstream>\n#include <functional>\n#include <iomanip>\n#include <ios>\n\
    #include <iosfwd>\n#include <iostream>\n#include <istream>\n#include <iterator>\n\
    #include <limits>\n#include <list>\n#include <locale>\n#include <map>\n#include\
    \ <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <stdexcept>\n#include <streambuf>\n#include\
    \ <string>\n#include <thread>\n#include <tuple>\n#include <type_traits>\n#include\
    \ <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n#include <utility>\n\
    #include <valarray>\n#include <vector>\n\n// C++11\n#include <atomic>\n#include\
    \ <condition_variable>\n#include <future>\n#include <initializer_list>\n#include\
    \ <mutex>\n#include <scoped_allocator>\n#line 71 \"template/template.h\"\n#include\
    \ <typeindex>\n\n// C++14\n#include <shared_mutex>\n\n// C++17\n#if __cplusplus\
    \ >= 201703L\n#include <any>\n#include <charconv>\n#include <execution>\n#include\
    \ <filesystem>\n#include <memory_resource>\n#include <optional>\n#include <string_view>\n\
    #include <variant>\n#endif\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n\n// Portable builtin implementations for compilers that don't have\
    \ them\n// __lg(x) - returns floor(log2(x)) for x > 0\n#ifndef __has_builtin\n\
    \  #define __has_builtin(x) 0\n#endif\n\n#if !__has_builtin(__lg)\n  inline int\
    \ __lg(int x) {\n    assert(x > 0);\n    int r = 0;\n    while (x >>= 1) r++;\n\
    \    return r;\n  }\n  inline int __lg(unsigned int x) {\n    assert(x > 0);\n\
    \    int r = 0;\n    while (x >>= 1) r++;\n    return r;\n  }\n  inline int __lg(long\
    \ long x) {\n    assert(x > 0);\n    int r = 0;\n    while (x >>= 1) r++;\n  \
    \  return r;\n  }\n  inline int __lg(unsigned long long x) {\n    assert(x > 0);\n\
    \    int r = 0;\n    while (x >>= 1) r++;\n    return r;\n  }\n#endif\n\n// __builtin_popcount\
    \ - count number of set bits\n#if !__has_builtin(__builtin_popcount)\n  inline\
    \ int __builtin_popcount(unsigned int x) {\n    int c = 0;\n    while (x) { c++;\
    \ x &= x - 1; }\n    return c;\n  }\n#endif\n\n#if !__has_builtin(__builtin_popcountll)\n\
    \  inline int __builtin_popcountll(unsigned long long x) {\n    int c = 0;\n \
    \   while (x) { c++; x &= x - 1; }\n    return c;\n  }\n#endif\n\n// __builtin_clz\
    \ - count leading zeros (undefined for x=0)\n#if !__has_builtin(__builtin_clz)\n\
    \  inline int __builtin_clz(unsigned int x) {\n    assert(x != 0);\n    int c\
    \ = 0;\n    if (x <= 0x0000FFFF) { c += 16; x <<= 16; }\n    if (x <= 0x00FFFFFF)\
    \ { c += 8; x <<= 8; }\n    if (x <= 0x0FFFFFFF) { c += 4; x <<= 4; }\n    if\
    \ (x <= 0x3FFFFFFF) { c += 2; x <<= 2; }\n    if (x <= 0x7FFFFFFF) { c += 1; }\n\
    \    return c;\n  }\n#endif\n\n#if !__has_builtin(__builtin_clzll)\n  inline int\
    \ __builtin_clzll(unsigned long long x) {\n    assert(x != 0);\n    int c = 0;\n\
    \    if (x <= 0x00000000FFFFFFFFULL) { c += 32; x <<= 32; }\n    if (x <= 0x0000FFFFFFFFFFFFULL)\
    \ { c += 16; x <<= 16; }\n    if (x <= 0x00FFFFFFFFFFFFFFULL) { c += 8; x <<=\
    \ 8; }\n    if (x <= 0x0FFFFFFFFFFFFFFFULL) { c += 4; x <<= 4; }\n    if (x <=\
    \ 0x3FFFFFFFFFFFFFFFULL) { c += 2; x <<= 2; }\n    if (x <= 0x7FFFFFFFFFFFFFFFULL)\
    \ { c += 1; }\n    return c;\n  }\n#endif\n\n// __builtin_ctz - count trailing\
    \ zeros (undefined for x=0)\n#if !__has_builtin(__builtin_ctz)\n  inline int __builtin_ctz(unsigned\
    \ int x) {\n    assert(x != 0);\n    int c = 0;\n    if ((x & 0x0000FFFF) == 0)\
    \ { c += 16; x >>= 16; }\n    if ((x & 0x000000FF) == 0) { c += 8; x >>= 8; }\n\
    \    if ((x & 0x0000000F) == 0) { c += 4; x >>= 4; }\n    if ((x & 0x00000003)\
    \ == 0) { c += 2; x >>= 2; }\n    if ((x & 0x00000001) == 0) { c += 1; }\n   \
    \ return c;\n  }\n#endif\n\n#if !__has_builtin(__builtin_ctzll)\n  inline int\
    \ __builtin_ctzll(unsigned long long x) {\n    assert(x != 0);\n    int c = 0;\n\
    \    if ((x & 0x00000000FFFFFFFFULL) == 0) { c += 32; x >>= 32; }\n    if ((x\
    \ & 0x000000000000FFFFULL) == 0) { c += 16; x >>= 16; }\n    if ((x & 0x00000000000000FFULL)\
    \ == 0) { c += 8; x >>= 8; }\n    if ((x & 0x000000000000000FULL) == 0) { c +=\
    \ 4; x >>= 4; }\n    if ((x & 0x0000000000000003ULL) == 0) { c += 2; x >>= 2;\
    \ }\n    if ((x & 0x0000000000000001ULL) == 0) { c += 1; }\n    return c;\n  }\n\
    #endif\n\n// __builtin_parity - parity of number of set bits\n#if !__has_builtin(__builtin_parity)\n\
    \  inline int __builtin_parity(unsigned int x) {\n    return __builtin_popcount(x)\
    \ & 1;\n  }\n#endif\n\n#if !__has_builtin(__builtin_parityll)\n  inline int __builtin_parityll(unsigned\
    \ long long x) {\n    return __builtin_popcountll(x) & 1;\n  }\n#endif\n\nusing\
    \ namespace std;\n#line 1 \"numeric/sieve_factor.h\"\n/*\n|           | $\\max_{1\
    \ \\leq k \\leq n} \\tau(k)$ | $\\pi(n)$ |\n| --------- | --------------------------------\
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
    \ sieve(int n) {\n  mn_factor.resize(n + 1);\n  for (int i = 2; i <= n; i++) {\n\
    \    if (!mn_factor[i]) {\n      mn_factor[i] = i;\n      primes.push_back(i);\n\
    \      for (int64_t j = 1ll * i * i; j <= n; j += i) {\n        if (!mn_factor[j])\
    \ {\n          mn_factor[j] = i;\n        }\n      }\n    }\n  }\n}\n\ntemplate\
    \ <class T>\nauto factorize(T x) {\n  vector<pair<T, int>> res;\n\n  // O(log\
    \ x) if sieved up to x\n  if (x <= sz(mn_factor) - 1) {\n    while (x > 1) {\n\
    \      int y = mn_factor[x];\n      res.emplace_back(y, 0);\n      while (x %\
    \ y == 0) {\n        x /= y;\n        res.back().second++;\n      }\n    }\n \
    \   return res;\n  }\n\n  // O(sqrt x log x) otherwise, must have sieved to sqrt(x)\n\
    \  for (int p : primes) {\n    if (1ll * p * p > x) {\n      break;\n    }\n \
    \   int exp = 0;\n    while (x % p == 0) {\n      x /= p;\n      exp++;\n    }\n\
    \    if (exp) {\n      res.emplace_back(p, exp);\n    }\n  }\n  if (x > 1) {\n\
    \    res.emplace_back(x, 1);\n  }\n  return res;\n}\n\ntemplate <class T>\nauto\
    \ gen_divisors(T x) {\n  vector<T> res = {1};\n  for (auto [p, exp] : factorize(x))\
    \ {\n    const int old_size = sz(res);\n    T coeff = 1;\n    for (int i = 0;\
    \ i < exp; i++) {\n      coeff *= p;\n      for (int j = 0; j < old_size; j++)\
    \ {\n        res.push_back(coeff * res[j]);\n      }\n    }\n  }\n  return res;\n\
    }\n#line 5 \"verify/library_checker/number_theory/enumerate_primes.test.cpp\"\n\
    \nint main() {\n  int n, a, b;\n  cin >> n >> a >> b;\n  sieve(n);\n  cout <<\
    \ sz(primes) << ' ';\n  vector<int> res;\n  for (int i = b; i < sz(primes); i\
    \ += a) {\n    res.push_back(primes[i]);\n  }\n  cout << sz(res) << '\\n';\n \
    \ for (int x : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include \"../../../template/template.h\"\n#include \"../../../numeric/sieve_factor.h\"\
    \n\nint main() {\n  int n, a, b;\n  cin >> n >> a >> b;\n  sieve(n);\n  cout <<\
    \ sz(primes) << ' ';\n  vector<int> res;\n  for (int i = b; i < sz(primes); i\
    \ += a) {\n    res.push_back(primes[i]);\n  }\n  cout << sz(res) << '\\n';\n \
    \ for (int x : res) {\n    cout << x << ' ';\n  }\n  cout << '\\n';\n}"
  dependsOn:
  - template/template.h
  - numeric/sieve_factor.h
  isVerificationFile: true
  path: verify/library_checker/number_theory/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2025-09-06 19:45:01-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/number_theory/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp
- /verify/verify/library_checker/number_theory/enumerate_primes.test.cpp.html
title: verify/library_checker/number_theory/enumerate_primes.test.cpp
---
