#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../utils/random.hpp"
#include "../../../datastructures/segtree/segment_tree_sparse.hpp"

const int N = 1e9, QUERIES = 5e4;

ll op(ll x, ll y) {
  return x + y;
}

ll id() {
  return 0;
}

int main() {
  vector<pii> a;
  SparseSegmentTree<ll, op, id> st(N);

  rep(i, QUERIES) {
    if (rnd<>(0, 1)) {
      const int p = rnd<>(0, N - 1), v = rnd<>(1, inf<>);
      bool flag = false;
      for (auto &b : a) {
        if (b.fi == p) {
          flag = true;
          b.se = v;
          break;
        }
      }
      if (!flag) {
        a.eb(p, v);
      }
      st.set(p, v);
    } else {
      int l = rnd<>(0, N - 1), r = rnd<>(0, N - 1);
      if (l > r) {
        swap(l, r);
      }
      ll sum = 0;
      for (auto [p, v] : a) {
        if (p >= l && p <= r) {
          sum += v;
        }
      }
      assert(st.query(l, r) == sum);
    }
  }

  cerr << "Tests passed\n";

  int a_, b_;
  cin >> a_ >> b_;
  cout << a_ + b_ << '\n';
}