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
    \ i) & 1;\n      if (nxt[pos][dir] == -1) {\n        nxt[pos][dir] = ssize(nxt);\n\
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
    \  nxt[pos][dir] = ssize(nxt);\n        nxt.push_back({-1, -1});\n        cnt.push_back(0);\n\
    \      }\n      pos = nxt[pos][dir];\n      cnt[pos] += v;\n    }\n  }\n\n  BinaryTrie\
    \ &operator^=(T x) {\n    filter ^= x;\n    return *this;\n  }\n\n  T min_xor(T\
    \ x) {\n    x ^= filter;\n    int pos = 0;\n    T res = 0;\n    for (int i = W\
    \ - 1; i >= 0; i--) {\n      bool dir = (x >> i) & 1;\n      if (nxt[pos][dir]\
    \ == -1 || cnt[nxt[pos][dir]] == 0) {\n        res |= T(1) << i;\n        pos\
    \ = nxt[pos][dir ^ 1];\n      } else {\n        pos = nxt[pos][dir];\n      }\n\
    \    }\n    return res;\n  }\n\n  T max_xor(T x) {\n    static const T mask =\
    \ -1;\n    return mask ^ min_xor(x ^ mask);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/binary_trie.h
  requiredBy: []
  timestamp: '2025-09-14 12:12:28-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/data_structure/set_xor_min.test.cpp
documentation_of: src/datastructures/binary_trie.h
layout: document
title: Binary Trie
---

Binary trie for efficient XOR queries on integers with global XOR filter support.

## Operations

- `BinaryTrie<T>()`: Create empty trie for type `T`
- `insert(x, v=1)`: Add `v` to count of integer `x` (use `v=-1` to remove)
- `min_xor(x)`: Find minimum XOR of `x` with any element in trie
- `max_xor(x)`: Find maximum XOR of `x` with any element in trie
- `operator^=(x)`: Apply global XOR filter to all elements

## Complexity

- All operations: $O(W)$ where $W$ is bit width of type `T`
- Space: $O(k \cdot W)$ where $k$ is number of unique elements

## Usage

```cpp
BinaryTrie<int> trie;
trie.insert(5);   // Add 5
trie.insert(3);   // Add 3
trie.insert(7);   // Add 7

int mn = trie.min_xor(2);  // Min XOR with 2
int mx = trie.max_xor(2);  // Max XOR with 2

trie.insert(5, -1);  // Remove one occurrence of 5

trie ^= 4;  // XOR all elements by 4 (lazy, O(1))
```

## Notes

Bit width `W` is `sizeof(T) * 8` (32 for `int`, 64 for `long long`). The `^=` operator applies a lazy XOR filter without modifying the trie structure.
