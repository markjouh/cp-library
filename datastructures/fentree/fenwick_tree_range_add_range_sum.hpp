#pragma once

#include "fenwick_tree.hpp"

template <class T>
struct RangeAddRangeSumFT {
  int n;
  FenwickTree<T> in_pref, os_pref;

  RangeAddRangeSumFT(int n_) : n(n_), in_pref(n), os_pref(n) {}

  T sum(int r) {
    return in_pref.sum(r - 1) + os_pref.sum(n - r - 1) * (r + 1);
  }

  T sum(int l, int r) {
    return sum(r) - (l > 0 ? sum(l - 1) : 0);
  }

  void add(int r, T v) {
    in_pref.add(r, v * (r + 1));
    os_pref.add(n - r - 1, v);
  }

  void add(int l, int r, T v) {
    add(r, v);
    if (l > 0) {
      add(l - 1, T(0) - T(v));
    }
  }
};