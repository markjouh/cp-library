struct Frac {
  int64_t num, den;

  Frac(int64_t n = 0, int64_t d = 1) : num(n), den(d) {
    assert(den != 0);
    if (den < 0) {
      num = -num;
      den = -den;
    }
  }

  void reduce() {
    int64_t g = __gcd(abs(num), den);
    num /= g;
    den /= g;
  }

  int comp(const Frac &b) const {
    __int128_t val = (__int128_t) num * b.den - (__int128_t) b.num * den;
    return (val > 0) - (val < 0);
  }

  Frac operator-() const {
    return Frac(-num, den);
  }

  Frac &operator+=(const Frac &b) {
    return *this = Frac(num * b.den + b.num * den, den * b.den);
  }
  Frac &operator-=(const Frac &b) {
    return *this = Frac(num * b.den - b.num * den, den * b.den);
  }
  Frac &operator*=(const Frac &b) {
    return *this = Frac(num * b.num, den * b.den);
  }
  Frac &operator/=(const Frac &b) {
    return *this = Frac(num * b.den, den * b.num);
  }

  friend Frac operator+(Frac a, const Frac &b) {
    return a += b;
  }
  friend Frac operator-(Frac a, const Frac &b) {
    return a -= b;
  }
  friend Frac operator*(Frac a, const Frac &b) {
    return a *= b;
  }
  friend Frac operator/(Frac a, const Frac &b) {
    return a /= b;
  }

  bool operator==(const Frac &b) const {
    return comp(b) == 0;
  }
  bool operator!=(const Frac &b) const {
    return comp(b) != 0;
  }
  bool operator<(const Frac &b) const {
    return comp(b) < 0;
  }
  bool operator>(const Frac &b) const {
    return comp(b) > 0;
  }
  bool operator<=(const Frac &b) const {
    return comp(b) <= 0;
  }
  bool operator>=(const Frac &b) const {
    return comp(b) >= 0;
  }

  friend ostream &operator<<(ostream &out, const Frac a) {
    return out << a.num << '/' << a.den;
  }
};