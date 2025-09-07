---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/datastructures/w_ary_tree.h\"\nstruct Word {\n  uint64_t\
    \ mask;\n  \n  Word() : mask(0) {}\n  \n  void flip_bit(int p) {\n    mask ^=\
    \ 1ull << p;\n  }\n\n  int min_bit() {\n    return __builtin_ctzll(mask);\n  }\n\
    \n  int max_bit() {\n    return 63 - __builtin_clzll(mask);\n  }\n};\n\nstruct\
    \ WAryTreeBase : public Word {\n  bool flip(int p) {\n    bool old = mask != 0;\n\
    \    flip_bit(p);\n    return (mask != 0) != old;\n  }\n\n  int min() {\n    return\
    \ min_bit();\n  }\n\n  int max() {\n    return max_bit();\n  }\n};\n\ntemplate\
    \ <int L>\nstruct WAryTree : public Word {\n  array<conditional_t<(L > 2), WAryTree<L\
    \ - 1>, WAryTreeBase>, 64> nxt;\n\n  static constexpr int block_sz = 1ull << (6\
    \ * (L - 1));\n\n  bool flip(int p) {\n    bool old = mask != 0;\n    int block\
    \ = p / block_sz;\n    if (nxt[block].flip(p % block_sz)) {\n      flip_bit(block);\n\
    \    }\n    return (mask != 0) != old;\n  }\n\n  int get_min() {\n    int block\
    \ = min_bit();\n    return block * block_sz + nxt[block].min();\n  }\n  \n  int\
    \ get_max() {\n    int block = max_bit();\n    return block * block_sz + nxt[block].max();\n\
    \  }\n};\n"
  code: "struct Word {\n  uint64_t mask;\n  \n  Word() : mask(0) {}\n  \n  void flip_bit(int\
    \ p) {\n    mask ^= 1ull << p;\n  }\n\n  int min_bit() {\n    return __builtin_ctzll(mask);\n\
    \  }\n\n  int max_bit() {\n    return 63 - __builtin_clzll(mask);\n  }\n};\n\n\
    struct WAryTreeBase : public Word {\n  bool flip(int p) {\n    bool old = mask\
    \ != 0;\n    flip_bit(p);\n    return (mask != 0) != old;\n  }\n\n  int min()\
    \ {\n    return min_bit();\n  }\n\n  int max() {\n    return max_bit();\n  }\n\
    };\n\ntemplate <int L>\nstruct WAryTree : public Word {\n  array<conditional_t<(L\
    \ > 2), WAryTree<L - 1>, WAryTreeBase>, 64> nxt;\n\n  static constexpr int block_sz\
    \ = 1ull << (6 * (L - 1));\n\n  bool flip(int p) {\n    bool old = mask != 0;\n\
    \    int block = p / block_sz;\n    if (nxt[block].flip(p % block_sz)) {\n   \
    \   flip_bit(block);\n    }\n    return (mask != 0) != old;\n  }\n\n  int get_min()\
    \ {\n    int block = min_bit();\n    return block * block_sz + nxt[block].min();\n\
    \  }\n  \n  int get_max() {\n    int block = max_bit();\n    return block * block_sz\
    \ + nxt[block].max();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructures/w_ary_tree.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructures/w_ary_tree.h
layout: document
title: W-ary Tree
---

Generalized segment tree with configurable branching factor for optimized cache performance.

## Operations

- `WAryTree<W>(n)`: Create W-ary tree with branching factor `W`
- `set(pos, val)`: Set position to value  
- `query(l, r)`: Query range with specified operation

## Complexity

- All operations: $O(\log_W n)$
- Space: $O(n)$

## Usage

```cpp
// 4-ary tree (quaternary)
WAryTree<4> wtree(n);
wtree.set(pos, val);
int result = wtree.query(l, r);
```

## Notes

Higher branching factor reduces tree height but increases work per node. Optimal W depends on cache characteristics and operation complexity.

**Cache Optimization**: For typical competitive programming constraints ($n \leq 10^5$), $W = 4$ or $W = 8$ often performs better than binary trees due to improved cache locality, despite higher constant factors. The optimal choice depends on whether the bottleneck is memory access patterns or computational complexity.