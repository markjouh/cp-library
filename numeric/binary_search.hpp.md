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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ numeric/binary_search.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/* Find the first true/last true value given a discrete monotonic boolean\
    \ function.\n * `bsmin(l, r, f)`, `bsmax(l, r, f)`: O(log(hi - lo) * T_f)\n */\n\
    \n#pragma once\n\ntemplate<class T, class U> T bsmin(T lo, T hi, U f) {\n    assert(lo\
    \ <= hi);\n    hi++;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n\
    \        hi -= (hi - i >= lo && f(hi - i)) * i;\n    }\n    return hi;\n}\n\n\
    template<class T, class U> T bsmax(T lo, T hi, U f) {\n    assert(lo <= hi);\n\
    \    lo--;\n    for (T i = T(1) << __lg(hi - lo); i > 0; i >>= 1) {\n        lo\
    \ += (lo + i <= hi && f(lo + i)) * i;\n    }\n    return lo;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binary_search.hpp
  requiredBy: []
  timestamp: '2024-08-26 11:12:12-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/binary_search.hpp
layout: document
redirect_from:
- /library/numeric/binary_search.hpp
- /library/numeric/binary_search.hpp.html
title: numeric/binary_search.hpp
---
