---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructures/static/rmq.h
    title: datastructures/static/rmq.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructures/static/rmq.h\"\n\ntemplate <class T>\nT min_f(T\
    \ x, T y) {\n    return x < y ? x : y;\n}\ntemplate <class T>\nT max_f(T x, T\
    \ y) {\n    return x > y ? x : y;\n}\n\ntemplate <class T, auto op = min_f<T>>\n\
    struct RMQ {\n    int n, log;\n    vector<vector<T>> st;\n\n    RMQ() {}\n   \
    \ RMQ(const vector<T> &a) : n(sz(a)), log(__lg(n) + 1) {\n        st.resize(log);\n\
    \        st[0] = a;\n        for (int i = 1; i < log; i++) {\n            st[i].resize(n\
    \ - (1 << i) + 1);\n            for (int j = 0; j < sz(st[i]); j++) {\n      \
    \          st[i][j] = op(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);\n     \
    \       }\n        }\n    }\n\n    T query(int l, int r) {\n        assert(l <=\
    \ r);\n        int i = __lg(++r - l);\n        return op(st[i][l], st[i][r - (1\
    \ << i)]);\n    }\n};\n#line 2 \"graphs/trees/lca.h\"\n\nstruct LCA {\n    vector<int>\
    \ tin, dep;\n    RMQ<pair<int, int>> rmq;\n\n    LCA(const vector<vector<int>>\
    \ &g) {\n        const int n = sz(g);\n        tin.resize(n), dep.resize(n);\n\
    \n        vector<pair<int, int>> d;\n\n        auto dfs = [&](auto &&self, int\
    \ u, int par) -> void {\n            tin[u] = sz(d);\n            d.emplace_back(dep[u],\
    \ u);\n            for (int v : g[u]) {\n                if (v != par) {\n   \
    \                 dep[v] = dep[u] + 1;\n                    self(self, v, u);\n\
    \                    d.emplace_back(dep[u], u);\n                }\n         \
    \   }\n        };\n\n        dfs(dfs, 0, -1);\n        rmq = RMQ(d);\n    }\n\n\
    \    int lca(int u, int v) {\n        if (tin[u] > tin[v]) {\n            swap(u,\
    \ v);\n        }\n        return rmq.query(tin[u], tin[v]).second;\n    }\n  \
    \  int dist(int u, int v) {\n        if (tin[u] > tin[v]) {\n            swap(u,\
    \ v);\n        }\n        return dep[u] + dep[v] - 2 * rmq.query(tin[u], tin[v]).first;\n\
    \    }\n};\n"
  code: "#include \"../../datastructures/static/rmq.h\"\n\nstruct LCA {\n    vector<int>\
    \ tin, dep;\n    RMQ<pair<int, int>> rmq;\n\n    LCA(const vector<vector<int>>\
    \ &g) {\n        const int n = sz(g);\n        tin.resize(n), dep.resize(n);\n\
    \n        vector<pair<int, int>> d;\n\n        auto dfs = [&](auto &&self, int\
    \ u, int par) -> void {\n            tin[u] = sz(d);\n            d.emplace_back(dep[u],\
    \ u);\n            for (int v : g[u]) {\n                if (v != par) {\n   \
    \                 dep[v] = dep[u] + 1;\n                    self(self, v, u);\n\
    \                    d.emplace_back(dep[u], u);\n                }\n         \
    \   }\n        };\n\n        dfs(dfs, 0, -1);\n        rmq = RMQ(d);\n    }\n\n\
    \    int lca(int u, int v) {\n        if (tin[u] > tin[v]) {\n            swap(u,\
    \ v);\n        }\n        return rmq.query(tin[u], tin[v]).second;\n    }\n  \
    \  int dist(int u, int v) {\n        if (tin[u] > tin[v]) {\n            swap(u,\
    \ v);\n        }\n        return dep[u] + dep[v] - 2 * rmq.query(tin[u], tin[v]).first;\n\
    \    }\n};"
  dependsOn:
  - datastructures/static/rmq.h
  isVerificationFile: false
  path: graphs/trees/lca.h
  requiredBy: []
  timestamp: '2024-10-25 19:46:34-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graphs/trees/lca.h
layout: document
redirect_from:
- /library/graphs/trees/lca.h
- /library/graphs/trees/lca.h.html
title: graphs/trees/lca.h
---
