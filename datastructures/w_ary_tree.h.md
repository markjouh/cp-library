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
  bundledCode: "#line 1 \"datastructures/w_ary_tree.h\"\nstruct Word {\n    uint64_t\
    \ mask;\n    Word() : mask(0) {}\n    \n    void flip_bit(int p) { mask ^= 1ull\
    \ << p; }\n    int min_bit() { return __builtin_ctzll(mask); }\n    int max_bit()\
    \ { return 63 - __builtin_clzll(mask); }\n};\n\nstruct WaryBase : public Word\
    \ {\n    bool flip(int p) {\n        bool old = mask != 0;\n        flip_bit(p);\n\
    \        return (mask != 0) != old;\n    }\n    int min() { return min_bit();\
    \ }\n    int max() { return max_bit(); }\n};\n\ntemplate <int L>\nstruct WaryTree\
    \ : public Word {\n    array<conditional_t<(L > 2), WaryTree<L - 1>, WaryBase>,\
    \ 64> nxt;\n\n    static constexpr int block_sz = 1ull << (6 * (L - 1));\n\n \
    \   bool flip(int p) {\n        bool old = mask != 0;\n        int block = p /\
    \ block_sz;\n        if (nxt[block].flip(p % block_sz)) {\n            flip_bit(block);\n\
    \        }\n        return (mask != 0) != old;\n    }\n    int min() {\n     \
    \   int block = min_bit();\n        return block * block_sz + nxt[block].min();\n\
    \    }\n    int max() {\n        int block = max_bit();\n        return block\
    \ * block_sz + nxt[block].max();\n    }\n};\n"
  code: "struct Word {\n    uint64_t mask;\n    Word() : mask(0) {}\n    \n    void\
    \ flip_bit(int p) { mask ^= 1ull << p; }\n    int min_bit() { return __builtin_ctzll(mask);\
    \ }\n    int max_bit() { return 63 - __builtin_clzll(mask); }\n};\n\nstruct WaryBase\
    \ : public Word {\n    bool flip(int p) {\n        bool old = mask != 0;\n   \
    \     flip_bit(p);\n        return (mask != 0) != old;\n    }\n    int min() {\
    \ return min_bit(); }\n    int max() { return max_bit(); }\n};\n\ntemplate <int\
    \ L>\nstruct WaryTree : public Word {\n    array<conditional_t<(L > 2), WaryTree<L\
    \ - 1>, WaryBase>, 64> nxt;\n\n    static constexpr int block_sz = 1ull << (6\
    \ * (L - 1));\n\n    bool flip(int p) {\n        bool old = mask != 0;\n     \
    \   int block = p / block_sz;\n        if (nxt[block].flip(p % block_sz)) {\n\
    \            flip_bit(block);\n        }\n        return (mask != 0) != old;\n\
    \    }\n    int min() {\n        int block = min_bit();\n        return block\
    \ * block_sz + nxt[block].min();\n    }\n    int max() {\n        int block =\
    \ max_bit();\n        return block * block_sz + nxt[block].max();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/w_ary_tree.h
  requiredBy: []
  timestamp: '2024-11-16 20:34:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/w_ary_tree.h
layout: document
redirect_from:
- /library/datastructures/w_ary_tree.h
- /library/datastructures/w_ary_tree.h.html
title: datastructures/w_ary_tree.h
---
