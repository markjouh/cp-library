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
  bundledCode: "#line 2 \"utils/my_timer.h\"\n\nchrono::time_point<chrono::high_resolution_clock>\
    \ timer;\n\nvoid start_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n\
    }\n\nlong long elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}\n"
  code: "#pragma once\n\nchrono::time_point<chrono::high_resolution_clock> timer;\n\
    \nvoid start_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n\
    }\n\nlong long elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}"
  dependsOn: []
  isVerificationFile: false
  path: utils/my_timer.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: utils/my_timer.h
layout: document
redirect_from:
- /library/utils/my_timer.h
- /library/utils/my_timer.h.html
title: utils/my_timer.h
---
