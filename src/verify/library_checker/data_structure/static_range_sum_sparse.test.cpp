#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "../../../template/template.h"
#include "../../../datastructures/segment_tree/sparse_segtree.h"

using ll = long long;

int main() {
  int n, q;
  cin >> n >> q;
  
  auto op = [](ll a, ll b) { return a + b; };
  auto id = []() { return 0LL; };
  
  SparseSegtree<ll, op, id> seg(n);
  
  for (int i = 0; i < n; i++) {
    ll a;
    cin >> a;
    seg.set(i, a);
  }
  
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << seg.query(l, r - 1) << '\n';
  }
  
  return 0;
}