---
title: Modular Integer (Mint)
documentation_of: ./src/numeric/mint.h
---

Template class for modular arithmetic with compile-time fixed modulus and automatic reduction.

## Operations

- `Mint(x)`: Create from integer with modular reduction
- `a + b`, `a += b`: Modular addition
- `a - b`, `a -= b`: Modular subtraction
- `a * b`, `a *= b`: Modular multiplication
- `a / b`, `a /= b`: Modular division (prime modulus only)
- `pow(base, exp)`: Fast modular exponentiation

## Complexity

- Basic operations: $O(1)$
- Exponentiation: $O(\log \text{exp})$
- Space: $O(1)$ per instance

## Usage

```cpp
using mi = Mint<int(1e9 + 7)>;

mi a = 5, b = 3;
mi sum = a + b;      // 8
mi prod = a * b;     // 15
mi quot = a / b;     // modular inverse

// Exponentiation
mi result = pow(mi(2), 10);  // 2^10 mod (1e9+7)

// Factorial computation
vector<mi> fact(1000);
fact[0] = 1;
for (int i = 1; i < 1000; i++) {
  fact[i] = fact[i-1] * i;
}
```

## Notes

**Prime Modulus Required**: Division uses Fermat's Little Theorem and requires the modulus to be prime. Common prime moduli: `1000000007`, `998244353`.