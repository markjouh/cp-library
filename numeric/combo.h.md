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
  bundledCode: "#line 2 \"numeric/combo.h\"\n\nvector<mi> fact, inv_fact;\n\nvoid\
    \ init_fact(int n) {\n    fact.resize(n + 1);\n    inv_fact.resize(n + 1);\n \
    \   fact[0] = fact[1] = inv_fact[0] = inv_fact[1] = 1;\n    for (int i = 2; i\
    \ <= n; i++) {\n        fact[i] = fact[i - 1] * i;\n    }\n    inv_fact[n] = 1\
    \ / fact[n];\n    for (int i = n - 1; i >= 2; i--) {\n        inv_fact[i] = inv_fact[i\
    \ + 1] * (i + 1);\n    }\n}\n\nmi nck(int n, int k) {\n    if (n < k || k < 0)\
    \ {\n        return 0;\n    }\n    return fact[n] * inv_fact[k] * inv_fact[n -\
    \ k];\n}\n\nmi partitions(int items, int bins) {\n    if (bins == 0) {\n     \
    \   return items == 0;\n    }\n    return nck(bins + items - 1, bins - 1);\n}\n"
  code: "#pragma once\n\nvector<mi> fact, inv_fact;\n\nvoid init_fact(int n) {\n \
    \   fact.resize(n + 1);\n    inv_fact.resize(n + 1);\n    fact[0] = fact[1] =\
    \ inv_fact[0] = inv_fact[1] = 1;\n    for (int i = 2; i <= n; i++) {\n       \
    \ fact[i] = fact[i - 1] * i;\n    }\n    inv_fact[n] = 1 / fact[n];\n    for (int\
    \ i = n - 1; i >= 2; i--) {\n        inv_fact[i] = inv_fact[i + 1] * (i + 1);\n\
    \    }\n}\n\nmi nck(int n, int k) {\n    if (n < k || k < 0) {\n        return\
    \ 0;\n    }\n    return fact[n] * inv_fact[k] * inv_fact[n - k];\n}\n\nmi partitions(int\
    \ items, int bins) {\n    if (bins == 0) {\n        return items == 0;\n    }\n\
    \    return nck(bins + items - 1, bins - 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: numeric/combo.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/combo.h
layout: document
redirect_from:
- /library/numeric/combo.h
- /library/numeric/combo.h.html
title: numeric/combo.h
---
