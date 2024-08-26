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
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/binary_search.hpp
layout: document
redirect_from:
- /library/numeric/binary_search.hpp
- /library/numeric/binary_search.hpp.html
title: numeric/binary_search.hpp
---
