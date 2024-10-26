---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graphs/shortest_paths/dijkstras.h
    title: graphs/shortest_paths/dijkstras.h
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
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"verify/library_checker/graph/shortest_path.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#line 1 \"\
    template/template.h\"\n#include <bits/stdc++.h>\n#include <ext/pb_ds/assoc_container.hpp>\n\
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
    //     while (t--) {\n//         solve();\n//     }\n// }\n#line 1 \"graphs/shortest_paths/dijkstras.h\"\
    \ntemplate <class T>\nauto dijkstras(const vector<vector<pair<int, int>>> &g,\
    \ int start = 0) {\n    priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T,\
    \ int>>> pq;\n\n    vector<T> dist(sz(g), numeric_limits<T>::max());\n    vector<int>\
    \ from(sz(g), -1);\n    \n    dist[start] = 0;\n    pq.emplace(0, start);\n\n\
    \    while (sz(pq)) {\n        auto [d, u] = pq.top();\n        pq.pop();\n  \
    \      if (d != dist[u]) {\n            continue;\n        }\n        for (auto\
    \ [v, w] : g[u]) {\n            if (d + w < dist[v]) {\n                dist[v]\
    \ = d + w;\n                from[v] = u;\n                pq.emplace(dist[v],\
    \ v);\n            }\n        }\n    }\n    return make_pair(dist, from);\n}\n\
    #line 5 \"verify/library_checker/graph/shortest_path.test.cpp\"\n\nint main()\
    \ {\n    int n, m, s, t;\n    cin >> n >> m >> s >> t;\n    vector<vector<pair<int,\
    \ int>>> g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v, w;\n    \
    \    cin >> u >> v >> w;\n        g[u].emplace_back(v, w);\n    }\n    \n    auto\
    \ [dist, from] = dijkstras<ll>(g, s);\n    if (dist[t] != LLONG_MAX) {\n     \
    \   cout << dist[t] << ' ';\n        vector<pair<int, int>> path;\n        int\
    \ p = t;\n        while (p != s) {\n            path.emplace_back(from[p], p);\n\
    \            p = from[p];\n        }\n        reverse(all(path));\n        cout\
    \ << sz(path) << '\\n';\n        for (auto [u, v] : path) {\n            cout\
    \ << u << ' ' << v << '\\n';\n        }\n    } else {\n        cout << -1 << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../../../template/template.h\"\n#include \"../../../graphs/shortest_paths/dijkstras.h\"\
    \n\nint main() {\n    int n, m, s, t;\n    cin >> n >> m >> s >> t;\n    vector<vector<pair<int,\
    \ int>>> g(n);\n    for (int i = 0; i < m; i++) {\n        int u, v, w;\n    \
    \    cin >> u >> v >> w;\n        g[u].emplace_back(v, w);\n    }\n    \n    auto\
    \ [dist, from] = dijkstras<ll>(g, s);\n    if (dist[t] != LLONG_MAX) {\n     \
    \   cout << dist[t] << ' ';\n        vector<pair<int, int>> path;\n        int\
    \ p = t;\n        while (p != s) {\n            path.emplace_back(from[p], p);\n\
    \            p = from[p];\n        }\n        reverse(all(path));\n        cout\
    \ << sz(path) << '\\n';\n        for (auto [u, v] : path) {\n            cout\
    \ << u << ' ' << v << '\\n';\n        }\n    } else {\n        cout << -1 << '\\\
    n';\n    }\n}"
  dependsOn:
  - template/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - graphs/shortest_paths/dijkstras.h
  isVerificationFile: true
  path: verify/library_checker/graph/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2024-10-25 20:32:34-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/library_checker/graph/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/graph/shortest_path.test.cpp
- /verify/verify/library_checker/graph/shortest_path.test.cpp.html
title: verify/library_checker/graph/shortest_path.test.cpp
---
