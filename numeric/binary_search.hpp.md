---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/binary_search.test.cpp
    title: verify/aizu/alds1/binary_search.test.cpp
  - icon: ':x:'
    path: verify/library_checker/string/enumerate_palindromes.test.cpp
    title: verify/library_checker/string/enumerate_palindromes.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"numeric/binary_search.hpp\"\n\ntemplate<class T, class U>\
    \ T bsmin(T lo, T hi, U f) {\n    assert(lo <= hi);\n    hi++;\n    for (T i =\
    \ T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        hi -= (hi - i >= lo && f(hi\
    \ - i)) * i;\n    }\n    return hi;\n}\n\ntemplate<class T, class U> T bsmax(T\
    \ lo, T hi, U f) {\n    assert(lo <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi\
    \ - lo); i > 0; i >>= 1) {\n        lo += (lo + i <= hi && f(lo + i)) * i;\n \
    \   }\n    return lo;\n}\n"
  code: "#pragma once\n\ntemplate<class T, class U> T bsmin(T lo, T hi, U f) {\n \
    \   assert(lo <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0;\
    \ i >>= 1) {\n        hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return\
    \ hi;\n}\n\ntemplate<class T, class U> T bsmax(T lo, T hi, U f) {\n    assert(lo\
    \ <= hi);\n    lo--;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n\
    \        lo += (lo + i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binary_search.hpp
  requiredBy: []
  timestamp: '2024-08-26 19:37:00-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/aizu/alds1/binary_search.test.cpp
  - verify/library_checker/string/enumerate_palindromes.test.cpp
documentation_of: numeric/binary_search.hpp
layout: document
redirect_from:
- /library/numeric/binary_search.hpp
- /library/numeric/binary_search.hpp.html
title: numeric/binary_search.hpp
---
