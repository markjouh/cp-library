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
  bundledCode: "#line 2 \"misc/next_greater_element.hpp\"\n\ntemplate <class T>\n\
    pair<vector<int>, vector<int>> findNGE(vector<T> a, bool greater = false) {\n\
    \  const int n = sz(a);\n  vector<int> prev(n, -1), nxt(n, n);\n\n  if (greater)\
    \ {\n    for (int i = 0; i < n; i++) {\n      a[i] = -a[i];\n    }\n  }\n\n  stack<int>\
    \ s;\n  for (int i = 0; i < n; i++) {\n    while (sz(s) && a[s.top()] > a[i])\
    \ {\n      s.pop();\n    }\n    if (sz(s)) {\n      prev[i] = s.top();\n    }\n\
    \    s.push(i);\n  }\n  while (sz(s)) {\n    s.pop();\n  }\n  for (int i = n -\
    \ 1; i >= 0; i--) {\n    while (sz(s) && a[s.top()] >= a[i]) {\n      s.pop();\n\
    \    }\n    if (sz(s)) {\n      nxt[i] = s.top();\n    }\n    s.push(i);\n  }\n\
    \n  return make_pair(prev, nxt);\n}\n"
  code: "#pragma once\n\ntemplate <class T>\npair<vector<int>, vector<int>> findNGE(vector<T>\
    \ a, bool greater = false) {\n  const int n = sz(a);\n  vector<int> prev(n, -1),\
    \ nxt(n, n);\n\n  if (greater) {\n    for (int i = 0; i < n; i++) {\n      a[i]\
    \ = -a[i];\n    }\n  }\n\n  stack<int> s;\n  for (int i = 0; i < n; i++) {\n \
    \   while (sz(s) && a[s.top()] > a[i]) {\n      s.pop();\n    }\n    if (sz(s))\
    \ {\n      prev[i] = s.top();\n    }\n    s.push(i);\n  }\n  while (sz(s)) {\n\
    \    s.pop();\n  }\n  for (int i = n - 1; i >= 0; i--) {\n    while (sz(s) &&\
    \ a[s.top()] >= a[i]) {\n      s.pop();\n    }\n    if (sz(s)) {\n      nxt[i]\
    \ = s.top();\n    }\n    s.push(i);\n  }\n\n  return make_pair(prev, nxt);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/next_greater_element.hpp
  requiredBy: []
  timestamp: '2024-09-11 14:41:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/next_greater_element.hpp
layout: document
redirect_from:
- /library/misc/next_greater_element.hpp
- /library/misc/next_greater_element.hpp.html
title: misc/next_greater_element.hpp
---
