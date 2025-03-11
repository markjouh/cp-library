#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../../template/template.h"
#include "../../../graphs/trees/fast_lca.h"

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  FastLCA ds(g);
  while (q--) {
    int u, v;
    cin >> u >> v;
    cout << ds.lca(u, v) << '\n';
  }
}