---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/hash_table.h
    title: src/datastructures/hash_table.h
  - icon: ':heavy_check_mark:'
    path: src/datastructures/static/mo_handler.h
    title: src/datastructures/static/mo_handler.h
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_mode_query
    links:
    - https://judge.yosupo.jp/problem/static_range_mode_query
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/static_range_mode_query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\n\
    \n#line 1 \"src/template/template.h\"\n#include <algorithm>\n#include <array>\n\
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
    \ <mutex>\n#include <scoped_allocator>\n#line 71 \"src/template/template.h\"\n\
    #include <typeindex>\n\n// C++14\n#include <shared_mutex>\n\n// C++17\n#if __cplusplus\
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
    \ namespace std;\n#line 1 \"src/datastructures/hash_table.h\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nstruct CustomHash {\n  static uint64_t splitmix64(uint64_t x) {\n    x += 0x9e3779b97f4a7c15;\n\
    \    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return x ^ (x >> 31);\n  }\n\n  size_t operator()(uint64_t x) const {\n \
    \   static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return splitmix64(x + FIXED_RANDOM);\n  }\n};\n\ntemplate <class T, class\
    \ U>\nusing hash_table = __gnu_pbds::gp_hash_table<T, U, CustomHash>;\n#line 1\
    \ \"src/datastructures/static/mo_handler.h\"\ntemplate <int K>\nstruct MoHandler\
    \ {\n  vector<array<int, 3>> queries;\n \n  MoHandler() {}\n \n  void add(int\
    \ l, int r) {\n    queries.push_back({l, r, int(queries.size())});\n  }\n \n \
    \ template <class F1, class F2, class F3, class F4, class F5>\n  void run(F1 add_l,\
    \ F2 del_l, F3 add_r, F4 del_r, F5 answer) {\n    sort(queries.begin(), queries.end(),\
    \ [](array<int, 3> a, array<int, 3> b) {\n      if (a[1] / K != b[1] / K) {\n\
    \        return a[1] / K < b[1] / K;\n      }\n      return a[0] < b[0];\n   \
    \ });\n \n    int cur_l = 0, cur_r = -1;\n    for (auto [l, r, idx] : queries)\
    \ {\n      while (cur_l > l) {\n        add_l(--cur_l);\n      }\n      while\
    \ (cur_r < r) {\n        add_r(++cur_r);\n      }\n      while (cur_l < l) {\n\
    \        del_l(cur_l++);\n      }\n      while (cur_r > r) {\n        del_r(cur_r--);\n\
    \      }\n      answer(idx);\n    }\n  }\n \n  template <class F1, class F2, class\
    \ F3>\n  void run(F1 add, F2 del, F3 answer) {\n    run<F1, F2, F1, F2, F3>(add,\
    \ del, add, del, answer);\n  }\n};\n#line 6 \"src/verify/library_checker/data_structure/static_range_mode_query.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int\
    \ i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  MoHandler<300> mo;\n  for (int\
    \ i = 0; i < q; i++) {\n    int l, r;\n    cin >> l >> r;\n    mo.add(l, r - 1);\n\
    \  }\n\n  hash_table<int, int> freq;\n  set<pair<int, int>> st;\n\n  auto add\
    \ = [&](int p) {\n    if (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]],\
    \ a[p]});\n    }\n    freq[a[p]]++;\n    st.insert({freq[a[p]], a[p]});\n  };\n\
    \n  auto del = [&](int p) {\n    if (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]],\
    \ a[p]});\n    }\n    freq[a[p]]--;\n    st.insert({freq[a[p]], a[p]});\n  };\n\
    \n  vector<pair<int, int>> ans(q);\n\n  auto query = [&](int idx) {\n    ans[idx]\
    \ = make_pair(rbegin(st)->second, rbegin(st)->first);\n  };\n\n  mo.run(add, del,\
    \ query);\n  for (auto [x, y] : ans) {\n    cout << x << ' ' << y << '\\n';\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../datastructures/hash_table.h\"\
    \n#include \"../../../datastructures/static/mo_handler.h\"\n\nint main() {\n \
    \ int n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    cin >> a[i];\n  }\n  MoHandler<300> mo;\n  for (int i = 0; i < q; i++)\
    \ {\n    int l, r;\n    cin >> l >> r;\n    mo.add(l, r - 1);\n  }\n\n  hash_table<int,\
    \ int> freq;\n  set<pair<int, int>> st;\n\n  auto add = [&](int p) {\n    if (freq.find(a[p])\
    \ != freq.end()) {\n      st.extract({freq[a[p]], a[p]});\n    }\n    freq[a[p]]++;\n\
    \    st.insert({freq[a[p]], a[p]});\n  };\n\n  auto del = [&](int p) {\n    if\
    \ (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]], a[p]});\n \
    \   }\n    freq[a[p]]--;\n    st.insert({freq[a[p]], a[p]});\n  };\n\n  vector<pair<int,\
    \ int>> ans(q);\n\n  auto query = [&](int idx) {\n    ans[idx] = make_pair(rbegin(st)->second,\
    \ rbegin(st)->first);\n  };\n\n  mo.run(add, del, query);\n  for (auto [x, y]\
    \ : ans) {\n    cout << x << ' ' << y << '\\n';\n  }\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/hash_table.h
  - src/datastructures/static/mo_handler.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
- /verify/src/verify/library_checker/data_structure/static_range_mode_query.test.cpp.html
title: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
---
