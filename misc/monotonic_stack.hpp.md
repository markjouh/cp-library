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
  bundledCode: "#line 2 \"misc/monotonic_stack.hpp\"\n\ntemplate <class T>\npair<vector<int>,\
    \ vector<int>> monotonic_stack(vector<T> a, bool greater = false) {\n  const int\
    \ n = sz(a);\n  vector<int> prev(n, -1), nxt(n, n);\n\n  if (greater) {\n    for\
    \ (int i = 0; i < n; i++) {\n      a[i] = -a[i];\n    }\n  }\n\n  stack<int> s;\n\
    \  for (int i = 0; i < n; i++) {\n    while (sz(s) && a[s.top()] > a[i]) {\n \
    \     s.pop();\n    }\n    if (sz(s)) {\n      prev[i] = s.top();\n    }\n   \
    \ s.push(i);\n  }\n  while (sz(s)) {\n    s.pop();\n  }\n  for (int i = n - 1;\
    \ i >= 0; i--) {\n    while (sz(s) && a[s.top()] >= a[i]) {\n      s.pop();\n\
    \    }\n    if (sz(s)) {\n      nxt[i] = s.top();\n    }\n    s.push(i);\n  }\n\
    \n  return make_pair(prev, nxt);\n}\n"
  code: "#pragma once\n\ntemplate <class T>\npair<vector<int>, vector<int>> monotonic_stack(vector<T>\
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
  path: misc/monotonic_stack.hpp
  requiredBy: []
  timestamp: '2024-09-06 17:58:54-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/monotonic_stack.hpp
layout: document
redirect_from:
- /library/misc/monotonic_stack.hpp
- /library/misc/monotonic_stack.hpp.html
title: misc/monotonic_stack.hpp
---
