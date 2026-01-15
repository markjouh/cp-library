---
title: Fraction
documentation_of: ./src/numeric/fraction.h
---

Exact rational arithmetic with comparison using 128-bit integers to prevent overflow.

## Operations

- `Frac(num, den)`: Create fraction `num/den` (default: `0/1`)
- `reduce()`: Reduce fraction to lowest terms
- `+`, `-`, `*`, `/`: Arithmetic operations
- `-a`: Unary negation
- `<`, `<=`, `>`, `>=`, `==`, `!=`: Comparison operations
- `<<`: Output as `num/den`

## Complexity

- Arithmetic: $O(1)$ (no auto-reduction)
- `reduce()`: $O(\log(\min(\text{num}, \text{den})))$
- Comparison: $O(1)$ using 128-bit multiplication
- Space: $O(1)$ per fraction

## Usage

```cpp
Frac a(3, 4);  // 3/4
Frac b(1, 2);  // 1/2

Frac sum = a + b;      // 10/8 (not auto-reduced)
sum.reduce();          // 5/4

Frac product = a * b;  // 3/8

if (a > b) {
  cout << a << " > " << b << endl;  // "3/4 > 1/2"
}
```

## Notes

Fractions are not automatically reduced after operations; call `reduce()` explicitly when needed. Comparisons use `__int128` to avoid overflow. Denominator is always kept positive.
