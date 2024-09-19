---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/pbds/hash_table.h
    title: datastructures/pbds/hash_table.h
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"verify/library_checker/data_structure/associative_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n#line\
    \ 1 \"misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n\
    #ifdef LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
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
    \       cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 2 \"datastructures/pbds/hash_table.h\"\
    \n\n#include <ext/pb_ds/assoc_container.hpp>\n\nstruct CustomHash {\n    static\
    \ uint64_t splitmix64(uint64_t x) {\n        x += 0x9e3779b97f4a7c15;\n      \
    \  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \        return x ^ (x >> 31);\n    }\n\n    size_t operator()(uint64_t x) const\
    \ {\n        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \        return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate <class T,\
    \ class U>\nusing HashTable = __gnu_pbds::gp_hash_table<T, U, CustomHash>;\n#line\
    \ 5 \"verify/library_checker/data_structure/associative_array.test.cpp\"\n\nint\
    \ main() {\n    int q;\n    cin >> q;\n    HashTable<ll, ll> mp;\n    while (q--)\
    \ {\n        bool t;\n        ll k;\n        cin >> t >> k;\n        if (t) {\n\
    \            cout << mp[k] << '\\n';\n        } else {\n            ll v;\n  \
    \          cin >> v;\n            mp[k] = v;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"../../../misc/template.h\"\n#include \"../../../datastructures/pbds/hash_table.h\"\
    \n\nint main() {\n    int q;\n    cin >> q;\n    HashTable<ll, ll> mp;\n    while\
    \ (q--) {\n        bool t;\n        ll k;\n        cin >> t >> k;\n        if\
    \ (t) {\n            cout << mp[k] << '\\n';\n        } else {\n            ll\
    \ v;\n            cin >> v;\n            mp[k] = v;\n        }\n    }\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/pbds/hash_table.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/associative_array.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/associative_array.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/associative_array.test.cpp
- /verify/verify/library_checker/data_structure/associative_array.test.cpp.html
title: verify/library_checker/data_structure/associative_array.test.cpp
---
