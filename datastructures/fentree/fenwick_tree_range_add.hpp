#pragma once

template <class T>
struct RangeAddFT {
  int n;
  vector<T> ft;

  RangeAddFT(int x) : n(x), ft(n + 1) {}

  RangeAddFT(const vector<T> &a) : n(sz(a)), ft(n + 1) {
    for (int i = 0; i < n; i++) {
      ft[i + 1] += a[i];
      ft[i] -= a[i];
    }
    for (int i = n; i >= 1; i--) {
      ft[i - (i & -i)] += ft[i];
    }
  }

  void add(int r, T v) {
    // assert(r < n);
    for (r++; r > 0; r -= r & -r) {
      ft[r] += v;
    }
  }

  void add(int l, int r, T v) {
    add(r, v);
    add(l - 1, T(0) - v);
  }

  T get(int p) {
    // assert(p >= 0);
    T res = 0;
    for (p++; p <= n; p += p & -p) {
      res += ft[p];
    }
    return res;
  }
};