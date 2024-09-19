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
    path: utils/encode.h
    title: utils/encode.h
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
    \ LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
    \ b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    #define pb push_back\n#define eb emplace_back\n#define f first\n#define s second\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n    return b <\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n\
    \    return b > a ? a = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n    \
    \    cin.tie(0)->sync_with_stdio(0);\n        cin.exceptions(cin.failbit);\n \
    \       cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 2 \"datastructures/binary_trie.h\"\
    \n\nstruct BinaryTrie {\n    vector<array<int, 2>> nxt;\n    vector<int> cnt;\n\
    \n    BinaryTrie() : nxt(1, {-1, -1}), cnt(1, 0) {}\n\n    int count(unsigned\
    \ int x) {\n        int pos = 0;\n        for (int i = 31; i >= 0; i--) {\n  \
    \          pos = nxt[pos][(x >> i) & 1];\n            if (pos == -1) {\n     \
    \           return 0;\n            }\n        }\n        return cnt[pos];\n  \
    \  }\n\n    void insert(unsigned int x) {\n        int pos = 0;\n        for (int\
    \ i = 31; i >= 0; i--) {\n            bool dir = (x >> i) & 1;\n            if\
    \ (nxt[pos][dir] == -1) {\n                nxt[pos][dir] = sz(nxt);\n        \
    \        nxt.push_back({-1, -1});\n                cnt.push_back(0);\n       \
    \     }\n            pos = nxt[pos][dir];\n            cnt[pos]++;\n        }\n\
    \    }\n\n    void remove(unsigned int x) {\n        int pos = 0;\n        for\
    \ (int i = 31; i >= 0; i--) {\n            pos = nxt[pos][(x >> i) & 1];\n   \
    \         cnt[pos]--;\n        }\n    }\n\n    unsigned int min_xor(unsigned int\
    \ x) {\n        int pos = 0;\n        unsigned int res = 0;\n        for (int\
    \ i = 31; i >= 0; i--) {\n            bool dir = (x >> i) & 1;\n            if\
    \ (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]] == 0) {\n                res |= 1\
    \ << i;\n                pos = nxt[pos][dir ^ 1];\n            } else {\n    \
    \            pos = nxt[pos][dir];\n            }\n        }\n        return res;\n\
    \    }\n\n    unsigned int max_xor(unsigned int x) {\n        static const unsigned\
    \ int mask = -1;\n        return mask ^ min_xor(x ^ mask);\n    }\n};\n#line 5\
    \ \"verify/library_checker/data_structure/set_xor_min.test.cpp\"\n\nint main()\
    \ {\n    int q;\n    cin >> q;\n    BinaryTrie bt;\n    while (q--) {\n      \
    \  int t, x;\n        cin >> t >> x;\n        if (t == 0) {\n            if (bt.count(x)\
    \ == 0) {\n                bt.insert(x);\n            }\n        } else if (t\
    \ == 1) {\n            if (bt.count(x) == 1) {\n                bt.remove(x);\n\
    \            }\n        } else {\n            cout << bt.min_xor(x) << '\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../../misc/template.h\"\n#include \"../../../datastructures/binary_trie.h\"\
    \n\nint main() {\n    int q;\n    cin >> q;\n    BinaryTrie bt;\n    while (q--)\
    \ {\n        int t, x;\n        cin >> t >> x;\n        if (t == 0) {\n      \
    \      if (bt.count(x) == 0) {\n                bt.insert(x);\n            }\n\
    \        } else if (t == 1) {\n            if (bt.count(x) == 1) {\n         \
    \       bt.remove(x);\n            }\n        } else {\n            cout << bt.min_xor(x)\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/binary_trie.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp.html
title: verify/library_checker/data_structure/set_xor_min.test.cpp
---
