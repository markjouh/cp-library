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
  bundledCode: '#line 2 "datastructures/indexed_set.hpp"

    #include <ext/pb_ds/assoc_container.hpp>


    using namespace __gnu_pbds;


    template <class T>

    using IndSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    '
  code: '#pragma once

    #include <ext/pb_ds/assoc_container.hpp>


    using namespace __gnu_pbds;


    template <class T>

    using IndSet = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

    '
  dependsOn: []
  isVerificationFile: false
  path: datastructures/indexed_set.hpp
  requiredBy: []
  timestamp: '2024-08-28 03:11:34-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructures/indexed_set.hpp
layout: document
title: Indexed Set
---

### Overview

Basically an `std::set` that supports order statistic queries, using `__gnu_pbds`.

### Usage

* `find_by_order(k)`: Finds the kth item in the set, in increasing order, indexed from 0.
* `order_of_key(k)`: Counts the number of elements < k.