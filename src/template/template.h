#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <chrono>
#include <climits>
#include <clocale>
#include <cmath>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <forward_list>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>

// C++11
#include <atomic>
#include <condition_variable>
#include <future>
#include <initializer_list>
#include <mutex>
#include <scoped_allocator>
#include <thread>
#include <typeindex>

// C++14
#include <shared_mutex>

// C++17
#if __cplusplus >= 201703L
#include <any>
#include <charconv>
#include <execution>
#include <filesystem>
#include <memory_resource>
#include <optional>
#include <string_view>
#include <variant>
#endif

#define sz(x) int(size(x))
#define all(x) begin(x), end(x)

// Portable builtin implementations for compilers that don't have them
// __lg(x) - returns floor(log2(x)) for x > 0
#ifndef __has_builtin
  #define __has_builtin(x) 0
#endif

#if !__has_builtin(__lg)
  inline int __lg(int x) {
    assert(x > 0);
    int r = 0;
    while (x >>= 1) r++;
    return r;
  }
  inline int __lg(unsigned int x) {
    assert(x > 0);
    int r = 0;
    while (x >>= 1) r++;
    return r;
  }
  inline int __lg(long long x) {
    assert(x > 0);
    int r = 0;
    while (x >>= 1) r++;
    return r;
  }
  inline int __lg(unsigned long long x) {
    assert(x > 0);
    int r = 0;
    while (x >>= 1) r++;
    return r;
  }
#endif

// __builtin_popcount - count number of set bits
#if !__has_builtin(__builtin_popcount)
  inline int __builtin_popcount(unsigned int x) {
    int c = 0;
    while (x) { c++; x &= x - 1; }
    return c;
  }
#endif

#if !__has_builtin(__builtin_popcountll)
  inline int __builtin_popcountll(unsigned long long x) {
    int c = 0;
    while (x) { c++; x &= x - 1; }
    return c;
  }
#endif

// __builtin_clz - count leading zeros (undefined for x=0)
#if !__has_builtin(__builtin_clz)
  inline int __builtin_clz(unsigned int x) {
    assert(x != 0);
    int c = 0;
    if (x <= 0x0000FFFF) { c += 16; x <<= 16; }
    if (x <= 0x00FFFFFF) { c += 8; x <<= 8; }
    if (x <= 0x0FFFFFFF) { c += 4; x <<= 4; }
    if (x <= 0x3FFFFFFF) { c += 2; x <<= 2; }
    if (x <= 0x7FFFFFFF) { c += 1; }
    return c;
  }
#endif

#if !__has_builtin(__builtin_clzll)
  inline int __builtin_clzll(unsigned long long x) {
    assert(x != 0);
    int c = 0;
    if (x <= 0x00000000FFFFFFFFULL) { c += 32; x <<= 32; }
    if (x <= 0x0000FFFFFFFFFFFFULL) { c += 16; x <<= 16; }
    if (x <= 0x00FFFFFFFFFFFFFFULL) { c += 8; x <<= 8; }
    if (x <= 0x0FFFFFFFFFFFFFFFULL) { c += 4; x <<= 4; }
    if (x <= 0x3FFFFFFFFFFFFFFFULL) { c += 2; x <<= 2; }
    if (x <= 0x7FFFFFFFFFFFFFFFULL) { c += 1; }
    return c;
  }
#endif

// __builtin_ctz - count trailing zeros (undefined for x=0)
#if !__has_builtin(__builtin_ctz)
  inline int __builtin_ctz(unsigned int x) {
    assert(x != 0);
    int c = 0;
    if ((x & 0x0000FFFF) == 0) { c += 16; x >>= 16; }
    if ((x & 0x000000FF) == 0) { c += 8; x >>= 8; }
    if ((x & 0x0000000F) == 0) { c += 4; x >>= 4; }
    if ((x & 0x00000003) == 0) { c += 2; x >>= 2; }
    if ((x & 0x00000001) == 0) { c += 1; }
    return c;
  }
#endif

#if !__has_builtin(__builtin_ctzll)
  inline int __builtin_ctzll(unsigned long long x) {
    assert(x != 0);
    int c = 0;
    if ((x & 0x00000000FFFFFFFFULL) == 0) { c += 32; x >>= 32; }
    if ((x & 0x000000000000FFFFULL) == 0) { c += 16; x >>= 16; }
    if ((x & 0x00000000000000FFULL) == 0) { c += 8; x >>= 8; }
    if ((x & 0x000000000000000FULL) == 0) { c += 4; x >>= 4; }
    if ((x & 0x0000000000000003ULL) == 0) { c += 2; x >>= 2; }
    if ((x & 0x0000000000000001ULL) == 0) { c += 1; }
    return c;
  }
#endif

// __builtin_parity - parity of number of set bits
#if !__has_builtin(__builtin_parity)
  inline int __builtin_parity(unsigned int x) {
    return __builtin_popcount(x) & 1;
  }
#endif

#if !__has_builtin(__builtin_parityll)
  inline int __builtin_parityll(unsigned long long x) {
    return __builtin_popcountll(x) & 1;
  }
#endif

using namespace std;