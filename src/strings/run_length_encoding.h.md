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
  bundledCode: "#line 1 \"src/strings/run_length_encoding.h\"\ntemplate <class T>\n\
    auto rle(const T &a) {\n  vector<pair<typename T::value_type, int>> res;\n  res.emplace_back(a[0],\
    \ 0);\n  for (auto x : a) {\n    if (x != res.back().first) {\n      res.emplace_back(x,\
    \ 0);\n    }\n    res.back().second++;\n  }\n  return res;\n}\n"
  code: "template <class T>\nauto rle(const T &a) {\n  vector<pair<typename T::value_type,\
    \ int>> res;\n  res.emplace_back(a[0], 0);\n  for (auto x : a) {\n    if (x !=\
    \ res.back().first) {\n      res.emplace_back(x, 0);\n    }\n    res.back().second++;\n\
    \  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/strings/run_length_encoding.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/strings/run_length_encoding.h
layout: document
redirect_from:
- /library/src/strings/run_length_encoding.h
- /library/src/strings/run_length_encoding.h.html
title: src/strings/run_length_encoding.h
---
