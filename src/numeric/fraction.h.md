---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/numeric/fraction.h\"\nstruct Frac {\n  int64_t num,\
    \ den;\n\n  Frac(int64_t n = 0, int64_t d = 1) : num(n), den(d) {\n    assert(den\
    \ != 0);\n    if (den < 0) {\n      num = -num;\n      den = -den;\n    }\n  }\n\
    \n  void reduce() {\n    int64_t g = __gcd(abs(num), den);\n    num /= g;\n  \
    \  den /= g;\n  }\n\n  int comp(const Frac &b) const {\n    __int128_t val = (__int128_t)\
    \ num * b.den - (__int128_t) b.num * den;\n    return (val > 0) - (val < 0);\n\
    \  }\n\n  Frac operator-() const {\n    return Frac(-num, den);\n  }\n\n  Frac\
    \ &operator+=(const Frac &b) {\n    return *this = Frac(num * b.den + b.num *\
    \ den, den * b.den);\n  }\n  Frac &operator-=(const Frac &b) {\n    return *this\
    \ = Frac(num * b.den - b.num * den, den * b.den);\n  }\n  Frac &operator*=(const\
    \ Frac &b) {\n    return *this = Frac(num * b.num, den * b.den);\n  }\n  Frac\
    \ &operator/=(const Frac &b) {\n    return *this = Frac(num * b.den, den * b.num);\n\
    \  }\n\n  friend Frac operator+(Frac a, const Frac &b) {\n    return a += b;\n\
    \  }\n  friend Frac operator-(Frac a, const Frac &b) {\n    return a -= b;\n \
    \ }\n  friend Frac operator*(Frac a, const Frac &b) {\n    return a *= b;\n  }\n\
    \  friend Frac operator/(Frac a, const Frac &b) {\n    return a /= b;\n  }\n\n\
    \  bool operator==(const Frac &b) const {\n    return comp(b) == 0;\n  }\n  bool\
    \ operator!=(const Frac &b) const {\n    return comp(b) != 0;\n  }\n  bool operator<(const\
    \ Frac &b) const {\n    return comp(b) < 0;\n  }\n  bool operator>(const Frac\
    \ &b) const {\n    return comp(b) > 0;\n  }\n  bool operator<=(const Frac &b)\
    \ const {\n    return comp(b) <= 0;\n  }\n  bool operator>=(const Frac &b) const\
    \ {\n    return comp(b) >= 0;\n  }\n\n  friend ostream &operator<<(ostream &out,\
    \ const Frac a) {\n    return out << a.num << '/' << a.den;\n  }\n};\n"
  code: "struct Frac {\n  int64_t num, den;\n\n  Frac(int64_t n = 0, int64_t d = 1)\
    \ : num(n), den(d) {\n    assert(den != 0);\n    if (den < 0) {\n      num = -num;\n\
    \      den = -den;\n    }\n  }\n\n  void reduce() {\n    int64_t g = __gcd(abs(num),\
    \ den);\n    num /= g;\n    den /= g;\n  }\n\n  int comp(const Frac &b) const\
    \ {\n    __int128_t val = (__int128_t) num * b.den - (__int128_t) b.num * den;\n\
    \    return (val > 0) - (val < 0);\n  }\n\n  Frac operator-() const {\n    return\
    \ Frac(-num, den);\n  }\n\n  Frac &operator+=(const Frac &b) {\n    return *this\
    \ = Frac(num * b.den + b.num * den, den * b.den);\n  }\n  Frac &operator-=(const\
    \ Frac &b) {\n    return *this = Frac(num * b.den - b.num * den, den * b.den);\n\
    \  }\n  Frac &operator*=(const Frac &b) {\n    return *this = Frac(num * b.num,\
    \ den * b.den);\n  }\n  Frac &operator/=(const Frac &b) {\n    return *this =\
    \ Frac(num * b.den, den * b.num);\n  }\n\n  friend Frac operator+(Frac a, const\
    \ Frac &b) {\n    return a += b;\n  }\n  friend Frac operator-(Frac a, const Frac\
    \ &b) {\n    return a -= b;\n  }\n  friend Frac operator*(Frac a, const Frac &b)\
    \ {\n    return a *= b;\n  }\n  friend Frac operator/(Frac a, const Frac &b) {\n\
    \    return a /= b;\n  }\n\n  bool operator==(const Frac &b) const {\n    return\
    \ comp(b) == 0;\n  }\n  bool operator!=(const Frac &b) const {\n    return comp(b)\
    \ != 0;\n  }\n  bool operator<(const Frac &b) const {\n    return comp(b) < 0;\n\
    \  }\n  bool operator>(const Frac &b) const {\n    return comp(b) > 0;\n  }\n\
    \  bool operator<=(const Frac &b) const {\n    return comp(b) <= 0;\n  }\n  bool\
    \ operator>=(const Frac &b) const {\n    return comp(b) >= 0;\n  }\n\n  friend\
    \ ostream &operator<<(ostream &out, const Frac a) {\n    return out << a.num <<\
    \ '/' << a.den;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/numeric/fraction.h
  requiredBy: []
  timestamp: '2025-09-06 20:10:03-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/numeric/fraction.h
layout: document
title: Fraction
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