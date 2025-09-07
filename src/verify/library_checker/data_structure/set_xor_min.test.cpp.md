---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/binary_trie.h
    title: src/datastructures/binary_trie.h
  - icon: ':heavy_check_mark:'
    path: src/template/template.h
    title: src/template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 1 \"\
    src/template/template.h\"\n#include <algorithm>\n#include <array>\n#include <bitset>\n\
    #include <cassert>\n#include <cctype>\n#include <cerrno>\n#include <cfloat>\n\
    #include <chrono>\n#include <climits>\n#include <clocale>\n#include <cmath>\n\
    #include <complex>\n#include <csetjmp>\n#include <csignal>\n#include <cstdarg>\n\
    #include <cstddef>\n#include <cstdint>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <ctime>\n#include <cwchar>\n#include <cwctype>\n\
    #include <deque>\n#include <exception>\n#include <forward_list>\n#include <fstream>\n\
    #include <functional>\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n\
    #include <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n\
    #include <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include\
    \ <new>\n#include <numeric>\n#include <ostream>\n#include <queue>\n#include <random>\n\
    #include <ratio>\n#include <regex>\n#include <set>\n#include <sstream>\n#include\
    \ <stack>\n#include <stdexcept>\n#include <streambuf>\n#include <string>\n#include\
    \ <thread>\n#include <tuple>\n#include <type_traits>\n#include <typeinfo>\n#include\
    \ <unordered_map>\n#include <unordered_set>\n#include <utility>\n#include <valarray>\n\
    #include <vector>\n\n// C++11\n#include <atomic>\n#include <condition_variable>\n\
    #include <future>\n#include <initializer_list>\n#include <mutex>\n#include <scoped_allocator>\n\
    #line 71 \"src/template/template.h\"\n#include <typeindex>\n\n// C++14\n#include\
    \ <shared_mutex>\n\n// C++17\n#if __cplusplus >= 201703L\n#include <any>\n#include\
    \ <charconv>\n#include <execution>\n#include <filesystem>\n#include <memory_resource>\n\
    #include <optional>\n#include <string_view>\n#include <variant>\n#endif\n\n#define\
    \ sz(x) int(size(x))\n#define all(x) begin(x), end(x)\n\n// Portable builtin implementations\
    \ for compilers that don't have them\n// __lg(x) - returns floor(log2(x)) for\
    \ x > 0\n#ifndef __has_builtin\n  #define __has_builtin(x) 0\n#endif\n\n#if !__has_builtin(__lg)\n\
    \  inline int __lg(int x) {\n    assert(x > 0);\n    int r = 0;\n    while (x\
    \ >>= 1) r++;\n    return r;\n  }\n  inline int __lg(unsigned int x) {\n    assert(x\
    \ > 0);\n    int r = 0;\n    while (x >>= 1) r++;\n    return r;\n  }\n  inline\
    \ int __lg(long long x) {\n    assert(x > 0);\n    int r = 0;\n    while (x >>=\
    \ 1) r++;\n    return r;\n  }\n  inline int __lg(unsigned long long x) {\n   \
    \ assert(x > 0);\n    int r = 0;\n    while (x >>= 1) r++;\n    return r;\n  }\n\
    #endif\n\n// __builtin_popcount - count number of set bits\n#if !__has_builtin(__builtin_popcount)\n\
    \  inline int __builtin_popcount(unsigned int x) {\n    int c = 0;\n    while\
    \ (x) { c++; x &= x - 1; }\n    return c;\n  }\n#endif\n\n#if !__has_builtin(__builtin_popcountll)\n\
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
    \ namespace std;\n#line 1 \"src/datastructures/binary_trie.h\"\ntemplate <class\
    \ T>\nstruct BinaryTrie {\n  static const int W = sizeof(T) * 8;\n  vector<array<int,\
    \ 2>> nxt;\n  vector<int> cnt;\n  T filter = 0;\n\n  BinaryTrie() : nxt(1, {-1,\
    \ -1}), cnt(1, 0) {}\n\n  void insert(T x, int v = 1) {\n    x ^= filter;\n  \
    \  int pos = 0;\n    for (int i = W - 1; i >= 0; i--) {\n      bool dir = (x >>\
    \ i) & 1;\n      if (nxt[pos][dir] == -1) {\n        nxt[pos][dir] = sz(nxt);\n\
    \        nxt.push_back({-1, -1});\n        cnt.push_back(0);\n      }\n      pos\
    \ = nxt[pos][dir];\n      cnt[pos] += v;\n    }\n  }\n\n  BinaryTrie &operator^=(T\
    \ x) {\n    filter ^= x;\n    return *this;\n  }\n\n  T min_xor(T x) {\n    x\
    \ ^= filter;\n    int pos = 0;\n    T res = 0;\n    for (int i = W - 1; i >= 0;\
    \ i--) {\n      bool dir = (x >> i) & 1;\n      if (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]]\
    \ == 0) {\n        res |= T(1) << i;\n        pos = nxt[pos][dir ^ 1];\n     \
    \ } else {\n        pos = nxt[pos][dir];\n      }\n    }\n    return res;\n  }\n\
    \n  T max_xor(T x) {\n    static const T mask = -1;\n    return mask ^ min_xor(x\
    \ ^ mask);\n  }\n};\n#line 5 \"src/verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n\nint main() {\n  int q;\n  cin >> q;\n  BinaryTrie<uint32_t> bt;\n  while (q--)\
    \ {\n    int t, x;\n    cin >> t >> x;\n    if (t == 0) {\n      if (bt.min_xor(x)\
    \ != 0) {\n        bt.insert(x);\n      }\n    } else if (t == 1) {\n      if\
    \ (bt.min_xor(x) == 0) {\n        bt.insert(x, -1);\n      }\n    } else {\n \
    \     cout << bt.min_xor(x) << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../datastructures/binary_trie.h\"\
    \n\nint main() {\n  int q;\n  cin >> q;\n  BinaryTrie<uint32_t> bt;\n  while (q--)\
    \ {\n    int t, x;\n    cin >> t >> x;\n    if (t == 0) {\n      if (bt.min_xor(x)\
    \ != 0) {\n        bt.insert(x);\n      }\n    } else if (t == 1) {\n      if\
    \ (bt.min_xor(x) == 0) {\n        bt.insert(x, -1);\n      }\n    } else {\n \
    \     cout << bt.min_xor(x) << '\\n';\n    }\n  }\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/binary_trie.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/set_xor_min.test.cpp
- /verify/src/verify/library_checker/data_structure/set_xor_min.test.cpp.html
title: src/verify/library_checker/data_structure/set_xor_min.test.cpp
---
