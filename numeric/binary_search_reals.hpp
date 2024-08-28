#pragma once

template <class T>
double bsmin_reals(double lo, double hi, T f) {
  static_assert(sizeof(uint64_t) >= sizeof(double));
  assert(lo <= hi);
  uint64_t l = reinterpret_cast<uint64_t&>(lo), r = reinterpret_cast<uint64_t&>(hi) + 1;
  for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {
    uint64_t nxt = r - i;
    r -= (nxt >= l && f(reinterpret_cast<double&>(nxt))) * i;
  }
  return reinterpret_cast<double&>(r);
}

template <class T>
double bsmax_reals(double lo, double hi, T f) {
  static_assert(sizeof(uint64_t) >= sizeof(double));
  assert(lo <= hi);
  uint64_t l = reinterpret_cast<uint64_t&>(lo) - 1, r = reinterpret_cast<uint64_t&>(hi);
  for (uint64_t i = 1ull << __lg(r - l); i > 0; i >>= 1) {
    uint64_t nxt = l + i;
    l += (nxt <= r && f(reinterpret_cast<double&>(nxt))) * i;
  }
  return reinterpret_cast<double&>(l);
}
