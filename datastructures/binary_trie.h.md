---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/library_checker/data_structure/set_xor_min.test.cpp
    title: verify/library_checker/data_structure/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/binary_trie.h\"\n\nstruct BinaryTrie {\n\
    \    vector<array<int, 2>> nxt;\n    vector<int> cnt;\n\n    BinaryTrie() : nxt(1,\
    \ {-1, -1}), cnt(1, 0) {}\n\n    int count(unsigned int x) {\n        int pos\
    \ = 0;\n        for (int i = 31; i >= 0; i--) {\n            pos = nxt[pos][(x\
    \ >> i) & 1];\n            if (pos == -1) {\n                return 0;\n     \
    \       }\n        }\n        return cnt[pos];\n    }\n\n    void insert(unsigned\
    \ int x) {\n        int pos = 0;\n        for (int i = 31; i >= 0; i--) {\n  \
    \          bool dir = (x >> i) & 1;\n            if (nxt[pos][dir] == -1) {\n\
    \                nxt[pos][dir] = sz(nxt);\n                nxt.push_back({-1,\
    \ -1});\n                cnt.push_back(0);\n            }\n            pos = nxt[pos][dir];\n\
    \            cnt[pos]++;\n        }\n    }\n\n    void remove(unsigned int x)\
    \ {\n        int pos = 0;\n        for (int i = 31; i >= 0; i--) {\n         \
    \   pos = nxt[pos][(x >> i) & 1];\n            cnt[pos]--;\n        }\n    }\n\
    \n    unsigned int min_xor(unsigned int x) {\n        int pos = 0;\n        unsigned\
    \ int res = 0;\n        for (int i = 31; i >= 0; i--) {\n            bool dir\
    \ = (x >> i) & 1;\n            if (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]] ==\
    \ 0) {\n                res |= 1 << i;\n                pos = nxt[pos][dir ^ 1];\n\
    \            } else {\n                pos = nxt[pos][dir];\n            }\n \
    \       }\n        return res;\n    }\n\n    unsigned int max_xor(unsigned int\
    \ x) {\n        static const unsigned int mask = -1;\n        return mask ^ min_xor(x\
    \ ^ mask);\n    }\n};\n"
  code: "#pragma once\n\nstruct BinaryTrie {\n    vector<array<int, 2>> nxt;\n   \
    \ vector<int> cnt;\n\n    BinaryTrie() : nxt(1, {-1, -1}), cnt(1, 0) {}\n\n  \
    \  int count(unsigned int x) {\n        int pos = 0;\n        for (int i = 31;\
    \ i >= 0; i--) {\n            pos = nxt[pos][(x >> i) & 1];\n            if (pos\
    \ == -1) {\n                return 0;\n            }\n        }\n        return\
    \ cnt[pos];\n    }\n\n    void insert(unsigned int x) {\n        int pos = 0;\n\
    \        for (int i = 31; i >= 0; i--) {\n            bool dir = (x >> i) & 1;\n\
    \            if (nxt[pos][dir] == -1) {\n                nxt[pos][dir] = sz(nxt);\n\
    \                nxt.push_back({-1, -1});\n                cnt.push_back(0);\n\
    \            }\n            pos = nxt[pos][dir];\n            cnt[pos]++;\n  \
    \      }\n    }\n\n    void remove(unsigned int x) {\n        int pos = 0;\n \
    \       for (int i = 31; i >= 0; i--) {\n            pos = nxt[pos][(x >> i) &\
    \ 1];\n            cnt[pos]--;\n        }\n    }\n\n    unsigned int min_xor(unsigned\
    \ int x) {\n        int pos = 0;\n        unsigned int res = 0;\n        for (int\
    \ i = 31; i >= 0; i--) {\n            bool dir = (x >> i) & 1;\n            if\
    \ (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]] == 0) {\n                res |= 1\
    \ << i;\n                pos = nxt[pos][dir ^ 1];\n            } else {\n    \
    \            pos = nxt[pos][dir];\n            }\n        }\n        return res;\n\
    \    }\n\n    unsigned int max_xor(unsigned int x) {\n        static const unsigned\
    \ int mask = -1;\n        return mask ^ min_xor(x ^ mask);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/binary_trie.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/library_checker/data_structure/set_xor_min.test.cpp
documentation_of: datastructures/binary_trie.h
layout: document
redirect_from:
- /library/datastructures/binary_trie.h
- /library/datastructures/binary_trie.h.html
title: datastructures/binary_trie.h
---
