#pragma once

template <class T>
struct FenwickTree {
  int n;
  vector<T> ft;

  FenwickTree(int x) : n(x), ft(n + 1) {}

  FenwickTree(const vector<T> &a) : n(sz(a)), ft(n + 1) {
    for (int i = 1; i <= n; i++) {
      ft[i] += a[i - 1];
      if (i + (i & -i) <= n) {
        ft[i + (i & -i)] += ft[i];
      }
    }
  }

  void add(int p, T v) {
    // assert(p >= 0);
    for (p++; p <= n; p += p & -p) {
      ft[p] += v;
    }
  }

  T sum(int r) {
    // assert(r < n);
    T res = 0;
    for (r++; r > 0; r -= r & -r) {
      res += ft[r];
    }
    return res;
  }

  T sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};