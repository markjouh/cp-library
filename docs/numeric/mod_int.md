---
title: Mod Int
documentation_of: ../../numeric/mod_int.hpp
---

### Overview

Class that does arithmetic mod some prime modulus $M$. Commonly used in combinatorics problems.

### Usage

* `ModInt::operator o` For $o \in {+, -, *}$: $O(1)$
* `ModInt::operator/`: $O(\log{M})$
* `pow(b, e)`: $O(\log{e})$