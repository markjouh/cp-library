---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: numeric/mint.h
    title: numeric/mint.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"verify/aizu/ntl/power.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#line 1 \"template/template.h\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <cctype>\n#include <cerrno>\n\
    #include <cfloat>\n#include <chrono>\n#include <climits>\n#include <clocale>\n\
    #include <cmath>\n#include <complex>\n#include <csetjmp>\n#include <csignal>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdint>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <cwchar>\n\
    #include <cwctype>\n#include <deque>\n#include <exception>\n#include <forward_list>\n\
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
    \ namespace std;\n#line 1 \"numeric/mint.h\"\ntemplate <int MOD>\nstruct Mint\
    \ {\n  int v;\n \n  Mint(int64_t x = 0) : v(int(-MOD < x && x < MOD ? x : x %\
    \ MOD) + (x < 0) * MOD) {}\n \n  friend Mint pow(Mint base, int64_t exp) {\n \
    \   Mint res = 1;\n    while (exp) {\n      if (exp & 1) {\n        res *= base;\n\
    \      }\n      base *= base;\n      exp >>= 1;\n    }\n    return res;\n  }\n\
    \n  Mint &operator+=(Mint b) {\n    v = v + b.v - (v + b.v >= MOD) * MOD;\n  \
    \  return *this;\n  }\n  Mint &operator-=(Mint b) {\n    v = v - b.v + (v < b.v)\
    \ * MOD;\n    return *this;\n  }\n  Mint &operator*=(Mint b) {\n    v = int(1ll\
    \ * v * b.v % MOD);\n    return *this;\n  }\n  Mint &operator/=(Mint b) {\n  \
    \  v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n    return *this;\n  }\n  friend\
    \ Mint operator+(Mint a, Mint b) {\n    return a += b;\n  }\n  friend Mint operator-(Mint\
    \ a, Mint b) {\n    return a -= b;\n  }\n  friend Mint operator*(Mint a, Mint\
    \ b) {\n    return a *= b;\n  }\n  friend Mint operator/(Mint a, Mint b) {\n \
    \   return a /= b;\n  }\n  friend ostream &operator<<(ostream &os, Mint a) {\n\
    \    return os << a.v;\n  }\n};\n\n// using mi = Mint<int(1e9 + 7)>;\n// using\
    \ mi = Mint<998244353>;\n\n// vector<mi> fact, inv_fact;\n\n// void gen_fact(int\
    \ n) {\n//   fact.resize(n + 1);\n//   inv_fact.resize(n + 1);\n//   fact[0] =\
    \ fact[1] = inv_fact[0] = inv_fact[1] = 1;\n//   for (int i = 2; i <= n; i++)\
    \ {\n//     fact[i] = fact[i - 1] * i;\n//   }\n//   inv_fact[n] = 1 / fact[n];\n\
    //   for (int i = n - 1; i >= 2; i--) {\n//     inv_fact[i] = inv_fact[i + 1]\
    \ * (i + 1);\n//   }\n// }\n\n// mi nck(int n, int k) {\n//   if (n < k || k <\
    \ 0) {\n//     return 0;\n//   }\n//   return fact[n] * inv_fact[k] * inv_fact[n\
    \ - k];\n// }\n#line 5 \"verify/aizu/ntl/power.test.cpp\"\n\nusing mi = Mint<1000000007>;\n\
    \nint main() {\n  int m, n;\n  cin >> m >> n;\n  cout << pow(mi(m), n) << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../numeric/mint.h\"\
    \n\nusing mi = Mint<1000000007>;\n\nint main() {\n  int m, n;\n  cin >> m >> n;\n\
    \  cout << pow(mi(m), n) << '\\n';\n}"
  dependsOn:
  - template/template.h
  - numeric/mint.h
  isVerificationFile: true
  path: verify/aizu/ntl/power.test.cpp
  requiredBy: []
  timestamp: '2025-09-06 19:45:01-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/aizu/ntl/power.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/ntl/power.test.cpp
- /verify/verify/aizu/ntl/power.test.cpp.html
title: verify/aizu/ntl/power.test.cpp
---
