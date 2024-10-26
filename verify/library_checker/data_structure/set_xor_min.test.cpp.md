---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_trie.h
    title: datastructures/binary_trie.h
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':heavy_check_mark:'
    path: utils/my_random.h
    title: utils/my_random.h
  - icon: ':heavy_check_mark:'
    path: utils/my_timer.h
    title: utils/my_timer.h
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
  bundledCode: "#line 1 \"verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#line 1 \"\
    misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef\
    \ LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x),\
    \ end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 1 \"\
    datastructures/binary_trie.h\"\ntemplate <class T>\nstruct BinaryTrie {\n    static\
    \ const int W = sizeof(T) * 8;\n    vector<array<int, 2>> nxt;\n    vector<int>\
    \ cnt;\n    T filter = 0;\n\n    BinaryTrie() : nxt(1, {-1, -1}), cnt(1, 0) {}\n\
    \n    void add(T x, int v = 1) {\n        x ^= filter;\n        int pos = 0;\n\
    \        for (int i = W - 1; i >= 0; i--) {\n            bool dir = (x >> i) &\
    \ 1;\n            if (nxt[pos][dir] == -1) {\n                nxt[pos][dir] =\
    \ sz(nxt);\n                nxt.push_back({-1, -1});\n                cnt.push_back(0);\n\
    \            }\n            pos = nxt[pos][dir];\n            cnt[pos] += v;\n\
    \        }\n    }\n\n    BinaryTrie &operator^=(T x) {\n        filter ^= x;\n\
    \        return *this;\n    }\n\n    T min_xor(T x) {\n        x ^= filter;\n\
    \        int pos = 0;\n        T res = 0;\n        for (int i = W - 1; i >= 0;\
    \ i--) {\n            bool dir = (x >> i) & 1;\n            if (nxt[pos][dir]\
    \ == -1 || cnt[nxt[pos][dir]] == 0) {\n                res |= T(1) << i;\n   \
    \             pos = nxt[pos][dir ^ 1];\n            } else {\n               \
    \ pos = nxt[pos][dir];\n            }\n        }\n        return res;\n    }\n\
    \n    T max_xor(T x) {\n        static const T mask = -1;\n        return mask\
    \ ^ min_xor(x ^ mask);\n    }\n};\n#line 5 \"verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n\nint main() {\n    int q;\n    cin >> q;\n    BinaryTrie<uint32_t> bt;\n  \
    \  while (q--) {\n        int t, x;\n        cin >> t >> x;\n        if (t ==\
    \ 0) {\n            if (bt.min_xor(x) != 0) {\n                bt.add(x);\n  \
    \          }\n        } else if (t == 1) {\n            if (bt.min_xor(x) == 0)\
    \ {\n                bt.add(x, -1);\n            }\n        } else {\n       \
    \     cout << bt.min_xor(x) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../../misc/template.h\"\n#include \"../../../datastructures/binary_trie.h\"\
    \n\nint main() {\n    int q;\n    cin >> q;\n    BinaryTrie<uint32_t> bt;\n  \
    \  while (q--) {\n        int t, x;\n        cin >> t >> x;\n        if (t ==\
    \ 0) {\n            if (bt.min_xor(x) != 0) {\n                bt.add(x);\n  \
    \          }\n        } else if (t == 1) {\n            if (bt.min_xor(x) == 0)\
    \ {\n                bt.add(x, -1);\n            }\n        } else {\n       \
    \     cout << bt.min_xor(x) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/binary_trie.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 20:08:44-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp.html
title: verify/library_checker/data_structure/set_xor_min.test.cpp
---
