#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../boilerplate.hpp"
#include "../../../datastructures/mergesort_tree.hpp"
#include "../../../numeric/binary_search.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  MergesortTree<int> mt(a);
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    r--;
    cout << bsmin(0, INF, [&](int x) {
      return mt.query(l, r, x + 1) >= k + 1;
    }) << '\n';
  }
}