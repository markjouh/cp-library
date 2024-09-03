---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/encode.hpp\"\n\nconstexpr ll pow_94[10] = {1, 94,\
    \ 8836, 830584, 78074896, 7339040224, 689869781056, 64847759419264, 6095689385410816,\
    \ 572994802228616704};\n\ntemplate <class T, int W>\nstring encode(T x) {\n  if\
    \ constexpr (is_integral_v<T>) {\n    string res(W, 0);\n    for (int i = 0; i\
    \ < W; i++) {\n      res[i] = char(33 + x % 94);\n      x /= 94;\n    }\n    return\
    \ res;\n  } else {\n    string res;\n    for (auto &y : x) {\n      res += encode<typename\
    \ T::value_type, W>(y);\n    }\n    return res;\n  }\n}\n\ntemplate <class T,\
    \ int W>\nT decode(string s) {\n  if constexpr (is_integral_v<T>) {\n    T res\
    \ = 0;\n    for (int i = 0; i < W; i++) {\n      res += pow_94[i] * ll(s[i] -\
    \ 33);\n    }\n    return res;\n  } else {\n    constexpr int segs = tuple_size_v<T>;\n\
    \    const int len = sz(s) / segs;\n    T res;\n    for (int i = 0; i < segs;\
    \ i++) {\n      res[i] = decode<typename T::value_type, W>(s.substr(len * i, len));\n\
    \    }\n    return res;\n  }\n}\n\n#define make_encoded(type, x, w) cout << \"\
    const \" << type << ' ' << #x << \" = decode<\" << type << \", \" << w << \">(R\\\
    \"zzzzz(\" << encode<decltype(x), w>(x) << \")zzzzz\\\")\" << endl\n"
  code: "#pragma once\n\nconstexpr ll pow_94[10] = {1, 94, 8836, 830584, 78074896,\
    \ 7339040224, 689869781056, 64847759419264, 6095689385410816, 572994802228616704};\n\
    \ntemplate <class T, int W>\nstring encode(T x) {\n  if constexpr (is_integral_v<T>)\
    \ {\n    string res(W, 0);\n    for (int i = 0; i < W; i++) {\n      res[i] =\
    \ char(33 + x % 94);\n      x /= 94;\n    }\n    return res;\n  } else {\n   \
    \ string res;\n    for (auto &y : x) {\n      res += encode<typename T::value_type,\
    \ W>(y);\n    }\n    return res;\n  }\n}\n\ntemplate <class T, int W>\nT decode(string\
    \ s) {\n  if constexpr (is_integral_v<T>) {\n    T res = 0;\n    for (int i =\
    \ 0; i < W; i++) {\n      res += pow_94[i] * ll(s[i] - 33);\n    }\n    return\
    \ res;\n  } else {\n    constexpr int segs = tuple_size_v<T>;\n    const int len\
    \ = sz(s) / segs;\n    T res;\n    for (int i = 0; i < segs; i++) {\n      res[i]\
    \ = decode<typename T::value_type, W>(s.substr(len * i, len));\n    }\n    return\
    \ res;\n  }\n}\n\n#define make_encoded(type, x, w) cout << \"const \" << type\
    \ << ' ' << #x << \" = decode<\" << type << \", \" << w << \">(R\\\"zzzzz(\" <<\
    \ encode<decltype(x), w>(x) << \")zzzzz\\\")\" << endl"
  dependsOn: []
  isVerificationFile: false
  path: utils/encode.hpp
  requiredBy: []
  timestamp: '2024-09-02 21:02:51-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/encode.hpp
layout: document
redirect_from:
- /library/utils/encode.hpp
- /library/utils/encode.hpp.html
title: utils/encode.hpp
---
