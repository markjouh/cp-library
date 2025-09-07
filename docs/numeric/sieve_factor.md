---
title: Sieve with Factorization
documentation_of: ./src/numeric/sieve_factor.h
---

Sieve of Eratosthenes with prime factorization support for efficient factor queries.

## Operations

- `SieveFactor(n)`: Precompute primes and smallest factors up to `n`
- `is_prime(x)`: Check if `x` is prime
- `factorize(x)`: Get prime factorization of `x`

## Complexity

- Construction: $O(n \log \log n)$
- `is_prime`: $O(1)$
- `factorize`: $O(\log x)$
- Space: $O(n)$

## Usage

```cpp
SieveFactor sieve(100);

bool prime = sieve.is_prime(17); // true
auto factors = sieve.factorize(60); // {2: 2, 3: 1, 5: 1} for 2^2 * 3 * 5
```

## Notes

Stores smallest prime factor for each number. Factorization extracts factors by repeatedly dividing by smallest factor.