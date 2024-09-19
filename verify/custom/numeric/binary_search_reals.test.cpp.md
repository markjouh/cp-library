---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':x:'
    path: numeric/binsearch_reals.h
    title: numeric/binsearch_reals.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/numeric/binary_search_reals.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\
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
    \    }\n} init_io;\n#line 2 \"numeric/binsearch_reals.h\"\n\ntemplate <class T>\n\
    double bsmin_reals(double lo, double hi, T f) {\n    static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n    assert(lo <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo),\
    \ r = reinterpret_cast<uint64_t&>(hi) + 1;\n    for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n        uint64_t nxt = r - i;\n        r -= (nxt >=\
    \ l && f(reinterpret_cast<double&>(nxt))) * i;\n    }\n    return reinterpret_cast<double&>(r);\n\
    }\n\ntemplate <class T>\ndouble bsmax_reals(double lo, double hi, T f) {\n   \
    \ static_assert(sizeof(uint64_t) >= sizeof(double));\n    assert(lo <= hi);\n\
    \    uint64_t l = reinterpret_cast<uint64_t&>(lo) - 1, r = reinterpret_cast<uint64_t&>(hi);\n\
    \    for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n        uint64_t\
    \ nxt = l + i;\n        l += (nxt <= r && f(reinterpret_cast<double&>(nxt))) *\
    \ i;\n    }\n    return reinterpret_cast<double&>(l);\n}\n#line 5 \"verify/custom/numeric/binary_search_reals.test.cpp\"\
    \n\nconst int T = 1e6;\nconst double MXV = 1e12, ERR = 1e-3;\n\nvoid test() {\n\
    \    // Search for exact double value, should have no ERR\n    const double t1\
    \ = rand_doub(1e100);\n    double left = bsmax_reals(0, 1e100, [&](double x) {\n\
    \        return x <= t1;\n    });\n    assert(left == t1);\n    double right =\
    \ bsmin_reals(0, 1e100, [&](double x) {\n        return x >= t1;\n    });\n  \
    \  assert(right == t1);\n\n    // Try computing sqrt\n    const double t2 = rand_doub(MXV);\n\
    \    double sqrt_val = bsmax_reals(0, MXV, [&](double x) {\n        return x *\
    \ x <= t2;\n    });\n    double sqrt_prod = sqrt_val * sqrt_val;\n    assert(sqrt_prod\
    \ <= t2 && t2 - sqrt_prod < ERR);\n\n    // Try computing cbrt\n    const double\
    \ t3 = rand_doub(MXV);\n    double cbrt_val = bsmax_reals(0, MXV, [&](double x)\
    \ {\n        return x * x * x <= t3;\n    });\n    double cbrt_prod = cbrt_val\
    \ * cbrt_val * cbrt_val;\n    assert(cbrt_prod <= t3 && t3 - cbrt_prod < ERR);\n\
    }\n\nint main() {\n    for (int i = 0; i < T; i++) {\n        test();\n    }\n\
    \    cerr << \"Tests passed\\n\";\n\n    int a, b;\n    cin >> a >> b;\n    cout\
    \ << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../numeric/binsearch_reals.h\"\n\n\
    const int T = 1e6;\nconst double MXV = 1e12, ERR = 1e-3;\n\nvoid test() {\n  \
    \  // Search for exact double value, should have no ERR\n    const double t1 =\
    \ rand_doub(1e100);\n    double left = bsmax_reals(0, 1e100, [&](double x) {\n\
    \        return x <= t1;\n    });\n    assert(left == t1);\n    double right =\
    \ bsmin_reals(0, 1e100, [&](double x) {\n        return x >= t1;\n    });\n  \
    \  assert(right == t1);\n\n    // Try computing sqrt\n    const double t2 = rand_doub(MXV);\n\
    \    double sqrt_val = bsmax_reals(0, MXV, [&](double x) {\n        return x *\
    \ x <= t2;\n    });\n    double sqrt_prod = sqrt_val * sqrt_val;\n    assert(sqrt_prod\
    \ <= t2 && t2 - sqrt_prod < ERR);\n\n    // Try computing cbrt\n    const double\
    \ t3 = rand_doub(MXV);\n    double cbrt_val = bsmax_reals(0, MXV, [&](double x)\
    \ {\n        return x * x * x <= t3;\n    });\n    double cbrt_prod = cbrt_val\
    \ * cbrt_val * cbrt_val;\n    assert(cbrt_prod <= t3 && t3 - cbrt_prod < ERR);\n\
    }\n\nint main() {\n    for (int i = 0; i < T; i++) {\n        test();\n    }\n\
    \    cerr << \"Tests passed\\n\";\n\n    int a, b;\n    cin >> a >> b;\n    cout\
    \ << a + b << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - numeric/binsearch_reals.h
  isVerificationFile: true
  path: verify/custom/numeric/binary_search_reals.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/custom/numeric/binary_search_reals.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/numeric/binary_search_reals.test.cpp
- /verify/verify/custom/numeric/binary_search_reals.test.cpp.html
title: verify/custom/numeric/binary_search_reals.test.cpp
---
