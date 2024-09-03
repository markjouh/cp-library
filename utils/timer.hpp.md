---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/custom/utils/timer.test.cpp
    title: verify/custom/utils/timer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"utils/timer.hpp\"\n\nchrono::time_point<chrono::high_resolution_clock>\
    \ timer;\n\nvoid set_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n\
    }\n\nll elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}\n"
  code: "#pragma once\n\nchrono::time_point<chrono::high_resolution_clock> timer;\n\
    \nvoid set_timer() {\n  timer = std::chrono::high_resolution_clock::now();\n}\n\
    \nll elapsed() {\n  return (chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now()\
    \ - timer)).count();\n}"
  dependsOn: []
  isVerificationFile: false
  path: utils/timer.hpp
  requiredBy: []
  timestamp: '2024-09-02 21:09:01-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/custom/utils/timer.test.cpp
documentation_of: utils/timer.hpp
layout: document
redirect_from:
- /library/utils/timer.hpp
- /library/utils/timer.hpp.html
title: utils/timer.hpp
---
