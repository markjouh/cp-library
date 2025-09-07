#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../../template/template.h"
#include "../../../datastructures/segment_tree/lazy_segtree.h"

using ll = long long;

const ll MOD = 998244353;

struct S {
  ll sum, size;
};

struct F {
  ll a, b;
};

S op(S l, S r) {
  return {(l.sum + r.sum) % MOD, l.size + r.size};
}

S t_id() {
  return {0, 0};
}

S mapping(S x, F f) {
  return {(f.a * x.sum % MOD + f.b * x.size % MOD) % MOD, x.size};
}

F comp(F f, F g) {
  return {g.a * f.a % MOD, (g.a * f.b % MOD + g.b) % MOD};
}

F u_id() {
  return {1, 0};
}

int main() {
  int n, q;
  cin >> n >> q;
  
  vector<S> init(n);
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    init[i] = {a, 1};
  }
  
  LazySegtree<S, op, t_id, F, mapping, comp, u_id> seg(init);
  
  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r;
      ll b, c;
      cin >> l >> r >> b >> c;
      seg.update(l, r - 1, {b, c});
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.query(l, r - 1).sum << '\n';
    }
  }
  
  return 0;
}