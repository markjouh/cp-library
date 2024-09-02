---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/2000/submission/279265358
  bundledCode: "#line 1 \"datastructures/segtree/range_set_range_query_contig.hpp\"\
    \n// https://codeforces.com/contest/2000/submission/279265358\n\nstruct Seg {\n\
    \  int len, pref, suff, mx;\n\n  Seg(int x) : len(1), pref(x), suff(x), mx(x)\
    \ {}\n};\n\nSeg op(Seg a, Seg b) {\n  Seg res = a;\n  res.len = a.len + b.len;\n\
    \  res.pref = a.pref + (a.pref == a.len ? b.pref : 0);\n  res.suff = b.suff +\
    \ (b.suff == b.len ? a.suff : 0);\n  res.mx = max({a.mx, b.mx, a.suff + b.pref});\n\
    \  return res;\n}\n\nSeg seg_id() {\n  return Seg(0);\n}\n\nstruct Upd {\n  short\
    \ v;\n\n  Upd(short x) {\n    v = x;\n  }\n};\n\nSeg mapping(Seg x, Upd y) {\n\
    \  if (y.v == 1) {\n    x.pref = x.suff = x.mx = x.len;\n  }\n  if (y.v == 0)\
    \ {\n    x.pref = x.suff = x.mx = 0;\n  }\n  return x;\n}\n\nUpd comp(Upd x, Upd\
    \ y) {\n  return y.v != -1 ? y : x;\n}\n\nUpd upd_id() {\n  return Upd(-1);\n\
    }\n"
  code: "// https://codeforces.com/contest/2000/submission/279265358\n\nstruct Seg\
    \ {\n  int len, pref, suff, mx;\n\n  Seg(int x) : len(1), pref(x), suff(x), mx(x)\
    \ {}\n};\n\nSeg op(Seg a, Seg b) {\n  Seg res = a;\n  res.len = a.len + b.len;\n\
    \  res.pref = a.pref + (a.pref == a.len ? b.pref : 0);\n  res.suff = b.suff +\
    \ (b.suff == b.len ? a.suff : 0);\n  res.mx = max({a.mx, b.mx, a.suff + b.pref});\n\
    \  return res;\n}\n\nSeg seg_id() {\n  return Seg(0);\n}\n\nstruct Upd {\n  short\
    \ v;\n\n  Upd(short x) {\n    v = x;\n  }\n};\n\nSeg mapping(Seg x, Upd y) {\n\
    \  if (y.v == 1) {\n    x.pref = x.suff = x.mx = x.len;\n  }\n  if (y.v == 0)\
    \ {\n    x.pref = x.suff = x.mx = 0;\n  }\n  return x;\n}\n\nUpd comp(Upd x, Upd\
    \ y) {\n  return y.v != -1 ? y : x;\n}\n\nUpd upd_id() {\n  return Upd(-1);\n}"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/segtree/range_set_range_query_contig.hpp
  requiredBy: []
  timestamp: '2024-09-01 20:39:09-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/segtree/range_set_range_query_contig.hpp
layout: document
redirect_from:
- /library/datastructures/segtree/range_set_range_query_contig.hpp
- /library/datastructures/segtree/range_set_range_query_contig.hpp.html
title: datastructures/segtree/range_set_range_query_contig.hpp
---
