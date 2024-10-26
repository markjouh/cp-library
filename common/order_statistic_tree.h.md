---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 1 "common/order_statistic_tree.h"

    #include <ext/pb_ds/assoc_container.hpp>


    using namespace __gnu_pbds;


    template <class T>

    using OSTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    '
  code: '#include <ext/pb_ds/assoc_container.hpp>


    using namespace __gnu_pbds;


    template <class T>

    using OSTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    '
  dependsOn: []
  isVerificationFile: false
  path: common/order_statistic_tree.h
  requiredBy: []
  timestamp: '2024-10-25 20:08:44-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/number_of_inversions.test.cpp
documentation_of: common/order_statistic_tree.h
layout: document
redirect_from:
- /library/common/order_statistic_tree.h
- /library/common/order_statistic_tree.h.html
title: common/order_statistic_tree.h
---
