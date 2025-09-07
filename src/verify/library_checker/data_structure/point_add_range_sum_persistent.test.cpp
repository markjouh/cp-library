#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../../template/template.h"
#include "../../../datastructures/segment_tree/persistent_segtree.h"

using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  
  auto op = [](ll a, ll b) { return a + b; };
  auto id = []() { return 0LL; };
  
  PersistentSegtree<ll, op, id> seg(n);
  
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    seg.update(i, a);
  }
  
  while (q--) {
    int t;
    cin >> t;
    if (t == 0) {
      int p;
      ll x;
      cin >> p >> x;
      ll cur = seg.query(p, p);
      seg.update(p, cur + x);
    } else {
      int l, r;
      cin >> l >> r;
      cout << seg.query(l, r - 1) << '\n';
    }
  }
  
  return 0;
}