---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/pbds/hash_table.hpp
    title: datastructures/pbds/hash_table.hpp
  - icon: ':heavy_check_mark:'
    path: datastructures/static/mo_queries.hpp
    title: datastructures/static/mo_queries.hpp
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
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_range_mode_query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\n\
    \n#line 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n\
    #include <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n\
    #include <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing\
    \ namespace std;\n\n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r)\
    \ for (int i = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define\
    \ rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l,\
    \ r) for (int i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n) per3(i, 0,\
    \ n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\n#define\
    \ all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\ntemplate <class\
    \ T>\nusing vec = vector<T>;\n\nusing ll = long long;\nusing pii = pair<int, int>;\n\
    using pll = pair<ll, ll>;\n\ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n\
    \  return __lg(x);\n#else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n \
    \ }\n  return res;\n#endif\n}\n\ntemplate <class T>\nbool ckmin(T &a, const T\
    \ &b) {\n  return b < a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T\
    \ &a, const T &b) {\n  return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T =\
    \ int>\nstatic constexpr T inf = numeric_limits<T>::max() / 2;\n\nstruct InitIO\
    \ {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \    cout << setprecision(10) << fixed;\n  }\n} init_io;\n#line 2 \"datastructures/pbds/hash_table.hpp\"\
    \n\n#include <ext/pb_ds/assoc_container.hpp>\n\nstruct CustomHash {\n  static\
    \ uint64_t splitmix64(uint64_t x) {\n    x += 0x9e3779b97f4a7c15;\n    x = (x\
    \ ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return x ^ (x >> 31);\n  }\n\n  size_t operator()(uint64_t x) const {\n \
    \   static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return splitmix64(x + FIXED_RANDOM);\n  }\n};\n\ntemplate <class T, class\
    \ U>\nusing HashTable = __gnu_pbds::gp_hash_table<T, U, CustomHash>;\n#line 2\
    \ \"datastructures/static/mo_queries.hpp\"\n\ntemplate <class T, int B>\nstruct\
    \ MoQueries {\n  vector<array<int, 3>> queries;\n  vector<T> res;\n\n  MoQueries()\
    \ {}\n\n  void insert(int l, int r) {\n    queries.push_back({l, r, sz(queries)});\n\
    \  }\n\n  template<class AddL, class DelL, class AddR, class DelR, class Query>\n\
    \  void solve(AddL add_l, DelL del_l, AddR add_r, DelR del_r, Query query) {\n\
    \    sort(all(queries), [](array<int, 3> a, array<int, 3> b) {\n      if (a[1]\
    \ / B != b[1] / B) {\n        return a[1] / B < b[1] / B;\n      }\n      return\
    \ a[0] < b[0];\n    });\n    res.resize(sz(queries));\n\n    int cur_l = 0, cur_r\
    \ = -1;\n    for (auto [l, r, idx] : queries) {\n      while (cur_l > l) {\n \
    \       add_l(--cur_l);\n      }\n      while (cur_r < r) {\n        add_r(++cur_r);\n\
    \      }\n      while (cur_l < l) {\n        del_l(cur_l++);\n      }\n      while\
    \ (cur_r > r) {\n        del_r(cur_r--);\n      }\n      res[idx] = query();\n\
    \    }\n  }\n\n  template<class Add, class Del, class Query>\n  void solve(Add\
    \ add, Del del, Query query) {\n    solve<Add, Del, Add, Del, Query>(add, del,\
    \ add, del, query);\n  }\n};\n#line 6 \"verify/library_checker/data_structure/static_range_mode_query.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int\
    \ i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  MoQueries<pair<int, int>, 300>\
    \ mo;\n  while (q--) {\n    int l, r;\n    cin >> l >> r;\n    mo.insert(l, r\
    \ - 1);\n  }\n  HashTable<int, int> freq;\n  set<pair<int, int>> st;\n  auto add\
    \ = [&](int p) {\n    if (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]],\
    \ a[p]});\n    }\n    freq[a[p]]++;\n    st.insert({freq[a[p]], a[p]});\n  };\n\
    \  auto del = [&](int p) {\n    if (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]],\
    \ a[p]});\n    }\n    freq[a[p]]--;\n    st.insert({freq[a[p]], a[p]});\n  };\n\
    \  auto query = [&]() {\n    return make_pair(rbegin(st)->se, rbegin(st)->fi);\n\
    \  };\n  mo.solve(add, del, query);\n  for (auto [x, y] : mo.res) {\n    cout\
    \ << x << ' ' << y << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\
    \n\n#include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/pbds/hash_table.hpp\"\
    \n#include \"../../../datastructures/static/mo_queries.hpp\"\n\nint main() {\n\
    \  int n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n;\
    \ i++) {\n    cin >> a[i];\n  }\n  MoQueries<pair<int, int>, 300> mo;\n  while\
    \ (q--) {\n    int l, r;\n    cin >> l >> r;\n    mo.insert(l, r - 1);\n  }\n\
    \  HashTable<int, int> freq;\n  set<pair<int, int>> st;\n  auto add = [&](int\
    \ p) {\n    if (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]],\
    \ a[p]});\n    }\n    freq[a[p]]++;\n    st.insert({freq[a[p]], a[p]});\n  };\n\
    \  auto del = [&](int p) {\n    if (freq.find(a[p]) != freq.end()) {\n      st.extract({freq[a[p]],\
    \ a[p]});\n    }\n    freq[a[p]]--;\n    st.insert({freq[a[p]], a[p]});\n  };\n\
    \  auto query = [&]() {\n    return make_pair(rbegin(st)->se, rbegin(st)->fi);\n\
    \  };\n  mo.solve(add, del, query);\n  for (auto [x, y] : mo.res) {\n    cout\
    \ << x << ' ' << y << '\\n';\n  }\n}"
  dependsOn:
  - datastructures/pbds/hash_table.hpp
  - datastructures/static/mo_queries.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  requiredBy: []
  timestamp: '2024-09-04 17:54:50-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_range_mode_query.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_range_mode_query.test.cpp
- /verify/verify/library_checker/data_structure/static_range_mode_query.test.cpp.html
title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
---
