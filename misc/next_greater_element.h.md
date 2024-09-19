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
  bundledCode: "#line 2 \"misc/next_greater_element.h\"\n\ntemplate <class T>\nauto\
    \ find_nge(vector<T> a, bool greater = false) {\n    const int n = sz(a);\n  \
    \  vector<int> prev(n, -1), nxt(n, n);\n\n    if (greater) {\n        for (int\
    \ i = 0; i < n; i++) {\n            a[i] = -a[i];\n        }\n    }\n\n    stack<int>\
    \ s;\n    for (int i = 0; i < n; i++) {\n        while (sz(s) && a[s.top()] >\
    \ a[i]) {\n            s.pop();\n        }\n        if (sz(s)) {\n           \
    \ prev[i] = s.top();\n        }\n        s.push(i);\n    }\n    while (sz(s))\
    \ {\n        s.pop();\n    }\n    for (int i = n - 1; i >= 0; i--) {\n       \
    \ while (sz(s) && a[s.top()] >= a[i]) {\n            s.pop();\n        }\n   \
    \     if (sz(s)) {\n            nxt[i] = s.top();\n        }\n        s.push(i);\n\
    \    }\n\n    return {prev, nxt};\n}\n"
  code: "#pragma once\n\ntemplate <class T>\nauto find_nge(vector<T> a, bool greater\
    \ = false) {\n    const int n = sz(a);\n    vector<int> prev(n, -1), nxt(n, n);\n\
    \n    if (greater) {\n        for (int i = 0; i < n; i++) {\n            a[i]\
    \ = -a[i];\n        }\n    }\n\n    stack<int> s;\n    for (int i = 0; i < n;\
    \ i++) {\n        while (sz(s) && a[s.top()] > a[i]) {\n            s.pop();\n\
    \        }\n        if (sz(s)) {\n            prev[i] = s.top();\n        }\n\
    \        s.push(i);\n    }\n    while (sz(s)) {\n        s.pop();\n    }\n   \
    \ for (int i = n - 1; i >= 0; i--) {\n        while (sz(s) && a[s.top()] >= a[i])\
    \ {\n            s.pop();\n        }\n        if (sz(s)) {\n            nxt[i]\
    \ = s.top();\n        }\n        s.push(i);\n    }\n\n    return {prev, nxt};\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: misc/next_greater_element.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/next_greater_element.h
layout: document
redirect_from:
- /library/misc/next_greater_element.h
- /library/misc/next_greater_element.h.html
title: misc/next_greater_element.h
---
