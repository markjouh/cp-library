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
  bundledCode: "#line 2 \"numeric/binary_search_reals.hpp\"\n\ntemplate<class T> db\
    \ bsmin_reals(db lo, db hi, T f) {\n    assert(sizeof(uint64_t) >= sizeof(db));\n\
    \    assert(lo <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo), r =\
    \ reinterpret_cast<uint64_t&>(hi) + 1;\n    for (uint64_t i = 1ull << __lg(r -\
    \ l); i > 0; i >>= 1) {\n        uint64_t nxt = r - i;\n        r -= (nxt >= l\
    \ && f(reinterpret_cast<db&>(nxt))) * i;\n    }\n    return reinterpret_cast<db&>(r);\n\
    }\n\ntemplate<class T> db bsmax_reals(db lo, db hi, T f) {\n    assert(sizeof(uint64_t)\
    \ >= sizeof(db));\n    assert(lo <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n    for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n        uint64_t nxt = l + i;\n        l += (nxt <=\
    \ r && f(reinterpret_cast<db&>(nxt))) * i;\n    }\n    return reinterpret_cast<db&>(l);\n\
    }\n"
  code: "#pragma once\n\ntemplate<class T> db bsmin_reals(db lo, db hi, T f) {\n \
    \   assert(sizeof(uint64_t) >= sizeof(db));\n    assert(lo <= hi);\n    uint64_t\
    \ l = reinterpret_cast<uint64_t&>(lo), r = reinterpret_cast<uint64_t&>(hi) + 1;\n\
    \    for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n        uint64_t\
    \ nxt = r - i;\n        r -= (nxt >= l && f(reinterpret_cast<db&>(nxt))) * i;\n\
    \    }\n    return reinterpret_cast<db&>(r);\n}\n\ntemplate<class T> db bsmax_reals(db\
    \ lo, db hi, T f) {\n    assert(sizeof(uint64_t) >= sizeof(db));\n    assert(lo\
    \ <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo) - 1, r = reinterpret_cast<uint64_t&>(hi);\n\
    \    for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {\n        uint64_t\
    \ nxt = l + i;\n        l += (nxt <= r && f(reinterpret_cast<db&>(nxt))) * i;\n\
    \    }\n    return reinterpret_cast<db&>(l);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binary_search_reals.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/binary_search_reals.hpp
layout: document
redirect_from:
- /library/numeric/binary_search_reals.hpp
- /library/numeric/binary_search_reals.hpp.html
title: numeric/binary_search_reals.hpp
---
