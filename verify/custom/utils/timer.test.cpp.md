---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':heavy_check_mark:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':heavy_check_mark:'
    path: utils/encode.h
    title: utils/encode.h
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/custom/utils/timer.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#include <unistd.h>\n\n#line 1 \"\
    misc/template.h\"\n#include <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef\
    \ LOCAL\n#include <utils>\n#else\n#define dbg(...)\n#endif\n\n#define arg4(a,\
    \ b, c, d, ...) d\n \n#define rep3(i, l, r) for (int i = int(l); i < int(r); i++)\n\
    #define rep2(i, n) rep3(i, 0, n)\n#define rep(...) arg4(__VA_ARGS__, rep3, rep2)\
    \ (__VA_ARGS__)\n \n#define per3(i, l, r) for (int i = int(r) - 1; i >= int(l);\
    \ i--)\n#define per2(i, n) per3(i, 0, n)\n#define per(...) arg4(__VA_ARGS__, per3,\
    \ per2) (__VA_ARGS__)\n\n#define all(x) begin(x), end(x)\n#define sz(x) int(size(x))\n\
    #define pb push_back\n#define eb emplace_back\n#define f first\n#define s second\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\n\ntemplate <class T>\nbool ckmin(T &a, const T &b) {\n    return b <\
    \ a ? a = b, 1 : 0;\n}\n\ntemplate <class T>\nbool ckmax(T &a, const T &b) {\n\
    \    return b > a ? a = b, 1 : 0;\n}\n\nstruct InitIO {\n    InitIO() {\n    \
    \    cin.tie(0)->sync_with_stdio(0);\n        cin.exceptions(cin.failbit);\n \
    \       cout << setprecision(10) << fixed;\n    }\n} init_io;\n#line 6 \"verify/custom/utils/timer.test.cpp\"\
    \n\n// Just for completionism's sake...\n\nconst int T = 10;\n\nint main() {\n\
    \    for (int i = 0; i < T; i++) {\n        const int rand_ms = rand_int(50, 500);\n\
    \n        start_timer();\n        usleep(rand_ms * 1000);\n        assert(abs(elapsed()\
    \ - rand_ms) < 10);\n    }\n\n    cerr << \"Tests passed\\n\";\n\n    int a, b;\n\
    \    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <unistd.h>\n\
    \n#include \"../../../misc/template.h\"\n\n// Just for completionism's sake...\n\
    \nconst int T = 10;\n\nint main() {\n    for (int i = 0; i < T; i++) {\n     \
    \   const int rand_ms = rand_int(50, 500);\n\n        start_timer();\n       \
    \ usleep(rand_ms * 1000);\n        assert(abs(elapsed() - rand_ms) < 10);\n  \
    \  }\n\n    cerr << \"Tests passed\\n\";\n\n    int a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  isVerificationFile: true
  path: verify/custom/utils/timer.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:47:28-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/timer.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/timer.test.cpp
- /verify/verify/custom/utils/timer.test.cpp.html
title: verify/custom/utils/timer.test.cpp
---
