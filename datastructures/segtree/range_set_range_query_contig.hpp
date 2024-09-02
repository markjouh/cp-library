// https://codeforces.com/contest/2000/submission/279265358

#define IGNORE

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