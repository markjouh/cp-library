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
  bundledCode: "#line 1 \"datastructures/sqrt_range_sum.h\"\n// Supports point updates\
    \ in O(1) and range queries in O(sqrt N).\n\ntemplate <class T, int K>\nstruct\
    \ SqrtRangeSum {\n  vector<int> arr, blocks;\n\n  SqrtRangeSum(int n) {\n    const\
    \ int m = (n + K - 1) / K;\n    arr.resize(m * K);\n    blocks.resize(m);\n  }\n\
    \n  SqrtRangeSum(const vector<T> &a) {\n    SqrtRangeSum(a.size());\n    for (int\
    \ i = 0; i < int(a.size()); i++) {\n      arr[i] = a[i];\n      blocks[i / K]\
    \ += a[i];\n    }\n  }\n\n  void add(int p, T x) {\n    arr[p] += x;\n    blocks[p\
    \ / K] += x;\n  }\n\n  void set(int p, T x) {\n    add(p, x - arr[p]);\n  }\n\n\
    \  T get(int p) {\n    return arr[p];\n  }\n\n  T sum(int l, int r) {\n    T res\
    \ = 0;\n    if (l / K == r / K) {\n      for (int i = l; i <= r; i++) {\n    \
    \    res += arr[i];\n      }\n    } else {\n      while (l % K) {\n        res\
    \ += arr[l++];\n      }\n      while ((r + 1) % K) {\n        res += arr[r--];\n\
    \      }\n      for (int i = l / K; i <= r / K; i++) {\n        res += blocks[i];\n\
    \      }\n    }\n    return res;\n  }\n};\n"
  code: "// Supports point updates in O(1) and range queries in O(sqrt N).\n\ntemplate\
    \ <class T, int K>\nstruct SqrtRangeSum {\n  vector<int> arr, blocks;\n\n  SqrtRangeSum(int\
    \ n) {\n    const int m = (n + K - 1) / K;\n    arr.resize(m * K);\n    blocks.resize(m);\n\
    \  }\n\n  SqrtRangeSum(const vector<T> &a) {\n    SqrtRangeSum(a.size());\n  \
    \  for (int i = 0; i < int(a.size()); i++) {\n      arr[i] = a[i];\n      blocks[i\
    \ / K] += a[i];\n    }\n  }\n\n  void add(int p, T x) {\n    arr[p] += x;\n  \
    \  blocks[p / K] += x;\n  }\n\n  void set(int p, T x) {\n    add(p, x - arr[p]);\n\
    \  }\n\n  T get(int p) {\n    return arr[p];\n  }\n\n  T sum(int l, int r) {\n\
    \    T res = 0;\n    if (l / K == r / K) {\n      for (int i = l; i <= r; i++)\
    \ {\n        res += arr[i];\n      }\n    } else {\n      while (l % K) {\n  \
    \      res += arr[l++];\n      }\n      while ((r + 1) % K) {\n        res +=\
    \ arr[r--];\n      }\n      for (int i = l / K; i <= r / K; i++) {\n        res\
    \ += blocks[i];\n      }\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/sqrt_range_sum.h
  requiredBy: []
  timestamp: '2025-02-24 14:31:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/sqrt_range_sum.h
layout: document
redirect_from:
- /library/datastructures/sqrt_range_sum.h
- /library/datastructures/sqrt_range_sum.h.html
title: datastructures/sqrt_range_sum.h
---
