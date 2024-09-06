#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../datastructures/fentree/fenwick_tree_range_add.hpp"

const int N = 1e5, Q = 1e5;

int main() {
  vector<ll> a = randvec<ll>(N);
  RangeAddFT<ll> ft(a);
  for (int i = 0; i < Q; i++) {
    if (randbool()) {
      int l = randint(N), r = randint(N);
      if (l > r) {
        swap(l, r);
      }
      const int v = rnd<>(1, inf<>);
      for (int j = l; j <= r; j++) {
        a[j] += v;
      }
      ft.add(l, r, v);
    } else {
      int p = randint(N);
      assert(a[p] == ft.get(p));
    }
  }

  cerr << "Tests passed\n";

  int a_, b_;
  cin >> a_ >> b_;
  cout << a_ + b_ << '\n';
}