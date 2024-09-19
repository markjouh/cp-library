---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/custom/utils/encode.test.cpp
    title: verify/custom/utils/encode.test.cpp
  _isVerificationFailed: true
  _pathExtension: h
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/encode.h\"\n\nconstexpr uint64_t pow94[10] = {1, 94,\
    \ 8836, 830584, 78074896, 7339040224, 689869781056, 64847759419264, 6095689385410816,\
    \ 572994802228616704};\n\n// Turn array into a base-94 encoded string\ntemplate\
    \ <class T, int W>\nstring encode(T x) {\n    if constexpr (is_integral_v<T>)\
    \ {\n        string res(W, 0);\n        for (int i = 0; i < W; i++) {\n      \
    \      res[i] = char(33 + x % 94);\n            x /= 94;\n        }\n        return\
    \ res;\n    } else {\n        string res;\n        for (auto &y : x) {\n     \
    \       res += encode<typename T::value_type, W>(y);\n        }\n        return\
    \ res;\n    }\n}\n\ntemplate <class T, int W>\nT decode(string s) {\n    if constexpr\
    \ (is_integral_v<T>) {\n        T res = 0;\n        for (int i = 0; i < W; i++)\
    \ {\n            res += pow94[i] * uint64_t(s[i] - 33);\n        }\n        return\
    \ res;\n    } else {\n        constexpr int segs = tuple_size_v<T>;\n        const\
    \ int len = ssize(s) / segs;\n        T res;\n        for (int i = 0; i < segs;\
    \ i++) {\n            res[i] = decode<typename T::value_type, W>(s.substr(len\
    \ * i, len));\n        }\n        return res;\n    }\n}\n\n// Generate code to\
    \ copy paste into frontend\n#define make_encoded(type, x, w) cout << \"const \"\
    \ << type << ' ' << #x << \" = decode<\" << type << \", \" << w << \">(R\\\"zzzzz(\"\
    \ << encode<decltype(x), w>(x) << \")zzzzz\\\")\" << endl\n"
  code: "#pragma once\n\nconstexpr uint64_t pow94[10] = {1, 94, 8836, 830584, 78074896,\
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
    \ w>(x) << \")zzzzz\\\")\" << endl"
  dependsOn: []
  isVerificationFile: false
  path: utils/encode.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/custom/utils/encode.test.cpp
documentation_of: utils/encode.h
layout: document
redirect_from:
- /library/utils/encode.h
- /library/utils/encode.h.html
title: utils/encode.h
---
