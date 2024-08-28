#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../boilerplate.hpp"
#include "../../../graphs/kosaraju_scc.hpp"

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
  }
  KosarajuSCC scc(g);
  cout << scc.sccs << '\n';
  for (int i = 0; i < scc.sccs; i++) {
    cout << sz(scc.members[i]) << ' ';
    for (int x : scc.members[i]) {
      cout << x << ' ';
    }
    cout << '\n';
  }
}