---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/hash_table.h
    title: Hash Table
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
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/associative_array.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n#line\
    \ 1 \"src/template/template.h\"\n/**\n  *    author: mark\n**/\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n#line 1 \"src/datastructures/hash_table.h\"\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \nstruct CustomHash {\n  static uint64_t splitmix64(uint64_t x) {\n    x += 0x9e3779b97f4a7c15;\n\
    \    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return x ^ (x >> 31);\n  }\n\n  size_t operator()(uint64_t x) const {\n \
    \   static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return splitmix64(x + FIXED_RANDOM);\n  }\n};\n\ntemplate <class T, class\
    \ U>\nusing hash_table = __gnu_pbds::gp_hash_table<T, U, CustomHash>;\n#line 5\
    \ \"src/verify/library_checker/data_structure/associative_array.test.cpp\"\n\n\
    int main() {\n  int q;\n  cin >> q;\n  hash_table<int64_t, int64_t> mp;\n  while\
    \ (q--) {\n    bool t;\n    int64_t k;\n    cin >> t >> k;\n    if (t) {\n   \
    \   cout << mp[k] << '\\n';\n    } else {\n      int64_t v;\n      cin >> v;\n\
    \      mp[k] = v;\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n\n\
    #include \"../../../template/template.h\"\n#include \"../../../datastructures/hash_table.h\"\
    \n\nint main() {\n  int q;\n  cin >> q;\n  hash_table<int64_t, int64_t> mp;\n\
    \  while (q--) {\n    bool t;\n    int64_t k;\n    cin >> t >> k;\n    if (t)\
    \ {\n      cout << mp[k] << '\\n';\n    } else {\n      int64_t v;\n      cin\
    \ >> v;\n      mp[k] = v;\n    }\n  }\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/hash_table.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/associative_array.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/associative_array.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/associative_array.test.cpp
- /verify/src/verify/library_checker/data_structure/associative_array.test.cpp.html
title: src/verify/library_checker/data_structure/associative_array.test.cpp
---
