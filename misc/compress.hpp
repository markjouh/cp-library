#pragma once

template <class T>
struct Compress {
  vector<T> vals;

  Compress() {}

  Compress(const vector<T> &a) : vals(a) {
    init();
  }

  void init() {
    sort(all(vals));
    vals.resize(unique(all(vals)) - begin(vals));
  }

  void insert(T x) {
    vals.push_back(x);
  }

  int get(T x) {
    return lower_bound(all(vals), x) - begin(vals);
  }

  T operator[](int p) {
    return vals[p];
  }
};