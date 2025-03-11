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
  bundledCode: "#line 1 \"datastructures/w_ary_tree.h\"\nstruct Word {\n  uint64_t\
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
  path: datastructures/w_ary_tree.h
  requiredBy: []
  timestamp: '2025-03-11 01:06:40-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/w_ary_tree.h
layout: document
redirect_from:
- /library/datastructures/w_ary_tree.h
- /library/datastructures/w_ary_tree.h.html
title: datastructures/w_ary_tree.h
---
