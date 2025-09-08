---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: src/verify/library_checker/convolution/convolution_mod.test.cpp
    title: src/verify/library_checker/convolution/convolution_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/numeric/mint.h\"\ntemplate <int MOD>\nstruct Mint {\n\
    \  int v;\n\n  Mint(int64_t x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD)\
    \ + (x < 0) * MOD) {}\n \n  friend Mint pow(Mint base, int64_t exp) {\n    Mint\
    \ res = 1;\n    while (exp) {\n      if (exp & 1) {\n        res *= base;\n  \
    \    }\n      base *= base;\n      exp >>= 1;\n    }\n    return res;\n  }\n\n\
    \  Mint &operator+=(Mint b) {\n    v = v + b.v - (v + b.v >= MOD) * MOD;\n   \
    \ return *this;\n  }\n  Mint &operator-=(Mint b) {\n    v = v - b.v + (v < b.v)\
    \ * MOD;\n    return *this;\n  }\n  Mint &operator*=(Mint b) {\n    v = int(1ll\
    \ * v * b.v % MOD);\n    return *this;\n  }\n  Mint &operator/=(Mint b) {\n  \
    \  v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n    return *this;\n  }\n  friend\
    \ Mint operator+(Mint a, Mint b) {\n    return a += b;\n  }\n  friend Mint operator-(Mint\
    \ a, Mint b) {\n    return a -= b;\n  }\n  friend Mint operator*(Mint a, Mint\
    \ b) {\n    return a *= b;\n  }\n  friend Mint operator/(Mint a, Mint b) {\n \
    \   return a /= b;\n  }\n  friend ostream &operator<<(ostream &os, Mint a) {\n\
    \    return os << a.v;\n  }\n};\n\n// using mi = Mint<int(1e9 + 7)>;\n// using\
    \ mi = Mint<998244353>;\n\n// vector<mi> fact, inv_fact;\n\n// void gen_fact(int\
    \ n) {\n//   fact.resize(n + 1);\n//   inv_fact.resize(n + 1);\n//   fact[0] =\
    \ fact[1] = inv_fact[0] = inv_fact[1] = 1;\n//   for (int i = 2; i <= n; i++)\
    \ {\n//     fact[i] = fact[i - 1] * i;\n//   }\n//   inv_fact[n] = 1 / fact[n];\n\
    //   for (int i = n - 1; i >= 2; i--) {\n//     inv_fact[i] = inv_fact[i + 1]\
    \ * (i + 1);\n//   }\n// }\n\n// mi nck(int n, int k) {\n//   if (n < k || k <\
    \ 0) {\n//     return 0;\n//   }\n//   return fact[n] * inv_fact[k] * inv_fact[n\
    \ - k];\n// }\n"
  code: "template <int MOD>\nstruct Mint {\n  int v;\n\n  Mint(int64_t x = 0) : v(int(-MOD\
    \ < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}\n \n  friend Mint pow(Mint\
    \ base, int64_t exp) {\n    Mint res = 1;\n    while (exp) {\n      if (exp &\
    \ 1) {\n        res *= base;\n      }\n      base *= base;\n      exp >>= 1;\n\
    \    }\n    return res;\n  }\n\n  Mint &operator+=(Mint b) {\n    v = v + b.v\
    \ - (v + b.v >= MOD) * MOD;\n    return *this;\n  }\n  Mint &operator-=(Mint b)\
    \ {\n    v = v - b.v + (v < b.v) * MOD;\n    return *this;\n  }\n  Mint &operator*=(Mint\
    \ b) {\n    v = int(1ll * v * b.v % MOD);\n    return *this;\n  }\n  Mint &operator/=(Mint\
    \ b) {\n    v = int(1ll * v * pow(b, MOD - 2).v % MOD);\n    return *this;\n \
    \ }\n  friend Mint operator+(Mint a, Mint b) {\n    return a += b;\n  }\n  friend\
    \ Mint operator-(Mint a, Mint b) {\n    return a -= b;\n  }\n  friend Mint operator*(Mint\
    \ a, Mint b) {\n    return a *= b;\n  }\n  friend Mint operator/(Mint a, Mint\
    \ b) {\n    return a /= b;\n  }\n  friend ostream &operator<<(ostream &os, Mint\
    \ a) {\n    return os << a.v;\n  }\n};\n\n// using mi = Mint<int(1e9 + 7)>;\n\
    // using mi = Mint<998244353>;\n\n// vector<mi> fact, inv_fact;\n\n// void gen_fact(int\
    \ n) {\n//   fact.resize(n + 1);\n//   inv_fact.resize(n + 1);\n//   fact[0] =\
    \ fact[1] = inv_fact[0] = inv_fact[1] = 1;\n//   for (int i = 2; i <= n; i++)\
    \ {\n//     fact[i] = fact[i - 1] * i;\n//   }\n//   inv_fact[n] = 1 / fact[n];\n\
    //   for (int i = n - 1; i >= 2; i--) {\n//     inv_fact[i] = inv_fact[i + 1]\
    \ * (i + 1);\n//   }\n// }\n\n// mi nck(int n, int k) {\n//   if (n < k || k <\
    \ 0) {\n//     return 0;\n//   }\n//   return fact[n] * inv_fact[k] * inv_fact[n\
    \ - k];\n// }"
  dependsOn: []
  isVerificationFile: false
  path: src/numeric/mint.h
  requiredBy: []
  timestamp: '2025-09-07 14:42:16-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - src/verify/library_checker/convolution/convolution_mod.test.cpp
documentation_of: src/numeric/mint.h
layout: document
title: Modular Integer (Mint)
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