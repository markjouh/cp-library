---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/w_ary_tree.h
    title: datastructures/w_ary_tree.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"verify/library_checker/data_structure/double_ended_priority_queue.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#line 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
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
    \       cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 2 \"datastructures/w_ary_tree.h\"\
    \n\ntemplate <int N>\nstruct WAryTree {\n    uint32_t freq[N];\n    uint64_t l0[(N\
    \ >> 6) + 1], l1[(N >> 12) + 1], root;\n\n    WAryTree() {\n        memset(freq,\
    \ 0, sizeof freq);\n        memset(l0, 0, sizeof l0);\n        memset(l1, 0, sizeof\
    \ l1);\n        root = 0;\n    }\n\n    void insert(int x) {\n        freq[x]++;\n\
    \        if (freq[x] == 1) {\n            l0[x >> 6] |= 1ull << (x & 63);\n  \
    \          if (__builtin_popcountll(l0[x >> 6]) == 1) {\n                l1[x\
    \ >> 12] |= 1ull << ((x >> 6) & 63);\n                if (__builtin_popcountll(l1[x\
    \ >> 12]) == 1) {\n                    root |= 1ull << ((x >> 12) & 63);\n   \
    \             }\n            }\n        }\n    }\n\n    void remove(int x) {\n\
    \        freq[x]--;\n        if (freq[x] == 0) {\n            l0[x >> 6] ^= 1ull\
    \ << (x & 63);\n            if (__builtin_popcountll(l0[x >> 6]) == 0) {\n   \
    \             l1[x >> 12] ^= 1ull << ((x >> 6) & 63);\n                if (__builtin_popcountll(l1[x\
    \ >> 12]) == 0) {\n                    root ^= 1ull << ((x >> 12) & 63);\n   \
    \             }\n            }\n        }\n    }\n\n    int get_min() {\n    \
    \    uint32_t p = __builtin_ctzll(root);\n        p = (p << 6) + __builtin_ctzll(l1[p]);\n\
    \        p = (p << 6) + __builtin_ctzll(l0[p]);\n        return p;\n    }\n\n\
    \    int get_max() {\n        uint32_t p = 63 - __builtin_clzll(root);\n     \
    \   p = (p << 6) + 63 - __builtin_clzll(l1[p]);\n        p = (p << 6) + 63 - __builtin_clzll(l0[p]);\n\
    \        return p;\n    }\n};\n#line 5 \"verify/library_checker/data_structure/double_ended_priority_queue.test.cpp\"\
    \n\nconst int N = 1 << 18;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n\
    \    vector<int> queries, vals;\n    for (int i = 0; i < n; i++) {\n        int\
    \ x;\n        cin >> x;\n        queries.push_back(x);\n        vals.push_back(x);\n\
    \    }\n    for (int i = 0; i < q; i++) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int x;\n            cin >> x;\n          \
    \  queries.push_back(x);\n            vals.push_back(x);\n        } else if (t\
    \ == 1) {\n            queries.push_back(INT_MIN);\n        } else {\n       \
    \     queries.push_back(INT_MAX);\n        }\n    }\n    sort(all(vals));\n  \
    \  vals.resize(unique(all(vals)) - begin(vals));\n\n    array<int, 3> cnt{};\n\
    \    array<WAryTree<1 << 18>, 3> ds;\n    for (int x : queries) {\n        if\
    \ (x == INT_MIN) {\n            for (int i = 0; i < 3; i++) {\n              \
    \  if (cnt[i] > 0) {\n                    int rem = ds[i].get_min();\n       \
    \             cout << vals[i * N + rem] << '\\n';\n                    ds[i].remove(rem);\n\
    \                    cnt[i]--;\n                    break;\n                }\n\
    \            }\n        } else if (x == INT_MAX) {\n            for (int i = 2;\
    \ i >= 0; i--) {\n                if (cnt[i] > 0) {\n                    int rem\
    \ = ds[i].get_max();\n                    cout << vals[i * N + rem] << '\\n';\n\
    \                    ds[i].remove(rem);\n                    cnt[i]--;\n     \
    \               break;\n                }\n            }\n        } else {\n \
    \           int idx = lower_bound(all(vals), x) - begin(vals);\n            ds[idx\
    \ / N].insert(idx % N);\n            cnt[idx / N]++;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"../../../misc/template.h\"\n#include \"../../../datastructures/w_ary_tree.h\"\
    \n\nconst int N = 1 << 18;\n\nint main() {\n    int n, q;\n    cin >> n >> q;\n\
    \    vector<int> queries, vals;\n    for (int i = 0; i < n; i++) {\n        int\
    \ x;\n        cin >> x;\n        queries.push_back(x);\n        vals.push_back(x);\n\
    \    }\n    for (int i = 0; i < q; i++) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int x;\n            cin >> x;\n          \
    \  queries.push_back(x);\n            vals.push_back(x);\n        } else if (t\
    \ == 1) {\n            queries.push_back(INT_MIN);\n        } else {\n       \
    \     queries.push_back(INT_MAX);\n        }\n    }\n    sort(all(vals));\n  \
    \  vals.resize(unique(all(vals)) - begin(vals));\n\n    array<int, 3> cnt{};\n\
    \    array<WAryTree<1 << 18>, 3> ds;\n    for (int x : queries) {\n        if\
    \ (x == INT_MIN) {\n            for (int i = 0; i < 3; i++) {\n              \
    \  if (cnt[i] > 0) {\n                    int rem = ds[i].get_min();\n       \
    \             cout << vals[i * N + rem] << '\\n';\n                    ds[i].remove(rem);\n\
    \                    cnt[i]--;\n                    break;\n                }\n\
    \            }\n        } else if (x == INT_MAX) {\n            for (int i = 2;\
    \ i >= 0; i--) {\n                if (cnt[i] > 0) {\n                    int rem\
    \ = ds[i].get_max();\n                    cout << vals[i * N + rem] << '\\n';\n\
    \                    ds[i].remove(rem);\n                    cnt[i]--;\n     \
    \               break;\n                }\n            }\n        } else {\n \
    \           int idx = lower_bound(all(vals), x) - begin(vals);\n            ds[idx\
    \ / N].insert(idx % N);\n            cnt[idx / N]++;\n        }\n    }\n}"
  dependsOn:
  - misc/template.h
  - datastructures/w_ary_tree.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
- /verify/verify/library_checker/data_structure/double_ended_priority_queue.test.cpp.html
title: verify/library_checker/data_structure/double_ended_priority_queue.test.cpp
---
