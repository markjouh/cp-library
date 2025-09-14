---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/binary_trie.h
    title: Binary Trie
  - icon: ':heavy_check_mark:'
    path: src/template/template.h
    title: Template
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 1 \"\
    src/template/template.h\"\n/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"src/datastructures/binary_trie.h\"\ntemplate <class T>\nstruct\
    \ BinaryTrie {\n  static const int W = sizeof(T) * 8;\n  vector<array<int, 2>>\
    \ nxt;\n  vector<int> cnt;\n  T filter = 0;\n\n  BinaryTrie() : nxt(1, {-1, -1}),\
    \ cnt(1, 0) {}\n\n  void insert(T x, int v = 1) {\n    x ^= filter;\n    int pos\
    \ = 0;\n    for (int i = W - 1; i >= 0; i--) {\n      bool dir = (x >> i) & 1;\n\
    \      if (nxt[pos][dir] == -1) {\n        nxt[pos][dir] = ssize(nxt);\n     \
    \   nxt.push_back({-1, -1});\n        cnt.push_back(0);\n      }\n      pos =\
    \ nxt[pos][dir];\n      cnt[pos] += v;\n    }\n  }\n\n  BinaryTrie &operator^=(T\
    \ x) {\n    filter ^= x;\n    return *this;\n  }\n\n  T min_xor(T x) {\n    x\
    \ ^= filter;\n    int pos = 0;\n    T res = 0;\n    for (int i = W - 1; i >= 0;\
    \ i--) {\n      bool dir = (x >> i) & 1;\n      if (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]]\
    \ == 0) {\n        res |= T(1) << i;\n        pos = nxt[pos][dir ^ 1];\n     \
    \ } else {\n        pos = nxt[pos][dir];\n      }\n    }\n    return res;\n  }\n\
    \n  T max_xor(T x) {\n    static const T mask = -1;\n    return mask ^ min_xor(x\
    \ ^ mask);\n  }\n};\n#line 5 \"src/verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n\nint main() {\n  int q;\n  cin >> q;\n  BinaryTrie<uint32_t> bt;\n  while (q--)\
    \ {\n    int t, x;\n    cin >> t >> x;\n    if (t == 0) {\n      if (bt.min_xor(x)\
    \ != 0) {\n        bt.insert(x);\n      }\n    } else if (t == 1) {\n      if\
    \ (bt.min_xor(x) == 0) {\n        bt.insert(x, -1);\n      }\n    } else {\n \
    \     cout << bt.min_xor(x) << '\\n';\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../datastructures/binary_trie.h\"\
    \n\nint main() {\n  int q;\n  cin >> q;\n  BinaryTrie<uint32_t> bt;\n  while (q--)\
    \ {\n    int t, x;\n    cin >> t >> x;\n    if (t == 0) {\n      if (bt.min_xor(x)\
    \ != 0) {\n        bt.insert(x);\n      }\n    } else if (t == 1) {\n      if\
    \ (bt.min_xor(x) == 0) {\n        bt.insert(x, -1);\n      }\n    } else {\n \
    \     cout << bt.min_xor(x) << '\\n';\n    }\n  }\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/binary_trie.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2025-09-14 12:12:28-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/set_xor_min.test.cpp
- /verify/src/verify/library_checker/data_structure/set_xor_min.test.cpp.html
title: src/verify/library_checker/data_structure/set_xor_min.test.cpp
---
