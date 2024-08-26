---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructures/quick_heap.hpp: line 10: #pragma once found in a non-first line\n"
  code: "/* A functionally O(1) heap-like datastructure with good constant using hardware\
    \ intrinsics.\n * Can be represented as a W-ary search tree with a fixed structure,\
    \ where W is the word size.\n * Space complexity is O(V), where V is the largest\
    \ value that can be inserted, or O(V / W) if\n * duplicate values are disallowed.\n\
    \ * Time complexity of queries is O(log_W(V)).\n * This implementation is fixed\
    \ at 2 layers, which makes it very fast O(1), but limits V\n * to 64^3 = 262144\
    \ (which should cover most practical uses, anyway).\n */\n\n#pragma once\n\ntemplate<int\
    \ N> struct quick_heap {\n    uint32_t freq[N];\n    uint64_t l0[(N >> 6) + 1],\
    \ l1[(N >> 12) + 1], root;\n\n    quick_heap() {\n        memset(freq, 0, sizeof\
    \ freq);\n        memset(l0, 0, sizeof l0);\n        memset(l1, 0, sizeof l1);\n\
    \        root = 0;\n    }\n\n    void insert(int x) {\n        freq[x]++;\n  \
    \      if (freq[x] == 1) {\n            l0[x >> 6] |= 1ull << (x & 63);\n    \
    \        if (__builtin_popcountll(l0[x >> 6]) == 1) {\n                l1[x >>\
    \ 12] |= 1ull << ((x >> 6) & 63);\n                if (__builtin_popcountll(l1[x\
    \ >> 12]) == 1) {\n                    root |= 1ull << ((x >> 12) & 63);\n   \
    \             }\n            }\n        }\n    }\n\n    void extract(int x) {\n\
    \        freq[x]--;\n        if (freq[x] == 0) {\n            l0[x >> 6] ^= 1ull\
    \ << (x & 63);\n            if (__builtin_popcountll(l0[x >> 6]) == 0) {\n   \
    \             l1[x >> 12] ^= 1ull << ((x >> 6) & 63);\n                if (__builtin_popcountll(l1[x\
    \ >> 12]) == 0) {\n                    root ^= 1ull << ((x >> 12) & 63);\n   \
    \             }\n            }\n        }\n    }\n\n    int get_min() {\n    \
    \    uint32_t p = __builtin_ctzll(root);\n        p = (p << 6) + __builtin_ctzll(l1[p]);\n\
    \        p = (p << 6) + __builtin_ctzll(l0[p]);\n        return p;\n    }\n\n\
    \    int get_max() {\n        uint32_t p = 63 - __builtin_clzll(root);\n     \
    \   p = (p << 6) + 63 - __builtin_clzll(l1[p]);\n        p = (p << 6) + 63 - __builtin_clzll(l0[p]);\n\
    \        return p;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/quick_heap.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/quick_heap.hpp
layout: document
redirect_from:
- /library/datastructures/quick_heap.hpp
- /library/datastructures/quick_heap.hpp.html
title: datastructures/quick_heap.hpp
---
