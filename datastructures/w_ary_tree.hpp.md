---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/priority_queue.test.cpp
    title: verify/aizu/alds1/priority_queue.test.cpp
  - icon: ':x:'
    path: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
    title: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/w_ary_tree.hpp\"\n\ntemplate<int N> struct\
    \ w_ary_tree {\n    uint32_t freq[N];\n    uint64_t l0[(N >> 6) + 1], l1[(N >>\
    \ 12) + 1], root;\n\n    w_ary_tree() {\n        memset(freq, 0, sizeof freq);\n\
    \        memset(l0, 0, sizeof l0);\n        memset(l1, 0, sizeof l1);\n      \
    \  root = 0;\n    }\n\n    void insert(int x) {\n        freq[x]++;\n        if\
    \ (freq[x] == 1) {\n            l0[x >> 6] |= 1ull << (x & 63);\n            if\
    \ (__builtin_popcountll(l0[x >> 6]) == 1) {\n                l1[x >> 12] |= 1ull\
    \ << ((x >> 6) & 63);\n                if (__builtin_popcountll(l1[x >> 12]) ==\
    \ 1) {\n                    root |= 1ull << ((x >> 12) & 63);\n              \
    \  }\n            }\n        }\n    }\n\n    void extract(int x) {\n        freq[x]--;\n\
    \        if (freq[x] == 0) {\n            l0[x >> 6] ^= 1ull << (x & 63);\n  \
    \          if (__builtin_popcountll(l0[x >> 6]) == 0) {\n                l1[x\
    \ >> 12] ^= 1ull << ((x >> 6) & 63);\n                if (__builtin_popcountll(l1[x\
    \ >> 12]) == 0) {\n                    root ^= 1ull << ((x >> 12) & 63);\n   \
    \             }\n            }\n        }\n    }\n\n    int get_min() {\n    \
    \    uint32_t p = __builtin_ctzll(root);\n        p = (p << 6) + __builtin_ctzll(l1[p]);\n\
    \        p = (p << 6) + __builtin_ctzll(l0[p]);\n        return p;\n    }\n\n\
    \    int get_max() {\n        uint32_t p = 63 - __builtin_clzll(root);\n     \
    \   p = (p << 6) + 63 - __builtin_clzll(l1[p]);\n        p = (p << 6) + 63 - __builtin_clzll(l0[p]);\n\
    \        return p;\n    }\n};\n"
  code: "#pragma once\n\ntemplate<int N> struct w_ary_tree {\n    uint32_t freq[N];\n\
    \    uint64_t l0[(N >> 6) + 1], l1[(N >> 12) + 1], root;\n\n    w_ary_tree() {\n\
    \        memset(freq, 0, sizeof freq);\n        memset(l0, 0, sizeof l0);\n  \
    \      memset(l1, 0, sizeof l1);\n        root = 0;\n    }\n\n    void insert(int\
    \ x) {\n        freq[x]++;\n        if (freq[x] == 1) {\n            l0[x >> 6]\
    \ |= 1ull << (x & 63);\n            if (__builtin_popcountll(l0[x >> 6]) == 1)\
    \ {\n                l1[x >> 12] |= 1ull << ((x >> 6) & 63);\n               \
    \ if (__builtin_popcountll(l1[x >> 12]) == 1) {\n                    root |= 1ull\
    \ << ((x >> 12) & 63);\n                }\n            }\n        }\n    }\n\n\
    \    void extract(int x) {\n        freq[x]--;\n        if (freq[x] == 0) {\n\
    \            l0[x >> 6] ^= 1ull << (x & 63);\n            if (__builtin_popcountll(l0[x\
    \ >> 6]) == 0) {\n                l1[x >> 12] ^= 1ull << ((x >> 6) & 63);\n  \
    \              if (__builtin_popcountll(l1[x >> 12]) == 0) {\n               \
    \     root ^= 1ull << ((x >> 12) & 63);\n                }\n            }\n  \
    \      }\n    }\n\n    int get_min() {\n        uint32_t p = __builtin_ctzll(root);\n\
    \        p = (p << 6) + __builtin_ctzll(l1[p]);\n        p = (p << 6) + __builtin_ctzll(l0[p]);\n\
    \        return p;\n    }\n\n    int get_max() {\n        uint32_t p = 63 - __builtin_clzll(root);\n\
    \        p = (p << 6) + 63 - __builtin_clzll(l1[p]);\n        p = (p << 6) + 63\
    \ - __builtin_clzll(l0[p]);\n        return p;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/w_ary_tree.hpp
  requiredBy: []
  timestamp: '2024-08-26 22:02:11-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aizu/alds1/priority_queue.test.cpp
  - verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
documentation_of: datastructures/w_ary_tree.hpp
layout: document
redirect_from:
- /library/datastructures/w_ary_tree.hpp
- /library/datastructures/w_ary_tree.hpp.html
title: datastructures/w_ary_tree.hpp
---
