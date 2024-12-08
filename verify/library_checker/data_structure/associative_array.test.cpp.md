---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/hash_table.h
    title: datastructures/hash_table.h
  - icon: ':question:'
    path: template/template.h
    title: template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"verify/library_checker/data_structure/associative_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n#line\
    \ 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\nusing ll = long\
    \ long;\n#line 1 \"datastructures/hash_table.h\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nstruct custom_hash {\n    static uint64_t splitmix64(uint64_t x) {\n       \
    \ x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate <class T, class\
    \ U>\nusing hash_table = __gnu_pbds::gp_hash_table<T, U, custom_hash>;\n#line\
    \ 5 \"verify/library_checker/data_structure/associative_array.test.cpp\"\n\nint\
    \ main() {\n    int q;\n    cin >> q;\n    hash_table<ll, ll> mp;\n    while (q--)\
    \ {\n        bool t;\n        ll k;\n        cin >> t >> k;\n        if (t) {\n\
    \            cout << mp[k] << '\\n';\n        } else {\n            ll v;\n  \
    \          cin >> v;\n            mp[k] = v;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"../../../template/template.h\"\n#include \"../../../datastructures/hash_table.h\"\
    \n\nint main() {\n    int q;\n    cin >> q;\n    hash_table<ll, ll> mp;\n    while\
    \ (q--) {\n        bool t;\n        ll k;\n        cin >> t >> k;\n        if\
    \ (t) {\n            cout << mp[k] << '\\n';\n        } else {\n            ll\
    \ v;\n            cin >> v;\n            mp[k] = v;\n        }\n    }\n}"
  dependsOn:
  - template/template.h
  - datastructures/hash_table.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/associative_array.test.cpp
  requiredBy: []
  timestamp: '2024-12-07 19:52:17-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/associative_array.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/associative_array.test.cpp
- /verify/verify/library_checker/data_structure/associative_array.test.cpp.html
title: verify/library_checker/data_structure/associative_array.test.cpp
---
