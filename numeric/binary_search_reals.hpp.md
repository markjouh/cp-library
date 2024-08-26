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
    - https://codeforces.com/blog/entry/63085.
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ numeric/binary_search_reals.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/* Find the first true/last true value given a continous monotonic boolean\
    \ function.\n * Implementation based off of https://codeforces.com/blog/entry/63085.\n\
    \ * `bsmin(l, r, f)`, `bsmax(l, r, f)`: O(log(hi - lo) * T_f)\n */\n\n#pragma\
    \ once\n\ntemplate<class T> db bsmin_reals(db lo, db hi, T f) {\n    assert(sizeof(uint64_t)\
    \ >= sizeof(db));\n    assert(lo <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo),\
    \ r = reinterpret_cast<uint64_t&>(hi) + 1;\n    for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n        uint64_t nxt = r - i;\n        r -= (nxt >=\
    \ l && f(reinterpret_cast<db&>(nxt))) * i;\n    }\n    return reinterpret_cast<db&>(r);\n\
    }\n\ntemplate<class T> db bsmax_reals(db lo, db hi, T f) {\n    assert(sizeof(uint64_t)\
    \ >= sizeof(db));\n    assert(lo <= hi);\n    uint64_t l = reinterpret_cast<uint64_t&>(lo)\
    \ - 1, r = reinterpret_cast<uint64_t&>(hi);\n    for (uint64_t i = 1ull << __lg(r\
    \ - l); i > 0; i >>= 1) {\n        uint64_t nxt = l + i;\n        l += (nxt <=\
    \ r && f(reinterpret_cast<db&>(nxt))) * i;\n    }\n    return reinterpret_cast<db&>(l);\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: numeric/binary_search_reals.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/binary_search_reals.hpp
layout: document
redirect_from:
- /library/numeric/binary_search_reals.hpp
- /library/numeric/binary_search_reals.hpp.html
title: numeric/binary_search_reals.hpp
---
