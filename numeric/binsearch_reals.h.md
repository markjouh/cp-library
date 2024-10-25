---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/binsearch_reals.h\"\n\ntemplate <class T>\ndouble\
    \ bsmin_reals(double lo, double hi, T f) {\n    static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n    assert(lo <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo),\
    \ r = reinterpret_cast<uint64_t&>(hi) + 1;\n    for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n        uint64_t nxt = r - i;\n        r -= (nxt >=\
    \ l && f(reinterpret_cast<double&>(nxt))) * i;\n    }\n    return reinterpret_cast<double&>(r);\n\
    }\n\ntemplate <class T>\ndouble bsmax_reals(double lo, double hi, T f) {\n   \
    \ static_assert(sizeof(uint64_t) >= sizeof(double));\n    assert(lo <= hi);\n\
    \    uint64_t l = reinterpret_cast<uint64_t&>(lo) - 1, r = reinterpret_cast<uint64_t&>(hi);\n\
    \    for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n        uint64_t\
    \ nxt = l + i;\n        l += (nxt <= r && f(reinterpret_cast<double&>(nxt))) *\
    \ i;\n    }\n    return reinterpret_cast<double&>(l);\n}\n"
  code: "#pragma once\n\ntemplate <class T>\ndouble bsmin_reals(double lo, double\
    \ hi, T f) {\n    static_assert(sizeof(uint64_t) >= sizeof(double));\n    assert(lo\
    \ <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo), r = reinterpret_cast<uint64_t&>(hi)\
    \ + 1;\n    for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n       \
    \ uint64_t nxt = r - i;\n        r -= (nxt >= l && f(reinterpret_cast<double&>(nxt)))\
    \ * i;\n    }\n    return reinterpret_cast<double&>(r);\n}\n\ntemplate <class\
    \ T>\ndouble bsmax_reals(double lo, double hi, T f) {\n    static_assert(sizeof(uint64_t)\
    \ >= sizeof(double));\n    assert(lo <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n    for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n        uint64_t nxt = l + i;\n        l += (nxt <=\
    \ r && f(reinterpret_cast<double&>(nxt))) * i;\n    }\n    return reinterpret_cast<double&>(l);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binsearch_reals.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/binsearch_reals.h
layout: document
redirect_from:
- /library/numeric/binsearch_reals.h
- /library/numeric/binsearch_reals.h.html
title: numeric/binsearch_reals.h
---
