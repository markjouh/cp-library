#pragma once

template <class T>
double bsminReals(double lo, double hi, T f) {
  static_assert(sizeof(u64) >= sizeof(double));
  assert(lo <= hi);
  u64 l = reinterpret_cast<u64&>(lo), r = reinterpret_cast<u64&>(hi) + 1;
  for (u64 i = 1ull << __lg(r - l); i > 0; i >>= 1) {
    u64 nxt = r - i;
    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt))) * i;
  }
  return reinterpret_cast<double&>(r);
}

template <class T>
double bsmaxReals(double lo, double hi, T f) {
  static_assert(sizeof(u64) >= sizeof(double));
  assert(lo <= hi);
  u64 l = reinterpret_cast<u64&>(lo) - 1, r = reinterpret_cast<u64&>(hi);
  for (u64 i = 1ull << __lg(r - l); i > 0; i >>= 1) {
    u64 nxt = l + i;
    l += (nxt <= r && f(reinterpret_cast<double&>(nxt))) * i;
  }
  return reinterpret_cast<double&>(l);
}
