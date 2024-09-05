#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
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
    if (randbool()) {
      const int p = randint(N), v = randint(inf<int>);
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
      int l = randint(N), r = randint(N);
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