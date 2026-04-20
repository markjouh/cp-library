#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/2/DSL/2/DSL_2_G"

#include "../../../template/template.h"
#include "../../../datastructures/fenwick_tree/dual_fentree.h"

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  DualFentree<long long> ft(n);
  while (q--) {
    int op;
    cin >> op;
    if (op == 0) {
      int s, t;
      long long x;
      cin >> s >> t >> x;
      ft.add(s - 1, t - 1, x);
    } else {
      int s, t;
      cin >> s >> t;
      cout << ft.sum(s - 1, t - 1) << '\n';
    }
  }
}
