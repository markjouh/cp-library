---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':x:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  - icon: ':x:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
  - icon: ':x:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  - icon: ':x:'
    path: verify/aizu/ntl/power.test.cpp
    title: verify/aizu/ntl/power.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/associative_array.test.cpp
    title: verify/library_checker/data_structure/associative_array.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/set_xor_min.test.cpp
    title: verify/library_checker/data_structure/set_xor_min.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
  - icon: ':x:'
    path: verify/library_checker/graph/scc.test.cpp
    title: verify/library_checker/graph/scc.test.cpp
  - icon: ':x:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':x:'
    path: verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: verify/library_checker/number_theory/enumerate_primes.test.cpp
  - icon: ':x:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/binlift_lca.test.cpp
    title: verify/library_checker/tree/binlift_lca.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/fast_lca.test.cpp
    title: verify/library_checker/tree/fast_lca.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - icon: ':x:'
    path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"template/template.h\"\n#include <algorithm>\n#include <array>\n\
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
    \ namespace std;\n"
  code: "#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cerrno>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <climits>\n#include <clocale>\n#include <cmath>\n#include <complex>\n#include\
    \ <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <cwchar>\n#include <cwctype>\n#include <deque>\n#include <exception>\n\
    #include <forward_list>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n\
    #include <ios>\n#include <iosfwd>\n#include <iostream>\n#include <istream>\n#include\
    \ <iterator>\n#include <limits>\n#include <list>\n#include <locale>\n#include\
    \ <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n\
    #include <queue>\n#include <random>\n#include <ratio>\n#include <regex>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <thread>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <valarray>\n#include <vector>\n\n// C++11\n#include\
    \ <atomic>\n#include <condition_variable>\n#include <future>\n#include <initializer_list>\n\
    #include <mutex>\n#include <scoped_allocator>\n#include <thread>\n#include <typeindex>\n\
    \n// C++14\n#include <shared_mutex>\n\n// C++17\n#if __cplusplus >= 201703L\n\
    #include <any>\n#include <charconv>\n#include <execution>\n#include <filesystem>\n\
    #include <memory_resource>\n#include <optional>\n#include <string_view>\n#include\
    \ <variant>\n#endif\n\n#define sz(x) int(size(x))\n#define all(x) begin(x), end(x)\n\
    \n// Portable builtin implementations for compilers that don't have them\n// __lg(x)\
    \ - returns floor(log2(x)) for x > 0\n#ifndef __has_builtin\n  #define __has_builtin(x)\
    \ 0\n#endif\n\n#if !__has_builtin(__lg)\n  inline int __lg(int x) {\n    assert(x\
    \ > 0);\n    int r = 0;\n    while (x >>= 1) r++;\n    return r;\n  }\n  inline\
    \ int __lg(unsigned int x) {\n    assert(x > 0);\n    int r = 0;\n    while (x\
    \ >>= 1) r++;\n    return r;\n  }\n  inline int __lg(long long x) {\n    assert(x\
    \ > 0);\n    int r = 0;\n    while (x >>= 1) r++;\n    return r;\n  }\n  inline\
    \ int __lg(unsigned long long x) {\n    assert(x > 0);\n    int r = 0;\n    while\
    \ (x >>= 1) r++;\n    return r;\n  }\n#endif\n\n// __builtin_popcount - count\
    \ number of set bits\n#if !__has_builtin(__builtin_popcount)\n  inline int __builtin_popcount(unsigned\
    \ int x) {\n    int c = 0;\n    while (x) { c++; x &= x - 1; }\n    return c;\n\
    \  }\n#endif\n\n#if !__has_builtin(__builtin_popcountll)\n  inline int __builtin_popcountll(unsigned\
    \ long long x) {\n    int c = 0;\n    while (x) { c++; x &= x - 1; }\n    return\
    \ c;\n  }\n#endif\n\n// __builtin_clz - count leading zeros (undefined for x=0)\n\
    #if !__has_builtin(__builtin_clz)\n  inline int __builtin_clz(unsigned int x)\
    \ {\n    assert(x != 0);\n    int c = 0;\n    if (x <= 0x0000FFFF) { c += 16;\
    \ x <<= 16; }\n    if (x <= 0x00FFFFFF) { c += 8; x <<= 8; }\n    if (x <= 0x0FFFFFFF)\
    \ { c += 4; x <<= 4; }\n    if (x <= 0x3FFFFFFF) { c += 2; x <<= 2; }\n    if\
    \ (x <= 0x7FFFFFFF) { c += 1; }\n    return c;\n  }\n#endif\n\n#if !__has_builtin(__builtin_clzll)\n\
    \  inline int __builtin_clzll(unsigned long long x) {\n    assert(x != 0);\n \
    \   int c = 0;\n    if (x <= 0x00000000FFFFFFFFULL) { c += 32; x <<= 32; }\n \
    \   if (x <= 0x0000FFFFFFFFFFFFULL) { c += 16; x <<= 16; }\n    if (x <= 0x00FFFFFFFFFFFFFFULL)\
    \ { c += 8; x <<= 8; }\n    if (x <= 0x0FFFFFFFFFFFFFFFULL) { c += 4; x <<= 4;\
    \ }\n    if (x <= 0x3FFFFFFFFFFFFFFFULL) { c += 2; x <<= 2; }\n    if (x <= 0x7FFFFFFFFFFFFFFFULL)\
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
    \ namespace std;"
  dependsOn: []
  isVerificationFile: false
  path: template/template.h
  requiredBy: []
  timestamp: '2025-09-06 19:45:01-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/library_checker/data_structure/set_xor_min.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/associative_array.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/data_structure/static_rmq.test.cpp
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - verify/library_checker/tree/fast_lca.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  - verify/library_checker/tree/binlift_lca.test.cpp
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/scc.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/aizu/ntl/power.test.cpp
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/aizu/alds1/number_of_inversions.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/aizu/dsl/rmq.test.cpp
documentation_of: template/template.h
layout: document
redirect_from:
- /library/template/template.h
- /library/template/template.h.html
title: template/template.h
---
