---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructures/hash_table.h
    title: src/datastructures/hash_table.h
  - icon: ':heavy_check_mark:'
    path: src/datastructures/static/mo_handler.h
    title: src/datastructures/static/mo_handler.h
  - icon: ':heavy_check_mark:'
    path: src/template/template.h
    title: src/template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_mode_query
    links:
    - https://judge.yosupo.jp/problem/static_range_mode_query
  bundledCode: "#line 1 \"src/verify/library_checker/data_structure/static_range_mode_query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\n\
    \n#line 1 \"src/template/template.h\"\n/**\n *    author: mark\n**/\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#define sz(x) int(size(x))\n#define\
    \ all(x) begin(x), end(x)\n#line 1 \"src/datastructures/hash_table.h\"\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n\nstruct CustomHash {\n  static uint64_t splitmix64(uint64_t\
    \ x) {\n    x += 0x9e3779b97f4a7c15;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return x ^ (x >> 31);\n  }\n\
    \n  size_t operator()(uint64_t x) const {\n    static const uint64_t FIXED_RANDOM\
    \ = chrono::steady_clock::now().time_since_epoch().count();\n    return splitmix64(x\
    \ + FIXED_RANDOM);\n  }\n};\n\ntemplate <class T, class U>\nusing hash_table =\
    \ __gnu_pbds::gp_hash_table<T, U, CustomHash>;\n#line 1 \"src/datastructures/static/mo_handler.h\"\
    \ntemplate <int K>\nstruct MoHandler {\n  vector<array<int, 3>> queries;\n \n\
    \  MoHandler() {}\n \n  void add(int l, int r) {\n    queries.push_back({l, r,\
    \ int(queries.size())});\n  }\n \n  template <class F1, class F2, class F3, class\
    \ F4, class F5>\n  void run(F1 add_l, F2 del_l, F3 add_r, F4 del_r, F5 answer)\
    \ {\n    sort(queries.begin(), queries.end(), [](array<int, 3> a, array<int, 3>\
    \ b) {\n      if (a[1] / K != b[1] / K) {\n        return a[1] / K < b[1] / K;\n\
    \      }\n      return a[0] < b[0];\n    });\n \n    int cur_l = 0, cur_r = -1;\n\
    \    for (auto [l, r, idx] : queries) {\n      while (cur_l > l) {\n        add_l(--cur_l);\n\
    \      }\n      while (cur_r < r) {\n        add_r(++cur_r);\n      }\n      while\
    \ (cur_l < l) {\n        del_l(cur_l++);\n      }\n      while (cur_r > r) {\n\
    \        del_r(cur_r--);\n      }\n      answer(idx);\n    }\n  }\n \n  template\
    \ <class F1, class F2, class F3>\n  void run(F1 add, F2 del, F3 answer) {\n  \
    \  run<F1, F2, F1, F2, F3>(add, del, add, del, answer);\n  }\n};\n#line 6 \"src/verify/library_checker/data_structure/static_range_mode_query.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int\
    \ i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  MoHandler<300> mo;\n  for (int\
    \ i = 0; i < q; i++) {\n    int l, r;\n    cin >> l >> r;\n    mo.add(l, r - 1);\n\
    \  }\n\n  hash_table<int, int> freq;\n  set<pair<int, int>> st;\n\n  auto add\
    \ = [&](int p) {\n    if (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]],\
    \ a[p]});\n    }\n    freq[a[p]]++;\n    st.insert({freq[a[p]], a[p]});\n  };\n\
    \n  auto del = [&](int p) {\n    if (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]],\
    \ a[p]});\n    }\n    freq[a[p]]--;\n    st.insert({freq[a[p]], a[p]});\n  };\n\
    \n  vector<pair<int, int>> ans(q);\n\n  auto query = [&](int idx) {\n    ans[idx]\
    \ = make_pair(rbegin(st)->second, rbegin(st)->first);\n  };\n\n  mo.run(add, del,\
    \ query);\n  for (auto [x, y] : ans) {\n    cout << x << ' ' << y << '\\n';\n\
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../datastructures/hash_table.h\"\
    \n#include \"../../../datastructures/static/mo_handler.h\"\n\nint main() {\n \
    \ int n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++)\
    \ {\n    cin >> a[i];\n  }\n  MoHandler<300> mo;\n  for (int i = 0; i < q; i++)\
    \ {\n    int l, r;\n    cin >> l >> r;\n    mo.add(l, r - 1);\n  }\n\n  hash_table<int,\
    \ int> freq;\n  set<pair<int, int>> st;\n\n  auto add = [&](int p) {\n    if (freq.find(a[p])\
    \ != freq.end()) {\n      st.extract({freq[a[p]], a[p]});\n    }\n    freq[a[p]]++;\n\
    \    st.insert({freq[a[p]], a[p]});\n  };\n\n  auto del = [&](int p) {\n    if\
    \ (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]], a[p]});\n \
    \   }\n    freq[a[p]]--;\n    st.insert({freq[a[p]], a[p]});\n  };\n\n  vector<pair<int,\
    \ int>> ans(q);\n\n  auto query = [&](int idx) {\n    ans[idx] = make_pair(rbegin(st)->second,\
    \ rbegin(st)->first);\n  };\n\n  mo.run(add, del, query);\n  for (auto [x, y]\
    \ : ans) {\n    cout << x << ' ' << y << '\\n';\n  }\n}"
  dependsOn:
  - src/template/template.h
  - src/datastructures/hash_table.h
  - src/datastructures/static/mo_handler.h
  isVerificationFile: true
  path: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
  requiredBy: []
  timestamp: '2025-09-07 13:11:03-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
layout: document
redirect_from:
- /verify/src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
- /verify/src/verify/library_checker/data_structure/static_range_mode_query.test.cpp.html
title: src/verify/library_checker/data_structure/static_range_mode_query.test.cpp
---
