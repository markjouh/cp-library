---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: misc/template.h
    title: misc/template.h
  - icon: ':x:'
    path: utils/debug.h
    title: utils/debug.h
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "#line 1 \"verify/custom/utils/debug.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
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
    \    }\n} init_io;\n#line 2 \"utils/debug.h\"\n\nnamespace debug_internal {\n\n\
    using namespace std;\n\ntemplate <typename T>\nconcept is_core = requires(T x)\
    \ {\n    cerr << x;\n};\n\ntemplate <typename T>\nconcept is_pair = requires(T\
    \ x) {\n    x.first;\n    x.second;\n};\n\ntemplate <typename T>\nconcept is_iterable\
    \ = ranges::range<T>;\n\ntemplate <typename T>\nvoid print(T x) {\n    if constexpr\
    \ (is_core<T>) {\n        cerr << x;\n    } else if constexpr (is_pair<T>) {\n\
    \        cerr << '(';\n        print(x.first);\n        cerr << \", \";\n    \
    \    print(x.second);\n        cerr << ')';\n    } else if constexpr (is_iterable<T>)\
    \ {\n        cerr << '[';\n        bool flag = false;\n        for (auto y : x)\
    \ {\n            if (flag) {\n                cerr << \", \";\n            }\n\
    \            print(y);\n            flag = true;\n        }\n        cerr << ']';\n\
    \    } else {\n        cerr << \"Unknown type\";\n    }\n}\n\ntemplate <typename\
    \ T>\nvoid debug(string s, T x) {\n    cerr << \"\\033[1;35m\" << s << \"\\033[0;0m\
    \ = \";\n    print(x);\n    cerr << endl;\n}\n\ntemplate <typename T, typename...\
    \ Args>\nvoid debug(string s, T x, Args... args) {\n    int idx = 0, layer = 0;\n\
    \    while (idx < ssize(s) && (s[idx] != ',' || layer != 0)) {\n        layer\
    \ += s[idx] == '(' || s[idx] == '{';\n        layer -= s[idx] == ')' || s[idx]\
    \ == '}';\n        idx++;\n    }\n    cerr << \"\\033[1;35m\" << s.substr(0, idx)\
    \ << \"\\033[0;0m = \";\n    print(x);\n    cerr << \"\\033[1;32m | \\033[0;0m\"\
    ;\n    debug(s.substr(s.find_first_not_of(' ', idx + 1)), args...);\n}\n}\n\n\
    #define dbg(...) debug_internal::debug(#__VA_ARGS__, __VA_ARGS__)\n#line 5 \"\
    verify/custom/utils/debug.test.cpp\"\n\n// Just make sure the output looks right...\n\
    \nint main() {\n    const int n = rand_int(100);\n    vector<int> p = rand_vec<int>(n);\n\
    \    dbg(p);\n\n    map<int, vector<int>> mp;\n    for (int i = 0; i < 100; i++)\
    \ {\n        mp[rand_int()] = rand_vec<int>(100);\n    }\n    dbg(mp);\n\n   \
    \ array<double, 100> arr = rand_arr<double, 100>();\n    dbg(arr);\n\n    int\
    \ a, b;\n    cin >> a >> b;\n    cout << a + b << '\\n';\n}\n"
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
  isVerificationFile: true
  path: verify/custom/utils/debug.test.cpp
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/custom/utils/debug.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/debug.test.cpp
- /verify/verify/custom/utils/debug.test.cpp.html
title: verify/custom/utils/debug.test.cpp
---
