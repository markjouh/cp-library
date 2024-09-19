---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: datastructures/segtree/segtree_sparse.h
    title: datastructures/segtree/segtree_sparse.h
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"verify/custom/datastructure/segment_tree_sparse.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define arg4(a, b, c, d, ...) d\n \n#define\
    \ rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n#define rep2(i, n) rep3(i,\
    \ 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2) (__VA_ARGS__)\n \n#define\
    \ per3(i, l, r) for (int i = int(r) - 1; i >= int(l); i--)\n#define per2(i, n)\
    \ per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3, per2) (__VA_ARGS__)\n\
    \n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n#define pb push_back\n\
    #define eb emplace_back\n#define f first\n#define s second\n\nusing ll = long\
    \ long;\nusing u32 = unsigned int;\nusing u64 = unsigned long long;\n\ntemplate\
    \ <class T>\nbool ckmin(T &a, const T &b) {\n    return b < a ? a = b, 1 : 0;\n\
    }\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n    return b > a ? a\
    \ = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n        cin.tie(0)->sync_with_stdio(0);\n\
    \        cin.exceptions(cin.failbit);\n        cout << setprecision(10) << fixed;\n\
    \    }\n} init_io;\n#line 2 \"datastructures/segtree/segtree_sparse.h\"\n\ntemplate\
    \ <class T, T(*op)(T, T), T(*id)()>\nstruct SparseSegtree {\n    SparseSegtree()\
    \ {}\n    \n    SparseSegtree(int n) {\n        log = __lg(n - 1) + 1;\n     \
    \   tree_sz = 1 << log;\n        st.push_back(id());\n        ch.emplace_back(-1,\
    \ -1);\n    }\n\n    void set(int p, T v) {\n        buf[0] = idx = 0;\n     \
    \   int tl = 0, tr = tree_sz;\n        while (tl + 1 != tr) {\n            int\
    \ mid = (tl + tr) >> 1;\n            if (p < mid) {\n                buf[idx +\
    \ 1] = get_l(buf[idx]);\n                tr = mid;\n            } else {\n   \
    \             buf[idx + 1] = get_r(buf[idx]);\n                tl = mid;\n   \
    \         }\n            idx++;\n        }\n        st[buf[idx--]] = v;\n    \
    \    while (idx >= 0) {\n            pull(buf[idx--]);\n        }\n    }\n\n \
    \   T query(int l, int r) {\n        return query(l, r + 1, 0, 0, tree_sz);\n\
    \    }\n\nprivate:\n    int log, tree_sz;\n    vector<T> st;\n    vector<pair<int,\
    \ int>> ch;\n\n    int buf[32];\n    int idx;\n\n    int get_l(int x) {\n    \
    \    if (ch[x].first == -1) {\n            ch[x].first = sz(st);\n           \
    \ st.push_back(id());\n            ch.emplace_back(-1, -1);\n        }\n     \
    \   return ch[x].first;\n    }\n\n    int get_r(int x) {\n        if (ch[x].second\
    \ == -1) {\n            ch[x].second = sz(st);\n            st.push_back(id());\n\
    \            ch.emplace_back(-1, -1);\n        }\n        return ch[x].second;\n\
    \    }\n\n    void pull(int x) {\n        if (ch[x].first == -1) {\n         \
    \   st[x] = st[ch[x].second];\n        } else if (ch[x].second != -1) {\n    \
    \        st[x] = op(st[ch[x].first], st[ch[x].second]);\n        } else {\n  \
    \          st[x] = st[ch[x].first];\n        }\n    }\n\n    T query(int l, int\
    \ r, int x, int tl, int tr) {\n        if (x == -1 || tl >= r || tr <= l) {\n\
    \            return id();\n        }\n        if (tl >= l && tr <= r) {\n    \
    \        return st[x];\n        }\n        int mid = (tl + tr) >> 1;\n       \
    \ return op(query(l, r, ch[x].first, tl, mid), query(l, r, ch[x].second, mid,\
    \ tr));\n    }\n};\n#line 5 \"verify/custom/datastructure/segment_tree_sparse.test.cpp\"\
    \n\nconst int N = 1e9, Q = 5e4;\n\nll op(ll x, ll y) {\n    return x + y;\n}\n\
    \nll id() {\n    return 0;\n}\n\nint main() {\n    vector<pair<int, int>> a;\n\
    \    SparseSegtree<ll, op, id> st(N);\n\n    for (int i = 0; i < Q; i++) {\n \
    \       if (rand_bool()) {\n            const int p = rand_int(N), v = rand_int(1e9);\n\
    \            bool flag = false;\n            for (auto &b : a) {\n           \
    \     if (b.first == p) {\n                    flag = true;\n                \
    \    b.second = v;\n                    break;\n                }\n          \
    \  }\n            if (!flag) {\n                a.emplace_back(p, v);\n      \
    \      }\n            st.set(p, v);\n        } else {\n            int l = rand_int(N),\
    \ r = rand_int(N);\n            if (l > r) {\n                swap(l, r);\n  \
    \          }\n            ll sum = 0;\n            for (auto [p, v] : a) {\n \
    \               if (p >= l && p <= r) {\n                    sum += v;\n     \
    \           }\n            }\n            assert(st.query(l, r) == sum);\n   \
    \     }\n    }\n\n    cerr << \"Tests passed\\n\";\n\n    int a_, b_;\n    cin\
    \ >> a_ >> b_;\n    cout << a_ + b_ << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../datastructures/segtree/segtree_sparse.h\"\
    \n\nconst int N = 1e9, Q = 5e4;\n\nll op(ll x, ll y) {\n    return x + y;\n}\n\
    \nll id() {\n    return 0;\n}\n\nint main() {\n    vector<pair<int, int>> a;\n\
    \    SparseSegtree<ll, op, id> st(N);\n\n    for (int i = 0; i < Q; i++) {\n \
    \       if (rand_bool()) {\n            const int p = rand_int(N), v = rand_int(1e9);\n\
    \            bool flag = false;\n            for (auto &b : a) {\n           \
    \     if (b.first == p) {\n                    flag = true;\n                \
    \    b.second = v;\n                    break;\n                }\n          \
    \  }\n            if (!flag) {\n                a.emplace_back(p, v);\n      \
    \      }\n            st.set(p, v);\n        } else {\n            int l = rand_int(N),\
    \ r = rand_int(N);\n            if (l > r) {\n                swap(l, r);\n  \
    \          }\n            ll sum = 0;\n            for (auto [p, v] : a) {\n \
    \               if (p >= l && p <= r) {\n                    sum += v;\n     \
    \           }\n            }\n            assert(st.query(l, r) == sum);\n   \
    \     }\n    }\n\n    cerr << \"Tests passed\\n\";\n\n    int a_, b_;\n    cin\
    \ >> a_ >> b_;\n    cout << a_ + b_ << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - datastructures/segtree/segtree_sparse.h
  isVerificationFile: true
  path: verify/custom/datastructure/segment_tree_sparse.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/custom/datastructure/segment_tree_sparse.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/datastructure/segment_tree_sparse.test.cpp
- /verify/verify/custom/datastructure/segment_tree_sparse.test.cpp.html
title: verify/custom/datastructure/segment_tree_sparse.test.cpp
---
