#pragma once

template <class T, auto op, auto idT, class U, auto mapping, auto comp, auto idU>
struct LazySegmentTree {
  LazySegmentTree(int x, T v = idT()) {
    init(x, v);
    pullAll();
  }

  LazySegmentTree(const vector<T> &a) {
    init(sz(a), idT());
    copy(all(a), begin(st) + treeSize);
    pullAll();
  }

  void set(int p, T v) {
    pushPath(p += treeSize);
    st[p] = v;
    pullPath(p);
  }

  void update(int p, U v) {
    pushPath(p += treeSize);
    st[p] = mapping(st[p], v);
    pullPath(p);
  }

  void update(int l, int r, U v) {
    update(l, r + 1, v, 1, 0, treeSize);
  }

  T getAll() {
    return st[1];
  }

  T get(int p) {
    pushPath(p += treeSize);
    return st[p];
  }

  T query(int l, int r) {
    return query(l, r + 1, 1, 0, treeSize);
  }

  template <class F>
  int findFirst(F f) {
    T pref = idT();
    int x = 1;
    while (x < treeSize) {
      push(x);
      if (f(op(pref, st[x << 1]))) {
        x = x << 1;
      } else {
        pref = op(pref, st[x << 1]);
        x = x << 1 | 1;
      }
    }
    return f(op(pref, st[x])) ? x - treeSize : n;
  }

  template <class F>
  int findLast(F f) {
    T suff = idT();
    int x = 1;
    while (x < treeSize) {
      push(x);
      if (f(st[x << 1 | 1], suff)) {
        x = x << 1 | 1;
      } else {
        suff = op(st[x << 1 | 1], suff);
        x = x << 1;
      }
    }
    return f(op(st[x], suff)) ? x - treeSize : -1;
  }
  
private:
  int n, log, treeSize;
  vector<T> st;
  vector<U> lz;

  void init(int x, T v) {
    n = x;
    log = __lg(n - 1) + 1;
    treeSize = 1 << log;
    st.resize(treeSize << 1, v);
    lz.resize(treeSize, idU());
  }

  void pull(int x) {
    st[x] = op(st[x << 1], st[x << 1 | 1]);
  }

  void pullPath(int x) {
    for (int i = 1; i <= log; i++) {
      pull(x >> i);
    }
  }

  void pullAll() {
    for (int i = treeSize - 1; i > 0; i--) {
      pull(i);
    }
  }

  void apply(int x) {
    st[x] = mapping(st[x], lz[x >> 1]);
    if (x < treeSize) {
      lz[x] = comp(lz[x], lz[x >> 1]);
    }
  }

  void push(int x) {
    apply(x << 1);
    apply(x << 1 | 1);
    lz[x] = idU();
  }

  void pushPath(int x) {
    for (int i = log; i > 0; i--) {
      push(x >> i);
    }
  }

  void update(int l, int r, U v, int x, int tl, int tr) {
    if (tl >= r || tr <= l) {
      return;
    }
    if (tl >= l && tr <= r) {
      st[x] = mapping(st[x], v);
      if (x < treeSize) {
        lz[x] = comp(lz[x], v);
      }
      return;
    }
    push(x);
    int mid = (tl + tr) >> 1;
    update(l, r, v, x << 1, tl, mid);
    update(l, r, v, x << 1 | 1, mid, tr);
    pull(x);
  }

  T query(int l, int r, int x, int tl, int tr) {
    if (tl >= r || tr <= l) {
      return idT();
    }
    if (tl >= l && tr <= r) {
      return st[x];
    }
    push(x);
    int mid = (tl + tr) >> 1;
    return op(query(l, r, x << 1, tl, mid), query(l, r, x << 1 | 1, mid, tr));
  }
};