#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../datastructures/fentree/fenwick_tree_range_add.hpp"

const int N = 1e5, Q = 1e5;

int main() {
  vector<i64> a = randVec<i64>(N);
  RangeAddFT<i64> ft(a);
  for (int i = 0; i < Q; i++) {
    if (randBool()) {
      int l = randInt(N), r = randInt(N);
      if (l > r) {
        swap(l, r);
      }
      const int v = randInt(1e9);
      for (int j = l; j <= r; j++) {
        a[j] += v;
      }
      ft.add(l, r, v);
    } else {
      int p = randInt(N);
      assert(a[p] == ft.get(p));
    }
  }

  cerr << "Tests passed\n";

  int a_, b_;
  cin >> a_ >> b_;
  cout << a_ + b_ << '\n';
}