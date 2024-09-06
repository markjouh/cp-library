#pragma once

// https://codeforces.com/contest/2006/submission/280125218

template <class T, T(*op)(T, T), T(*id)()>
struct SegmentTreeSet {
  int n;
  set<int> free;
  set<pair<T, int>> used;
  SegmentTree<T, op, id> st;

  SegmentTreeSet(int n_) : n(n_), st(n) {
    for (int i = 0; i < n; i++) {
      free.insert(i);
    }
  }

  void insert(T x) {
    assert(!free.empty());
    T p = *begin(free);
    free.erase(begin(free));
    st.set(p, x);
    used.emplace(x, p);
  }

  void extract(T x) {
    auto it = used.lower_bound({x, -1});
    assert(it->fi == x);
    st.set(it->se, id());
    free.insert(it->se);
    used.erase(it);
  }

  T query() {
    return st.query(0, n - 1);
  }
};