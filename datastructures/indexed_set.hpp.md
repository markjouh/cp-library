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
  bundledCode: "Traceback (most recent call last):\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/home/runner/.local/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructures/indexed_set.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/* An order statistic tree using gnu pbds.\n * `find_by_order(k)`: O(log(N)),\
    \ finds the kth smallest element (0-indexed)\n * `order_of_key(v)`: O(log(N)),\
    \ counts the number of elements < v in the set\n */\n\n#pragma once\n#include\
    \ <ext/pb_ds/assoc_container.hpp>\n\nusing namespace __gnu_pbds;\n\ntemplate<class\
    \ T> using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructures/indexed_set.hpp
  requiredBy: []
  timestamp: '2024-08-26 16:40:45-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/indexed_set.hpp
layout: document
redirect_from:
- /library/datastructures/indexed_set.hpp
- /library/datastructures/indexed_set.hpp.html
title: datastructures/indexed_set.hpp
---
