#pragma once

template <int MOD>
struct ModInt {
  int v;
 
  ModInt(i64 x = 0) : v(int(-MOD < x && x < MOD ? x : x % MOD) + (x < 0) * MOD) {}
 
  friend ModInt pow(ModInt base, int exp) {
    ModInt res = 1;
    while (exp) {
      if (exp & 1) {
        res *= base;
      }
      base *= base;
      exp >>= 1;
    }
    return res;
  }
 
  ModInt &operator+=(ModInt b) {
    if ((v += b.v) >= MOD) {
      v -= MOD;
    }
    return *this;
  }
 
  ModInt &operator-=(ModInt b) {
    if ((v -= b.v) < 0) {
      v += MOD;
    }
    return *this;
  }
 
  ModInt &operator*=(ModInt b) {
    v = int(1ll * v * b.v % MOD);
    return *this;
  }
 
  ModInt &operator/=(ModInt b) {
    v = int(1ll * v * pow(b, MOD - 2).v % MOD);
    return *this;
  }
 
  friend ModInt operator+(ModInt a, ModInt b) {
    return a += b;
  }
 
  friend ModInt operator-(ModInt a, ModInt b) {
    return a -= b;
  }
 
  friend ModInt operator*(ModInt a, ModInt b) {
    return a *= b;
  }
 
  friend ModInt operator/(ModInt a, ModInt b) {
    return a /= b;
  }
 
  friend ostream &operator<<(ostream &os, ModInt a) {
    return os << a.v;
  }
};
