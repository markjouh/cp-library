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
  bundledCode: '#line 2 "datastructures/pbds/order_statistic_tree.h"


    #include <ext/pb_ds/assoc_container.hpp>


    using namespace __gnu_pbds;


    template <class T>

    using OSTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    '
  code: '#pragma once


    #include <ext/pb_ds/assoc_container.hpp>


    using namespace __gnu_pbds;


    template <class T>

    using OSTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    '
  dependsOn: []
  isVerificationFile: false
  path: datastructures/pbds/order_statistic_tree.h
  requiredBy: []
  timestamp: '2024-09-19 17:13:58-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/number_of_inversions.test.cpp
documentation_of: datastructures/pbds/order_statistic_tree.h
layout: document
redirect_from:
- /library/datastructures/pbds/order_statistic_tree.h
- /library/datastructures/pbds/order_statistic_tree.h.html
title: datastructures/pbds/order_statistic_tree.h
---
