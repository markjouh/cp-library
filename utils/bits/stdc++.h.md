---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rmq.test.cpp
    title: verify/aizu/dsl/rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/dsl/rsq_and_raq.test.cpp
    title: verify/aizu/dsl/rsq_and_raq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/aizu/ntl/power.test.cpp
    title: verify/aizu/ntl/power.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/associative_array.test.cpp
    title: verify/library_checker/data_structure/associative_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/point_add_range_sum.test.cpp
    title: verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
    title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/set_xor_min.test.cpp
    title: verify/library_checker/data_structure/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
    title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/static_rmq.test.cpp
    title: verify/library_checker/data_structure/static_rmq.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/unionfind.test.cpp
    title: verify/library_checker/data_structure/unionfind.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/scc.test.cpp
    title: verify/library_checker/graph/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/graph/shortest_path.test.cpp
    title: verify/library_checker/graph/shortest_path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/number_theory/enumerate_primes.test.cpp
    title: verify/library_checker/number_theory/enumerate_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/string/suffix_array.test.cpp
    title: verify/library_checker/string/suffix_array.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/lca.test.cpp
    title: verify/library_checker/tree/lca.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
    title: verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
    title: verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - http://www.gnu.org/licenses/>.
  bundledCode: "#line 1 \"utils/bits/stdc++.h\"\n// C++ includes used for precompiling\
    \ -*- C++ -*-\n\n// Copyright (C) 2003-2022 Free Software Foundation, Inc.\n//\n\
    // This file is part of the GNU ISO C++ Library.  This library is free\n// software;\
    \ you can redistribute it and/or modify it under the\n// terms of the GNU General\
    \ Public License as published by the\n// Free Software Foundation; either version\
    \ 3, or (at your option)\n// any later version.\n\n// This library is distributed\
    \ in the hope that it will be useful,\n// but WITHOUT ANY WARRANTY; without even\
    \ the implied warranty of\n// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\
    \  See the\n// GNU General Public License for more details.\n\n// Under Section\
    \ 7 of GPL version 3, you are granted additional\n// permissions described in\
    \ the GCC Runtime Library Exception, version\n// 3.1, as published by the Free\
    \ Software Foundation.\n\n// You should have received a copy of the GNU General\
    \ Public License and\n// a copy of the GCC Runtime Library Exception along with\
    \ this program;\n// see the files COPYING3 and COPYING.RUNTIME respectively. \
    \ If not, see\n// <http://www.gnu.org/licenses/>.\n\n/** @file stdc++.h\n *  This\
    \ is an implementation file for a precompiled header.\n */\n\n// 17.4.1.2 Headers\n\
    \n// C\n#ifndef _GLIBCXX_NO_ASSERT\n#include <cassert>\n#endif\n#include <cctype>\n\
    #include <cerrno>\n#include <cfloat>\n#include <ciso646>\n#include <climits>\n\
    #include <clocale>\n#include <cmath>\n#include <csetjmp>\n#include <csignal>\n\
    #include <cstdarg>\n#include <cstddef>\n#include <cstdio>\n#include <cstdlib>\n\
    #include <cstring>\n#include <ctime>\n#include <cwchar>\n#include <cwctype>\n\n\
    #if __cplusplus >= 201103L\n#include <ccomplex>\n#include <cfenv>\n#include <cinttypes>\n\
    #include <cstdbool>\n#include <cstdint>\n#include <ctgmath>\n#endif\n\n// C++\n\
    #include <algorithm>\n#include <bitset>\n#include <complex>\n#include <deque>\n\
    #include <exception>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n\
    #include <ios>\n#include <iosfwd>\n#include <iostream>\n#include <istream>\n#include\
    \ <iterator>\n#include <limits>\n#include <list>\n#include <locale>\n#include\
    \ <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n\
    #include <queue>\n#include <set>\n#include <sstream>\n#include <stack>\n#include\
    \ <stdexcept>\n#include <streambuf>\n#include <string>\n#include <typeinfo>\n\
    #include <utility>\n#include <valarray>\n#include <vector>\n\n#if __cplusplus\
    \ >= 201103L\n#include <array>\n#include <atomic>\n#include <chrono>\n#include\
    \ <codecvt>\n#include <condition_variable>\n#include <forward_list>\n#include\
    \ <future>\n#include <initializer_list>\n#include <mutex>\n#include <random>\n\
    #include <ratio>\n#include <regex>\n#include <scoped_allocator>\n#include <system_error>\n\
    #include <thread>\n#include <tuple>\n#include <typeindex>\n#include <type_traits>\n\
    #include <unordered_map>\n#include <unordered_set>\n#endif\n\n#if __cplusplus\
    \ >= 201402L\n#include <shared_mutex>\n#endif\n\n#if __cplusplus >= 201703L\n\
    #include <any>\n#include <charconv>\n// #include <execution>\n#include <filesystem>\n\
    #include <optional>\n#include <string_view>\n#include <variant>\n#endif\n\n#if\
    \ __cplusplus >= 202002L\n#include <barrier>\n#include <bit>\n#include <compare>\n\
    #include <concepts>\n#include <latch>\n#include <numbers>\n#include <ranges>\n\
    #include <span>\n#include <semaphore>\n#include <version>\n#endif\n\n#if __cplusplus\
    \ > 202002L\n#endif\n"
  code: "// C++ includes used for precompiling -*- C++ -*-\n\n// Copyright (C) 2003-2022\
    \ Free Software Foundation, Inc.\n//\n// This file is part of the GNU ISO C++\
    \ Library.  This library is free\n// software; you can redistribute it and/or\
    \ modify it under the\n// terms of the GNU General Public License as published\
    \ by the\n// Free Software Foundation; either version 3, or (at your option)\n\
    // any later version.\n\n// This library is distributed in the hope that it will\
    \ be useful,\n// but WITHOUT ANY WARRANTY; without even the implied warranty of\n\
    // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n// GNU General\
    \ Public License for more details.\n\n// Under Section 7 of GPL version 3, you\
    \ are granted additional\n// permissions described in the GCC Runtime Library\
    \ Exception, version\n// 3.1, as published by the Free Software Foundation.\n\n\
    // You should have received a copy of the GNU General Public License and\n// a\
    \ copy of the GCC Runtime Library Exception along with this program;\n// see the\
    \ files COPYING3 and COPYING.RUNTIME respectively.  If not, see\n// <http://www.gnu.org/licenses/>.\n\
    \n/** @file stdc++.h\n *  This is an implementation file for a precompiled header.\n\
    \ */\n\n// 17.4.1.2 Headers\n\n// C\n#ifndef _GLIBCXX_NO_ASSERT\n#include <cassert>\n\
    #endif\n#include <cctype>\n#include <cerrno>\n#include <cfloat>\n#include <ciso646>\n\
    #include <climits>\n#include <clocale>\n#include <cmath>\n#include <csetjmp>\n\
    #include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include <cstdio>\n\
    #include <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <cwchar>\n\
    #include <cwctype>\n\n#if __cplusplus >= 201103L\n#include <ccomplex>\n#include\
    \ <cfenv>\n#include <cinttypes>\n#include <cstdbool>\n#include <cstdint>\n#include\
    \ <ctgmath>\n#endif\n\n// C++\n#include <algorithm>\n#include <bitset>\n#include\
    \ <complex>\n#include <deque>\n#include <exception>\n#include <fstream>\n#include\
    \ <functional>\n#include <iomanip>\n#include <ios>\n#include <iosfwd>\n#include\
    \ <iostream>\n#include <istream>\n#include <iterator>\n#include <limits>\n#include\
    \ <list>\n#include <locale>\n#include <map>\n#include <memory>\n#include <new>\n\
    #include <numeric>\n#include <ostream>\n#include <queue>\n#include <set>\n#include\
    \ <sstream>\n#include <stack>\n#include <stdexcept>\n#include <streambuf>\n#include\
    \ <string>\n#include <typeinfo>\n#include <utility>\n#include <valarray>\n#include\
    \ <vector>\n\n#if __cplusplus >= 201103L\n#include <array>\n#include <atomic>\n\
    #include <chrono>\n#include <codecvt>\n#include <condition_variable>\n#include\
    \ <forward_list>\n#include <future>\n#include <initializer_list>\n#include <mutex>\n\
    #include <random>\n#include <ratio>\n#include <regex>\n#include <scoped_allocator>\n\
    #include <system_error>\n#include <thread>\n#include <tuple>\n#include <typeindex>\n\
    #include <type_traits>\n#include <unordered_map>\n#include <unordered_set>\n#endif\n\
    \n#if __cplusplus >= 201402L\n#include <shared_mutex>\n#endif\n\n#if __cplusplus\
    \ >= 201703L\n#include <any>\n#include <charconv>\n// #include <execution>\n#include\
    \ <filesystem>\n#include <optional>\n#include <string_view>\n#include <variant>\n\
    #endif\n\n#if __cplusplus >= 202002L\n#include <barrier>\n#include <bit>\n#include\
    \ <compare>\n#include <concepts>\n#include <latch>\n#include <numbers>\n#include\
    \ <ranges>\n#include <span>\n#include <semaphore>\n#include <version>\n#endif\n\
    \n#if __cplusplus > 202002L\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: utils/bits/stdc++.h
  requiredBy:
  - template/template.h
  timestamp: '2024-11-16 20:34:38-05:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/aizu/alds1/number_of_inversions.test.cpp
  - verify/aizu/ntl/power.test.cpp
  - verify/aizu/dsl/rmq.test.cpp
  - verify/aizu/dsl/rsq_and_raq.test.cpp
  - verify/library_checker/number_theory/enumerate_primes.test.cpp
  - verify/library_checker/data_structure/static_rmq.test.cpp
  - verify/library_checker/data_structure/set_xor_min.test.cpp
  - verify/library_checker/data_structure/point_add_range_sum.test.cpp
  - verify/library_checker/data_structure/unionfind.test.cpp
  - verify/library_checker/data_structure/static_range_mode_query.test.cpp
  - verify/library_checker/data_structure/range_kth_smallest.test.cpp
  - verify/library_checker/data_structure/associative_array.test.cpp
  - verify/library_checker/string/suffix_array.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
  - verify/library_checker/graph/shortest_path.test.cpp
  - verify/library_checker/graph/scc.test.cpp
  - verify/library_checker/tree/rooted_tree_isomorphism.test.cpp
  - verify/library_checker/tree/lca.test.cpp
  - verify/library_checker/tree/vertex_add_subtree_sum.test.cpp
documentation_of: utils/bits/stdc++.h
layout: document
redirect_from:
- /library/utils/bits/stdc++.h
- /library/utils/bits/stdc++.h.html
title: utils/bits/stdc++.h
---
