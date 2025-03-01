---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructures/mergesort_tree.h
    title: datastructures/mergesort_tree.h
  - icon: ':x:'
    path: datastructures/ordered_set.h
    title: datastructures/ordered_set.h
  - icon: ':x:'
    path: numeric/binsearch.h
    title: numeric/binsearch.h
  - icon: ':x:'
    path: template/template.h
    title: template/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"verify/library_checker/data_structure/range_kth_smallest.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n#line\
    \ 1 \"template/template.h\"\n#include <bits/stdc++.h>\n \nusing namespace std;\n\
    \ \n#define arg4(a, b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l);\
    \ i < int(r); i++)\n#define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__,\
    \ rep3, rep2) (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1;\
    \ i >= int(l); i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__,\
    \ per3, per2) (__VA_ARGS__)\n \n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n \n#define pb push_back\n#define eb emplace_back\n#define fi first\n\
    #define se second\n \nusing ll = long long;\nusing pi = pair<int, int>;\nusing\
    \ pl = pair<ll, ll>;\nusing vi = vector<int>;\nusing vl = vector<ll>;\nusing vpi\
    \ = vector<pi>;\nusing vpl = vector<pl>;\n \ntemplate <class T>\nbool ckmin(T\
    \ &a, const T b) {\n    return b < a ? a = b, 1 : 0; \n}\ntemplate <class T>\n\
    bool ckmax(T &a, const T b) {\n    return b > a ? a = b, 1 : 0;\n}\n \ntemplate\
    \ <class T, class U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n\
    \    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi -= (hi -\
    \ i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\ntemplate <class T, class\
    \ U>\nT bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n    for (T\
    \ i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo += (lo + i <= hi &&\
    \ f(lo + i)) * i;\n    }\n    return lo;\n}\n\ntemplate <class T, class = void>\n\
    struct is_range : false_type {};\ntemplate <class T>\nstruct is_range<T, void_t<decltype(begin(declval<T>())),\
    \ decltype(end(declval<T>()))>> : true_type {};\ntemplate <class T>\nusing enable_if_cont\
    \ = enable_if_t<!is_same<T, string>::value && is_range<T>::value, bool>;\n\ntemplate\
    \ <class T, class U>\nistream &operator>>(istream &is, pair<T, U> &p) {\n    is\
    \ >> p.fi >> p.se;\n    return is;\n}\ntemplate <class T, class U>\nostream &operator<<(ostream\
    \ &os, const pair<T, U> &p) {\n    os << p.fi << ' ' << p.se;\n    return os;\n\
    }\ntemplate <class T, enable_if_cont<T> = true>\nistream &operator>>(istream &is,\
    \ T &v) {\n    for (auto &x : v) {\n        is >> x;\n    }\n    return is;\n\
    }\ntemplate <class T, enable_if_cont<T> = true>\nostream &operator<<(ostream &os,\
    \ const T &v) {\n    for (int i = 0; i < sz(v); i++) {\n        os << v[i];\n\
    \        if (i != sz(v) - 1) {\n            os << (is_range<typename T::value_type>::value\
    \ ? '\\n' : ' ');\n        }\n    }\n    return os;\n}\n\ntemplate <class ...T>\n\
    void re(T &...a) {\n    (cin >> ... >> a);\n}\ntemplate <class ...T>\nvoid pr(const\
    \ T &...a) {\n    int p = 0;\n    ((cout << a << (++p == sizeof...(T) ? '\\n'\
    \ : ' ')), ...);\n}\n \nmt19937 rng(chrono::steady_clock::now().time_since_epoch().count());\n\
    \ \nconst int INF = 1e9;\nconst ll INFL = 1e18;\n\nvoid solve() {\n}\n\nint32_t\
    \ main() {\n    cin.tie(0)->sync_with_stdio(0);\n    cin.exceptions(cin.failbit);\n\
    \n    int t = 1;\n    // cin >> t;\n    while (t--) {\n        solve();\n    }\n\
    }\n#line 1 \"numeric/binsearch.h\"\ntemplate <class T, class U>\nT bsmin(T lo,\
    \ T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i)) * i;\n \
    \   }\n    return hi;\n}\n\ntemplate <class T, class U>\nT bsmax(T lo, T hi, U\
    \ f) {\n    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi - lo);\
    \ i > 0; i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n    }\n \
    \   return lo;\n}\n#line 1 \"datastructures/ordered_set.h\"\n#include <ext/pb_ds/assoc_container.hpp>\
    \ \n#include <ext/pb_ds/tree_policy.hpp>\n\nusing namespace __gnu_pbds; \n\ntemplate\
    \ <class T>\nusing ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ntemplate <class T>\nstruct ordered_multiset {\n    int time = 0;\n    ordered_set<pair<T,\
    \ int>> st;\n\n    void insert(T x) {\n        st.insert({x, time++});\n    }\n\
    \    void extract(T x) {\n        auto it = st.lower_bound({x, 0});\n        if\
    \ (it != end(st) && it->fi == x) {\n            st.erase(it);\n        }\n   \
    \ }\n\n    T find_by_order(int k) {\n        return (*st.find_by_order(k)).first;\n\
    \    }\n    int order_of_key(T x) {\n        return st.order_of_key({x, 0});\n\
    \    }\n};\n#line 2 \"datastructures/mergesort_tree.h\"\n\ntemplate <class T>\n\
    struct mergesort_tree {\n    int n;\n    vector<ordered_set<pair<T, int>>> st;\n\
    \ \n    mergesort_tree(const vector<T> &a) : n(sz(a)), st(2 * n) {\n        for\
    \ (int i = 0; i < n; i++) {\n            for (int p = i + n; p > 0; p >>= 1) {\n\
    \                st[p].insert({a[i], i});\n            }\n        }\n    }\n \n\
    \    int query(int l, int r, T v) {\n        int res = 0;\n        for (l += n,\
    \ r += n + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n         \
    \       res += st[l++].order_of_key({v, 0});\n            }\n            if (r\
    \ & 1) {\n                res += st[--r].order_of_key({v, 0});\n            }\n\
    \        }\n        return res;\n    }\n \n    void set(int p, T v) {\n      \
    \  const auto old = *begin(st[p + n]);\n        for (p += n; p > 0; p >>= 1) {\n\
    \            st[p].erase(old);\n            st[p].insert(v);\n        }\n    }\n\
    };\n#line 6 \"verify/library_checker/data_structure/range_kth_smallest.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n \
    \   for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    mergesort_tree<int>\
    \ mt(a);\n    while (q--) {\n        int l, r, k;\n        cin >> l >> r >> k;\n\
    \        r--;\n        cout << bsmin(0, int(1e9), [&](int x) {\n            return\
    \ mt.query(l, r, x + 1) >= k + 1;\n        }) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\n\
    #include \"../../../template/template.h\"\n#include \"../../../numeric/binsearch.h\"\
    \n#include \"../../../datastructures/mergesort_tree.h\"\n\nint main() {\n    int\
    \ n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0; i < n;\
    \ i++) {\n        cin >> a[i];\n    }\n    mergesort_tree<int> mt(a);\n    while\
    \ (q--) {\n        int l, r, k;\n        cin >> l >> r >> k;\n        r--;\n \
    \       cout << bsmin(0, int(1e9), [&](int x) {\n            return mt.query(l,\
    \ r, x + 1) >= k + 1;\n        }) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.h
  - numeric/binsearch.h
  - datastructures/mergesort_tree.h
  - datastructures/ordered_set.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/range_kth_smallest.test.cpp
  requiredBy: []
  timestamp: '2025-02-28 17:36:32-08:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/range_kth_smallest.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp
- /verify/verify/library_checker/data_structure/range_kth_smallest.test.cpp.html
title: verify/library_checker/data_structure/range_kth_smallest.test.cpp
---
