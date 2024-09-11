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
  bundledCode: "#line 2 \"numeric/combo.hpp\"\n\nvector<mi> fact, factI;\n\nvoid genFact(int\
    \ n) {\n  fact.resize(n + 1);\n  factI.resize(n + 1);\n  fact[0] = fact[1] = factI[0]\
    \ = factI[1] = 1;\n  for (int i = 2; i <= n; i++) {\n    fact[i] = fact[i - 1]\
    \ * i;\n  }\n  factI[n] = 1 / fact[n];\n  for (int i = n - 1; i >= 2; i--) {\n\
    \    factI[i] = factI[i + 1] * (i + 1);\n  }\n}\n\nmi nck(int n, int k) {\n  if\
    \ (n < k || k < 0) {\n    return 0;\n  }\n  return fact[n] * factI[k] * factI[n\
    \ - k];\n}\n\nmi partitions(int items, int bins) {\n  if (bins == 0) {\n    return\
    \ items == 0;\n  }\n  return nck(bins + items - 1, bins - 1);\n}\n"
  code: "#pragma once\n\nvector<mi> fact, factI;\n\nvoid genFact(int n) {\n  fact.resize(n\
    \ + 1);\n  factI.resize(n + 1);\n  fact[0] = fact[1] = factI[0] = factI[1] = 1;\n\
    \  for (int i = 2; i <= n; i++) {\n    fact[i] = fact[i - 1] * i;\n  }\n  factI[n]\
    \ = 1 / fact[n];\n  for (int i = n - 1; i >= 2; i--) {\n    factI[i] = factI[i\
    \ + 1] * (i + 1);\n  }\n}\n\nmi nck(int n, int k) {\n  if (n < k || k < 0) {\n\
    \    return 0;\n  }\n  return fact[n] * factI[k] * factI[n - k];\n}\n\nmi partitions(int\
    \ items, int bins) {\n  if (bins == 0) {\n    return items == 0;\n  }\n  return\
    \ nck(bins + items - 1, bins - 1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: numeric/combo.hpp
  requiredBy: []
  timestamp: '2024-09-11 15:33:10-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/combo.hpp
layout: document
redirect_from:
- /library/numeric/combo.hpp
- /library/numeric/combo.hpp.html
title: numeric/combo.hpp
---
