#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../boilerplate.hpp"
#include "../../../datastructures/fentree/fenwick_tree.hpp"
#include "../../../graphs/tree/euler_tour.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  EulerTour et(g);
  FenwickTree<i64> ft(n);
  for (int i = 0; i < n; i++) {
    ft.add(et.tin[i], a[i]);
  }
  while (q--) {
    bool t;
    int u;
    cin >> t >> u;
    if (t) {
      cout << ft.sum(et.tin[u], et.tout[u] - 1) << '\n';
    } else {
      int x;
      cin >> x;
      ft.add(et.tin[u], x);
    }
  }
}