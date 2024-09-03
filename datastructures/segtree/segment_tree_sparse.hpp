#pragma once

template <class T, T(*op)(T, T), T(*id)()>
struct SparseSegmentTree {
  SparseSegmentTree() {}
  
  SparseSegmentTree(int n) {
    log = lg(n - 1) + 1;
    tree_sz = 1 << log;
    st.push_back(id());
    ch.emplace_back(-1, -1);
  }

  void set(int p, T v) {
    vis_buf[0] = idx = 0;
    int tl = 0, tr = tree_sz;
    while (tl + 1 != tr) {
      int mid = (tl + tr) >> 1;
      if (p < mid) {
        vis_buf[idx + 1] = get_l(vis_buf[idx]);
        tr = mid;
      } else {
        vis_buf[idx + 1] = get_r(vis_buf[idx]);
        tl = mid;
      }
      idx++;
    }
    st[vis_buf[idx--]] = v;
    while (idx >= 0) {
      pull(vis_buf[idx--]);
    }
  }

  T query(int l, int r) {
    return query(l, r + 1, 0, 0, tree_sz);
  }

private:
  int log, tree_sz;
  vector<T> st;
  vector<pii> ch;

  int vis_buf[32];
  int idx;

  int get_l(int x) {
    if (ch[x].fi == -1) {
      ch[x].fi = sz(st);
      st.pb(id());
      ch.eb(-1, -1);
    }
    return ch[x].fi;
  }

  int get_r(int x) {
    if (ch[x].se == -1) {
      ch[x].se = sz(st);
      st.pb(id());
      ch.eb(-1, -1);
    }
    return ch[x].se;
  }

  void pull(int x) {
    if (ch[x].fi == -1) {
      st[x] = st[ch[x].se];
    } else if (ch[x].se != -1) {
      st[x] = op(st[ch[x].fi], st[ch[x].se]);
    } else {
      st[x] = st[ch[x].fi];
    }
  }

  T query(int l, int r, int x, int tl, int tr) {
    if (x == -1 || tl >= r || tr <= l) {
      return id();
    }
    if (tl >= l && tr <= r) {
      return st[x];
    }
    int mid = (tl + tr) >> 1;
    return op(query(l, r, ch[x].fi, tl, mid), query(l, r, ch[x].se, mid, tr));
  }
};