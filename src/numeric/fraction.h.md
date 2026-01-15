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
