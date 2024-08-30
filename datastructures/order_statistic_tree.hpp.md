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
  bundledCode: '#line 2 "datastructures/order_statistic_tree.hpp"


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
  path: datastructures/order_statistic_tree.hpp
  requiredBy: []
  timestamp: '2024-08-30 00:19:12-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/alds1/number_of_inversions.test.cpp
documentation_of: datastructures/order_statistic_tree.hpp
layout: document
title: Order Statistic Tree
---

### Overview

Basically an `std::set` that supports order statistic queries, using `__gnu_pbds`.

### Usage

* `find_by_order(k)`: Finds the kth item in the set, in increasing order, indexed from 0.
* `order_of_key(k)`: Counts the number of elements < k.