#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"

#include "../../boilerplate.hpp"
#include "../../../datastructures/segtreecore/segment_tree.hpp"

int op(int x, int y) {
  return x < y ? x : y;
}

int id() {
  return numeric_limits<int>::max();
}

int main() {
  int n, q;
  cin >> n >> q;
  SegmentTree<int, op, id> st(n);
  while (q--) {
    bool t;
    int x, y;
    cin >> t >> x >> y;
    if (t) {
      cout << st.query(x, y) << '\n';
    } else {
      st.set(x, y);
    }
  }
}