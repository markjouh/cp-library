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
  bundledCode: "#line 2 \"utils/bits/builtins.hpp\"\n\n#if !__has_builtin(__lg)\n\
    template <class T>\nint __lg(T x) {\n  int res = 0;\n  while (x >>= 1) {\n   \
    \ res++;\n  }\n  return res;\n}\n#endif\n\n#if !__has_builtin(__builtin_popcount)\n\
    int __builtin_popcount(unsigned int x) {\n  int res = 0;\n  for (int i = 0; i\
    \ < 32; i++) {\n    res += (x >> i) & 1;\n  }\n  return res;\n}\n#endif\n\n#if\
    \ !__has_builtin(__builtin_popcountll)\nint __builtin_popcountll(unsigned long\
    \ long x) {\n  int res = 0;\n  for (int i = 0; i < 64; i++) {\n    res += (x >>\
    \ i) & 1;\n  }\n  return res;\n}\n}\n#endif\n"
  code: "#pragma once\n\n#if !__has_builtin(__lg)\ntemplate <class T>\nint __lg(T\
    \ x) {\n  int res = 0;\n  while (x >>= 1) {\n    res++;\n  }\n  return res;\n\
    }\n#endif\n\n#if !__has_builtin(__builtin_popcount)\nint __builtin_popcount(unsigned\
    \ int x) {\n  int res = 0;\n  for (int i = 0; i < 32; i++) {\n    res += (x >>\
    \ i) & 1;\n  }\n  return res;\n}\n#endif\n\n#if !__has_builtin(__builtin_popcountll)\n\
    int __builtin_popcountll(unsigned long long x) {\n  int res = 0;\n  for (int i\
    \ = 0; i < 64; i++) {\n    res += (x >> i) & 1;\n  }\n  return res;\n}\n}\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: utils/bits/builtins.hpp
  requiredBy: []
  timestamp: '2024-09-05 22:57:47-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/bits/builtins.hpp
layout: document
redirect_from:
- /library/utils/bits/builtins.hpp
- /library/utils/bits/builtins.hpp.html
title: utils/bits/builtins.hpp
---
