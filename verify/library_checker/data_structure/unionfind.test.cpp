#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "../../boilerplate.hpp"
#include "../../../datastructures/union_find.hpp"

int main() {
  int n, q;
  cin >> n >> q;
  UnionFind uf(n);
  while (q--) {
    bool t;
    int x, y;
    cin >> t >> x >> y;
    if (t) {
      cout << (uf.find(x) == uf.find(y)) << '\n';
    } else {
      uf.join(x, y);
    }
  }
}