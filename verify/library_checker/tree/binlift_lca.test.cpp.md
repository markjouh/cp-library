---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graphs/trees/binary_lifting.h
    title: graphs/trees/binary_lifting.h
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
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"verify/library_checker/tree/binlift_lca.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#line 1 \"template/template.h\"\
    \n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <cctype>\n#include <cerrno>\n#include <cfloat>\n#include <chrono>\n#include\
    \ <climits>\n#include <clocale>\n#include <cmath>\n#include <complex>\n#include\
    \ <csetjmp>\n#include <csignal>\n#include <cstdarg>\n#include <cstddef>\n#include\
    \ <cstdint>\n#include <cstdio>\n#include <cstdlib>\n#include <cstring>\n#include\
    \ <ctime>\n#include <cwchar>\n#include <cwctype>\n#include <deque>\n#include <exception>\n\
    #include <forward_list>\n#include <fstream>\n#include <functional>\n#include <iomanip>\n\
    #include <ios>\n#include <iosfwd>\n#include <iostream>\n#include <istream>\n#include\
    \ <iterator>\n#include <limits>\n#include <list>\n#include <locale>\n#include\
    \ <map>\n#include <memory>\n#include <new>\n#include <numeric>\n#include <ostream>\n\
    #include <queue>\n#include <random>\n#include <ratio>\n#include <regex>\n#include\
    \ <set>\n#include <sstream>\n#include <stack>\n#include <stdexcept>\n#include\
    \ <streambuf>\n#include <string>\n#include <thread>\n#include <tuple>\n#include\
    \ <type_traits>\n#include <typeinfo>\n#include <unordered_map>\n#include <unordered_set>\n\
    #include <utility>\n#include <valarray>\n#include <vector>\n\n// C++11\n#include\
    \ <atomic>\n#include <condition_variable>\n#include <future>\n#include <initializer_list>\n\
    #include <mutex>\n#include <scoped_allocator>\n#line 71 \"template/template.h\"\
    \n#include <typeindex>\n\n// C++14\n#include <shared_mutex>\n\n// C++17\n#if __cplusplus\
    \ >= 201703L\n#include <any>\n#include <charconv>\n#include <execution>\n#include\
    \ <filesystem>\n#include <memory_resource>\n#include <optional>\n#include <string_view>\n\
    #include <variant>\n#endif\n\n#define sz(x) int(size(x))\n#define all(x) begin(x),\
    \ end(x)\n\n// Portable builtin implementations for compilers that don't have\
    \ them\n// __lg(x) - returns floor(log2(x)) for x > 0\n#ifndef __has_builtin\n\
    \  #define __has_builtin(x) 0\n#endif\n\n#if !__has_builtin(__lg)\n  inline int\
    \ __lg(int x) {\n    assert(x > 0);\n    int r = 0;\n    while (x >>= 1) r++;\n\
    \    return r;\n  }\n  inline int __lg(unsigned int x) {\n    assert(x > 0);\n\
    \    int r = 0;\n    while (x >>= 1) r++;\n    return r;\n  }\n  inline int __lg(long\
    \ long x) {\n    assert(x > 0);\n    int r = 0;\n    while (x >>= 1) r++;\n  \
    \  return r;\n  }\n  inline int __lg(unsigned long long x) {\n    assert(x > 0);\n\
    \    int r = 0;\n    while (x >>= 1) r++;\n    return r;\n  }\n#endif\n\n// __builtin_popcount\
    \ - count number of set bits\n#if !__has_builtin(__builtin_popcount)\n  inline\
    \ int __builtin_popcount(unsigned int x) {\n    int c = 0;\n    while (x) { c++;\
    \ x &= x - 1; }\n    return c;\n  }\n#endif\n\n#if !__has_builtin(__builtin_popcountll)\n\
    \  inline int __builtin_popcountll(unsigned long long x) {\n    int c = 0;\n \
    \   while (x) { c++; x &= x - 1; }\n    return c;\n  }\n#endif\n\n// __builtin_clz\
    \ - count leading zeros (undefined for x=0)\n#if !__has_builtin(__builtin_clz)\n\
    \  inline int __builtin_clz(unsigned int x) {\n    assert(x != 0);\n    int c\
    \ = 0;\n    if (x <= 0x0000FFFF) { c += 16; x <<= 16; }\n    if (x <= 0x00FFFFFF)\
    \ { c += 8; x <<= 8; }\n    if (x <= 0x0FFFFFFF) { c += 4; x <<= 4; }\n    if\
    \ (x <= 0x3FFFFFFF) { c += 2; x <<= 2; }\n    if (x <= 0x7FFFFFFF) { c += 1; }\n\
    \    return c;\n  }\n#endif\n\n#if !__has_builtin(__builtin_clzll)\n  inline int\
    \ __builtin_clzll(unsigned long long x) {\n    assert(x != 0);\n    int c = 0;\n\
    \    if (x <= 0x00000000FFFFFFFFULL) { c += 32; x <<= 32; }\n    if (x <= 0x0000FFFFFFFFFFFFULL)\
    \ { c += 16; x <<= 16; }\n    if (x <= 0x00FFFFFFFFFFFFFFULL) { c += 8; x <<=\
    \ 8; }\n    if (x <= 0x0FFFFFFFFFFFFFFFULL) { c += 4; x <<= 4; }\n    if (x <=\
    \ 0x3FFFFFFFFFFFFFFFULL) { c += 2; x <<= 2; }\n    if (x <= 0x7FFFFFFFFFFFFFFFULL)\
    \ { c += 1; }\n    return c;\n  }\n#endif\n\n// __builtin_ctz - count trailing\
    \ zeros (undefined for x=0)\n#if !__has_builtin(__builtin_ctz)\n  inline int __builtin_ctz(unsigned\
    \ int x) {\n    assert(x != 0);\n    int c = 0;\n    if ((x & 0x0000FFFF) == 0)\
    \ { c += 16; x >>= 16; }\n    if ((x & 0x000000FF) == 0) { c += 8; x >>= 8; }\n\
    \    if ((x & 0x0000000F) == 0) { c += 4; x >>= 4; }\n    if ((x & 0x00000003)\
    \ == 0) { c += 2; x >>= 2; }\n    if ((x & 0x00000001) == 0) { c += 1; }\n   \
    \ return c;\n  }\n#endif\n\n#if !__has_builtin(__builtin_ctzll)\n  inline int\
    \ __builtin_ctzll(unsigned long long x) {\n    assert(x != 0);\n    int c = 0;\n\
    \    if ((x & 0x00000000FFFFFFFFULL) == 0) { c += 32; x >>= 32; }\n    if ((x\
    \ & 0x000000000000FFFFULL) == 0) { c += 16; x >>= 16; }\n    if ((x & 0x00000000000000FFULL)\
    \ == 0) { c += 8; x >>= 8; }\n    if ((x & 0x000000000000000FULL) == 0) { c +=\
    \ 4; x >>= 4; }\n    if ((x & 0x0000000000000003ULL) == 0) { c += 2; x >>= 2;\
    \ }\n    if ((x & 0x0000000000000001ULL) == 0) { c += 1; }\n    return c;\n  }\n\
    #endif\n\n// __builtin_parity - parity of number of set bits\n#if !__has_builtin(__builtin_parity)\n\
    \  inline int __builtin_parity(unsigned int x) {\n    return __builtin_popcount(x)\
    \ & 1;\n  }\n#endif\n\n#if !__has_builtin(__builtin_parityll)\n  inline int __builtin_parityll(unsigned\
    \ long long x) {\n    return __builtin_popcountll(x) & 1;\n  }\n#endif\n\nusing\
    \ namespace std;\n#line 1 \"graphs/trees/binary_lifting.h\"\nstruct binary_lifting\
    \ {\n    int log;\n    vector<int> dep;\n    vector<vector<int>> up;\n\n    binary_lifting(const\
    \ vector<vector<int>> &g, int root = 0) {\n        log = __lg(sz(g)) + 1;\n  \
    \      dep.resize(sz(g), -1);\n        up = vector(sz(g), vector<int>(log, -1));\n\
    \n        queue<int> q;\n        dep[root] = 0;\n        q.push(root);\n     \
    \   while (sz(q)) {\n            int u = q.front();\n            q.pop();\n  \
    \          for (int v : g[u]) {\n                if (dep[v] == -1) {\n       \
    \             dep[v] = dep[u] + 1;\n                    up[v][0] = u;\n      \
    \              for (int i = 1; i < log; i++) {\n                        if (up[v][i\
    \ - 1] == -1) {\n                            break;\n                        }\n\
    \                        up[v][i] = up[up[v][i - 1]][i - 1];\n               \
    \     }\n                    q.push(v);\n                }\n            }\n  \
    \      }\n    }\n    \n    int anc(int x, int k) {\n        for (int i = 0; i\
    \ < log; i++) {\n            if (x != -1 && ((k >> i) & 1)) {\n              \
    \  x = up[x][i];\n            }\n        }\n        return x;\n    }\n\n    int\
    \ lca(int x, int y) {\n        if (dep[x] < dep[y]) {\n            swap(x, y);\n\
    \        }\n        x = anc(x, dep[x] - dep[y]);\n        if (x == y) {\n    \
    \        return x;\n        }\n        for (int i = log - 1; i >= 0; i--) {\n\
    \            if (up[x][i] != up[y][i]) {\n                x = up[x][i];\n    \
    \            y = up[y][i];\n            }\n        }\n        return up[x][0];\n\
    \    }\n\n    int dist(int x, int y) {\n        return dep[x] + dep[y] - 2 * dep[lca(x,\
    \ y)];\n    }\n};\n#line 5 \"verify/library_checker/tree/binlift_lca.test.cpp\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<vector<int>> g(n);\n\
    \    for (int i = 1; i < n; i++) {\n        int p;\n        cin >> p;\n      \
    \  g[p].push_back(i);\n    }\n    binary_lifting bl(g);\n    while (q--) {\n \
    \       int u, v;\n        cin >> u >> v;\n        cout << bl.lca(u, v) << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../../template/template.h\"\
    \n#include \"../../../graphs/trees/binary_lifting.h\"\n\nint main() {\n    int\
    \ n, q;\n    cin >> n >> q;\n    vector<vector<int>> g(n);\n    for (int i = 1;\
    \ i < n; i++) {\n        int p;\n        cin >> p;\n        g[p].push_back(i);\n\
    \    }\n    binary_lifting bl(g);\n    while (q--) {\n        int u, v;\n    \
    \    cin >> u >> v;\n        cout << bl.lca(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - template/template.h
  - graphs/trees/binary_lifting.h
  isVerificationFile: true
  path: verify/library_checker/tree/binlift_lca.test.cpp
  requiredBy: []
  timestamp: '2025-09-06 19:45:01-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/library_checker/tree/binlift_lca.test.cpp
layout: document
redirect_from:
- /verify/verify/library_checker/tree/binlift_lca.test.cpp
- /verify/verify/library_checker/tree/binlift_lca.test.cpp.html
title: verify/library_checker/tree/binlift_lca.test.cpp
---
