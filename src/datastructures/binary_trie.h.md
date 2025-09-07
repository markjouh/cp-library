---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/data_structure/set_xor_min.test.cpp
    title: src/verify/library_checker/data_structure/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/binary_trie.h\"\ntemplate <class T>\n\
    struct BinaryTrie {\n  static const int W = sizeof(T) * 8;\n  vector<array<int,\
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
    \ ^ mask);\n  }\n};\n"
  code: "template <class T>\nstruct BinaryTrie {\n  static const int W = sizeof(T)\
    \ * 8;\n  vector<array<int, 2>> nxt;\n  vector<int> cnt;\n  T filter = 0;\n\n\
    \  BinaryTrie() : nxt(1, {-1, -1}), cnt(1, 0) {}\n\n  void insert(T x, int v =\
    \ 1) {\n    x ^= filter;\n    int pos = 0;\n    for (int i = W - 1; i >= 0; i--)\
    \ {\n      bool dir = (x >> i) & 1;\n      if (nxt[pos][dir] == -1) {\n      \
    \  nxt[pos][dir] = sz(nxt);\n        nxt.push_back({-1, -1});\n        cnt.push_back(0);\n\
    \      }\n      pos = nxt[pos][dir];\n      cnt[pos] += v;\n    }\n  }\n\n  BinaryTrie\
    \ &operator^=(T x) {\n    filter ^= x;\n    return *this;\n  }\n\n  T min_xor(T\
    \ x) {\n    x ^= filter;\n    int pos = 0;\n    T res = 0;\n    for (int i = W\
    \ - 1; i >= 0; i--) {\n      bool dir = (x >> i) & 1;\n      if (nxt[pos][dir]\
    \ == -1 || cnt[nxt[pos][dir]] == 0) {\n        res |= T(1) << i;\n        pos\
    \ = nxt[pos][dir ^ 1];\n      } else {\n        pos = nxt[pos][dir];\n      }\n\
    \    }\n    return res;\n  }\n\n  T max_xor(T x) {\n    static const T mask =\
    \ -1;\n    return mask ^ min_xor(x ^ mask);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/binary_trie.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/set_xor_min.test.cpp
documentation_of: src/datastructures/binary_trie.h
layout: document
title: Binary Trie
---

Binary trie for efficient XOR queries and prefix operations on integers.

## Operations

- `BinaryTrie()`: Create empty trie
- `insert(x)`: Insert integer `x`
- `erase(x)`: Remove integer `x`
- `max_xor(x)`: Find maximum XOR with any element
- `min_xor(x)`: Find minimum XOR with any element

## Complexity

- All operations: $O(\log(\text{max\_value}))$ 
- Space: $O(k \log(\text{max\_value}))$ where $k$ is number of elements

## Usage

```cpp
BinaryTrie trie;
trie.insert(5);   // 101
trie.insert(3);   // 011
trie.insert(7);   // 111

int max_xor = trie.max_xor(2); // Max XOR with 010
int min_xor = trie.min_xor(2); // Min XOR with 010
```

## Notes

Builds tree structure based on binary representation. Efficient for XOR-related queries and bit manipulation problems.

**Bit Manipulation Details**: Processes integers bit by bit from most significant to least significant. For maximum XOR, at each level it tries to take the opposite bit path when possible. The trie depth is typically 30-32 levels for 32-bit integers, making operations effectively $O(30)$ in practice.