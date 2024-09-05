#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/random.hpp"
#include "../../../datastructures/fentree/fenwick_tree_range_add.hpp"

const int N = 1e5, QUERIES = 1e5;

int main() {
  vec<ll> a = randvec<ll>(N);
  RangeAddFT<ll> ft(a);
  rep(i, QUERIES) {
    if (randbool()) {
      int l = randint(N), r = randint(N);
      if (l > r) {
        swap(l, r);
      }
      const int v = rnd<>(1, inf<>);
      rep(j, l, r + 1) {
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