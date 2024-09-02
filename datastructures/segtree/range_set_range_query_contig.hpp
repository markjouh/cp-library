// https://codeforces.com/contest/2000/submission/279265358

#include "segment_tree_lazy.hpp"

struct Seg {
  int len, pref, suff, mx;

  Seg(int x) : len(1), pref(x), suff(x), mx(x) {}
};

Seg op(Seg a, Seg b) {
  Seg res = a;
  res.len = a.len + b.len;
  res.pref = a.pref + (a.pref == a.len ? b.pref : 0);
  res.suff = b.suff + (b.suff == b.len ? a.suff : 0);
  res.mx = max({a.mx, b.mx, a.suff + b.pref});
  return res;
}

Seg seg_id() {
  return Seg(0);
}

struct Upd {
  short v;

  Upd(short x) {
    v = x;
  }
};

Seg mapping(Seg x, Upd y) {
  if (y.v == 1) {
    x.pref = x.suff = x.mx = x.len;
  }
  if (y.v == 0) {
    x.pref = x.suff = x.mx = 0;
  }
  return x;
}

Upd comp(Upd x, Upd y) {
  return y.v != -1 ? y : x;
}

Upd upd_id() {
  return Upd(-1);
}