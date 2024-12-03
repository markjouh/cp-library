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
  bundledCode: "#line 1 \"datastructures/w_ary_tree.h\"\nstruct word {\n    uint64_t\
    \ mask;\n    word() : mask(0) {}\n    \n    void flip_bit(int p) { mask ^= 1ull\
    \ << p; }\n    int min_bit() { return __builtin_ctzll(mask); }\n    int max_bit()\
    \ { return 63 - __builtin_clzll(mask); }\n};\n\nstruct w_ary_base : public word\
    \ {\n    bool flip(int p) {\n        bool old = mask != 0;\n        flip_bit(p);\n\
    \        return (mask != 0) != old;\n    }\n    int min() { return min_bit();\
    \ }\n    int max() { return max_bit(); }\n};\n\ntemplate <int L>\nstruct w_ary_tree\
    \ : public word {\n    array<conditional_t<(L > 2), w_ary_tree<L - 1>, w_ary_base>,\
    \ 64> nxt;\n\n    static constexpr int block_sz = 1ull << (6 * (L - 1));\n\n \
    \   bool flip(int p) {\n        bool old = mask != 0;\n        int block = p /\
    \ block_sz;\n        if (nxt[block].flip(p % block_sz)) {\n            flip_bit(block);\n\
    \        }\n        return (mask != 0) != old;\n    }\n    int get_min() {\n \
    \       int block = min_bit();\n        return block * block_sz + nxt[block].min();\n\
    \    }\n    int get_max() {\n        int block = max_bit();\n        return block\
    \ * block_sz + nxt[block].max();\n    }\n};\n"
  code: "struct word {\n    uint64_t mask;\n    word() : mask(0) {}\n    \n    void\
    \ flip_bit(int p) { mask ^= 1ull << p; }\n    int min_bit() { return __builtin_ctzll(mask);\
    \ }\n    int max_bit() { return 63 - __builtin_clzll(mask); }\n};\n\nstruct w_ary_base\
    \ : public word {\n    bool flip(int p) {\n        bool old = mask != 0;\n   \
    \     flip_bit(p);\n        return (mask != 0) != old;\n    }\n    int min() {\
    \ return min_bit(); }\n    int max() { return max_bit(); }\n};\n\ntemplate <int\
    \ L>\nstruct w_ary_tree : public word {\n    array<conditional_t<(L > 2), w_ary_tree<L\
    \ - 1>, w_ary_base>, 64> nxt;\n\n    static constexpr int block_sz = 1ull << (6\
    \ * (L - 1));\n\n    bool flip(int p) {\n        bool old = mask != 0;\n     \
    \   int block = p / block_sz;\n        if (nxt[block].flip(p % block_sz)) {\n\
    \            flip_bit(block);\n        }\n        return (mask != 0) != old;\n\
    \    }\n    int get_min() {\n        int block = min_bit();\n        return block\
    \ * block_sz + nxt[block].min();\n    }\n    int get_max() {\n        int block\
    \ = max_bit();\n        return block * block_sz + nxt[block].max();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/w_ary_tree.h
  requiredBy: []
  timestamp: '2024-12-02 22:41:32-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/w_ary_tree.h
layout: document
redirect_from:
- /library/datastructures/w_ary_tree.h
- /library/datastructures/w_ary_tree.h.html
title: datastructures/w_ary_tree.h
---
