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
  bundledCode: "#line 1 \"verify/custom/utils/debug.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing ld = long double;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 2 \"\
    utils/debug.h\"\n\nnamespace debug_internal {\n\nusing namespace std;\n\ntemplate\
    \ <typename T>\nconcept is_core = requires(T x) {\n    cerr << x;\n};\n\ntemplate\
    \ <typename T>\nconcept is_pair = requires(T x) {\n    x.first;\n    x.second;\n\
    };\n\ntemplate <typename T>\nconcept is_iterable = ranges::range<T>;\n\ntemplate\
    \ <typename T>\nvoid print(T x) {\n    if constexpr (is_core<T>) {\n        cerr\
    \ << x;\n    } else if constexpr (is_pair<T>) {\n        cerr << '(';\n      \
    \  print(x.first);\n        cerr << \", \";\n        print(x.second);\n      \
    \  cerr << ')';\n    } else if constexpr (is_iterable<T>) {\n        cerr << '[';\n\
    \        bool flag = false;\n        for (auto y : x) {\n            if (flag)\
    \ {\n                cerr << \", \";\n            }\n            print(y);\n \
    \           flag = true;\n        }\n        cerr << ']';\n    } else {\n    \
    \    cerr << \"Unknown type\";\n    }\n}\n\ntemplate <typename T>\nvoid debug(string\
    \ s, T x) {\n    cerr << \"\\033[1;35m\" << s << \"\\033[0;0m = \";\n    print(x);\n\
    \    cerr << endl;\n}\n\ntemplate <typename T, typename... Args>\nvoid debug(string\
    \ s, T x, Args... args) {\n    int idx = 0, layer = 0;\n    while (idx < ssize(s)\
    \ && (s[idx] != ',' || layer != 0)) {\n        layer += s[idx] == '(' || s[idx]\
    \ == '{';\n        layer -= s[idx] == ')' || s[idx] == '}';\n        idx++;\n\
    \    }\n    cerr << \"\\033[1;35m\" << s.substr(0, idx) << \"\\033[0;0m = \";\n\
    \    print(x);\n    cerr << \"\\033[1;32m | \\033[0;0m\";\n    debug(s.substr(s.find_first_not_of('\
    \ ', idx + 1)), args...);\n}\n}\n\n#define dbg(...) debug_internal::debug(#__VA_ARGS__,\
    \ __VA_ARGS__)\n#line 5 \"verify/custom/utils/debug.test.cpp\"\n\n// Just make\
    \ sure the output looks right...\n\nint main() {\n    const int n = rand_int(100);\n\
    \    vector<int> p = rand_vec<int>(n);\n    dbg(p);\n\n    map<int, vector<int>>\
    \ mp;\n    for (int i = 0; i < 100; i++) {\n        mp[rand_int()] = rand_vec<int>(100);\n\
    \    }\n    dbg(mp);\n\n    array<double, 100> arr = rand_arr<double, 100>();\n\
    \    dbg(arr);\n\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\\
    n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../utils/debug.h\"\n\n// Just make\
    \ sure the output looks right...\n\nint main() {\n    const int n = rand_int(100);\n\
    \    vector<int> p = rand_vec<int>(n);\n    dbg(p);\n\n    map<int, vector<int>>\
    \ mp;\n    for (int i = 0; i < 100; i++) {\n        mp[rand_int()] = rand_vec<int>(100);\n\
    \    }\n    dbg(mp);\n\n    array<double, 100> arr = rand_arr<double, 100>();\n\
    \    dbg(arr);\n\n    int a, b;\n    cin >> a >> b;\n    cout << a + b << '\\\
    n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  isVerificationFile: true
  path: verify/custom/utils/debug.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/debug.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/debug.test.cpp
- /verify/verify/custom/utils/debug.test.cpp.html
title: verify/custom/utils/debug.test.cpp
---
