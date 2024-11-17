---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_trie.h
    title: datastructures/binary_trie.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  - icon: ':question:'
    path: utils/bits/stdc++.h
    title: utils/bits/stdc++.h
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
    template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\n\n// void solve() {\n// }\n\n// int main() {\n//     cin.tie(0)->sync_with_stdio(0);\n\
    //     cin.exceptions(cin.failbit);\n\n//     int t = 1;\n//     // cin >> t;\n\
    //     while (t--) {\n//         solve();\n//     }\n\n//     return 0;\n// }\n\
    #line 1 \"datastructures/binary_trie.h\"\ntemplate <class T>\nstruct BinaryTrie\
    \ {\n    static const int W = sizeof(T) * 8;\n    vector<array<int, 2>> nxt;\n\
    \    vector<int> cnt;\n    T filter = 0;\n\n    BinaryTrie() : nxt(1, {-1, -1}),\
    \ cnt(1, 0) {}\n\n    void add(T x, int v = 1) {\n        x ^= filter;\n     \
    \   int pos = 0;\n        for (int i = W - 1; i >= 0; i--) {\n            bool\
    \ dir = (x >> i) & 1;\n            if (nxt[pos][dir] == -1) {\n              \
    \  nxt[pos][dir] = sz(nxt);\n                nxt.push_back({-1, -1});\n      \
    \          cnt.push_back(0);\n            }\n            pos = nxt[pos][dir];\n\
    \            cnt[pos] += v;\n        }\n    }\n\n    BinaryTrie &operator^=(T\
    \ x) {\n        filter ^= x;\n        return *this;\n    }\n\n    T min_xor(T\
    \ x) {\n        x ^= filter;\n        int pos = 0;\n        T res = 0;\n     \
    \   for (int i = W - 1; i >= 0; i--) {\n            bool dir = (x >> i) & 1;\n\
    \            if (nxt[pos][dir] == -1 || cnt[nxt[pos][dir]] == 0) {\n         \
    \       res |= T(1) << i;\n                pos = nxt[pos][dir ^ 1];\n        \
    \    } else {\n                pos = nxt[pos][dir];\n            }\n        }\n\
    \        return res;\n    }\n\n    T max_xor(T x) {\n        static const T mask\
    \ = -1;\n        return mask ^ min_xor(x ^ mask);\n    }\n};\n#line 5 \"verify/library_checker/data_structure/set_xor_min.test.cpp\"\
    \n\nint main() {\n    int q;\n    cin >> q;\n    BinaryTrie<uint32_t> bt;\n  \
    \  while (q--) {\n        int t, x;\n        cin >> t >> x;\n        if (t ==\
    \ 0) {\n            if (bt.min_xor(x) != 0) {\n                bt.add(x);\n  \
    \          }\n        } else if (t == 1) {\n            if (bt.min_xor(x) == 0)\
    \ {\n                bt.add(x, -1);\n            }\n        } else {\n       \
    \     cout << bt.min_xor(x) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../datastructures/binary_trie.h\"\
    \n\nint main() {\n    int q;\n    cin >> q;\n    BinaryTrie<uint32_t> bt;\n  \
    \  while (q--) {\n        int t, x;\n        cin >> t >> x;\n        if (t ==\
    \ 0) {\n            if (bt.min_xor(x) != 0) {\n                bt.add(x);\n  \
    \          }\n        } else if (t == 1) {\n            if (bt.min_xor(x) == 0)\
    \ {\n                bt.add(x, -1);\n            }\n        } else {\n       \
    \     cout << bt.min_xor(x) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - template/template.h
  - utils/bits/stdc++.h
  - datastructures/binary_trie.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 20:34:38-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp
- /verify/verify/library_checker/data_structure/set_xor_min.test.cpp.html
title: verify/library_checker/data_structure/set_xor_min.test.cpp
---
