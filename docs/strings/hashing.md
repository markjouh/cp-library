---
title: String Hashing
documentation_of: ../../strings/hashing.hpp
---

### Overview

A collection of classes used for string hashing. Allows for querying the hash of a substring, as well as comparing and concatenating returned hash objects, all in $O(1)$. Uses the random base scheme described in [rng_58's blog](https://rng-58.blogspot.com/2017/02/hashing-and-probability-of-collision.html).

### Usage

* `StringHash(s)`: Computes the polynomial rolling hash for s. $O(n)$
* `get(l, r)`: Returns the hash of the substring $[l, r]$ of s as a `Hash` object.
* `Hash::operator+`: Concatenates two substring hashes.
* `Hash::operator==`: Compares two substring hashes.