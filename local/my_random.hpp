#pragma once

namespace my_random {
  mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count());

  template <class T>
  T randint(T lo, T hi) {
    return uniform_int_distribution<T>(lo, hi)(rng_64);
  }

  template <class T>
  T randreal(T lo, T hi) {
    return uniform_real_distribution<T>(lo, hi)(rng_64);
  }

  template <class T>
  void randshuf(T &a) {
    for (int i = 1; i < sz(a); i++) {
      swap(a[i], a[randint(0, i)]);
    }
  }
};