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
  bundledCode: "#line 1 \"utils/compat.h\"\n\n\n\n#ifdef __clang__\n\ntemplate <class\
    \ T>\nunsigned int __lg(T x) {\n    unsigned int res = 0;\n    while (x > 0) {\n\
    \        x >>= 1;\n        res++;\n    }\n    return res;\n}\n\n#endif //__clang__\n\
    \n\n"
  code: "#ifndef COMPAT_H\n#define COMPAT_H\n\n#ifdef __clang__\n\ntemplate <class\
    \ T>\nunsigned int __lg(T x) {\n    unsigned int res = 0;\n    while (x > 0) {\n\
    \        x >>= 1;\n        res++;\n    }\n    return res;\n}\n\n#endif //__clang__\n\
    \n#endif // COMPAT_H"
  dependsOn: []
  isVerificationFile: false
  path: utils/compat.h
  requiredBy: []
  timestamp: '2024-11-16 20:34:38-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/compat.h
layout: document
redirect_from:
- /library/utils/compat.h
- /library/utils/compat.h.html
title: utils/compat.h
---
