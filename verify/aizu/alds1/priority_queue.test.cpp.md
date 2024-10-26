---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: common/compress.h
    title: common/compress.h
  - icon: ':heavy_check_mark:'
    path: esoteric/w_ary_tree.h
    title: esoteric/w_ary_tree.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C
  bundledCode: "#line 1 \"verify/aizu/alds1/priority_queue.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\n\n\
    #line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define all(x)\
    \ begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate\
    \ <class T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line\
    \ 1 \"esoteric/w_ary_tree.h\"\ntemplate <int N>\nstruct WAryTree {\n    uint32_t\
    \ freq[N];\n    uint64_t l0[(N >> 6) + 1], l1[(N >> 12) + 1], root;\n\n    WAryTree()\
    \ {\n        memset(freq, 0, sizeof freq);\n        memset(l0, 0, sizeof l0);\n\
    \        memset(l1, 0, sizeof l1);\n        root = 0;\n    }\n\n    void insert(int\
    \ x) {\n        freq[x]++;\n        if (freq[x] == 1) {\n            l0[x >> 6]\
    \ |= 1ull << (x & 63);\n            if (__builtin_popcountll(l0[x >> 6]) == 1)\
    \ {\n                l1[x >> 12] |= 1ull << ((x >> 6) & 63);\n               \
    \ if (__builtin_popcountll(l1[x >> 12]) == 1) {\n                    root |= 1ull\
    \ << ((x >> 12) & 63);\n                }\n            }\n        }\n    }\n\n\
    \    void remove(int x) {\n        freq[x]--;\n        if (freq[x] == 0) {\n \
    \           l0[x >> 6] ^= 1ull << (x & 63);\n            if (__builtin_popcountll(l0[x\
    \ >> 6]) == 0) {\n                l1[x >> 12] ^= 1ull << ((x >> 6) & 63);\n  \
    \              if (__builtin_popcountll(l1[x >> 12]) == 0) {\n               \
    \     root ^= 1ull << ((x >> 12) & 63);\n                }\n            }\n  \
    \      }\n    }\n\n    int get_min() {\n        uint32_t p = __builtin_ctzll(root);\n\
    \        p = (p << 6) + __builtin_ctzll(l1[p]);\n        p = (p << 6) + __builtin_ctzll(l0[p]);\n\
    \        return p;\n    }\n\n    int get_max() {\n        uint32_t p = 63 - __builtin_clzll(root);\n\
    \        p = (p << 6) + 63 - __builtin_clzll(l1[p]);\n        p = (p << 6) + 63\
    \ - __builtin_clzll(l0[p]);\n        return p;\n    }\n};\n#line 2 \"common/compress.h\"\
    \n\ntemplate <class T>\nstruct Compress {\n    vector<T> vals;\n    bool ready\
    \ = true;\n \n    void init() {\n        if (!ready) {\n            sort(all(vals));\n\
    \            vals.resize(unique(all(vals)) - begin(vals));\n            ready\
    \ = true;\n        }\n    }\n    void add(T x) {\n        vals.push_back(x);\n\
    \        ready = false;\n    }\n \n    int size() {\n        init();\n       \
    \ return vals.size();\n    }\n    int operator[](int p) {\n        init();\n \
    \       return vals[p];\n    }\n    int get(T x) {\n        init();\n        return\
    \ lower_bound(all(vals), x) - begin(vals);\n    }\n};\n#line 6 \"verify/aizu/alds1/priority_queue.test.cpp\"\
    \n\nint main() {\n    string s;\n    int x;\n    vector<int> queries;\n    Compress<int>\
    \ vals;\n    while (cin >> s) {\n        if (s == \"end\") {\n            break;\n\
    \        }\n        if (s == \"insert\") {\n            cin >> x;\n          \
    \  queries.push_back(x);\n            vals.add(x);\n        } else {\n       \
    \     queries.push_back(-1);\n        }\n    }\n    WAryTree<2000000> ds;\n  \
    \  for (auto x : queries) {\n        if (x == -1) {\n            int idx = ds.get_max();\n\
    \            cout << vals[idx] << '\\n';\n            ds.remove(idx);\n      \
    \  } else {\n            ds.insert(vals.get(x));\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_9_C\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../esoteric/w_ary_tree.h\"\
    \n#include \"../../../common/compress.h\"\n\nint main() {\n    string s;\n   \
    \ int x;\n    vector<int> queries;\n    Compress<int> vals;\n    while (cin >>\
    \ s) {\n        if (s == \"end\") {\n            break;\n        }\n        if\
    \ (s == \"insert\") {\n            cin >> x;\n            queries.push_back(x);\n\
    \            vals.add(x);\n        } else {\n            queries.push_back(-1);\n\
    \        }\n    }\n    WAryTree<2000000> ds;\n    for (auto x : queries) {\n \
    \       if (x == -1) {\n            int idx = ds.get_max();\n            cout\
    \ << vals[idx] << '\\n';\n            ds.remove(idx);\n        } else {\n    \
    \        ds.insert(vals.get(x));\n        }\n    }\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - esoteric/w_ary_tree.h
  - common/compress.h
  isVerificationFile: true
  path: verify/aizu/alds1/priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 20:01:05-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/alds1/priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/alds1/priority_queue.test.cpp
- /verify/verify/aizu/alds1/priority_queue.test.cpp.html
title: verify/aizu/alds1/priority_queue.test.cpp
---
