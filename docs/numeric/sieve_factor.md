---
title: Sieve with Factorization
documentation_of: ./src/numeric/sieve_factor.h
---

Sieve of Eratosthenes with prime factorization and divisor generation.

## Operations

- `sieve(n)`: Precompute primes and smallest prime factors up to `n`
- `factorize(x)`: Get prime factorization of `x` as vector of `(prime, exponent)` pairs
- `gen_divisors(x)`: Generate all divisors of `x`

## Global Variables

- `primes`: Vector of all primes up to `n`
- `mn_factor`: Vector where `mn_factor[i]` is the smallest prime factor of `i`

## Complexity

- `sieve`: $O(n \log \log n)$
- `factorize`: $O(\log x)$ if sieved up to `x`, $O(\sqrt{x} \log x)$ otherwise
- `gen_divisors`: $O(d(x))$ where $d(x)$ is the number of divisors
- Space: $O(n)$

## Usage

```cpp
sieve(100000);

// Check if prime
bool is_prime = (mn_factor[17] == 17);  // true

// Get prime factorization
auto factors = factorize(60);  // [(2, 2), (3, 1), (5, 1)] for 2^2 * 3 * 5

// Generate all divisors
auto divs = gen_divisors(12);  // [1, 2, 4, 3, 6, 12]
```

## Notes

Stores smallest prime factor for each number. Factorization extracts factors by repeatedly dividing by smallest factor. For numbers larger than sieved range, requires sieving up to $\sqrt{x}$.
