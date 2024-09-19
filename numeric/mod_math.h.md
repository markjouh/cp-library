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
  bundledCode: "#line 2 \"numeric/mod_math.h\"\n\nll madd(ll a, ll b, ll mod) {\n\
    \    return (a + b) % mod;\n}\n\nll msub(ll a, ll b, ll mod) {\n    return ((a\
    \ - b) % mod + mod) % mod;\n}\n\nll mmul(ll a, ll b, ll mod) {\n    return (a\
    \ % mod) * (b % mod) % mod;\n}\n\nll binpow(ll base, ll exp, ll mod) {\n  ll res\
    \ = 1;\n  while (exp) {\n      if (exp & 1) {\n          res = res * base % mod;\n\
    \      }\n      base = base * base % mod;\n      exp >>= 1;\n  }\n  return res;\n\
    }\n\n// Compute gcd and coefficients x, y such that ax + by = gcd(a, b)\nll extended_gcd(ll\
    \ a, ll b, ll &x, ll &y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n\
    \        return a;\n    }\n    ll x1, y1;\n    ll g = extended_gcd(b, a % b, x1,\
    \ y1);\n    x = y1;\n    y = x1 - (a / b) * y1;\n    return g;\n}\n\n// Compute\
    \ mod inverse for any a coprime to mod\nll mod_inverse(ll a, ll mod) {\n    ll\
    \ x, y;\n    ll g = extended_gcd(a, mod, x, y);\n    if (g != 1) {\n        return\
    \ -1;\n    } else {\n        return (x % mod + mod) % mod;\n    }\n}\n"
  code: "#pragma once\n\nll madd(ll a, ll b, ll mod) {\n    return (a + b) % mod;\n\
    }\n\nll msub(ll a, ll b, ll mod) {\n    return ((a - b) % mod + mod) % mod;\n\
    }\n\nll mmul(ll a, ll b, ll mod) {\n    return (a % mod) * (b % mod) % mod;\n\
    }\n\nll binpow(ll base, ll exp, ll mod) {\n  ll res = 1;\n  while (exp) {\n  \
    \    if (exp & 1) {\n          res = res * base % mod;\n      }\n      base =\
    \ base * base % mod;\n      exp >>= 1;\n  }\n  return res;\n}\n\n// Compute gcd\
    \ and coefficients x, y such that ax + by = gcd(a, b)\nll extended_gcd(ll a, ll\
    \ b, ll &x, ll &y) {\n    if (b == 0) {\n        x = 1;\n        y = 0;\n    \
    \    return a;\n    }\n    ll x1, y1;\n    ll g = extended_gcd(b, a % b, x1, y1);\n\
    \    x = y1;\n    y = x1 - (a / b) * y1;\n    return g;\n}\n\n// Compute mod inverse\
    \ for any a coprime to mod\nll mod_inverse(ll a, ll mod) {\n    ll x, y;\n   \
    \ ll g = extended_gcd(a, mod, x, y);\n    if (g != 1) {\n        return -1;\n\
    \    } else {\n        return (x % mod + mod) % mod;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: numeric/mod_math.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/mod_math.h
layout: document
redirect_from:
- /library/numeric/mod_math.h
- /library/numeric/mod_math.h.html
title: numeric/mod_math.h
---
