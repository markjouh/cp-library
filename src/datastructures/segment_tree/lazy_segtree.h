template <class T, auto op, auto t_id, class U, auto mapping, auto comp, auto u_id>
struct LazySegtree {
  LazySegtree(int n_, T v = t_id()) {
    init(n_, v);
    pull_all();
  }

  LazySegtree(const vector<T> &a) {
    init(ssize(a), t_id());
    copy(all(a), begin(st) + tree_sz);
    pull_all();
  }

  void set(int p, T v) {
    push_path(p += tree_sz);
    st[p] = v;
    pull_path(p);
  }

  void update(int p, U v) {
    push_path(p += tree_sz);
    st[p] = mapping(st[p], v);
    pull_path(p);
  }

  void update(int l, int r, U v) {
    assert(0 <= l && l <= r && r < n);
    l += tree_sz;
    r += tree_sz + 1;

    push_range(l, r);

    int l2 = l, r2 = r;
    while (l2 < r2) {
      if (l2 & 1) {
        apply(l2++, v);
      }
      if (r2 & 1) {
        apply(--r2, v);
      }
      l2 >>= 1;
      r2 >>= 1;
    }

    pull_range(l, r);
  }

  T get(int p) {
    push_path(p += tree_sz);
    return st[p];
  }

  T query(int l, int r) {
    assert(0 <= l && l <= r && r < n);
    l += tree_sz;
    r += tree_sz + 1;

    push_range(l, r);

    T ls = t_id(), rs = t_id();
    while (l < r) {
      if (l & 1) {
        ls = op(ls, st[l++]);
      }
      if (r & 1) {
        rs = op(st[--r], rs);
      }
      l >>= 1;
      r >>= 1;
    }
    return op(ls, rs);
  }

  T query_all() {
    return st[1];
  }

  template <class F>
  int find_first(F f) {
    T pref = t_id();
    int x = 1;
    for (int i = 0; i < log; i++) {
      push(x);
      if (f(op(pref, st[x << 1]))) {
        x = x << 1;
      } else {
        pref = op(pref, st[x << 1]);
        x = x << 1 | 1;
      }
    }
    return f(op(pref, st[x])) ? x - tree_sz : n;
  }

  template <class F>
  int find_last(F f) {
    T suff = t_id();
    int x = 1;
    for (int i = 0; i < log; i++) {
      push(x);
      if (f(op(st[x << 1 | 1], suff))) {
        x = x << 1 | 1;
      } else {
        suff = op(st[x << 1 | 1], suff);
        x = x << 1;
      }
    }
    return f(op(st[x], suff)) ? x - tree_sz : -1;
  }
  
private:
  int n, log, tree_sz;
  vector<T> st;
  vector<U> lz;

  void init(int n_, T v) {
    n = n_;
    log = __lg(n - 1) + 1;
    tree_sz = 1 << log;
    st.resize(tree_sz << 1, v);
    lz.resize(tree_sz, u_id());
  }

  void apply(int x, U y) {
    st[x] = mapping(st[x], y);
    if (x < tree_sz) {
      lz[x] = comp(lz[x], y);
    }
  }

  void push(int x) {
    apply(x << 1, lz[x]);
    apply(x << 1 | 1, lz[x]);
    lz[x] = u_id();
  }

  void push_path(int x) {
    for (int i = log; i > 0; i--) {
      push(x >> i);
    }
  }

  void push_range(int l, int r) {
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) {
        push(l >> i);
      }
      if (((r >> i) << i) != r) {
        push((r - 1) >> i);
      }
    }
  }

  void pull(int x) {
    st[x] = op(st[x << 1], st[x << 1 | 1]);
  }

  void pull_path(int x) {
    for (int i = 1; i <= log; i++) {
      pull(x >> i);
    }
  }

  void pull_range(int l, int r) {
    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) {
        pull(l >> i);
      }
      if (((r >> i) << i) != r) {
        pull((r - 1) >> i);
      }
    }
  }

  void pull_all() {
    for (int i = tree_sz - 1; i > 0; i--) {
      pull(i);
    }
  }
};
