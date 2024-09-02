---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/static/mergesort_tree.hpp
    title: datastructures/static/mergesort_tree.hpp
  - icon: ':heavy_check_mark:'
    path: numeric/binary_search.hpp
    title: numeric/binary_search.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/library_checker/data_structure/range_kth_smallest.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
    \ 1 \"verify/boilerplate.hpp\"\n#include <algorithm>\n#include <array>\n#include\
    \ <bitset>\n#include <cassert>\n#include <chrono>\n#include <climits>\n#include\
    \ <cmath>\n#include <cstdint>\n#include <cstring>\n#include <functional>\n#include\
    \ <iomanip>\n#include <iostream>\n#include <map>\n#include <numeric>\n#include\
    \ <queue>\n#include <random>\n#include <set>\n#include <vector>\n\nusing namespace\
    \ std;\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define\
    \ pb push_back\n#define eb emplace_back\n#define fi first\n#define se second\n\
    \nusing ll = long long;\nusing pii = pair<int, int>;\nusing pll = pair<ll, ll>;\n\
    \ntemplate <class T>\nint lg(T x) {\n#if __has_builtin(__lg)\n  return __lg(x);\n\
    #else\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n#endif\n\
    }\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n  return b < a ? a =\
    \ b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n  return\
    \ b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T = int>\nstatic constexpr T inf\
    \ = numeric_limits<T>::max() / 2;\n\nstruct InitIO {\n  InitIO() {\n    cin.tie(0)->sync_with_stdio(0);\n\
    \    cin.exceptions(cin.failbit);\n    cout << setprecision(10) << fixed;\n  }\n\
    } init_io;\n#line 2 \"datastructures/static/mergesort_tree.hpp\"\n\ntemplate <class\
    \ T>\nstruct MergesortTree {\n  int n;\n  vector<vector<T>> st;\n\n  MergesortTree(const\
    \ vector<T> &a) : n(sz(a)), st(2 * n) {\n    for (int i = 0; i < n; i++) {\n \
    \     st[i + n] = {a[i]};\n    }\n    for (int i = n - 1; i > 0; i--) {\n    \
    \  merge(begin(st[i << 1]), end(st[i << 1]), begin(st[i << 1 | 1]),\n        end(st[i\
    \ << 1 | 1]), back_inserter(st[i]));\n    }\n  }\n\n  T query(int l, int r, T\
    \ v) {\n    T ls = 0, rs = 0;\n    for (l += n, r += n + 1; l < r; l >>= 1, r\
    \ >>= 1) {\n      if (l & 1) {\n        ls += lower_bound(all(st[l]), v) - begin(st[l]);\n\
    \        l++;\n      }\n      if (r & 1) {\n        r--;\n        rs += lower_bound(all(st[r]),\
    \ v) - begin(st[r]);\n      }\n    }\n    return ls + rs;\n  }\n};\n#line 2 \"\
    numeric/binary_search.hpp\"\n\ntemplate <class T, class U>\nT bsmin(T lo, T hi,\
    \ U f) {\n  assert(lo <= hi);\n  hi++;\n  for (T i = T(1) << lg(hi - lo); i >\
    \ 0; i >>= 1) {\n    hi -= (hi - i >= lo && f(hi - i)) * i;\n  }\n  return hi;\n\
    }\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U f) {\n  assert(lo <= hi);\n\
    \  lo--;\n  for (T i = T(1) << lg(hi - lo); i > 0; i >>= 1) {\n    lo += (lo +\
    \ i <= hi && f(lo + i)) * i;\n  }\n  return lo;\n}\n#line 6 \"verify/library_checker/data_structure/range_kth_smallest.test.cpp\"\
    \n\nint main() {\n  int n, q;\n  cin >> n >> q;\n  vector<int> a(n);\n  for (int\
    \ i = 0; i < n; i++) {\n    cin >> a[i];\n  }\n  MergesortTree<int> mt(a);\n \
    \ while (q--) {\n    int l, r, k;\n    cin >> l >> r >> k;\n    r--;\n    cout\
    \ << bsmin(0, inf<>, [&](int x) {\n      return mt.query(l, r, x + 1) >= k + 1;\n\
    \    }) << '\\n';\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../boilerplate.hpp\"\n#include \"../../../datastructures/static/mergesort_tree.hpp\"\
    \n#include \"../../../numeric/binary_search.hpp\"\n\nint main() {\n  int n, q;\n\
    \  cin >> n >> q;\n  vector<int> a(n);\n  for (int i = 0; i < n; i++) {\n    cin\
    \ >> a[i];\n  }\n  MergesortTree<int> mt(a);\n  while (q--) {\n    int l, r, k;\n\
    \    cin >> l >> r >> k;\n    r--;\n    cout << bsmin(0, inf<>, [&](int x) {\n\
    \      return mt.query(l, r, x + 1) >= k + 1;\n    }) << '\\n';\n  }\n}"
  dependsOn:
  - datastructures/static/mergesort_tree.hpp
  - numeric/binary_search.hpp
  isVerificationFile: true
  path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2024-09-01 21:27:07-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp.html
title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
---
