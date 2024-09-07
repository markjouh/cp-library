---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1983/submission/280230910
  bundledCode: "#line 2 \"datastructures/min_xor_set.hpp\"\n\n// https://codeforces.com/contest/1983/submission/280230910\n\
    \ntemplate <class T>\nstruct MinXorSet {\n  multiset<T> xors, vals;\n\n  MinXorSet()\
    \ {}\n\n  void insert(T x) {\n    vals.insert(x);\n    auto it = vals.find(x);\n\
    \    if (it != begin(vals) && it != prev(end(vals))) {\n      xors.extract(*next(it)\
    \ ^ *prev(it));\n    }\n    if (it != begin(vals)) {\n      xors.insert(x ^ *prev(it));\n\
    \    }\n    if (it != prev(end(vals))) {\n      xors.insert(x ^ *next(it));\n\
    \    }\n  }\n\n  void remove(T x) {\n    auto it = vals.find(x);\n    if (it !=\
    \ begin(vals) && it != prev(end(vals))) {\n      xors.insert(*next(it) ^ *prev(it));\n\
    \    }\n    if (it != begin(vals)) {\n      xors.extract(x ^ *prev(it));\n   \
    \ }\n    if (it != prev(end(vals))) {\n      xors.extract(x ^ *next(it));\n  \
    \  }\n    vals.extract(x);\n  }\n\n  T get() {\n    return xors.empty() ? numeric_limits<T>::max()\
    \ : *begin(xors);\n  }\n};\n"
  code: "#pragma once\n\n// https://codeforces.com/contest/1983/submission/280230910\n\
    \ntemplate <class T>\nstruct MinXorSet {\n  multiset<T> xors, vals;\n\n  MinXorSet()\
    \ {}\n\n  void insert(T x) {\n    vals.insert(x);\n    auto it = vals.find(x);\n\
    \    if (it != begin(vals) && it != prev(end(vals))) {\n      xors.extract(*next(it)\
    \ ^ *prev(it));\n    }\n    if (it != begin(vals)) {\n      xors.insert(x ^ *prev(it));\n\
    \    }\n    if (it != prev(end(vals))) {\n      xors.insert(x ^ *next(it));\n\
    \    }\n  }\n\n  void remove(T x) {\n    auto it = vals.find(x);\n    if (it !=\
    \ begin(vals) && it != prev(end(vals))) {\n      xors.insert(*next(it) ^ *prev(it));\n\
    \    }\n    if (it != begin(vals)) {\n      xors.extract(x ^ *prev(it));\n   \
    \ }\n    if (it != prev(end(vals))) {\n      xors.extract(x ^ *next(it));\n  \
    \  }\n    vals.extract(x);\n  }\n\n  T get() {\n    return xors.empty() ? numeric_limits<T>::max()\
    \ : *begin(xors);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/min_xor_set.hpp
  requiredBy: []
  timestamp: '2024-09-07 13:28:20-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/min_xor_set.hpp
layout: document
redirect_from:
- /library/datastructures/min_xor_set.hpp
- /library/datastructures/min_xor_set.hpp.html
title: datastructures/min_xor_set.hpp
---
