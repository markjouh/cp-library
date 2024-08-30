---
title: Indexed Set
documentation_of: ../../datastructures/order_statistic_tree.hpp
---

### Overview

Basically an `std::set` that supports order statistic queries, using `__gnu_pbds`.

### Usage

* `find_by_order(k)`: Finds the kth item in the set, in increasing order, indexed from 0.
* `order_of_key(k)`: Counts the number of elements < k.