#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../boilerplate.hpp"
#include "../../../misc/compress.hpp"
#include "../../../datastructures/fentree/fenwick_tree_2d.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  vec<array<int, 3>> pts(n);
  Compress<int> rows, cols;
  for (auto &[r, c, w] : pts) {
    cin >> r >> c >> w;
    rows.insert(r);
    cols.insert(c);
  }
  vec<array<int, 5>> qry(q);
  for (auto &[t, l, d, r, u] : qry) {
    cin >> t >> l >> d >> r;
    rows.insert(l);
    cols.insert(d);
    if (t) {
      cin >> u;
      r--, u--;
      rows.insert(r);
      cols.insert(u);
    }
  }

  rows.init();
  cols.init();
  FenwickTree2d<ll> ft(sz(rows), sz(cols));
  for (auto [r, c, w] : pts) {
    r = rows.get(r), c = cols.get(c);
    ft.add(r, c, w);
  }
  for (auto [t, l, d, r, u] : qry) {
    l = rows.get(l), d = cols.get(d);
    if (t) {
      r = rows.get(r), u = cols.get(u);
      cout << ft.sum(l, d, r, u) << '\n';
    } else {
      ft.add(l, d, r);
    }
  }
}