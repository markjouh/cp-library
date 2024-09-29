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
  bundledCode: "#line 1 \"verify/custom/utils/encode.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"misc/template.h\"\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\n#ifdef LOCAL\n#include <utils>\n\
    #else\n#define dbg(...)\n#endif\n\n#define all(x) begin(x), end(x)\n#define sz(x)\
    \ int(size(x))\n\nusing ll = long long;\nusing ld = long double;\n\ntemplate <class\
    \ T>\nbool ckmin(T &a, T b) {\n    return b < a ? a = b, 1 : 0;\n}\ntemplate <class\
    \ T>\nbool ckmax(T &a, T b) {\n    return b > a ? a = b, 1 : 0;\n}\n#line 2 \"\
    utils/encode.h\"\n\nconstexpr uint64_t pow94[10] = {1, 94, 8836, 830584, 78074896,\
    \ 7339040224, 689869781056, 64847759419264, 6095689385410816, 572994802228616704};\n\
    \n// Turn array into a base-94 encoded string\ntemplate <class T, int W>\nstring\
    \ encode(T x) {\n    if constexpr (is_integral_v<T>) {\n        string res(W,\
    \ 0);\n        for (int i = 0; i < W; i++) {\n            res[i] = char(33 + x\
    \ % 94);\n            x /= 94;\n        }\n        return res;\n    } else {\n\
    \        string res;\n        for (auto &y : x) {\n            res += encode<typename\
    \ T::value_type, W>(y);\n        }\n        return res;\n    }\n}\n\ntemplate\
    \ <class T, int W>\nT decode(string s) {\n    if constexpr (is_integral_v<T>)\
    \ {\n        T res = 0;\n        for (int i = 0; i < W; i++) {\n            res\
    \ += pow94[i] * uint64_t(s[i] - 33);\n        }\n        return res;\n    } else\
    \ {\n        constexpr int segs = tuple_size_v<T>;\n        const int len = ssize(s)\
    \ / segs;\n        T res;\n        for (int i = 0; i < segs; i++) {\n        \
    \    res[i] = decode<typename T::value_type, W>(s.substr(len * i, len));\n   \
    \     }\n        return res;\n    }\n}\n\n// Generate code to copy paste into\
    \ frontend\n#define make_encoded(type, x, w) cout << \"const \" << type << ' '\
    \ << #x << \" = decode<\" << type << \", \" << w << \">(R\\\"zzzzz(\" << encode<decltype(x),\
    \ w>(x) << \")zzzzz\\\")\" << endl\n#line 5 \"verify/custom/utils/encode.test.cpp\"\
    \n\nconst int T = 1000;\n\nint main() {\n\tfor (int i = 0; i < T; i++) {\n\t\t\
    auto arr = rand_arr<int, 2500>(1e9);\n\t\tauto enc = encode<decltype(arr), 5>(arr);\n\
    \t\tauto dec = decode<decltype(arr), 5>(enc);\n\t\tassert(arr == dec);\n\t}\n\n\
    \tfor (int i = 0; i < T; i++) {\n\t\tarray<array<int, 50>, 50> arr;\n\t\tfor (int\
    \ j = 0; j < 50; j++) {\n\t\t\tarr[j] = rand_arr<int, 50>(1e9);\n\t\t}\n\t\tauto\
    \ enc = encode<decltype(arr), 5>(arr);\n\t\tauto dec = decode<decltype(arr), 5>(enc);\n\
    \t\tassert(arr == dec);\n\t}\n\n\tcerr << \"Tests passed\\n\";\n\n\tint a, b;\n\
    \tcin >> a >> b;\n\tcout << a + b << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    ../../../misc/template.h\"\n#include \"../../../utils/encode.h\"\n\nconst int\
    \ T = 1000;\n\nint main() {\n\tfor (int i = 0; i < T; i++) {\n\t\tauto arr = rand_arr<int,\
    \ 2500>(1e9);\n\t\tauto enc = encode<decltype(arr), 5>(arr);\n\t\tauto dec = decode<decltype(arr),\
    \ 5>(enc);\n\t\tassert(arr == dec);\n\t}\n\n\tfor (int i = 0; i < T; i++) {\n\t\
    \tarray<array<int, 50>, 50> arr;\n\t\tfor (int j = 0; j < 50; j++) {\n\t\t\tarr[j]\
    \ = rand_arr<int, 50>(1e9);\n\t\t}\n\t\tauto enc = encode<decltype(arr), 5>(arr);\n\
    \t\tauto dec = decode<decltype(arr), 5>(enc);\n\t\tassert(arr == dec);\n\t}\n\n\
    \tcerr << \"Tests passed\\n\";\n\n\tint a, b;\n\tcin >> a >> b;\n\tcout << a +\
    \ b << '\\n';\n}"
  dependsOn:
  - misc/template.h
  - utils/debug.h
  - utils/encode.h
  - utils/my_random.h
  - utils/my_timer.h
  isVerificationFile: true
  path: verify/custom/utils/encode.test.cpp
  requiredBy: []
  timestamp: '2024-09-29 00:35:58-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/custom/utils/encode.test.cpp
layout: document
redirect_from:
- /verify/verify/custom/utils/encode.test.cpp
- /verify/verify/custom/utils/encode.test.cpp.html
title: verify/custom/utils/encode.test.cpp
---
