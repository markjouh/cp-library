---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_indexed_tree/bit.h
    title: datastructures/binary_indexed_tree/bit.h
  - icon: ':heavy_check_mark:'
    path: datastructures/binary_indexed_tree/bit_dual.h
    title: datastructures/binary_indexed_tree/bit_dual.h
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G
  bundledCode: "#line 1 \"verify/aizu/dsl/rsq_and_raq.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\n\n#line\
    \ 1 \"template/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\n#define pb push_back\n\
    #define eb emplace_back\n#define fi first\n#define se second\n\nusing ll = long\
    \ long;\n\n// void solve() {\n// }\n\n// int main() {\n//     cin.tie(0)->sync_with_stdio(0);\n\
    //     cin.exceptions(cin.failbit);\n\n//     int t = 1;\n//     // cin >> t;\n\
    //     while (t--) {\n//         solve();\n//     }\n\n//     return 0;\n// }\n\
    #line 1 \"datastructures/binary_indexed_tree/bit.h\"\ntemplate <class T>\nstruct\
    \ BIT {\n    int n;\n    vector<T> ft;\n\n    BIT(int n_) : n(n_), ft(n + 1) {}\n\
    \n    BIT(const vector<T> &a) : n(sz(a)), ft(n + 1) {\n        for (int i = 1;\
    \ i <= n; i++) {\n            ft[i] += a[i - 1];\n            if (i + (i & -i)\
    \ <= n) {\n                ft[i + (i & -i)] += ft[i];\n            }\n       \
    \ }\n    }\n\n    void add(int p, T v) {\n        for (p++; p <= n; p += p & -p)\
    \ {\n            ft[p] += v;\n        }\n    }\n\n    T sum(int r) {\n       \
    \ T res = 0;\n        for (r++; r > 0; r -= r & -r) {\n            res += ft[r];\n\
    \        }\n        return res;\n    }\n\n    T sum(int l, int r) {\n        return\
    \ sum(r) - sum(l - 1);\n    }\n};\n#line 2 \"datastructures/binary_indexed_tree/bit_dual.h\"\
    \n\ntemplate <class T>\nstruct BITDual {\n    int n;\n    BIT<T> pref, suff;\n\
    \n    BITDual(int n_) : n(n_), pref(n), suff(n) {}\n\n    T sum(int r) {\n   \
    \     return pref.sum(r - 1) + suff.sum(n - r - 1) * (r + 1);\n    }\n\n    T\
    \ sum(int l, int r) {\n        return sum(r) - (l > 0 ? sum(l - 1) : 0);\n   \
    \ }\n\n    void add(int r, T v) {\n        pref.add(r, v * (r + 1));\n       \
    \ suff.add(n - r - 1, v);\n    }\n\n    void add(int l, int r, T v) {\n      \
    \  add(r, v);\n        if (l > 0) {\n            add(l - 1, T(0) - T(v));\n  \
    \      }\n    }\n};\n#line 5 \"verify/aizu/dsl/rsq_and_raq.test.cpp\"\n\nint main()\
    \ {\n    int n, q;\n    cin >> n >> q;\n    BITDual<ll> ft(n);\n    while (q--)\
    \ {\n        bool t;\n        int l, r;\n        cin >> t >> l >> r;\n       \
    \ l--; r--;\n        if (t) {\n            cout << ft.sum(l, r) << '\\n';\n  \
    \      } else {\n            int x;\n            cin >> x;\n            ft.add(l,\
    \ r, x);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../datastructures/binary_indexed_tree/bit_dual.h\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    BITDual<ll> ft(n);\n\
    \    while (q--) {\n        bool t;\n        int l, r;\n        cin >> t >> l\
    \ >> r;\n        l--; r--;\n        if (t) {\n            cout << ft.sum(l, r)\
    \ << '\\n';\n        } else {\n            int x;\n            cin >> x;\n   \
    \         ft.add(l, r, x);\n        }\n    }\n}"
  dependsOn:
  - template/template.h
  - utils/bits/stdc++.h
  - datastructures/binary_indexed_tree/bit_dual.h
  - datastructures/binary_indexed_tree/bit.h
  isVerificationFile: true
  path: verify/aizu/dsl/rsq_and_raq.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 20:34:38-05:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/aizu/dsl/rsq_and_raq.test.cpp
layout: document
redirect_from:
- /verify/verify/aizu/dsl/rsq_and_raq.test.cpp
- /verify/verify/aizu/dsl/rsq_and_raq.test.cpp.html
title: verify/aizu/dsl/rsq_and_raq.test.cpp
---
