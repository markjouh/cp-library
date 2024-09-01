#pragma once

struct LazySegmentTree {
  using item_t = pair<int, int>;
  using upd_t = int;

  // Identity element, null update tag
  const item_t id = {INF, 1};
  const upd_t lz_id = 0;

  // Associative merge operation
  item_t merge(item_t a, item_t b) {
    if (a.first == b.first) {
      return {a.first, a.second + b.second};
    } else {
      return a.first < b.first ? a : b;
    }
  }

  // Apply a lazy tag to a full segment
  void apply(int x, upd_t v) {
    lz[x] += v;
  }

  // Consume and propagate a lazy tag
  void push(int x, int tl, int tr) {
    if (lz[x] != lz_id) {
      st[x].first += lz[x];
      if (tl + 1 != tr) {
        lz[2 * x + 1] += lz[x];
        lz[2 * x + 2] += lz[x];
      }
      lz[x] = lz_id;
    }
  }

  LazySegmentTree(int n_) {
    init(n_);
  }

  LazySegmentTree(const vector<item_t> &a) {
    init(sz(a));
    build(a, 0, 0, n);
  }

  item_t query() {
    return st[0];
  }

  item_t query(int l, int r) {
    return query(l, r + 1, 0, 0, n);
  }

  void update(int l, int r, upd_t v) {
    update(l, r + 1, v, 0, 0, n);
  }

private:
  int n;
  vector<item_t> st;
  vector<upd_t> lz;

  void init(int sz) {
    n = 1;
    while (n < sz) {
      n *= 2;
    }
    st.resize(2 * n, id);
    lz.resize(2 * n, lz_id);
  }

  void build(const vector<item_t> &a, int x, int tl, int tr) {
    if (tl + 1 == tr) {
      if (tl < sz(a)) {
        st[x] = a[tl];
      }
      return;
    }
    int mid = (tl + tr) / 2;
    build(a, 2 * x + 1, tl, mid);
    build(a, 2 * x + 2, mid, tr);
    st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
  }

  item_t query(int l, int r, int x, int tl, int tr) {
    push(x, tl, tr);
    if (tl >= r || tr <= l) {
      return id;
    }
    if (tl >= l && tr <= r) {
      return st[x];
    }
    int mid = (tl + tr) / 2;
    return merge(query(l, r, 2 * x + 1, tl, mid), query(l, r, 2 * x + 2, mid, tr));
  }

  void update(int l, int r, int v, int x, int tl, int tr) {
    push(x, tl, tr);
    if (tl >= r || tr <= l) {
      return;
    }
    if (tl >= l && tr <= r) {
      apply(x, v);
      push(x, tl, tr);
      return;
    }
    int mid = (tl + tr) / 2;
    update(l, r, v, 2 * x + 1, tl, mid);
    update(l, r, v, 2 * x + 2, mid, tr);
    st[x] = merge(st[2 * x + 1], st[2 * x + 2]);
  }
};