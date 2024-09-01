#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../boilerplate.hpp"
#include "../../../datastructures/fentree/fenwick_tree_range_add_range_sum.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  RangeAddRangeSumFT<ll> ft(n);
  while (q--) {
    bool t;
    int l, r;
    cin >> t >> l >> r;
    l--; r--;
    if (t) {
      cout << ft.sum(l, r) << '\n';
    } else {
      int x;
      cin >> x;
      ft.add(l, r, x);
    }
  }
}