---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/hash_table.h
    title: datastructures/hash_table.h
  - icon: ':heavy_check_mark:'
    path: datastructures/static/mo_queries.h
    title: datastructures/static/mo_queries.h
  - icon: ':heavy_check_mark:'
    path: template/template.h
    title: template/template.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
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
    PROBLEM: https://judge.yosupo.jp/problem/static_range_mode_query
    links:
    - https://judge.yosupo.jp/problem/static_range_mode_query
  bundledCode: "#line 1 \"verify/library_checker/data_structure/static_range_mode_query.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\n\
    \n#line 1 \"template/template.h\"\n#include <bits/stdc++.h>\n#include <ext/pb_ds/assoc_container.hpp>\n\
    \ \nusing namespace std;\nusing namespace __gnu_pbds;\n \n#ifdef LOCAL\n#include\
    \ <utils>\n#else\n#define dbg(...)\n#endif\n \n#define arg4(a, b, c, d, ...) d\n\
    \ \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define rep2(i,\
    \ n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n\
    \ \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define\
    \ per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \ \n#define bg(x) begin(x)\n#define all(x) bg(x), end(x)\n#define sz(x) int(size(x))\n\
    \ \n#define acc accumulate\n#define mne min_element\n#define mxe max_element\n\
    #define lb lower_bound\n#define ub upper_bound\n \n#define pb push_back\n#define\
    \ eb emplace_back\n#define pbk pop_back\n#define ins insert\n#define era erase\n\
    \ \n#define fi first\n#define se second\n \ntemplate <class T, size_t N> using\
    \ arr = array<T, N>;\ntemplate <class T> using vec = vector<T>;\ntemplate <class\
    \ T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n\
    \ \nusing ll = long long;\nusing ld = long double;\nusing str = string;\n \nusing\
    \ pi = pair<int, int>;\nusing pl = pair<ll, ll>;\n \nusing vb = vec<bool>;\nusing\
    \ vi = vec<int>; \nusing vl = vec<ll>;\nusing vd = vec<ld>;\nusing vs = vec<str>;\n\
    using vpi = vec<pi>;\nusing vpl = vec<pl>;\n\ntemplate <class T>\nbool ckmin(T\
    \ &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class T>\nbool ckmax(T\
    \ &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n\ntemplate <class T, class\
    \ U>\nT bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T\
    \ i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi -= (hi - i >= lo &&\
    \ f(hi - i)) * i;\n    }\n    return hi;\n}\ntemplate <class T, class U>\nT bsmax(T\
    \ lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n \
    \   }\n    return lo;\n}\n\nconst int INF = INT_MAX / 2;\nconst ll INFL = LLONG_MAX\
    \ / 2;\n\n// void solve() {\n// }\n\n// int main() {\n//     cin.tie(0)->sync_with_stdio(0);\n\
    //     cin.exceptions(cin.failbit);\n\n//     int t = 1;\n//     // cin >> t;\n\
    //     while (t--) {\n//         solve();\n//     }\n// }\n#line 2 \"datastructures/hash_table.h\"\
    \n\nstruct CustomHash {\n    static uint64_t splitmix64(uint64_t x) {\n      \
    \  x += 0x9e3779b97f4a7c15;\n        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n\
    \        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n        return x ^ (x >> 31);\n\
    \    }\n\n    size_t operator()(uint64_t x) const {\n        static const uint64_t\
    \ FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();\n   \
    \     return splitmix64(x + FIXED_RANDOM);\n    }\n};\n\ntemplate <class T, class\
    \ U>\nusing HashTable = __gnu_pbds::gp_hash_table<T, U, CustomHash>;\n#line 1\
    \ \"datastructures/static/mo_queries.h\"\ntemplate <class T, int B>\nstruct MoQueries\
    \ {\n    vector<array<int, 3>> queries;\n    vector<T> res;\n\n    MoQueries()\
    \ {}\n\n    void insert(int l, int r) {\n        queries.push_back({l, r, sz(queries)});\n\
    \    }\n\n    template<class AddL, class DelL, class AddR, class DelR, class Query>\n\
    \    void solve(AddL addL, DelL delL, AddR addR, DelR delR, Query query) {\n \
    \       sort(all(queries), [](array<int, 3> a, array<int, 3> b) {\n          \
    \  if (a[1] / B != b[1] / B) {\n                return a[1] / B < b[1] / B;\n\
    \            }\n            return a[0] < b[0];\n        });\n        res.resize(sz(queries));\n\
    \n        int curL = 0, curR = -1;\n        for (auto [l, r, idx] : queries) {\n\
    \            while (curL > l) {\n                addL(--curL);\n            }\n\
    \            while (curR < r) {\n                addR(++curR);\n            }\n\
    \            while (curL < l) {\n                delL(curL++);\n            }\n\
    \            while (curR > r) {\n                delR(curR--);\n            }\n\
    \            res[idx] = query();\n        }\n    }\n\n    template<class Add,\
    \ class Del, class Query>\n    void solve(Add add, Del del, Query query) {\n \
    \       solve<Add, Del, Add, Del, Query>(add, del, add, del, query);\n    }\n\
    };\n#line 6 \"verify/library_checker/data_structure/static_range_mode_query.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n \
    \   for (int i = 0; i < n; i++) {\n        cin >> a[i];\n    }\n    MoQueries<pair<int,\
    \ int>, 300> mo;\n    while (q--) {\n        int l, r;\n        cin >> l >> r;\n\
    \        mo.insert(l, r - 1);\n    }\n\n    HashTable<int, int> freq;\n    set<pair<int,\
    \ int>> st;\n\n    auto add = [&](int p) {\n        if (freq.find(a[p]) != freq.end())\
    \ {\n            st.extract({freq[a[p]], a[p]});\n        }\n        freq[a[p]]++;\n\
    \        st.insert({freq[a[p]], a[p]});\n    };\n\n    auto del = [&](int p) {\n\
    \        if (freq.find(a[p]) != freq.end()) {\n            st.extract({freq[a[p]],\
    \ a[p]});\n        }\n        freq[a[p]]--;\n        st.insert({freq[a[p]], a[p]});\n\
    \    };\n\n    auto query = [&]() {\n        return make_pair(rbegin(st)->second,\
    \ rbegin(st)->first);\n    };\n\n    mo.solve(add, del, query);\n    for (auto\
    \ [x, y] : mo.res) {\n        cout << x << ' ' << y << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_mode_query\"\
    \n\n#include \"../../../template/template.h\"\n#include \"../../../datastructures/hash_table.h\"\
    \n#include \"../../../datastructures/static/mo_queries.h\"\n\nint main() {\n \
    \   int n, q;\n    cin >> n >> q;\n    vector<int> a(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        cin >> a[i];\n    }\n    MoQueries<pair<int, int>, 300>\
    \ mo;\n    while (q--) {\n        int l, r;\n        cin >> l >> r;\n        mo.insert(l,\
    \ r - 1);\n    }\n\n    HashTable<int, int> freq;\n    set<pair<int, int>> st;\n\
    \n    auto add = [&](int p) {\n        if (freq.find(a[p]) != freq.end()) {\n\
    \            st.extract({freq[a[p]], a[p]});\n        }\n        freq[a[p]]++;\n\
    \        st.insert({freq[a[p]], a[p]});\n    };\n\n    auto del = [&](int p) {\n\
    \        if (freq.find(a[p]) != freq.end()) {\n            st.extract({freq[a[p]],\
    \ a[p]});\n        }\n        freq[a[p]]--;\n        st.insert({freq[a[p]], a[p]});\n\
    \    };\n\n    auto query = [&]() {\n        return make_pair(rbegin(st)->second,\
    \ rbegin(st)->first);\n    };\n\n    mo.solve(add, del, query);\n    for (auto\
    \ [x, y] : mo.res) {\n        cout << x << ' ' << y << '\\n';\n    }\n}"
  dependsOn:
  - template/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - datastructures/hash_table.h
  - datastructures/static/mo_queries.h
  isVerificationFile: true
  path: verify/library_checker/data_structure/static_range_mode_query.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 20:41:56-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/data_structure/static_range_mode_query.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/data_structure/static_range_mode_query.test.cpp
- /verify/verify/library_checker/data_structure/static_range_mode_query.test.cpp.html
title: verify/library_checker/data_structure/static_range_mode_query.test.cpp
---
