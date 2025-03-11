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
  bundledCode: "#line 1 \"numeric/fraction.h\"\nstruct Frac {\n  int64_t num, den;\n\
    \n  Frac(int64_t n = 0, int64_t d = 1) : num(n), den(d) {\n    assert(den != 0);\n\
    \    if (den < 0) {\n      num = -num;\n      den = -den;\n    }\n  }\n\n  void\
    \ reduce() {\n    int64_t g = __gcd(abs(num), den);\n    num /= g;\n    den /=\
    \ g;\n  }\n\n  int comp(const Frac &b) const {\n    __int128_t val = (__int128_t)\
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
  path: numeric/fraction.h
  requiredBy: []
  timestamp: '2025-03-11 01:06:40-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: numeric/fraction.h
layout: document
redirect_from:
- /library/numeric/fraction.h
- /library/numeric/fraction.h.html
title: numeric/fraction.h
---
