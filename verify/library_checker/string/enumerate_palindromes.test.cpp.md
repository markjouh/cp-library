---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: numeric/binsearch.h
    title: numeric/binsearch.h
  - icon: ':x:'
    path: strings/hashing.h
    title: strings/hashing.h
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"verify/library_checker/string/enumerate_palindromes.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n\
    #line 1 \"template/template.h\"\n#include <algorithm>\n#include <array>\n#include\
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
    \ namespace std;\n#line 1 \"numeric/binsearch.h\"\ntemplate <class T, class U>\n\
    T bsmin(T lo, T hi, U f) {\n  assert(lo <= hi);\n  hi++;\n  for (T i = T(1) <<\
    \ __lg(hi - lo); i > 0; i >>= 1) {\n    hi -= (hi - i >= lo && f(hi - i)) * i;\n\
    \  }\n  return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f)\
    \ {\n  assert(lo <= hi);\n  lo--;\n  for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n    lo += (lo + i <= hi && f(lo + i)) * i;\n  }\n  return lo;\n\
    }\n#line 1 \"strings/hashing.h\"\nnamespace hashing {\n\nmt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
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
  timestamp: '2025-09-06 19:45:01-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/string/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp
- /verify/verify/library_checker/string/enumerate_palindromes.test.cpp.html
title: verify/library_checker/string/enumerate_palindromes.test.cpp
---
