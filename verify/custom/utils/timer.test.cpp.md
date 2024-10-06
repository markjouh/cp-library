---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':question:'
    path: utils/debug.h
    title: utils/debug.h
  - icon: ':question:'
    path: utils/encode.h
    title: utils/encode.h
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
  bundledCode: "#line 1 \"verify/custom/utils/timer.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing ld = long double;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 4 \"\
    verify/custom/utils/timer.test.cpp\"\n\n// Just for completionism's sake...\n\n\
    const int T = 50;\n\nint main() {\n    for (int i = 0; i < T; i++) {\n       \
    \ const long long rand_ns = rand_int(1e6, 1e7);\n\n        timer::start();\n \
    \       this_thread::sleep_for(chrono::nanoseconds(rand_ns));\n        long long\
    \ elapsed = timer::get_ns();\n\n        assert(abs(elapsed - rand_ns) < 1e7);\n\
    \    }\n\n    cerr << \"Tests passed\\n\";\n\n    int a, b;\n    cin >> a >> b;\n\
    \    cout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n\n// Just for completionism's sake...\n\nconst int\
    \ T = 50;\n\nint main() {\n    for (int i = 0; i < T; i++) {\n        const long\
    \ long rand_ns = rand_int(1e6, 1e7);\n\n        timer::start();\n        this_thread::sleep_for(chrono::nanoseconds(rand_ns));\n\
    \        long long elapsed = timer::get_ns();\n\n        assert(abs(elapsed -\
    \ rand_ns) < 1e7);\n    }\n\n    cerr << \"Tests passed\\n\";\n\n    int a, b;\n\
    \    cin >> a >> b;\n    cout << a + b << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  isVerificationFile: true
  path: verify/custom/utils/timer.test.cpp
  requiredBy: []
  timestamp: '2024-10-05 23:54:04-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/timer.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/timer.test.cpp
- /verify/verify/custom/utils/timer.test.cpp.html
title: verify/custom/utils/timer.test.cpp
---
