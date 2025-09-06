---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructures/merge_sort_tree.h
    title: datastructures/merge_sort_tree.h
  - icon: ':x:'
    path: datastructures/ordered_set.h
    title: datastructures/ordered_set.h
  - icon: ':x:'
    path: numeric/binsearch.h
    title: numeric/binsearch.h
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/library_checker/data_structure/range_kth_smallest.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
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
    \ namespace std;\n#line 1 \"numeric/binsearch.h\"\ntemplate <class T, class U>\n\
    T bsmin(T lo, T hi, U f) {\n  assert(lo <= hi);\n  hi++;\n  for (T i = T(1) <<\
    \ __lg(hi - lo); i > 0; i >>= 1) {\n    hi -= (hi - i >= lo && f(hi - i)) * i;\n\
    \  }\n  return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f)\
    \ {\n  assert(lo <= hi);\n  lo--;\n  for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n    lo += (lo + i <= hi && f(lo + i)) * i;\n  }\n  return lo;\n\
    }\n#line 1 \"datastructures/ordered_set.h\"\n#include <ext/pb_ds/assoc_container.hpp>\
    \ \n#include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds; \n\ntemplate\
    \ <class T>\nusing ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ntemplate <class T>\nstruct ordered_multiset {\n  int time = 0;\n  ordered_set<pair<T,\
    \ int>> st;\n\n  void insert(T x) {\n    st.insert({x, time++});\n  }\n  void\
    \ extract(T x) {\n    auto it = st.lower_bound({x, 0});\n    if (it != end(st)\
    \ && it->fi == x) {\n      st.erase(it);\n    }\n  }\n\n  T find_by_order(int\
    \ k) {\n    return (*st.find_by_order(k)).first;\n  }\n  int order_of_key(T x)\
    \ {\n    return st.order_of_key({x, 0});\n  }\n};\n#line 2 \"datastructures/merge_sort_tree.h\"\
    \n\ntemplate <class T>\nstruct MergeSortTree {\n  int n;\n  vector<ordered_set<pair<T,\
    \ int>>> st;\n \n  MergeSortTree(const vector<T> &a) : n(sz(a)), st(2 * n) {\n\
    \    for (int i = 0; i < n; i++) {\n      for (int p = i + n; p > 0; p >>= 1)\
    \ {\n        st[p].insert({a[i], i});\n      }\n    }\n  }\n \n  int query(int\
    \ l, int r, T v) {\n    int res = 0;\n    for (l += n, r += n + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n      if (l & 1) {\n        res += st[l++].order_of_key({v, 0});\n\
    \      }\n      if (r & 1) {\n        res += st[--r].order_of_key({v, 0});\n \
    \     }\n    }\n    return res;\n  }\n \n  void set(int p, T v) {\n    const auto\
    \ old = *begin(st[p + n]);\n    for (p += n; p > 0; p >>= 1) {\n      st[p].erase(old);\n\
    \      st[p].insert(v);\n    }\n  }\n};\n#line 6 \"verify/library_checker/data_structure/range_kth_smallest.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int\
    \ i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  MergeSortTree<int> mt(a);\n \
    \ while (q--) {\n    int l, r, k;\n    cin >> l >> r >> k;\n    r--;\n    cout\
    \ << bsmin(0, int(1e9), [&](int x) {\n      return mt.query(l, r, x + 1) >= k\
    \ + 1;\n    }) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../template/template.h\"\n#include \"../../../numeric/binsearch.h\"\
    \n#include \"../../../datastructures/merge_sort_tree.h\"\n\nint main() {\n  int\
    \ n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    cin >> a[i];\n  }\n  MergeSortTree<int> mt(a);\n  while (q--) {\n   \
    \ int l, r, k;\n    cin >> l >> r >> k;\n    r--;\n    cout << bsmin(0, int(1e9),\
    \ [&](int x) {\n      return mt.query(l, r, x + 1) >= k + 1;\n    }) << '\\n';\n\
    \  }\n}"
  dependsOn:
  - template/template.h
  - numeric/binsearch.h
  - datastructures/merge_sort_tree.h
  - datastructures/ordered_set.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2025-09-06 19:45:01-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp.html
title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
---
