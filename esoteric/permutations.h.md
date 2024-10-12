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
  bundledCode: "#line 2 \"esoteric/permutations.h\"\n\nconst ll fact[20] = {1, 1,\
    \ 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800,\
    \ 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000,\
    \ 121645100408832000};\n\nll perm_to_idx(const vector<int> &p) {\n    const int\
    \ n = sz(p);\n    ll ans = 0;\n    for (int i = n - 2; i >= 0; i--) {\n      \
    \  for (int j = i + 1; j < n; j++) {\n            if (p[j] < p[i]) {\n       \
    \         ans += fact[n - i - 1];\n            }\n        }\n    }\n    return\
    \ ans;\n}\n\nauto idx_to_perm(int n, ll idx) {\n    vector<int> vals(n);\n   \
    \ iota(all(vals), 1);\n\n    vector<int> res(n);\n    for (int i = 0; i < n; i++)\
    \ {\n        int rank = idx / fact[n - i - 1];\n        idx %= fact[n - i - 1];\n\
    \        res[i] = vals[rank];\n        vals.erase(begin(vals) + rank);\n    }\n\
    \    return res;\n}\n"
  code: "#pragma once\n\nconst ll fact[20] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320,\
    \ 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000,\
    \ 20922789888000, 355687428096000, 6402373705728000, 121645100408832000};\n\n\
    ll perm_to_idx(const vector<int> &p) {\n    const int n = sz(p);\n    ll ans =\
    \ 0;\n    for (int i = n - 2; i >= 0; i--) {\n        for (int j = i + 1; j <\
    \ n; j++) {\n            if (p[j] < p[i]) {\n                ans += fact[n - i\
    \ - 1];\n            }\n        }\n    }\n    return ans;\n}\n\nauto idx_to_perm(int\
    \ n, ll idx) {\n    vector<int> vals(n);\n    iota(all(vals), 1);\n\n    vector<int>\
    \ res(n);\n    for (int i = 0; i < n; i++) {\n        int rank = idx / fact[n\
    \ - i - 1];\n        idx %= fact[n - i - 1];\n        res[i] = vals[rank];\n \
    \       vals.erase(begin(vals) + rank);\n    }\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: esoteric/permutations.h
  requiredBy: []
  timestamp: '2024-10-12 02:07:15-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: esoteric/permutations.h
layout: document
redirect_from:
- /library/esoteric/permutations.h
- /library/esoteric/permutations.h.html
title: esoteric/permutations.h
---
