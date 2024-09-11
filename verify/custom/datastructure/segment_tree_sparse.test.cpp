#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../boilerplate.hpp"
#include "../../../datastructures/segtree/segment_tree_sparse.hpp"

const int N = 1e9, Q = 5e4;

i64 op(i64 x, i64 y) {
  return x + y;
}

i64 id() {
  return 0;
}

int main() {
  vector<pair<int, int>> a;
  SparseSegmentTree<i64, op, id> st(N);

  for (int i = 0; i < Q; i++) {
    if (randBool()) {
      const int p = randInt(N), v = randInt(1e9);
      bool flag = false;
      for (auto &b : a) {
        if (b.fi == p) {
          flag = true;
          b.se = v;
          break;
        }
      }
      if (!flag) {
        a.emplace_back(p, v);
      }
      st.set(p, v);
    } else {
      int l = randInt(N), r = randInt(N);
      if (l > r) {
        swap(l, r);
      }
      i64 sum = 0;
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