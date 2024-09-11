#pragma once

template <class T, T(*op)(T, T), T(*id)()>
struct SparseSegmentTree {
  SparseSegmentTree() {}
  
  SparseSegmentTree(int n) {
    log = __lg(n - 1) + 1;
    treeSize = 1 << log;
    st.push_back(id());
    ch.emplace_back(-1, -1);
  }

  void set(int p, T v) {
    buf[0] = idx = 0;
    int tl = 0, tr = treeSize;
    while (tl + 1 != tr) {
      int mid = (tl + tr) >> 1;
      if (p < mid) {
        buf[idx + 1] = getL(buf[idx]);
        tr = mid;
      } else {
        buf[idx + 1] = getR(buf[idx]);
        tl = mid;
      }
      idx++;
    }
    st[buf[idx--]] = v;
    while (idx >= 0) {
      pull(buf[idx--]);
    }
  }

  T query(int l, int r) {
    return query(l, r + 1, 0, 0, treeSize);
  }

private:
  int log, treeSize;
  vector<T> st;
  vector<pair<int, int>> ch;

  int buf[32];
  int idx;

  int getL(int x) {
    if (ch[x].fi == -1) {
      ch[x].fi = sz(st);
      st.push_back(id());
      ch.emplace_back(-1, -1);
    }
    return ch[x].fi;
  }

  int getR(int x) {
    if (ch[x].se == -1) {
      ch[x].se = sz(st);
      st.push_back(id());
      ch.emplace_back(-1, -1);
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