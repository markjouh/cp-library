---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: numeric/binsearch_reals.h
    title: numeric/binsearch_reals.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/my_random.h
    title: utils/my_random.h
  - icon: ':question:'
    path: utils/my_timer.h
    title: utils/my_timer.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/numeric/binary_search_reals.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\
    \n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing ld = long double;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 2 \"\
    numeric/binsearch_reals.h\"\n\ntemplate <class T>\ndouble bsmin_reals(double lo,\
    \ double hi, T f) {\n    static_assert(sizeof(uint64_t) >= sizeof(double));\n\
    \    assert(lo <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo), r =\
    \ reinterpret_cast<uint64_t&>(hi) + 1;\n    for (uint64_t i = 1ull << __lg(r -\
    \ l); i > 0; i >>= 1) {\n        uint64_t nxt = r - i;\n        r -= (nxt >= l\
    \ && f(reinterpret_cast<double&>(nxt))) * i;\n    }\n    return reinterpret_cast<double&>(r);\n\
    }\n\ntemplate <class T>\ndouble bsmax_reals(double lo, double hi, T f) {\n   \
    \ static_assert(sizeof(uint64_t) >= sizeof(double));\n    assert(lo <= hi);\n\
    \    uint64_t l = reinterpret_cast<uint64_t&>(lo) - 1, r = reinterpret_cast<uint64_t&>(hi);\n\
    \    for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n        uint64_t\
    \ nxt = l + i;\n        l += (nxt <= r && f(reinterpret_cast<double&>(nxt))) *\
    \ i;\n    }\n    return reinterpret_cast<double&>(l);\n}\n#line 5 \"verify/custom/numeric/binary_search_reals.test.cpp\"\
    \n\nconst int T = 1e6;\nconst double MXV = 1e12, ERR = 1e-3;\n\nvoid test() {\n\
    \    // Search for exact double value, should have no ERR\n    const double t1\
    \ = rand_db(1e100);\n    double left = bsmax_reals(0, 1e100, [&](double x) {\n\
    \        return x <= t1;\n    });\n    assert(left == t1);\n    double right =\
    \ bsmin_reals(0, 1e100, [&](double x) {\n        return x >= t1;\n    });\n  \
    \  assert(right == t1);\n\n    // Try computing sqrt\n    const double t2 = rand_db(MXV);\n\
    \    double sqrt_val = bsmax_reals(0, MXV, [&](double x) {\n        return x *\
    \ x <= t2;\n    });\n    double sqrt_prod = sqrt_val * sqrt_val;\n    assert(sqrt_prod\
    \ <= t2 && t2 - sqrt_prod < ERR);\n\n    // Try computing cbrt\n    const double\
    \ t3 = rand_db(MXV);\n    double cbrt_val = bsmax_reals(0, MXV, [&](double x)\
    \ {\n        return x * x * x <= t3;\n    });\n    double cbrt_prod = cbrt_val\
    \ * cbrt_val * cbrt_val;\n    assert(cbrt_prod <= t3 && t3 - cbrt_prod < ERR);\n\
    }\n\nint main() {\n    for (int i = 0; i < T; i++) {\n        test();\n    }\n\
    \    cerr << \"Tests passed\\n\";\n\n    int a, b;\n    cin >> a >> b;\n    cout\
    \ << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../numeric/binsearch_reals.h\"\n\n\
    const int T = 1e6;\nconst double MXV = 1e12, ERR = 1e-3;\n\nvoid test() {\n  \
    \  // Search for exact double value, should have no ERR\n    const double t1 =\
    \ rand_db(1e100);\n    double left = bsmax_reals(0, 1e100, [&](double x) {\n \
    \       return x <= t1;\n    });\n    assert(left == t1);\n    double right =\
    \ bsmin_reals(0, 1e100, [&](double x) {\n        return x >= t1;\n    });\n  \
    \  assert(right == t1);\n\n    // Try computing sqrt\n    const double t2 = rand_db(MXV);\n\
    \    double sqrt_val = bsmax_reals(0, MXV, [&](double x) {\n        return x *\
    \ x <= t2;\n    });\n    double sqrt_prod = sqrt_val * sqrt_val;\n    assert(sqrt_prod\
    \ <= t2 && t2 - sqrt_prod < ERR);\n\n    // Try computing cbrt\n    const double\
    \ t3 = rand_db(MXV);\n    double cbrt_val = bsmax_reals(0, MXV, [&](double x)\
    \ {\n        return x * x * x <= t3;\n    });\n    double cbrt_prod = cbrt_val\
    \ * cbrt_val * cbrt_val;\n    assert(cbrt_prod <= t3 && t3 - cbrt_prod < ERR);\n\
    }\n\nint main() {\n    for (int i = 0; i < T; i++) {\n        test();\n    }\n\
    \    cerr << \"Tests passed\\n\";\n\n    int a, b;\n    cin >> a >> b;\n    cout\
    \ << a + b << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/my_random.h
  - utils/my_timer.h
  - numeric/binsearch_reals.h
  isVerificationFile: true
  path: verify/custom/numeric/binary_search_reals.test.cpp
  requiredBy: []
  timestamp: '2024-10-12 02:07:15-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/numeric/binary_search_reals.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/numeric/binary_search_reals.test.cpp
- /verify/verify/custom/numeric/binary_search_reals.test.cpp.html
title: verify/custom/numeric/binary_search_reals.test.cpp
---
