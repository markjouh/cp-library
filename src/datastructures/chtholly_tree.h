// With this treasure, I summon...
template <class T>
struct ChthollyTree {
  struct Seg {
    int l, r;
    T val;

    Seg() {}
    Seg(int l_, int r_, T v) : l(l_), r(r_), val(v) {}

    bool operator<(const Seg &b) const {
      return l < b.l;
    }
  };

  int n;
  set<Seg> st;

  using Iter = typename set<Seg>::iterator;

  ChthollyTree(int n_, T v) : n(n_) {
    st.emplace(0, n - 1, v);
  }
  ChthollyTree(const vector<T> &a) : n(a.size()) {
    int p = -1;
    for (int i = 0; i < n; i++) {
      if (i == n - 1 || a[i] != a[i + 1]) {
        st.emplace(Seg(p + 1, i, a[i]));
        p = i;
      }
    }
  }

  template <class U>
  void traverse(int l, int r, U f) {
    try_split(find_seg(l), l);
    try_split(find_seg(r), r + 1);

    Iter it = find_seg(l), end = ++find_seg(r);
    while (it != end) {
      f(it++);
    }
  }

  template <class U>
  void apply(int l, int r, U f) {
    Seg buf;
    traverse(l, r, [&](Iter it) {
      Seg s = *it;
      st.erase(it);
      T v = f(s.val);
      if (v != buf.val || s.l == l) {
        if (s.l != l) {
          st.insert(buf);
        }
        buf.l = s.l;
        buf.val = v;
      }
      buf.r = s.r;
    });
    st.insert(buf);
  }

private:
  Iter find_seg(int x) const {
    assert(x >= 0 && x < n);
    return --st.upper_bound(Seg(x, INT_MAX, T{}));
  }

  void try_split(Iter it, int x) {
    if (it->l < x && it->r >= x) {
      Seg ls = Seg(it->l, x - 1, it->val);
      Seg rs = Seg(x, it->r, it->val);
      st.erase(it);
      st.insert(ls);
      st.insert(rs);
    }
  }
};