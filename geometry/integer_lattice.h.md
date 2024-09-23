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
  bundledCode: "#line 2 \"geometry/integer_lattice.h\"\n\n// Simple stuff for counting\
    \ lattice points when we have integer vertices.\n// Fully tested on CSES Polygon\
    \ Lattice Points.\n\ntemplate <class T>\nT lattice_seg(const Point<T> &s) {\n\
    \    auto a = s.p, b = s.p + s.d;\n    return gcd(b.x - a.x, b.y - a.y); // (inside,\
    \ on boundary)\n}\n\ntemplate <class T>\npair<ll, ll> lattice_poly(const vector<Point<T>>\
    \ &v) {\n    pair<ll, ll> res;\n    for (int i = 0; i < sz(v); i++) {\n      \
    \  auto nxt = v[i == sz(v) - 1 ? 0 : i + 1];\n        auto seg = Line<T>(v[i],\
    \ nxt);\n        res.first += v[i] ^ nxt;\n        res.second += lattice_seg(seg);\n\
    \    }\n    res.first = (abs(res.first) - res.second + 2) / 2;\n    return res;\n\
    }\n"
  code: "#pragma once\n\n// Simple stuff for counting lattice points when we have\
    \ integer vertices.\n// Fully tested on CSES Polygon Lattice Points.\n\ntemplate\
    \ <class T>\nT lattice_seg(const Point<T> &s) {\n    auto a = s.p, b = s.p + s.d;\n\
    \    return gcd(b.x - a.x, b.y - a.y); // (inside, on boundary)\n}\n\ntemplate\
    \ <class T>\npair<ll, ll> lattice_poly(const vector<Point<T>> &v) {\n    pair<ll,\
    \ ll> res;\n    for (int i = 0; i < sz(v); i++) {\n        auto nxt = v[i == sz(v)\
    \ - 1 ? 0 : i + 1];\n        auto seg = Line<T>(v[i], nxt);\n        res.first\
    \ += v[i] ^ nxt;\n        res.second += lattice_seg(seg);\n    }\n    res.first\
    \ = (abs(res.first) - res.second + 2) / 2;\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: geometry/integer_lattice.h
  requiredBy: []
  timestamp: '2024-09-22 22:20:12-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/integer_lattice.h
layout: document
redirect_from:
- /library/geometry/integer_lattice.h
- /library/geometry/integer_lattice.h.html
title: geometry/integer_lattice.h
---
