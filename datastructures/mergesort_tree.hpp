#pragma once

template <class T>
struct MergesortTree {
  int n;
  vector<vector<T>> st;

  MergesortTree(const vector<T> &a) : n(sz(a)), st(2 * n) {
    for (int i = 0; i < n; i++) {
      st[i + n] = {a[i]};
    }
    for (int i = n - 1; i > 0; i--) {
      merge(begin(st[i << 1]), end(st[i << 1]), begin(st[i << 1 | 1]),
        end(st[i << 1 | 1]), back_inserter(st[i]));
    }
  }

  T query(int l, int r, T v) {
    T ls = 0, rs = 0;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if (l & 1) {
        ls += lower_bound(all(st[l]), v) - begin(st[l]);
        l++;
      }
      if (r & 1) {
        r--;
        rs += lower_bound(all(st[r]), v) - begin(st[r]);
      }
    }
    return ls + rs;
  }
};