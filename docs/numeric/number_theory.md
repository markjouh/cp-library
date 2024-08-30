---
title: Number Theory
documentation_of: ../../numeric/number_theory.hpp
---

### Overview

A prime sieve and collection of helpers for number theory problems.

### Usage

* `sieve(n)`: Runs the sieve up to n. $O(n \log{\log{n}})$
* `factor(k)`: Computes the prime factorization of k. $O(\log{n})$ if sieve has been run up to k, $O(\dfrac{\sqrt{k}}{\log{k}})$ otherwise. Sieve must be run up to $\sqrt{k}$.
* `gen_divisors(facs)`: Generates all divisors of a number k from its prime factorization. Complexity is linear in the number of factors, which is approximately $\sqrt[3]{k}$.