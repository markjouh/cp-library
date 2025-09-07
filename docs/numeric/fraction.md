---
title: Fraction
documentation_of: ./src/numeric/fraction.h
---

Exact rational arithmetic with automatic simplification and overflow protection.

## Operations

- `Fraction(num, den)`: Create fraction `num/den`
- `+`, `-`, `*`, `/`: Arithmetic operations
- `<`, `<=`, `>`, `>=`, `==`, `!=`: Comparison operations
- `to_double()`: Convert to floating-point approximation

## Complexity

- All operations: $O(\log(\min(\text{num}, \text{den})))$ for GCD computation
- Space: $O(1)$ per fraction

## Usage

```cpp
Fraction a(3, 4);  // 3/4
Fraction b(1, 2);  // 1/2

Fraction sum = a + b;      // 5/4
Fraction product = a * b;  // 3/8
Fraction quotient = a / b; // 3/2

if (a > b) {
  cout << "3/4 > 1/2" << endl;
}

double approx = sum.to_double(); // 1.25
```

## Notes

Automatically reduces fractions to lowest terms. Handles negative fractions and prevents overflow in intermediate calculations.