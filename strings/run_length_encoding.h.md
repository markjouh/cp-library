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
  bundledCode: "#line 1 \"strings/run_length_encoding.h\"\ntemplate <class T>\nauto\
    \ rle(const T &a) {\n  vector<pair<typename T::value_type, int>> res;\n  res.emplace_back(a[0],\
    \ 0);\n  for (auto x : a) {\n    if (x != res.back().first) {\n      res.emplace_back(x,\
    \ 0);\n    }\n    res.back().second++;\n  }\n  return res;\n}\n"
  code: "template <class T>\nauto rle(const T &a) {\n  vector<pair<typename T::value_type,\
    \ int>> res;\n  res.emplace_back(a[0], 0);\n  for (auto x : a) {\n    if (x !=\
    \ res.back().first) {\n      res.emplace_back(x, 0);\n    }\n    res.back().second++;\n\
    \  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: strings/run_length_encoding.h
  requiredBy: []
  timestamp: '2025-03-18 16:29:46-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: strings/run_length_encoding.h
layout: document
redirect_from:
- /library/strings/run_length_encoding.h
- /library/strings/run_length_encoding.h.html
title: strings/run_length_encoding.h
---
