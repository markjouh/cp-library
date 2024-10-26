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
  bundledCode: "#line 1 \"common/compress.h\"\ntemplate <class T>\nstruct Compress\
    \ {\n    vector<T> vals;\n    bool ready = true;\n \n    void init() {\n     \
    \   if (!ready) {\n            sort(all(vals));\n            vals.resize(unique(all(vals))\
    \ - begin(vals));\n            ready = true;\n        }\n    }\n    void add(T\
    \ x) {\n        vals.push_back(x);\n        ready = false;\n    }\n \n    int\
    \ size() {\n        init();\n        return vals.size();\n    }\n    int operator[](int\
    \ p) {\n        init();\n        return vals[p];\n    }\n    int get(T x) {\n\
    \        init();\n        return lower_bound(all(vals), x) - begin(vals);\n  \
    \  }\n};\n"
  code: "template <class T>\nstruct Compress {\n    vector<T> vals;\n    bool ready\
    \ = true;\n \n    void init() {\n        if (!ready) {\n            sort(all(vals));\n\
    \            vals.resize(unique(all(vals)) - begin(vals));\n            ready\
    \ = true;\n        }\n    }\n    void add(T x) {\n        vals.push_back(x);\n\
    \        ready = false;\n    }\n \n    int size() {\n        init();\n       \
    \ return vals.size();\n    }\n    int operator[](int p) {\n        init();\n \
    \       return vals[p];\n    }\n    int get(T x) {\n        init();\n        return\
    \ lower_bound(all(vals), x) - begin(vals);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: common/compress.h
  requiredBy: []
  timestamp: '2024-10-25 20:08:44-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: common/compress.h
layout: document
redirect_from:
- /library/common/compress.h
- /library/common/compress.h.html
title: common/compress.h
---
