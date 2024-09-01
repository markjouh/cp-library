---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/alds1/number_of_inversions.test.cpp
    title: verify/aizu/alds1/number_of_inversions.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: '#line 2 "datastructures/pbds/order_statistic_tree.hpp"


    #include <ext/pb_ds/assoc_container.hpp>


    using namespace __gnu_pbds;


    template <class T>

    using OrderStatisticTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    '
  code: '#pragma once


    #include <ext/pb_ds/assoc_container.hpp>


    using namespace __gnu_pbds;


    template <class T>

    using OrderStatisticTree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    '
  dependsOn: []
  isVerificationFile: false
  path: datastructures/pbds/order_statistic_tree.hpp
  requiredBy: []
  timestamp: '2024-08-31 22:39:57-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/number_of_inversions.test.cpp
documentation_of: datastructures/pbds/order_statistic_tree.hpp
layout: document
redirect_from:
- /library/datastructures/pbds/order_statistic_tree.hpp
- /library/datastructures/pbds/order_statistic_tree.hpp.html
title: datastructures/pbds/order_statistic_tree.hpp
---
