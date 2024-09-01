#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../boilerplate.hpp"
#include "../../../datastructures/static/sparse_table.hpp"

int op(int x, int y) {
  return x < y ? x : y;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  SparseTable<int, op> rmq(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << rmq.query(l, r - 1) << '\n';
  }
}