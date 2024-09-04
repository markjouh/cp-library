#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/random.hpp"
#include "../../../datastructures/fentree/fenwick_tree_range_add.hpp"

const int N = 1e5, QUERIES = 1e5;

int main() {
  vec<ll> a = rnd_vec<ll>(N, 0, inf<ll>);
  RangeAddFT<ll> ft(a);
  rep(i, QUERIES) {
    if (rnd<>(0, 1)) {
      int l = rnd<>(0, N - 1), r = rnd<>(0, N - 1);
      if (l > r) {
        swap(l, r);
      }
      const int v = rnd<>(1, inf<>);
      rep(j, l, r + 1) {
        a[j] += v;
      }
      ft.add(l, r, v);
    } else {
      int p = rnd<>(0, N - 1);
      assert(a[p] == ft.get(p));
    }
  }

  cerr << "Tests passed\n";

  int a_, b_;
  cin >> a_ >> b_;
  cout << a_ + b_ << '\n';
}